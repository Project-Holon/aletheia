/*
 * function: func_020291C4
 * address:  0x020291C4
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020291C4.c \
 *       --func func_020291C4 --addr 0x020291C4 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02005E50(u8 *p);
extern void func_0202939C(u8 *p);
extern void func_02029344(void *obj, u32 value);
extern void func_02029364(u8 *p);

void func_020291C4(u8 *p)
{
    if (func_02005E50(p) != 0) {
        return;
    }
    func_0202939C(p);
    func_02029344(p, 0);
    func_02029364(p);
}
