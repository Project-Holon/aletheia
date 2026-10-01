/*
 * function: func_021FD550
 * address: 0x021FD550
 * packet: pkt_ov135_021FD550
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FD760 0x021FD760 thumb ov135
 *   func_021FD790 0x021FD790 thumb ov135
 *   func_021FD5F0 0x021FD5F0 thumb ov135
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern unsigned func_021F4D14(void *);
extern void func_021F4CE4(void *);
extern void func_021F4EC0(void *, u32, u32);
extern void func_021FD760(void *, void *, u32, void *, u16);
extern void func_021FD790(void *, void *, u32, void *);
extern void func_021FD5F0(void *);
extern void func_0201F7A8(void *, u32);
int func_021FD550(unsigned char *p)
{
    unsigned r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        *(int *)(p + 0x28) = 2;
        func_021F4EC0(p, 5, 6);
        func_021FD760(*(void **)(p + 0xb6c), p + 0xdc8, 0x53, p + 0xfa0, 0x440);
        func_021FD760(*(void **)(p + 0xb6c), p + 0xdb4, 0x57, p + 0xfa0, 0x3c40);
        func_021FD5F0(p);
    } else if (r == 2) {
        func_021F4CE4(p);
        func_0201F7A8(*(void **)(p + 0xd40), 0);
        *(int *)(p + 0x28) = 1;
        func_021FD790(*(void **)(p + 0xb6c), p + 0xd50, 0x5e, p + 0xfa0);
        func_021FD790(*(void **)(p + 0xb6c), p + 0xd54, 0x73, p + 0xfa0);
    }
    return 2;
}
