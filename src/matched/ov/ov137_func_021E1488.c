/*
 * function: func_021E1488
 * address: 0x021E1488
 * packet: pkt_ov137_021E1488
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E1468 0x021E1468 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *, int, unsigned);
extern void *func_02030DA8(void *, void (*)(void *, char *), void *, int);
extern void func_021E1468(void *, char *);
void func_021E1488(char *p)
{
    unsigned n = 80;
    func_02082BCC(p + 0xc90, 0, n);
    n += 180;
    *(void **)(p + 0xd90) = func_02030DA8(*(void **)(p + 0xd98), func_021E1468, p, n);
}
