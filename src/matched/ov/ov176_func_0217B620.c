/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2
 * address: 0x0217B620
 * packet: pkt_ov176_0217B620
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0217D398 0x0217D398 thumb ov176
 *   func_0217D434 0x0217D434 thumb ov176
 *   func_0217D44C 0x0217D44C thumb ov176
 *   func_0217D410 0x0217D410 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuExtra 0x0217B6AC thumb ov176
 */
#include "../include/Obj02222.h"
typedef struct { int mode; int a,b,c,d,e,f,g; } Config;
extern void MI_CpuFill8(void *,int,int);
extern int func_0217D398(Config *,int);
extern void func_0217D434(int *p);
extern int func_0217D44C(int *p);
extern void func_0217D410(int *p);
extern void func_021E8AA0(int *p, int v);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(int p, unsigned *state, int *q);
void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, 32);
        config.mode = 1;
        config.a = ((struct Obj02222 *)q)->f18;
        config.b = ((struct Obj02222 *)q)->f1C;
        config.c = ((struct Obj02222 *)q)->f20;
        config.d = ((struct Obj02222 *)q)->f24;
        config.e = ((struct Obj02222 *)q)->f28;
        config.f = ((struct Obj02222 *)q)->f2C;
        config.g = ((struct Obj02222 *)q)->f30;
        ((struct Obj02222 *)q)->f38 = func_0217D398(&config, ((struct Obj02222 *)q)->f34);
        (*state)++;
        break;
    case 1:
        func_0217D434((int *)(((struct Obj02222 *)q)->f38));
        if (func_0217D44C((int *)(((struct Obj02222 *)q)->f38))) (*state)++;
        break;
    case 2:
        func_0217D410((int *)(((struct Obj02222 *)q)->f38));
        func_021E8AA0((int *)p, (int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);
        break;
    }
}
