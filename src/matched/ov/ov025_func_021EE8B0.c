/*
 * function: func_021EE8B0
 * address: 0x021EE8B0
 * packet: pkt_ov025_021EE8B0
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 */
typedef unsigned char u8;
typedef struct { char pad[0x774]; int *list; } Obj;
extern int *func_021A21B8(int *);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021A244C(u8 *, int *, int *);
extern void func_021A2564(Obj *, int, int);
int func_021EE8B0(u8 *a)
{
    int *p;
    int x;
    int y;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 18, 3, -1);
    *p = 16;
    func_021A244C(a, &x, &y);
    func_021A2564((Obj *)a, x, y);
    return 1;
}
