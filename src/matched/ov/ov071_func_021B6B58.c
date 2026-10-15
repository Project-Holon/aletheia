/*
 * function: MONOLITH_TOOL_SetButtonVisible
 * address: 0x021B6B58
 * packet: pkt_ov071_021B6B58
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021B6B6E.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, u32);
extern void BMP_OAM_SetEnabled(u8 *, u32);
void MONOLITH_TOOL_SetButtonVisible(void **p, int v)
{
    CLACT_SetActorDrawEnable(p[0], v);
    BMP_OAM_SetEnabled(p[1], v);
}
