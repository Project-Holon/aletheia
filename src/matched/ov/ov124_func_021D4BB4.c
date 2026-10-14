/*
 * function: CG_HELP_ProcMain
 * address:  0x021D4BB4
 * packet:   pkt_021D4BB4
 * region:   ov124
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CG_HELP_Main  0x021D42A0  thumb ov124
 *   func_0200FB24  0x0200FB24  thumb
 */

typedef struct Struct021D4BB4 {
    char pad[8];
    int  f8;
    int  fC;
    int  f10;
} Struct021D4BB4;

int CG_HELP_Main(char *p);
typedef unsigned int   u32;
u32 func_0200FB24(void);

int CG_HELP_ProcMain(int a, int b, int c, Struct021D4BB4 *p)
{
    int r;

    (void)a; (void)b; (void)c;
    r = CG_HELP_Main((char *)p);
    if (func_0200FB24() != 0 && p->f8 == 0) {
        p->f8 = 1;
        p->f10 = 2;
    }
    return r == 1;
}
