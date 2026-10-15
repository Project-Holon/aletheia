/*
 * function: ZUKAN_SEARCH_PROC_Delete
 * address: 0x021BC280
 * packet: pkt_ov211_021BC280
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
struct Proc;extern void func_020315D4(struct Proc *);extern void GFL_HEAP_DeleteChecked(unsigned int);
int ZUKAN_SEARCH_PROC_Delete(struct Proc *p){func_020315D4(p);GFL_HEAP_DeleteChecked(126);return 1;}
