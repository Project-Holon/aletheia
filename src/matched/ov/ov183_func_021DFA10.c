/*
 * function: BR_CODEIN_CodeMain
 * address: 0x021DFA10
 * packet: pkt_ov183_021DFA10
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   d_021E37A8 0x021E37A8 data a4
 */
#include "../include/Obj05476.h"
typedef unsigned int u32;
typedef int (*Method)(char *,int *);
struct Methods { Method init,update,finish; };
extern const struct Methods d_021E37A8[];
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
typedef unsigned char  u8;
struct PrintSys;
extern int BR_UTIL_FlushText(u8 *p);
extern void BR_UTIL_FlushWindow(void *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BR_UTIL_RunHandles(char *);
int BR_CODEIN_CodeMain(void *unused,u32 *state,int *q,char *p)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 1: BR_FADE_Start(q[0],2,3,0); ++*state; break;
    case 2: if(BR_FADE_GetResult((int *)q[0])) *state=3; break;
    case 3: if(d_021E37A8[*(int *)(p+0x4c)].update(p,q)) {
        if(((struct Obj05476 *)p)->f50==-1) *state=10; else *state=4;
    } break;
    case 4: BR_FADE_Start(q[0],2,2,1); ++*state; break;
    case 5: if(BR_FADE_GetResult((int *)q[0])) ++*state; break;
    case 6: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) {
        ((struct Obj05476 *)p)->f4C=((struct Obj05476 *)p)->f50; ++*state;
    } break;
    case 7: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 8: BR_FADE_Start(q[0],2,2,0); ++*state; break;
    case 9: if(BR_FADE_GetResult((int *)q[0])) *state=3; break;
    case 10: BR_FADE_Start(q[0],2,3,1); ++*state; break;
    case 11: if(BR_FADE_GetResult((int *)q[0])) *state=12; break;
    case 12: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) return 1; break;
    }
    for(i=0;i<3;i++) if(*(void **)(p+i*4)) BR_UTIL_FlushText(*(void **)(p+i*4));
    for(i=0;i<6;i++) if(*(void **)(p+0x20+i*4)) BR_UTIL_FlushText(*(void **)(p+0x20+i*4));
    if(((struct Obj05476 *)p)->f38) BR_UTIL_FlushWindow(((struct Obj05476 *)p)->f38);
    PRINTSYS_QUE_Main(((struct Obj05476 *)p)->f48);
    for(i=0;i<2;i++) BR_UTIL_RunHandles(*(char **)(p+0x3c+i*4));
    return 0;
}
