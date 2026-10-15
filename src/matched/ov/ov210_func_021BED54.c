/*
 * function: ZKNSEARCH_MAIN_DeleteActorSystem
 * address:  0x021BED54
 * packet:   pkt_ov210_021BED54
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_DeleteActors 0x021BF370 thumb ov210
 *   ZKNSEARCH_MAIN_ReleaseActorRes 0x021BF080 thumb ov210
 *   CLACT_ExitSystem 0x0204A5AC arm
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_DeleteActors(int p);
typedef unsigned char  u8;
extern void ZKNSEARCH_MAIN_ReleaseActorRes(u8 *p);
extern void CLACT_ExitSystem(void);

void ZKNSEARCH_MAIN_DeleteActorSystem(int p)
{
    ZKNSEARCH_MAIN_DeleteActors(p);
    ZKNSEARCH_MAIN_ReleaseActorRes((u8 *)p);
    CLACT_ExitSystem();
}
