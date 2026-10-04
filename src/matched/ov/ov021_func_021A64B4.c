/*
 * function: func_021A64B4
 * address:  0x021A64B4
 * packet:   pkt_ov021_021A64B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A652C  0x021A652C  thumb  ov021
 *   func_021A658C  0x021A658C  thumb  ov021
 *   func_021A661C  0x021A661C  thumb  ov021
 *   func_021A666C  0x021A666C  thumb  ov021
 */
#include "../include/Obj04234.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021A3960(unsigned char *p);
extern int func_021A652C(void *a, void *x, int c, int d, int e, int f);
extern int func_021A658C(void *a, void *x, int c, int d, int e, int f);
extern int func_021A661C(void *a, void *x, int c, int d, int e, int f);
extern u32 func_021A666C(void *a, void *b, u32 c, u32 d, u32 e, u32 f);

int func_021A64B4(int *a, int b, int c, int d, int e)
{
    void *x = func_021A3960(*(unsigned char * *)&((struct Obj04234 *)a)->f14);
    int r = 0;
    switch (a[0]) {
    case 0: r = func_021A652C(a, x, b, c, d, e); break;
    case 1: r = func_021A658C(a, x, b, c, d, e); break;
    case 2: r = func_021A661C(a, x, b, c, d, e); break;
    case 3: r = func_021A666C(a, x, b, c, d, e); break;
    }
    return r;
}
