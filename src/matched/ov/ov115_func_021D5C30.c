/*
 * function: func_021D5C30
 * address: 0x021D5C30
 * packet: pkt_ov115_021D5C30
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x021D5C6E.
 * symbols:
 *   func_021D5B5C 0x021D5B5C thumb ov115
 *   func_0202F038 0x0202F038 thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202EE30 0x0202EE30 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021D5B5C(void *, unsigned int, int);
extern void func_0202F038(u8 *);
extern unsigned int func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
void func_021D5C30(u8 *p, unsigned int a, int b) {
    func_021D5B5C(p, a, b);
    if (*(void **)(p + 0x80)) {
        func_0202F038(*(void **)(p + 0x80));
        *(void **)(p + 0x80) = 0;
    }
    *(void **)(p + 0x80) = func_0202EE30((void *)func_020056BC(), *(void **)(p + 0x2c), 15, 16, *(u16 *)(p + 0x4c));
}
