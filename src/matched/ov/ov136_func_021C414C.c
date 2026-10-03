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
struct Sub02008F80Obj;
extern void func_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i);
extern void func_02008FC4(struct Sub02008F80Obj *obj, u16 value);
extern void func_02008FA8(struct Sub02008F80Obj *obj, u32 value);
void func_021C414C(void *a, u8 *p)
{
    u16 i;
    for (i = 0; i < 3; i++) func_02008FD8(a, p + 0x16 + i * 8, (u8)i);
    func_02008FC4(a, *(u16 *)(p + 0x32));
    func_02008FA8(a, p[0xB]);
}
