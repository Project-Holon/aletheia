/*
 * function: func_021C6638
 * address: 0x021C6638
 * packet: pkt_ov128_021C6638
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021CA478 0x021CA478 thumb ov128
 *   func_020310C4 0x020310C4 arm
 *   func_0204A600 0x0204A600 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021CA478(u8 *),func_020310C4(void *),func_0204A600(void);
void func_021C6638(u8 *p) { if(*(void **)(p+0x34)) { func_0201C4E4(*(void **)(p+0x34));func_021CA478(p); } if(*(void **)(p+0x28)) func_020310C4(*(void **)(p+0x28));func_0204A600(); }
