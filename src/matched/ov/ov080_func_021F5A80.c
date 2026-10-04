/*
 * function: func_021F5A80
 * address: 0x021F5A80
 * packet: pkt_ov080_021F5A80
 * region: ov080
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F5B64 0x021F5B64 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF580 0x021CF580 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F5ABC 0x021F5ABC thumb ov080
 *   func_021F582C 0x021F582C thumb ov077
 */
typedef struct { int x,y,z; } Vec;
extern const Vec d_021F5B64;
extern int func_02189A08(unsigned char *p);
extern void func_021CF580(void *);
extern void *func_021F5260(void *, const Vec *, void (*)(void), void (*)(void));
extern void func_021F5ABC(void *a);
extern void func_021F582C(void);
void *func_021F5A80(void *p, int b) {
    Vec v = d_021F5B64;
    func_021CF580((void *)func_02189A08((unsigned char *)b));
    return func_021F5260(p, &v, (void (*)(void))func_021F5ABC, func_021F582C);
}
