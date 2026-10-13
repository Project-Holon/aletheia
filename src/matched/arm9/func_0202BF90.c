/*
 * function: ISS_ZONE_SYS_BeginFade
 * address:  0x0202BF90
 * region:   arm9
 * packet:   pkt_0202BEBC
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Combines the record selected by the object's +0xc byte with the record
 * ISS_ZONE_SYS_FindRecord has just selected for the caller's key: the two crossings are
 * ANDed into +0xe and +0x10, +0x12 takes the new record's +6 and +0xc records
 * the new selection.
 *
 * The spelling that matters here is the object as a struct with named members:
 * with `u8 *p` and literal offsets the allocator puts p in r4 and sel in r5,
 * twenty bytes of register numbering away.  Reading `o->sel` first, calling
 * ISS_ZONE_SYS_FindRecord on the same object and only then loading `o->base` is what puts
 * sel in r4, p in r5 and the base in r6, which is the original.
 *
 * Closes the blocker of src/pending/ISS_ZONE_SYS_SwitchZone.c and, through it,
 * src/pending/ISS_SYS_OnZoneChangeZone.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_BeginFade.c \
 *       --func ISS_ZONE_SYS_BeginFade --addr 0x0202BF90 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ZONE_SYS_FindRecord  0x0202BFC4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct Obj {
    u32 pad0;
    u32 pad4;
    u32 base;
    u8  sel;
    u8  pad_d;
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Container;
extern u32 ISS_ZONE_SYS_FindRecord(const struct Container *c, u32 key);

void ISS_ZONE_SYS_BeginFade(struct Obj *o, u32 key)
{
    u8 sel;
    u32 idx;
    const struct Rec *base;

    sel = o->sel;
    idx = ISS_ZONE_SYS_FindRecord((const struct Container *)o, key);
    base = (const struct Rec *)o->base;
    if (idx == 0xff) {
        return;
    }
    o->fxe = base[sel].f4 & base[idx].f2;
    o->f10 = base[sel].f2 & base[idx].f4;
    o->f12 = base[idx].f6;
    o->f14 = 0;
    o->sel = (u8)idx;
}
