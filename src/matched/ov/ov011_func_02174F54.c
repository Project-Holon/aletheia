/*
 * function: INTRUDE_COMM_StorePlayerRecord
 * address:  0x02174F54
 * packet:   pkt_ov011_02174F54
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   GAME_COMM_UpdatePlayerStatus  0x020264B4  thumb
 *   func_02039338  0x02039338  arm
 *   INTRUDE_COMM_AdjustRemotePosition  0x021751D4  thumb ov011
 */
#include "../include/Obj00269.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u32 f0;
    u8 pad4[0x10];
    u16 f14;
    u16 a : 3;
    u16 rest : 13;
    u8 pad18[3];
    u8 lo : 6;
    u8 mid : 1;
    u8 hi : 1;
} Ent;

typedef struct Cp {
    int w[5];
} Cp;

void func_02082D44(const Ent *a, Ent *b, int c);
void GAME_COMM_UpdatePlayerStatus(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag);
u16 func_02039338(void);
void INTRUDE_COMM_AdjustRemotePosition(u8 *p, u16 a, int b, struct Ent *c);

void INTRUDE_COMM_StorePlayerRecord(u8 *p, int idx, const Ent *src, int arg)
{
    Ent *e;
    u32 saved;

    e = (Ent *)(p + 0x8C) + idx;
    saved = e->f0;
    func_02082D44(src, e, 0x1C);
    e->f0 = saved;
    e->hi = (u8)src->f0;
    if (src->f0 == 1) {
        e->f0 = 1;
    }
    GAME_COMM_UpdatePlayerStatus((void *)(((struct Obj00269 *)p)->f4), idx, e->f14, (u8)e->a, e->lo, arg);
    if (idx != func_02039338()) {
        *((Cp *)(p + 0xE0) + idx) = *(Cp *)e;
        INTRUDE_COMM_AdjustRemotePosition(p, ((struct Obj00269 *)p)->f84, ((struct Obj00269 *)p)->f74, e);
    }
    p[0x927] |= (u8)(1 << idx);
}
