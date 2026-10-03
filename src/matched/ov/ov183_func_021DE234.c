/*
 * function: func_021DE234
 * address: 0x021DE234
 * packet: pkt_ov183_021DE234
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE780 0x021DE780 thumb ov183
 *   func_021DE8FC 0x021DE8FC thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02025588 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 */
extern void func_021DE780(char *, char *);
extern void func_021DE8FC(char *, char *);
typedef unsigned int   u32;
struct PrintSys;
struct S020315D4;
extern void func_020409B4(u32 index);
extern void func_021FD820(char *r5);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02025588(void *);
extern void func_020315D4(struct S020315D4 *p);
int func_021DE234(void *a, int b, char *q, char *p)
{
    func_021DE780(p, q);
    func_021DE8FC(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FD820(*(void **)(p + 0x64));
    func_0201C4C0(*(void **)(p + 4));
    func_02025588(*(void **)p);
    func_020315D4(a);
    return 1;
}
