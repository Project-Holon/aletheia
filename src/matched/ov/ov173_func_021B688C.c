/*
 * function: func_021B688C
 * address: 0x021B688C
 * packet: pkt_ov173_021B688C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045C04(void *);
extern void func_0201ED04(void *);
extern void func_02045808(void *);
void func_021B688C(char *p) { func_02045C04(*(void **)(p+0x44)); func_0201ED04(*(void **)(p+0x48)); func_02045808(*(void **)(p+0x4c)); func_02045808(*(void **)(p+0x50)); func_02045808(*(void **)(p+0x54)); }
