/*
 * function: func_021646A0
 * address: 0x021646A0
 * packet: pkt_ov010_021646A0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188CCC 0x02188CCC thumb ov021
 *   func_021A0F90 0x021A0F90 thumb ov021
 *   func_021A0F30 0x021A0F30 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02188CCC(u8 *p);
extern u32 func_021A0F90(u8 *p);
extern int func_021A0F30(u32 a, u32 b);
int func_021646A0(void *a,void *b,void **p){void *v=(void *)func_02188CCC(p[1]); if(func_021A0F90(v)==6)func_021A0F30((u32)v,0);else func_021A0F30((u32)v,6);return 1;}
