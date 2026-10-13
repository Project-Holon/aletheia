/*
 * function: BTLV_CORE_ResetDisplay
 * address:  0x021E8E28
 * packet:   pkt_021E8E28
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_ExitDisplay   0x021E8F08  thumb ov093
 *   BTLV_CORE_InitDisplay   0x021E8E38  thumb ov093
 *   BTLV_CORE_ResetDisplay   0x021E8E28  thumb ov093
 *
 * wrapper over BTLV_CORE_ExitDisplay, BTLV_CORE_InitDisplay
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void BTLV_CORE_ExitDisplay(void);
extern void BTLV_CORE_InitDisplay(void *p);

void BTLV_CORE_ResetDisplay(void *p)
{
    BTLV_CORE_ExitDisplay();
    BTLV_CORE_InitDisplay(p);
}
