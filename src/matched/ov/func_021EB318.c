/*
 * function: func_021EB318
 * address:  0x021EB318
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EB318   0x021EB318  thumb  ov093
 *   FADE_IsActive   0x0204E804  arm

 * Calls the ARM9 predicate FADE_IsActive and returns its negation.  Filed here because it is the only witness available for BTLV_SCU_GetWaitState's pool word: no branch anywhere in the image targets 0x021EB318, so `label` and `sole-ref/code` both refuse it.  18 bytes against a 20-byte listing extent (the last two are alignment), so the entry is EXACT*.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 func_021EB318(void) { if (FADE_IsActive() == 0) return 1; return 0; }

