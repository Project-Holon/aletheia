/*
 * function: BTLV_CORE_PollYesNoMenu
 * address:  0x021EAC54
 * packet:   pkt_021E9964
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_PollYesNoMenu   0x021EAC54  thumb  ov093
 *   BTLV_SCD_PollChoiceScreen   0x0689B5CC  thumb  ov095
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

void BTLV_CORE_PollYesNoMenu(E64 *p, u32 a2) { BTLV_SCD_PollChoiceScreen(p[0x6].f0, a2); }

