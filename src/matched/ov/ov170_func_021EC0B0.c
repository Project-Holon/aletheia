/*
 * function: func_021EC0B0
 * address:  0x021EC0B0
 * packet:   pkt_ov170_021EC0B0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 */

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space)
{
    short t[2];
    CLACT_GetActorSurfacePos((struct Actor *)*(int *)(p + i * 4 + 0x9E74), (struct PtS *)t, space);
    *a = t[0];
    *b = t[1];
}
