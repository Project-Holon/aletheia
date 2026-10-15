/*
 * function: WF2DMAP_TOUCH_FriendKeyScreen, WF2DMAP_TOUCH_DeleteScreenThunk
 * unit: yes
 * address: 0x021C8E2C
 * packet: pkt_ov128_021C8E2C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Includes the eight-byte forwarding follower at 0x021C8F24.
 * symbols:
 *   WF2DMAP_TOUCH_DrawFriendKeyThunk 0x021C8E24 thumb ov128
 *   WF2DMAP_TOUCH_InitGfx 0x021C9180 thumb ov128
 *   WF2DMAP_TOUCH_GetFriendKeyInput 0x021C8F2C thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimA 0x021CA3A0 thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimB 0x021CA3C4 thumb ov128
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   Wf2dmapFriend_SetState 0x021C6438 thumb ov128
 *   WF2DMAP_TOUCH_ClearScreens 0x021C91CC thumb ov128
 *   WF2DMAP_TOUCH_DeleteScreens 0x021C9154 thumb ov128
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj03813.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WF2DMAP_TOUCH_DrawFriendKeyThunk(void *, void *, void *, int);
extern void WF2DMAP_TOUCH_InitGfx(char *p, char *q, char *r);
extern int WF2DMAP_TOUCH_GetFriendKeyInput(void *, int *);
struct Actor;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void WF2DMAP_TOUCH_PlayActorAnimA(char *p);
extern void WF2DMAP_TOUCH_PlayActorAnimB(char *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void Wf2dmapFriend_SetState(u8 *p, u8 a, u8 b);
extern void WF2DMAP_TOUCH_ClearScreens(char *p, void *q);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern u32 WIPE_SYS_EndCheck(void);
extern void WF2DMAP_TOUCH_DeleteScreens(char *p, int unused, char *q);
void WF2DMAP_TOUCH_DeleteScreenThunk(void *, void *, void *);
int WF2DMAP_TOUCH_FriendKeyScreen(void *p, u8 *q, u8 *r, int heap)
{
    int v;
    switch (q[8]) {
    case 0:
        WF2DMAP_TOUCH_DrawFriendKeyThunk(p, q, r, 52);
        WF2DMAP_TOUCH_InitGfx(p, (char *)q, (char *)r);
        q[8] = 1;
        break;
    case 1:
        v = WF2DMAP_TOUCH_GetFriendKeyInput(p, (int *)q);
        if (v == 0) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            WF2DMAP_TOUCH_PlayActorAnimA((char *)r);
            q[8] = 2;
        } else if (v == 1) {
            GFL_USE_PlaySeDefaultVolume(0x556);
            WF2DMAP_TOUCH_PlayActorAnimB((char *)r);
            q[8] = 3;
        }
        break;
    case 2:
        if (CLACT_IsActorAnimActive(((struct Obj03813 *)r)->f164) != 1) {
            Wf2dmapFriend_SetState(q, 0, 2);
            WF2DMAP_TOUCH_ClearScreens(p, r);
            WF2DMAP_TOUCH_DeleteScreenThunk(p, q, r);
            return 1;
        }
        break;
    case 3:
        if (CLACT_IsActorAnimActive(((struct Obj03813 *)r)->f168) != 1) q[8] = 4;
        break;
    case 4:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, heap);
        q[8] = 5;
        break;
    case 5:
        if (WIPE_SYS_EndCheck() == 1) {
            Wf2dmapFriend_SetState(q, 6, 0);
            WF2DMAP_TOUCH_DeleteScreenThunk(p, q, r);
            return 1;
        }
        break;
    }
    return 0;
}
void WF2DMAP_TOUCH_DeleteScreenThunk(void *p, void *q, void *r)
{
    WF2DMAP_TOUCH_DeleteScreens(p, (int)q, r);
}
