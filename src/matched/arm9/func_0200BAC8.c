/*
 * function: BATTLE_BOX_GetFromSave
 * address:  0x0200BAC8
 * packet:   pkt_0200BAC8
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
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *BATTLE_BOX_GetFromSave(void *p)
{
    return func_020071CC(p, 0x31);
}
