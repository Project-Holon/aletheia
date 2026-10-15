/*
 * function: BEACON_VIEW_UpdateRecordArrival
 * address:  0x021F02C4
 * packet:   pkt_ov032_021F02C4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_HandleRecordAction  0x021F180C  thumb  ov032
 *   BEACON_VIEW_SetArrowAnim  0x021F05E8  thumb  ov032
 *   BEACON_VIEW_PlaySe  0x021F0DD8  thumb  ov032
 *   BEACON_VIEW_SetupEntry  0x021F1144  thumb  ov032
 *   BEACON_VIEW_SetEntryVisible  0x021F0EA4  thumb  ov032
 *   BEACON_VIEW_ShowRecordCount  0x021F0AC0  thumb  ov032
 *   BEACON_VIEW_ShowPlayTime  0x021F0B10  thumb  ov032
 *   BEACON_VIEW_UpdateAchievements  0x021F06E0  thumb  ov032
 *   GAME_BEACON_ACCESSOR_TableRingGet  0x02165AC4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex  0x021659F0  thumb  ov010
 *   BEACON_VIEW_StartEntryMove  0x021F13A0  thumb  ov032
 */
#include "../include/Obj00007.h"
#include "../include/Obj20416.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int BEACON_VIEW_HandleRecordAction(char *this, int x, int flag);
extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void BEACON_VIEW_PlaySe(unsigned int a);
struct Queue;
struct Rec;
extern void BEACON_VIEW_SetupEntry(u8 *p, u8 *q, void *r, int mode, int skip, int t);
extern void BEACON_VIEW_SetEntryVisible(char *p, unsigned a);
extern void BEACON_VIEW_ShowRecordCount(char *p);
extern void BEACON_VIEW_ShowPlayTime(char *p, int a, int b);
extern void BEACON_VIEW_UpdateAchievements(u8 *p, u32 x, int y);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern void BEACON_VIEW_StartEntryMove(char *this, int a, int b, int c, int s);

int BEACON_VIEW_UpdateRecordArrival(u8 *p)
{
    int r;

    switch (((struct Obj00007 *)p)->f6C) {
    case 0:
        if (((struct Obj20416 *)(*(u8 * *)&((struct Obj00007 *)p)->f50))->f2C != 0)
            break;
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 1:
        r = BEACON_VIEW_HandleRecordAction((char *)p, ((struct Obj00007 *)p)->f4C, ((struct Obj00007 *)p)->f5C);
        if (((struct Obj00007 *)p)->f5C == 0) {
            if (r != 0) {
                BEACON_VIEW_SetArrowAnim(p, 4, 2);
                BEACON_VIEW_PlaySe(0x549);
            }
            if (*(u8 * *)&((struct Obj00007 *)p)->f50 != 0) {
                BEACON_VIEW_SetupEntry(p, *(u8 * *)&((struct Obj00007 *)p)->f50, (void *)(((struct Obj00007 *)p)->f4C), 0, r == 0, 0);
                BEACON_VIEW_SetEntryVisible((char *)(*(u8 * *)&((struct Obj00007 *)p)->f50), 1);
            }
            return 1;
        }
        BEACON_VIEW_SetArrowAnim(p, 4, 2);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 2:
        BEACON_VIEW_ShowRecordCount((char *)p);
        BEACON_VIEW_ShowPlayTime((char *)p, 1, (int)(p + 0xA8));
        BEACON_VIEW_UpdateAchievements(p, ((struct Obj00007 *)p)->f4C, p[0x57]);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 3:
        if (p[0x7C] != 0) {
            p[0x54] = p[0x7C];
            GAME_BEACON_ACCESSOR_TableRingGet((struct Queue *)(((struct Obj00007 *)p)->f3C), (struct Rec *)(((struct Obj00007 *)p)->f4C), (u16 *)(p + 0x4A), p[0x54]);
            p[0x55] = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(((struct Obj00007 *)p)->f3C), p[0x54]);
        }
        BEACON_VIEW_StartEntryMove((char *)p, ((struct Obj00007 *)p)->f4C, p[0x55], 1, (p[0x7C] != 0 ? 1 : 0) + 1);
        p[0x7C] = p[0x54];
        BEACON_VIEW_PlaySe(0x64A);
        return 1;
    }
    return 0;
}
