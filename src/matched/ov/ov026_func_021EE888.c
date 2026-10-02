/*
 * function: func_021EE888
 * address: 0x021EE888
 * packet: pkt_ov026_021EE888
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern int func_021A2248(u8 *, int);
extern void func_021A244C(u8 *, int *, int *);
typedef struct { char pad[0x774]; int *list; } Obj;
extern void func_021A2564(Obj *, int, int);

int func_021EE888(u8 *a, int b, int c)
{
    int x;
    int y;
    func_021A21B8((int *)a);
    func_021A2248(a, c);
    func_021A244C(a, &x, &y);
    func_021A2564((Obj *)a, x, y);
    return 0;
}
