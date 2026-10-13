/*
 * function: BTL_ABILITY_FlowerGiftUpdateForm
 * address: 0x021D8E1C
 * packet: pkt_ov093_021D8E1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ABILITY_IsCherrim 0x021D8E00 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   BTL_ABILITY_ChangeCherrimForm 0x021D8E7C thumb ov093
 * The thunk's caller supplies r0 and consumes its forwarded return.
 */
extern int BTL_ABILITY_IsCherrim(void *, int);
typedef unsigned char  u8;
extern int func_021C8288(u8 *p);
extern void BTL_ABILITY_ChangeCherrimForm(int, void *, unsigned int, unsigned int, unsigned char);
void BTL_ABILITY_FlowerGiftUpdateForm(int a, void *b, int c, int *d)
{
    if (BTL_ABILITY_IsCherrim(b, c)) {
        BTL_ABILITY_ChangeCherrimForm(a, b, c, (unsigned char)(func_021C8288(b) == 1), 1);
        *d = 1;
    }
}
