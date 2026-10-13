/*
 * function: HAND_TOKUSEI_FlowerGiftRevertFormIfOwner
 * address: 0x021D8F1C
 * packet: pkt_ov093_021D8F1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_IsCherrim 0x021D8E00 thumb ov093
 *   HAND_TOKUSEI_ChangeCherrimForm 0x021D8E7C thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int HAND_TOKUSEI_IsCherrim(void *, int);
extern void HAND_TOKUSEI_ChangeCherrimForm(int, void *, unsigned int, unsigned int, unsigned char);
void HAND_TOKUSEI_FlowerGiftRevertFormIfOwner(int a, void *b, int c, int *d)
{
    if (*d && c == BTL_EVENT_GetVar(2) && HAND_TOKUSEI_IsCherrim(b, c))
        HAND_TOKUSEI_ChangeCherrimForm(a, b, c, 0, 0);
}
