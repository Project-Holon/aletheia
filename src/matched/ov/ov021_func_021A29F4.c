/*
 * function: WEATHER_TASK_FreeSpriteResources
 * address:  0x021A29F4
 * packet:   pkt_ov021_021A29F4
 * region:   ov021
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

typedef unsigned short u16;

typedef unsigned int   u32;
void CLACT_ReleaseCharacter(u32 i);
void CLACT_ReleasePalette(u32 i);
void CLACT_ReleaseCellAnim(u32 i);

void WEATHER_TASK_FreeSpriteResources(u16 *p, u32 a1, u32 a2, u32 a3)
{
    if (p[0] != 0) {
        CLACT_ReleaseCharacter(p[1]);
        CLACT_ReleasePalette(p[2]);
        CLACT_ReleaseCellAnim(p[3]);
        p[0] = 0;
    }
}
