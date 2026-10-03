/*
 * function: func_021CA3A0
 * address: 0x021CA3A0
 * packet: pkt_ov128_021CA3A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_0204B8C4(void *,int);
extern void func_0204B878(void *,u16);
extern void func_0204B92C(void *,int);
void func_021CA3A0(char *p) {func_0204B8C4(*(void **)(p+356),0);func_0204B878(*(void **)(p+356),9);func_0204B92C(*(void **)(p+356),1);}
