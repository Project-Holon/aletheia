/*
 * function: func_02051838
 * address:  0x02051838
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * particle.c (wave 13): the emitter's three-word position at +0x28..+0x30 is
 * the caller's vector plus the vector at +4 of the block the private 3D
 * block's first word names (+0x20 -> +0x00 -> +0x04/+0x08/+0x0C).
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051838.c.txt: 72 against 72 with 10 bytes
 * out via a `volatile` parameter, permuter exhausted at 3000): the caller's
 * vector is a `const VecFx32 *`.  mwccarm lets a load through a const-
 * qualified pointer move above a store through a non-const one, so all three
 * q reads are hoisted to the top in the image's order (r4, r3, r2 -- a
 * descending run the peephole cannot merge into one ldm), while the block's
 * inner pointer is still re-read before each sum because the stores to the
 * emitter may alias it.  No named locals: each component is one statement.
 * The `volatile` spelling only imitated that hoisting and allocated
 * differently; plain non-const spellings keep the q reads in place and merge
 * two of them into an ldm (68 bytes).
 */

typedef unsigned int u32;

typedef struct { u32 x, y, z; } VecFx32;

struct ParticleInner {
    u32     f00;
    VecFx32 pos;            /* +0x04 */
};

struct ParticleBlk {
    struct ParticleInner *inner;    /* +0x00, re-read per statement */
};

struct ParticleEmitter {
    char                pad00[0x20];
    struct ParticleBlk *blk;        /* +0x20 */
    char                pad24[0x04];
    VecFx32             pos;        /* +0x28 */
};

void func_02051838(struct ParticleEmitter *e, const VecFx32 *q)
{
    e->pos.x = q->x + e->blk->inner->pos.x;
    e->pos.y = q->y + e->blk->inner->pos.y;
    e->pos.z = q->z + e->blk->inner->pos.z;
}
