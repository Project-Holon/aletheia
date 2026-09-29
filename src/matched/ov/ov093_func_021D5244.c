/*
 * function: func_021D5244
 * address:  0x021D5244
 * packet:   pkt_ov093_021D5244
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Ent {
    u16 id;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 lo5:4;
    u8 hi5:4;
};

extern u32 func_02017E1C(void *h, u32 k, u32 z);

int func_021D5244(struct Ent *e, void *h, u8 k)
{
    int r = 1;
    u16 v = func_02017E1C(h, k + 0x36, 0);
    if (e->id != v) {
        e->lo5 = 0;
        e->hi5 = 0;
    }
    e->id = v;
    if (e->id != 0) {
        e->b2 = func_02017E1C(h, k + 0x3a, 0);
        e->b3 = func_02017E1C(h, k + 0x42, 0);
        e->b4 = func_02017E1C(h, k + 0x3e, 0);
    } else {
        r = 0;
        e->b2 = 0;
        e->b3 = 0;
        e->b4 = 0;
    }
    return r;
}
