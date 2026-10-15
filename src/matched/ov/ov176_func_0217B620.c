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
 *   DIGITALCARDCHECK_Create 0x0217D398 thumb ov176
 *   DIGITALCARDCHECK_DeleteAlt 0x0217D434 thumb ov176
 *   DIGITALCARDCHECK_GetProcResult 0x0217D44C thumb ov176
 *   DIGITALCARDCHECK_Delete 0x0217D410 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuExtra 0x0217B6AC thumb ov176
 */
#include "../include/Obj02222.h"
typedef struct { int mode; int a,b,c,d,e,f,g; } Config;
extern void MI_CpuFill8(void *,int,int);
extern int DIGITALCARDCHECK_Create(Config *,int);
extern void DIGITALCARDCHECK_DeleteAlt(int *p);
extern int DIGITALCARDCHECK_GetProcResult(int *p);
extern void DIGITALCARDCHECK_Delete(int *p);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
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
        ((struct Obj02222 *)q)->f38 = DIGITALCARDCHECK_Create(&config, ((struct Obj02222 *)q)->f34);
        (*state)++;
        break;
    case 1:
        DIGITALCARDCHECK_DeleteAlt((int *)(((struct Obj02222 *)q)->f38));
        if (DIGITALCARDCHECK_GetProcResult((int *)(((struct Obj02222 *)q)->f38))) (*state)++;
        break;
    case 2:
        DIGITALCARDCHECK_Delete((int *)(((struct Obj02222 *)q)->f38));
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)p, (int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);
        break;
    }
}
