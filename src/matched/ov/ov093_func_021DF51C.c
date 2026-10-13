/*
 * function: BTL_HANDLER_ITEM_LightBallDoublePikachuAttack
 * address:  0x021DF51C
 * packet:   pkt_ov093_021DF51C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern void BTL_EVENT_MultiplyVar(int, int);
void BTL_HANDLER_ITEM_LightBallDoublePikachuAttack(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && BTL_POKEPARAM_GetSpecies(func_021C7CF4((int *)b, c)) == 0x19)
        BTL_EVENT_MultiplyVar(0x35, 2 << 12);
}
