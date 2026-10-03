/*
 * function: func_021DE02C
 * address: 0x021DE02C
 * packet: pkt_ov183_021DE02C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200DBA0 0x0200DBA0 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 */
typedef unsigned short u16;
extern int func_0200DBA0(void *, int, int);
extern void *func_0201296C(void *);
extern unsigned func_020142E8(void *, int);
int func_021DE02C(void *p, void *q)
{
    int a = func_0200DBA0(p, 5, 0);
    unsigned b = func_020142E8(func_0201296C(q), 0x960);
    if (a && b) return 1;
    return 0;
}
