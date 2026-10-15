/*
 * function: BR_POKESEARCH_Main
 * address: 0x021FFC9C
 * packet: pkt_ov186_021FFC9C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_POKESEARCH_PollGroupTouch 0x022000F0 thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_UTIL_GetListMenuField48 0x021FCDA8 thumb ov186
 *   BR_UTIL_IsEffectDone 0x021FD938 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_POKESEARCH_DestroyGroupWindows 0x021FFFCC thumb ov186
 *   func_02034714 0x02034714 arm
 *   BR_POKESEARCH_BuildSeenList 0x02200188 thumb ov186
 *   BR_POKESEARCH_CreateSpeciesList 0x021FFFF8 thumb ov186
 *   BR_POKESEARCH_DestroySpeciesList 0x022000D0 thumb ov186
 *   func_020307B0 0x020307B0 arm
 *   BR_POKESEARCH_CreateGroupWindows 0x021FFF28 thumb ov186
 *   BR_POKESEARCH_UpdatePrint 0x021FFE34 thumb ov186
 *   gBrPokeSearchAssertString 0x02200DAC data
 */
#include "../include/Obj00221.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
extern int BR_POKESEARCH_PollGroupTouch(char *);
typedef unsigned char  u8;
struct Work;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(char *,u32,const Pair *);
extern void BR_UTIL_MainListMenu(char *);
extern int BR_UTIL_GetListMenuField48(char *),BR_UTIL_IsEffectDone(char *),BR_FADE_GetResult(int *);
extern void BR_FADE_Start(int a, int b, int c, int d);
extern void BR_POKESEARCH_DestroyGroupWindows(u8 *p);
extern void BR_POKESEARCH_DestroySpeciesList(u8 *p);
extern void BR_POKESEARCH_CreateGroupWindows(struct Work *p);
extern void BR_POKESEARCH_CreateSpeciesList(char *);
extern u16 *BR_POKESEARCH_BuildSeenList(void *p, u32 index, const u16 *table, u32 *out, u16 heap);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern unsigned BR_POKESEARCH_UpdatePrint(char *p);
extern char gBrPokeSearchAssertString[];
int BR_POKESEARCH_Main(char *p)
{
    if (((struct Obj00221 *)p)->f6C) {
        switch (((struct Obj00221 *)p)->f0) {
        case 0: (((struct Obj00221 *)p)->f0)++; break;
        case 1: ((struct Obj00221 *)p)->f0=2; break;
        case 2: {
            int x,y,held;
            Pair pair;
            ((struct Obj00221 *)p)->fC=BR_POKESEARCH_PollGroupTouch(p);
            held=TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));
            if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj00221 *)p)->f2C),x,y)&held) {
                pair.x=x; pair.y=y;
                BR_UTIL_StartEffect(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=1;
            } else if (((struct Obj00221 *)p)->fC!=9) {
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=3;
            }
            break;
        }
        case 3: {
            int x,y,held;
            Pair pair;
            BR_UTIL_MainListMenu(*(char * *)&((struct Obj00221 *)p)->f68);
            ((struct Obj00221 *)p)->f10=BR_UTIL_GetListMenuField48(*(char * *)&((struct Obj00221 *)p)->f68);
            held=TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));
            if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj00221 *)p)->f2C),x,y)&held) {
                pair.x=x; pair.y=y;
                BR_UTIL_StartEffect(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=2;
            } else if (((struct Obj00221 *)p)->f10!=-1) {
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=2;
            }
            break;
        }
        case 4:
            if (BR_UTIL_IsEffectDone(*(char * *)&((struct Obj00221 *)p)->f78)) {
                BR_FADE_Start((int)(((struct Obj00221 *)p)->f30),2,2,1);
                (((struct Obj00221 *)p)->f0)++;
            }
            break;
        case 5:
            if (BR_FADE_GetResult(*(int * *)&((struct Obj00221 *)p)->f30)) (((struct Obj00221 *)p)->f0)++;
            break;
        case 6:
            if (((struct Obj00221 *)p)->f4==3) {
                BR_POKESEARCH_DestroyGroupWindows((u8 *)p);
                if (((struct Obj00221 *)p)->f88) func_02034714(gBrPokeSearchAssertString,0,gBrPokeSearchAssertString);
                *(u16 * *)&((struct Obj00221 *)p)->f88=BR_POKESEARCH_BuildSeenList(((struct Obj00221 *)p)->f7C,*(u32 *)&((struct Obj00221 *)p)->fC,*(u16 * *)&((struct Obj00221 *)p)->f80,(u32 *)(p+0x8c),((struct Obj00221 *)p)->f24);
                BR_POKESEARCH_CreateSpeciesList(p);
            } else {
                BR_POKESEARCH_DestroySpeciesList((u8 *)p);
                if (((struct Obj00221 *)p)->f88) {
                    func_020307B0(((struct Obj00221 *)p)->f88);
                    ((struct Obj00221 *)p)->f88=0;
                }
                BR_POKESEARCH_CreateGroupWindows((struct Work *)p);
            }
            BR_FADE_Start((int)(((struct Obj00221 *)p)->f30),2,2,0);
            (((struct Obj00221 *)p)->f0)++;
            break;
        case 7:
            if (BR_FADE_GetResult(*(int * *)&((struct Obj00221 *)p)->f30)) ((struct Obj00221 *)p)->f0=*(u32 *)&((struct Obj00221 *)p)->f4;
            break;
        case 8: (((struct Obj00221 *)p)->f0)++; break;
        case 9: (((struct Obj00221 *)p)->f0)++; break;
        case 10: ((struct Obj00221 *)p)->f20=1; break;
        }
    }
    return BR_POKESEARCH_UpdatePrint(p);
}
