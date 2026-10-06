/*
 * unit: yes
 * function: func_021BA21C, func_021BA238
 * address: 0x021BA21C
 * packet: pkt_ov218_021BA21C
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: parent-cleared ov218021BA238; lead EXACT*28B, no ARM9 blocker; independent ldrh/threshold/bx Thumb body fills remaining88B before A290.
 * volatile: VCOUNT04000006 read at A23A, SUB_BLDALPHA04001052 written at A244/A250/A25C/A268/A26E.
 * symbols:
 *   func_021B9944 0x021B9944 thumb ov218
 *   func_021B9C74 0x021B9C74 thumb ov218
 *   func_021B61F8 0x021B61F8 thumb ov067
 */
#include "../include/Obj26048.h"
extern void func_021B9944(void);
typedef unsigned char  u8;
extern void func_021B9C74(u8 *p);
extern void func_021B61F8(unsigned char *task, int value);
int func_021BA21C(unsigned char *task, char *ctx)
{
    func_021B9944();
    func_021B9C74(((struct Obj26048 *)ctx)->f28);
    func_021B61F8(task, 0);
    return 1;
}
void func_021BA238(void)
{
    int count = *(volatile unsigned short *)0x04000006;
    if (count >= 152)
        *(volatile unsigned short *)0x04001052 = 0x050b;
    else if (count >= 112)
        *(volatile unsigned short *)0x04001052 = 0x060a;
    else if (count >= 72)
        *(volatile unsigned short *)0x04001052 = 0x0709;
    else if (count >= 32)
        *(volatile unsigned short *)0x04001052 = 0x0808;
    else
        *(volatile unsigned short *)0x04001052 = 0x0a06;
}
