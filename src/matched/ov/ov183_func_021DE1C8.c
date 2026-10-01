/*
 * function: func_021DE1C8
 * address: 0x021DE1C8
 * packet: pkt_ov183_021DE1C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021DE3E4 0x021DE3E4 thumb ov183
 *   func_021DE7C0 0x021DE7C0 thumb ov183
 */
typedef unsigned short u16;
extern u16 func_021F9B9C(void *);
extern void *func_0203159C(void *, int, u16);
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_02025538(u16, void *);
extern void *func_0201C440(u16);
extern void *func_021FD760(void *, int, int, u16);
extern void func_021DE3E4(char *, char *);
extern void func_021DE7C0(char *, char *);
int func_021DE1C8(void *a, int b, char *q)
{
    char *p = func_0203159C(a, 0x70, func_021F9B9C(*(void **)(q + 0xC)));
    func_02082BCC(p, 0, 0x70);
    *(u16 *)(p + 0x6C) = func_021F9B9C(*(void **)(q + 0xC));
    *(void **)p = func_02025538(*(u16 *)(p + 0x6C), *(void **)q);
    *(void **)(p + 4) = func_0201C440(*(u16 *)(p + 0x6C));
    *(void **)(p + 0x64) = func_021FD760(*(void **)q, *(int *)(q + 8), 1, *(u16 *)(p + 0x6C));
    func_021DE3E4(p, q);
    func_021DE7C0(p, q);
    return 1;
}
