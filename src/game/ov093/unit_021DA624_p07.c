/*
 * file:     unit_021DA624_p07.c
 * unit:     yes
 * function: func_021DAD2C, func_021DAD58
 * address:  0x021DAD2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 */
struct UtilWork;
extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BB0(struct UtilWork *,unsigned int);
void func_021DAD2C(int a, int b, int c, int *d);
void func_021DAD58(int a, int *b, int c, int *d);

void func_021DAD2C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) { if (*d != 0) { d[1] = func_021D76BC(34,19); *d = 0; } else *d = 1; } }

/*
 * interface: func_021C7CF4 uses its live r0 result and visibly loaded r1;
 * its own legacy file declares void and one parameter. Preserve this
 * caller's observed result and two-argument setup without editing callee.
 */
void func_021DAD58(int a, int *b, int c, int *d) { if (c == func_021D775C(2)) { if (func_021D5BB0(func_021C7CF4(b,c),0)) *d = 1; } }
