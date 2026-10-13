/*
 * unit: yes
 * function: HAND_TOKUSEI_FlameBodyOnDamageReaction, HAND_TOKUSEI_AddFlameBody
 * address: 0x021D9CEC
 * packet: pkt_ov093_021D9CEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0840 0x021F0840 data a4
 *   BTL_CALC_MakeDefaultSickCont 0x021D7D18 thumb ov093
 *   HAND_TOKUSEI_TryAddContactSick 0x021D9E08 thumb ov093
 */

typedef union { unsigned int raw; struct { unsigned int kind:3, lo:6, hi:6, rest:17; } s; } Slot;
extern Slot BTL_CALC_MakeDefaultSickCont(int);
/* Callee reads fifth input solely with ldrb [sp+0x28] at 021D9E3E;
 * original outgoing str [sp] supplies 30. No padding bits are read. */
extern void HAND_TOKUSEI_TryAddContactSick(int,int,int,Slot,unsigned char);
void HAND_TOKUSEI_FlameBodyOnDamageReaction(int a,int b,int c) { Slot s; s=BTL_CALC_MakeDefaultSickCont(4); HAND_TOKUSEI_TryAddContactSick(b,c,4,s,30); }
extern unsigned int d_021F0840;
void *HAND_TOKUSEI_AddFlameBody(int *p) { *p=1; return &d_021F0840; }
