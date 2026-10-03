/*
 * function: func_021B61C4
 * address: 0x021B61C4
 * packet: pkt_ov098_021B61C4
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B632C 0x021B632C thumb ov098
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov094_id 0x0000005E data
 */
extern void func_021B632C(void *);
extern void func_020315D4(void *);
extern void func_020306F0(void *);
extern void func_02034A5C(int);
extern char ov094_id[];
int func_021B61C4(void *a, int b, int c, void **p)
{
    func_021B632C(*p);
    func_020315D4(a);
    func_020306F0((void *)0x85);
    func_02034A5C((int)ov094_id);
    return 1;
}
