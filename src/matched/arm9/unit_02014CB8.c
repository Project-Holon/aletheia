/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02014CB8
 * packet:   pkt_02014444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02014CB8, sub_02014CD4
 *
 * symbols:
 *   func_020490F4         0x020490F4  arm
 *   ENV_SetResourceSet_2  0x02049238  arm
 *
 * alias: an acquire/release pair on the same object. sub_02014CB8 only
 * acts the first time (its own field at +0 is the guard); it records the
 * argument at +4 and installs whatever func_020490F4 returns at +0.
 * sub_02014CD4 is the release: if +0 is set it tears it down and clears
 * both fields.
 *
 * ENV_SetResourceSet_2 is not the same call site as
 * src/matched/unit_02014444.c's ENV_SetResourceSet: `layout/symbols_sdk.txt`
 * recovers three separate addresses for that SDK name (0x020307B0,
 * 0x02049238, 0x0204B084), one per statically linked object that pulled the
 * small library routine in, and this file only ever reaches the second one.
 * The two extern declarations therefore differ (three registers forwarded
 * there, one used here), which is a property of each call site, not a
 * disagreement about the routine.
 *
 * The one detail that pinned the source: the field at +0x40 is read with a
 * plain `ldr` (word reach, +124) and truncated to u16 afterwards rather than
 * loaded with `ldrh` (reach +62) directly, which only happens when the field
 * itself is declared u32 and truncated at the call, matching
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md's family of reach-driven
 * tells. Declaring it u16 outright produces an extra `adds` to reach the
 * offset and is 4 bytes wrong.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014CB8.c \
 *       --addr 0x02014CB8 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void  ENV_SetResourceSet_2(void *p);

struct Sub02014CB8Obj {
    void *f00;
    u32   f04;
    u32   pad08[0xE];
    u32   f40;
};

void sub_02014CB8(struct Sub02014CB8Obj *o, u32 x)
{
    if (o->f00 == 0) {
        o->f04 = x;
        o->f00 = func_020490F4(x, (u16)o->f40);
    }
}

void sub_02014CD4(struct Sub02014CB8Obj *o)
{
    if (o->f00 != 0) {
        ENV_SetResourceSet_2(o->f00);
        o->f04 = 0;
        o->f00 = 0;
    }
}
