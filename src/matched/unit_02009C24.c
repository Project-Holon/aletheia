/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x02009C24
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009C24, sub_02009CA8
 *
 * symbols:
 *   MI_CpuFill8             0x02082BCC  arm
 *   DWC_CreateExchangeToken 0x020599BC  arm
 *
 * alias: wifilist.c.  sub_02009C24 folds one entry's three counters into
 * another's, clamping each at 9999 the way sub_02009BB8 does, and then clears
 * the entry it drained.
 *
 * The cut between this range and src/matched/unit_02009CB0.c is what makes
 * both halves EXACT.  DWC_CreateExchangeToken is reached from exactly two
 * places in the image, the pool word of sub_02009CA8 at 0x02009CAC and the
 * `blx` inside sub_02009CB0 at 0x02009CB8, and a range holding both leaves the
 * address with no witness at all.  Split, the `blx` attests this file's pool
 * word and the pool word attests that file's `blx`.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c  *       --addr 0x02009C24 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void DWC_CreateExchangeToken(void *account, void *out);

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

void sub_02009C24(struct Sub020097BCObj *obj, int src, int dest)
{
    if (dest < 0 || dest >= 0x20) {
        return;
    }
    if (src < 0 || src >= 0x20) {
        return;
    }
    obj->unk1C0[dest].unk24 += obj->unk1C0[src].unk24;
    if (obj->unk1C0[dest].unk24 > 9999) {
        obj->unk1C0[dest].unk24 = 9999;
    }
    obj->unk1C0[dest].unk26 += obj->unk1C0[src].unk26;
    if (obj->unk1C0[dest].unk26 > 9999) {
        obj->unk1C0[dest].unk26 = 9999;
    }
    obj->unk1C0[dest].unk28 += obj->unk1C0[src].unk28;
    if (obj->unk1C0[dest].unk28 > 9999) {
        obj->unk1C0[dest].unk28 = 9999;
    }
    MI_CpuFill8(&obj->unk1C0[src], 0, sizeof(obj->unk1C0[0]));
}

void sub_02009CA8(void *account, void *out)
{
    DWC_CreateExchangeToken(account, out);
}

