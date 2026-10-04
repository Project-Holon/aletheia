/*
 * function: func_021DD0AC
 * address: 0x021DD0AC
 * packet: pkt_ov183_021DD0AC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 */
typedef unsigned short u16;
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD860(int, int, int *);
void func_021DD0AC(char *p)
{
    if (!*(int *)(p + 0xe0)) {
        int args[2];
        *(int *)(p + 0xe0) = 1;
        if (!*(void **)(p + 0x18))
            *(void **)(p + 0x18) = func_021FD12C(*(int *)(*(char **)(p + 0xd0) + 0x10), (void *)(*(int *)(p + 4)), *(unsigned short *)(p + 0xb4));
        args[0] = 0x80;
        args[1] = 0x60;
        func_021FD860(*(int *)(p + 0xc), 4, args);
    }
}
