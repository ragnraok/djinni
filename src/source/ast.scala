/**
  * Copyright 2014 Dropbox, Inc.
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *    http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  */

package djinni.ast

import java.io.File
import djinni.ast.Record.DerivingType.DerivingType
import djinni.meta.MExpr
import djinni.syntax.Loc

case class IdlFile(imports: Seq[FileRef], typeDecls: Seq[TypeDecl])

abstract sealed class FileRef {
  val file: File
}
case class IdlFileRef(override val file: File) extends FileRef
case class ExternFileRef(override val file: File) extends FileRef

case class Ident(name: String, file: File, loc: Loc)
class ConstRef(ident: Ident) extends Ident(ident.name, ident.file, ident.loc)
class EnumValue(val ty: Ident, ident: Ident) extends Ident(ident.name, ident.file, ident.loc)

case class TypeParam(ident: Ident)

case class Doc(lines: Seq[String])

sealed abstract class TypeDecl {
  val ident: Ident
  val params: Seq[TypeParam]
  val body: TypeDef
  val origin: String
  val parent: Option[TypeRef] = null
}
case class InternTypeDecl(override val ident: Ident, override val params: Seq[TypeParam], override val body: TypeDef, doc: Doc, override val origin: String, override val parent: Option[TypeRef]) extends TypeDecl
case class ExternTypeDecl(override val ident: Ident, override val params: Seq[TypeParam], override val body: TypeDef, properties: Map[String, Any], override val origin: String) extends TypeDecl

case class Ext(java: Boolean, cpp: Boolean, objc: Boolean, proxy: Boolean) {
  def any(): Boolean = {
    java || cpp || objc || proxy
  }
}

case class TypeRef(expr: TypeExpr) {
  var resolved: MExpr = null
}
case class TypeExpr(ident: Ident, args: Seq[TypeExpr])

object Type {
  val TYPE_ENUM = 1
  val TYPE_RECORD = 2
  val TYPE_INTERFACE = 3
}

sealed abstract class TypeDef {
  
  def getType: Int
}

case class Const(ident: Ident, ty: TypeRef, value: Any, doc: Doc)

case class Enum(options: Seq[Enum.Option]) extends TypeDef {
  override def getType: Int = Type.TYPE_ENUM
}

object Enum {
  case class Option(ident: Ident, doc: Doc)
}

case class Record(ext: Ext, fields: Seq[Field], consts: Seq[Const], derivingTypes: Set[DerivingType]) extends TypeDef {
  override def getType: Int = Type.TYPE_RECORD
}
object Record {
  object DerivingType extends Enumeration {
    type DerivingType = Value
    val Eq, Ord, Parcel = Value
  }
}

case class Interface(ext: Ext, methods: Seq[Interface.Method], consts: Seq[Const]) extends TypeDef {
  override def getType: Int = Type.TYPE_INTERFACE

  var parent: Option[TypeRef] = None
  var superMethods: Seq[Interface.Method] = Seq.empty[Interface.Method]
}
object Interface {
  case class Method(ident: Ident, params: Seq[Field], ret: Option[TypeRef], doc: Doc, static: Boolean, const: Boolean)
}

case class Field(ident: Ident, ty: TypeRef, doc: Doc)
