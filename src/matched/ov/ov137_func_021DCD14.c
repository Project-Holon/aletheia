/*
 * unit: yes
 * function: func_021DCD14,func_021DCD34,func_021DCD44,func_021DCD5C,func_021DCD6C,func_021DCD7C
 * address: 0x021DCD14
 * packet: pkt_ov137_021DCD14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021DE17C 0x021DE17C thumb ov137
 * func_021E172C 0x021E172C thumb ov137
 * func_021E1758 0x021E1758 thumb ov137
 * func_021E168C 0x021E168C thumb ov137
 * func_02039338 0x02039338 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021DE17C(void *,int,int);
extern int func_02039338(void);
extern void func_021E172C(void *,void *),func_021E1758(void *,int),func_021E168C(void *,int);
void func_021DCD14(int a,int b,u8 *c,u8 *p)
{
    func_021DE17C(*(void **)(*(u8 **)p+32),1,*c);
    if(!func_02039338()) *(int *)(p+52)=0;
}
void func_021DCD34(int a,int b,u16 *c,u8 *p) { *(u16 *)(p+64)|=*c; }
void func_021DCD44(int a,int b,void *c,u8 *p) { *(u16 *)(p+66)|=(u16)(1<<a); }
void func_021DCD5C(int a,int b,void *c,u8 *p) { func_021E172C(*(void **)(*(u8 **)p+28),c); }
void func_021DCD6C(int a,int b,int *c,u8 *p) { func_021E1758(*(void **)(*(u8 **)p+28),*c); }
void func_021DCD7C(int a,int b,u8 *c,u8 *p) { func_021E168C(*(void **)(*(u8 **)p+28),*c); }
