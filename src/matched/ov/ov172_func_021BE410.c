/*
 * function: func_021BE410
 * address: 0x021BE410
 * packet: pkt_ov172_021BE410
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD3B8 0x021BD3B8 thumb ov172
 */
typedef unsigned int u32;
extern void func_021BD3B8(u32 *p);
extern void func_020307B0(u32 p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(int h);
int func_021BE410(void *a, void *b, int c, u32 *p)
{
    func_021BD3B8(p);
    if (c == 0) {
        func_020307B0(p[0x7e]);
    }
    func_020315D4(a);
    func_020306F0(0x6d);
    return 1;
}
