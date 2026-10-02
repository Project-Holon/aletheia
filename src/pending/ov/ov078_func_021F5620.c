/*
 * function: func_021F5620
 * address: 0x021F5620
 * packet: pkt_ov078_021F5620
 * region: ov078
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ov021 0x021CF59C unlabelled overlay-ID thunk, owned by Ilias.
 * symbols:
 *   d_021F5BC8 0x021F5BC8 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF59C 0x021CF59C thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F5698 0x021F5698 thumb ov078
 *   func_021F5800 0x021F5800 thumb ov078
 */
typedef struct { int x,y,z; } Vec;
extern const Vec d_021F5BC8;
extern int func_02189A08(int);
extern void func_021CF59C(void *);
extern void *func_021F5260(void *, const Vec *, void (*)(void), void (*)(void));
extern void func_021F5698(void);
extern void func_021F5800(void);
void *func_021F5620(void *p, int b) {
    Vec v = d_021F5BC8;
    func_021CF59C((void *)func_02189A08(b));
    return func_021F5260(p, &v, func_021F5698, func_021F5800);
}
