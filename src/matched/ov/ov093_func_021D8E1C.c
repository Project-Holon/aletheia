/*
 * function: HAND_TOKUSEI_FlowerGiftUpdateForm
 * address: 0x021D8E1C
 * packet: pkt_ov093_021D8E1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_TOKUSEI_IsCherrim 0x021D8E00 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   HAND_TOKUSEI_ChangeCherrimForm 0x021D8E7C thumb ov093
 * The thunk's caller supplies r0 and consumes its forwarded return.
 */
extern int HAND_TOKUSEI_IsCherrim(void *, int);
typedef unsigned char  u8;
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern void HAND_TOKUSEI_ChangeCherrimForm(int, void *, unsigned int, unsigned int, unsigned char);
void HAND_TOKUSEI_FlowerGiftUpdateForm(int a, void *b, int c, int *d)
{
    if (HAND_TOKUSEI_IsCherrim(b, c)) {
        HAND_TOKUSEI_ChangeCherrimForm(a, b, c, (unsigned char)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b) == 1), 1);
        *d = 1;
    }
}
