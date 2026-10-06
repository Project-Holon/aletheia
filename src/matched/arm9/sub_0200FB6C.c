/*
 * function: sub_0200FB6C
 * address:  0x0200FB6C
 * packet:   pkt_0200F83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0200F7B8  0x0200F7B8  thumb
 *   g_021461BC     0x021461BC  data
 *
 * Teardown for the module object at 0x0214617C (same object as
 * sub_0200FB24.c and sub_0200FB38): frees its three owned pointers, frees
 * pool id 8, marks offset 0x19 of a second object at 0x021461BC (which is
 * numerically 0x0214617C + 0x40, but the original loads it through its
 * own fresh literal-pool word rather than as an offset off r4, so the two
 * are declared as separate objects here to keep the same register/pool
 * shape) and forwards flag 1 to func_0200F7B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200FB6C.c \
 *       --func sub_0200FB6C --addr 0x0200FB6C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub0200FB6CObj {
    void *unk00;
    void *unk04;
    void *unk08;
};

extern u32 func_020307B0(void *p);
extern void func_020306F0(u32 id);
extern u32 func_0200F7B8(u32 a0);
extern u8   g_021461BC[0x1A];

void sub_0200FB6C(void)
{
    struct Sub0200FB6CObj *obj = (struct Sub0200FB6CObj *)0x0214617C;

    func_020307B0(obj->unk00);
    func_020307B0(obj->unk04);
    func_020307B0(obj->unk08);
    func_020306F0(8);

    g_021461BC[0x19] = 0x60;

    func_0200F7B8(1);
}
