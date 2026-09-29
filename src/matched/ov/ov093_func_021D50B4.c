/*
 * function: func_021D50B4
 * address:  0x021D50B4
 * packet:   pkt_ov093_021D50B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5244  0x021D5244  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Ent {
    u16 h[6];
    u8 fC;
    u8 fD;
};

struct Work {
    void *h;
    u8 pad4[0x100];
    struct Ent e[4];
    u8 pad13C[4];
    u8 n140;
};

extern int func_021D5244(struct Ent *e, void *h, u8 k);

void func_021D50B4(struct Work *p)
{
    void *h = p->h;
    u32 i;
    p->n140 = 0;
    for (i = 0; i < 4; i++) {
        if (func_021D5244(&p->e[i], h, i)) p->n140++;
        if (p->e[i].fC != 0) {
            p->e[i].h[3] = p->e[i].h[0];
            p->e[i].h[4] = p->e[i].h[1];
            p->e[i].h[5] = p->e[i].h[2];
        }
    }
}
