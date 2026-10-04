/*
 * function: func_021DB1D4
 * address: 0x021DB1D4
 * packet: pkt_ov093_021DB1D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021D7320 stores the full r1 payload unchanged at +12;
 * callback type records the observed pointer, with no arithmetic/narrowing.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021DB1A8 0x021DB1A8 thumb ov093
 */
extern int func_021D775C(int);
typedef unsigned int   u32;
struct QS;
extern void func_021D7320(struct QS *p, u32 v);
extern int func_021DB1A8(int,int,int,int,unsigned short);
void func_021DB1D4(char *a, int b, int c, int *d) { if (c == func_021D775C(3) && *d == 0) { func_021D7320((struct QS *)a,(u32)func_021DB1A8); *d = 1; } }
