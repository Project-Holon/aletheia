/*
 * function: BEACON_VIEW_InitList
 * address:  0x021EFEC0
 * packet:   pkt_ov032_021EFEC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_InitList  0x021EFEC0  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   BEACON_VIEW_ShowRecordCount  0x021F0AC0  thumb  ov032
 *   BEACON_VIEW_ShowPlayTime  0x021F0B10  thumb  ov032
 *   GAME_BEACON_ACCESSOR_TableRingGet  0x02165AC4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex  0x021659F0  thumb  ov010
 *   BEACON_VIEW_GetEntry  0x021F0F44  thumb  ov032
 *   BEACON_VIEW_SetEntrySlot  0x021F0F30  thumb  ov032
 *   BEACON_VIEW_SetupEntry  0x021F1144  thumb  ov032
 *   BEACON_VIEW_SetEntryVisible  0x021F0EA4  thumb  ov032
 *   BEACON_VIEW_UpdateActorAnims  0x021F0E24  thumb  ov032
 *   BEACON_VIEW_UpdateCountActorAnims  0x021F0E7C  thumb  ov032
 *   BEACON_VIEW_SetActorAnim  0x021F0DF4  thumb  ov032
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 */
#include "../include/Obj00007.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Obj02021EE4;
struct Queue;
struct Rec;
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void BEACON_VIEW_ShowRecordCount(char *p);
extern void BEACON_VIEW_ShowPlayTime(char *p, int a, int b);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern u8 *BEACON_VIEW_GetEntry(u8 *p, int a);
extern void BEACON_VIEW_SetEntrySlot(char *p, int a, int b);
extern void BEACON_VIEW_SetupEntry(u8 *p, u8 *q, void *r, int mode, int skip, int t);
extern void BEACON_VIEW_SetEntryVisible(char *p, unsigned a);
extern void BEACON_VIEW_UpdateActorAnims(char *p);
extern void BEACON_VIEW_UpdateCountActorAnims(char *p);
extern void BEACON_VIEW_SetActorAnim(void *p, unsigned short v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void BEACON_VIEW_InitList(u8 *o)
{
    int i;
    u8 *q;
    u8 *e;
    int s;
    int t;

    PALANM_SetAutoTransfer((struct Obj02021EE4 *)(*(int *)&((struct Obj00007 *)o)->fAC), 1);
    BEACON_VIEW_ShowRecordCount((char *)o);
    BEACON_VIEW_ShowPlayTime((char *)o, 1, 0);
    for (i = 0; i < o[0x7D]; i++) {
        q = o + 0x48;
        t = o[0x7C];
        GAME_BEACON_ACCESSOR_TableRingGet((struct Queue *)(((struct Obj00007 *)o)->f3C), (struct Rec *)(((struct Obj00007 *)o)->f40), (u16 *)q, t + i);
        s = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(((struct Obj00007 *)o)->f3C), t + i);
        e = BEACON_VIEW_GetEntry(o, 0xFF);
        BEACON_VIEW_SetEntrySlot((char *)e, (u8)s, (u8)(i + 1));
        BEACON_VIEW_SetupEntry(o, e, (void *)(((struct Obj00007 *)o)->f40), 2, 0, 0);
        BEACON_VIEW_SetEntryVisible((char *)e, (int)1);
    }
    BEACON_VIEW_UpdateActorAnims((char *)o);
    BEACON_VIEW_UpdateCountActorAnims((char *)o);
    if (((struct Obj00007 *)o)->f28 == 0x30)
        BEACON_VIEW_SetActorAnim((void *)(*(int *)&((struct Obj00007 *)o)->f2BC), 3);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00007 *)o)->f96);
}
