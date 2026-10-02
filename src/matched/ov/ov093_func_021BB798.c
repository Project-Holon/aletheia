/*
 * function: func_021BB798
 * address: 0x021BB798
 * packet: pkt_ov093_021BB798
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB830 0x021BB830 thumb ov093
 *   func_021EEB2C 0x021EEB2C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BB830(u8 *);
extern int func_021EEB2C(u32);
int func_021BB798(u8 *p) {
    int result;
    int i;
    u8 *q;
    result = 1; i = 0; q = p+20;
    for (; i < 4; i++) {
        if (func_021BB830(q+i*12)) {
            if (!func_021EEB2C(*(u32 *)((p+i*12)+20))) result = 0;
        }
    }
    return result;
}
