/*
 * file:     iss_city_sys_p01.c
 * unit:     yes
 * function: func_0202A994, func_0202A9F4, func_0202AAF4, func_0202AB28, func_0202AB38
 * address:  0x0202A994
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185B0  0x020185B0  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02019C90  0x02019C90  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0202AB84  0x0202AB84  thumb
 *   sub_020307B0   0x020307B0  arm
 */
struct Personal;
struct Node;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32  func_02017E1C(void *rec, u32 id, u32 slot);
extern void func_02017E40(void *rec, u32 id, u32 val);
extern void func_020185B0(void *rec, u32 val);
extern void func_02018A00(void *rec, u32 species, u32 arg);
extern u32  func_02019C90(u32 species, u16 arg, u32 sel);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0202AB64(void *obj, u32 unused, u32 value);
extern void func_0202AB7C(struct Node *p, void *heapId);
extern void func_0202AB84(void *p);
extern u32 sub_020307B0(void *p);
extern u32 func_0202ACC8(void *obj);
extern void func_0202ACCC(u8 *p);
void func_0202A994(u32 a, u32 b, int c, u32 *out, u16 d);
void func_0202A9F4(u32 a0, void *rec, u32 a2, u32 a3);
struct Node *func_0202AAF4(u32 a, void *heapId);
void func_0202AB28(void *p);
void func_0202AB38(u8 *p);




void func_0202A994(u32 a, u32 b, int c, u32 *out, u16 d)
{
    u32 t = c & 0xf;
    u32 u = (c & 0xf0) >> 4;
    u32 v;

    if (c == 0)
        return;

    v = (u32)func_0201ADE4((u16)a, (u16)b, d);

    if (t != 0) {
        *out = func_0201AE1C((const struct Personal *)v, 0x14);
        if (t == 1)
            *out = *out + 2;
        else
            *out = *out - 2;
    }

    if (u == 1)
        *out &= ~(u32)1;
    else if (u == 2)
        *out |= (u32)1;

    func_0201AE14((void *)v);
}




/*
 * tr_tool.c: finish one trainer party member.  Field 9 (friendship) is
 * 0xFF unless one of the four moves (fields 0x36..0x39) is 0xDA, then 0;
 * field 0x6F takes a2; the 0xF0 nibble of a3 selects a form path
 * (0x30: func_02018A00, otherwise func_02019C90 with selector 0x1A or
 * 0x1B); two trainer/species pairs force a fixed nature, the rest take
 * (personality >> 8) % 25.
 *
 * What closed the old 248-byte near miss (docs/notes/func_0202A9F4.c.txt):
 * the register the note read as a copy of the loop counter (`adds r6, r4,
 * #0` before the loop) is the constant 0, kept in r6 for the call's third
 * argument and for `found = 0`.  That zero occupies the fourth callee-saved
 * register across the loop, which is what spills species to sp+0xC.  The
 * tail is the remainder of _s32_div_f (r1), so `% 25`, not `/ 25`.
 */
void func_0202A9F4(u32 a0, void *rec, u32 a2, u32 a3)
{
    s32 slot;
    u32 found = 0xff;
    u32 species;
    u32 sel;
    u32 alt;
    u32 masked;
    u32 base;

    species = (u16)func_02017E1C(rec, 5, 0);
    for (slot = 0; slot < 4; slot++) {
        if (func_02017E1C(rec, 0x36 + slot, 0) == 0xda) {
            found = 0;
        }
    }
    func_02017E40(rec, 9, found);
    func_02017E40(rec, 0x6f, a2);

    masked = a3 & 0xf0;
    if (masked == 0x30) {
        func_02018A00(rec, species, a2);
    } else if (masked != 0) {
        sel = 0x1a;
        alt = 0x1b;
        if (func_02019C90(species, (u16)a2, 0x1b) != 0 && masked == 0x20) {
            sel = alt;
        }
        func_02017E40(rec, 0xa, func_02019C90(species, (u16)a2, sel));
    }

    base = 0x24a;
    if (a0 == base && species == base + 0x39) {
        func_020185B0(rec, 0xd);
        return;
    }
    base = 0x24b;
    if (a0 == base && species == base + 0x39) {
        func_020185B0(rec, 0xa);
        return;
    }
    func_020185B0(rec, (u8)(((s32)func_02017E1C(rec, 0, 0) >> 8) % 0x19));
}




/*
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * Allocates a 0x1c-byte node with the allocator entry point and runs the
 * two initialisers func_0202AB64 and func_0202AB7C over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AAF4.c \
 *       --func func_0202AAF4 --addr 0x0202AAF4 --thumb --cc 1.1p1
 */
struct Node *func_0202AAF4(u32 a, void *heapId)
{
    struct Node *p = (struct Node *)func_02030734((u32)heapId, 0x1c, 0,
                                                  (const void *)0x020A76E8, 0x92);

    func_0202AB64(p, (u32)heapId, a);
    func_0202AB7C(p, heapId);
    return p;
}



void func_0202AB28(void *p)
{
    func_0202AB84(p);
    sub_020307B0(p);
}


/*
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * When func_0202ACC8 reports non-zero, runs func_0202ACCC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AB38.c \
 *       --func func_0202AB38 --addr 0x0202AB38 --thumb --cc 1.1p1
 */
void func_0202AB38(u8 *p)
{
    if (func_0202ACC8(p) != 0) {
        func_0202ACCC(p);
    }
}
