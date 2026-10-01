/*
 * function: func_021F7B50
 * address: 0x021F7B50
 * packet: pkt_ov135_021F7B50
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F875C 0x021F875C thumb ov135
 */
typedef unsigned char u8;
extern void *func_021F875C(void *p, void *dst, void *win, void *bank, void *names, void *obj, void *ctx);
int func_021F7B50(u8 *p)
{
    *(void **)(p + 0xDF4) = func_021F875C(p, p + 0xDE8, *(void **)(p + 0xD54), *(void **)(p + 0xB6C), *(void **)(p + 0xB70), *(void **)(p + 0xE00), *(void **)(*(u8 **)p + 0x10));
    *(unsigned short *)(p + 0xBC) = 0xFFFF;
    *(unsigned *)(p + 0x28) = 6;
    return 2;
}
