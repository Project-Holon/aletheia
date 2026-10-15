/*
 * function: MB_SEQ_ProcExit
 * address:  0x021C54DC
 * packet:   pkt_ov136_021C54DC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_ProcExit 0x021C54DC thumb
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
typedef unsigned int u32;
struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void GFL_HEAP_DeleteChecked(u32 v);
int MB_SEQ_ProcExit(void *a, void *b, void *c, u32 *p)
{
    func_0203133C((struct S020314B8 *)p[12]);
    func_020315D4(a);
    func_0203084C(0x65);
    GFL_HEAP_DeleteChecked(0x65);
    return 1;
}
