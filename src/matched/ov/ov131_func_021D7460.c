/*
 * function: P_STA_SUB_UpdateTouch
 * address: 0x021D7460
 * packet: pkt_ov131_021D7460
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-02 (lane R4): the loop stores 0 (the copy of r4 before the loop is the
 *   zero already in r4), not the counter; the three post-loop stores are 0 too.
 * symbols:
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   P_STA_SUB_ResetStroke 0x021D77E8 thumb ov131
 *   P_STA_SUB_TrackStrokes 0x021D75A4 thumb ov131
 *   d_021DC1E0 0x021DC1E0 data a1
 */
#include "../include/Obj00200.h"
#include "../include/Obj23140.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u8 b[12];} Rects;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int TOUCHPANEL_HitCont(const void *);
extern void P_STA_SUB_ResetStroke(u8 *p, u32 a, u32 b);
extern void P_STA_SUB_TrackStrokes(int a, u8 *p);
extern const Rects d_021DC1E0;
void P_STA_SUB_UpdateTouch(u8 *a,u8 *p) {
    Rects r=d_021DC1E0;
    u32 x,y;
    int t,g,k;
    u8 i;
    TOUCHPANEL_GetPointCont(&x,&y);
    if(((struct Obj23140 *)a)->f38!=0) return;
    t=func_02035C60();
    g=func_02035C38();
    k=TOUCHPANEL_HitCont(&r);
    if(((struct Obj00200 *)p)->f8==0) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) {
                ((struct Obj00200 *)p)->f6C=1;
                ((struct Obj00200 *)p)->f58=0;
                P_STA_SUB_ResetStroke(p+0x78,x,y);
                P_STA_SUB_ResetStroke(p+0x80,x,y);
                P_STA_SUB_ResetStroke(p+0x88,x,y);
                for(i=0;i<5;i++) p[0x94+i]=0;
                p[0x99]=0;
                p[0x9a]=0;
                ((struct Obj00200 *)p)->f90=0;
            } else if(g==1 && ((struct Obj00200 *)p)->f6C==1) {
                P_STA_SUB_TrackStrokes((int)a,p);
            }
            ((struct Obj00200 *)p)->f70=x;
            ((struct Obj00200 *)p)->f74=y;
        } else {
            if(((struct Obj00200 *)p)->f6C==1 && ((struct Obj00200 *)p)->f58==0 && ((struct Obj00200 *)p)->f5C==0) {
                ((struct Obj00200 *)p)->f8=1;
                p[0x9b]=0;
            }
            P_STA_SUB_ResetStroke(p+0x78,x,y);
            P_STA_SUB_ResetStroke(p+0x80,x,y);
            P_STA_SUB_ResetStroke(p+0x88,x,y);
            ((struct Obj00200 *)p)->f6C=0;
        }
    } else if(((struct Obj00200 *)p)->f8==2) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) ((struct Obj00200 *)p)->f6C=1;
        } else if(((struct Obj00200 *)p)->f6C==1) {
            ((struct Obj00200 *)p)->f6C=0;
            ((struct Obj00200 *)p)->f8=3;
            p[0x9b]=0;
        }
    }
}
