/*
 * function: func_02207288
 * address: 0x02207288
 * packet: pkt_ov094_02207288
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0220742E..02207430 is two zero alignment bytes.
 * lever: rows are an array member of the object; raw offset casts gave 416 bytes and the wrong field-base spills, while the member form gives exact 422 bytes.
 * symbols:
 *   func_02082A48 0x02082A48 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02018584 0x02018584 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_02017F90 0x02017F90 thumb
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
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02018584(u16, u16, u16);
struct Blk37;
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern u8 func_02017F00(void *);
extern u32 func_02017F90(void *);
extern void func_02208814(struct O *obj, int k, int idx);
extern void func_022079C0(char *, int, Pt *);
extern void func_02208D50(W *, int, int);
extern void func_0220793C(S *);
extern void func_0220785C(char *, int, int, void *);
void func_02207288(W *p, void *a, void *q, int mode, int i)
{
    u32 x, y, exp;
    u16 species;
    func_02082A48(0, &p->rows[i].mode, 0x40);
    p->rows[i].a = func_02017E1C(q, 0xa0, 0);
    p->rows[i].b = func_02017E1C(q, 0xa1, 0);
    p->rows[i].f90 = 0x80000000;
    p->rows[i].fa8 = 0;
    p->rows[i].level = func_02017E1C(q, 0x9e, 0);
    p->rows[i].mode = mode;
    p->rows[i].side = i & 1;
    p->rows[i].flags |= 0x08000000;
    if (p->rows[i].level < 100) {
        x = func_02017E1C(q, 5, 0);
        y = func_02017E1C(q, 0x6f, 0);
        exp = func_02018584(x, y, p->rows[i].level);
        p->rows[i].f94 = func_02017E1C(q, 8, 0) - exp;
        p->rows[i].f98 = func_02018584(x, y, p->rows[i].level + 1) - exp;
    } else {
        p->rows[i].f94 = 0;
        p->rows[i].f98 = 0;
    }
    p->rows[i].fa4 = 0x80000000;
    p->rows[i].fa0 = 0;
    p->rows[i].fae = 0;
    species = func_02017E1C(q, 5, 0);
    p->rows[i].seen = func_0200CED4(a, species);
    if (species != 32 && species != 29)
        p->rows[i].sex = func_02017F00(q);
    else
        p->rows[i].sex = 2;
    func_02208814((O *)p, func_02017F90(q), i);
    func_022079C0((char *)p, i, 0);
    func_02208D50((W *)p, i, 1);
    func_0220793C((S *)&p->rows[i]);
    func_0220785C((char *)p, mode, i, q);
}
