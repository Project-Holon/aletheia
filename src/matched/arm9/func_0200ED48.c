/*
 * function: MET_TRAINERS_GetFromSave
 * address:  0x0200ED48
 * packet:   pkt_0200ED48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 *
 * symbols:
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *MET_TRAINERS_GetFromSave(void *p)
{
    return func_020071CC(p, 0x44);
}
