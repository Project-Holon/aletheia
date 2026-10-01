/*
 * function: func_021F6B7C
 * address: 0x021F6B7C
 * packet: pkt_ov097_021F6B7C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Named monster base/index and byte gender if/else retain the original scheduling; inline print helpers retain owner spills.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045738 0x02045738 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_0201D304 0x0201D304 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *func_020457B0(u32, u32);
extern void *func_02045EC0(void *, u32);
extern void *func_02045770(void *);
extern u8 func_02045738(void *);
extern void func_02045808(void *);
extern void func_0201EEF4(void *, u32, void *);
extern void func_0201F250(void *, void *, void *);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_02017E1C(void *, u32, u32);
extern u8 func_02017F00(void *);
extern u32 func_0201D304(void *, u32, u32);
static inline void print_text(int p, u32 windows, u32 dirty, int i, void *s, int x, int y, u16 color)
{
    void *owner = *(void **)(p + 0x1c);
    func_0201C724(owner, (u32)func_02045770(*(void **)(windows + i * 8)), x, y, (u32)s, *(u32 *)(p + 0xc), color);
    *(u8 *)(dirty + i * 8) = 1;
}
static inline void print_right(int p, u32 windows, u32 dirty, int i, void *window, u32 id, u16 color)
{
    void *s = func_02045EC0(*(void **)(p + 0x14), id);
    u32 font = *(u32 *)(p + 0xc);
    u32 w = func_02045738(window);
    s16 x = (s16)(w * 8 - func_0201D304(s, *(u32 *)(p + 0xc), 0));
    void *owner = *(void **)(p + 0x1c);
    func_0201C724(owner, (u32)func_02045770(*(void **)(windows + i * 8)), x, 7, (u32)s, font, color);
    *(u8 *)(dirty + i * 8) = 1;
    func_02045808(s);
}
void func_021F6B7C(int p, int i)
{
    u32 windows, dirty, mons, mi;
    u8 gender;
    void *window, *t, *s;
    windows = p;
    windows = p + 0x20;
    window = *(void **)(windows + i * 8);
    t = func_020457B0(0xc, 0x8071);
    s = func_02045EC0(*(void **)(p + 0x14), 0);
    mons = p + 0xf8;
    mi = i * 4;
    func_0201EEF4(*(void **)(p + 0x18), 0, *(void **)(mons + mi));
    func_0201F250(*(void **)(p + 0x18), t, s);
    dirty = p;
    dirty = p + 0x24;
    print_text(p, windows, dirty, i, t, 0x20, 7, 0x3dc0);
    func_02045808(s);
    func_02045808(t);
    if (func_02017E1C(*(void **)(mons + mi), 0xad, 0) == 1 &&
        func_02017E1C(*(void **)(mons + mi), 0x4c, 0) == 0) {
        gender = func_02017F00(*(void **)(mons + mi));
        if (gender == 0) print_right(p, windows, dirty, i, window, 0x16, 0x2960);
        else if (gender == 1) print_right(p, windows, dirty, i, window, 0x17, 0x31a0);
    }
}
