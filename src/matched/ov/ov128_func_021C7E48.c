/*
 * function: func_021C7E48
 * address: 0x021C7E48
 * packet: pkt_ov128_021C7E48
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original 021C7E64 sets r2=r+364 before func_021C89C4;
 * its filed source omits that argument. Preserve the caller's explicit third input.
 * symbols:
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_021C89C4 0x021C89C4 thumb ov128
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C6B38(u8 *);
extern void func_021C89C4(char *,void *,void *);
extern void func_02041B6C(u32);
void func_021C7E48(u8 *p,void *q,u8 *r) {int i;func_021C6B38(r);for(i=0;i<3;i++)func_021C89C4((char *)(p+12+i*76),r,r+364);func_02041B6C(0);}
