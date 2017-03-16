#import "TXSTextboxListenerImpl.h"
#import "TXSItemList.h"

@implementation TXSTextboxListenerImpl {
    UITextView * _textView;
}

- (id)initWithUITextView:(UITextView *)textView
{
    if (self = [super init]) {
        _textView = textView;
    }
    return self;
}

//- (void)update:(TXSItemList *)items
//{
////    NSString *str = [items.items componentsJoinedByString:@"\n"];
////    _textView.text = str;
//    NSLog(@"TXSTextboxListenerImpl update");
//}

- (void)updateNew:(nonnull TXSItemList *)items
{
//    NSString *str = [items.items componentsJoinedByString:@"\n"];
    NSLog(@"TXSTextboxListenerImpl udpateNew");
}

@end
