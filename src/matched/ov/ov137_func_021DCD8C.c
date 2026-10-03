/*
 * unit: yes
 * function: func_021DCD8C,func_021DCDA0,func_021DCDB0,func_021DCDC0,func_021DCDD8,func_021DCDF0
 * address: 0x021DCD8C
 * packet: pkt_ov137_021DCD8C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021E1694 0x021E1694 thumb ov137
 * func_021E180C 0x021E180C thumb ov137
 * func_021E1814 0x021E1814 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021E1694(void *,void *),func_021E1814(void *,void *);
extern void func_021E180C(int *p, int a, int b);
void func_021DCD8C(int a,int b,void *c,u8 *p) { if(a==0) func_021E1694(*(void **)(*(u8 **)p+28),c); }
void func_021DCDA0(int a,int b,int *c,u8 *p) { func_021E180C(*(void **)(*(u8 **)p+28),a,*c); }
void func_021DCDB0(int a,int b,void *c,u8 *p) { func_021E1814(*(void **)(*(u8 **)p+28),c); }
void func_021DCDC0(int a,int b,void *c,u8 *p) { *(u16 *)(p+72)|=(u16)(1<<a); }
void func_021DCDD8(int a,int b,void *c,u8 *p) { *(u16 *)(p+74)|=(u16)(1<<a); }
void *func_021DCDF0(int a,u8 *p) { return *(u8 **)(p+76)+a*0x594; }
