/*
 * function: EVENT_TRAINER_GetBattleType
 * address:  0x0215A4C8
 * packet:   pkt_0215A4C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);

int EVENT_TRAINER_GetBattleType(int a0)
{
    int a1;

a1 = 2;
    a0 = TPOKE_DATA_GetRecordField((void *)a0, a1);
loc_0215A4D0:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}
