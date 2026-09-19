/*
 * function: func_020730DC
 * address:  0x020730DC
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Three statements that each re-read o->p, so `volatile` on the pointer field
 *  * is load-bearing here too: it is what keeps the three loads. The three
 *  * statements also keep the early `bxeq lr`; the two-statement sibling
 *  * func_020730B8, byte for byte otherwise, is if-converted instead (see
 *  * docs/notes/pkt_02072EA8.c.txt).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8  pad00[0x34];
    u16 h34;
    u16 h36;
    u16 h38;
    u16 h3a;
};
struct Obj { struct Sub * volatile p; };

void func_020730DC(struct Obj *o, u16 a, u16 b)
{
    if (o->p == 0) return;
    o->p->h34 = 2;
    o->p->h38 = a;
    o->p->h3a = b;
}
