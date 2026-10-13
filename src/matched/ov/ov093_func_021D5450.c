/*
 * unit:     yes
 * function: BTL_POKEPARAM_CountRealMoves, BTL_POKEPARAM_CountUsedMoves
 * address:  0x021D5450
 * packet:   pkt_ov093_021D5450
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021D54A6 (n140 re-read as the loop bound of BTL_POKEPARAM_CountUsedMoves)
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Ent {
    u16 h0;
    u8 pad2[9];
    u8 lo11:4;
    u8 hi11:4;
    u8 fC;
    u8 fD;
};

struct Work {
    u8 pad0[0x104];
    struct Ent e[4];
    u8 pad13C[4];
    u8 n140;
};

u8 BTL_POKEPARAM_CountRealMoves(struct Work *p)
{
    u32 n;
    u32 i;
    i = 0;
    n = 0;
    for (; i < 4; i++) {
        if (p->e[i].h0 == 0) break;
        n++;
    }
    return n;
}

u8 BTL_POKEPARAM_CountUsedMoves(struct Work *p)
{
    u8 n;
    u8 i;
    i = 0;
    n = 0;
    for (; i < *(volatile u8 *)&p->n140; i++) {
        if (p->e[i].lo11 != 0) n++;
    }
    return n;
}
