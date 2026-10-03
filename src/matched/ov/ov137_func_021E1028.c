/*
 * function: func_021E1028
 * address: 0x021E1028
 * packet: pkt_ov137_021E1028
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0FAC 0x021E0FAC thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E0FAC(int *);
void func_021E1028(void *unused,char *p) { int i; int *q; q=(int *)(p+0xbfc); for(i=0;i<5;i++,q+=6) if(*q!=0) func_021E0FAC(q); }
