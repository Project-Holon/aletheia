/*
 * function: func_021DBA80
 * address: 0x021DBA80
 * packet: pkt_ov119_021DBA80
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_021D94A0 0x021D94A0 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBA38 0x021DBA38 thumb ov119
 */
#include "../include/Obj00001.h"
extern void MI_CpuFill8(void *,int,int);
extern void func_021D8C84(void *);
extern void func_021DF7AC(void *,int);
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_021D94A0(void *,int);
extern void func_021D8E84(void *,int);
extern void func_021DBA38(void *);
void func_021DBA80(char *p)
{
    ((struct Obj00001 *)p)->f1088=0;
    ((struct Obj00001 *)p)->f1078=0;
    ((struct Obj00001 *)p)->f107A=0;
    MI_CpuFill8(p+0xca0,0,0x78);
    MI_CpuFill8(p+0xd18,0,0x3c);
    MI_CpuFill8(p+0xd54,0,0x3c);
    func_021D8C84(p);
    func_021DF7AC(p,1);
    if(*(int *)&((struct Obj00001 *)p)->f64C) {
        APP_TASKMENU_CloseMenu((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C));
        *(int *)&((struct Obj00001 *)p)->f64C=0;
    }
    func_021D94A0(p,0);
    func_021D8E84(p,(int)func_021DBA38);
}
