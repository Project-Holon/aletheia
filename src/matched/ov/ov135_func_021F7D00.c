/*
 * function: func_021F7D00
 * address: 0x021F7D00
 * packet: pkt_ov135_021F7D00
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 */
typedef unsigned char u8;
extern int func_021F99F0(void *p);
extern void func_0201F7A8(void *p, unsigned kind);
typedef unsigned int   u32;
extern void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
int func_021F7D00(u8 *p)
{
    unsigned result = func_021F99F0(*(void **)(p + 0xDE4));
    switch (result) {
    case (unsigned)-2:
        func_0201F7A8(*(void **)(p + 0xD40), 0);
        *(unsigned *)(p + 0x28) = 0;
        break;
    case 0: case 1: case 2:
        *(signed char *)(p + 0xB52) = result + 1;
        *(unsigned *)(p + 0x28) = 10;
        func_021F81C8(*(void **)(p + 0xB6C), *(void **)(p + 0xB70), (int)(*(void **)(p + 0xB68)), p + 0xD90, *(short *)(p + 0xB50), *(signed char *)(p + 0xB52), -1, p + 0xFA0);
        break;
    }
    return 2;
}
