/*
 * function: func_021BD1C8
 * address: 0x021BD1C8
 * packet: pkt_ov209_021BD1C8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: repeated decrement in each arm cross-jumps through branch stubs; explicit shared goto costs DIFF81/156.
 * symbols:
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021B9280 0x021B9280 thumb ov067
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
extern int func_021B93B0(char *);
extern void func_021B9280(char *, unsigned short, unsigned);
extern void func_02041B6C(unsigned);
int func_021BD1C8(char *p)
{
    switch (*(u8 *)(p + 0xc26)) {
    case 0:
    case 2:
        if (*(u8 *)(p + 0xc27) == 0) {
            func_021B9280(*(char **)(p + 0xc2c), func_021B93B0(*(char **)(p + 0xc2c)), 1);
            *(u8 *)(p + 0xc27) = 4;
            (*(u8 *)(p + 0xc26))++;
        } else (*(u8 *)(p + 0xc27))--;
        break;
    case 1:
    case 3:
        if (*(u8 *)(p + 0xc27) == 0) {
            func_021B9280(*(char **)(p + 0xc2c), func_021B93B0(*(char **)(p + 0xc2c)), 2);
            func_02041B6C(2);
            *(u8 *)(p + 0xc27) = 4;
            (*(u8 *)(p + 0xc26))++;
        } else (*(u8 *)(p + 0xc27))--;
        break;
    case 4:
        if (*(u8 *)(p + 0xc27) == 0) {
            *(u8 *)(p + 0xc26) = 0;
            return 8;
        }
        (*(u8 *)(p + 0xc27))--;
        break;
    }
    return 7;
}
