/*
 * function: TPOKE_DATA_FindTrainerType
 * address:  0x0202A3D8
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gTpokeDataTrainerKindTable  0x0209FEE4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Record {
    u16 val : 7;
    u16 rest : 9;
};

extern const struct Record gTpokeDataTrainerKindTable[];

u8 TPOKE_DATA_FindTrainerType(u32 key)
{
    int i;

    for (i = 0; i < 0x1c; i++) {
        if (key == gTpokeDataTrainerKindTable[i].val) {
            return (u8)i;
        }
    }
    return 0x1c;
}
