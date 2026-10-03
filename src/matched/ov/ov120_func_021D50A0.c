/*
 * function: func_021D50A0
 * address: 0x021D50A0
 * packet: pkt_ov120_021D50A0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7ECC 0x021D7ECC thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5334 0x021D5334 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D7ECC(char *,u16); extern void func_021D4244(int,void (*)(int),int); extern void func_021D5334(int);
void func_021D50A0(u8 *p) { *(void **)(p+52)=func_021D7ECC(*(char **)(p+64),44); func_021D4244((int)p,func_021D5334,0x5ff); }
