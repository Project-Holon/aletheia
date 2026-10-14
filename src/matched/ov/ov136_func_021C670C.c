/*
 * function: MB_SEQ_SetActorObjMode
 * address:  0x021C670C
 * packet:   pkt_ov136_021C670C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorObjMode  0x0204B688  arm
 */

typedef unsigned char u8;
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
void MB_SEQ_SetActorObjMode(u8 *p, int i, int on)
{
    if (on == 1) {
        CLACT_SetActorObjMode(*(void **)(p + i * 4 + 0x1F0), 1);
    } else {
        CLACT_SetActorObjMode(*(void **)(p + i * 4 + 0x1F0), 0);
    }
}
