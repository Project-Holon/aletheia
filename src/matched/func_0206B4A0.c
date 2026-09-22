/*
 * function: func_0206B4A0
 * address:  0x0206B4A0
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * The object constructor of the 0x0206B458 script-object family: zero the
 * whole 0x188-byte object, set the +0xc4 and +0x08 words to 1, take the
 * program pointer from the config's +0x30 override or, absent one, from the
 * script blob's own +0x04 offset, then unpack the blob into the object --
 * three offset-or-null section pointers at +0xd4/+0xd8/+0xdc, three table
 * picks keyed by the blob's +0x15/+0x16 bytes, two words copied from +0x1c
 * and +0x20, an optional (index, byte) pair into the +0x0c/+0x8c arrays,
 * four flag bits mirrored out of the config's +0x00 word, an optional
 * caller hook, and finally the driver loop func_0206B458.
 *
 * Two spellings are load-bearing, both recorded as walls in
 * docs/notes/pkt_0206AFE4.c.txt:
 *   - `volatile` on the +0x04 config pointer.  Without it mwcc fuses the
 *     +0x00 and +0x04 stores into `stm r5, {r0, r4}` and the function comes
 *     out four bytes short; the qualifier restores the original's two
 *     separate `str`s and changes nothing else.  Same lever family as
 *     src/matched/func_0206AF74.c's `volatile s32 *dst`.
 *   - the local `q = cfg->f04;` in front of the +0xd8/+0xdc pointer
 *     assembly.  Spelled through `cfg->f04` directly, the `&&` materialises
 *     a boolean (`movne r1,#1 / cmp r1,#0`) and re-loads the offset, 28
 *     bytes of excess; through the local it is the original's predicated
 *     `cmp / ldrne / cmpne / addne / moveq` chain.  Found by
 *     tools/permuter.py (hill, 800/8, --types), which named
 *     `temp(tmp=(u32 *)(cfg->f04 + 0xc))` and took 440 bytes to 424.
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   func_0206B458     0x0206B458  arm
 *   g_020A829C        0x020A829C  data
 *   g_020A8290        0x020A8290  data
 *   g_020A82A8        0x020A82A8  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Cfg0206B4A0 Cfg0206B4A0;
typedef struct Obj0206B4A0 Obj0206B4A0;

struct Cfg0206B4A0 {
    u32   f00;
    u8   *f04;
    u8    pad08[0x20 - 0x08];
    u32   f20;
    u8    f24;
    u8    f25;
    u8    pad26[0x28 - 0x26];
    void (*f28)(Obj0206B4A0 *);
    u8    pad2c[0x30 - 0x2c];
    u8   *f30;
};

struct Obj0206B4A0 {
    u8   *f00;
    Cfg0206B4A0 *volatile f04;
    u32   f08;
    u32   f0c[0x20];
    u8    f8c[0x20];
    u8    padac[0xc4 - 0xac];
    u32   fc4;
    u8    padc8[0xd4 - 0xc8];
    u8   *fd4;
    u8   *fd8;
    u8   *fdc;
    u32   fe0;
    u32   fe4;
    u32   fe8;
    u32   fec;
    u32   ff0;
};

extern void MIi_CpuClearFast(u32 val, void *dst, u32 len);
extern void func_0206B458(Obj0206B4A0 *p);
extern u32 g_020A829C[];
extern u32 g_020A8290[];
extern u32 g_020A82A8[];

void func_0206B4A0(Obj0206B4A0 *o, Cfg0206B4A0 *cfg)
{
    u8 *q;

    MIi_CpuClearFast(0, o, 0x188);
    o->fc4 = 1;
    o->f08 = 1;
    o->f00 = cfg->f30 != 0 ? cfg->f30 : cfg->f04 + *(u32 *)(cfg->f04 + 4);
    o->f04 = cfg;
    o->fd4 = cfg->f04 != 0 ? cfg->f04 + 0x40 : 0;
    q = cfg->f04;
    o->fd8 = q != 0 && *(u32 *)(q + 8) != 0 ? q + *(u32 *)(q + 8) : 0;
    q = cfg->f04;
    o->fdc = q != 0 && *(u32 *)(q + 0xc) != 0 ? q + *(u32 *)(q + 0xc) : 0;
    o->fe8 = g_020A829C[cfg->f04[0x15]];
    o->fec = g_020A8290[cfg->f04[0x15]];
    o->ff0 = g_020A82A8[cfg->f04[0x16]];
    o->fe0 = *(u32 *)(cfg->f04 + 0x1c);
    o->fe4 = *(u32 *)(cfg->f04 + 0x20);
    if (cfg->f20 != 0 && cfg->f24 < 0x20) {
        o->f0c[cfg->f24] = cfg->f20;
        o->f8c[cfg->f24] = cfg->f25;
    }
    if (cfg->f00 & 1)   o->f08 |= 0x80;
    if (cfg->f00 & 2)   o->f08 |= 0x100;
    if (cfg->f00 & 4)   o->f08 |= 0x200;
    if (cfg->f00 & 8)   o->f08 |= 0x400;
    if (cfg->f28 != 0) cfg->f28(o);
    func_0206B458(o);
    cfg->f00 &= ~1u;
}
