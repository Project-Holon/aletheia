/*
 * file:     field_wfbc_p08.c
 * unit:     yes
 * function: func_02193FBC, func_02193FD4, func_02193FE8, func_02194014, func_02194038
 * address:  0x02193FBC
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
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 a; u8 b; u16 c; } Cell_02193FE8;

typedef struct { u8 a; u8 b; } Pair;

typedef struct { Pair k; u16 c; } Cell_02194014;

extern void func_02082D44(void *src, void *dst, int n);
void func_02193FBC(u16 *a, void *b);
void func_02193FD4(u16 *a, void *b);
void func_02193FE8(Cell_02193FE8 (*t)[8]);
void func_02194014(Cell_02194014 (*t)[8], int j, int i, Pair e, u16 c);
u32 func_02194038(char *a, int b, int c);


/*
 * Addresses are Black-image addresses.
 */
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
