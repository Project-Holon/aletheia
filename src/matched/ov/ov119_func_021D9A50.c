/*
 * function: func_021D9A50
 * address: 0x021D9A50
 * packet: pkt_ov119_021D9A50
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9750 0x021D9750 thumb ov119
 *   func_021D99F4 0x021D99F4 thumb ov119
 *   func_021DADAC 0x021DADAC thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_021D8E84(void *,int);
extern void func_021D9750(char *p);
extern void func_021D99F4(char *p);
extern void func_021DADAC(void *);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void func_021D9A50(char *p) { int v; if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));func_021E12F8(p);func_021E1098(p);*(int *)&((struct Obj00001 *)p)->f64C=0;switch(v) {case 0:func_021D8E84(p,(int)func_021D9750);return;case 1:WIPE_SYS_Start((void *)3,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);func_021D8E84(p,(int)func_021D99F4);return;case 2:func_021D8E84(p,(int)func_021DADAC);return;} } }
