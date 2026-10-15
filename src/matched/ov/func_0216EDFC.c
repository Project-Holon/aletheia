/*
 * function: EVENT_BATTLE_GetBattleKindClass
 * address:  0x0216EDFC
 * packet:   pkt_0216EDFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Mode word out of the overlay call decides between zero, one and two;
 * two of the modes are refused outright.
 *
 * symbols:
 *   TPOKE_DATA_GetRecordField   0x0202A230  thumb
 *   TPOKE_DATA_GetTrainerKind   0x0202A3FC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);
extern u8 TPOKE_DATA_GetTrainerKind(u32 key);

int EVENT_BATTLE_GetBattleKindClass(void *a0)
{
    int r = 1;
    int v;

    v = TPOKE_DATA_GetTrainerKind(TPOKE_DATA_GetRecordField(a0, 1));

    if (v == 0xC || v == 9)
        return 0;
    if (v != 2)
        r = 2;

    return r;
}

