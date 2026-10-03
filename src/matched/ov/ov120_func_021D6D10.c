/*
 * function: func_021D6D10
 * address: 0x021D6D10
 * packet: pkt_ov120_021D6D10
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows.
 * symbols:
 *   func_021D4F70 0x021D4F70 thumb ov120
 *   func_021D6C7C 0x021D6C7C thumb ov120
 *   func_021D6CCC 0x021D6CCC thumb ov120
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D4F70(void **p, int i);
extern void func_021D6C7C(u8 *,int);
extern void func_021D6CCC(u8 *,int);
extern void func_02041B6C(u32 bit);
void func_021D6D10(u8 *p,void *list,int first){int i;for(i=0;i<6;i++){if(func_021D4F70(list,first+i))func_021D6C7C(p,i);else func_021D6CCC(p,i);}func_02041B6C(4);}
