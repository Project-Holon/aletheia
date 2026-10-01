/*
 * function: func_021B657C
 * address: 0x021B657C
 * packet: pkt_ov172_021B657C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B65C4 0x021B65C4 thumb ov172
 *   func_020490A8 0x020490A8 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_02048F4C 0x02048F4C arm
 *   func_020862F0 0x020862F0 arm
 *   d_021C71C0 0x021C71C0 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B65C4(void *);
extern u32 func_020490A8(int, int);
extern void *func_0203D7C8(u16, u32, const void *, int);
extern void func_02048F4C(void *, int, int);
extern void func_020862F0(void *, u32);
extern const char d_021C71C0[];
void func_021B657C(char *obj, int mode)
{
    char *p = obj;
    int which = 0;
    u32 size;
    if (mode != 1) which = 1;
    func_021B65C4(p);
    which = (u16)which;
    size = func_020490A8(0xD4, which);
    *(u32 *)(p + 0x4C) = size;
    *(void **)(p + 0x48) = func_0203D7C8(*(u16 *)p, size, d_021C71C0, 0x13B);
    func_02048F4C(*(void **)(p + 0x48), 0xD4, which);
    func_020862F0(*(void **)(p + 0x48), *(u32 *)(p + 0x4C));
}
