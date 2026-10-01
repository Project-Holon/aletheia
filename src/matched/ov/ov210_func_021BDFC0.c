/*
 * function: func_021BDFC0
 * address: 0x021BDFC0
 * packet: pkt_ov210_021BDFC0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7AB0 0x021B7AB0 thumb ov067
 *   func_021BEDE0 0x021BEDE0 thumb ov210
 *   func_021BF728 0x021BF728 thumb ov210
 */
typedef unsigned char u8;
extern int func_021B7AB0(void *);
extern int func_021BEDE0(int, int);
extern void func_021BF728(u8 *, int);
int func_021BDFC0(u8 *p)
{
    switch (*(int *)(p + 20)) {
    case 0:
        if (func_021B7AB0(*(void **)(p + 0x1E0)) == -1)
            ++*(int *)(p + 20);
        break;
    case 1:
        if (p[0x2C1] != 57 && func_021BEDE0((int)p, p[0x2C1]) != 0)
            break;
        *(int *)(p + 20) = 0;
        func_021BF728(p, 0);
        return *(int *)(p + 24);
    }
    return 24;
}
