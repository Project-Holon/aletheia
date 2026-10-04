/*
 * function: func_021B787C
 * address: 0x021B787C
 * packet: pkt_ov103_021B787C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Verified against the ov103 Thumb image.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_021B7B3C 0x021B7B3C thumb ov103
 *   func_021B7970 0x021B7970 thumb ov103
 *   func_021B7C68 0x021B7C68 thumb ov103
 *   func_021B8C14 0x021B8C14 thumb ov103
 *   func_020056A0 0x020056A0 thumb
 *   d_021B92D4 0x021B92D4 data ov103 a4
 *   func_021B795C 0x021B795C thumb ov103
 */
#include "../include/Obj22176.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_02082BCC(void *,int,int); extern void func_0204335C(int); extern void func_020433E0(void *); extern int func_0204363C(int); extern int func_0204361C(int); extern void func_020434CC(int); extern void func_021B7B3C(void *,void *,int); extern void func_021B7970(void *,int); extern void func_021B7C68(void *,int); extern void func_021B8C14(void *,void *,int); extern int func_020056A0(void *,void *,int); extern u8 d_021B92D4[]; extern void func_021B795C(void);
void func_021B787C(u8 *p,int x) {func_02082BCC(p,0,0x174); func_0204335C(0); func_020433E0(d_021B92D4); func_020434CC(func_0204361C(func_0204363C(0))); func_021B7B3C(p+0xcc,d_021B92D4,x); func_021B7970(p,x); func_021B7C68(p+4,x); func_021B8C14(p+0x160,p+4,x); ((struct Obj22176 *)p)->f170=func_020056A0(func_021B795C,p,0); }
