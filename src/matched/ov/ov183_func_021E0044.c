/*
 * function: func_021E0044
 * address: 0x021E0044
 * packet: pkt_ov183_021E0044
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 */
typedef unsigned short u16;
extern void *func_0200CA1C(void *);
extern char *func_021FFBD4(void *, void *, int, int, int, int, int, u16);
extern void func_021FFE5C(char *);
extern unsigned func_021FFE34(char *p);
void func_021E0044(char *p, char *q)
{
    *(char **)(p + 0x1c) = func_021FFBD4(func_0200CA1C(*(void **)(q + 0x10)), *(void **)(q + 8), *(int *)(q + 4), *(int *)(p + 0x44), *(int *)q, *(int *)(p + 0x3c), *(int *)(p + 0x40), *(u16 *)(p + 0x54));
    func_021FFE5C(*(char **)(p + 0x1c));
    func_021FFE34(*(char **)(p + 0x1c));
}
