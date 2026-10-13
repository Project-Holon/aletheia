/*
 * function: func_021DCBA4
 * address: 0x021DCBA4
 * packet: pkt_ov119_021DCBA4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021E36C8 0x021E36C8 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   FADE_Start 0x0204E720 arm
 */
#include "../include/Obj01728.h"
#include "../include/Obj03256.h"
typedef signed int     s32;
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void func_02082D44(void *,const void *,int);
extern void func_021E36C8(void *,int,int,void *,int);
extern int func_021D8AA8(void *);
extern void MCSS_SetVanishFlag(void *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
void func_021DCBA4(char *a, char *p)
{
    func_02082D44(((struct Obj01728 *)a)->f34,((struct Obj03256 *)p)->f5DC,POKE_TOOL_GetPartyParamSize());
    func_02082D44(((struct Obj01728 *)a)->f38,((struct Obj03256 *)p)->f5E0,POKE_TOOL_GetPartyParamSize());
    func_021E36C8(p,0,1,((struct Obj01728 *)a)->f34,1);
    func_021E36C8(p,1,1,((struct Obj01728 *)a)->f38,1);
    MCSS_SetVanishFlag((void *)(*(unsigned *)(p+(func_021D8AA8(p) == 0 ? 0x848 : 0x844))));
    ((struct Obj03256 *)p)->f830=((struct Obj01728 *)a)->f3C;
    ((struct Obj03256 *)p)->f834=((struct Obj01728 *)a)->f40;
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj03256 *)p)->f5F4);
    FADE_Start(3,16,0,2);
}
