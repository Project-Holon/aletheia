/*
 * file:     unit_021D7908.c
 * unit:     yes
 * function: func_021D7908, func_021D7930
 * address:  0x021D7908
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
 *   d_021F0462 0x021F0462 data a1
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021F041C 0x021F041C data a1
 *   func_021D78AC 0x021D78AC thumb ov093
 */
extern int _s32_div_f(int, int);
extern unsigned int func_021D78AC(unsigned int);
unsigned char func_021D7908(int a, int i);
int func_021D7930(int i);
extern unsigned char d_021F0462[][2];
extern unsigned char d_021F041C[];

unsigned char func_021D7908(int a, int i) { unsigned int v = _s32_div_f(a*d_021F0462[i][0], d_021F0462[i][1]); if(v>100) v=100; return v; }

int func_021D7930(int i) { if ((unsigned char)func_021D78AC(d_021F041C[i]) == 0) return 1; return 0; }
