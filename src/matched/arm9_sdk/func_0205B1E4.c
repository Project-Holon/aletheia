/*
 * function: func_0205B1E4
 * address:  0x0205B1E4
 * packet:   pkt_0205B1E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_CloseNetwork (close.o)
 *
 * symbols:
 *   func_0205B264 0x0205B264 arm
 *   func_0217AA20 0x0217AA20 arm
 *   func_0217A950 0x0217A950 arm
 *   func_0205B2F8 0x0205B2F8 arm
 */

extern int func_0205B264(void);
extern void func_0217AA20(void);
extern void func_0217A950(void);
extern int func_0205B2F8(void);

int func_0205B1E4(unsigned char *phase)
{
    int result;

    if (*phase <= 10) {
        result = func_0205B264();
        if (result == 1) {
            *phase = 0;
            return 1;
        } else if (result == -1) {
            *phase = 0x12;
            return 1;
        }
    } else if (*phase == 14) {
        func_0217AA20();
        func_0217A950();
        *phase = 12;
    } else if (*phase < 0x12) {
        if (func_0205B2F8() == 1)
            *phase = 10;
    }
    return 0;
}
