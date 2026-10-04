/*
 * function: func_021D584C
 * address: 0x021D584C
 * packet: pkt_ov115_021D584C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Bank;
struct Node;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_02030EAC(struct Node *n);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021D584C(u8 *p) {
    int i;
    for (i = 0; i < 5; ++i) {
        if (*(u32 *)(p + i * 4 + 0x99c)) {
            func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4 + 0x99c)));
            *(u32 *)(p + i * 4 + 0x99c) = 0;
        }
    }
    func_0204ADA4(*(u32 *)(p + 0x98c));
    func_0204A8D4(*(u32 *)(p + 0x990));
    func_0204AFD8(*(u32 *)(p + 0x994));
    if (*(u32 *)(p + 0x988)) func_02030EAC((struct Node *)(*(u32 *)(p + 0x988)));
    func_02030EAC((struct Node *)(*(u32 *)(p + 0x984)));
    func_0204B1CC((struct Bank *)(*(u32 *)(p + 0x980)));
    func_0204A5AC();
}
