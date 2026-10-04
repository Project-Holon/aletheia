/*
 * function: func_021BB7FC
 * address: 0x021BB7FC
 * packet: pkt_ov093_021BB7FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB830 0x021BB830 thumb ov093
 *   func_021EEAD0 0x021EEAD0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BB830(u8 *);
extern void func_021EEAD0(u8 *p);
void func_021BB7FC(const u8 *p) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830((u8 *)(p+20+i*12))) func_021EEAD0((u8 *)(*(const u32 *)((p+i*12)+20)));
    }
}
