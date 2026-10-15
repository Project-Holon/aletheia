/*
 * function: TPOKE_DATA_GetTrainerGroup
 * address:  0x0202A420
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TPOKE_DATA_FindTrainerType   0x0202A3D8  thumb
 *   gTpokeDataTrainerKindTable  0x0209FEE4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Record {
    u16 val : 7;
    u16 field2 : 4;
    u16 rest : 5;
};

extern u8 TPOKE_DATA_FindTrainerType(u32 key);
extern const struct Record gTpokeDataTrainerKindTable[];

u32 TPOKE_DATA_GetTrainerGroup(u32 key)
{
    u8 idx = TPOKE_DATA_FindTrainerType(key);
    if (idx >= 0x1c) {
        return 0x11;
    }
    return gTpokeDataTrainerKindTable[idx].rest;
}
