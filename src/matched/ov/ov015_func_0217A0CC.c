/*
 * function: func_0217A0CC
 * address:  0x0217A0CC
 * packet:   pkt_ov015_0217A0CC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    2026-10-05 wave P18 lane 8: libirc finish. When the field at d_0217ABA8 + 0x24 is set, and the field at
 *           +0x18 and the argument n are both zero, sends a 0xF4 frame through func_0217A034. Then calls the
 *           callback stored at +0xC with n when it is set, and resets the state with func_02179F48.
 *
 * symbols:
 *   func_0217A034  0x0217A034  arm    ov015
 *   func_02179F48  0x02179F48  arm    ov015
 *   d_0217ABA8     0x0217ABA8  data   ov015
 *   g_0217AAB0     0x0217AAB0  data   ov015
 */

extern char d_0217ABA8[];
extern unsigned char g_0217AAB0[];
extern void func_0217A034(int a0, int a1, int a2, int a3);
extern void func_02179F48(void);

void func_0217A0CC(int n)
{
    void (*cb)(int);

    if (*(int *)(d_0217ABA8 + 0x24) != 0 && *(int *)(d_0217ABA8 + 0x18) == 0 && n == 0)
        func_0217A034(0, 0, 0xF4, g_0217AAB0[0]);
    cb = *(void (**)(int))(d_0217ABA8 + 0xC);
    if (cb != 0)
        cb(n);
    func_02179F48();
}
