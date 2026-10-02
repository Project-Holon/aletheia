/*
 * function: func_0215901C
 * address: 0x0215901C
 * packet: pkt_ov010_0215901C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows the 18-byte function.
 * Return stays full-width: the fallback id has no halfword truncation.
 * symbols:
 *   func_02158FE0 0x02158FE0 thumb ov010
 */
typedef unsigned short u16;
extern u16 *func_02158FE0(void *, void *, unsigned int);
unsigned int func_0215901C(void *a, void *b, unsigned int id)
{
    u16 *p = func_02158FE0(a, b, id);
    if (p) id = *p;
    return id;
}
