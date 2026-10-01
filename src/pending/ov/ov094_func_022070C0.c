/*
 * function: func_022070C0
 * address:  0x022070C0
 * packet:   pkt_ov094_022070C0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Battle-side twin of func_02207288 (same row layout).
 *
 * 2026-10-01: logic and call order match. Two residues remain: (1) the
 * original keeps p + i*0x80 in a scratch register across consecutive row
 * stores (b/f90/fa8, side then the f94/f98 = 0 else arm, fa4/fa0/fae) and
 * adds each field offset to a copy, while this source (like the sibling)
 * recomputes p + r4 per store; (2) the original frame is one word larger
 * (push r3 pad, sub sp #0x28, slot sp+0x24 never referenced), hinting at a
 * local that was optimised away. Tried: Row pointer local (gets a callee
 * saved register), char* raw offsets, inline helpers, nested sub-struct,
 * u8 index, explicit x/y locals.
 *
 * symbols:
 *   func_02082A48 0x02082A48 arm
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02018584 0x02018584 thumb
 *   func_021B8724 0x021B8724 thumb ov093
 *   func_021D5864 0x021D5864 thumb ov093
 *   func_02017F00 0x02017F00 thumb
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8A78 0x021E8A78 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_02208814 0x02208814 thumb ov094
 *   func_022079C0 0x022079C0 thumb ov094
 *   func_02208D50 0x02208D50 thumb ov094
 *   func_0220793C 0x0220793C thumb ov094
 *   func_0220785C 0x0220785C thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct O O;
typedef struct { char pad[0x40]; u32 mode, side, a, b, f90, f94, f98, f9c, fa0, fa4, fa8; u8 level, sex, fae, seen; u32 flags, fb4, fb8, fbc; } Row;
typedef struct W { char pad[0x40]; Row rows[8]; } W;
typedef struct S S;
typedef struct { short x, y; } Pt;
extern void func_02082A48(u32, void *, u32);
extern int func_021D59B4(void *, int);
extern u16 func_021D5444(void *);
extern u32 func_02018584(u16, u16, u16);
extern int func_021B8724(void *, void *);
extern void *func_021D5864(void *);
extern u32 func_02017F00(void *);
extern int func_021D6314(void *, int);
extern int func_021E8A78(int);
extern int func_021D62A8(void *);
extern void func_02208814(O *, int, int);
extern void func_022079C0(char *, int, Pt *);
extern void func_02208D50(W *, int, int);
extern void func_0220793C(S *);
extern void func_0220785C(char *, int, int, void *);

void func_022070C0(W *p, void *a, void *q, int mode, int i)
{
    u32 exp;
    u16 species;
    int item;

    func_02082A48(0, &p->rows[i].mode, 0x40);
    p->rows[i].a = func_021D59B4(q, 0xd);
    p->rows[i].b = func_021D59B4(q, 0xe);
    p->rows[i].f90 = 0x80000000;
    p->rows[i].fa8 = 0;
    p->rows[i].level = func_021D59B4(q, 0xf);
    p->rows[i].mode = mode;
    p->rows[i].side = i & 1;
    p->rows[i].flags |= 0x08000000;
    if (p->rows[i].level < 100) {
        exp = func_02018584(func_021D5444(q), func_021D59B4(q, 0x13), func_021D59B4(q, 0xf));
        p->rows[i].f94 = func_021D59B4(q, 0x14) - exp;
        p->rows[i].f98 = func_02018584(func_021D5444(q), func_021D59B4(q, 0x13), func_021D59B4(q, 0xf) + 1) - exp;
    } else {
        p->rows[i].f94 = 0;
        p->rows[i].f98 = 0;
    }
    p->rows[i].fa4 = 0x80000000;
    p->rows[i].fa0 = 0;
    p->rows[i].fae = 0;
    p->rows[i].seen = func_021B8724(a, q);
    species = func_021D5444(q);
    if (species != 32 && species != 29)
        p->rows[i].sex = func_02017F00(func_021D5864(q));
    else
        p->rows[i].sex = 2;
    if (func_021E8A78(func_021D6314(q, 5)) == 1 && func_021D62A8(q) == 5)
        item = 6;
    else
        item = func_021D62A8(q);
    func_02208814((O *)p, item, i);
    func_022079C0((char *)p, i, 0);
    func_02208D50(p, i, 1);
    func_0220793C((S *)&p->rows[i]);
    func_0220785C((char *)p, mode, i, func_021D5864(q));
}
