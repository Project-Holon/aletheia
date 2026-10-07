/*
 * file:     fldmmdl_p38.c
 * unit:     yes
 * function: func_0216E3C8, func_0216E3CC, func_0216E3D0, func_0216E3D8, func_0216E400, func_0216E40C, func_0216E418, func_0216E42C, func_0216E434
 * address:  0x0216E3C8
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
 *   func_020143CC 0x020143CC thumb
 *   d_021D5E04  0x021D5E04  data  ov093  a4
 *   d_021D770C  0x021D770C  data  ov021  a4
 *   func_020142E8  0x020142E8  thumb
 */
#include "../../matched/include/Obj19137.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

extern unsigned int func_020143CC(unsigned int, unsigned int);
extern unsigned int func_020142E8(void *bitmap, int id);
void *func_0216E3C8(void *p);
u8 *func_0216E3CC(u8 *p);
int func_0216E3D0(int a, int b);
unsigned int func_0216E3D8(unsigned int a, unsigned int id);
u32 func_0216E400(int i);
u32 func_0216E40C(int i);
int func_0216E418(void *a);
unsigned int func_0216E42C(void *bitmap, int id);
u32 func_0216E434(u32 a);
extern u32 d_021D5E04[];
extern u32 d_021D770C[];

/*
 * Unlabelled leaf: adds r0, #0x10; bx lr.
 */
void *func_0216E3C8(void *p)
{
    return (char *)p + 0x10;
}


/*
 * Unlabelled leaf: returns its argument plus 0x10.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_0216E3CC(u8 *p)
{
    return p + 0x10;
}


/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0216E3D9);
 * the sole blocker of ov021 func_021B181C.
 */
int func_0216E3D0(int a, int b)
{
    return func_0216E3D8(a, b);
}

unsigned int func_0216E3D8(unsigned int a, unsigned int id) { if (id>=162 && id<=177) { if(a==0) id=10; else id=*(u16 *)func_020143CC(a,(u16)(id+0x3f7e)); } return id; }


/*
 * note: the parked file gave no overlay hint; un-hinted, sole-ref/data saw
 * data at 0x021D5E04 in several overlapping overlays and refused.  ov093 is
 * the one overlay where it is a data object start, so the hint fixes the
 * choice and the site resolves as sole-ref/data.
 */
u32 func_0216E400(int i)
{
    return d_021D5E04[i];
}


/*
 * note: the parked file gave no overlay hint; un-hinted, sole-ref saw data at
 * 0x021D770C in several overlapping overlays and refused.  ov021 is the
 * pointer-table home of the word (the ov021 datum is 0x021D86C0), so the hint
 * fixes the choice and the site resolves as sole-ref/self.
 */
u32 func_0216E40C(int i)
{
    return d_021D770C[i];
}

int func_0216E418(void *a) { if (((struct Obj19137 *)a)->fA==65535) return 1; return 0; }


/*
 * Tail call thunk: forwards its arguments unchanged to 0x020142E8.
 */
unsigned int func_0216E42C(void *bitmap, int id)
{
    return func_020142E8(bitmap, id);
}

/*
 * Classify an id: 1 for the eight 'special' values, the id itself otherwise.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216E434(u32 a)
{
switch (a) {
case 4:
case 5:
case 6:
case 7:
case 8:
case 11:
case 12:
case 13:
return 1;
}
return a;
}
