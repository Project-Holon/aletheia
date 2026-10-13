/*
 * function: BTLV_SCD_StartRotateMenu
 * address:  0x06899F64
 * packet:   pkt_ov095_06899F64
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCD_PushTask  0x06899E48  thumb  ov095
 *   func_06899FA4  0x06899FA4  thumb  ov095
 *   func_06899FB4  0x06899FB4  thumb  ov095
 *   func_06899FC4  0x06899FC4  thumb  ov095
 *   BTLV_SCD_WaitRotateTouchStep  0x0689ABA0  thumb  ov095
 *   BTLV_SCD_OpenRotateMenuStep  0x0689AB48  thumb  ov095
 */
#include "../include/Obj07913.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Q;
extern void BTLV_SCD_PushTask(struct Q *p, void *a, void *b);
extern void func_06899FA4(void *);
extern void func_06899FB4(void *);
extern void func_06899FC4(void *);
extern int BTLV_SCD_WaitRotateTouchStep(int unused, u8 *s);
extern int BTLV_SCD_OpenRotateMenuStep(int unused, u8 *s);

void BTLV_SCD_StartRotateMenu(u8 *s, u8 *a, void *b)
{
    ((struct Obj07913 *)s)->f98 = 0;
    *(u8 * *)&((struct Obj07913 *)s)->f7C = a;
    ((struct Obj07913 *)s)->f70 = b;
    ((struct Obj07913 *)s)->f68 = (void *)BTLV_SCD_WaitRotateTouchStep;
    func_06899FA4(b);
    func_06899FB4(a + 0x18);
    func_06899FC4(a + 0x1c);
    BTLV_SCD_PushTask((struct Q *)s, (void *)BTLV_SCD_OpenRotateMenuStep, (void *)BTLV_SCD_WaitRotateTouchStep);
}
