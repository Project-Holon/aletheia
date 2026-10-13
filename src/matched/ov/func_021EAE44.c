/*
 * function: BTLV_CORE_StartAutoSelectNotice
 * address:  0x021EAE44
 * packet:   pkt_021EAE44
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_StartAutoSelectNotice   0x021EAE44  thumb  ov093
 *   BTLV_SCD_BeginCloseSequence   0x0689B670  thumb  ov095
 *
 * Resolved: BTLV_SCD_BeginCloseSequence was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void BTLV_CORE_StartAutoSelectNotice(E64 *p) { BTLV_SCD_BeginCloseSequence(p[0x6].f0); }
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

void BTLV_CORE_StartAutoSelectNotice(E64 *p) { BTLV_SCD_BeginCloseSequence(p[0x6].f0); }
