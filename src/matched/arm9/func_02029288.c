/*
 * function: func_02029288
 * address:  0x02029288
 * packet:   pkt_02029250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02005E50(u8 *p);
extern void func_02029344(void *obj, u32 value);
extern void func_0202938C(u8 *p);
extern void func_02029364(u8 *p);

void func_02029288(u8 *p)
{
    if (func_02005E50(p) != 0) {
        return;
    }
    if (*(u32 *)(p + 0xc) != 0 && *(u32 *)(p + 0xc) != *(u32 *)(p + 8)) {
        func_0202938C(p);
        func_02029344(p, 8);
        return;
    }
    func_02029344(p, 1);
    func_02029364(p);
}
