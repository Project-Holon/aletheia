/*
 * function: func_021EECD8
 * address: 0x021EECD8
 * packet: pkt_ov026_021EECD8
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021EF9D8 0x021EF9D8 thumb ov026
 *   func_021EEF0C 0x021EEF0C thumb ov026
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern int func_021A2248(u8 *, int);
extern void func_021EF9D8(void *, int);
extern void func_021EEF0C(int, int *);

int func_021EECD8(u8 *a, int b, int c)
{
    int *p;
    p = func_021A21B8((int *)a);
    p[2] = (p[2] + 1) % 300;
    func_021A2248(a, c);
    func_021EF9D8(p + 3, (int)a);
    func_021EEF0C((int)a, p);
    return 0;
}
