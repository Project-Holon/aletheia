/*
 * function: func_021DCDB8
 * address:  0x021DCDB8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Allocate 76 bytes, keep the handle, then configure it.
 */

typedef unsigned int   u32;
struct PalAnmSlot;
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

void func_021DCDB8(char *p)
{
    int v = (int)func_02021518(0x4c);

    *(int *)(*(char **)(p + 0x2c) + 0x6c) = v;
    func_0202155C((struct PalAnmSlot *)(*(int *)(*(char **)(p + 0x2c) + 0x6c)), 0, 0x200, 0x4c);
}

