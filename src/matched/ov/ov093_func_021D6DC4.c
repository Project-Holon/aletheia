/*
 * unit:     yes
 * function: BTL_POKEPARAM_ClearFoughtList, BTL_POKEPARAM_AddFoughtPoke
 * address:  0x021D6DC4
 * packet:   pkt_ov093_021D6DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

void BTL_POKEPARAM_ClearFoughtList(u8 *p)
{
    p[0xd0] = 0;
}

void BTL_POKEPARAM_AddFoughtPoke(u8 *p, u32 v)
{
    u32 i;
    u8 n = p[0xd0];

    for (i = 0; i < n; i++) {
        if (v == (p + i)[0xd1]) return;
    }
    if (i < 0x18) {
        (p + i)[0xd1] = v;
        p[0xd0]++;
    }
}
