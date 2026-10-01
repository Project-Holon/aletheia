/*
 * function: func_0220C5AC
 * address: 0x0220C5AC
 * packet: pkt_ov198_0220C5AC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045EC0(void *, u32);
extern u32 func_02045770(void *);
extern void func_0201C724(void *, u32, u16, u16, u32, u32, u16);
extern void func_02045808(void *);
void func_0220C5AC(char *p, int i, u16 x, u16 y)
{
    void *t;
    void *f;
    t = func_02045EC0(*(void **)(p + 0x1EA0), 0x14);
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, func_02045770(*(void **)(p + 0x1F70 + i * 8)), x, y, (u32)t, *(u32 *)(*(char **)p + 0xC), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}
