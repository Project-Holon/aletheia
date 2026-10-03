/*
 * function: func_021FA64C
 * address: 0x021FA64C
 * packet: pkt_ov132_021FA64C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware control read at 021FA652 and store 021FA658.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_0204B1CC(struct Bank *bank);
extern void func_020307B0(void *);
void func_021FA64C(char *p)
{
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    if (*(u16 *)(p + 0x48) != 255) func_0204B3B4(*(void **)(p + 0x4c));
    if (*(u16 *)(p + 0x4a) != 255) func_0204B3B4(*(void **)(p + 0x50));
    func_0204B3B4(*(void **)(p + 0x5c));
    func_0204ADA4(*(void **)(p + 0x1c));
    func_0204A8D4(*(void **)(p + 0x28));
    func_0204AFD8(*(void **)(p + 0x34));
    func_0204ADA4(*(void **)(p + 0x20));
    func_0204A8D4(*(void **)(p + 0x2c));
    func_0204AFD8(*(void **)(p + 0x38));
    func_0204ADA4(*(void **)(p + 0x24));
    func_0204A8D4(*(void **)(p + 0x30));
    func_0204AFD8(*(void **)(p + 0x3c));
    func_0204B1CC(*(void **)(p + 0x18));
    func_020307B0(p);
}
