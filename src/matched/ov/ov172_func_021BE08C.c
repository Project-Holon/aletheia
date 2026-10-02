/*
 * function: func_021BE08C
 * address:  0x021BE08C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing the inverted flag at +0x1c as the second argument.
 *
 * symbols:
 *   func_021BE07C  0x021BE07C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021BE07C is ov172's own code (a tail call to func_021B8720
 * right after func_021BE078's bx lr), inside ov172's window, so only ov172
 * can be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021BE07C(void *p, int v);

void func_021BE08C(void *p)
{
    u32 v = *(u32 *)((char *)p + 0x1c);
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    func_021BE07C(p, v);
}
