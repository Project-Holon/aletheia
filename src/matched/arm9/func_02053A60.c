/*
 * function: SPL_EMITTER_SetupResource
 * address:  0x02053A60
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The particle/rig emitter-instance initialiser: copies a resource
 * descriptor's fields into a live instance block, offsetting the instance's
 * position by the descriptor's own offset, and turning two pairs of 2-bit
 * scale-exponent fields plus their sign bits into the four s16 scale values
 * at +0x78..+0x7e.
 *
 * THIS CLOSES docs/notes/pkt_02053A60.c.txt, which concluded the row was an
 * unresolvable "arm7tdmi epilogue versus v5TE smulbb" conflict.  It is not a
 * conflict: the note only ever measured 1.1p1, where the row is 708 bytes /
 * 66 out at arm946e and 712 / 73 at arm7tdmi.  Under THIS RANGE'S FAMILY PIN,
 * `../1.2/sp2 -proc arm946e`, the note's own source is 716/716 with 17
 * concrete bytes out, and both horns of the supposed conflict vanish at once:
 * 1.2 emits the ARMv4T `pop {r4, r5, r6, lr}; bx lr` return AND the four
 * `smulbb` from `(s16)(x * -1)`.  Same tell as the rest of the
 * 0x0205429C..0x020584E0 3D-rig unit (docs/FRONTEND-PINS.md).
 *
 * THREE SPELLINGS ARE LOAD-BEARING on top of the note's source, the last two
 * found by tools/permuter.py (--mode anneal --focus pos,f28,f2c,f30,cfg,
 * EXACT at compile 321 from a 13-byte residue):
 *   1. `volatile struct Res0 *r` for the cached descriptor pointer around the
 *      +0x50/+0x52/+0x54 halfword copies.  Without volatile the two `ldrh`
 *      for f1c/f1e swap registers (the note's residue, 4 instructions).
 *   2. `const struct Vec3 *pos`, NOT `const volatile`.  With volatile the
 *      three position adds and the descriptor chain that feeds them are 10
 *      instructions of register naming out.
 *   3. `pos->x + o->f20->f00->f04`, position FIRST.  Field-first is the
 *      note's order and costs the same 10 instructions in the other
 *      direction (cmp/commutative operand order names the temporary).
 * The rest of the source, the every-time re-read of `o->f20->f00` for each
 * copied field, the `volatile struct Obj *o`, and `(s16)(x * -1)` for the
 * sign flips, is the note's and is unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_SetupResource.c \
 *       --func SPL_EMITTER_SetupResource --addr 0x02053A60 --arm --cc ../1.2/sp2
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
struct Res0
{
  u32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  s32 f14;
  s32 f18;
  u16 f1c;
  u16 f1e;
  u16 f20;
  u16 f22;
  s32 f24;
  s32 f28;
  s32 f2c;
  s32 f30;
  s32 f34;
  u16 f38;
  u16 f3a;
  u16 f3c;
  u16 f3e;
  s32 f40;
  u8 f44;
  u8 f45;
  u8 f46;
  u8 f47;
  u32 f48;
  u32 f4c;
};
struct Sub14
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  u32 f10;
};
struct Cfg
{
  struct Res0 *f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  struct Sub14 *f14;
};
struct Vec3
{
  s32 x;
  s32 y;
  s32 z;
};
struct Obj
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  s32 f14;
  s32 f18;
  s32 f1c;
  struct Cfg *f20;
  s32 f24;
  s32 f28;
  s32 f2c;
  s32 f30;
  s32 f34;
  s32 f38;
  s32 f3c;
  s32 f40;
  s32 f44;
  s32 f48;
  u16 f4c;
  u16 f4e;
  u16 f50;
  u16 f52;
  u16 f54;
  u16 f56;
  s32 f58;
  s32 f5c;
  s32 f60;
  s32 f64;
  s32 f68;
  s32 f6c;
  u16 f70;
  u16 f72;
  u32 f74;
  s16 f78;
  s16 f7a;
  s16 f7c;
  s16 f7e;
  u32 f80;
  s32 f84;
  s32 f88;
  s32 f8c;
  s32 f90;
  s32 f94;
  s32 f98;
};
void SPL_EMITTER_SetupResource(volatile struct Obj *o, struct Cfg *cfg, const struct Vec3 *pos)
{
  volatile struct Res0 *r;
  struct Cfg *c;
  o->f20 = cfg;
  o->f24 = 0;
  o->f28 = pos->x + o->f20->f00->f04;
  o->f2c = pos->y + o->f20->f00->f08;
  o->f30 = pos->z + o->f20->f00->f0c;
  o->f40 = 0;
  o->f44 = 0;
  o->f48 = 0;
  o->f3c = 0;
  o->f38 = o->f3c;
  o->f34 = o->f38;
  o->f4c = 0;
  o->f4e = 0;
  r = o->f20->f00;
  {
    u16 h0 = r->f1c;
    u16 h1 = r->f1e;
    o->f50 = h0;
    o->f52 = h1;
  }
  o->f54 = r->f20;
  o->f56 = o->f20->f00->f38;
  o->f58 = o->f20->f00->f10;
  o->f5c = o->f20->f00->f14;
  o->f60 = o->f20->f00->f18;
  o->f64 = o->f20->f00->f24;
  o->f68 = o->f20->f00->f28;
  o->f6c = o->f20->f00->f2c;
  o->f70 = o->f20->f00->f3e;
  o->f72 = 0x7fff;
  *((u8 *) (&o->f80)) = o->f20->f00->f44;
  *(((u8 *) (&o->f80)) + 1) = o->f20->f00->f45;
  o->f80 = o->f80 & (~0x70000u);
  o->f80 = o->f80 & 0x0007ffffu;
  o->f74 = 0x80000000u;
  o->f78 = (s16) (0x1000 << ((o->f20->f00->f48 << 6) >> 30));
  o->f7a = (s16) (0x1000 << ((o->f20->f00->f48 << 4) >> 30));
  if ((o->f20->f00->f4c << 31) >> 31)
    o->f78 = (s16) (o->f78 * (-1));
  if ((o->f20->f00->f4c << 30) >> 31)
    o->f7a = (s16) (o->f7a * (-1));
  c = o->f20;
  if ((c->f00->f00 << 15) >> 31)
  {
    {
      s32 t = c->f14->f10;
      s32 u = t << 30;
      o->f7c = (s16) (0x1000 << (((u32) u) >> 30));
    }
    o->f7e = (s16) (0x1000 << ((o->f20->f14->f10 << 28) >> 30));
    if ((o->f20->f14->f10 << 27) >> 31)
      o->f7c = (s16) (o->f7c * (-1));
    if ((o->f20->f14->f10 << 26) >> 31)
      o->f7e = (s16) (o->f7e * (-1));
  }
  o->f04 = 0;
  o->f00 = o->f04;
  o->f14 = 0;
  o->f08 = o->f14;
  o->f18 = 0;
  o->f0c = o->f18;
  o->f90 = 0;
  o->f94 = 0;
  o->f98 = 0;
}


