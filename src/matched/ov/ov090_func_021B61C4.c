/*
 * function: func_021B61C4
 * address: 0x021B61C4
 * packet: pkt_ov090_021B61C4
 * region: ov090
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1A4(int);
void func_021B61C4(int a, int b, unsigned char *c, unsigned char *d) {
    func_0203D1A4((int)func_020399A8());
    if(c[2]==0) d[148]++;
}
