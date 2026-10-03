/*
 * function: func_021BDEF0
 * address: 0x021BDEF0
 * packet: pkt_ov172_021BDEF0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct StrObj;
struct U16Vec;
extern void *func_02008510(void *a, int tag);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(u32 p);
extern void func_0201C724(u32 owner, void *b, short y, u32 c, void *d, u32 e, u32 f);
extern void func_02045808(struct U16Vec *vec);
void func_021BDEF0(u8 *p, char *a, u32 b)
{
    void *s;
    int x;
    s = func_02008510(a, *(u16 *)p);
    x = (0x60 - (u8)func_0201D304(s, *(u32 *)(p + 0x1c8), 0)) / 2;
    func_0201C724(*(u32 *)(p + 0x1d0), func_02045770(b), x + 1, 1, s, *(u32 *)(p + 0x1c8), 0x400);
    func_0201C724(*(u32 *)(p + 0x1d0), func_02045770(b), x - 1, 1, s, *(u32 *)(p + 0x1c8), 0x400);
    func_0201C724(*(u32 *)(p + 0x1d0), func_02045770(b), x, 2, s, *(u32 *)(p + 0x1c8), 0x400);
    func_0201C724(*(u32 *)(p + 0x1d0), func_02045770(b), x, 0, s, *(u32 *)(p + 0x1c8), 0x400);
    func_0201C724(*(u32 *)(p + 0x1d0), func_02045770(b), x, 1, s, *(u32 *)(p + 0x1c8), 0x3c00);
    func_02045808(s);
}
