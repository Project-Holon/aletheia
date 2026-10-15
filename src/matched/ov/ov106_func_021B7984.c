/*
 * function: IRC_RANKING_SeqBrowse
 * address: 0x021B7984
 * packet: pkt_ov106_021B7984
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Unsigned conversion and ROUND use runtime-proven add C95C/sub CB8C. 8FA8 stores word +28 then tail-calls 3630C; 8E90 reads five inputs, writes Pair/Vec/word outputs.
 * symbols:
 *   IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 *   IRC_RANKING_InputGetKeys 0x021B8FA8 thumb ov106
 *   IRC_RANKING_InertiaStart 0x021B900C thumb ov106
 *   IRC_RANKING_InputGetDrag 0x021B8E50 thumb ov106
 *   IRC_RANKING_ListScrollBy 0x021B8408 thumb ov106
 *   IRC_RANKING_InertiaStop 0x021B9134 thumb ov106
 *   IRC_RANKING_InputGetFlick 0x021B8E90 thumb ov106
 *   VEC_DotProduct 0x0207CA68 arm
 *   gIrcRankingFlickAxis 0x021B949C data a4
 *   IRC_RANKING_InertiaIsActive 0x021B9198 thumb ov106
 *   IRC_RANKING_InertiaStep 0x021B913C thumb ov106
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   IRC_RANKING_SeqSetFunc 0x021B78D0 thumb ov106
 *   IRC_RANKING_SeqFadeOut 0x021B7948 thumb ov106
 *   IRC_RANKING_ListUpdate 0x021B838C thumb ov106
 *   IRC_RANKING_InputUpdate 0x021B8DA8 thumb ov106
 *   IRC_RANKING_InertiaUpdate 0x021B8FD0 thumb ov106
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207C768 0x0207C768 arm
 */
#include "../include/Obj10252.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
typedef struct { int x,y,z; } Vec;
extern const Vec gIrcRankingFlickAxis;
extern int IRC_APPBAR_IsBusy(int),IRC_APPBAR_GetResult(int *);
extern void *IRC_RANKING_InputGetKeys(u8 *p, int *out);
extern int IRC_RANKING_InputGetDrag(u8 *,Pair *,Pair *,Pair *),IRC_RANKING_InputGetFlick(u8 *,Pair *,Pair *,Vec *,int *);
extern int VEC_DotProduct(const Vec *,const Vec *),func_0207C768(int,int);
extern void IRC_RANKING_InertiaStart(u8 *,int,int),IRC_RANKING_ListScrollBy(u8 *,s16),IRC_RANKING_InertiaStop(u8 *);
extern int IRC_RANKING_InertiaIsActive(int *p);
extern s16 IRC_RANKING_InertiaStep(u8 *);
extern void IRC_RANKING_SeqSetFunc(u8 *,u32);
extern void IRC_RANKING_SeqFadeOut(u8 *a, int *s);
extern void IRC_RANKING_ListUpdate(u8 *);
extern void IRC_RANKING_InputUpdate(int *);
extern void IRC_RANKING_InertiaUpdate(u8 *);
extern void IRC_APPBAR_Update(int a);
#define ROUND(a) ((int)((a)!=0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))
#define SCALE(a) ((int)(((long long)func_0207C768(ROUND(a)-81920,163840)*245760+2048)>>12))
void IRC_RANKING_SeqBrowse(u8 *a,u32 unused,u8 *p) {
    u32 value;
    Pair pair;
    Vec vec;
    int duration;
    if(!IRC_APPBAR_IsBusy(*(int *)&((struct Obj10252 *)p)->f614)) {
        if(((u32)IRC_RANKING_InputGetKeys(p+0x5d4,(int *)(&value)))&128) {
            if(ROUND(value)>81920)IRC_RANKING_InertiaStart(p+0x600,SCALE(value),12);
            else IRC_RANKING_InertiaStart(p+0x600,8192,12);
        } else if(((u32)IRC_RANKING_InputGetKeys(p+0x5d4,(int *)(&value)))&64) {
            if(ROUND(value)>81920)IRC_RANKING_InertiaStart(p+0x600,-SCALE(value),12);
            else IRC_RANKING_InertiaStart(p+0x600,-8192,12);
        } else if(IRC_RANKING_InputGetDrag(p+0x5d4,0,0,&pair)) {
            IRC_RANKING_ListScrollBy(p+0x38,-pair.y);
            IRC_RANKING_InertiaStop(p+0x600);
        } else if(IRC_RANKING_InputGetFlick(p+0x5d4,0,0,&vec,&duration))
            IRC_RANKING_InertiaStart(p+0x600,VEC_DotProduct(&gIrcRankingFlickAxis,&vec),duration);
    }
    if(IRC_RANKING_InertiaIsActive((int *)(p+0x600)))IRC_RANKING_ListScrollBy(p+0x38,IRC_RANKING_InertiaStep(p+0x600));
    if(IRC_APPBAR_GetResult(*(int * *)&((struct Obj10252 *)p)->f614)==1)IRC_RANKING_SeqSetFunc(a,(u32)IRC_RANKING_SeqFadeOut);
    IRC_RANKING_ListUpdate(p+0x38);
    IRC_RANKING_InputUpdate((int *)(p+0x5d4));
    IRC_RANKING_InertiaUpdate(p+0x600);
    IRC_APPBAR_Update(*(u32 *)&((struct Obj10252 *)p)->f614);
}
