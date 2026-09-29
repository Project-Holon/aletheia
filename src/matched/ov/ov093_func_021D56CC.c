/*
 * function: func_021D56CC
 * address:  0x021D56CC
 * packet:   pkt_ov093_021D56CC
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
    u8 pad0[5];
    u8 lo5:4;
    u8 hi5:4;
    u8 pad6[5];
    u8 lo11:4;
    u8 hi11:4;
    u8 c;
    u8 padD;
};

struct Work {
    u8 pad0[0x104];
    struct Ent e[4];
    u8 pad13C[7];
    u8 c143;
};

void func_021D56CC(struct Work *p, u32 i)
{
    struct Ent *e = &p->e[i];
    if (e->hi11 == 0) {
        e->hi11 = 1;
        p->c143++;
    }
    e->lo11 = 1;
    if (e->c != 0) {
        e->lo5 = e->lo11;
        e->hi5 = e->hi11;
    }
}
