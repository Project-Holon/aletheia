/*
 * file:     field_wfbc_p02.c
 * unit:     yes
 * function: func_02193F34, func_02193F6C, func_02193F80, func_02193FBC, func_02193FD4, func_02193FE8, func_02194014, func_02194038
 * address:  0x02193F34
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
 *   func_021867B0  0x021867B0  thumb  ov020
 *   func_02082BCC  0x02082BCC  arm  arm9
 *   func_02082D44  0x02082D44  arm  arm9
 *   func_02161ECC  0x02161ECC  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_02193F34;

typedef struct E50_02193F34 {
    u16 f00;
    u8  pad02[0x32];
    u8  f34[0x1C];
} E50_02193F34;

typedef struct E18 {
    u8 b[0x18];
} E18;

typedef struct Tbl {
    u8  hdr[8];
    E18 e[10];
} Tbl;

typedef struct V {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50_02193F34 *f04;
    Tbl *f08;
} V;

typedef struct E50_02193F6C {
    u16 f00;
    u8  pad02[0x4E];
} E50_02193F6C;

typedef struct E50_02193F80 {
    u16 f00;
    u16 f02;
    u8  f04[0x30];
    u8  f34[0x18];
    u16 f4c;
    u16 f4e;
} E50_02193F80;

typedef signed short   s16_02193FBC;

typedef signed char    s8;

typedef struct { u8 a; u8 b; u16 c; } Cell_02193FE8;

typedef struct { u8 a; u8 b; } Pair;

typedef struct { Pair k; u16 c; } Cell_02194014;

extern int func_021867B0(u8 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02161ECC(void *a);
extern void func_02082D44(void *src, void *dst, int n);
E50_02193F34 *func_02193F34(V *v, u32 key);
void func_02193F6C(E50_02193F6C *e);
void func_02193F80(E50_02193F80 *e, void *a, u8 *b, void *c);
void func_02193FBC(u16 *a, void *b);
void func_02193FD4(u16 *a, void *b);
void func_02193FE8(Cell_02193FE8 (*t)[8]);
void func_02194014(Cell_02194014 (*t)[8], int j, int i, Pair e, u16 c);
u32 func_02194038(char *a, int b, int c);



/*
 * Addresses are Black-image addresses.
 */
E50_02193F34 *func_02193F34(V *v, u32 key)
{
    int i;

    if (v->f04 != 0) {
        for (i = 0; i < 10; i++) {
            if (v->f04[i].f00 != 0 && key == func_021867B0(v->f04[i].f34))
                return &v->f04[i];
        }
    }
    return 0;
}



void func_02193F6C(E50_02193F6C *e)
{
    func_02082BCC(e, 0, 0x50);
    e->f00 = 0;
}



void func_02193F80(E50_02193F80 *e, void *a, u8 *b, void *c)
{
    func_02161ECC(a);
    e->f00 = 1;
    func_02082D44(a, e->f34, 0x18);
    func_02082D44(c, e->f04, 0x30);
    e->f4c = b[0];
    e->f4e = b[1];
}



void func_02193FBC(u16 *a, void *b)
{
    if (*a == 1) {
        func_02082D44(b, (u8 *)a + 0x34, 0x18);
    }
}



void func_02193FD4(u16 *a, void *b)
{
    if (*a == 1) {
        func_02082D44((u8 *)a + 0x34, b, 0x18);
    }
}



void func_02193FE8(Cell_02193FE8 (*t)[8])
{
    int i;
    int j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            t[i][j].b = 0xFF;
            t[i][j].c = 0xFFFF;
        }
    }
}



/*
 * Cell holds the Pair as one member; the struct copy t[i][j].k = e emits the
 * two byte stores, the first one addressed [j*4, row].
 *
 * Addresses are Black-image addresses.
 */
void func_02194014(Cell_02194014 (*t)[8], int j, int i, Pair e, u16 c)
{
    t[i][j].k = e;
    t[i][j].c = c;
}



u32 func_02194038(char *a, int b, int c)
{
    return *(u32 *)(a + c * 0x20 + b * 4);
}
