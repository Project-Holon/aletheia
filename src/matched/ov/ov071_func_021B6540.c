/*
 * function: func_021B6540
 * address:  0x021B6540
 * packet:   pkt_ov071_021B6540
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 */

typedef unsigned int   u32;
struct Obj02021EE4;
struct PalAnmSlot;
void func_021B6540(int *p)
{
    void *func_02021518(u32 heap);
    void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
    void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);

    *p = (int)func_02021518(0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 2, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 3, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 0, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 1, 0x1c0, 0x61);
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)(*p), 1);
}
