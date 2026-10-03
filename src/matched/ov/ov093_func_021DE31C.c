/*
 * function: func_021DE31C
 * address: 0x021DE31C
 * packet: pkt_ov093_021DE31C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 021DE34A.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D7E10 0x021D7E10 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int func_021D7E10(struct Unk021D62A8 *);
extern void func_021DD044(void *, void *, int);
void func_021DE31C(int a, void *b, int c) { if(c == func_021D775C(2)) { if(func_021D7E10(func_021C7CF4(b,c))) func_021DD044((void *)a,b,c); } }
