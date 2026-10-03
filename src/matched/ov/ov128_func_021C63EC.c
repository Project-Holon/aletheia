/*
 * function: func_021C63EC
 * address: 0x021C63EC
 * packet: pkt_ov128_021C63EC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_020355C4 0x020355C4 arm
 *   func_02012FFC 0x02012FFC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 func_020355C4(void);
extern signed char func_02012FFC(void);
void func_021C63EC(u8 *p,const u32 *q,u32 heap) {*(u32 *)(p+4)=*q;*(void **)(p+0x58)=func_020457B0(128,heap);*(void **)(p+0x5c)=func_020457B0(128,heap);*(u32 *)p=func_020355C4();p[12]=func_02012FFC();p[13]=0;p[14]=1;}
