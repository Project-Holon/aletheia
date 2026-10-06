/*
 * function: func_020480E4
 * address:  0x020480E4
 * packet:   pkt_02047E88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02048918  0x02048918  arm
 *   func_020482B4  0x020482B4  arm
 *
 * PARKED AT MATCH.  Every one of the 60 concrete bytes is right; the PC24 at
 * +0x000C is wildcarded because 0x02048918 has exactly one branch reference
 * image wide and it is that call, so no cut of a one-function range frees it.
 * Blocking evidence class: label/matched, no outside witness.  The site
 * unsticks the moment 0x02048918 (220 bytes, packet pkt_02048330) is itself
 * EXACT -- the `matched` class then resolves it with no change to this C.
 * The sibling site, the call to 0x020482B4 at +0x0018, resolves today
 * (`matched`, src/matched/func_020482B4.c).
 *
 * Seed one OAM slot of a cell actor and stamp four -1 halfwords into the
 * 8-byte record the actor keeps for it: the two calls initialise the slot and
 * the four stores write the record at +0x16 of the indexed base, which is why
 * the index scales by 8 (`lsl #3`) while the displacement 0x16 rides the
 * stores.  The -1 cannot be encoded as a halfword immediate, so it takes the
 * pool word 0x0000ffff and is loaded once for all four stores.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020480E4.c \
 *       --func func_020480E4 --addr 0x020480E4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

struct Ctx {
    u8         pad_00[0x16];
    struct Ent e[1];
};

extern void func_02048918(struct Ctx *c, u32 i);
struct Owner;
extern void func_020482B4(struct Owner *owner, u32 index);

void func_020480E4(struct Ctx *c, u32 i)
{
    func_02048918(c, i);
    func_020482B4((struct Owner *)c, i);
    c->e[i].a = -1;
    c->e[i].b = -1;
    c->e[i].c = -1;
    c->e[i].d = -1;
}
