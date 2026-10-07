/*
 * file:     field_effect_p37.c
 * unit:     yes
 * function: func_021AB634, func_021AB650
 * address:  0x021AB634
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef struct {
    int pad[2];
    int f8;
    int fc;
    int f10;
    int f14;
} S;

void func_021AB634(S *s, int a, int b, int c);
void func_021AB650(S *s);


void func_021AB634(S *s, int a, int b, int c)
{
    func_021AB650(s);
    s->f8 = a;
    s->fc = c;
    s->f10 = b;
    s->f14 = -1;
}


void func_021AB650(S *s)
{
    s->f8 = 0;
    s->fc = 0;
    s->f10 = 0;
    s->f14 = -1;
}
