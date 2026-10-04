/*
 * function: func_0203A770
 * address:  0x0203A770
 * packet:   pkt_0203A748
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0203A634 0x0203A634  arm
 *   func_020399B8 0x020399B8  arm
 *   func_0203A70C 0x0203A70C  arm
 *   func_0203A730 0x0203A730  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0203A634(u32 a);
extern u32 func_020399B8(u8 *p);
extern int func_0203A70C(u32 idx);
extern u32 func_0203A730(u32 a);

void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f)
{
    u32 ok;
    u32 fn;

    if (func_0203A634(b) == 0) {
        return;
    }
    ok = 1;
    if (func_020399B8((u8 *)f) == 0) {
        if (c >= 0x11) {
            ok = 0;
        }
    }
    if (ok == 0) {
        return;
    }
    fn = func_0203A70C(c);
    if (fn == 0) {
        return;
    }
    ((void (*)(u32, u32, u32, u32, u32))fn)(a, d, e, func_0203A730(c), f);
}
