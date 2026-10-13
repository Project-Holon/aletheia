/*
 * function: func_021BED68
 * address:  0x021BED68
 * packet:   pkt_ov210_021BED68
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorAutoAnim(struct Obj *p);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void CLACT_DrawSystem(void);

void func_021BED68(int p)
{
    unsigned i;

    for (i = 0; i < 0x39; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0xa] != 0 && CLACT_GetActorAutoAnim((struct Obj *)q[0xa]) != 1)
            CLACT_AddActorAnimFrame((struct Obj *)q[0xa], 0x1000);
    }
    CLACT_DrawSystem();
}
