/*
 * function: BR_CODEIN_ProfileCreateActors2
 * address: 0x021E0A88
 * packet: pkt_ov183_021E0A88
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: 0204B294 r0 consumed after call; pointer request passed as the unchanged u32 fifth payload.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BR_CODEIN_ProfileSetActorPos 0x021E0D00 thumb ov183
 *   BR_CODEIN_ProfileAddActorSurfacePos 0x021E0D38 thumb ov183
 *   BR_CODEIN_ProfileSetActorVisible 0x021E0CE8 thumb ov183
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u16 a,b,c;u8 flag,pad;} Params;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Obj;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void BR_CODEIN_ProfileSetActorPos(char *,int);
struct Coordinates;
extern void BR_CODEIN_ProfileAddActorSurfacePos(struct Coordinates *p, int index);
extern void BR_CODEIN_ProfileSetActorVisible(char *,int,int);
void BR_CODEIN_ProfileCreateActors2(char *p)
{
    int base,zero;
    u32 owner;
    Params params;
    base=0x25c;owner=*(u32 *)(p+base);zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    *(u32 *)(p+base-0xc8)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    CLACT_SetActorObjMode(*(void **)(p+base-0xc8),1);
    *(u32 *)(p+base-0xac)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    CLACT_SetActorObjMode(*(void **)(p+base-0xac),1);
    *(u32 *)(p+base-0x90)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    CLACT_SetActorObjMode(*(void **)(p+base-0x90),1);
    BR_CODEIN_ProfileSetActorPos(p,0);
    CLACT_SetActorAnimSeq(*(void **)(p+base-0xc8),0);CLACT_SetActorAutoAnim(*(void **)(p+base-0xc8),1);
    *(u16 *)(p+base-0xa4)=zero;*(u16 *)(p+base-0xa2)=zero;*(u32 *)(p+base-0xb8)=1;
    BR_CODEIN_ProfileAddActorSurfacePos((struct Coordinates *)p,0);
    CLACT_SetActorAnimSeq(*(void **)(p+base-0xac),*(u32 *)(p+base-0xb8));
    CLACT_SetActorAutoAnim(*(void **)(p+base-0xac),1);CLACT_SetActorObjMode(*(void **)(p+base-0xac),1);
    *(u16 *)(p+base-0x88)=zero;*(u16 *)(p+base-0x86)=zero;*(u32 *)(p+base-0x9c)=1;
    BR_CODEIN_ProfileAddActorSurfacePos((struct Coordinates *)p,zero);
    CLACT_SetActorAnimSeq(*(void **)(p+base-0x90),*(u32 *)(p+base-0x9c));
    CLACT_SetActorObjMode(*(void **)(p+base-0x90),1);CLACT_SetActorAutoAnim(*(void **)(p+base-0x90),1);
    BR_CODEIN_ProfileSetActorVisible(p,1,zero);BR_CODEIN_ProfileSetActorVisible(p,2,zero);
}
