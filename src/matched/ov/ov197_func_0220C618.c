/*
 * function: func_0220C618
 * address: 0x0220C618
 * packet: pkt_ov197_0220C618
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * caller-width: BB98 takes full signed short promotion; no u16 truncation in this caller.
 * symbols:
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_0220BBD8 0x0220BBD8 thumb ov197
 *   func_0220C180 0x0220C180 thumb ov197
 *   func_0220C4D4 0x0220C4D4 thumb ov197
 *   func_0220C724 0x0220C724 thumb ov197
 *   func_0220C6F8 0x0220C6F8 thumb ov197
 *   d_0220DB80 0x0220DB80 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Pair { short x, y; };
extern const struct Pair d_0220DB80[];
extern unsigned func_0220BB98(const char *, int);
typedef unsigned int   u32;
extern u16 func_0220BBD8(u32 key);
extern void func_0220C180(char *, unsigned, unsigned, unsigned);
extern void func_0220C4D4(int, int);
extern void func_0220C724(char *, u16, u8, u8, const struct Pair *);
extern void func_0220C6F8(u8 *, unsigned, unsigned);
void func_0220C618(char *p)
{
    unsigned item = func_0220BB98(p, *(short *)(*(char **)p + *(u8 *)(p + 0x533) * 2 + 0x30));
    func_0220C180(p, item, 6, 6);
    func_0220C4D4(*(int *)(p + 0x43c), (int)&d_0220DB80[0]);
    if (*(int *)(*(char **)p + 8) == 1)
        func_0220C724(p, 7, func_0220BBD8(item), 0, &d_0220DB80[1]);
    if (*(int *)(*(char **)p + 8) == 2) func_0220C6F8((u8 *)p, 0x68, 0x98);
}
