/*
 * function: sub_02039338
 * address:  0x02039338
 * packet:   pkt_02038C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *
 * Reads the current value through the vtable slot at +0x80 of the object
 * hanging off +0x340 of func_0203D788()'s record.  The mode byte at +0x65 of
 * func_0203D798()'s record selects which of the two spellings runs: modes 1
 * and 2 treat a -1 result as "nothing", every other mode takes the raw
 * result.  Both arms call the same slot, and the u16 narrowing is written
 * out in each of them rather than factored behind a label.
 *
 * The mode test is spelled `mode + 0xff`, not `mode - 1`: both wrap to the
 * same u8, but this compiler emits the constant as written, so `- 1` gives
 * `sub r0, r0, #1` and only the wrap-around spelling gives the original's
 * `add r0, r0, #0xff`.  See docs/idioms/a-u8-decrement-is-spelled-as-the-
 * wraparound-add.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039338.c \
 *       --func sub_02039338 --addr 0x02039338 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;

struct Slots {
    u8 pad_00[0x80];
    s32 (*unk80)(void);
};

struct Owner {
    u8 pad_00[0x340];
    struct Slots *unk340;
};

struct Mode {
    u8 pad_00[0x65];
    u8 unk65;
};

extern void *g_021469D0;
extern void *func_0203D788(void);
extern struct Mode *func_0203D798(void);

u16 sub_02039338(void)
{
    struct Owner *owner;
    u8 sel;
    s32 v;

    if (g_021469D0 == 0) {
        goto none;
    }

    owner = func_0203D788();
    sel = func_0203D798()->unk65 + 0xff;

    if (sel <= 1) {
        v = owner->unk340->unk80();
        if (v == -1) {
            goto none;
        }
        return (u16)v;
    }

    return (u16)owner->unk340->unk80();

none:
    return 0;
}
