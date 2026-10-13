/*
 * function: FIELD_SOUND_SYSTEM_GetTrainerClassBgm
 * address:  0x02029E20
 * packet:   pkt_02029E20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sTrainerClassBgmTable  0x020A75A8  data
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 key; u16 val; } Pair;
extern Pair sTrainerClassBgmTable[];

u16 FIELD_SOUND_SYSTEM_GetTrainerClassBgm(u32 k)
{
    int i;
    for (i = 0; sTrainerClassBgmTable[i].key != 0x69; i++) {
        if (k == sTrainerClassBgmTable[i].key)
            return sTrainerClassBgmTable[i].val;
    }
    return 0x45A;
}
