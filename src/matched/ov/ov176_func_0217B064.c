/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_FadeOut
 * address: 0x0217B064
 * packet: pkt_ov176_0217B064
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_End 0x0217B00C thumb ov176
 *   func_02034714 0x02034714 arm
 *   d_0217E5E0 0x0217E5E0 data a1
 */
#include "../include/Obj24401.h"
#include "../include/Obj24402.h"
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void func_021E8AA0(int *p, int v);
extern void BATTLE_CHAMPIONSHIP_FLOW_End(void *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_0217E5E0[];
void BATTLE_CHAMPIONSHIP_FLOW_FadeOut(void *a,int *state,char *p)
{
    int mode;
    switch(*state){
    case 0:
        if(((struct Obj24402 *)(*(char * *)&((struct Obj24401 *)p)->f28))->f8==0){GFL_USE_FadeOutBgm(6);mode=12;}else mode=3;
        FADE_Start(mode,0,16,0);
        *state=1;
        break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: func_021E8AA0(a,(int)BATTLE_CHAMPIONSHIP_FLOW_End); break;
    default: func_02034714(d_0217E5E0,0,d_0217E5E0); break;
    }
}
