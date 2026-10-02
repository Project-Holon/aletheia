/*
 * function: func_021F5400
 * address: 0x021F5400
 * packet: pkt_ov083_021F5400
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02010F8C 0x02010F8C thumb
 *   func_0216D9E4 0x0216D9E4 thumb ov010
 */
typedef unsigned char u8;
extern void func_02045808(void *p);
extern void func_0201ED04(void *p);
extern void func_02045C04(void *p);
extern void func_02010F8C(void *p);
extern void func_0216D9E4(void *p);
void func_021F5400(u8 *p) { func_02045808(*(void **)(p+0x38));func_02045808(*(void **)(p+0x34));func_0201ED04(*(void **)(p+0x2c));func_02045C04(*(void **)(p+0x28));func_02010F8C(*(void **)(p+0x30));func_0216D9E4(*(void **)(p+0x1c)); }
