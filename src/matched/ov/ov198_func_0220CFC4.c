/*
 * function: func_0220CFC4
 * address: 0x0220CFC4
 * packet: pkt_ov198_0220CFC4
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
extern int func_022110D4(u8 *, int);
extern void *func_02045B38(u32, u32, u32, u32);
extern void func_02045C04(void *);
void func_0220CFC4(char *p, int index)
{
    char *elem;
    void *bank;
    void *t;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    bank = func_02045B38(0, 2, 0xB7, *(u16 *)(*(char **)p + 16));
    t = func_02045EC0(bank, *(u16 *)(elem + 0x18));
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, func_02045770(*(void **)(p + 0x1F80)), 0, 0, (u32)t, *(u32 *)(*(char **)p + 12), 0x2120);
    *(u8 *)(p + 0x1F84) = 1;
    func_02045808(t);
    func_02045C04(bank);
}
