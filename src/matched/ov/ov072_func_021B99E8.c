/*
 * function: TOWNMAP_StepBrowse
 * address: 0x021B99E8
 * packet: pkt_ov072_021B99E8
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Point objects scoped to their use-site blocks; inner out word declared before o1/o2.
 * note: Pool words prove the case-7 sounds are 0x648 and 0x649, correcting the old note.
 * symbols:
 *   TOWNMAP_BackButtonIsHeld 0x021BA040 thumb ov072
 *   TOWNMAP_IsScrollZooming 0x021BB0E0 thumb ov072
 *   TOWNMAP_CursorGetPos 0x021BA3BC thumb ov072
 *   TOWNMAP_CursorGetHeldKeys 0x021BA3EC thumb ov072
 *   TOWNMAP_GRH_GetTouchDrag 0x021BB6AC thumb ov072
 *   TOWNMAP_GRH_RestartTouchDrag 0x021BB6DC thumb ov072
 *   TOWNMAP_MapGetScroll 0x021BA69C thumb ov072
 *   TOWNMAP_MoveScroll 0x021BB19C thumb ov072
 *   TOWNMAP_MapAddScroll 0x021BA6A8 thumb ov072
 *   TOWNMAP_CursorMoveHoverSprite 0x021BA450 thumb ov072
 *   TOWNMAP_CursorGetHoverTown 0x021BA488 thumb ov072
 *   TOWNMAP_MapFindTownUnderCursor 0x021BA6C8 thumb ov072
 *   TOWNMAP_CursorIsPressed 0x021BA3E8 thumb ov072
 *   TOWNMAP_TownGetField 0x021BA774 thumb ov072
 *   TOWNMAP_ProcSetStep 0x021B995C thumb ov072
 *   TOWNMAP_DrawSelection 0x021BB220 thumb ov072
 *   TOWNMAP_MapHighlightTown 0x021BA7A4 thumb ov072
 *   TOWNMAP_CursorSetHoverTown 0x021BA3F4 thumb ov072
 *   TOWNMAP_GRH_SetLabelTown 0x021BB5AC thumb ov072
 *   TOWNMAP_ClearSelection 0x021BB3D0 thumb ov072
 *   TOWNMAP_GRH_SetLabelVisible 0x021BB5B4 thumb ov072
 *   TOWNMAP_MapClearHighlight 0x021BA7D4 thumb ov072
 *   TOWNMAP_CursorSetSnapToTown 0x021BA48C thumb ov072
 *   TOWNMAP_BackButtonUpdate 0x021B9F50 thumb ov072
 *   TOWNMAP_CursorUpdate 0x021BA0E4 thumb ov072
 *   TOWNMAP_MapUpdate 0x021BA5AC thumb ov072
 *   TOWNMAP_StepScrollZoom 0x021BAFA8 thumb ov072
 *   TOWNMAP_GRH_UpdateLabel 0x021BB548 thumb ov072
 *   TOWNMAP_GRH_UpdateTouch 0x021BB5EC thumb ov072
 *   TOWNMAP_BackButtonGetPressed 0x021BA028 thumb ov072
 *   TOWNMAP_StartScrollZoom 0x021BB0B4 thumb ov072
 *   TOWNMAP_GetScrollPosition 0x021BB190 thumb ov072
 *   TOWNMAP_IsScrollZoomDone 0x021BB0DC thumb ov072
 *   TOWNMAP_StepFadeOut 0x021B99AC thumb ov072
 *   func_020355C4 0x020355C4 arm
 *   d_021BBB78 0x021BBB78 data ov072 a4
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef long long s64;
typedef struct { int x,y; } Pos;
typedef struct { int x,y,z; } Vec;
extern const Pos d_021BBB78;
extern int TOWNMAP_BackButtonIsHeld(int *);
extern int TOWNMAP_IsScrollZooming(void *);
extern void TOWNMAP_CursorGetPos(char *,int *);
extern int TOWNMAP_CursorGetHeldKeys(char *);
extern int TOWNMAP_GRH_GetTouchDrag(u32 *,Vec *,u32 *);
extern void TOWNMAP_GRH_RestartTouchDrag(int *);
extern void TOWNMAP_MapGetScroll(char *,int *);
extern void TOWNMAP_MoveScroll(u32 *,const u32 *);
extern void TOWNMAP_MapAddScroll(char *,const int *);
extern void TOWNMAP_CursorMoveHoverSprite(int *,int *);
extern int TOWNMAP_CursorGetHoverTown(int *);
extern int TOWNMAP_MapFindTownUnderCursor(void *,void *);
extern int TOWNMAP_CursorIsPressed(int *);
extern int TOWNMAP_TownGetField(char *p, int i);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void TOWNMAP_ProcSetStep(int *,int);
struct Obj;
extern u8 func_020355C4(void);
extern void TOWNMAP_DrawSelection(u32 *,void *);
extern void TOWNMAP_MapHighlightTown(char *,void *);
extern void TOWNMAP_CursorSetHoverTown(int *p, int a, int *b);
extern void TOWNMAP_GRH_SetLabelTown(int *p, int x);
extern void TOWNMAP_ClearSelection(void **);
extern void TOWNMAP_GRH_SetLabelVisible(u32 *,u32);
extern void TOWNMAP_MapClearHighlight(char *);
extern void TOWNMAP_CursorSetSnapToTown(int *,int);
extern void TOWNMAP_BackButtonUpdate(u32 *p, void *q);
extern void TOWNMAP_CursorUpdate(void *,void *);
extern void TOWNMAP_MapUpdate(void *);
extern void TOWNMAP_StepScrollZoom(void *,void *);
extern void TOWNMAP_GRH_UpdateLabel(u32 *);
extern void TOWNMAP_GRH_UpdateTouch(struct Obj *p);
extern int TOWNMAP_BackButtonGetPressed(char *);
extern void TOWNMAP_StartScrollZoom(void *,int,const Pos *,const Pos *);
extern void TOWNMAP_GetScrollPosition(char *,int *);
extern int TOWNMAP_IsScrollZoomDone(void *);
extern void TOWNMAP_StepFadeOut(int *,int *);
#define W(k) (*(int *)(p+(k)))
#define R(k) ((void *)(p+(k)))
int TOWNMAP_StepBrowse(int *a,int unused,char *p)
{
    u8 moved;
    int w,mask,t;
    moved=0;
    if (TOWNMAP_BackButtonIsHeld((int *)R(0x14)) == 0) {
        if (W(0x138)!=0 && TOWNMAP_IsScrollZooming(R(0x78))==0) {
            Vec v;
            Pos pos,delta={0,0};
            u32 out;
            Pos o1,o2;
            TOWNMAP_CursorGetPos(R(0x38),&pos.x);
            mask=TOWNMAP_CursorGetHeldKeys(R(0x38));
            if (pos.y<16 && (mask&0x40)) { delta.y-=4; moved=1; }
            if (pos.y<=168 && pos.y>136 && (mask&0x80)) { delta.y+=4; moved=1; }
            if (pos.x<16 && (mask&0x20)) { delta.x-=4; moved=1; }
            if (pos.x>240 && (mask&0x10)) { delta.x+=4; moved=1; }
            if (TOWNMAP_IsScrollZooming(R(0x78))==0 && TOWNMAP_GRH_GetTouchDrag(R(0xf4),&v,&out)) {
                delta.x=-(int)(((s64)v.x*4096+2048)>>12)>>12;
                delta.y=-(int)(((s64)v.y*4096+2048)>>12)>>12;
                TOWNMAP_GRH_RestartTouchDrag(R(0xf4)); moved=1;
            }
            if (moved != 0) {
                TOWNMAP_MapGetScroll(R(0x50),&o1.x);
                TOWNMAP_MoveScroll(R(0x78),(const u32 *)&delta);
                delta.x*=-1; delta.y*=-1;
                TOWNMAP_MapAddScroll(R(0x50),&delta.x);
                TOWNMAP_MapGetScroll(R(0x50),&o2.x);
                TOWNMAP_CursorMoveHoverSprite(R(0x38),&o2.x);
            }
        }
        if (moved==0 && TOWNMAP_IsScrollZooming(R(0x78))==0) {
            if (*(int *)W(0x130)==0 || *(int *)W(0x130)==2) {
                w=TOWNMAP_CursorGetHoverTown(R(0x38));
                t=TOWNMAP_MapFindTownUnderCursor(R(0x50),R(0x38));
                if (w!=0 && w==t && TOWNMAP_CursorIsPressed(R(0x38))!=0 && TOWNMAP_TownGetField((char *)w,12)!=0) {
                    *(int *)(W(0x130)+4)=2;
                    *(unsigned short *)(W(0x130)+8)=TOWNMAP_TownGetField((char *)w,0);
                    *(int *)(W(0x130)+12)=TOWNMAP_TownGetField((char *)w,13);
                    *(int *)(W(0x130)+16)=TOWNMAP_TownGetField((char *)w,14);
                    GFL_USE_PlaySeDefaultVolume(0x54c); TOWNMAP_ProcSetStep(a,(int)TOWNMAP_StepFadeOut);
                }
            }
            if (func_020355C4()==0) t=1; else t=TOWNMAP_CursorIsPressed(R(0x38));
            if (t != 0) {
                w=TOWNMAP_MapFindTownUnderCursor(R(0x50),R(0x38));
                if (w!=W(0x134) && w!=0) {
                    Pos o3;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    TOWNMAP_DrawSelection(R(0xb0),(void *)w); TOWNMAP_MapHighlightTown(R(0x50),(void *)w);
                    W(0x134)=w; TOWNMAP_MapGetScroll(R(0x50),&o3.x);
                    TOWNMAP_CursorSetHoverTown(R(0x38),w,(int *)(&o3));
                    if (W(0x138)==0) TOWNMAP_GRH_SetLabelTown(R(0xd4),w);
                } else if (w==0 && W(0x134)!=0) {
                    TOWNMAP_ClearSelection(R(0xb0)); TOWNMAP_GRH_SetLabelVisible(R(0xd4),0); TOWNMAP_MapClearHighlight(R(0x50));
                    TOWNMAP_CursorSetHoverTown(R(0x38),0,0); W(0x134)=0;
                }
            }
        }
        if (W(0x138)!=0) TOWNMAP_GRH_SetLabelVisible(R(0xd4),0);
        TOWNMAP_CursorSetSnapToTown(R(0x38),moved ? 0 : 1);
    }
    TOWNMAP_BackButtonUpdate(R(0x14),R(0x78));
    if (TOWNMAP_IsScrollZooming(R(0x78))==0) TOWNMAP_CursorUpdate(R(0x38),R(0x50));
    TOWNMAP_MapUpdate(R(0x50)); TOWNMAP_StepScrollZoom(R(0x78),R(0x50));
    TOWNMAP_GRH_UpdateLabel(R(0xd4)); TOWNMAP_GRH_UpdateTouch(R(0xf4));
    switch (TOWNMAP_BackButtonGetPressed(R(0x14))) {
    case 0:
        *(int *)(W(0x130)+4)=1; TOWNMAP_ProcSetStep(a,(int)TOWNMAP_StepFadeOut); break;
    case 1:
        *(int *)(W(0x130)+4)=0; TOWNMAP_ProcSetStep(a,(int)TOWNMAP_StepFadeOut); break;
    case 7:
        if (W(0x138)==0 && TOWNMAP_IsScrollZooming(R(0x78))==0) {
            Pos o4;
            TOWNMAP_CursorGetPos(R(0x38),&o4.x);
            TOWNMAP_StartScrollZoom(R(0x78),8192,&d_021BBB78,&o4);
            GFL_USE_PlaySeDefaultVolume(0x648);
            if (W(0x134)!=0) {
                TOWNMAP_ClearSelection(R(0xb0)); TOWNMAP_GRH_SetLabelVisible(R(0xd4),0); TOWNMAP_MapClearHighlight(R(0x50));
                TOWNMAP_CursorSetHoverTown(R(0x38),0,0); W(0x134)=0;
            }
            W(0x138)=1;
        } else if (W(0x138)==1 && TOWNMAP_IsScrollZooming(R(0x78))==0) {
            Pos o5;
            TOWNMAP_GetScrollPosition(R(0x78),&o5.x); o5.x+=128; o5.y+=96;
            TOWNMAP_StartScrollZoom(R(0x78),4096,&o5,&d_021BBB78);
            GFL_USE_PlaySeDefaultVolume(0x649);
            if (W(0x134)!=0) {
                TOWNMAP_ClearSelection(R(0xb0)); TOWNMAP_GRH_SetLabelVisible(R(0xd4),0); TOWNMAP_MapClearHighlight(R(0x50));
                TOWNMAP_CursorSetHoverTown(R(0x38),0,0); W(0x134)=0;
            }
            W(0x138)=0;
        }
        break;
    }
    return TOWNMAP_IsScrollZoomDone(R(0x78));
}
