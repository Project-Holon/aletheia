/*
 * function: BTL_POKEPARAM_ResetBattleMoves
 * address:  0x021D5150
 * packet:   pkt_ov093_021D5150
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Ent {
    u16 h[6];
    u8 fC;
    u8 fD;
};

struct Work {
    u8 pad0[0x104];
    struct Ent e[4];
    u8 pad13C[4];
    u8 n140;
};

void BTL_POKEPARAM_ResetBattleMoves(struct Work *p)
{
    u32 i;
    p->n140 = 0;
    for (i = 0; i < 4; i++) {
        p->e[i].h[3] = p->e[i].h[0];
        p->e[i].h[4] = p->e[i].h[1];
        p->e[i].h[5] = p->e[i].h[2];
        if (p->e[i].h[3] != 0) p->n140++;
        p->e[i].fC = 1;
    }
}
