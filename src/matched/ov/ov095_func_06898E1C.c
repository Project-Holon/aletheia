/*
 * unit:     yes
 * function: HAND_SIDE_GetHandlersReflect, HAND_SIDE_ReflectOnDamage, HAND_SIDE_GetHandlersLightScreen, HAND_SIDE_LightScreenOnDamage
 * address:  0x06898E1C
 * packet:   pkt_ov095_06898E1C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed extent 0x06898E0C (72 bytes) opens with a 16-byte `bx pc` veneer
 * to 0x021D70A8 (ARM linker stub, not compilable); the four functions after
 * it (0x06898E1C..0x06898E54) are this unit. 0x06898E1C and 0x06898E38 are
 * entries of the {key, fn} tables at 0x0689D6F0 / 0x0689D710.
 *
 * symbols:
 *   HAND_SIDE_ScreenReduceDamage  0x06898E54  thumb  ov095
 *   gHandSideReflectHandlers     0x0689D6F0  data   ov095  a4
 *   gHandSideLightScreenHandlers     0x0689D710  data   ov095  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 gHandSideReflectHandlers[];
extern u8 gHandSideLightScreenHandlers[];
extern void HAND_SIDE_ScreenReduceDamage(int a, int b, int c);

u8 *HAND_SIDE_GetHandlersReflect(u32 *p)
{
    *p = 1;
    return gHandSideReflectHandlers;
}

void HAND_SIDE_ReflectOnDamage(int a, int b, int c)
{
    HAND_SIDE_ScreenReduceDamage(b, c, 1);
}

u8 *HAND_SIDE_GetHandlersLightScreen(u32 *p)
{
    *p = 1;
    return gHandSideLightScreenHandlers;
}

void HAND_SIDE_LightScreenOnDamage(int a, int b, int c)
{
    HAND_SIDE_ScreenReduceDamage(b, c, 2);
}
