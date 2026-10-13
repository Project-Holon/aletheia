/*
 * function: func_0215E5B0
 * address:  0x0215E5B0
 * packet:   pkt_ov010_0215E5B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads species (5), a word at 0xA0 and a byte at 0x9D of the lead party
 * member, looks up a record for the species (func_0215E804) and either
 * rolls a 30% chance of func_0215E364 when there is none, sets one of two
 * states on it for modes 1-2 (with field 0xA0 clear) or 5, or copies the two
 * values into it and calls func_0215E364.
 *
 * MATCH, bytes exact. Blocker: BTL_SETUP_GetParty (arm9, Thumb) is an unlabelled
 * leaf (a .word after BTL_SETUP_SetParty's pool), so neither label nor
 * sole-ref/code reaches it. It is EXACT from
 *     void *BTL_SETUP_GetParty(void *p, int i)
 *     { return ((void **)((char *)p + 0x24))[i]; }
 * as src/matched/arm9/BTL_SETUP_GetParty.c (pkt_0201313C), outside this ov lane's
 * write set; once that shard exists this file verifies EXACT.
 * The local declaration order (mon, species, v, idx, tbl, b) is load-bearing.
 *
 * 2026-10-05 (wave D8): The arm9 leaf BTL_SETUP_GetParty now has an EXACT witness src/matched/arm9/BTL_SETUP_GetParty.c (pkt_0201313C); once its shard exists this file verifies EXACT.
 *
 * symbols:
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   BTL_SETUP_GetParty  0x0201313C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0215E804  0x0215E804  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   func_0215E364  0x0215E364  thumb  ov010
 *   func_0215E724  0x0215E724  thumb  ov010
 *   func_0200D494  0x0200D494  thumb
 *   func_0200D480  0x0200D480  thumb
 *   func_0200D470  0x0200D470  thumb
 *   func_0200D50C  0x0200D50C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    int f00;            /* 0x00 */
    int f04;            /* 0x04 */
    u8 pad08[0x8C - 0x08];
    int f8c;            /* 0x8C */
} Work;

struct Big;
struct Blk38;
struct GdsEnt;
struct Rec44;
struct SaveBlock;
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern void *BTL_SETUP_GetParty(void *p, int v);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *p);
extern struct GdsEnt *func_0215E804(int a0, int a1);
extern u32 func_02005728(u32 v);
extern void func_0215E364(void *p);
extern int func_0215E724(int species);
extern void func_0200D494(struct GdsEnt *e);
extern void func_0200D480(struct Blk38 *p, u32 i, u8 v);
struct Blk38;
extern void func_0200D470(struct Blk38 *p, u32 i, u32 v);
extern void func_0200D50C(struct GdsEnt *e, u32 i, u32 v);

void func_0215E5B0(void *a0, Work *w)
{
    void *mon;
    u16 species;
    u16 v;
    u32 idx;
    void *tbl;
    u8 b;

    if (w->f04 != 0 || w->f00 != 0) {
        return;
    }
    func_02012AC8(func_020127A4(a0));
    mon = func_0201AB28(BTL_SETUP_GetParty(w, 1), 0);
    species = func_02017E1C(mon, 5, 0);
    v = func_02017E1C(mon, 0xA0, 0);
    b = func_02017E1C(mon, 0x9D, 0);
    tbl = func_0200D418(func_02012EBC(a0));
    mon = func_0215E804((int)tbl, species);
    if (mon == 0) {
        if (func_02005728(100) < 30) {
            func_0215E364(a0);
        }
        return;
    }
    idx = func_0215E724(species);
    if ((w->f8c == 1 || w->f8c == 2) && v == 0) {
        func_0200D494(mon);
        func_0200D480(tbl, idx, 0x10);
        func_0200D470(tbl, idx, 2);
        return;
    }
    if (w->f8c == 5) {
        func_0200D494(mon);
        func_0200D480(tbl, idx, 0x10);
        func_0200D470(tbl, idx, 3);
        return;
    }
    func_0200D50C(mon, 5, v);
    func_0200D50C(mon, 7, b);
    func_0215E364(a0);
}
