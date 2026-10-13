/*
 * function: BTLV_CORE_WaitSceneEffect
 * address:  0x021EA0E4
 * packet:   pkt_021E9964
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_WaitSceneEffect   0x021EA0E4  thumb  ov093
 *   BTLV_SCU_RunWazaProc   0x021ED1B0  thumb  ov093
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

int BTLV_CORE_WaitSceneEffect(u32 *p) { return BTLV_SCU_RunWazaProc(p[0x5f]); }

