/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x02009CE4
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009CE4, sub_02009D08, sub_02009D1C, sub_02009D50
 *
 * symbols:
 *   sub_020071CC           0x020071CC  thumb
 *   DWC_CheckValidConsole  0x02059760  arm
 *   DWC_CheckHasProfile    0x020597C8  arm
 *   DWC_GetGsProfileId     0x020598EC  arm
 *
 * alias: the DWC-facing end of wifilist.c.  sub_02009D08 is the one that names
 * the save block: it fetches block id 0x1E out of sub_020071CC and hands it
 * straight to the entry accessor of src/matched/unit_02009860.c, so the wifi
 * friend list lives in block 0x1E.
 *
 * sub_02009860, the two-byte `bx lr` in src/matched/unit_02009860.c, is used
 * here the way sub_020084F4 is used in src/matched/unit_02008F48.c: its result
 * feeds the next call's first argument with no move in between, so it is an
 * identity accessor and is declared with the type that call needs.
 *
 * NEAR MISS, 0x02009CB0 and 0x02009CC0, 50 bytes, skipped for attestation and
 * not for codegen.  They are
 *
 *   void sub_02009CB0(struct WifiList *obj, void *out)
 *   {
 *       DWC_CreateExchangeToken(sub_02009860(obj), out);
 *   }
 *
 *   void sub_02009CC0(struct WifiList *obj)
 *   {
 *       u8 token[0xC];
 *       void *account = sub_02009860(obj);
 *
 *       sub_02009CB0(obj, token);
 *       DWC_GetGsProfileId(account, token);
 *   }
 *
 * and with sub_02009C24 they reproduce every concrete byte.  The chain that
 * blocks them is two links long.  DWC_CreateExchangeToken is reached from
 * exactly two places in the image: the pool word of sub_02009CA8 at 0x02009CAC
 * and the `blx` in sub_02009CB0 at 0x02009CB8.  Whichever of the two is in the
 * range, the other is its witness, so exactly one of them can be matched, and
 * src/matched/unit_02009C24.c takes sub_02009CA8 because that choice is what
 * lets its own pool word be attested by the `blx`.  sub_02009CB0 is then
 * unmatched, and the only branch to *it* anywhere in the image is the one in
 * sub_02009CC0, so sub_02009CC0 cannot be matched either.  Both close the day
 * anything else in the image calls either address.
 *
 * sub_02009D50 compares two call results against two parameters, and both
 * comparisons only come out `cmp r0, rN` when a named local holds the result:
 * written inline, in either operand order or as one `&&` chain, the compiler
 * normalises to `cmp rN, r0` and the file is two bytes wrong.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * sub_02009D50's second parameter is dead: nothing in it reads r1, and
 * sub_02009D1C still computes sub_020084F4(p) to pass there.  Leaving the
 * parameter out moves every argument and the function does not match, so the
 * dead argument is part of the shape.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c \
 *       --addr 0x02009C24 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub0200852CObj;

struct Sub020071CCCtrl;
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

extern int  DWC_CheckValidConsole(void *account);
extern int  DWC_CheckHasProfile(void *account);
extern void DWC_GetGsProfileId(void *account, void *out);

struct Sub020097BCFriend {
    u8 unk00[0xC];
};

struct Sub020097BCEnt {
    u8  unk00[0x1C];
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u8  unk2C;
    u8  unk2D;
    u8  unk2E;
    u8  unk2F_0 : 2;
    u8  unk2F_2 : 6;
};

struct Sub020097BCObj {
    u8 unk000[0x40];
    struct Sub020097BCFriend unk040[0x20];
    struct Sub020097BCEnt    unk1C0[32];
    u8 unk7C0[4];
};

extern void *sub_02009860(struct Sub020097BCObj *obj);
extern u32   sub_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern int   sub_02009A1C(struct Sub020097BCObj *obj, u32 i);
extern struct Sub020097BCEnt *sub_020099D4(struct Sub020097BCObj *obj, int i);

extern u32 sub_02008530(const struct Sub0200852CObj *obj);
extern u8  sub_02008550(const struct Sub0200852CObj *obj);
extern const void *sub_020084F4(const void *p);

int sub_02009D50(struct Sub020097BCObj *obj, const void *unused, u32 id,
                 u32 kind, u32 *out);

u32 sub_02009CE4(struct Sub020097BCObj *obj)
{
    void *account = sub_02009860(obj);

    if (DWC_CheckHasProfile(account) != 0) {
        if (DWC_CheckValidConsole(account) != 0) {
            return 1;
        }
    }
    return 0;
}

struct Sub020097BCObj *sub_02009D08(void *sys)
{
    struct Sub020097BCObj *obj = sub_020071CC(sys, 0x1E);

    sub_020099D4(obj, 0);
    return obj;
}

int sub_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p,
                 u32 *out)
{
    u32 id = sub_02008530(p);
    u8 kind = sub_02008550(p);

    return sub_02009D50(obj, sub_020084F4(p), id, kind, out);
}

int sub_02009D50(struct Sub020097BCObj *obj, const void *unused, u32 id,
                 u32 kind, u32 *out)
{
    u8 i;
    u32 v;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) == 1) {
            v = sub_02009864(obj, i, 0);
            if (v == id) {
                v = sub_02009864(obj, i, 9);
                if (v == kind) {
                    if (out != 0) {
                        *out = i;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
