/*
 * file:     union_oneself_p15.c
 * unit:     yes
 * function: func_0217FABC, func_0217FACC
 * address:  0x0217FABC
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
 *   func_0217FA54 0x0217FA54 thumb ov019
 *   func_0216DA30 0x0216DA30 thumb ov010
 *   func_0217FA78 0x0217FA78 thumb ov019
 */
typedef unsigned int u32;

extern void func_0217FA54(u32 *p);
extern int func_0216DA30(int a0, int a1);
extern void func_0217FA78(u32 *p);
void func_0217FABC(u32 *p);
void func_0217FACC(u32 *p, int a1);

void func_0217FABC(u32 *p) { if (p[3] != 0) func_0217FA54(p); }

void func_0217FACC(u32 *p, int a1)
{
    if (p[3] != 0) {
        if (func_0216DA30(p[0], a1) == 1) func_0217FA78(p);
        else func_0217FA54(p);
    }
}
