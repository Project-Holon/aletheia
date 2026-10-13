/*
 * function: func_021DB45C
 * address: 0x021DB45C
 * packet: pkt_ov119_021DB45C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_0207D658 0x0207D658 arm
 *   func_021E71E0 0x021E71E0 thumb ov119
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB41C 0x021DB41C thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void func_021DF7AC(void *,int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021E71E0(void *,int);
extern int func_021DD2F4(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DB41C(char *p);
void func_021DB45C(char *p)
{
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,0);
    func_021DF7AC(p,0);
    func_0207D658((u32)((void *)0x04001050),10,-8);
    func_021E71E0(p,1);
    if(func_021DD2F4(p))
        TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    func_021D8E84(p,(int)func_021DB41C);
}
