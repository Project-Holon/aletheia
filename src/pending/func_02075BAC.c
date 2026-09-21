/*
 * function: func_02075BAC
 * address:  0x02075BAC
 * packet:   pkt_02075BAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (20 concrete bytes out)
 *
 * symbols:
 *   func_02075BD4  0x02075BD4  arm
 */

typedef struct Struct_02075BAC {
    int f0;
    int f4;
    int f8;
    int fc;
} Struct_02075BAC;

extern int func_02075BD4(void);

int func_02075BAC(Struct_02075BAC *out, int a1, int a2)
{
    out->f0 = func_02075BD4();
    out->f4 = a1;
    out->fc = a2;
    out->f8 = 0;
    return 0;
}
