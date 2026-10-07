/*
 * file:     delivery_beacon_p03.c
 * unit:     yes
 * function: func_02157818, func_02157870, func_0215788C, func_021578A0, func_021578F0, func_02157910, func_02157928, func_02157938
 * address:  0x02157818
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F328  0x0203F328  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D010 0x0203D010 arm
 *   func_021576C4 0x021576C4 thumb ov010
 *   func_02157760 0x02157760 thumb ov010
 *   func_0203CD98  0x0203CD98  arm
 *   func_02157700  0x02157700  thumb  ov010
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_021576CC  0x021576CC  thumb  ov010
 *   d_021727E0  0x021727E0  data  ov010
 *   d_02172780  0x02172780  data  ov010
 *   func_02157724 0x02157724 thumb ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0203CEAC  0x0203CEAC  arm
 */
#include "../../matched/include/Obj04914.h"
#include "../../matched/include/Obj18737.h"

struct Req;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern void func_02082D44(void *, void *, u32);
extern void func_0203D010(void);
extern void func_021576C4(char *p, int v, int line);
extern void func_02157760(u8 *q);
extern int func_0203CD98(void);
extern void func_02157700(int *p);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_021576CC(void);
extern int func_02157724(u8 *);
extern u32 func_020307B0(void *p);
extern int func_0203CEAC(int a0);
void func_02157818(u8 *p);
void func_02157870(void *p);
void func_0215788C(void *p);
int func_021578A0(u32 *p);
int func_021578F0(void *p);
int func_02157910(u8 *p);
void func_02157928(u8 *p);
int func_02157938(void *a0);
extern u8 d_021727E0[];
extern u8 d_02172780[];


void func_02157818(u8 *p)
{
    u8 *base;
    int i;

    base = p;
    i = 0;
    base = p + 0x7C;

    for (; i < 0x12; i++) {
        u32 off = i * 0x54;
        u8 *e = base + i * 100;
        u32 n;

        func_0203F328((u16 *)(e + 8), 0x54, ((struct Obj18737 *)e)->f4);
        n = (u16)off;
        if (((struct Obj04914 *)p)->f8 > (int)(n + 0x54))
            func_02082D44(e + 8, (u8 *)((struct Obj04914 *)p)->fC + off, 0x54);
        else
            func_02082D44(e + 8, (u8 *)((struct Obj04914 *)p)->fC + off, ((struct Obj04914 *)p)->f8 - n);
    }
}

/*
 * extent: 28-byte lead followed by existing matched ov010_func_0215788C.c.
 */
void func_02157870(void *p) { func_0203D010(); func_021576C4(p, (int)func_02157760, 0x1d7); }


/*
 * Unlabelled tail-call thunk hidden in a .word run; witness for the
 * function pointer taken in func_021578A0.
 */
void func_0215788C(void *p)
{
    func_021576C4(p, (int)func_02157870, 0x1DD);
}


int func_021578A0(u32 *p)
{
    if (func_0203CD98() != 0)
        return 0;
    d_021727E0[7] = *p;
    *((u8 *)p + 0x31B8) = 0xFF;
    func_02157700((int *)p);
    func_0203CBAC((struct Req *)d_02172780, (u32)func_0215788C, (u32)p);
    func_021576C4((char *)p, (int)func_021576CC, 0x1F2);
    return 1;
}


/*
 * Unlabelled leaf, blocker of ov021 func_021D0C58: whether any of 18 slots (stride 100) has its flag byte set.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
int func_021578F0(void *p)
{
    int i;

    for (i = 0; i < 18; i++) {
        if (((u8 *)p)[i * 100 + 0xd9] != 0) {
            return 1;
        }
    }
    return 0;
}

/*
 * extent: 22 bytes of code followed by 2-byte alignment padding.
 */
int func_02157910(u8 *p) { int r; r = func_02157724(p); if (r) func_02157818(p); return r; }

void func_02157928(u8 *p) { (*(void (**)(u8 *))(p + 0x31bc))(p); }


int func_02157938(void *a0)
{

    a0 = (void *)func_020307B0(a0);
loc_0215793E:
a0 = 0;
    a0 = (void *)func_0203CEAC((int)a0);
loc_02157944:
    return (int)a0;}
