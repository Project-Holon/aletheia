/*
 * file:     unit_020730DC.c
 * unit:     yes
 * function: func_020730DC, func_02073108
 * address:  0x020730DC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct SNDTrackInfo;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub {
    u8  pad00[0x2c];
    u8  b2c;
    u8  pad2d[0x34 - 0x2d];
    u16 h34;
    u16 h36;
    u16 h38;
    u16 h3a;
    u8  b3c;
};

struct Obj { struct Sub * volatile p; };

extern int func_02072894(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);


/*
 * Three statements that each re-read o->p, so `volatile` on the pointer field
 *  * is load-bearing here too: it is what keeps the three loads. The three
 *  * statements also keep the early `bxeq lr`; the two-statement sibling
 *  * func_020730B8, byte for byte otherwise, is if-converted instead (see
 *  * docs/notes/pkt_02072EA8.c.txt).
 */
void func_020730DC(struct Obj *o, u32 a, u32 b)
{
    if (o->p == 0) return;
    o->p->h34 = 2;
    o->p->h38 = a;
    o->p->h3a = b;
}


/*
 * Returns 0 to the caller when the guarded pointer is null, and forwards its
 *  * own v and w to the callee (they are already in r1/r2, so the call sets only
 *  * r0).
 */
int func_02073108(struct Obj *o, int trackNo, struct SNDTrackInfo *trackInfo)
{
    if (o->p == 0) return 0;
    return func_02072894(o->p->b3c, trackNo, trackInfo);
}
