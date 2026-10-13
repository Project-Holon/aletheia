/*
 * function: UNION_APP_Update
 * address:  0x02183C3C
 * packet:   pkt_ov022_02183C3C
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   UNION_APP_ClearDisconnectedPending  0x02183EE0  thumb  ov022
 *   UNION_APP_SendSetting  0x02183D34  thumb  ov022
 *   UNION_APP_DropDisconnectedMembers  0x02183CC0  thumb  ov022
 *   UNION_APP_SelectQuitRequester  0x02183D4C  thumb  ov022
 *   UNION_APP_SendQuitAccept  0x02183D94  thumb  ov022
 *   UNION_APP_SendOwnEntry  0x02183DAC  thumb  ov022
 *   UNION_APP_ConfirmJoins  0x02183DDC  thumb  ov022
 *   UNION_APP_UpdateLeaves  0x02183E48  thumb  ov022
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00660.h"

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern void UNION_COMM_RequestShutdown(u8 *p);
extern int UNION_COMM_IsResetting(u8 *p);
extern u32 GFL_NET_IsParentAid(void);
struct C;
struct S;
extern void UNION_APP_ClearDisconnectedPending(struct S *s, struct C *c);
extern void UNION_APP_SendSetting(u8 *s);
extern void UNION_APP_DropDisconnectedMembers(u8 *s);
extern void UNION_APP_SelectQuitRequester(u8 *s);
extern void UNION_APP_SendQuitAccept(u8 *s);
extern void UNION_APP_SendOwnEntry(u8 *s);
extern void UNION_APP_ConfirmJoins(u8 *s);
extern void UNION_APP_UpdateLeaves(struct S *s, struct C *c);

void UNION_APP_Update(u8 *s, u8 *c)
{
    if (func_0200FB24() != 0) {
        return;
    }
    if (((struct Obj00660 *)s)->f28 == 1) {
        return;
    }
    if (((struct Obj00660 *)s)->f20 == 1) {
        UNION_COMM_RequestShutdown(c);
        ((struct Obj00660 *)s)->f20 = 0;
        ((struct Obj00660 *)s)->f24 = 1;
        return;
    }
    if (((struct Obj00660 *)s)->f24 == 1) {
        if (UNION_COMM_IsResetting(c) == 0) {
            ((struct Obj00660 *)s)->f24 = 0;
            ((struct Obj00660 *)s)->f28 = 1;
        }
        return;
    }
    if (GFL_NET_IsParentAid() == 1) {
        UNION_APP_ClearDisconnectedPending((struct S *)s, (struct C *)c);
        UNION_APP_SendSetting(s);
        UNION_APP_DropDisconnectedMembers(s);
        UNION_APP_SelectQuitRequester(s);
        UNION_APP_SendQuitAccept(s);
    }
    UNION_APP_SendOwnEntry(s);
    UNION_APP_ConfirmJoins(s);
    UNION_APP_UpdateLeaves((struct S *)s, (struct C *)c);
}
