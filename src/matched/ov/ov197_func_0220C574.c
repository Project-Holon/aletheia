/*
 * function: func_0220C574
 * address: 0x0220C574
 * packet: pkt_ov197_0220C574
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_0220BBD8 0x0220BBD8 thumb ov197
 *   func_0220C180 0x0220C180 thumb ov197
 *   func_0220C220 0x0220C220 thumb ov197
 *   func_0220C4D4 0x0220C4D4 thumb ov197
 *   func_0220C724 0x0220C724 thumb ov197
 *   func_0220C6F8 0x0220C6F8 thumb ov197
 *   d_0220DB88 0x0220DB88 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Pair { short x, y; };
extern const struct Pair d_0220DB88[];
extern unsigned func_0220BB98(const char *, unsigned);
extern unsigned func_0220BBD8(unsigned);
extern void func_0220C180(char *, unsigned, unsigned, unsigned);
extern void func_0220C220(char *, unsigned, unsigned);
extern void func_0220C4D4(int, int);
extern void func_0220C724(char *, u16, u8, u8, const struct Pair *);
extern void func_0220C6F8(u8 *, unsigned, unsigned);
void func_0220C574(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        unsigned item = func_0220BB98(p, i);
        if (item) {
            func_0220C180(p, item, i, i);
            func_0220C220(p, item, i);
            func_0220C4D4(*(int *)(p + i * 4 + 0x424), (int)&d_0220DB88[i]);
            if (*(int *)(*(char **)p + 8) == 1)
                func_0220C724(p, i * 8 + 7, func_0220BBD8(item), 0, &d_0220DB88[i + 6]);
        }
    }
    if (*(int *)(*(char **)p + 8) == 1)
        func_0220C724(p, 55, *(u8 *)(*(char **)p + 0x14), *(u8 *)(*(char **)p + 0x15), &d_0220DB88[i + 6]);
    if (*(int *)(*(char **)p + 8) == 2) func_0220C6F8((u8 *)p, 64, 16);
}
