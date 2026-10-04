/*
 * function: func_021F4300
 * address: 0x021F4300
 * packet: pkt_ov112_021F4300
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte padding at 0x021F434E.
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_021F4748 0x021F4748 thumb ov112
 *   func_020403F4 0x020403F4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Bank;
struct Obj;
struct TaskMenuState;
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B1CC(struct Bank *bank);
extern void func_021F4748(u8 *);
extern void func_020403F4(u32 i);
extern void func_020307B0(void *);
void func_021F4300(u8 *p)
{
    func_02027FD8((struct TaskMenuState *)(*(u32 *)(p+0x40)));
    if (*(u32 *)(p+0xc)==0) {
        func_0204ADA4(*(u32 *)(p+0x4c));
        func_0204A8D4(*(u32 *)(p+0x50));
        func_0204AFD8(*(u32 *)(p+0x54));
        func_0204B3B4((struct Obj *)(*(u32 *)(p+0x58)));
    }
    func_0204B1CC((struct Bank *)(*(u32 *)(p+0x48)));
    func_021F4748(p);
    func_020403F4(4);
    func_020403F4(6);
    func_020403F4(7);
    func_020307B0(p);
}
