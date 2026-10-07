/*
 * file:     zknsearch_main_p04.c
 * unit:     yes
 * function: func_021BF480, func_021BF4A4, func_021BF500
 * address:  0x021BF480
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 */
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
void func_021BF480(int p);
void func_021BF4A4(char *p);
void func_021BF500(char *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021BF480(int p)
{
    func_021BEDF0(p, 3, 0);
    func_021BEDF0(p, 4, 0);
    func_021BEDF0(p, 2, 1);
}

void func_021BF4A4(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
}

void func_021BF500(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
}
