/*
 * function: MONOLITH_TOOL_VBlankTask
 * address: 0x021B699C
 * packet: pkt_ov071_021B699C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
struct S02021D50;
extern void CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(struct S02021D50 *);
void MONOLITH_TOOL_VBlankTask(void *unused, struct S02021D50 **p)
{
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(*p);
}
