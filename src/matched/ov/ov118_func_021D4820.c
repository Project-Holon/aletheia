/*
 * function: POKETRADE_DEMO_UP_PrintMessage
 * address:  0x021D4820
 * packet:   pkt_ov118_021D4820
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos  0x021E0FF4  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00983.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct WordSet;
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void BG_SYS_SetTileEntry(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int b);
extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);

void POKETRADE_DEMO_UP_PrintMessage(u8 *p)
{
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00983 *)p)->f5F4);
    if (((struct Obj00983 *)p)->f118C == 6) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x98, (void *)(((struct Obj00983 *)p)->f73C));
    } else if (((struct Obj00983 *)p)->f118C == 8) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x9B, (void *)(((struct Obj00983 *)p)->f73C));
    } else if (((struct Obj00983 *)p)->f11ED != 0) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x82, (void *)(((struct Obj00983 *)p)->f73C));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x81, (void *)(((struct Obj00983 *)p)->f73C));
    }
    WORDSET_SetSlotMonNickname(((struct Obj00983 *)p)->f724, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)));
    WORDSET_SetSlotMyStatus((struct WordSet *)(*(u32 *)&((struct Obj00983 *)p)->f724), 1, (void *)(((struct Obj00983 *)p)->f834));
    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((struct Obj00983 *)p)->f724), (void *)(((struct Obj00983 *)p)->f738), (void *)(((struct Obj00983 *)p)->f73C));
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}
