/*
 * function: func_021EABD0
 * address: 0x021EABD0
 * packet: pkt_ov170_021EABD0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern void *func_02045EC0(void *,unsigned);
extern void *func_02045770(void *);
extern void func_0201C724(unsigned,void *,short,short,void *,unsigned,unsigned short);
extern void func_02045808(void *);
void func_021EABD0(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color) {
 void *s; unsigned print;
 s=func_02045EC0(bank,idx);
 print=*(unsigned *)(w+0x8C);
 func_0201C724(print,func_02045770(*(void **)(w+0x94+i*8)),x,y,s,font,color);
 *(w+i*8+0x98)=1;
 func_02045808(s);
}
