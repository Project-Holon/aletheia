/*
 * file:     field_msgbg_p20.c
 * unit:     yes
 * function: func_0218C3B0, func_0218C3E0
 * address:  0x0218C3B0
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
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   d_021D3D5C     0x021D3D5C  data  a4
 *   func_0218C388  0x0218C388  thumb  ov021
 *   func_0218C23C  0x0218C23C  thumb  ov021
 *   func_0218C2E4  0x0218C2E4  thumb  ov021
 *   func_0218C290  0x0218C290  thumb  ov021
 *   func_0218C350  0x0218C350  thumb  ov021
 */
#include "../../matched/include/G_Ops.h"

typedef struct {
    void (*f0)(void *p, void *s);
    void (*f4)(void *p, int idx, int c);
    void (*f8)(void);
} Ops;

typedef struct {
    int f0;
    int *f4;
} Obj;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

u8 *func_0218BCAC(u8 *p);
extern void func_0218C388(u32 *st);
extern void func_0218C23C(u32 *st, int n);
extern void func_0218C2E4(u32 *st, int n);
extern void func_0218C290(u32 *st, int n);
extern void func_0218C350(u32 *st, int n);
void func_0218C3B0(Obj *p, int i, int c);
void func_0218C3E0(u32 *st, int n, int mode);
extern struct Ops d_021D3D5C[];


void func_0218C3B0(Obj *p, int i, int c)
{
    unsigned char k = *func_0218BCAC((u8 *)(*p->f4));
    unsigned char idx = i;
    if (idx >= 4)
        idx = 0;
    d_021D3D5C[k].f4(p, idx, c);
}


/*
 * Dispatches a slot-group operation by mode 0..4.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C3E0(u32 *st, int n, int mode)
{
    switch (mode) {
    case 0:
        func_0218C388(st);
        func_0218C23C(st, n);
        break;
    case 1:
        func_0218C388(st);
        func_0218C2E4(st, n);
        break;
    case 2:
        func_0218C388(st);
        func_0218C290(st, n);
        break;
    case 3:
        func_0218C350(st, n);
        break;
    case 4:
        func_0218C388(st);
        break;
    }
}
