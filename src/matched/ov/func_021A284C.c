/*
 * function: WEATHER_TASK_UnloadResources
 * address:  0x021A284C
 * packet:   pkt_021A284C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   WEATHER_TASK_FreeSpriteResources  0x021A29F4  thumb  ov021
 *   WEATHER_TASK_FreeArchive  0x021A2994  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 WEATHER_TASK_FreeArchive(u32);
extern void WEATHER_TASK_FreeSpriteResources(u16 *p, u32 a1, u32 a2, u32 a3);

int WEATHER_TASK_UnloadResources(u32 a, u32 b, u32 c, u32 d)
{
WEATHER_TASK_FreeSpriteResources((u16 *)(a + 40), b, c, d);
return WEATHER_TASK_FreeArchive((a + 40));
}

