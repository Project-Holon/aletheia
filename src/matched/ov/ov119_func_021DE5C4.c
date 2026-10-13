/*
 * function: func_021DE5C4
 * address: 0x021DE5C4
 * packet: pkt_ov119_021DE5C4
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
 *   WIPE_SYS_Start 0x0202208C thumb
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_021DEBD4 0x021DEBD4 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE12C 0x021DE12C thumb ov119
 *   func_021DE518 0x021DE518 thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
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
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void func_021DEBD4(void *);
extern int func_021D8980(char *p);
extern void func_021DD09C(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DE12C(char *p);
extern void func_021DE518(void *);
extern void func_021DEA24(char *p);
void func_021DE5C4(char *p)
{
    int v;
    if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
        v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
        func_021E12F8(p); func_021E1098(p);
        *(int *)&((struct Obj00001 *)p)->f64C=0;
        switch(v) {
        case 0: func_021D8E84(p,(int)func_021DE12C); return;
        case 1:
            WIPE_SYS_Start((void *)3,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
            TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,0);
            func_021D8E84(p,(int)func_021DE518); return;
        case 2:
            func_021DEBD4(p); func_021D8980(p); func_021DD09C(p);
            func_021D8E84(p,(int)func_021DEA24); return;
        }
    }
}
