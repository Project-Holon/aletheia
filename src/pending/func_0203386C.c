/*
 * function: func_0203386C
 * address:  0x0203386C
 * packet:   pkt_020334E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  func_02076B98 (label) -- has no witness outside 0203386C..020338B8,
 *           the only branch to it in the image is this function's own call.
 *           Every concrete byte of the body reproduces.
 * symbols:
 *   g_02146998    0x02146998  data
 *   func_02076B8C 0x02076B8C  arm
 *   func_02076B98 0x02076B98  arm
 *   func_02076B80 0x02076B80  arm
 *   func_02075EAC 0x02075EAC  arm
 *   func_02084F10 0x02084F10  arm
 */

typedef unsigned int u32;

extern u32 g_02146998;
extern u32 func_02076B8C(void);
extern void func_02076B98(void);
extern void func_02076B80(void);
extern void func_02075EAC(u32 a);
extern void func_02084F10(u32 a);

void func_0203386C(u32 a)
{
    if (func_02076B8C() == 0) {
        func_02076B98();
        func_02076B80();
    }
    if (g_02146998 != 1) {
        return;
    }
    func_02075EAC(a);
    func_02084F10(a);
    g_02146998 = 0;
}
