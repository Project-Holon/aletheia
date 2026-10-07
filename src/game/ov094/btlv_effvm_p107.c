/*
 * file:     btlv_effvm_p107.c
 * unit:     yes
 * function: func_02207288, func_02207430
 * address:  0x02207288
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
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
 *   d_0220AAC8 0x0220AAC8 data
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
struct Blk37;
struct PalAnmSlot;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct O O;

typedef struct { char pad[0x40]; u32 mode, side, a, b, f90, f94, f98, f9c, fa0, fa4, fa8; u8 level, sex, fae, seen; u32 flags, fb4, fb8, fbc; } Row;

typedef struct W { char pad[0x40]; Row rows[8]; } W;

typedef struct S S;

typedef struct { short x, y; } Pt;

typedef short s16;

typedef struct { s16 x, y, z; u8 pri, f7; } Cfg;

typedef struct {
    u32 f40, f44, f48, f4c, f50, f54;
    u32 f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry;

typedef struct {
    u32 f0, f4;
    char pad08[0x10];
    u32 pal[6];
    u32 f30, f34, f38, f3c;
    Entry entries[8];
    char pad440[8];
    u16 heap;
} Work;

typedef signed int     s32;

extern void func_02082A48(u32, void *, u32);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02018584(u16, u16, u16);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern u8 func_02017F00(void *);
extern u32 func_02017F90(void *);
extern void func_02208814(struct O *obj, int k, int idx);
extern void func_022079C0(char *, int, Pt *);
extern void func_02208D50(W *, int, int);
extern void func_0220793C(char *p);
extern void func_0220785C(struct O *o, int unused, int idx, void *data);
extern void func_0204ADA4(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_021F86E0(void);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_021F8710(void);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_02207288(W *p, void *a, void *q, int mode, int i);
void func_02207430(Work *p, int mode, int i);
extern const Cfg d_0220AAC8;

/*
 * trailing: 0220742E..02207430 is two zero alignment bytes.
 * lever: rows are an array member of the object; raw offset casts gave 416 bytes and the wrong field-base spills, while the member form gives exact 422 bytes.
 */
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
    func_0220793C((char *)((S *)&p->rows[i]));
    func_0220785C((struct O *)p, mode, i, q);
}

void func_02207430(Work *p, int mode, int i)
{
    int chr, pal, cell, cpal, j, n, side;
    Cfg cfg;
    switch (mode) {
    case 0:
    case 1:
    default:
        chr = (i & 1) ? 0xa5 : 0xa8;
        pal = (i & 1) ? 0xa6 : 0xa9;
        cell = (i & 1) ? 0xa7 : 0xaa;
        break;
    case 2:
    case 3:
        chr = (i & 1) ? 0xab : 0xae;
        pal = (i & 1) ? 0xac : 0xaf;
        cell = (i & 1) ? 0xad : 0xb0;
        break;
    case 4:
        break;
    }
    if (mode == 3) {
        j = i;
        if (i >= 2)
            j = i - 2;
        cpal = (i < 4) ? 0xa2 : 0xa3;
        func_0204ADA4(p->pal[j]);
        p->pal[j] = func_0204AC18((void *)p->f4, cpal, 0, (u16)(j << 5), 0, 1, p->heap);
        func_020216D4((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(func_0204AEF4(p->pal[j], 0) >> 1), 0x20);
    }
    p->entries[i].f58 = func_0204A6C8((void *)p->f4, chr, 0, 0, p->heap);
    p->entries[i].f5c = func_0204AF28((void *)p->f4, pal, cell, p->heap);
    p->entries[i].f60 = func_0204A6C8((void *)p->f4, 0xba, 0, 0, p->heap);
    p->entries[i].f64 = func_0204AF28((void *)p->f4, 0xbb, 0xbc, p->heap);
    p->entries[i].f68 = func_0204A6C8((void *)p->f4, 0xb1, 0, 0, p->heap);
    p->entries[i].f6c = func_0204AF28((void *)p->f4, 0xb2, 0xb3, p->heap);
    p->entries[i].f70 = func_0204A6C8((void *)p->f4, 0xb4, 0, 0, p->heap);
    p->entries[i].f74 = func_0204AF28((void *)p->f4, 0xb5, 0xb3, p->heap);
    side = i & 1;
    if (side == 0) {
        p->entries[i].f78 = func_0204A6C8((void *)p->f4, 0xb7, 0, 0, p->heap);
        p->entries[i].f7c = func_0204AF28((void *)p->f4, 0xb8, 0xb9, p->heap);
    }
    cfg = d_0220AAC8;
    j = i;
    if (i >= 2)
        j = i - 2;
    n = (7 - i) * 3;
    cfg.pri = n + 2;
    p->entries[i].f40 = (u32)func_0204B294((void *)p->f0, p->entries[i].f58, p->pal[j], p->entries[i].f5c, &cfg, 0, p->heap);
    cfg.pri = n + 1;
    p->entries[i].f44 = (u32)func_0204B294((void *)p->f0, p->entries[i].f60, p->pal[j], p->entries[i].f64, &cfg, 0, p->heap);
    p->entries[i].f48 = (u32)func_0204B294((void *)p->f0, p->entries[i].f68, p->pal[j], p->entries[i].f6c, &cfg, 0, p->heap);
    if (func_021F8710() == 3 && i >= 4)
        p->entries[i].f54 = (u32)func_0204B294((void *)p->f0, p->f30, p->f3c, p->f34, &cfg, 0, p->heap);
    else
        p->entries[i].f54 = (u32)func_0204B294((void *)p->f0, p->f30, p->f38, p->f34, &cfg, 0, p->heap);
    func_0204B92C((struct Obj *)p->entries[i].f54, 1);
    cfg.pri = n;
    p->entries[i].f4c = (u32)func_0204B294((void *)p->f0, p->entries[i].f70, p->pal[j], p->entries[i].f74, &cfg, 0, p->heap);
    func_0204B3DC((struct Obj *)p->entries[i].f4c, 0);
    if (side == 0 && mode != 2 && mode != 3)
        p->entries[i].f50 = (u32)func_0204B294((void *)p->f0, p->entries[i].f78, p->pal[j], p->entries[i].f7c, &cfg, 0, p->heap);
}
