/*
 * function: func_021DE228
 * address: 0x021DE228
 * packet: pkt_ov093_021DE228
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5D68 0x021D5D68 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char    s8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5D68(s8 *p);
extern void func_021DD044(void *, void *, int);
void func_021DE228(int a, void *b, int c) { if (func_021D5D68(func_021C7CF4(b,c))) func_021DD044((void *)a,b,c); }
