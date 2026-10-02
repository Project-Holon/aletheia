/*
 * function: func_021B8F0C
 * address:  0x021B8F0C
 * packet:   pkt_ov070_021B8F0C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BA9AC  0x021BA9AC  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 */

typedef unsigned int u32;

extern u32 func_020362DC(void);
extern int func_02035C60();
extern void func_021B80C4();
extern void func_021B6138();
extern void func_021BA9AC();
extern void func_0204B92C();
extern void func_021BB3F4();
extern void func_021B8AF4();

void func_021B8F0C(int p)
{
    if (func_020362DC() & 3) {
        func_021B80C4(p, 1);
    } else if (func_02035C60()) {
        func_021B80C4(p, 0);
    } else {
        return;
    }
    *(int *)((char *)p + 0x818) = 0xFFFF;
    func_021B6138(p);
    func_021BA9AC(p);
    func_0204B92C(*(int *)((char *)p + 0x6A8), 1);
    func_021BB3F4(p, 1);
    func_021B8AF4(p);
}
