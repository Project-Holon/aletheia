/*
 * function: func_021EBBC8
 * address: 0x021EBBC8
 * packet: pkt_ov170_021EBBC8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_0201EF14 0x0201EF14 thumb
 *   func_021EBA84 0x021EBA84 thumb ov170
 * The image leaves the message undefined for kinds above six.
 */
extern int func_021DD2D0(void ***p, int a, unsigned b);
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
extern void func_021EBA84(unsigned char *, int, int);
void func_021EBBC8(unsigned char *p, unsigned kind, int i)
{
    int msg;
    switch (kind) {
    case 0: msg = 2; break;
    case 1: msg = 3;
        func_0201EF14(*(void **)(*(char **)(p + 0x2c) + 0x84), 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 2: msg = 4;
        func_0201EF14(*(void **)(*(char **)(p + 0x2c) + 0x84), 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 3: msg = 0x1c; break;
    case 4: msg = 0x1d;
        func_0201EF14(*(void **)(*(char **)(p + 0x2c) + 0x84), 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 5: msg = 0x1e; break;
    case 6: msg = 6; break;
    }
    func_021EBA84(p, msg, i);
}
