/*
 * function: FLDEFF_ENCOUNT_CreateKind2
 * address: 0x021AD770
 * packet: pkt_ov021_021AD770
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/fldeff_namipoke.c and filed here.
 *
 * symbols:
 *   FLDEFF_ENCOUNT_Create 0x021AD7B4 thumb
 */

struct P_021AD3D4;
typedef unsigned int u32;
typedef struct P_021AD3D4 { u32 f0; } P_021AD3D4;
void *FLDEFF_ENCOUNT_CreateKind2(u32 a, int heap);
P_021AD3D4 *FLDEFF_ENCOUNT_Create(u32 a, int heap, u32 c);

void *FLDEFF_ENCOUNT_CreateKind2(u32 a, int heap)
{
    return (void *)FLDEFF_ENCOUNT_Create(a, heap, 2);
}
