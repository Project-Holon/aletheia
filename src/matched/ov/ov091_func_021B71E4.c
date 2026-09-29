/*
 * function: func_021B71E4
 * address:  0x021B71E4
 * packet:   pkt_ov091_021B71E4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201C450  0x0201C450  thumb
 *   func_0201DD68  0x0201DD68  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u16 heap);
extern void *func_02045B38(u32 a, u32 b, u32 c, u16 heap);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern void *func_0201C450(u32 a, u16 heap);
extern void func_0201DD68(void);

void func_021B71E4(char *p)
{
    *(void **)(p + 0x138) = func_0201D7EC(0x17, 0, 0, 0, *(u16 *)p);
    *(void **)(p + 0x13c) = func_0201D7EC(0x17, 3, 0, 0, *(u16 *)p);
    *(void **)(p + 0x134) = func_02045B38(0, 2, 0x9d, *(u16 *)p);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, *(u16 *)p);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, *(u16 *)p);
    *(void **)(p + 0x140) = func_0201C450(0x1800, *(u16 *)p);
    func_0201DD68();
}
