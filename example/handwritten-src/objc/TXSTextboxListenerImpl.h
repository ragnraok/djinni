#import "TXSTextboxListener.h"
#import "TXSTextboxSuperListenerImpl.h"
#import <Foundation/Foundation.h>

@interface TXSTextboxListenerImpl : TXSuperListenerImpl<TXSTextboxListener>

- (id)initWithUITextView:(UITextView *)textView;

@end
