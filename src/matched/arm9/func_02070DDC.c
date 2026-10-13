/*
 * function: NNSi_G3dGetJointScaleMaya
 * address:  0x02070DDC
 * packet:   pkt_02070DDC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PIN: ../2.0/sp2, the same pin its packet-mate src/matched/func_02070F2C.c
 * carries, here on the "kept branches" tell combined with the re-read tell.
 * The image keeps `beq 0x02070EF4` (`03 00 00 0a`) at 0x02070EE0 over the
 * THREE-instruction guard body at 0x02070EE4..0x02070EEC
 * (`00 00 9c e5` ldr r0,[ip] / `08 00 80 e3` orr r0,r0,#8 /
 * `00 00 8c e5` str r0,[ip]), closing it with `b 0x02070F0C`
 * (`05 00 00 ea`) at 0x02070EF0, and the guard body RE-READS the flags word
 * the `str r1, [ip]` at 0x02070EC0 has just written.  1.1p1 -O4,p predicates
 * the block AND forwards the still-live value, emitting
 * `orrne r0, r3, #8` / `strne r0, [ip]` / `bne`, giving 328 bytes against the
 * original's 336 with every byte before 0x02070EAC identical modulo the
 * eight-byte pool displacement.  Under the pin the same C is 336 bytes,
 * 0 mismatches.
 *
 * The C lever, needed under BOTH front ends: the three-word row copy at
 * 0x02070F04/0x02070F08 (`ldm r0, {r0, r1, r2}` / `stm r3, {r0, r1, r2}`) is
 * a struct assignment, not three field assignments.  Written out field by
 * field, 1.1p1 and 2.0 both emit three `ldr`/`str` pairs off separate pool
 * words: 344 bytes and 298 concrete out.
 *
 * symbols:
 *   gCurrentRS  0x02148DB0  data
 *   g_02149BC0  0x02149BC0  data
 */

#include "../include/G_Root.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Vec { s32 a, b, c; };

struct Owner {
    u32 flags;   /* 0x00 */
    s32 f04;
    s32 f08;
    s32 f0c;
    struct Vec v10;   /* 0x10 */
};

struct Desc {
    u8 f00;
    u8 idx;      /* 0x01 */
    u8 slot;     /* 0x02 */
    u8 mode;     /* 0x03 */
};

struct Row { struct Vec v; s32 pad[3]; };  /* 0x18 bytes */

extern struct Root *gCurrentRS;
extern struct Row  g_02149BC0[];

void NNSi_G3dGetJointScaleMaya(struct Owner *oo, s32 *src, struct Desc *d, u32 f)
{
    struct Owner *o = oo;
    u32 m;

    m = d->mode;

    if (f & 4) {
        o->flags |= 1;
        if (m & 2) {
            u32 i = d->idx;
            gCurrentRS->bits[i >> 5] |= 1U << (i & 0x1f);
        }
    } else {
        o->f04 = src[0];
        o->f08 = src[1];
        o->f0c = src[2];
        if (m & 2) {
            u32 i = d->idx;
            gCurrentRS->bits[i >> 5] &= ~(1U << (i & 0x1f));
            g_02149BC0[i].v.a = src[3];
            g_02149BC0[i].v.b = src[4];
            g_02149BC0[i].v.c = src[5];
        }
    }

    if (m & 1) {
        u32 j = d->slot;
        o->flags |= 0x20;
        if (gCurrentRS->bits[j >> 5] & (1U << (j & 0x1f))) {
            o->flags |= 8;
        } else {
            o->v10 = g_02149BC0[j].v;
        }
    }

    o->flags |= 0x10;
}
