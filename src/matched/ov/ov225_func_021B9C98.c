/*
 * function: func_021B9C98
 * address:  0x021B9C98
 * packet:   pkt_021B9C98
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker: byte-correct but capped at MATCH* (one unlabelled follower byte
 * pair makes the inferred extent run long).  The THM_CALL at +0xA to
 * func_0200ED48 (0x0200ED48) has no witness outside this range: no func_
 * label at the address and no branch to it from anywhere else in the image.
 * The other two sites are attested (GAME_DATA_GetSaveControl label x19, func_0200EDEC
 * matched).  A split cannot free the site: its only caller anywhere is this
 * function, so cutting elsewhere leaves it witnessless.  Blocked on label.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200EDEC  0x0200EDEC  thumb
 *
 * Addresses are Black-image addresses.
 */

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200ED48(void *p);
extern int func_0200EDEC(char *obj, int i);

int func_021B9C98(void *unused, int b, int c)
{
    return func_0200EDEC(func_0200ED48(GAME_DATA_GetSaveControl((struct Big *)c)), b);
}
