/*
 * file:     weather_task_p35.c
 * unit:     yes
 * function: func_021A3920, func_021A392C, func_021A3938
 * address:  0x021A3920
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
 *   func_0216D5F8  0x0216D5F8  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_02012B30  0x02012B30  thumb
 */
#include "../../matched/include/Obj18033.h"
#include "../../matched/include/Obj19776.h"
#include "../../matched/include/Obj18034.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u16 func_0216D5F8(u32);
extern void func_0216D5E0(int, int);
extern u32 func_02012B30(u32, u32);
extern void func_021A3AD8(u8 *p, int a);
u16 func_021A3920(u8 *p);
void func_021A392C(void *p, int b);
int func_021A3938(u32 a, u32 b);


/*
 * Tail-call thunk: the object's word at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3920(u8 *p)
{
    return func_0216D5F8(((struct Obj18033 *)p)->f1C);
}


/*
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x1c]; ldr r3,[pc,#4]; bx r3; nop; .word 0x0216D5E1
 * The pool word carries the Thumb bit for func_0216D5E0, which is traced
 * only in ov010 (0x0216D5E0 is data in ov009), so the hint names ov010.
 */
void func_021A392C(void *p, int b)
{
    func_0216D5E0(((struct Obj19776 *)p)->f1C, b);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3938(u32 a, u32 b)
{
func_021A3AD8((u8 *)a, b);
return func_02012B30(((struct Obj18034 *)((u8 *)(a)))->fC, b);
}
