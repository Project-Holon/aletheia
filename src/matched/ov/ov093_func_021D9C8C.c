/*
 * unit: yes
 * function: HAND_TOKUSEI_PoisonPointOnDamageReaction, HAND_TOKUSEI_AddPoisonPoint
 * address: 0x021D9C8C
 * packet: pkt_ov093_021D9C8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPoisonPointHandlers 0x021F0850 data a4
 *   BTL_CALC_MakeDefaultSickCont 0x021D7D18 thumb ov093
 *   HAND_TOKUSEI_TryAddContactSick 0x021D9E08 thumb ov093
 */

typedef union { unsigned int raw; struct { unsigned int kind:3, lo:6, hi:6, rest:17; } s; } Slot;
extern Slot BTL_CALC_MakeDefaultSickCont(int);
/* Callee reads fifth input solely with ldrb [sp+0x28] at 021D9E3E;
 * original outgoing str [sp] supplies 30. No padding bits are read. */
extern void HAND_TOKUSEI_TryAddContactSick(int,int,int,Slot,unsigned char);
void HAND_TOKUSEI_PoisonPointOnDamageReaction(int a,int b,int c) { Slot s; s=BTL_CALC_MakeDefaultSickCont(5); HAND_TOKUSEI_TryAddContactSick(b,c,5,s,30); }
extern unsigned int gPoisonPointHandlers;
void *HAND_TOKUSEI_AddPoisonPoint(int *p) { *p=1; return &gPoisonPointHandlers; }
