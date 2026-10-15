/*
 * function: MANUAL_COMMON_UpdateListWorkInput
 * address: 0x021BAABC
 * packet: pkt_ov225_021BAABC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: capture scrollbar helper result, store x then y; direct y-store
 * before x-store changes all four coordinate write blocks (28 bytes).
 * symbols:
 *   MANUAL_COMMON_BuildListRects 0x021BAFF8 thumb ov225
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   MANUAL_COMMON_GetVisibleCount 0x021BB05C thumb ov225
 *   MANUAL_COMMON_GetLastVisible 0x021BB044 thumb ov225
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   MANUAL_COMMON_GetCursorIndex 0x021BB034 thumb ov225
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   MANUAL_COMMON_GetScrollTop 0x021BB074 thumb ov225
 *   MANUAL_COMMON_RebuildListWindows 0x021BB088 thumb ov225
 *   MANUAL_COMMON_IndexToY 0x021BB258 thumb ov225
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj00074.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct State {u16 a,b,count,c;void *data;u16 top,selected;};
struct Obj;struct Vec2 {short x,y;};
extern void MANUAL_COMMON_BuildListRects(u8 *);
extern int TOUCHPANEL_HitTrg(const void *);
extern u16 MANUAL_COMMON_GetVisibleCount(u16 **),MANUAL_COMMON_GetLastVisible(u16 **),MANUAL_COMMON_GetCursorIndex(u16 **),MANUAL_COMMON_GetScrollTop(u16 **);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 KEY_GetTrg(void),KEY_GetRepeat(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void MANUAL_COMMON_RebuildListWindows(char *);
extern u16 MANUAL_COMMON_IndexToY(void *,u16,u16);
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,u32);
#define S (*(struct State **)p)
int MANUAL_COMMON_UpdateListWorkInput(char *p)
{
    u8 rect[28];
    struct Vec2 delta[4];
    int hit;
    u16 count,last,y;
    MANUAL_COMMON_BuildListRects(rect);
    hit=TOUCHPANEL_HitTrg(rect);
    count=MANUAL_COMMON_GetVisibleCount((u16 **)p);
    last=MANUAL_COMMON_GetLastVisible((u16 **)p);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<count) {
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&2)) {
            func_020355D8(0);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
            ((struct Obj00074 *)p)->f8C=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        }
        if(S->count>1) {
            if(KEY_GetRepeat()&0x40) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),0);
                if(S->selected>S->top) S->selected--;
                else if(S->count<=6) S->selected=S->count-1;
                else {
                    if(S->selected!=0) {
                        S->top--;
                        S->selected--;
                    } else {
                        S->top=MANUAL_COMMON_GetScrollTop((u16 **)p);
                        S->selected=S->count-1;
                    }
                    MANUAL_COMMON_RebuildListWindows(p);
                    y=MANUAL_COMMON_IndexToY(p,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)p)+1),S->top);
                    delta[3].x=240;
                    delta[3].y=y;
                    CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[3],1);
                }
                APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
                ((struct Obj00074 *)p)->f8C=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x80) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),0);
                if(S->selected<last) S->selected++;
                else if(S->count<=6) S->selected=0;
                else {
                    if(S->selected<S->count-1) {
                        S->top++;
                        S->selected++;
                    } else {S->top=0;S->selected=0;}
                    MANUAL_COMMON_RebuildListWindows(p);
                    y=MANUAL_COMMON_IndexToY(p,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)p)+1),S->top);
                    delta[2].x=240;
                    delta[2].y=y;
                    CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[2],1);
                }
                APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
                ((struct Obj00074 *)p)->f8C=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x220) {
                if(S->selected!=0) {
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),0);
                    if(S->count<=6) S->selected=0;
                    else {
                        if(S->top>=6) {S->top-=6;S->selected-=6;}
                        else {S->top=0;if(S->selected>=6) S->selected-=6;else S->selected=0;}
                        MANUAL_COMMON_RebuildListWindows(p);
                        y=MANUAL_COMMON_IndexToY(p,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)p)+1),S->top);
                        delta[1].x=240;
                        delta[1].y=y;
                        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[1],1);
                    }
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
                    ((struct Obj00074 *)p)->f8C=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            } else if(KEY_GetRepeat()&0x110) {
                if(S->selected<S->count-1) {
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),0);
                    if(S->count<=6) S->selected=S->count-1;
                    else {
                        S->top+=6;
                        if(S->top>MANUAL_COMMON_GetScrollTop((u16 **)p)) S->top=MANUAL_COMMON_GetScrollTop((u16 **)p);
                        S->selected+=6;
                        if(S->selected>=S->count) S->selected=S->count-1;
                        MANUAL_COMMON_RebuildListWindows(p);
                        y=MANUAL_COMMON_IndexToY(p,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)p)+1),S->top);
                        delta[0].x=240;
                        delta[0].y=y;
                        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[0],1);
                    }
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
                    ((struct Obj00074 *)p)->f8C=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            }
        }
    } else if(hit>=0 && hit<count) {
        S->selected=S->top+hit;
        APP_TASKMENU_WIN_SetActive(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
        ((struct Obj00074 *)p)->f8C=0;
        APP_TASKMENU_WIN_SetDecide(*(void **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc),1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}
