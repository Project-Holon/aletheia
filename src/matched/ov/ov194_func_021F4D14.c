/*
 * function: func_021F4D14, func_021F4D1C
 * address: 0x021F4D14
 * packet: pkt_ov194_021F4D14
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * extent: lead tail-call stub followed by unlabelled load-and-return at 021F4D1C.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204A648(void);
void func_021F4D14(u8 *a0) { func_0204A648(); }
u32 func_021F4D1C(const u32 *p) { return *p; }
