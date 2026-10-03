/*
 * function: func_021BCF7C
 * address: 0x021BCF7C
 * packet: pkt_ov110_021BCF7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BCFBA.
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void func_02028218(struct Obj *obj, u32 a);
void func_021BCF7C(u8 *p, int n, int v) {
    int i;
    void **a = (void **)(p + 0x64);
    if (a[n]) {
        for (i = 0; i < 3; i++) {
            if (*(void **)(p + 0x64 + i * 4)) func_02028218(*(void **)(p + 0x64 + i * 4), 0);
        }
        func_02028218(a[n], v);
    }
}
