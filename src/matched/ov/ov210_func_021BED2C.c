/*
 * function: ZKNSEARCH_MAIN_InitActorSystem
 * address:  0x021BED2C
 * packet:   pkt_ov210_021BED2C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_InitClact 0x021BEE94 thumb ov210
 *   ZKNSEARCH_MAIN_RegisterActorRes 0x021BEEC4 thumb ov210
 *   ZKNSEARCH_MAIN_CreateActors 0x021BF0DC thumb ov210
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_InitClact(void);
struct Obj021BF0DC;
struct Res021BEEC4;
extern void ZKNSEARCH_MAIN_RegisterActorRes(struct Res021BEEC4 *p);
extern void ZKNSEARCH_MAIN_CreateActors(struct Obj021BF0DC *p);
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void ZKNSEARCH_MAIN_InitActorSystem(int p)
{
    ZKNSEARCH_MAIN_InitClact();
    ZKNSEARCH_MAIN_RegisterActorRes((struct Res021BEEC4 *)p);
    ZKNSEARCH_MAIN_CreateActors((struct Obj021BF0DC *)p);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
