/*
 * file:     unit_0689C888_p02.c
 * unit:     yes
 * function: func_0689C91C, func_0689C93C, func_0689C944, func_0689C954, func_0689C974
 * address:  0x0689C91C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C888 0x0689C888 thumb ov095
 *   d_0689E2E6 0x0689E2E6 data a2
 *   d_0689E2A4 0x0689E2A4 data a2
 */
extern int func_0689C888(unsigned a, unsigned short *b, unsigned n);
int func_0689C91C(unsigned a);
int func_0689C93C(unsigned a);
int func_0689C944(unsigned a);
int func_0689C954(unsigned a);
int func_0689C974(int a);
extern unsigned short d_0689E2E6[];
extern unsigned short d_0689E2A4[];

int func_0689C91C(unsigned a)
{
    if (func_0689C974(a)) return 1;
    return func_0689C888(a, d_0689E2E6, 8);
}

int func_0689C93C(unsigned a) { return func_0689C944(a); }


int func_0689C944(unsigned a)
{
    if (a == 25) return 0;
    return func_0689C91C(a);
}


int func_0689C954(unsigned a)
{
    if (func_0689C974(a)) return 1;
    return func_0689C888(a, d_0689E2A4, 3);
}


int func_0689C974(int a)
{
    return a == 0x79;
}
