/*
 * unit: yes
 * function: func_021D8808, func_021D8838
 * address: 0x021D8808
 * packet: pkt_ov093_021D8808
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 021D881C loads r1=c and 021D8822 forwards the returned r0.
 * func_021C7CF4's legacy void signature is read as a pointer result;
 * its ldr r0,[r0,#8] tail forwards the full-word payload unchanged.
 * symbols:
 *   d_021F0668 0x021F0668 data ov093 a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021F0668[];
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern void *func_021C7CF4(int,int);
extern int func_021D62C4(void *,int);
void func_021D8808(int a,int b,int c) { if (c==func_021D775C(4)) { if (func_021D62C4(func_021C7CF4(b,c),6)) func_021D7704(53,2048); } }
u8 *func_021D8838(u32 *p) { *p=1; return d_021F0668; }
