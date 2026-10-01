/*
 * function: func_021BDB34
 * address: 0x021BDB34
 * packet: pkt_ov210_021BDB34
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCB58 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   func_021BC8B4 0x021BC8B4 thumb ov210
 *   func_021BEB0C 0x021BEB0C thumb ov210
 *   func_021C0434 0x021C0434 thumb ov210
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_021BF728 0x021BF728 thumb ov210
 *   func_021BF55C 0x021BF55C thumb ov210
 *   func_021BCB58 0x021BCB58 thumb ov210
 *   func_021BC5C8 0x021BC5C8 thumb ov210
 *   func_021BCD30 0x021BCD30 thumb ov210
 */
typedef unsigned char u8;
extern void func_021BC8B4(int);
extern void func_021BEB0C(u8 *);
extern void func_021C0434(u8 *);
extern int func_021B7A64(void *);
extern void func_021BF728(u8 *, int);
extern void func_021BF55C(u8 *);
extern void func_021BCB58(u8 *);
extern void func_021BC5C8(void);
extern void func_021BCD30(u8 *);
int func_021BDB34(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 3;
        func_021BC8B4(1);
        func_021BEB0C(p);
        func_021C0434(p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(*(void **)(p + 0x1E0)) == 0) {
            func_021BF728(p, 0);
            func_021BF55C(p);
            func_021BCB58(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 19;
        }
    }
    return 18;
}
