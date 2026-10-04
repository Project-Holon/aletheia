/*
 * function: func_021F42A0
 * address: 0x021F42A0
 * packet: pkt_ov194_021F42A0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02045808 0x02045808 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned int   u32;
struct Grid;
struct Obj;
struct Obj020437AC;
struct U16Vec;
extern void func_0204ADA4(u32 i);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B3B4(struct Obj *p);
extern void func_02082BCC(unsigned char *,unsigned,unsigned);
void func_021F42A0(unsigned char *p) {
    if (*(void **)(p+0x2c)) {
        func_0204ADA4(*(int *)(p+0x24));
        func_02045808(*(void **)(p+0x28));
        func_0202570C(*(void **)(p+0x2c));
        func_020437AC(*(void **)(p+0x30));
    }
    func_0204ADA4(*(int *)(p+8));
    func_0204A8D4((u32)(*(void **)(p+12)));
    func_0204AFD8(*(int *)(p+16));
    func_0204B3B4(*(void **)p);
    func_02082BCC(p,0,0x3c);
}
