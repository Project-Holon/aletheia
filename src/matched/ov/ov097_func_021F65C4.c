/*
 * function: VS_MULTI_LIST_ProcExit
 * address: 0x021F65C4
 * packet: pkt_ov097_021F65C4
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int VS_MULTI_LIST_ProcExit(void *p) { func_020315D4(p); GFL_HEAP_DeleteChecked(0x71); return 1; }
