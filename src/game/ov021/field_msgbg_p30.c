/*
 * file:     field_msgbg_p30.c
 * unit:     yes
 * function: func_0218D7A8, func_0218D934, func_0218D970, func_0218D980
 * address:  0x0218D7A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218DD84  0x0218DD84  thumb ov021
 *   func_0218DD98  0x0218DD98  thumb ov021
 *   func_0218DDA4  0x0218DDA4  thumb ov021
 *   func_0218DD70  0x0218DD70  thumb ov021
 *   func_0218DD4C  0x0218DD4C  thumb ov021
 *   func_0218B9FC  0x0218B9FC  thumb ov021
 *   func_02169500  0x02169500  thumb ov010
 *   func_021694F8  0x021694F8  thumb ov010
 *   func_021694D4  0x021694D4  thumb ov010
 *   func_02169470  0x02169470  thumb ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Cell {
    u32 id;             /* 0x00 */
    int x;              /* 0x04 */
    int y;              /* 0x08 */
    int z;              /* 0x0C */
} Cell;

typedef struct Entry {
    int obj;            /* 0x00 */
    u8 desc[0x14];      /* 0x04 */
    Cell cell;          /* 0x18 */
} Entry;

typedef struct Obj {
    u16 heap;           /* 0x00 */
    u8 pad02[2];
    int size;           /* 0x04 */
    int height;         /* 0x08 */
    u32 mode;           /* 0x0C */
    u32 f10;            /* 0x10 */
    u16 w;              /* 0x14 */
    u16 h;              /* 0x16 */
    u32 count;          /* 0x18 */
    int *table;         /* 0x1C */
    u32 f20;            /* 0x20 */
    Entry *entries;     /* 0x24 */
    Cell *f28;          /* 0x28 */
    u8 cols;            /* 0x2C */
    u8 rows;            /* 0x2D */
    u16 n;              /* 0x2E */
    u8 pad30[0x64 - 0x30];
    int f64;            /* 0x64 */
} Obj;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern int func_0218DD84(u32 a);
extern u32 func_0218DD98(u8 *p);
extern void func_0218DDA4(Cell *c, Vec *v);
extern int func_0218DD70(u32 a);
extern void func_0218DD4C(void **a);
extern void func_0218B9FC(int a, int obj);
extern void func_02169500(u8 *p, u8 *q);
extern void func_021694F8(u8 *p, u16 v);
extern void func_021694D4(int obj);
extern void func_02169470(u8 *obj, u32 member);
extern u32 func_0207C768(u32 a, u32 b);
extern int func_0207C994(int a, int b);
int func_0218D7A8(Obj *p, Cell *nc);
int func_0218D934(u32 a, int b, int c);
int func_0218D970(u32 a, int b, int c);
int func_0218D980(u32 a, int b, int c);


/*
 * Reconciles the grid object's live entries with a freshly laid-out cell
 * array (func_0218CA78's tail): entries whose id survives move to the new
 * position, the rest are hidden and released; new cells then take a free
 * entry.  Returns 1 when any free entry was claimed.
 */
int func_0218D7A8(Obj *p, Cell *nc)
{
    int placed;
    int moved;
    int changed;
    int ret;
    int i;
    int j;

    ret = 0;
    for (i = 0; i < p->n; i++) {
        if (func_0218DD84((u32)(&p->entries[i].cell))) {
            u32 id;
            moved = 0;
            id = func_0218DD98((u8 *)(&p->entries[i].cell));
            for (j = 0; j < p->n; j++) {
                if (id == func_0218DD98((u8 *)(&nc[j])) && !moved) {
                    Vec v;
                    func_0218DDA4(&nc[j], &v);
                    func_02169500((u8 *)p->entries[i].obj, (u8 *)(&v));
                    func_0218DD70((u32)(&nc[j]));
                    moved = 1;
                }
            }
            if (!moved) {
                func_0218DD70((u32)(&p->entries[i].cell));
                func_021694F8((u8 *)p->entries[i].obj, 0);
                func_0218B9FC(p->f64, p->entries[i].obj);
                func_0218DD4C((void **)p->entries[i].desc);
                func_021694D4(p->entries[i].obj);
            }
        }
    }
    changed = 0;
    for (i = 0; i < p->n; i++) {
        if (func_0218DD84((u32)(&nc[i]))) {
            placed = 0;
            for (j = 0; j < p->n; j++) {
                if (!func_0218DD84((u32)(&p->entries[j].cell)) && !placed) {
                    int obj = p->table[func_0218DD98((u8 *)(&nc[i]))];
                    Vec v;
                    func_0218DDA4(&nc[i], &v);
                    if (obj != -1) {
                        func_02169470((u8 *)p->entries[j].obj, (u32)obj);
                        func_02169500((u8 *)p->entries[j].obj, (u8 *)(&v));
                        func_021694F8((u8 *)p->entries[j].obj, 1);
                    }
                    p->entries[j].cell = nc[i];
                    placed = 1;
                    changed = 1;
                }
            }
        }
    }
    if (changed == 1)
        ret = 1;
    return ret;
}


int func_0218D934(u32 a, int b, int c)
{
    int r = -(int)((a >> 1) - 1);
    int q = c / b;
    if (c % b < (int)func_0207C768((int)b, (int)0x2000))
        r += q - 1;
    else
        r += q;
    return r;
}


int func_0218D970(u32 a, int b, int c)
{
    int r = -(int)(a >> 1);
    r += c / b;
    return r;
}


int func_0218D980(u32 a, int b, int c)
{
    int r = ((int)func_0207C768((int)c, (int)b) >> 12) - (a >> 1);
    if ((a & 1) == 0) {
        int m = func_0207C994(c, b);
        if ((int)func_0207C768((int)b, (int)0x2000) < m)
            r++;
    }
    return r;
}
