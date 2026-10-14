/*
 * function: MB_SEQ_CreateActors
 * address: 0x021C64A8
 * packet: pkt_ov136_021C64A8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: named q reloaded after the first tail call; explicit if/else
 *   keeps the zero arm first and joins the one arm with the initial path.
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   MB_SEQ_InitActorSystem 0x021C65A8 thumb ov136
 *   MB_SEQ_CreateActor 0x021C660C thumb ov136
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb ov136
 *   MB_SEQ_LoadActorArc 0x021C6738 thumb ov136
 *   MB_SEQ_RegisterSystemActorResources 0x021C675C thumb ov136
 *   MB_SEQ_RegisterMailActorResources 0x021C67D4 thumb ov136
 *   d_021C7BBC 0x021C7BBC data ov136 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C7BBC[];
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void MB_SEQ_LoadActorArc(u8 *);
extern void MB_SEQ_InitActorSystem(u8 *);
extern void MB_SEQ_RegisterMailActorResources(u8 *);
extern void MB_SEQ_RegisterSystemActorResources(u8 *);
extern void *MB_SEQ_CreateActor(u8 *, const u8 *);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void MB_SEQ_SetActorVisible(u8 *, int, u32);
typedef enum { ACTIVE = 1 } Active;
typedef enum { OFF = 0, ON = 1 } Enable;
static inline void activate(void *p)
{
    Active v = ACTIVE;
    CLACT_SetActorAutoAnim(p, v);
}
void MB_SEQ_CreateActors(u8 *p)
{
    u32 i;
    int k;
    u8 *q;
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    for (i = 0; i < 8; i++) {
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x210) = 0;
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x230) = 0;
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x250) = 0;
    }
    MB_SEQ_LoadActorArc(*(u8 **)(p + 8));
    MB_SEQ_InitActorSystem(*(u8 **)(p + 8));
    MB_SEQ_RegisterMailActorResources(*(u8 **)(p + 8));
    MB_SEQ_RegisterSystemActorResources(*(u8 **)(p + 8));
    for (i = 0; i < 8; i++) {
        *(void **)(*(u8 **)(p + 8) + i * 4 + 0x1F0) = MB_SEQ_CreateActor(*(u8 **)(p + 8), d_021C7BBC + i * 0x34);
        activate(*(void **)(*(u8 **)(p + 8) + i * 4 + 0x1F0));
    }
    q = *(u8 **)(p + 8);
    if (*(u16 *)(q + 0x2FC) <= 10) {
        MB_SEQ_SetActorVisible(q, 0, 0);
        q = *(u8 **)(p + 8);
        k = 1;
    } else {
        if (*(u16 *)(p + 0x1C) == 0) k = 0;
        else k = 1;
    }
    MB_SEQ_SetActorVisible(q, k, 0);
    MB_SEQ_SetActorVisible(*(u8 **)(p + 8), 4, 0);
    MB_SEQ_SetActorVisible(*(u8 **)(p + 8), 5, 0);
    MB_SEQ_SetActorVisible(*(u8 **)(p + 8), 6, 0);
}
