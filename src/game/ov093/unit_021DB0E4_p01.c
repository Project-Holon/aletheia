/*
 * file:     unit_021DB0E4_p01.c
 * unit:     yes
 * function: func_021DB1D4, func_021DB200
 * address:  0x021DB1D4
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
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021DB1A8 0x021DB1A8 thumb ov093
 *   func_021D7324 0x021D7324 thumb ov093
 */
struct QS;
typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_021D775C(int);
extern void func_021D7320(struct QS *p, u32 v);
extern int func_021DB1A8(int,int,int,int,unsigned short);
extern void func_021D7324(u8 *p);
void func_021DB1D4(char *a, int b, int c, int *d);
void func_021DB200(char *a, int b, int c, int *d);

/*
 * interface: func_021D7320 stores the full r1 payload unchanged at +12;
 * callback type records the observed pointer, with no arithmetic/narrowing.
 */
void func_021DB1D4(char *a, int b, int c, int *d) { if (c == func_021D775C(3) && *d == 0) { func_021D7320((struct QS *)a,(u32)func_021DB1A8); *d = 1; } }

void func_021DB200(char *a, int b, int c, int *d) { if (c == func_021D775C(2) && *d == 1) { func_021D7324((u8 *)a); *d = 0; } }
