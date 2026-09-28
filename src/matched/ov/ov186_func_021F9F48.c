/*
 * function: func_021F9F48
 * address:  0x021F9F48
 * packet:   pkt_021F9F48
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD714  0x021FD714  thumb  ov186
 *   func_021FD15C  0x021FD15C  thumb  ov186
 *   func_021FACE0  0x021FACE0  thumb  ov186
 *   func_021FC0C8  0x021FC0C8  thumb  ov186
 *   func_021FB63C  0x021FB63C  thumb  ov186
 *   func_020307B0  0x020307B0  arm
 *   func_02025588  0x02025588  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021FD714(u32 a);
extern void func_021FD15C(u32 a, u32 b);
extern void func_021FACE0(void *p);
extern void func_021FC0C8(u32 a, u32 b);
extern void func_021FB63C(u32 a);
extern void func_020307B0(void *p);
extern void func_02025588(u32 a);
extern void func_0201C4C0(u32 a);

void func_021F9F48(u8 *p)
{
    int i;

    func_021FD714(*(u32 *)(p + 0xc));
    if (*(u32 *)(p + 0x50) != 0) {
        func_021FD15C(*(u32 *)(p + 0x50), *(u32 *)(p + 4));
        *(u32 *)(p + 0x50) = 0;
    }
    for (i = 0; i < *(u8 *)(p + 0x3b); i++)
        func_021FACE0((u8 *)(*(u32 *)(p + 0x3c) + i * 0x44));
    func_020307B0((void *)*(u32 *)(p + 0x3c));
    for (i = 0; i < *(u8 *)(p + 0x39); i++)
        func_021FACE0((u8 *)(*(u32 *)(p + 0x40) + i * 0x44));
    func_020307B0((void *)*(u32 *)(p + 0x40));
    func_021FC0C8(*(u32 *)(p + 4), *(u32 *)(p + 0x10));
    func_021FC0C8(*(u32 *)(p + 4), *(u32 *)(p + 0x10) + 1);
    func_021FB63C(*(u32 *)(p + 0x44));
    func_02025588(*(u32 *)(p + 0x48));
    func_0201C4C0(*(u32 *)(p + 0x4c));
    func_020307B0(p);
}


