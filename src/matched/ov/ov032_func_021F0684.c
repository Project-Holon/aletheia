/*
 * function: BEACON_VIEW_CountDifferingRecords
 * address:  0x021F0684
 * packet:   pkt_ov032_021F0684
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_TableRingGet  0x02165AC4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPmVersion  0x02165C48  thumb  ov010
 */
#include "../include/Obj04310.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Queue;
struct Rec;
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern u8 GAME_BEACON_ACCESSOR_GetSex(struct Rec *r);
extern u32 GAME_BEACON_ACCESSOR_GetPmVersion(u32 rec);

void BEACON_VIEW_CountDifferingRecords(u8 *p, u8 *a, u8 *b)
{
    int i = 0;
    u16 tag;

    *a = 0;
    *b = 0;
    for (; i < p[0x7b]; i++) {
        GAME_BEACON_ACCESSOR_TableRingGet((struct Queue *)(((struct Obj04310 *)p)->f3C), (struct Rec *)(((struct Obj04310 *)p)->f44), &tag, i);
        if (p[0x30] != GAME_BEACON_ACCESSOR_GetSex((struct Rec *)(((struct Obj04310 *)p)->f44)))
            (*a)++;
        if (p[0x32] != GAME_BEACON_ACCESSOR_GetPmVersion(((struct Obj04310 *)p)->f44))
            (*b)++;
    }
}
