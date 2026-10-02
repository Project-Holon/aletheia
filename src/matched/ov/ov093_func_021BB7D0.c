/*
 * function: func_021BB7D0
 * address: 0x021BB7D0
 * packet: pkt_ov093_021BB7D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB830 0x021BB830 thumb ov093
 *   func_021EEB70 0x021EEB70 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BB830(u8 *);
extern void func_021EEB70(u32);
void func_021BB7D0(const u8 *p) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830((u8 *)(p+20+i*12))) func_021EEB70(*(const u32 *)((p+i*12)+20));
    }
}
