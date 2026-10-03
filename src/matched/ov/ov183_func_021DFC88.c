/*
 * function: func_021DFC88
 * address: 0x021DFC88
 * packet: pkt_ov183_021DFC88
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 */
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_020409B4(unsigned int);
extern void func_021FBDA4(int a, unsigned mode);
int func_021DFC88(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(void **)(p + i * 4) != 0) {
            func_021FC734(*(void **)(p + i * 4));
            *(void **)(p + i * 4) = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(void **)(p + i * 4 + 12) != 0) {
            func_021FB494(*(void **)(p + i * 4 + 12));
            *(void **)(p + i * 4 + 12) = 0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(*(int *)(q + 8), 26);
    return 1;
}
