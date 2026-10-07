/*
 * function: func_021BA660
 * address:  0x021BA660
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA674  0x021BA674  thumb
 *   func_021BA6DC  0x021BA6DC  thumb
 *
 * Runs the two arm9 setup routines on the second argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BA674(void *a);
extern void func_021BA6DC(void *a);

void func_021BA660(int unused, void *p)
{
    func_021BA674(p);
    func_021BA6DC(p);
}
