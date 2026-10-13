/*
 * function: ov208_func_021C24A4
 * address:  0x021C24A4
 * packet:   pkt_ov208_021C24A4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorObjMode  0x0204B688  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

void ov208_func_021C24A4(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 1);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
    }
}
