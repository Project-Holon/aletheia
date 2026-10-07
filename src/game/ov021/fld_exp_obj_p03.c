/*
 * file:     fld_exp_obj_p03.c
 * unit:     yes
 * function: func_021BE630, func_021BE674, func_021BE6B0, func_021BE6B4, func_021BE6B8, func_021BE6BC
 * address:  0x021BE630
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
 *   func_02030734  0x02030734  arm
 *   d_021DE390     0x021DE390  data  a4
 */
#include "../../matched/include/Obj12904.h"

typedef unsigned short u16;

typedef unsigned char u8;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
void func_021BE630(int *p, int n, int heap);
void *func_021BE674(char *base, int i, unsigned int j, int k);
void func_021BE6B0(unsigned char *p, int v);
u8 func_021BE6B4(u8 *p);
void func_021BE6B8(unsigned char *p, int v);
int func_021BE6BC(int *p);
extern int d_021DE390;


void func_021BE630(int *p, int n, int heap)
{
    u8 *e = (u8 *)func_02030734((u16)heap, n << 4, 1, (const char *)&d_021DE390, 0x19D);
    int i;

    p[1] = (int)e;
    p[0] = n;
    for (i = 0; i < n; i++) {
        e[i * 16] = 0;
        e[i * 16 + 1] = 1;
        e[i * 16 + 2] = 0;
        *(int *)(e + i * 16 + 4) = 0x1000;
    }
}


void *func_021BE674(char *base, int i, unsigned int j, int k)
{
    char *e = base + i * 16;
    struct S {
        int n;
        char *arr;
    };
    char *arr;

    if (((struct Obj12904 *)e)->f8 == 0) {
        return 0;
    }
    if (j >= ((struct Obj12904 *)e)->f16) {
        return 0;
    }
    arr = (*(struct S **)(e + 0x10))[j].arr;
    if (k >= (*(struct S **)(e + 0x10))[j].n) {
        return 0;
    }
    return arr + k * 16;
}

void func_021BE6B0(unsigned char *p, int v)
{
    p[0] = v;
}


u8 func_021BE6B4(u8 *p)
{
    return *p;
}

/*
 * Unlabelled leaf: strb r1, [r0, #1].
 */
void func_021BE6B8(unsigned char *p, int v)
{
    p[1] = v;
}

int func_021BE6BC(int *p)
{
    return p[2] == 0;
}
