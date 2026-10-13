/*
 * function: BTLV_SCU_IsMonGraphicSwapDone
 * address:  0x021ED714
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_IsMonGraphicSwapDone   0x021ED714  thumb  ov093

 * Untraced mid-stream entry point, same shape as BTLV_SCU_IsMonWithdrawDone with the offset 0x40.  Two family C thunks tail into this one.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 BTLV_SCU_IsMonGraphicSwapDone(u8 *p) { if (p[0x40] == 0) return 1; return 0; }

