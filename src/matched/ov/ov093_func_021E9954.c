/*
 * function: func_021E9954
 * address: 0x021E9954
 * packet: pkt_ov093_021E9954
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Indexed-dispatch thunk, sibling of func_021E9964 (same shape, other tail target).
 * Tail call T(p[6].f0) with the index materialised as a scaled immediate.
 * Unlabelled leaf filed as the witness for the call in BTL_CLIENT_StepSelectAction.
 * symbols:
 *   func_021E9954 0x021E9954 thumb ov093
 *   func_06899D3C 0x06899D3C thumb ov095
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 f0; u8 pad[60]; } E64;
extern void func_06899D3C(u32);
void func_021E9954(E64 *p) { func_06899D3C(p[0x6].f0); }
