/*
 * function: func_021D72D8
 * address: 0x021D72D8
 * packet: pkt_ov123_021D72D8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D57D0 0x021D57D0 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62D0 0x021D62D0 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D6458 0x021D6458 thumb ov123
 *   func_021D652C 0x021D652C thumb ov123
 *   func_021D7204 0x021D7204 thumb ov123
 *   func_021D7180 0x021D7180 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   GAME_DATA_SaveMain  0x02012DD0  thumb  arm9
 *   POKE_TOOL_Dummy  0x020185F0  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01254.h"
typedef unsigned short u16;
typedef struct { u16 f0; char *f4; void (*f8)(char *); } Callback;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int GAME_DATA_SaveMain(u8 *p);
extern void func_021D584C(char *);
extern void func_021D57D0(void *p, int msg, int n, void *mon);
extern void func_021D5960(char *,int,int);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_021D62BC(u8 *p, int i, u32 v);
extern void func_021D62D0(u8 *p, int i, int v);
extern void func_021D6650(u8 *p, int flag);
extern int POKE_TOOL_Dummy(void *);
struct Obj02181;
extern void func_021D6458(struct Obj02181 *p, void *n, int i);
extern void func_021D652C(char *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021D7204(u8 *p);
extern void func_021D7180(int a);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D72D8(char *p)
{
    Callback cb;
    func_02009448(((struct Obj01254 *)p)->f28);
    if (GAME_DATA_SaveMain(((struct Obj01254 *)p)->f2C)==2) {
        ((struct Obj01254 *)p)->fAD=0;
        ((struct Obj01254 *)p)->fAB=0;
        ((struct Obj01254 *)p)->fAE=0;
        func_021D584C(*(char * *)&((struct Obj01254 *)p)->f18);
        func_021D57D0(*(char * *)&((struct Obj01254 *)p)->f18,45,0,(void *)(*(int *)&((struct Obj01254 *)p)->fC));
        func_021D5960(*(char * *)&((struct Obj01254 *)p)->f18,1,4);
        func_021D62B4((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        func_021D62BC((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),6,7);
        func_021D62BC((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,1);
        cb.f0=0; cb.f4=p; cb.f8=(void (*)(char *))func_021D7204;
        func_021D62D0((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,(int)&cb);
        func_021D6650((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        func_021D6458((struct Obj02181 *)(*(char * *)&((struct Obj01254 *)p)->f14),(void *)POKE_TOOL_Dummy(((struct Obj01254 *)p)->fC),0);
        func_021D652C(*(char * *)&((struct Obj01254 *)p)->f14);
        GFL_USE_PlaySeDefaultVolume(0x658);
        func_021D6EE0((u8 *)p,(int)func_021D7180,0x295);
    }
}
