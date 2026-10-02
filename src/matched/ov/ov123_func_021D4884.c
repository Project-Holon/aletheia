/*
 * function: func_021D4884
 * address: 0x021D4884
 * packet: pkt_ov123_021D4884
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 02049990 arg5 is u16 at both original call-site truncations; 02049F78 arg3 is an unchanged address payload passed to 02062A98, whose body stores through it.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_021D43B8 0x021D43B8 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_021D478C 0x021D478C thumb ov123
 *   d_021DA9D0 0x021DA9D0 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DA9D0[];
extern void *func_020457B0(int, u16);
extern void *func_0201D7EC(int, int, int, int, u32);
extern void *func_02045B38(u32, u32, u16, u32);
extern void *func_020490F4(void *, u32);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void *func_02049F78(void *, int, void **, u16);
extern void func_02082D44(const void *, void *, u32);
extern void func_021D43B8(char *, const char *, int);
extern void func_020307B0(void *);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern u32 func_02049990(void *, u32, u32, u32, u16, u32, u32, u16);
extern void func_02049238(void *);
extern void *func_0201F5DC(void *, u32, u32, u32);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void *func_0204A6C8(void *, u32, u32, u32, u16);
extern void *func_0204AC18(void *, u32, u32, u32, u32, u32, u16);
extern void *func_0204AF28(void *, u32, u32, u16);
extern void func_021D478C(char *);
void func_021D4884(char *p)
{
    void *h;
    void *allocated;
    void *record;
    *(void **)(p + 0x38) = func_020457B0(300, *(u16 *)(p + 12));
    *(void **)(p + 0x30) = func_0201D7EC(23, 0, 0, 0, *(u16 *)(p + 12));
    *(void **)(p + 0x24) = func_02045B38(0, 2, 39, *(u16 *)(p + 12));
    *(void **)(p + 0x28) = func_02045B38(0, 2, 232, *(u16 *)(p + 12));
    h = func_020490F4((void *)29, *(u16 *)(p + 12));
    func_02049B68(h, 1, 4, 0, 0, *(u16 *)(p + 12));
    func_02049B68(h, 0, 0, 0, 0, *(u16 *)(p + 12));
    allocated = func_02049F78(h, 1, &record, *(u16 *)(p + 12));
    func_02082D44(*(void **)((char *)record + 12), p + 0x44, 0xe0);
    func_02082D44(*(void **)((char *)record + 12), p + 0x124, 0xe0);
    func_021D43B8(p + 0x124, d_021DA9D0, 7);
    func_020307B0(allocated);
    *(u32 *)(p + 0x40) = func_02049740(h, 4, 4, 0, 0, *(u16 *)(p + 12));
    func_02049990(h, 9, 4, 0, *(u32 *)(p + 0x40), 0, 0, *(u16 *)(p + 12));
    func_02049990(h, 14, 6, 0, *(u32 *)(p + 0x40), 0, 0, *(u16 *)(p + 12));
    func_02049238(h);
    *(void **)(p + 0x3c) = func_0201F5DC((void *)5, 12, 0, *(u16 *)(p + 12));
    func_02049B40(23, 5, 4, 0x1a0, 32, *(u16 *)(p + 12));
    h = func_020490F4((void *)29, *(u16 *)(p + 12));
    *(void **)(p + 0x294) = func_0204A6C8(h, 5, 0, 1, *(u16 *)(p + 12));
    *(void **)(p + 0x290) = func_0204AC18(h, 3, 1, 0, 0, 10, *(u16 *)(p + 12));
    *(void **)(p + 0x298) = func_0204AF28(h, 7, 16, *(u16 *)(p + 12));
    func_02049238(h);
    func_021D478C(p);
}
