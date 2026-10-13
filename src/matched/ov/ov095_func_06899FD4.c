/*
 * unit:     yes
 * function: BTLV_SCD_WaitMoveMenu, BTLV_SCD_ReopenMenu, BTLV_SCD_StartMoveInfoMenu, BTLV_SCD_StartTargetMenu, BTLV_SCD_WaitTargetMenu, BTLV_SCD_CancelMenus
 * address:  0x06899FD4
 * packet:   pkt_ov095_06899FD4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed extent 0x06899FC4 (108 bytes) opens with a 16-byte `bx pc` veneer
 * to 0x021D8434 (ARM linker stub, not compilable); the six unlabelled
 * tail-call stubs after it (0x06899FD4..0x0689A030) are this unit.
 *
 * symbols:
 *   BTLV_SCD_RunTask  0x06899E68  thumb  ov095
 *   BTLV_SCD_PushTask  0x06899E48  thumb  ov095
 *   BTLV_SCD_ClearTasks  0x06899E2C  thumb  ov095
 *   BTLV_SCD_OpenMoveMenuStep  0x0689A878  thumb  ov095
 *   BTLV_SCD_WaitBackTouchStep  0x0689A84C  thumb  ov095
 *   BTLV_SCD_OpenTargetMenuStep  0x0689B0D4  thumb  ov095
 *   BTLV_SCD_WaitTargetTouchStep  0x0689B1E4  thumb  ov095
 */
#include "../include/Obj10164.h"
#include "../include/Obj13634.h"
#include "../include/Obj21890.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BTLV_SCD_RunTask(void);
struct Q;
extern void BTLV_SCD_PushTask(struct Q *p, void *a, void *b);
extern void BTLV_SCD_ClearTasks(void);
extern int BTLV_SCD_OpenMoveMenuStep(int unused, u8 *s);
extern int BTLV_SCD_WaitBackTouchStep(u32 unused, u32 p);
extern int BTLV_SCD_OpenTargetMenuStep(int unused, u8 *s);
extern int BTLV_SCD_WaitTargetTouchStep(int *state, u8 *s);

void BTLV_SCD_WaitMoveMenu(void)
{
    BTLV_SCD_RunTask();
}

void BTLV_SCD_ReopenMenu(u8 *p)
{
    BTLV_SCD_PushTask((struct Q *)p, 0, (void *)((struct Obj21890 *)p)->f68);
}

void BTLV_SCD_StartMoveInfoMenu(u8 *p, u32 a, u32 b)
{
    ((struct Obj10164 *)p)->f6C = a;
    ((struct Obj10164 *)p)->f70 = b;
    ((struct Obj10164 *)p)->f98 = 0;
    BTLV_SCD_PushTask((struct Q *)p, (void *)BTLV_SCD_OpenMoveMenuStep, (void *)BTLV_SCD_WaitBackTouchStep);
}

void BTLV_SCD_StartTargetMenu(u8 *p, u32 a, u32 b)
{
    ((struct Obj13634 *)p)->f6C = a;
    ((struct Obj13634 *)p)->f70 = b;
    BTLV_SCD_PushTask((struct Q *)p, (void *)BTLV_SCD_OpenTargetMenuStep, (void *)BTLV_SCD_WaitTargetTouchStep);
}

void BTLV_SCD_WaitTargetMenu(void)
{
    BTLV_SCD_RunTask();
}

void BTLV_SCD_CancelMenus(void)
{
    BTLV_SCD_ClearTasks();
}
