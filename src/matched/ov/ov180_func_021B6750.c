/*
 * function: HALL_OF_FAME_InitParticleHeap
 * address: 0x021B6750
 * packet: pkt_ov180_021B6750
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DOUBLE3DDISP_Init 0x0204E8C0 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void DOUBLE3DDISP_Init(u32 heap);
void HALL_OF_FAME_InitParticleHeap(void) {DOUBLE3DDISP_Init(141);}
