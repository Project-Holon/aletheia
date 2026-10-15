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
 * function: WIFILIST_IsProfileValid, WIFILIST_GetFromSave, WIFILIST_FindFriendByStatus, WIFILIST_FindFriendByStatusAndOutfit
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock           0x020071CC  thumb
 *   DWC_CheckValidConsole  0x02059760  arm
 *   DWC_CheckHasProfile    0x020597C8  arm
 *   DWC_GetGsProfileId     0x020598EC  arm
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   WIFILIST_GetWork  0x02009860  thumb
 *   WIFILIST_GetFriendInfoField  0x02009864  thumb
 *   WIFILIST_GetFriendInfo  0x020099D4  thumb
 *   WIFILIST_IsFriendDataValid  0x02009A1C  thumb
 *
 * alias: the DWC-facing end of wifilist.c.  WIFILIST_GetFromSave is the one that names
 * the save block: it fetches block id 0x1E out of SAVE_CONTROL_GetBlock and hands it
 * straight to the entry accessor of src/matched/unit_02009860.c, so the wifi
 * friend list lives in block 0x1E.
 *
 * WIFILIST_GetWork, the two-byte `bx lr` in src/matched/unit_02009860.c, is used
 * here the way MYSTATUS_GetName is used in src/matched/unit_02008F48.c: its result
 * feeds the next call's first argument with no move in between, so it is an
 * identity accessor and is declared with the type that call needs.
 *
 * NEAR MISS, 0x02009CB0 and 0x02009CC0, 50 bytes, skipped for attestation and
 * not for codegen.  They are
 *
 *   void sub_02009CB0(struct WifiList *obj, void *out)
 *   {
 *       DWC_CreateExchangeToken(WIFILIST_GetWork(obj), out);
 *   }
 *
 *   void sub_02009CC0(struct WifiList *obj)
 *   {
 *       u8 token[0xC];
 *       void *account = WIFILIST_GetWork(obj);
 *
 *       sub_02009CB0(obj, token);
 *       DWC_GetGsProfileId(account, token);
 *   }
 *
 * and with WIFILIST_MergeFriendRecord they reproduce every concrete byte.  The chain that
 * blocks them is two links long.  DWC_CreateExchangeToken is reached from
 * exactly two places in the image: the pool word of WIFILIST_CreateExchangeToken at 0x02009CAC
 * and the `blx` in sub_02009CB0 at 0x02009CB8.  Whichever of the two is in the
 * range, the other is its witness, so exactly one of them can be matched, and
 * src/matched/unit_02009C24.c takes WIFILIST_CreateExchangeToken because that choice is what
 * lets its own pool word be attested by the `blx`.  sub_02009CB0 is then
 * unmatched, and the only branch to *it* anywhere in the image is the one in
 * sub_02009CC0, so sub_02009CC0 cannot be matched either.  Both close the day
 * anything else in the image calls either address.
 *
 * WIFILIST_FindFriendByStatusAndOutfit compares two call results against two parameters, and both
 * comparisons only come out `cmp r0, rN` when a named local holds the result:
 * written inline, in either operand order or as one `&&` chain, the compiler
 * normalises to `cmp rN, r0` and the file is two bytes wrong.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * WIFILIST_FindFriendByStatusAndOutfit's second parameter is dead: nothing in it reads r1, and
 * WIFILIST_FindFriendByStatus still computes MYSTATUS_GetName(p) to pass there.  Leaving the
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
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

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

extern struct Sub020097BCObj *WIFILIST_GetWork(struct Sub020097BCObj *obj);
extern u32   WIFILIST_GetFriendInfoField(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern int   WIFILIST_IsFriendDataValid(struct Sub020097BCObj *obj, u32 i);
extern struct Sub020097BCEnt *WIFILIST_GetFriendInfo(struct Sub020097BCObj *obj, int i);

extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern u8  MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj);
extern const void *MYSTATUS_GetName(const void *p);

int WIFILIST_FindFriendByStatusAndOutfit(struct Sub020097BCObj *obj, const void *unused, u32 id,
                 u32 kind, u32 *out);

u32 WIFILIST_IsProfileValid(struct Sub020097BCObj *obj)
{
    void *account = WIFILIST_GetWork(obj);

    if (DWC_CheckHasProfile(account) != 0) {
        if (DWC_CheckValidConsole(account) != 0) {
            return 1;
        }
    }
    return 0;
}

struct Sub020097BCObj *WIFILIST_GetFromSave(void *sys)
{
    struct Sub020097BCObj *obj = SAVE_CONTROL_GetBlock(sys, 0x1E);

    WIFILIST_GetFriendInfo(obj, 0);
    return obj;
}

int WIFILIST_FindFriendByStatus(struct Sub020097BCObj *obj, struct Sub0200852CObj *p,
                 u32 *out)
{
    u32 id = MYSTATUS_GetId(p);
    u8 kind = MYSTATUS_GetOutfitVariant(p);

    return WIFILIST_FindFriendByStatusAndOutfit(obj, MYSTATUS_GetName(p), id, kind, out);
}

int WIFILIST_FindFriendByStatusAndOutfit(struct Sub020097BCObj *obj, const void *unused, u32 id,
                 u32 kind, u32 *out)
{
    u8 i;
    u32 v;

    for (i = 0; i < 0x20; i++) {
        if (WIFILIST_IsFriendDataValid(obj, i) == 1) {
            v = WIFILIST_GetFriendInfoField(obj, i, 0);
            if (v == id) {
                v = WIFILIST_GetFriendInfoField(obj, i, 9);
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
