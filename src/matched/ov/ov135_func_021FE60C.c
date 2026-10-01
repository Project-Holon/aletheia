/*
 * function: func_021FE60C
 * address: 0x021FE60C
 * packet: pkt_ov135_021FE60C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021FF4D0 0x021FF4D0 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 */
typedef unsigned int u32;
extern void func_021FF318(void *, int, int, int, int);
extern int func_021FF4D0(void *, void *, u32, u32);
extern void func_021F4E98(void *, u32, u32);
extern void func_021FFBC8(void *);
extern void func_020061E4(u32);
int func_021FE60C(unsigned char *p)
{
    if (*(short *)(p + 0xb56) == 0) {
        func_021FF318(p, 12, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 1);
    } else {
        if (func_021FF4D0(p + 0xb56, p + 0xb5c, *(u32 *)(p + 0xf84), *(u32 *)(p + 0xb64))) {
            func_021FF318(p, 39, 1, 0, 0xf0f);
            func_021F4E98(p, 23, 1);
        } else {
            func_020061E4(0x63f);
            *(int *)(p + 0x12e8) = 0x76;
            func_021FF318(p, 13, 1, 0, 0xf0f);
            func_021F4E98(p, 23, 17);
            if (*(int *)(p + 0xd0) > 0)
                func_021FFBC8(p);
        }
    }
    return 2;
}
