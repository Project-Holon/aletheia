/*
 * function: func_021FC528
 * address: 0x021FC528
 * packet: pkt_ov135_021FC528
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 */
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_021FC528(char *p)
{
    int i;
    *(void **)(p + 0xb88) = func_020457B0(0xb4, 0x48);
    *(void **)(p + 0xb8c) = func_02045EC0(*(void **)(p + 0xb6c), 0x2d);
    for (i = 0; i < 10; i++) {
        *(void **)(p + i * 4 + 0xb90) = func_020457B0(0x14, 0x48);
    }
}
