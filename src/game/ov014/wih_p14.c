/*
 * file:     wih_p14.c
 * unit:     yes
 * function: func_02179188, func_021791A0, func_021791EC
 * address:  0x02179188
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_021791F8  0x021791F8  thumb  ov014
 *   func_0208F370  0x0208F370  arm
 *   func_0208F380  0x0208F380  arm
 */
#include "../../matched/include/Obj19343.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef int BOOL;

extern void func_02178138(int);
extern void func_0217814C(int);
extern void func_021791F8(u16 *arg);
extern int func_0208F370(void *buf, void (*cb)(void *), int dma);
extern int func_0208F380(void *buf, void (*cb)(void *), int dma, int x);
void func_02179188(u8 *p);
BOOL func_021791A0(int a, int flag);
void func_021791EC(void);
extern u8 *g_021797A8;

/*
 * extent: two zero alignment bytes at 0217919E precede labelled 021791A0.
 */
void func_02179188(u8 *p) { if (((struct Obj19343 *)p)->f2 == 8) { func_02178138(9); func_0217814C(25); } }


/*
 * The DWC copy of WH_Initialize's WM start: WM_Initialize (0208F370) or, when
 * the flag is set, WM_InitializeForListening (0208F380), on the work block
 * behind g_021797A8 +0x40 with completion callback func_021791F8.  Anything
 * but WM_ERRCODE_OPERATING goes to the error setter.  The unlabelled
 * follower at 021791EC (`movs r0,#1; bx` tail call to func_02178138) is why
 * the extent runs long.
 */
BOOL func_021791A0(int a, int flag)
{
    int r;

    func_02178138(3);
    if (flag == 0)
        r = func_0208F370(g_021797A8 + 0x40, (void (*)(void *))func_021791F8, 2);
    else
        r = func_0208F380(g_021797A8 + 0x40, (void (*)(void *))func_021791F8, 2, 0);
    if (r != 2) {
        func_0217814C(r);
        func_02178138(10);
        return 0;
    }
    return 1;
}


/*
 * Unlabelled leaf: sets state 1 by tail-calling func_02178138.  Used as the
 * callback of func_021791F8's call to func_02090DEC.
 */
void func_021791EC(void)
{
    func_02178138(1);
}
