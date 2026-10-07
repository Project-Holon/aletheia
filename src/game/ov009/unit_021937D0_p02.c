/*
 * file:     unit_021937D0_p02.c
 * unit:     yes
 * function: func_02193BD8, func_02193BF0
 * address:  0x02193BD8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021ADFD0  0x021ADFD0  data
 *   g_021ADFD4  0x021ADFD4  data
 *   g_021ADFD8  0x021ADFD8  data
 */
char *func_02193BD8(int v);
char *func_02193BF0(int a, int b);
extern char g_021ADFD0[];
extern char g_021ADFD4[];
extern char g_021ADFD8[];


/*
 * Stores a word at +4 of the state object and returns the address of the next.
 */
char *func_02193BD8(int v)
{
    *(int *)(g_021ADFD0 + 4) = v;

    return g_021ADFD4;
}


/*
 * Stores two words at +8 and +0xc of the state object and returns +8 of it.
 */
char *func_02193BF0(int a, int b)
{
    *(int *)(g_021ADFD0 + 8) = a;
    *(int *)(g_021ADFD0 + 0xc) = b;

    return g_021ADFD8;
}
