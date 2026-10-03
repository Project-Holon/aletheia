/*
 * unit: yes
 * function: func_021B9AA8, func_021B9AF8
 * address: 0x021B9AA8
 * packet: pkt_ov114_021B9AA8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled follower 021B9AF8 is the free callback tail-call stub.
 * symbols:
 * d_021CE31C 0x021CE31C data a2
 * d_021CE3B8 0x021CE3B8 data a4
 * d_021CE3A0 0x021CE3A0 data a4
 * func_02034714 0x02034714 arm
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
extern u16 d_021CE31C;
extern char d_021CE3B8[], d_021CE3A0[];
extern void func_02034714(const char *, unsigned int, const char *);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *);
void *func_021B9AA8(int n)
{
    void *p;
    if (d_021CE31C == 0xffff)
        func_02034714(d_021CE3B8, 0, d_021CE3B8);
    p = func_02030734(d_021CE31C, n, 0, d_021CE3A0, 0xe9);
    if (p == 0)
        func_02034714(d_021CE3B8, 0, d_021CE3B8);
    return p;
}
void func_021B9AF8(void *p)
{
    func_020307B0(p);
}
