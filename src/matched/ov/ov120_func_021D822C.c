/*
 * function: func_021D822C
 * address: 0x021D822C
 * packet: pkt_ov120_021D822C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_021D4F70 0x021D4F70 thumb ov120
 *   func_021D8118 0x021D8118 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_021D4F70(void **p, int i);
extern void func_021D8118(char *,void *,int);
extern void func_02041B6C(u32);
void func_021D822C(char *p,void *q,int index) { func_021D8118(p,func_021D4F70(q,index),5); func_02041B6C(6); }
