/*
 * function: LIVEBATTLEMATCH_FLOW_SelectPhase, LIVEBATTLEMATCH_FLOW_End
 * unit: yes
 * address: 0x0217BB58
 * packet: pkt_ov176_0217BB58
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_Main 0x0217BBDC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Sub 0x0217CC78 thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Battle 0x0217C2EC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Card 0x0217CAE0 thumb ov176
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   func_02034714 0x02034714 arm
 *   d_0217E618 0x0217E618 data a4
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 */
#include "../include/Obj14363.h"
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
typedef signed int     s32;
typedef unsigned char  u8;
struct Reg2;
extern void LIVEBATTLEMATCH_FLOW_Main(int *sys, unsigned int *state, u8 *p);
extern void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p);
extern void LIVEBATTLEMATCH_FLOW_Battle(int *sys, unsigned int *state, u8 *p);
extern void LIVEBATTLEMATCH_FLOW_Card(int *sys, unsigned int *state, u8 *p);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, unsigned int id);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_0217E618[];
void LIVEBATTLEMATCH_FLOW_SelectPhase(int p,int *state,char *q)
{
    switch(((struct Obj14363 *)q)->f1A0) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Main); break;
    case 1:
        if(REGULATION_Card_GetValue((struct Reg2 *)(((struct Obj14363 *)q)->f38),10)==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Sub);
        else WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Battle);
        break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Card); break;
    case 3: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Sub); break;
    default: func_02034714(d_0217E618,0,d_0217E618); break;
    }
}
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
void LIVEBATTLEMATCH_FLOW_End(int p) {WIFIBATTLEMATCH_UTIL_ClearCallback(p);}
