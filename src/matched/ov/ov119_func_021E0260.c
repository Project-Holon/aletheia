/*
 * function: POKETRADE_SAVE_FreeBackups
 * address: 0x021E0260
 * packet: pkt_ov119_021E0260
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj01536.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *,int,int);
void POKETRADE_SAVE_FreeBackups(char *p)
{
    int zero;
    if (((struct Obj01536 *)p)->f60C) func_020307B0(((struct Obj01536 *)p)->f60C);
    if (((struct Obj01536 *)p)->f610) func_020307B0(((struct Obj01536 *)p)->f610);
    if (((struct Obj01536 *)p)->f614) func_020307B0(((struct Obj01536 *)p)->f614);
    if (((struct Obj01536 *)p)->f618) func_020307B0(((struct Obj01536 *)p)->f618);
    if (((struct Obj01536 *)p)->f61C) func_020307B0(((struct Obj01536 *)p)->f61C);
    if (((struct Obj01536 *)p)->f620) func_020307B0(((struct Obj01536 *)p)->f620);
    if (((struct Obj01536 *)p)->f624) func_020307B0(((struct Obj01536 *)p)->f624);
    zero=0;
    MI_CpuFill8(p+0x60c,zero,36);
    p[0x11f7]=zero;
}
