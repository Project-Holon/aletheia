/*
 * function: UNION_SUBDISP_Update
 * address:  0x021F00D4
 * packet:   pkt_ov031_021F00D4
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   UNION_CHAT_LOG_Add  0x021BBA70  thumb  ov021
 *   UNION_SUBDISP_UpdateChatLines  0x021F0680  thumb  ov031
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   UNION_SUBDISP_CheckTouch  0x021F0584  thumb  ov031
 *   UNION_COMM_SetChatType  0x021736C8  thumb  ov012
 *   UNION_SUBDISP_UpdateKnobDrag  0x021F0B98  thumb  ov031
 *   UNION_SUBDISP_CheckTrackTouch  0x021F0D64  thumb  ov031
 *   UNION_SUBDISP_PageScrollByButtons  0x021F0FE0  thumb  ov031
 *   UNION_SUBDISP_SyncKnobAndScroll  0x021F0C34  thumb  ov031
 *   UNION_SUBDISP_CheckLineTouch  0x021F0DB0  thumb  ov031
 *   UNION_SUBDISP_UpdateLineHighlights  0x021F0EF4  thumb  ov031
 *   UNION_MAIN_SetAppealNo  0x02173934  thumb  ov012
 */
#include "../include/Obj01128.h"
#include "../include/Obj07628.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct Src;
extern u32 GAME_COMM_GetWork(void *obj);
extern u32 GAME_COMM_GetKind(void *obj);
extern void UNION_CHAT_LOG_Add(struct Ctx *ctx, struct Src *src, u16 *v, u8 kind);
extern void UNION_SUBDISP_UpdateChatLines(char *p, u8 *b);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern int UNION_SUBDISP_CheckTouch(int *p, u8 *flag);
extern void UNION_COMM_SetChatType(u8 *a, int v);
extern int UNION_SUBDISP_UpdateKnobDrag(char *o);
extern int UNION_SUBDISP_CheckTrackTouch(char *p);
extern void UNION_SUBDISP_PageScrollByButtons(char *p, u8 *q);
extern void UNION_SUBDISP_SyncKnobAndScroll(char *a, unsigned char *b);
extern int UNION_SUBDISP_CheckLineTouch(u8 *a0, char *a1, u8 *a2);
extern void UNION_SUBDISP_UpdateLineHighlights(char *p, u8 *q);
extern void UNION_MAIN_SetAppealNo(u8 *p, int v);

void UNION_SUBDISP_Update(char *p, int mode)
{
    void *s;
    u8 *q;
    u8 *r;
    int res;

    s = (void *)GAMESYSTEM_GetGameComm(((struct Obj01128 *)p)->f0);
    q = (u8 *)GAME_COMM_GetWork(s);
    if (q != 0) {
        r = q + 0x2830;
        if (r[0xe] == 1) {
            UNION_CHAT_LOG_Add((struct Ctx *)q, 0, (u16 *)(r + 4), r[0xf]);
            r[0xe] = 0;
        }
        UNION_SUBDISP_UpdateChatLines(p, q + 0x30E0);
        if (((struct Obj07628 *)q)->f351C >= 3)
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01128 *)p)->f2C, 1);
    }
    if (mode == 1) {
        res = UNION_SUBDISP_CheckTouch((int *)p, q);
        if (q != 0 && res == 1) {
            switch (((struct Obj01128 *)p)->f30) {
            case 0:
                break;
            case 1:
                UNION_COMM_SetChatType(q, 2);
                break;
            case 2:
                UNION_COMM_SetChatType(q, 3);
                break;
            case 3:
                break;
            case 4:
                UNION_COMM_SetChatType(q, 4);
                break;
            case 5:
                UNION_COMM_SetChatType(q, 5);
                break;
            }
        }
        ((struct Obj01128 *)p)->f31 = UNION_SUBDISP_UpdateKnobDrag(p);
        if (((struct Obj01128 *)p)->f31 == 0)
            ((struct Obj01128 *)p)->f31 = UNION_SUBDISP_CheckTrackTouch(p);
        if (((struct Obj01128 *)p)->f31 == 0 && q != 0)
            UNION_SUBDISP_PageScrollByButtons(p, q);
    }
    if (q != 0) {
        UNION_SUBDISP_SyncKnobAndScroll((char *)q, (unsigned char *)p);
        if (mode == 1)
            UNION_SUBDISP_CheckLineTouch(q, p, q + 0x30E0);
        UNION_SUBDISP_UpdateLineHighlights(p, q + 0x30E0);
    }
    if (GAME_COMM_GetKind(s) == 3 && q != 0)
        UNION_MAIN_SetAppealNo(q, ((struct Obj01128 *)p)->f30);
}
