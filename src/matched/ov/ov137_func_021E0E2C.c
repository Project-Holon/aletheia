/*
 * function: func_021E0E2C
 * address: 0x021E0E2C
 * packet: pkt_ov137_021E0E2C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021E0E2C(char *p,int value) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) { if(*q==0) { *q=1; q[7]=value; return; } } }
