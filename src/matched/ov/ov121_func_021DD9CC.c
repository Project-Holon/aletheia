/*
 * function: MYSTERY_ALBUM_StepIntro
 * address: 0x021DD9CC
 * packet: pkt_ov121_021DD9CC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * verdict: 612-byte lead; the rest of the 652-byte extent is the two ARM
 *   followers 021DDC30 and 021DDC44 (20 bytes each), filed as their own
 *   ARM leaves (pkt_ov121_021DDC30, pkt_ov121_021DDC44, W82 R11), which
 *   also resolve the ABS32 blend callbacks at +0x258/+0x25C.
 * lever: case 5 seeds the result flag with its own constant and ANDs the
 *   call in (done = 1; done &= f(...)); "f(...) & 1" or "1 & f(...)" CSEs
 *   the 1 with ok's r6 (11 bytes).
 * symbols:
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   MYSTERY_UTIL_BlendPaletteRange 0x021DAB50 thumb ov121
 *   PM_VOICE_Play 0x02006984 thumb
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_GetActorRotation 0x0204B5FC arm
 *   MYSTERY_ALBUM_PathAnimInit 0x021DE128 thumb ov121
 *   MYSTERY_ALBUM_PathAnimStep 0x021DE154 thumb ov121
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PM_VOICE_IsActive 0x02006BD0 thumb
 *   MYSTERY_ALBUM_SetBlendMain 0x021DDC30 arm ov121
 *   MYSTERY_ALBUM_SetBlendSub 0x021DDC44 arm ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x,y; } Point;
typedef struct { s16 kind,x,y; } Output;
extern void CLACT_SetActorBgPriority(void *,u8);
extern void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Actor;
extern u16 CLACT_GetActorRotation(const struct Actor *actor);
extern void MYSTERY_ALBUM_PathAnimInit(u8 *p, u16 b, int c, int d);
extern int MYSTERY_ALBUM_PathAnimStep(void *,void *,void *);
extern void CLACT_AddActorSurfacePos(void *,const Point *,u16);
extern u32 PM_VOICE_IsActive(u32 i);
extern void MYSTERY_ALBUM_SetBlendMain(int,int);
extern void MYSTERY_ALBUM_SetBlendSub(int,int);
void MYSTERY_ALBUM_StepIntro(char *p)
{
    char *q=*(char **)(p+0x11c);
    int layer,a,b,done,ok;
    u16 tick;
    void (*blend)(int,int);
    Point pos;
    int xy[2];
    Output pt;
    if(*(int *)(q+0x84)) { layer=14; blend=MYSTERY_ALBUM_SetBlendMain; }
    else { blend=MYSTERY_ALBUM_SetBlendSub; layer=30; }
    switch(*(u16 *)(p+0xdc)) {
    case 1:
        CLACT_SetActorBgPriority(*(void **)(q+0x20),*(u32 *)(q+0x90));
        *(u16 *)(p+0xdc)=2;
        break;
    case 2:
        MYSTERY_UTIL_BlendPaletteRange((void *)layer,(u16 *)(q+0x24),(*(u16 *)(p+0xde)*0x7fff)/60,(u8)(*(u32 *)(q+0x88)),(const u16 *)(q+0x64),(const u16 *)(q+0x44));
        tick=*(u16 *)(p+0xde);
        a=tick*14/60;
        b=tick*-12/60;
        blend(a+2,b+12);
        if((*(u16 *)(p+0xde))++>60) {
            *(u16 *)(p+0xde)=0;
            *(u16 *)(p+0xdc)=3;
        }
        break;
    case 3: *(u16 *)(p+0xdc)=4; break;
    case 4:
        if(!*(int *)(p+0xe0))
            *(u32 *)(p+0xe8)=PM_VOICE_Play(*(u16 *)(p+0xe4),*(u16 *)(p+0xe6),64,0,0,0,0,0);
        CLACT_GetActorSurfacePos(*(void **)(q+0x20),(struct PtS *)(&pos),*(u32 *)(q+0x98));
        MYSTERY_ALBUM_PathAnimInit((u8 *)(p+0xec),CLACT_GetActorRotation(*(void **)(q+0x20)),pos.x,pos.y);
        *(u16 *)(p+0xdc)=5;
        break;
    case 5:
        ok=1;
        done=1;
        done&=MYSTERY_ALBUM_PathAnimStep(p+0xec,&pt,xy);
        pt.x=xy[0];
        pt.y=xy[1];
        CLACT_AddActorSurfacePos(*(void **)(q+0x20),(Point *)&pt.x,*(u32 *)(q+0x98));
        if(!*(int *)(p+0xe0)) {
            if(PM_VOICE_IsActive(*(u32 *)(p+0xe8))) ok=0;
            done &= ok;
        }
        if(done) *(u16 *)(p+0xdc)=6;
        break;
    case 6:
        MYSTERY_UTIL_BlendPaletteRange((void *)layer,(u16 *)(q+0x24),0x7fff-(*(u16 *)(p+0xde)*0x7fff)/60,(u8)(*(u32 *)(q+0x88)),(const u16 *)(q+0x64),(const u16 *)(q+0x44));
        tick=*(u16 *)(p+0xde);
        a=tick*-14/60;
        b=tick*12/60;
        blend(a+16,b);
        if((*(u16 *)(p+0xde))++>60) {
            *(u16 *)(p+0xde)=0;
            *(u16 *)(p+0xdc)=7;
        }
        break;
    case 7: *(u16 *)(p+0xdc)=8; break;
    case 8:
        CLACT_SetActorBgPriority(*(void **)(q+0x20),*(u32 *)(q+0x8c));
        *(u16 *)(p+0xdc)=0;
        break;
    }
}
