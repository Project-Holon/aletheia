/*
 * function: func_021C873C
 * address: 0x021C873C
 * packet: pkt_ov128_021C873C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   func_021C7600 0x021C7600 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C7600(void *,int *);
int func_021C873C(void *p,int *state,u8 *q) {if(func_021C7600(*(void **)(q+44),(int *)(q+48))==0) {*state=0;return 1;}return 0;}
