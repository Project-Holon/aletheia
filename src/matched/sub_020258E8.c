/*
 * function: func_020258E8
 * address:  0x020258E8
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0204B454  0x0204B454  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct PtS {
    s16 x;
    s16 y;
};

struct Actor;

struct Obj02025774 {
    u8            pad00[4];
    struct Actor *actor;
    u8            pad08[0xc0];
    u16           space;
};

extern void sub_0204B454(struct Actor *actor, struct PtS *out, u32 space);

void func_020258E8(struct Obj02025774 *p, s16 *out_x, s16 *out_y)
{
    struct PtS pt;

    sub_0204B454(p->actor, &pt, p->space);
    *out_x = pt.x;
    *out_y = pt.y;
}
