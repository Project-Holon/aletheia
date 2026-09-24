/*
 * function: func_021EE25C
 * address:  0x021EE25C
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE25C   0x021EE25C  thumb  ov093
 *   func_021EB318   0x021EB318  thumb  ov093

 * Untraced mid-stream entry point: a plain tail thunk, `ldr r3,=T; bx r3`, whose pool word names func_021EB318.  The listing's next func_ label is func_021EE2A0, but the thunk is 8 bytes and 0x021EE264 is a second untraced entry point; the address is not a func_ start, so match.py has no listing extent to compare against and the entry reaches EXACT outright.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void func_021EE25C(void) { func_021EB318(); }

