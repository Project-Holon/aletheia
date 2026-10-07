/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3890, func_021F38D4, func_021F3904
 * address:  0x021F3890
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   d_021F4290  0x021F4290  data  ov056  a4
 *   d_021F42D8  0x021F42D8  data  ov056  a4
 *   func_0218C860 0x0218C860 thumb ov021
 *   func_0218C69C 0x0218C69C thumb ov021
 *   func_0218C88C 0x0218C88C thumb ov021
 */
#include "../../matched/include/Obj03166.h"

typedef unsigned int u32;

typedef struct { u32 a, b, c; } Ent;

extern int func_0218C7D8(void *p, int b, int c);
extern int func_0218C654(int a, int b, int c);
extern void func_0218C860(void *);
extern void func_0218C69C(unsigned char *,int,int,int);
extern void func_0218C88C(unsigned char *,int,int);
void func_021F3890(u32 *out, int a, int idx);
void func_021F38D4(unsigned char *p);
void func_021F3904(unsigned char **p);
extern u32 d_021F4290[];
extern Ent d_021F42D8[];


void func_021F3890(u32 *out, int a, int idx)
{
    if (d_021F4290[idx] != 0) {
        out[0] = func_0218C7D8((void *)a, 0, (int)(&d_021F42D8[idx]));
        out[1] = func_0218C654(a, 0, (int)(&d_021F42D8[idx]));
        out[2] = a;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}

void func_021F38D4(unsigned char *p) { if (((struct Obj03166 *)p)->f0) { func_0218C860(((struct Obj03166 *)p)->f0); func_0218C69C(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,1); func_0218C69C(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,3); *(int *)&((struct Obj03166 *)p)->f0=0; ((struct Obj03166 *)p)->f4=0; *(int *)&((struct Obj03166 *)p)->f8=0; } }

void func_021F3904(unsigned char **p) { if (*p) func_0218C88C(*p,0,0); }
