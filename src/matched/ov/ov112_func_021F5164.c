/*
 * function: func_021F5164
 * address: 0x021F5164
 * packet: pkt_ov112_021F5164
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   d_021F83C4 0x021F83C4 data a1
 *   func_021F55F8 0x021F55F8 thumb ov112
 *   func_021F621C 0x021F621C thumb ov112
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern const char d_021F83C4[];
extern void *func_021F55F8(int, u32);
extern void func_021F621C(void *);
void *func_021F5164(u32 heap)
{
    int i;
    char *p;
    p = sub_02030734(heap, 4456, 0, d_021F83C4, 76);
    *(u16 *)p = heap;
    *(void **)(p + 4) = func_021F55F8(8, heap);
    for (i = 0; i < 8; i++) *(u32 *)(p + i * 556 + 8) = 0;
    func_021F621C(*(void **)(p + 4));
    return p;
}
