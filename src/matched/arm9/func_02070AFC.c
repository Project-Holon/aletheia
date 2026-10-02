/*
 * function: func_02070AFC
 * address:  0x02070AFC
 * packet:   pkt_02070360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolves the palette offset for the bound slot: the dictionary entry
 * (offset, flag) of obj's resource at +0x34, plus the 16-bit base index
 * held in obj->f2c (masked to 29 bits).  When flag bit 0 is clear both are
 * halved before the sum is stored at dst->f14 -- the NitroSystem 4-colour
 * palette rule (offsets in 8-byte units for 4-colour, 16-byte otherwise).
 *
 * WHAT CLOSED IT (wave 10), after the 4-instruction r0/r1 exchange of
 * docs/notes/func_02070AFC.c.txt: the two shift pairs `<<15, >>16` are not
 * an explicit truncation but `v >>= 1` on u16 LOCALS (the store's narrowing
 * folded into the shift).  With `u16 ofs, base` and `ofs >>= 1; base >>= 1;`
 * inside `if (!(e->flag & 1))`, plus the obj/h34 guard as an inline
 * GetEnt() helper, it is byte-exact on the first compile.  ../2.0/sp2 (1.1p1
 * is 100 bytes).  The caller func_02070B64 treats it as void.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070AFC.c
 *       --func func_02070AFC --addr 0x02070AFC --arm --cc ../2.0/sp2
 *
 * symbols:
 *   func_0206E62C    0x0206E62C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent70AFC { u16 offset; u16 flag; };

struct Obj70AFC {
    u8  pad00[0x2c];
    u32 f2c;
    u32 pad30[1];
    u16 h34;
};

struct Dst70AFC { u8 pad00[0x14]; u32 f14; };

struct Ent70AFC *func_0206E62C(void *dict, void *name);

static inline struct Ent70AFC *GetEnt(struct Obj70AFC *obj, void *name)
{
    if (obj != 0 && obj->h34 != 0)
        return func_0206E62C((u8 *)obj + obj->h34, name);
    return 0;
}

void func_02070AFC(struct Obj70AFC *obj, void *name, struct Dst70AFC *dst)
{
    struct Ent70AFC *e = GetEnt(obj, name);
    u16 base = (u16)obj->f2c & ~0xE0000000;
    u16 ofs = e->offset;
    if (!(e->flag & 1)) {
        ofs >>= 1;
        base >>= 1;
    }
    dst->f14 = ofs + base;
}
