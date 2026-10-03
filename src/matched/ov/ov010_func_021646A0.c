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
extern void *func_02188CCC(void *);
extern u32 func_021A0F90(u8 *p);
extern void func_021A0F30(void *,int);
int func_021646A0(void *a,void *b,void **p){void *v=func_02188CCC(p[1]); if(func_021A0F90(v)==6)func_021A0F30(v,0);else func_021A0F30(v,6);return 1;}
