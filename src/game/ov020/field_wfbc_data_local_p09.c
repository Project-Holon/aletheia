/*
 * file:     field_wfbc_data_local_p09.c
 * unit:     yes
 * function: func_02186B2C, func_02186B60, func_02186B84
 * address:  0x02186B2C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_02161ECC 0x02161ECC thumb ov010
 *   func_0218677C 0x0218677C thumb ov020
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 pad; u16 ids[8]; } T_02186B60;

typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 b3; } T_02186B84;

extern void func_02082D44(const void *src, void *dst, u32 size);
extern int func_02161ECC(T_02186B60 *p);
extern void func_0218677C(u8 *p, void *src);
char *func_02186B2C(char *p, char *src);
char *func_02186B60(char *p);
void func_02186B84(T_02186B84 *p, int a, int b, int c, int d);

/*
 * Lever: unsigned index scaling retains separate source/destination multiplies.
 */
char *func_02186B2C(char *p, char *src) { int i; for (i = 9; i > 0; i--) func_02082D44(p + (u32)(i - 1) * 24, p + (u32)i * 24, 24); func_02082D44(src, p, 24); return p; }

char *func_02186B60(char *p)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC((T_02186B60 *)(p + i * 24)) == 0)
            return p + i * 24;
    }
    return p;
}

/*
 * lever: assign the low bitfield before the byte fields; a later bitfield store changes scheduling.
 */
void func_02186B84(T_02186B84 *p, int a, int b, int c, int d)
{
    p->lo = 1;
    p->b1 = a;
    p->b3 = 7;
    p->b2 = c;
    if (d) func_0218677C((u8 *)p, (void *)b);
}
