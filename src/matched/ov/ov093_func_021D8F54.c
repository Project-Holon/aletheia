/*
 * function: BTL_ABILITY_FlowerGiftRevertForm
 * address: 0x021D8F54
 * packet: pkt_ov093_021D8F54
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_ABILITY_IsCherrim 0x021D8E00 thumb ov093
 *   BTL_ABILITY_ChangeCherrimForm 0x021D8E7C thumb ov093
 */
extern int BTL_ABILITY_IsCherrim(void *, int);
extern void BTL_ABILITY_ChangeCherrimForm(int, void *, unsigned int, unsigned int, unsigned char);
void BTL_ABILITY_FlowerGiftRevertForm(int a, void *b, int c, int *d)
{
    if (*d && BTL_ABILITY_IsCherrim(b, c)) BTL_ABILITY_ChangeCherrimForm(a, b, c, 0, 0);
}
