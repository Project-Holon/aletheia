/*
 * function: func_02158FE0
 * address: 0x02158FE0
 * packet: pkt_ov010_02158FE0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201296C 0x0201296C thumb
 *   func_020143CC 0x020143CC thumb
 *   func_02158FD0 0x02158FD0 thumb ov010
 */
typedef unsigned short u16;
extern void *func_0201296C(void *);
extern unsigned int func_020143CC(unsigned int, unsigned int);
extern u16 *func_02158FD0(void *, unsigned int);
u16 *func_02158FE0(void *a, void *b, unsigned int id)
{
    void *p = func_0201296C(b);
    if (id < 0x4000) return 0;
    if (id < 0x8000) return (u16 *)func_020143CC((unsigned int)p, id);
    if (id < 0xc000) return func_02158FD0(a, id);
    return 0;
}
