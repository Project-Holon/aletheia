/*
 * function: func_0220558C
 * address: 0x0220558C
 * packet: pkt_ov094_0220558C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 022056B2..022056B4 is two-byte alignment padding.
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 lacks an outside witness at +010C.
 * Verified EXACT C copied from ov029_func_021F0DB4.c:
 * int func_02021728(char *p, int i) { return *(int *)(p + i * 0x14); }
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02021728 0x02021728 thumb
 *   func_020215BC 0x020215BC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0201EC64(int);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32, u32, u32);
extern void func_0201EFA4(u32, u32, u32, u32, u32, u32);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(int, short, int, void *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(int);
extern void *func_021F86E0(void);
extern int func_02021728(char *, int);
extern void func_020215BC(int, u16 *, int, int, u16);
void func_0220558C(char *s, const int *b)
{
    int h;
    void *v;
    void *w;
    void *extra;
    u8 c[3];
    h = func_0201EC64(*(u16 *)(s + 0x240));
    v = func_020457B0(8, *(u16 *)(s + 0x240));
    w = func_02045EC0(*(void **)(s + 0x5c), 6);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(9, 10, 0);
    func_0201EFA4(h, 0, b[2], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    func_0201C7A4(*(int *)(s + 0x22c), 0x8c, 8, v, *(int *)(s + 0x224));
    if (b[0] != b[1])
        func_0201DD78(7, 8, 0);
    func_0201EFA4(h, 0, b[1], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    func_0201C7A4(*(int *)(s + 0x22c), 0x60, 8, v, *(int *)(s + 0x224));
    func_0201DD78(1, 2, 0);
    extra = func_02045EC0(*(void **)(s + 0x5c), 7);
    func_0201C7A4(*(int *)(s + 0x22c), 0x7c, 8, extra, *(int *)(s + 0x224));
    func_02045808(extra);
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04(h);
    func_02045808(w);
    func_02045808(v);
    func_020215BC(*(int *)(s + 0x64), (u16 *)(func_02021728(func_021F86E0(), 1) + 0x40), 1, 0x70, 0x20);
}
