/*
 * function: func_021BC868
 * address: 0x021BC868
 * packet: pkt_ov099_021BC868
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020200CC 0x020200CC thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045770(void *);
extern u32 func_0201C6C4(void *, void *);
extern void func_02045334(void *);
extern int func_020200CC(void *);
extern void func_021BA8EC(char *);
extern void *func_021BA8BC(void *);
extern void func_0202020C(void *, u16 *, u16 *);
extern void func_0201F868(void *);
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
int func_021BC868(char *p, int v)
{
    int r;
    void *q;
    q = *(void **)(p + 0x1b8);
    if (*(u8 *)(p + 0x1b0) != 0) {
        if (func_0201C6C4(q, func_02045770(*(void **)(p + 0x1ac))) == 0) {
            func_02045334(*(void **)(p + 0x1ac));
            *(u8 *)(p + 0x1b0) = 0;
        }
    }
    r = func_020200CC(*(void **)(p + 0xbc));
    if (r == -1) return v;
    func_021BA8EC(p);
    *(void **)(p + 0x1a4) = func_021BA8BC(*(void **)(p + 0x1a4));
    func_0202020C(*(void **)(p + 0xbc), 0, (u16 *)(p + 0x234));
    func_0201F868(*(void **)(p + 0xb8));
    if (r == -2) {
        if (*(u32 *)(p + 0x135c) == 3 || *(u32 *)(p + 0x135c) == 4) {
            func_021BA874(p, *(u16 *)(p + 0x242) - 1);
            func_021BAAB8(p, 0x60, 0);
            *(u32 *)(p + 0x1cc) = 0x45;
        } else {
            *(u32 *)(p + 0x1cc) = 0x1c;
        }
    } else {
        if (*(u32 *)(p + 0x135c) == 3 || *(u32 *)(p + 0x135c) == 4) {
            *(u32 *)(p + 0x1cc) = r;
        } else if (r == 0x5b) {
            *(u32 *)(p + 0x1cc) = 0x75;
        } else {
            *(u32 *)(p + 0x1cc) = r;
        }
    }
    return v;
}
