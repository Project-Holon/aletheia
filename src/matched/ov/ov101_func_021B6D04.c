/*
 * unit: yes
 * function: func_021B6D04, func_021B6D3C
 * address: 0x021B6D04
 * packet: pkt_ov101_021B6D04
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * d_021B753C 0x021B753C data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern char d_021B753C[];
extern void *func_02030734(unsigned heapId,unsigned size,int clear,const char *site,u16 tag);
extern void func_02082BCC(int,int,unsigned);
extern void func_020307B0(int);
int func_021B6D04(unsigned a,int p) {
 int q;
 q=(int)func_02030734(a,0x14,0,d_021B753C,0x3af);
 func_02082BCC(q,0,0x14);
 *(int *)q=**(int **)(p+0x10);
 *(int *)(q+4)=*(int *)p;
 *(int *)(q+8)=*(int *)(p+0x3c);
 return q;
}
void func_021B6D3C(int p,int q) {
 *(int *)(q+0x24)=*(int *)(p+0xc);
 *(u8 *)(q+0x2e)=*(u8 *)(p+0x10);
 *(u8 *)(q+0x2f)=*(u8 *)(p+0x11);
 *(int *)(q+0x30)=*(u8 *)(p+0x12);
 func_020307B0(p);
}
