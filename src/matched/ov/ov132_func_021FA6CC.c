/*
 * function: STA_ACT_BUTTON_Update
 * address: 0x021FA6CC
 * packet: pkt_ov132_021FA6CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 fresh 9730/9768 show and 25EA4/23F60/B3DC/B9A0/B98C bodies confirm arities; 2 fresh A5B0/A64C/A7E0 no full twin; 3 u8/const-char pointer unchanged; 4 struct-field, chained-assignment and enum-zero idioms; 5 fresh directory/neighbours.
 * spelling: enum-typed one/zero locals retain separate constant webs; literals and enum-typed stores alone left six differing bytes. Prior permuter300 was not repeated.
 * symbols:
 *   table 0x021FDC20 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   STA_ACTING_RequestAction 0x021F9730 thumb ov132
 *   STA_ACTING_GetCurrentAction 0x021F9768 thumb ov132
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
#include "../include/Obj00914.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef enum { FLAG_ZERO, FLAG_ONE } Flag;
typedef struct {u8 bytes[12];} Key;
typedef struct {s16 x,y;} Pos;
extern const Key table;
extern int TOUCHPANEL_HitTrg(const void *);
struct Obj;
struct Actor;
struct Vec2;
extern void G2x_SetBlendBrightness_(unsigned long,int,int);
extern void STA_ACTING_RequestAction(char *p, int value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void UI_SetInputMode(u8);
extern int STA_ACTING_GetCurrentAction(char *p);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
void STA_ACT_BUTTON_Update(char *p)
{
    Key key;
    Pos pos;
    int hit;
    Flag one,zero;
    if(((struct Obj00914 *)p)->fC==1) {
        key=table;
        hit=TOUCHPANEL_HitTrg(&key);
        G2x_SetBlendBrightness_(0x04001050,16,0);
        if(hit!=-1 && *(u16 *)(p+0x48+hit*2)!=255 && *(int *)(p+0x40+hit*4)==0) {
            if(hit==0) STA_ACTING_RequestAction(((struct Obj00914 *)p)->f4,7);
            else STA_ACTING_RequestAction(((struct Obj00914 *)p)->f4,8);
            G2x_SetBlendBrightness_(0x04001050,16,-8);
            one=FLAG_ONE;
            zero=FLAG_ZERO;
            *(u32 *)(p+0x40+hit*4)=one;
            *(u32 *)&((struct Obj00914 *)p)->f10=one;
            *(u32 *)&((struct Obj00914 *)p)->fC=zero;
            ((struct Obj00914 *)p)->f14=hit;
            pos.x=hit==0?32:224;
            pos.y=128;
            CLACT_RestartActorAnim(((struct Obj00914 *)p)->f5C);
            CLACT_SetActorDrawEnable(((struct Obj00914 *)p)->f5C,1);
            CLACT_AddActorSurfacePos(((struct Obj00914 *)p)->f5C,(const struct Vec2 *)(&pos),1);
            UI_SetInputMode(1);
        }
    }
    if(((struct Obj00914 *)p)->f14!=2) {
        if(STA_ACTING_GetCurrentAction(((struct Obj00914 *)p)->f4)==0) {
            if(((struct Obj00914 *)p)->f10==0) {
                ((struct Obj00914 *)p)->fC=1;
                CLACT_SetActorDrawEnable(*(void **)(p+0x4c+((struct Obj00914 *)p)->f14*4),0);
                CLACT_SetActorDrawEnable(*(void **)(p+0x54+((struct Obj00914 *)p)->f14*4),0);
                ((struct Obj00914 *)p)->f14=2;
            }
        } else {
            if(((struct Obj00914 *)p)->f10==1) ((struct Obj00914 *)p)->f10=0;
        }
    }
    if(CLACT_GetActorDrawEnable(((struct Obj00914 *)p)->f5C)==1) {
        if(CLACT_IsActorAnimActive(((struct Obj00914 *)p)->f5C)==0) CLACT_SetActorDrawEnable(((struct Obj00914 *)p)->f5C,0);
    }
}
