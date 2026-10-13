/*
 * function: OPTION_MENU_ExitScreen
 * address:  0x021B98E0
 * packet:   pkt_ov068_021B98E0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   OPTION_MENU_ExitSprites  0x021B9F70  thumb  ov068
 *   OPTION_MENU_ExitGfx  0x021B9B6C  thumb  ov068
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../include/Obj20635.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Node;
extern void func_02030EAC(struct Node *n);
extern void OPTION_MENU_ExitSprites(u32 *p);
extern void OPTION_MENU_ExitGfx(u32 *p);
extern void func_0201DD68(void);
extern void func_02082BCC(void *p, u32 a, u32 b);

void OPTION_MENU_ExitScreen(u8 *p)
{
    func_02030EAC((struct Node *)(((struct Obj20635 *)p)->fD0));
    OPTION_MENU_ExitSprites((u32 *)(p + 0x7c));
    OPTION_MENU_ExitGfx((u32 *)p);
    func_0201DD68();
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    func_02082BCC(p, 0, 0xd4);
}
