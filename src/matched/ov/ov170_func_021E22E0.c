/*
 * function: func_021E22E0
 * address: 0x021E22E0
 * packet: pkt_ov170_021E22E0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021EBCB4 0x021EBCB4 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 */
extern void func_020307B0(void *);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021EBC58(unsigned char *, int, int, int);
int func_021E22E0(unsigned char *p)
{
    func_020307B0(*(void **)(*(char **)(p + 0x2C) + 0x60));
    if ((*(unsigned char **)(p + 0x2C))[0xA172] == 1) {
        if (*(int *)(*(char **)p + 0x24) == 3) {
            if (*(unsigned short *)(*(char **)(p + 0x2C) + 0xA16C) == 0)
                func_021EBCB4(p, 0, 0x18);
            else
                func_021EBCB4(p, 1, 0x18);
        } else {
            func_021EBC58(p, p[0x16], 1, 0x18);
        }
        (*(char **)(p + 0x2C))[0xA172] = 0;
    }
    return *(int *)(p + 0x28);
}
