/*
 * function: func_021DD1D4
 * address: 0x021DD1D4
 * packet: pkt_ov183_021DD1D4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 zero alignment bytes at 0x021DD226
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_020409B4(unsigned int);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD15C(void *, int);
void func_021DD1D4(char *p, char *q)
{
    int i;
    char *slot;
    if (*(int *)(p + 0xe4)) {
        for (i = 0; i < 2; i++) {
            slot = p + i * 4;
            if (*(void **)(slot + 0x28)) {
                func_021FC734(*(void **)(slot + 0x28));
                *(int *)(slot + 0x28) = 0;
            }
        }
        func_020409B4(4);
        func_021FBDA4(*(int *)(q + 0x10), 30);
        if (*(void **)(p + 0x18)) {
            func_021FD15C(*(void **)(p + 0x18), *(int *)(q + 0x10));
            *(int *)(p + 0x18) = 0;
        }
        *(int *)(p + 0xe4) = 0;
    }
}
