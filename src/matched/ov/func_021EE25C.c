/*
 * function: BTLV_SCU_GetWaitState
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
 *   BTLV_SCU_GetWaitState   0x021EE25C  thumb  ov093
 *   BTLV_SCU_IsFadeDone   0x021EB318  thumb  ov093

 * Untraced mid-stream entry point: a plain tail thunk, `ldr r3,=T; bx r3`, whose pool word names BTLV_SCU_IsFadeDone.  The listing's next func_ label is BTLV_SCU_UpdateBallWindowOpen, but the thunk is 8 bytes and 0x021EE264 is a second untraced entry point; the address is not a func_ start, so match.py has no listing extent to compare against and the entry reaches EXACT outright.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void BTLV_SCU_GetWaitState(void) { BTLV_SCU_IsFadeDone(); }

