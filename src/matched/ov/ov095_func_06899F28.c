/*
 * unit: yes
 * function: BTLV_SCD_WaitActionMenu, BTLV_SCD_StartMoveMenu
 * address: 0x06899F28
 * packet: pkt_ov095_06899F28
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCD_RunTask 0x06899E68 thumb ov095
 *   BTLV_SCD_PushTask 0x06899E48 thumb ov095
 *   BTLV_SCD_WaitMoveTouchStep 0x0689A988 thumb ov095
 *   BTLV_SCD_OpenMoveMenuStep 0x0689A878 thumb ov095
 * Unlabelled setter follower at 06899F40 lies inside the handed extent.
 */
#include "../include/Obj07912.h"
#include "../include/Obj21889.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Slot { int (*f0)(void *,int); int (*f1)(void *,int); int arg; int data; } Slot;
typedef struct Q { u8 pad[0x20]; Slot tab[4]; int n; } Q;
extern int BTLV_SCD_RunTask(Q *);
extern void BTLV_SCD_PushTask(struct Q *p, void *a, void *b);
extern int BTLV_SCD_WaitMoveTouchStep(int,u8 *);
extern int BTLV_SCD_OpenMoveMenuStep(int,u8 *);
u32 BTLV_SCD_WaitActionMenu(u8 *p) {
 if(BTLV_SCD_RunTask((Q *)p)) return ((struct Obj21889 *)p)->f98;
 return 0;
}
void BTLV_SCD_StartMoveMenu(u8 *p, void *a, void *b) {
 ((struct Obj07912 *)p)->f6C=a;
 ((struct Obj07912 *)p)->f70=b;
 ((struct Obj07912 *)p)->f98=0;
 ((struct Obj07912 *)p)->f68=(void *)BTLV_SCD_WaitMoveTouchStep;
 BTLV_SCD_PushTask((struct Q *)p,(void *)BTLV_SCD_OpenMoveMenuStep,(void *)BTLV_SCD_WaitMoveTouchStep);
}
