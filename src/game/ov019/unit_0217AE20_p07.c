/*
 * file:     unit_0217AE20_p07.c
 * unit:     yes
 * function: func_0217BAF0, func_0217BB04, func_0217BB20
 * address:  0x0217BAF0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A2E44 0x021A2E44 thumb ov021
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0217B8E4 0x0217B8E4 thumb ov019
 */
extern void func_021A2E44(int, unsigned int);
extern unsigned int func_0200FB24(void);
extern int func_0217B8E4(char *p, int v);
void func_0217BAF0(char *p, int x, unsigned int v);
int func_0217BB04(char *p);
int func_0217BB20(char *p);

void func_0217BAF0(char *p, int x, unsigned int v)
{
    p[0x3563] = v;
    func_021A2E44(x, v);
}

int func_0217BB04(char *p)
{
    if (func_0200FB24() != 0) {
        func_0217B8E4(p, 1);
        return 1;
    }
    return 0;
}

int func_0217BB20(char *p)
{
    if (func_0217BB04(p) == 1) {
        func_0217B8E4(p, 50);
        return 1;
    }
    return 0;
}
