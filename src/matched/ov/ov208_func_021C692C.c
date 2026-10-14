/*
 * function: ZUKAN_DETAIL_FORM_UpdateArrowAnim
 * address:  0x021C692C
 * packet:   pkt_ov208_021C692C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ov208_func_021BDC48  0x021BDC48  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Actor;
struct Obj;
extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *obj, unsigned int on);
extern void ov208_func_021BDC48(void *scene, u32 on);

#define W(o) (*(u32 *)(p + (o)))
#define ST(i) (*(u32 *)(p + (i) * 0x28 + 0x614))
#define OBJ(i) (*(u32 *)(p + (i) * 0x28 + 0x618))
#define STB(i) (*(u32 *)(p + 0x614 + (i) * 0x28))
#define OBJB(i) (*(u32 *)(p + 0x618 + (i) * 0x28))
#define B8(i) (*(p + (i) * 0x28 + 0x608))

void ZUKAN_DETAIL_FORM_UpdateArrowAnim(u16 *heap, u8 *p, int key)
{
    void *scene;
    u32 other;

    scene = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    if (W(0x694) == 5)
        return;
    switch (STB(W(0x694))) {
    case 0:
        break;
    case 1:
        STB(W(0x694)) = 2;
        return;
    case 2:
        if (CLACT_IsActorAnimActive((struct Actor *)OBJ(W(0x694))) != 0)
            break;
        ST(W(0x694)) = 3;
        return;
    case 3:
        CLACT_SetActorAnimSeq((struct Obj *)OBJ(W(0x694)), B8(W(0x694)));
        ST(W(0x694)) = 0;
        other = 5;
        if (W(0x694) == 2)
            other = 3;
        else if (W(0x694) == 3)
            other = 2;
        if (other != 5 && ST(other) == 0) {
            CLACT_SetActorAutoAnim((struct Obj *)OBJB(other), 1);
            CLACT_SetActorAnimSeq((struct Obj *)OBJB(other), B8(other));
        }
        W(0x694) = 5;
        if (W(0x6b8) == 0 || W(0x6b8) == 4)
            ov208_func_021BDC48(scene, 1);
        break;
    }
}
