/*
 * file:     field_3dbg_p04.c
 * unit:     yes
 * function: func_021A1524, func_021A1530, func_021A153C, func_021A1548
 * address:  0x021A1524
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0058  0x021F0058  thumb  ov034
 *   func_021F00BC  0x021F00BC  thumb  ov034
 *   func_021F00F0  0x021F00F0  thumb  ov034
 *   func_021F0108  0x021F0108  thumb  ov034
 */
typedef unsigned int u32;

extern void func_021F0058(char *p);
extern void func_021F00BC(int *p);
extern int func_021F00F0(char *p);
extern void func_021F0108(int *p);
void func_021A1524(u32 *p);
void func_021A1530(u32 *p);
int func_021A153C(u32 *p);
void func_021A1548(u32 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021A1524(u32 *p)
{
    func_021F0058((char *)p[8]);
}


void func_021A1530(u32 *p)
{
    func_021F00BC((int *)p[8]);
}


int func_021A153C(u32 *p)
{
    return func_021F00F0((char *)p[8]);
}


/*
 * 2026-10-01: byte-correct; tail-call target is an unlabelled ov034 Thumb function (listing reads it as ARM), no witness.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1548(u32 *p)
{
    func_021F0108((int *)p[8]);
}
