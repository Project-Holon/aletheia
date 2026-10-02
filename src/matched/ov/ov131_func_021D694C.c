/*
 * function: func_021D694C
 * address: 0x021D694C
 * packet: pkt_ov131_021D694C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
extern void func_0204B3B4(void *);
void func_021D694C(void *a,unsigned char *p) {
 u8 i;
 func_0204B3B4(*(void **)(p+0x48));
 func_0204B3B4(*(void **)(p+0x44));
 for(i=0;i<8;i++) func_0204B3B4(*(void **)(p+0x24+i*4));
 func_0204B3B4(*(void **)(p+0x20));
}
