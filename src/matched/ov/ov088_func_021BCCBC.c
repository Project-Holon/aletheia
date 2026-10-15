/*
 * function: STARTMENU_LogoScreenEnd
 * address:  0x021BCCBC
 * packet:   pkt_ov088_021BCCBC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */

struct Proc;
extern void func_020315D4(struct Proc *a);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);

int STARTMENU_LogoScreenEnd(int a0)
{
    func_020315D4((struct Proc *)a0);
    GFL_HEAP_DeleteChecked(0x16);
    return 1;
}
