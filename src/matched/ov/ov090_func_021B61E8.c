/*
 * function: func_021B61E8
 * address: 0x021B61E8
 * packet: pkt_ov090_021B61E8
 * region: ov090
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_02039C68(void *, u32, u32);
void func_021B61E8(void *a, u32 b) { func_02039C68(func_020399A8(), b, 45); }
