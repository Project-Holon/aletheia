/*
 * function: TPOKE_DATA_IsRecordKindTwo
 * address:  0x0202A19C
 * packet:   pkt_0202A19C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   TPOKE_DATA_GetEntryIndex  0x0202A20C  thumb
 *   TPOKE_DATA_GetRecordPtr  0x0202A21C  thumb
 */
#include "../include/Obj15810.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  TPOKE_DATA_GetEntryIndex(u8 *p, u32 key, u32 v2, u32 v3);
extern int TPOKE_DATA_GetRecordPtr(int a0, int a1);

int TPOKE_DATA_IsRecordKindTwo(u32 a, u32 *p, u32 c, u32 d, u16 e)
{
    int i = TPOKE_DATA_GetEntryIndex((u8 *)p, c, d, e);
    u8 *r = (u8 *)TPOKE_DATA_GetRecordPtr((int)p, *(u16 *)((u8 *)*p + i * 8 + 6));

    if (((struct Obj15810 *)r)->f7 == 2) {
        return 1;
    }
    return 0;
}
