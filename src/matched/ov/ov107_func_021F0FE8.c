/*
 * function: func_021F0FE8
 * address: 0x021F0FE8
 * packet: pkt_ov107_021F0FE8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-05 P26L5: source order is flag clear first, then the word at +4 (the compiler schedules the str before ands/strh). Plain literal zeros, no zero local. 021F1008 and 021F1010 are separate stubs.
 * symbols:
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203E6C0 0x0203E6C0 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u32 a; u32 f4; u8 pad[16];unsigned short low:11,flag:1,rest:4;} State;
extern int func_0203CEAC(int);
extern void func_0203E6C0(void);
void func_021F0FE8(State *p) { func_0203CEAC(0); func_0203E6C0(); p->flag=0; p->f4=0; }
