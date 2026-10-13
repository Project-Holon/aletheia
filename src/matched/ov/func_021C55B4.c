/*
 * function: DWCi_SceneSetApList_procScene
 * address:  0x021C55B4
 * packet:   pkt_021C55B4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetApList_procScene   0x021C55B4  arm
 *
 * Call func_021C55C8, func_021C57E4, func_021C5A10.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetApList_procScene.c \
 *       --func DWCi_SceneSetApList_procScene --addr 0x021C55B4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C55C8(void);
extern void func_021C57E4(void);
extern void func_021C5A10(void);

void DWCi_SceneSetApList_procScene(void)
{
    func_021C55C8();
    func_021C57E4();
    func_021C5A10();
}
