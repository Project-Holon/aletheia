/*
 * function: func_021BFAE4
 * address: 0x021BFAE4
 * packet: pkt_ov203_021BFAE4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BFB12 rereads byte just incremented at 021BFB10.
 * symbols:
 *   func_021BE620 0x021BE620 thumb ov203
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021C3BD0 0x021C3BD0 data a2
 */
struct Obj; struct Vec2 { short x, y; };
extern int func_021BE620(void *);
extern void func_0204B404(struct Obj *, const struct Vec2 *, unsigned);
extern void func_0204B3DC(struct Obj *, unsigned);
extern const struct Vec2 d_021C3BD0[];
void func_021BFAE4(char *p)
{
    unsigned char *a = *(unsigned char **)(p + 0x10);
    int progress = func_021BE620(*(void **)(p + 8)) >> 12;
    if (*a < 54 && *a * 100 <= progress) {
        func_0204B404(*(struct Obj **)(a + 0x14), d_021C3BD0 + *a, 1);
        ++*a;
        if (*(volatile unsigned char *)a == 54)
            func_0204B3DC(*(struct Obj **)(a + 0x14), 0);
    }
}
