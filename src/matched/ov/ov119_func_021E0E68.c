/*
 * function: func_021E0E68
 * address: 0x021E0E68
 * packet: pkt_ov119_021E0E68
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021E0EF2, labelled next function 0x021E0EF4.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_021E0E4C 0x021E0E4C thumb ov119
 *   func_020275E4 0x020275E4 thumb
 *   func_02027720 0x02027720 thumb
 *   func_0202772C 0x0202772C thumb
 *   func_02027738 0x02027738 thumb
 *   func_02027740 0x02027740 thumb
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Descriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} Descriptor;
extern u32 func_02017E1C(void *,u32,void *);
extern void func_021E0E4C(void *);
extern u32 func_020275E4(void);
extern int func_02027720(int);
extern int func_0202772C(int);
extern int func_02027738(int,int);
extern int func_02027740(int,int);
extern void func_021B6208(void *,Descriptor *,int,u16);
extern int func_021B629C(void *,int,u8,u8,u8,u16);
void func_021E0E68(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c) {Descriptor d;int v;v=func_02017E1C(mon,152,0);func_021E0E4C(p);d.a=a;d.b=0;d.c=func_020275E4();d.d=func_02027720(v);d.e=func_0202772C(v);d.f=func_02027738(v,2);d.g=func_02027740(v,2);d.h=c;d.i=0;d.j=1;func_021B6208(p,&d,slot,b);*(int *)(p+16)=func_021B629C(p,slot,x,y,0,b);}
