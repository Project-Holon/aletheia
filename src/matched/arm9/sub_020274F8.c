/*
 * function: GAME_BEACON_ClearFlags
 * address:  0x020274F8
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_BEACON_Work  0x02146940  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BeaconSys {
    u8 pad[0x62];
    u8 field_62;
    u8 pad2[0xBA4 - 0x63];
    u32 field_BA4;
};

extern struct BeaconSys *GAME_BEACON_Work;

void GAME_BEACON_ClearFlags(void)
{
    if (GAME_BEACON_Work != 0) {
        GAME_BEACON_Work->field_BA4 = 0;
        GAME_BEACON_Work->field_62 = 0;
        GAME_BEACON_Work->field_BA4 = 0;
    }
}
