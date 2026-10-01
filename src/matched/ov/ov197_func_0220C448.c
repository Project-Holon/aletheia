/*
 * function: func_0220C448
 * address: 0x0220C448
 * packet: pkt_ov197_0220C448
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220C6E8 0x0220C6E8 thumb ov197
 *   func_0220C6C0 0x0220C6C0 thumb ov197
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
struct Obj;
struct Bank;
extern void func_0220C6E8(char *);
extern void func_0220C6C0(char *);
extern void func_0204B3B4(struct Obj *);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204B1CC(struct Bank *);
void func_0220C448(char *p)
{
    unsigned i;
    func_0220C6E8(p);
    for (i = 0; i < 63; i++) func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x424));
    func_0220C6C0(p);
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x544) != -1) func_0204A8D4(*(int *)(p + i * 4 + 0x544));
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x568) != -1) func_0204ADA4(*(int *)(p + i * 4 + 0x568));
    for (i = 0; i < 3; i++) if (*(int *)(p + i * 4 + 0x58c) != -1) func_0204AFD8(*(int *)(p + i * 4 + 0x58c));
    func_0204B1CC(*(struct Bank **)(p + 0x420));
}
