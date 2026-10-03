/*
 * function: func_021BFB90
 * address: 0x021BFB90
 * packet: pkt_ov099_021BFB90
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BFBBA.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 */
extern void *func_020399A8(void);
extern void func_02039C68(void *, unsigned int, unsigned int);
extern int func_02156A3C(void);
extern void func_02009B80(void *,int);
int func_021BFB90(char *p, int ret) {
 func_02039C68(func_020399A8(),19,10);
 func_02009B80(*(void **)(p+4),func_02156A3C());
 *(int *)(p+0x1cc)=149;
 return ret;
}
