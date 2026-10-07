/*
 * unit:     yes
 * address:  0x0201BEB8
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201BEB8, sub_0201BF44, sub_0201BF58
 *
 * waza_tool.c: the flag-bit query and the packed triple, each with its own
 * copy of the cache lookup src/matched/unit_0201BD28.c carries.
 *
 * sub_0201BF44 has to stay in this file: the `bl` at 0x0201BF36 is the only
 * branch to it in the image, so split off it would have no witness, and kept
 * here the site is the `local` class.
 *
 * sub_0201BF44's early `return r` on the bit being set is not interchangeable
 * with the `if (... == 0) r = 0;` spelling that reads more naturally: the
 * latter copies the loaded word into a second register and returns through a
 * third, eight bytes of register numbering, while the early return leaves the
 * result in r0 from the `movs r0, #1` the original opens the test with.
 *
 * sub_0201BF58 packs three fields of the record into one halfword of
 * bitfields on the stack, 4 bits then 6 then 6, and hands the halfword back
 * signed.  Two details are load bearing.  The halfword is never initialised:
 * when the record's +0x0B byte is zero the function returns whatever the
 * slot the prologue's `push {r3, ...}` reserved happens to hold, and adding
 * an initialiser adds an instruction the original does not have.  And the
 * result is read with a register-offset `ldrsh`, which is the only form Thumb
 * has, so the object is a union of the bitfield triple and an `s16` rather
 * than three separate variables.
 *
 * symbols:
 *   gWazaTool   0x02146530  data
 *   g_02146534  0x02146534  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BEB8.c  *       --addr 0x0201BEB8 --thumb
 */

#include "../include/G_WazaTool.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;

struct Waza {
    u8  unk00[0x0B];
    u8  unk0B;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E[0x12];
    u32 unk20;
};

union Packed {
    struct {
        u16 a : 4;
        u16 b : 6;
        u16 c : 6;
    } f;
    s16 v;
};

extern struct WazaTool *gWazaTool;
extern struct Waza g_02146534;

extern void func_02048F4C(void *dst, u32 archive_id, u32 member);

u32 sub_0201BF44(const struct Waza *p, u32 bit);

u32 sub_0201BEB8(u16 id, u32 bit)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (((u16 *)gWazaTool->vals)[i] == 0) {
                ((u16 *)gWazaTool->vals)[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == ((u16 *)gWazaTool->vals)[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            ((u16 *)gWazaTool->vals)[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    return sub_0201BF44(rec, bit);
}

u32 sub_0201BF44(const struct Waza *p, u32 bit)
{
    u32 r = 1;

    if ((p->unk20 & (1 << bit)) != 0) {
        return r;
    }
    r = 0;
    return r;
}

s16 sub_0201BF58(u16 id)
{
    struct Waza *rec;
    s32 i;
    union Packed u;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (((u16 *)gWazaTool->vals)[i] == 0) {
                ((u16 *)gWazaTool->vals)[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == ((u16 *)gWazaTool->vals)[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            ((u16 *)gWazaTool->vals)[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    if (rec->unk0B != 0) {
        u.f.a = rec->unk0B;
        u.f.b = rec->unk0C;
        u.f.c = rec->unk0D;
    }
    return u.v;
}
