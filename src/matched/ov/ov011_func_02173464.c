/*
 * function: INTRUDE_COMM_SyncPlayers
 * address:  0x02173464
 * packet:   pkt_ov011_02173464
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   INTRUDE_FIELD_IsListedZone  0x0217C11C  thumb  ov018
 *   COMM_PLAYER_ClearPending  0x02167794  thumb  ov010
 *   COMM_PLAYER_Resume  0x021676E4  thumb  ov010
 *   COMM_PLAYER_CheckOccupy  0x021677E4  thumb  ov010
 *   COMM_PLAYER_SetPackage  0x02167848  thumb  ov010
 *   INTRUDE_COMM_StorePlayerRecord  0x02174F54  thumb  ov011
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19161.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Head {
    u32 f0;
    u32 w[4];
} Head;

typedef struct Entry {
    Head h;
    u16 f14;
    u16 a : 3;
    u16 b : 6;
    u16 f18;
    u8 pad1a;
    u8 pad1b : 7;
    u8 hi : 1;
} Entry;

typedef struct Obj {
    u8 pad0[8];
    int f8;
    u8 padc[0x80];
    Entry ents[3];
    u8 pad[0x8fb - 0x8c - 3 * 0x1c];
    u8 mask;
} Obj;

struct BigObj;
struct Work;
extern u32 GAME_COMM_GetGameData(void *obj);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern int INTRUDE_FIELD_IsListedZone(u32 value);
extern void COMM_PLAYER_ClearPending(struct Work *w);
extern void COMM_PLAYER_Resume(struct Work *w);
extern int COMM_PLAYER_CheckOccupy(void *p, int i);
extern void COMM_PLAYER_SetPackage(char *a0, int a1, char *a2);
struct Ent;
extern void INTRUDE_COMM_StorePlayerRecord(u8 *p, int idx, const struct Ent *src, int arg);

void INTRUDE_COMM_SyncPlayers(u8 *a0, Obj *p, int a2)
{
    int h;
    int me;
    int i;
    Head tmp;

    if (p == 0) {
        return;
    }
    h = GAME_COMM_GetGameData((void *)(((struct Obj19161 *)a0)->f4));
    me = GAME_DATA_GetExitMode((const struct BigObj *)h);
    if (GAME_DATA_GetIntrudeCount((const struct BigObj *)h) == 0) {
        if (INTRUDE_FIELD_IsListedZone(FIELDMAP_GetZoneId((u8 *)a2)) == 1) {
            COMM_PLAYER_Resume((struct Work *)p->f8);
        } else {
            COMM_PLAYER_ClearPending((struct Work *)p->f8);
        }
    } else {
        COMM_PLAYER_Resume((struct Work *)p->f8);
    }
    for (i = 0; i < 3; i++) {
        if (i != me && COMM_PLAYER_CheckOccupy((void *)p->f8, i) == 1) {
            p->ents[i].h.f0 = p->ents[i].hi;
            tmp = p->ents[i].h;
            tmp.f0 = 1;
            COMM_PLAYER_SetPackage((char *)p->f8, i, (char *)(&tmp));
        }
    }
    for (i = 0; i < 3; i++) {
        if (i != me && (p->mask & (1 << i))) {
            int hi = p->ents[i].hi;
            INTRUDE_COMM_StorePlayerRecord((u8 *)p, i, (const struct Ent *)(&p->ents[i]), 0);
            p->ents[i].hi = hi;
        }
    }
}
