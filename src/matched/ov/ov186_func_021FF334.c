/*
 * function: BR_SIDEBAR_UpdateSlide
 * address: 0x021FF334
 * packet: pkt_ov186_021FF334
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: 0x0204B5E4 ARM9 ARM, sole unresolved relocation in own MATCH 212; unit_0204B5D4.c defines CLACT_GetActorScaleAxis but omits it from function: header. Owner unit and shard require the integrator maintenance.
 * Verified blocker C: one --arm without region, fixed compiler/flags/lang, EXACT 16 (scratch b5e4.c and b5e4-verify.log).
 * typedef unsigned long u32;
 * typedef struct { char pad[0x14]; u32 a; u32 b; } Actor;
 * u32 CLACT_GetActorScaleAxis(const Actor *p,u32 which)
 * { if(which==0)return p->a; else return p->b; }
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorSurfacePosAxis 0x0204B4EC arm
 *   CLACT_GetActorScaleAxis 0x0204B5E4 arm
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   CLACT_SetActorScaleAxis 0x0204B5D4 arm
 *   BR_SIDEBAR_SetSlotMode 0x021FF038 thumb ov186
 * Width: space argument truncated by original caller to u16 despite callee u32.
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
typedef unsigned char  u8;
extern s16 CLACT_GetActorSurfacePosAxis(struct Actor *actor, u32 space, u32 axis);
extern u32 CLACT_GetActorScaleAxis(const struct Actor *actor, u32 which);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void CLACT_SetActorScaleAxis(struct Actor *actor, u32 value, u32 which);
extern void BR_SIDEBAR_SetSlotMode(u8 *p, u32 mode);
void BR_SIDEBAR_UpdateSlide(char *p)
{
    s16 x;
    u32 y;
    *(int *)(p+0x28)=(*(int *)(p+0x28)+1)%2;
    if(*(int *)(p+0x28)!=0)return;
    switch(*(int *)(p+0x1C)){
    case 0:
        CLACT_SetActorDrawEnable(*(void **)(p+4),1);
        *(int *)(p+0x24)=0;
        *(int *)(p+0x1C)=1;
        break;
    case 1:
        x=CLACT_GetActorSurfacePosAxis(*(void **)(p+4),(u16)(*(u32 *)(p+0x44)),0);
        y=CLACT_GetActorScaleAxis(*(void **)(p+4),0);
        if(*(int *)(p+0x24)==0){
            *(int *)(p+0x2C)=*(s16 *)(p+0x34)-x;
            *(int *)(p+0x2C)/=*(s16 *)(p+0x3A);
            (*(int *)(p+0x24))++;
            *(int *)(p+0x30)=*(s16 *)(p+0x38)-y;
            *(int *)(p+0x30)/=*(s16 *)(p+0x3A);
        }else if(*(int *)(p+0x24)==*(s16 *)(p+0x3A)+1){
            x=*(s16 *)(p+0x34);
            y=*(s16 *)(p+0x38);
            *(int *)(p+0x1C)=2;
        }else{
            x+=(s16)*(int *)(p+0x2C);
            y+=*(int *)(p+0x30);
            (*(int *)(p+0x24))++;
        }
        CLACT_SetActorSurfacePosAxis(*(void **)(p+4),x,(u16)(*(u32 *)(p+0x44)),0);
        CLACT_SetActorScaleAxis(*(void **)(p+4),y,0);
        break;
    case 2:BR_SIDEBAR_SetSlotMode((u8 *)p,0);break;
    }
}
