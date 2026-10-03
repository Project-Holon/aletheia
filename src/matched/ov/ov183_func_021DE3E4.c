/*
 * function: func_021DE3E4
 * address: 0x021DE3E4
 * packet: pkt_ov183_021DE3E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 */
typedef unsigned short u16;
extern void *func_021FD12C(int, int, u16);
extern void func_021FD170(void *, int, int);
void func_021DE3E4(char *p, char *q)
{
    *(void **)(p + 8) = func_021FD12C(*(int *)(q + 8), *(int *)(p + 4), *(u16 *)(p + 0x6c));
    func_021FD170(*(void **)(p + 8), *(int *)(q + 8), 0x86);
}
