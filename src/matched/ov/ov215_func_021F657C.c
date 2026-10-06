/*
 * function: func_021F657C
 * address: 0x021F657C
 * packet: pkt_ov215_021F657C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: the caller truncates the 020403F4 argument with lsl/lsr #24,
 * so its extern is u8 although the callee's own source uses a word.
 * lever: a named unsigned byte-address base keeps the table in r4 and
 * index in r5; the inline address swaps them, and word indexing adds lsl #2.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021F71F4 0x021F71F4 data a4
 */
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *,int,unsigned);
extern const unsigned d_021F71F4[];
void func_021F657C(void *p){unsigned base=(unsigned)d_021F71F4;unsigned i;for(i=0;i<6;i++)func_020403F4((unsigned char)(*(const unsigned *)(base+i*44)));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}
