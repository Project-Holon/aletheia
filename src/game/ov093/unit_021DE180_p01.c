/*
 * file:     unit_021DE180_p01.c
 * unit:     yes
 * function: func_021DE24C, func_021DE270
 * address:  0x021DE24C
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
 *   func_021DE228 0x021DE228 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5D68 0x021D5D68 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed char    s8;

extern int func_021D775C(int);
extern void func_021DE228(int, void *, int, int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5D68(s8 *p);
extern void func_021DD044(void *, void *, int);
void func_021DE24C(int a, void *b, int c, int d);
void func_021DE270(int a, void *b, int c);

/*
 * extent: two-byte alignment padding at 021DE26E.
 * interface: original restores r3 from r7 before calling 021DE228.
 */
void func_021DE24C(int a, void *b, int c, int d) { if (func_021D775C(12) != 6) func_021DE228(a,b,c,d); }

/*
 * extent: two-byte alignment padding at 021DE29E.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 */
void func_021DE270(int a, void *b, int c) { if(c == func_021D775C(2)) { if(func_021D5D68(func_021C7CF4(b,c))) func_021DD044((void *)a,b,c); } }
