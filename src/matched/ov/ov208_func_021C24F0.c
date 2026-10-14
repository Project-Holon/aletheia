/*
 * function: ZUKAN_DETAIL_AREA_SetIconsNormalMode
 * address:  0x021C24F0
 * packet:   pkt_ov208_021C24F0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   func_0207D63C  0x0207D63C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);

void ZUKAN_DETAIL_AREA_SetIconsNormalMode(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            CLACT_SetActorObjMode((struct Actor *)(((u32 *)(p + 0x5c))[i]), 0);
    }
    func_0207D63C((volatile void *)0x04001050, 8, 0x3f, 12, 4);
}
