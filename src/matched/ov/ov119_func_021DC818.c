/*
 * function: func_021DC818
 * address: 0x021DC818
 * packet: pkt_ov119_021DC818
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 */
extern void func_02005E9C(void);
extern void func_02005DE4(int);
extern void func_02005DF8(int);
void func_021DC818(char *p)
{
    switch (*(unsigned char *)(p + 0x11F8)) {
    case 0:
        break;
    case 2:
        func_02005E9C();
        func_02005DE4(0);
    case 1:
        func_02005E9C();
        func_02005DE4(0);
        func_02005DF8(30);
    }
    *(unsigned char *)(p + 0x11F8) = 0;
}
