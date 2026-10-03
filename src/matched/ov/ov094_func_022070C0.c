/*
 * function: func_022070C0
 * address:  0x022070C0
 * packet:   pkt_ov094_022070C0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * trailing: 02207286..02207288 is two zero alignment bytes.
 *
 * Battle-side twin of func_02207288 (same row layout).
 *
 * lever: func_021D6314 returns a one-word struct (Word) passed by value to
 * func_021E8A78, as in the ov093 callers. The struct-return temporary
 * reserves the extra frame word (push r3, sub sp #0x28, slot sp+0x24 never
 * touched) and that one change also flips the row stores to share p + i*0x80
 * in a scratch register; with int prototypes both residues remained
 * (2026-10-01 note: Row pointer local, char* offsets, inline helpers,
 * nested sub-struct, u8 index, x/y locals were all inert).
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
extern int func_021D59B4(u8 *p, int k);
struct QF;
struct Unk021D62A8;
struct Work;
extern u16 func_021D5444(struct QF *p);
extern u32 func_02018584(u16, u16, u16);
extern int func_021B8724(char *p, void *m);
extern void *func_021D5864(struct Work *p);
extern u8 func_02017F00(void *);
typedef struct { u32 v; } Word;
extern Word func_021D6314(void *, int);
extern int func_021E8A78(Word);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void func_02208814(struct O *obj, int k, int idx);
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
