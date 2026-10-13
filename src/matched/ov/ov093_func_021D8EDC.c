/*
 * function: HAND_TOKUSEI_FlowerGiftReapplyForm
 * address:  0x021D8EDC
 * packet:   pkt_ov093_021D8EDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_TOKUSEI_IsCherrim  0x021D8E00  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   HAND_TOKUSEI_ChangeCherrimForm  0x021D8E7C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int HAND_TOKUSEI_IsCherrim(void *a, int b);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern void HAND_TOKUSEI_ChangeCherrimForm(int u, void *a, u32 b, u32 c, u8 d);

void HAND_TOKUSEI_FlowerGiftReapplyForm(int u, int a, int b, int *p)
{
    if (*p != 0 && HAND_TOKUSEI_IsCherrim((void *)a, b) != 0)
        HAND_TOKUSEI_ChangeCherrimForm(u, (void *)a, (int)b, (u8)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk((u8 *)a) == 1), 1);
}
