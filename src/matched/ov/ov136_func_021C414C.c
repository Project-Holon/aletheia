/*
 * function: func_021C414C
 * address:  0x021C414C
 * packet:   pkt_ov136_021C414C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C414C 0x021C414C thumb
 *   func_02008FD8 0x02008FD8 thumb
 *   func_02008FC4 0x02008FC4 thumb
 *   func_02008FA8 0x02008FA8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02008FD8(void *a, void *b, u32 c);
extern void func_02008FC4(void *a, u32 b);
extern void func_02008FA8(void *a, u32 b);
void func_021C414C(void *a, u8 *p)
{
    u16 i;
    for (i = 0; i < 3; i++) func_02008FD8(a, p + 0x16 + i * 8, (u8)i);
    func_02008FC4(a, *(u16 *)(p + 0x32));
    func_02008FA8(a, p[0xB]);
}
