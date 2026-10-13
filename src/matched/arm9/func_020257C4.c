/*
 * function: BMP_OAM_GetEnabled
 * address:  0x020257C4
 * packet:   pkt_020257C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: a bare tail call forwarding the
 * word at +4.
 *
 * symbols:
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

int BMP_OAM_GetEnabled(const int *p)
{
    return CLACT_GetActorDrawEnable((struct Obj *)p[1]);
}
