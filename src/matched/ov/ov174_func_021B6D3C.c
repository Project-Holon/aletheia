/*
 * unit: yes
 * function: LOCAL_TVT_CHARA_Update,LOCAL_TVT_CHARA_SetActive
 * address: 0x021B6D3C
 * packet: pkt_ov174_021B6D3C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: trailing store-and-return follower 021B6F24 included in this unit; 021B6F2A..021B6F2C is alignment padding.
 * symbols:
 *   LOCAL_TVT_CHARA_LoadPalette 0x021B7180 thumb ov174
 *   LOCAL_TVT_CHARA_CopyTiles 0x021B71A0 thumb ov174
 *   func_020307B0 0x020307B0 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_020056EC 0x020056EC thumb
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_GetActorAnimSeqCount 0x0204B918 arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 *   d_021B7485 0x021B7485 data a1
 *   d_021B7481 0x021B7481 data a1
 */
#include "../include/Obj00152.h"
#include "../include/Obj00185.h"
#include "../include/Obj24206.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void LOCAL_TVT_CHARA_LoadPalette(char *p, char *q, int id);
extern void LOCAL_TVT_CHARA_CopyTiles(int,int *,int,int,int);
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern unsigned func_020056EC(unsigned);
struct Actor;
extern void CLACT_StartActorAnim(struct Actor *a);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_StopActorAnim(struct Actor *a);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
struct Obj;
extern u16 CLACT_GetActorAnimSeqCount(struct Obj *p);
extern const u8 d_021B7485[],d_021B7481[];
void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q)
{
    unsigned size;
    unsigned pal;
    unsigned base;
    unsigned step;
    if(((struct Obj00152 *)p)->f8==2) size=0x6000; else size=0x3000;
    if(p[13]==0) pal=0;else pal=0xC000;
    if(((struct Obj00152 *)p)->f8==2) base=0;else base=0x1C00;
    switch(((struct Obj00185 *)q)->f8) {
    case 1:
        q[1]=0;
        LOCAL_TVT_CHARA_LoadPalette((char *)p,(char *)q,q[4]+d_021B7485[q[2]*3]);
        ((struct Obj00185 *)q)->f8=2;
        break;
    case 2:
        step=q[1]*0x3000u;
        LOCAL_TVT_CHARA_CopyTiles((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x10000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=3;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 3:
        q[1]=0;
        LOCAL_TVT_CHARA_LoadPalette((char *)p,(char *)q,(q[5]+d_021B7481[q[3]*2])+(((struct Obj00152 *)p)->f10*2));
        ((struct Obj00185 *)q)->f8=4;
        break;
    case 4:
        step=q[1]*0x3000u;
        LOCAL_TVT_CHARA_CopyTiles((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x28000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=5;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 0:
        break;
    }
    if(q[6]<40) q[6]++;
    else if(((struct Obj00185 *)q)->f8==5 || ((struct Obj00185 *)q)->f8==0) {
        q[6]=0;
        q[4]=q[4]==0?1:0;
        q[5]=q[5]==0?1:0;
    }
    if(((struct Obj00185 *)q)->f14==1 && PRINTSYS_QUE_IsFinished(((struct Obj00152 *)p)->f78)==1) {
        BMP_WIN_TransferChars(((struct Obj00185 *)q)->f18);
        ((struct Obj00185 *)q)->f14=0;
    }
    ((struct Obj00185 *)q)->f30+=(u16)(func_020056EC(2)+1);
    if(((struct Obj00185 *)q)->f30>=150) {
        CLACT_StartActorAnim(((struct Obj00185 *)q)->f28);
        CLACT_RestartActorAnim(((struct Obj00185 *)q)->f28);
        ((struct Obj00185 *)q)->f30=0;
    }
    if(((struct Obj00185 *)q)->f34==1 || ((struct Obj00185 *)q)->f38!=0) {
        if(CLACT_IsActorAnimActive(((struct Obj00185 *)q)->f2C)==0) CLACT_StartActorAnim(((struct Obj00185 *)q)->f2C);
    } else {
        if(CLACT_IsActorAnimActive(((struct Obj00185 *)q)->f2C)==1 && CLACT_GetActorAnimSeqCount(((struct Obj00185 *)q)->f2C)==0)
            CLACT_StopActorAnim(((struct Obj00185 *)q)->f2C);
    }
    if(((struct Obj00185 *)q)->f38!=0) (((struct Obj00185 *)q)->f38)--;
}
void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2)
{
    ((struct Obj24206 *)q)->f8=1;
}
