/*
 * file:     wf2dmap_objdraw_p02.c
 * unit:     yes
 * function: func_021C5814, func_021C5834, func_021C5840, func_021C584C, func_021C5858, func_021C5864, func_021C5878
 * address:  0x021C5814
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C41DC  0x021C41DC  thumb  ov127
 *   func_021C425C  0x021C425C  thumb  ov127
 *   func_021C4230  0x021C4230  thumb  ov127
 *   func_021C424C  0x021C424C  thumb  ov127
 *   func_021C4224  0x021C4224  thumb  ov127
 *   func_021C5944  0x021C5944  thumb
 *   func_021C42C4  0x021C42C4  thumb
 */
#include "../../matched/include/Obj23048.h"
#include "../../matched/include/Obj23049.h"
#include "../../matched/include/Obj23050.h"
#include "../../matched/include/Obj23051.h"
#include "../../matched/include/Obj23052.h"
#include "../../matched/include/Obj00328.h"

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} P2;

typedef unsigned char  u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021C41DC(u8 *p, int x, int y);
extern int func_021C425C(char *p);
extern void func_021C4230(char *p, int a);
extern void func_021C424C(char *p, int a);
extern int func_021C4224(u8 *p);
extern void func_021C5944(u8 *p, int n, int a);
extern void func_021C42C4(u8 *p);
void func_021C5814(char *p, P2 v);
int func_021C5834(char *p);
void func_021C5840(char *p, int a);
void func_021C584C(u8 *p, int a);
int func_021C5858(u8 *p);
void func_021C5864(u8 *p, int b);
int func_021C5878(int a,int b);


/*
 * Unlabelled: forwards a by-value {s16 x, y} pair to func_021C41DC with the
 * pointer at +4.  Blocker of ov099 func_021BA2D4 / func_021BA36C.
 */
void func_021C5814(char *p, P2 v)
{
    func_021C41DC(((struct Obj23048 *)p)->f4, v.x, v.y);
}


/*
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=func_021C425C; bx r3.
 * Blocker of ov099 func_021BA2D4.
 */
int func_021C5834(char *p)
{
    return func_021C425C(((struct Obj23049 *)p)->f4);
}


void func_021C5840(char *p, int a)
{
    func_021C4230(((struct Obj23050 *)p)->f4, a);
}


/*
 * Unlabelled 8-byte ov127 accessor veneer in a .word run (0x021C5834,
 * 0x021C5840, 0x021C584C, 0x021C5858 are four in a row): `ldr r0,[r0,#0];
 * ldr r3,=func_021C424C; bx r3`.  Blocker target of src/pending/
 * ov099_func_021B98E4.c.
 *
 * Addresses are Black-image addresses.
 */
void func_021C584C(u8 *p, int a)
{
    func_021C424C(*(char * *)&((struct Obj23051 *)p)->f4, a);
}


/*
 * Unlabelled accessor veneer after func_021C584C (`ldr r0,[r0,#4]; ldr r3,=
 * func_021C4224; bx r3`).  Blocker of ov099 func_021B989C.
 */
int func_021C5858(u8 *p)
{
    return func_021C4224(((struct Obj23052 *)p)->f4);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C5864(u8 *p, int b)
{
    func_021C5944(p, 0, b);
    func_021C42C4(((struct Obj00328 *)p)->f4);
}

int func_021C5878(int a,int b) { if(b==1) return 250-a/4; else return 251-a/4; }
