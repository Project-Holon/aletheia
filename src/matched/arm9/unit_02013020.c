/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_02013020, sub_02013050, sub_02013080
 * address:  0x02013020
 * packet:   pkt_02012F08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ptr_020A7298  0x020A7298  data
 *   data_0209DFB0 0x0209DFB0  data
 *   sub_0200873C  0x0200873C  thumb
 *   sub_02008374  0x02008374  thumb
 *
 * Mode mapping helpers calling clamped lookup sub_02013080.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013020.c \
 *       --addr 0x02013020 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *ptr_020A7298;
extern const signed char data_0209DFB0[];

extern void *sub_0200873C(void *sys);
extern u32 sub_02008374(void *obj);

signed char sub_02013080(u32 idx);

signed char sub_02013020(void)
{
    u32 val = sub_02008374(sub_0200873C(ptr_020A7298));
    switch (val) {
    case 0:
        val = 1;
        break;
    case 1:
        val = 2;
        break;
    case 2:
        val = 3;
        break;
    }
    return sub_02013080(val);
}

signed char sub_02013050(void)
{
    u32 val = sub_02008374(sub_0200873C(ptr_020A7298));
    switch (val) {
    case 0:
        val = 4;
        break;
    case 1:
        val = 0;
        break;
    case 2:
        val = 1;
        break;
    }
    return sub_02013080(val);
}

signed char sub_02013080(u32 idx)
{
    if (idx >= 5) {
        idx = 4;
    }
    return data_0209DFB0[idx];
}
