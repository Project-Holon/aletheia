/*
 * file:     wih_p09.c
 * unit:     yes
 * function: func_021788FC, func_02178964, func_02178980
 * address:  0x021788FC
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
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217863C  0x0217863C  thumb  ov014
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   WM_EndParent                     0x0208F808  arm
 *   DWCi_MOV_WH_SetError             0x0217814C  thumb
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_021789C8  0x021789C8  thumb  ov014
 */
#include "../../matched/include/G_S.h"
#include "../../matched/include/Obj12472.h"
#include "../../matched/include/Obj12473.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed short s16;

void func_02178138(int a);
int func_0217863C(void);
int func_02087988(void);
void func_0208799C(int a);
extern int WM_EndParent(void *);
extern void DWCi_MOV_WH_SetError(int code);
void func_0217814C(int a);
int func_021789C8(void);
int func_021788FC(void);
void func_02178980(u8 *m);
extern struct S *g_021797A8;


int func_021788FC(void)
{
    int irq;
    int r = 0;

    irq = func_02087988();

    if (*(u32 *)(((u8 *)g_021797A8) + 0x1E70) == 2) {
        if (*(s16 *)(((u8 *)g_021797A8) + 0x1EBE) != 0) {
            if (func_0217863C() == 0)
                func_02178138(9);
        }
        *(s16 *)(((u8 *)g_021797A8) + 0x1EBE) = -1;
        *(u16 *)(((u8 *)g_021797A8) + 0x1EB4) = 0;
        r = 1;
        ((u8 *)g_021797A8)[0x1EDF] = 1;
        func_02178138(3);
    }
    func_0208799C(irq);
    return r;
}


static int DWCi_MOV_WH_StateInEndParent(void)
{
	int result;

	result = WM_EndParent((void *)0x02178981);
	if (result != 2)
	{
		DWCi_MOV_WH_SetError(result);
		return 0;
	}
	return 1;
}


void func_02178980(u8 *m)
{
    u8 *g;

    ((u8 *)g_021797A8)[0x1EDF] = 0;
    if (((struct Obj12472 *)m)->f2 != 0) {
        func_0217814C(((struct Obj12472 *)m)->f2);
        return;
    }
    func_02178138(1);
    g = ((u8 *)g_021797A8);
    if (((struct Obj12473 *)g)->f1EB4 != 0) {
        ((struct Obj12473 *)g)->f1EB4 = 0;
        if (func_021789C8() == 0)
            func_02178138(9);
    }
}
