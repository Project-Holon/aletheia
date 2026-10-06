/*
 * function: func_0201D83C
 * address:  0x0201D83C
 * packet:   pkt_0201D83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201DADC  0x0201DADC  thumb
 *   func_0201D9C8  0x0201D9C8  thumb
 *   func_020307B0  0x020307B0  arm
 */

struct Font;
extern void func_0201DADC(struct Font *f);
extern void func_0201D9C8(struct Font *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

u32 func_0201D83C(void *ptr)
{
    func_0201DADC(ptr);
    func_0201D9C8(ptr);
    return func_020307B0(ptr);
}
