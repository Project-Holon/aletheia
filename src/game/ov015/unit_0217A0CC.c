/*
 * file:     unit_0217A0CC.c
 * unit:     yes
 * function: func_0217A0CC, func_0217A134
 * address:  0x0217A0CC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217A034  0x0217A034  arm    ov015
 *   func_02179F48  0x02179F48  arm    ov015
 *   d_0217ABA8     0x0217ABA8  data   ov015
 *   g_0217AAB0     0x0217AAB0  data   ov015
 *   func_0217A648  0x0217A648  arm  ov015
 */
#include "../../matched/include/G_ov015_0217ABA8.h"

extern void func_0217A034(unsigned char *data, unsigned char size, int command, unsigned char id);
extern void func_02179F48(void);
extern void func_0217A648(void);
void func_0217A0CC(int n);
void func_0217A134(void);
extern struct G_ov015_0217ABA8 d_0217ABA8;
extern unsigned char g_0217AAB0[];


/*
 * notes:    2026-10-05 wave P18 lane 8: libirc finish. When the field at d_0217ABA8 + 0x24 is set, and the field at
 *           +0x18 and the argument n are both zero, sends a 0xF4 frame through func_0217A034. Then calls the
 *           callback stored at +0xC with n when it is set, and resets the state with func_02179F48.
 */
void func_0217A0CC(int n)
{
    void (*cb)(int);

    if (*(int *)(((char *)&d_0217ABA8) + 0x24) != 0 && *(int *)(((char *)&d_0217ABA8) + 0x18) == 0 && n == 0)
        func_0217A034(0, 0, 0xF4, g_0217AAB0[0]);
    cb = *(void (**)(int))(((char *)&d_0217ABA8) + 0xC);
    if (cb != 0)
        cb(n);
    func_02179F48();
}


/*
 * notes:    2026-10-05 wave P27 lane 4: libirc shutdown. Calls func_0217A0CC with 0 (finish), then
 *           func_0217A648 (IRCi_End).
 */
void func_0217A134(void)
{
    func_0217A0CC(0);
    func_0217A648();
}
