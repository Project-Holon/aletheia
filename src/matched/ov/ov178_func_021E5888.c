/*
 * function: PARTY_STATUS_DestroySub
 * address:  0x021E5888
 * packet:   pkt_021E5888
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PARTY_STATUS_DestroySubWork  0x021E5A44  thumb  ov178
 *   PARTY_STATUS_ExitSubWork  0x021E5B1C  thumb  ov178
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */
typedef unsigned int u32;

extern void PARTY_STATUS_DestroySubWork(void **pp, u32 *c);
extern void PARTY_STATUS_ExitSubWork(int *p, void *c);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(u32 v);

int PARTY_STATUS_DestroySub(void *a, u32 b, u32 *c, void *d)
{
    switch (c[1]) {
    case 0:
        PARTY_STATUS_DestroySubWork(d, c);
        break;
    case 1:
        PARTY_STATUS_ExitSubWork(d, c);
        break;
    }
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x58);
    return 1;
}
