/*
 * unit:     no
 * function: sub_0204A48C
 * address:  0x0204A48C
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 288 concrete bytes are correct and seven of the ten
 * relocation sites now resolve.  func_0204BA38 (+0x00C0) was closed by wave
 * 20C (src/matched/func_0204BA38.c).  The other three are each byte-correct
 * in src/pending/ but capped at MATCH by a fan-in-1 extern of their own, so
 * this file needs three `matched` entries that do not exist yet:
 *   func_0204D7E0 (+0x0090) waits on 0x02034558, 0x0204DA5C and 0x0204DCA8
 *   func_0204BC94 (+0x00AC) waits on func_0204BD3C, which waits on 0x02063138
 *   func_0204C660 (+0x00D8) waits on 0x02066934
 * All four of those addresses sit outside clact.c.
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   s_clact_c      0x020A7F74  data
 *   sub_02030734   0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204D7E0  0x0204D7E0  arm
 *   func_0204BC94  0x0204BC94  arm
 *   func_0204BA38  0x0204BA38  arm
 *   func_0204C660  0x0204C660  arm
 *   func_0204BAEC  0x0204BAEC  arm
 *   func_0204BB20  0x0204BB20  arm
 *
 * Bring up the single global cell-actor system behind 0x02146A74, the exact
 * inverse of src/pending/sub_0204A5AC.c: one 0x124-byte allocation, zeroed,
 * then each of the four embedded sub-objects at +0x00, +0x40, +0x0e0 and
 * +0x104 initialised from the caller's config record, the two-entry u16 table
 * at +0xf0 cleared, and the system enabled.  The __FILE__ pointer is the same
 * s_clact_c the rest of clact.c uses.
 *
 * The six halfwords at +0x10..+0x1a of the config are copied into a stack
 * array one field at a time rather than as an aggregate: a twelve-byte struct
 * assignment would be an inlined `ldm`/`stm` pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), and the original spells out
 * six `ldrh`/`strh`.
 *
 * The zero that clears the +0xf0 table is the loop counter's own initial
 * value, hoisted out of the loop, and is the same register as the allocator's
 * `clear` argument and the fill byte
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md),
 * so `i` has to be a function-scope local.  The trailing 1 is shared by the
 * last two calls the same way.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204A48C.c \
 *       --func sub_0204A48C --addr 0x0204A48C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cfg {
    u8  pad_00[8];
    u8  unk_08;
    u8  unk_09;
    u8  unk_0a;
    u8  unk_0b;
    u32 unk_0c;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1a;
};

struct Sys {
    u8  pad_00[0xf0];
    u16 unk_f0[2];
    u8  pad_f4[0x30];
};

extern struct Sys *g_02146A74;
extern char s_clact_c[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  func_02082BCC(void *dst, int fill, u32 size);
struct Caps;
struct Obj;
struct Res;
extern void func_0204D7E0(struct Res *res, u32 heapId, const struct Cfg *cfg, const struct Caps *caps);
extern void func_0204BC94(struct Obj *o, u32 base, u32 count, u32 base2, u8 count2);
typedef signed short   s16;
extern void func_0204BA38(void *a, const s16 *src, u32 mode);
struct Pool;
extern void func_0204C660(struct Pool *p, u8 n, u32 heapId);
extern void  func_0204BAEC(u32 on);
extern void  func_0204BB20(u32 on);

void sub_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId)
{
    u16 dims[6];
    int i;

    g_02146A74 = sub_02030734(heapId, sizeof(struct Sys), 0, s_clact_c, 0x28f);
    func_02082BCC(g_02146A74, 0, sizeof(struct Sys));

    dims[0] = cfg->unk_10;
    dims[1] = cfg->unk_12;
    dims[2] = cfg->unk_14;
    dims[3] = cfg->unk_16;
    dims[4] = cfg->unk_18;
    dims[5] = cfg->unk_1a;

    func_0204D7E0((struct Res *)((u8 *)g_02146A74 + 0x104), heapId, (const struct Cfg *)arg, (const struct Caps *)dims);
    func_0204BC94((struct Obj *)g_02146A74, cfg->unk_08, cfg->unk_09, cfg->unk_0a,
                  cfg->unk_0b);
    func_0204BA38((u8 *)g_02146A74 + 0x40, (const s16 *)cfg, heapId);
    func_0204C660((struct Pool *)((u8 *)g_02146A74 + 0xe0), cfg->unk_0c, heapId);

    for (i = 0; i < 2; i++) {
        g_02146A74->unk_f0[i] = 0;
    }

    func_0204BAEC(1);
    func_0204BB20(1);
}
