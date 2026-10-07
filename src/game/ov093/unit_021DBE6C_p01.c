/*
 * file:     unit_021DBE6C_p01.c
 * unit:     yes
 * function: func_021DBF28, func_021DBF58
 * address:  0x021DBF28
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
 *   func_021DBFD4 0x021DBFD4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern int func_021DBFD4(unsigned short);
extern void func_021D7704(int,int);
extern int func_021D76BC(int,unsigned int);
void func_021DBF28(int a,int b,int c);
void func_021DBF58(int a,int b,int c);

void func_021DBF28(int a,int b,int c) { if(c==func_021D775C(3) && func_021DBFD4(func_021D775C(0x12))) func_021D7704(0x31,0x14cd); }

void func_021DBF58(int a,int b,int c) { if(c==func_021D775C(3) && func_021DBFD4(func_021D775C(0x12))) func_021D76BC(0x41,1); }
