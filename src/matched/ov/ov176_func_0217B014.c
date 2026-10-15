/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_FadeIn
 * address: 0x0217B014
 * packet: pkt_ov176_0217B014
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_SelectFlow 0x0217AFD0 thumb ov176
 *   func_02034714 0x02034714 arm
 *   d_0217E5E0 0x0217E5E0 data a1
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void BATTLE_CHAMPIONSHIP_FLOW_SelectFlow(void *,int,char *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_0217E5E0[];
void BATTLE_CHAMPIONSHIP_FLOW_FadeIn(void *a,int *state,char *p)
{
    switch(*state){
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(a,(int)BATTLE_CHAMPIONSHIP_FLOW_SelectFlow); break;
    default: func_02034714(d_0217E5E0,0,d_0217E5E0); break;
    }
}
