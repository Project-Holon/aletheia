/*
 * function: BEACON_VIEW_SetupEntry
 * address:  0x021F1144
 * packet:   pkt_ov032_021F1144
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetTrainerId  0x02165CE4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPlayerName  0x02165C34  thumb  ov010
 *   STRBUF_Clear  0x0204581C  arm
 *   GAME_BEACON_ACCESSOR_GetGreeting  0x02165D50  thumb  ov010
 *   BEACON_VIEW_PrintEntryRank  0x021F10D8  thumb  ov032
 *   BEACON_VIEW_LoadEntryPanel  0x021F0F74  thumb  ov032
 *   BEACON_VIEW_LoadEntryPanelColor  0x021F1004  thumb  ov032
 *   GAME_BEACON_ACCESSOR_GetActionNo  0x02165E24  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetThanksName  0x02165D6C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetFreeText  0x02165D8C  thumb  ov010
 *   BEACON_VIEW_PrintEntryName  0x021F1070  thumb  ov032
 *   BEACON_VIEW_StartIconWait  0x021F1E40  thumb  ov032
 *   BEACON_VIEW_PrintEntryFrames  0x021F1080  thumb  ov032
 */
#include "../include/Obj00007.h"
#include "../include/Obj00225.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
struct U16Vec;
extern u16 GAME_BEACON_ACCESSOR_GetTrainerId(u8 *r);
extern u8 GAME_BEACON_ACCESSOR_GetSex(struct Rec *r);
extern void GAME_BEACON_ACCESSOR_GetPlayerName(struct Rec *r, void *buf);
extern void STRBUF_Clear(struct U16Vec *vec);
struct Strbuf;
extern void GAME_BEACON_ACCESSOR_GetGreeting(struct Rec *r, struct Strbuf *buf);
extern void BEACON_VIEW_PrintEntryRank(char *this, u8 *p, int a);
extern void BEACON_VIEW_LoadEntryPanel(char *p, u8 *q, void *r);
extern void BEACON_VIEW_LoadEntryPanelColor(char *p, u8 *q, int r);
extern int GAME_BEACON_ACCESSOR_GetActionNo(int a0);
extern int GAME_BEACON_ACCESSOR_GetThanksName(int a0, int a1);
extern int GAME_BEACON_ACCESSOR_GetFreeText(int a0, int a1);
extern void BEACON_VIEW_PrintEntryName(char *p, char *q, void *text, int a4);
extern void BEACON_VIEW_StartIconWait(char *p, char *q, void *x, int flag);
extern void BEACON_VIEW_PrintEntryFrames(char *p, char *q, int r, int t);

void BEACON_VIEW_SetupEntry(u8 *p, u8 *q, void *r, int mode, int skip, int t)
{
    ((struct Obj00225 *)q)->f6 = GAME_BEACON_ACCESSOR_GetTrainerId(r);
    q[4] = GAME_BEACON_ACCESSOR_GetSex(r);
    GAME_BEACON_ACCESSOR_GetPlayerName(r, ((struct Obj00225 *)q)->f24);
    STRBUF_Clear(((struct Obj00225 *)q)->f20);
    GAME_BEACON_ACCESSOR_GetGreeting(r, ((struct Obj00225 *)q)->f20);
    BEACON_VIEW_PrintEntryRank((char *)p, q, (int)r);
    BEACON_VIEW_LoadEntryPanel((char *)p, q, r);
    BEACON_VIEW_LoadEntryPanelColor((char *)p, q, (int)r);
    if (skip != 0)
        return;
    switch (mode) {
    case 0:
        switch (GAME_BEACON_ACCESSOR_GetActionNo((int)r)) {
        case 0x18:
            GAME_BEACON_ACCESSOR_GetThanksName((int)r, (int)(((struct Obj00007 *)p)->f118));
            BEACON_VIEW_PrintEntryName((char *)p, (char *)q, ((struct Obj00007 *)p)->f118, t);
            break;
        case 0x31:
            GAME_BEACON_ACCESSOR_GetFreeText((int)r, (int)(((struct Obj00007 *)p)->f118));
            BEACON_VIEW_PrintEntryName((char *)p, (char *)q, ((struct Obj00007 *)p)->f118, t);
            break;
        }
        BEACON_VIEW_StartIconWait((char *)p, (char *)q, r, 0);
        break;
    case 1:
        BEACON_VIEW_PrintEntryName((char *)p, (char *)q, ((struct Obj00225 *)q)->f20, t);
        BEACON_VIEW_StartIconWait((char *)p, (char *)q, r, 1);
        break;
    case 2:
        BEACON_VIEW_PrintEntryFrames((char *)p, (char *)q, 1, t);
        break;
    }
}
