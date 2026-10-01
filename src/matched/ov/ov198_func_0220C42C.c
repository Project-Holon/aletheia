/*
 * function: func_0220C42C
 * address: 0x0220C42C
 * packet: pkt_ov198_0220C42C
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
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_020457B0 0x020457B0 arm
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *func_02045EC0(void *, u32);
extern u32 func_02045770(void *);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern void func_02045808(void *);
extern int func_022110D4(u8 *, int);
extern u32 func_020457B0(u32, u32);
extern void func_0201EF40(void *, u32, u32);
extern void func_0201F250(void *, u32, void *);
void func_0220C42C(char *p, int i, int index)
{
    char *elem;
    void *t;
    void *format;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    if (*(u16 *)(elem + 0x1A) == 0)
        t = func_02045EC0(*(void **)(p + 0x1EA0), 0x1E);
    else {
        t = (void *)func_020457B0(0x12, *(u16 *)(*(char **)p + 16));
        format = func_02045EC0(*(void **)(p + 0x1EA0), 15);
        func_0201EF40(*(void **)(p + 0x1EA4), 0, *(u16 *)(elem + 0x1A));
        func_0201F250(*(void **)(p + 0x1EA4), (u32)t, format);
        func_02045808(format);
    }
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, *(u32 *)(*(char **)p + 12), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}
