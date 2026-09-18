/*
 * function: func_020274F8
 * address:  0x020274F8
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_02146940  0x02146940  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BeaconSys {
    u8 pad[0x62];
    u8 field_62;
    u8 pad2[0xBA4 - 0x63];
    u32 field_BA4;
};

extern struct BeaconSys *g_02146940;

void func_020274F8(void)
{
    if (g_02146940 != 0) {
        g_02146940->field_BA4 = 0;
        g_02146940->field_62 = 0;
        g_02146940->field_BA4 = 0;
    }
}
