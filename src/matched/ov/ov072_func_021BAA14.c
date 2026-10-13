/*
 * function: TOWNMAP_TownFree
 * address: 0x021BAA14
 * packet: pkt_ov072_021BAA14
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void MI_CpuFill8(void *p, int v, int n);
void TOWNMAP_TownFree(unsigned int *p) { if (*p) CLACT_DeleteActor((struct Obj *)(*p)); MI_CpuFill8(p,0,0x44); }
