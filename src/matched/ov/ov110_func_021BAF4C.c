/*
 * function: func_021BAF4C
 * address: 0x021BAF4C
 * packet: pkt_ov110_021BAF4C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B6CCC 0x021B6CCC thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02045808(void *);
extern void func_02045C04(void *);
extern void func_020307B0(void *);
extern void func_021B6CCC(int *);
void func_021BAF4C(unsigned p) { int i; func_02045808(*(void **)(p+0xad0));func_021B6CCC(*(int **)(p+0x78));for(i=0;i<27;i++)func_02045C04(*(void **)(p+i*4+0xc));func_020307B0((void *)p); }
