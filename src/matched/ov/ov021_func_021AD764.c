/*
 * function: func_021AD764
 * address: 0x021AD764
 * packet: pkt_ov021_021AD764
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
 *   func_021AD7B4 0x021AD7B4 thumb
 */

struct P_021AD3D4;
typedef unsigned int u32;
typedef struct P_021AD3D4 { u32 f0; } P_021AD3D4;
void *func_021AD764(u32 a, int heap);
P_021AD3D4 *func_021AD7B4(u32 a, int heap, u32 c);

void *func_021AD764(u32 a, int heap)
{
    return (void *)func_021AD7B4(a, heap, 1);
}
