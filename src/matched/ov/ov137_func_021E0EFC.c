/*
 * function: func_021E0EFC
 * address: 0x021E0EFC
 * packet: pkt_ov137_021E0EFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0EAC 0x021E0EAC thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E0EAC(int *);
void func_021E0EFC(void *unused,char *p) { int i; int *q; q=(int *)(p+0xb98); for(i=0;i<5;i++,q+=5) if(*q!=0) func_021E0EAC(q); }
