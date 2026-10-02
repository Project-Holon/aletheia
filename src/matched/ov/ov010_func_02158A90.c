/*
 * function: func_02158A90
 * address: 0x02158A90
 * packet: pkt_ov010_02158A90
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012844 0x02012844 thumb
 *   func_02162450 0x02162450 thumb ov010
 *   func_02158B3C 0x02158B3C thumb ov010
 *   func_02158A34 0x02158A34 thumb ov010
 */
typedef unsigned char u8;
extern void *func_020120F4(void *);
extern void *func_02012844(void *);
extern const u8 *func_02162450(void *);
extern int func_02158B3C(const u8 *, int);
extern void func_02158A34(int, int, int, int);
int func_02158A90(void *a, int unused, int key, int d) {
    int result = func_02158B3C(func_02162450(func_02012844(func_020120F4(a))), key);
    if (result == 0xffff) return 0;
    func_02158A34((int)a, 0, result, d);
    return 1;
}
