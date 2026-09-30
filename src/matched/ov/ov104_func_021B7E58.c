/*
 * function: func_021B7E58
 * address: 0x021B7E58
 * packet: pkt_ov104_021B7E58
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: c and its callee parameter are u8; u32 hoists its spill reload.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,int);
extern void *func_020450F0(u32,u32,u8,u8,u8,u8,u8);
extern void *func_020457B0(u32,u16);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u32 func_02045730(void *);
extern void func_020409B4(u32);
void func_021B7E58(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size) { void *q; func_02082BCC(p,0,0x14); *(u16 *)(p+0x10)=color; *(void **)p=func_020450F0(a,b,c,d,e,f,heap); *(void **)(p+0xc)=func_020457B0(0xff,size); *(void **)(p+4)=*(void **)p; p[8]=0; func_02043B5C(func_02045770(*(void **)p),*(u16 *)(p+0x10)); q=*(void **)p; func_02045334(q); func_02045374(q); func_020409B4(func_02045730(q)); }
