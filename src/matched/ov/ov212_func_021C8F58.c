/*
 * function: func_021C8F58
 * address: 0x021C8F58
 * packet: pkt_ov212_021C8F58
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C8F7C 0x021C8F7C thumb ov212
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S020314B8; struct S020315D4;
extern void func_021C8F7C(u8 *);
extern void func_0203133C(struct S020314B8 *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32 heap);
int func_021C8F58(struct S020315D4 *obj, void *b, void *c, u8 *p) {
    func_021C8F7C(p);
    func_0203133C(*(struct S020314B8 **)(p + 4));
    func_020315D4(obj);
    func_020306F0(105);
    return 1;
}
