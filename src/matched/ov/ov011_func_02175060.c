/*
 * function: INTRUDE_COMM_UpdatePlayerObject
 * address:  0x02175060
 * packet:   pkt_ov011_02175060
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   ZONEDATA_IsSameMatrixGroup  0x02013E90  thumb
 *   COMM_PLAYER_CheckOccupy  0x021677E4  thumb  ov010
 *   func_02026478  0x02026478  thumb
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb  ov010
 *   INTRUDE_COMM_GetPlayerObjCode  0x02175598  thumb  ov011
 *   COMM_PLAYER_GetObjCode  0x02167810  thumb  ov010
 *   COMM_PLAYER_Del  0x02167658  thumb  ov010
 *   COMM_PLAYER_Add  0x021675D0  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05913.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u32 f0;
    u8 pad4[0xe];
    u8 f12;
    u8 pad13;
    u16 f14;
    u16 a : 3;
    u16 b : 6;
    u16 f18;
    u8 pad1a;
    u8 pad1b : 7;
    u8 hi : 1;
} Entry;

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 func_02013D5C(u32 id);
extern u32 func_02013D9C(u32 id);
extern u32 ZONEDATA_IsSameMatrixGroup(u32 a, u32 b);
struct Work;
extern int COMM_PLAYER_CheckOccupy(void *p, int i);
extern u32 func_02026478(void *obj);
extern int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
extern u16 INTRUDE_COMM_GetPlayerObjCode(u8 *o, u32 id);
extern u16 COMM_PLAYER_GetObjCode(struct Work *w, int i);
extern void COMM_PLAYER_Del(int, int);
struct Src;
extern void COMM_PLAYER_Add(struct Work *w, int idx, int a2, struct Src *src);

static inline int func_02175060_check(Entry *e, Entry *me)
{
    if (e->hi == 1) {
        return 1;
    }
    if (e->f12 != 0 && e->f12 != 1) {
        return 1;
    }
    if (func_02013D5C(e->f14) == 1 && func_02013D5C(me->f14) == 1) {
        return 0;
    }
    if (e->a == me->a) {
        if (func_02013D9C(e->f14) == 1 && func_02013D9C(me->f14) == 1) {
            if (e->b == me->b) {
                return 0;
            }
            return 1;
        }
        if (ZONEDATA_IsSameMatrixGroup(me->f14, e->f14) == 1) {
            return 0;
        }
        return 1;
    }
    return 1;
}

void INTRUDE_COMM_UpdatePlayerObject(u8 *p, int idx)
{
    Entry *e;
    int r;

    e = (Entry *)(p + 0x8c) + idx;
    if (idx != GFL_NET_SYSTEM_GetCurrentAid()) {
        Entry *me = (Entry *)(p + 0x70);
        e->f0 = func_02175060_check(e, me);
    }
    if (COMM_PLAYER_CheckOccupy((void *)(((struct Obj05913 *)p)->f8), idx) == 1) {
        r = INTRUDE_COMM_GetPlayerObjCode((u8 *)e, GAME_DATA_GetMyStatusByNetId((void *)func_02026478((void *)(((struct Obj05913 *)p)->f4)), idx));
        if (r != COMM_PLAYER_GetObjCode((struct Work *)(((struct Obj05913 *)p)->f8), idx)) {
            COMM_PLAYER_Del(((struct Obj05913 *)p)->f8, idx);
            if (e->f18 != 0) {
                COMM_PLAYER_Add((struct Work *)(((struct Obj05913 *)p)->f8), idx, r, (struct Src *)e);
            }
        }
    }
}
