/*
 * function: func_021F7108
 * address:  0x021F7108
 * packet:   pkt_ov097_021F7108
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 */

typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

void func_021F7108(char *p)
{
    unsigned i;

    for (i = 0; i < 9; i++)
        CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0xb4));
    for (i = 0; i < 4; i++)
        CLACT_ReleasePalette(*(int *)(p + i * 4 + 0xd8));
    for (i = 0; i < 4; i++)
        CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0xe8));
}
