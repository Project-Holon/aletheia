/*
 * unit: yes
 * function: func_021D9C8C, func_021D9CB0
 * address: 0x021D9C8C
 * packet: pkt_ov093_021D9C8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0850 0x021F0850 data a4
 *   func_021D7D18 0x021D7D18 thumb ov093
 *   func_021D9E08 0x021D9E08 thumb ov093
 */

typedef union { unsigned int raw; struct { unsigned int kind:3, lo:6, hi:6, rest:17; } s; } Slot;
extern Slot func_021D7D18(int);
/* Callee reads fifth input solely with ldrb [sp+0x28] at 021D9E3E;
 * original outgoing str [sp] supplies 30. No padding bits are read. */
extern void func_021D9E08(int,int,int,Slot,unsigned char);
void func_021D9C8C(int a,int b,int c) { Slot s; s=func_021D7D18(5); func_021D9E08(b,c,5,s,30); }
extern unsigned int d_021F0850;
void *func_021D9CB0(int *p) { *p=1; return &d_021F0850; }
