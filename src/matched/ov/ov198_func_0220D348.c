/*
 * function: func_0220D348
 * address: 0x0220D348
 * packet: pkt_ov198_0220D348
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
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *func_02045EC0(void *, u32);
extern u32 func_02045770(void *);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern void func_02045808(void *);
extern void *func_02045B38(u32, u32, u32, u32);
extern void func_02045C04(void *);
void func_0220D348(char *p, int i, int id)
{
    void *bank;
    void *t;
    void *f;
    bank = func_02045B38(0, 2, 0xCA, *(u16 *)(*(char **)p + 16));
    t = func_02045EC0(bank, id);
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, *(u32 *)(*(char **)p + 12), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
    func_02045C04(bank);
}
