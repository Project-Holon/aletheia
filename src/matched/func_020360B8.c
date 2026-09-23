/*
 * function: func_020360B8
 * address:  0x020360B8
 * packet:   pkt_020360B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * key.c.  Walks a run of 12-byte entries from o->f00 + o->f08 * 12 and
 * applies each entry's mask/value pair to the three state words at
 * +0x1c/+0x18/+0x20: case 1 ORs the value in where the mask matches, case 2
 * swaps the two bit groups (m2), case 3 clears the mask's bits, and case 0
 * ends the walk.  The function has no relocations; its one pooled word is the
 * constant 0x0000FFFF.
 *
 * What closed it (wave 13): the case-2 accumulator is a FRESH zero per field
 * (`u32 v = 0;` inside a per-field helper, or equally a block-scoped local).
 * The three zeros are three distinct values that the optimiser hoists as
 * r3/r2/r1 ahead of the loop, and that is what leaves lr, the highest
 * callee-saved register, for 0xFFFF.  The earlier source kept three
 * function-scope accumulators a, b, c = 0 and copied them into one v per arm;
 * every instruction was right but 0xFFFF and the arm temporaries rotated
 * through r4/r5/r6/lr (127 bytes).  The two compound statements
 * `*f &= mask; *f |= v;` (not one merged assignment) are still what
 * re-reads the field before the AND.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent {
    u32 f00;
    u32 f04;
    u8  f08;
    u8  pad09[3];
};

struct Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad0c[0xc];
    u32 f18;
    u32 f1c;
    u32 f20;
};

static inline void m2(u32 *f, struct Ent *p)
{
    u32 v = 0;
    if (*f & p->f00)
        v |= p->f04;
    if (*f & p->f04)
        v |= p->f00;
    *f &= (p->f00 | p->f04) ^ 0xffff;
    *f |= v;
}
static inline void m1(u32 *f, struct Ent *p)
{
    if (*f & p->f00)
        *f |= p->f04;
}
static inline void m3(u32 *f, struct Ent *p)
{
    *f &= p->f00 ^ 0xffff;
}
void func_020360B8(struct Obj *o)
{
    struct Ent *p;

    if (o->f00 == 0)
        return;

    p = (struct Ent *)(o->f00 + o->f08 * 12);

    for (;;) {
        switch (p->f08) {
        case 0:
            return;
        case 1:
            m1(&o->f1c, p);
            m1(&o->f18, p);
            m1(&o->f20, p);
            break;
        case 2:
            m2(&o->f1c, p);
            m2(&o->f18, p);
            m2(&o->f20, p);
            break;
        case 3:
            m3(&o->f1c, p);
            m3(&o->f18, p);
            m3(&o->f20, p);
            break;
        }
        p++;
    }
}
