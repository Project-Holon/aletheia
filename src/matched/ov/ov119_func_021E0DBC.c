/*
 * function: func_021E0DBC
 * address: 0x021E0DBC
 * packet: pkt_ov119_021E0DBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275EC 0x020275EC thumb
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Descriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} Descriptor;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275F8(u32);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern u8 func_020275EC(u8 i);
extern void func_021B6208(void *,Descriptor *,int,u16);
extern int func_021B629C(void *,int,u8,u8,u8,u16);
extern void func_0204B6F4(int,int,int);
void func_021E0DBC(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b) {Descriptor d;u8 v;int z=0;v=func_02017E1C(mon,index+174,0);d.a=a;d.b=z;d.c=func_020275E4();d.d=func_020275E8();d.e=func_020275F8(v);d.f=func_020275FC(2);d.g=func_02027600(2);d.h=8;d.i=z;d.j=3;func_021B6208(p,&d,slot,b);*(int *)(p+16)=func_021B629C(p,slot,x,y,z,b);func_0204B6F4(*(int *)(p+16),func_020275EC(v),1);}
