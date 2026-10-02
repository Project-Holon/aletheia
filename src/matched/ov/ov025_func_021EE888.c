/*
 * function: func_021EE888
 * address: 0x021EE888
 * packet: pkt_ov025_021EE888
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021EE8AE.
 * symbols:
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 */
typedef unsigned char u8;
typedef struct { char pad[0x774]; int *list; } Obj;
extern int func_021A2248(u8 *, int);
extern void func_021A244C(u8 *, int *, int *);
extern void func_021A2564(Obj *, int, int);
int func_021EE888(u8 *p, int unused, int arg)
{
    int x;
    int y;
    func_021A2248(p, arg);
    func_021A244C(p, &x, &y);
    func_021A2564((Obj *)p, x, y);
    return 0;
}
