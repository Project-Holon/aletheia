/*
 * function: NAMEIN_SETUP_ExitHostProc
 * address: 0x0216C8B0
 * packet: pkt_ov010_0216C8B0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: zero alignment halfword at 0x0216C8CA, then labelled 0x0216C8CC.
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
struct S020314B8;
struct Proc;
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int);
int NAMEIN_SETUP_ExitHostProc(void *a, int b, int c, void **d) {
    func_0203133C(*d); func_020315D4(a); GFL_HEAP_DeleteChecked(0x76); return 1;
}
