/*
 * function: func_021DF548
 * address: 0x021DF548
 * packet: pkt_ov119_021DF548
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
 *   func_021DF510 0x021DF510 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_021D8E84(void *, int);
extern void func_021DF510(char *p);
extern void func_021DBBD0(char *p);
void func_021DF548(void *p)
{
    int v;
    if (!APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) return;
    v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    *(int *)&((struct Obj00001 *)p)->f64C=0;
    if (v==0) {func_021D8E84(p,(int)func_021DF510);return;}
    func_021E1098(p);
    func_021D8E84(p,(int)func_021DBBD0);
}
