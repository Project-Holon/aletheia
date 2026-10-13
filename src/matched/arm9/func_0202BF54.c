/*
 * function: ISS_ZONE_SYS_SelectRecord
 * address:  0x0202BF54
 * packet:   pkt_0202BEDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Selects the record ISS_ZONE_SYS_FindRecord matches for the caller's key and latches
 * it into the object: +0xc keeps the index, +0xe and +0x10 take the record's
 * +2 and +4 words, +0x12 and +0x14 are the arm flag and its counter, and the
 * +0 word marks the object live.  A non-zero +0 word means "already
 * selected", and 0xff means "no match"; both leave the object untouched.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_SelectRecord.c \
 *       --func ISS_ZONE_SYS_SelectRecord --addr 0x0202BF54 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ZONE_SYS_FindRecord  0x0202BFC4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 key;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct Obj {
    u32 state;
    u32 pad4;
    const struct Rec *base;
    u8  sel;
    u8  pad_d;
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Container;
extern u32 ISS_ZONE_SYS_FindRecord(const struct Container *c, u32 key);

void ISS_ZONE_SYS_SelectRecord(struct Obj *o, u16 key)
{
    u32 idx;

    if (o->state != 0) {
        return;
    }
    idx = ISS_ZONE_SYS_FindRecord((const struct Container *)((const u8 *)o), key);
    if (idx == 0xff) {
        return;
    }
    o->sel = (u8)idx;
    o->state = 1;
    o->fxe = o->base[idx].f2;
    o->f10 = o->base[idx].f4;
    o->f12 = 1;
    o->f14 = 0;
}
