/*
 * function: func_021E13BC
 * address: 0x021E13BC
 * packet: pkt_ov137_021E13BC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E13A8 0x021E13A8 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *, int, unsigned);
extern void *func_02030DA8(void *, void (*)(void *, char *), void *, int);
extern void func_021E13A8(void *, char *);
void func_021E13BC(char *p)
{
    unsigned n = 8;
    func_02082BCC(p + 0xc88, 0, n);
    n += 251;
    *(void **)(p + 0xd8c) = func_02030DA8(*(void **)(p + 0xd98), func_021E13A8, p, n);
}
