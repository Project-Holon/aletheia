/*
 * function: func_0216AED0
 * address: 0x0216AED0
 * packet: pkt_ov010_0216AED0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_02188C7C 0x02188C7C thumb ov021
 *   func_0216DE94 0x0216DE94 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern void *func_02188C7C(void *p);
extern void *func_0216DE94(void *, u32);
void *func_0216AED0(void *p, u32 id) { return func_0216DE94(func_02188C7C(func_0201210C(func_0215A5DC(p))), id); }
