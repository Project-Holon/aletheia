/*
 * function: MISC_SAVEDATA_GetBlock44
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
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *MISC_SAVEDATA_GetBlock44(void *p)
{
    return func_020071CC(p, 0x44);
}
