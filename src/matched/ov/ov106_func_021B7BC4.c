/*
 * function: IRC_RANKING_SeqScrollToLatest
 * address: 0x021B7BC4
 * packet: pkt_ov106_021B7BC4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: The signed-halfword result of 021B913C is already sign-extended by its body. ROUND follows the runtime-confirmed add/subtract mapping.
 * symbols:
 *   IRC_RANKING_ListFindLatestScrollPos 0x021B84D0 thumb ov106
 *   IRC_RANKING_ListGetScrollPos 0x021B84C4 thumb ov106
 *   IRC_RANKING_ListGetScrollMax 0x021B8518 thumb ov106
 *   IRC_RANKING_InertiaStart 0x021B900C thumb ov106
 *   IRC_RANKING_InertiaStop 0x021B9134 thumb ov106
 *   IRC_RANKING_SeqSetFunc 0x021B78D0 thumb ov106
 *   IRC_RANKING_SeqBrowse 0x021B7984 thumb ov106
 *   IRC_RANKING_InertiaIsActive 0x021B9198 thumb ov106
 *   IRC_RANKING_InertiaStep 0x021B913C thumb ov106
 *   IRC_RANKING_ListScrollBy 0x021B8408 thumb ov106
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   IRC_RANKING_SeqFadeOut 0x021B7948 thumb ov106
 *   IRC_RANKING_ListUpdate 0x021B838C thumb ov106
 *   IRC_RANKING_InertiaUpdate 0x021B8FD0 thumb ov106
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207C768 0x0207C768 arm
 */
#include "../include/Obj10253.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern int IRC_RANKING_ListFindLatestScrollPos(u8 *);
extern s16 IRC_RANKING_ListGetScrollPos(u8 *),IRC_RANKING_ListGetScrollMax(u8 *);
extern void IRC_RANKING_InertiaStart(u8 *,int,int),IRC_RANKING_InertiaStop(u8 *),IRC_RANKING_SeqSetFunc(u8 *,u32);
extern void IRC_RANKING_SeqBrowse(u8 *,u32,u8 *);
extern void IRC_RANKING_SeqFadeOut(u8 *a, int *s);
extern int IRC_RANKING_InertiaIsActive(int *p);
extern int IRC_APPBAR_GetResult(int *);
extern s16 IRC_RANKING_InertiaStep(u8 *);
extern u32 func_0207C768(u32 a, u32 b);
extern void IRC_RANKING_ListScrollBy(u8 *,s16);
extern void IRC_RANKING_ListUpdate(u8 *);
extern void IRC_RANKING_InertiaUpdate(u8 *);
extern void IRC_APPBAR_Update(int a);
#define ROUND(a) ((int)((a)>0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))
void IRC_RANKING_SeqScrollToLatest(u8 *a,u32 unused,u8 *p) {
    int target,current,last;
    target=(s16)(IRC_RANKING_ListFindLatestScrollPos(p+0x38)-192);
    if(target<0) target=0;
    current=IRC_RANKING_ListGetScrollPos(p+0x38);
    last=IRC_RANKING_ListGetScrollMax(p+0x38);
    if((s16)target>current && current!=last) {
        int n=++((struct Obj10253 *)p)->f640;
        if(ROUND(n)>81920)
            IRC_RANKING_InertiaStart(p+0x600,(int)(((long long)(int)func_0207C768((int)(ROUND(n)-81920),(int)163840)*245760+2048)>>12),12);
        else IRC_RANKING_InertiaStart(p+0x600,8192,12);
    } else {
        IRC_RANKING_InertiaStop(p+0x600);
        IRC_RANKING_SeqSetFunc(p+0x28,(u32)IRC_RANKING_SeqBrowse);
    }
    if(IRC_RANKING_InertiaIsActive((int *)(p+0x600))) IRC_RANKING_ListScrollBy(p+0x38,IRC_RANKING_InertiaStep(p+0x600));
    if(IRC_APPBAR_GetResult(*(int * *)&((struct Obj10253 *)p)->f614)==1)IRC_RANKING_SeqSetFunc(a,(u32)IRC_RANKING_SeqFadeOut);
    IRC_RANKING_ListUpdate(p+0x38);
    IRC_RANKING_InertiaUpdate(p+0x600);
    IRC_APPBAR_Update((u32)(*(u32 *)&((struct Obj10253 *)p)->f614));
}
