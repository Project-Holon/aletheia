/*
 * function: func_021B8FA0
 * address: 0x021B8FA0
 * packet: pkt_ov103_021B8FA0
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Loop bound remains g*h in the condition; caching the product adds a register copy and shifts the body. Callee widths follow caller truncations.
 * symbols:
 * func_0204A380 0x0204A380 arm
 * func_02062B30 0x02062B30 arm
 * func_0204169C 0x0204169C arm
 * func_0204162C 0x0204162C arm
 * func_020410D0 0x020410D0 arm
 * func_020413B0 0x020413B0 arm
 * func_020409B4 0x020409B4 arm
 * func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(u8);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8,u8,u8,u8,u8,u8);
extern void func_020409B4(u8);
extern void func_020307B0(void *);
void func_021B8FA0(int a,int b,int c,int d,u8 e,u8 f,u8 g,u8 h,u8 i,u8 j,u8 k,u8 l,u8 m,int n,u16 o) {
 void *handle;
 int t;
 u8 *data;
 u16 *p;
 int count;
 handle=func_0204A380((void *)a,b,n,(u16)((o&0x7fff)|0x8000));
 func_02062B30(handle,(void **)(&data));
 if(d && !func_0204169C(c)) {
  count=h*g;
  p=(u16 *)(data+12);
  for(t=0;t<(g*h);t++)p[t]+=(u16)d;
 }
 if(func_0204162C((u8)c)) {
  func_020410D0((u8)c,i,j,k,l,(u32)(data+12),e,f,g,h);
  func_020413B0(c,i,j,k,l,m);
  func_020409B4(c);
 }
 func_020307B0(handle);
}
