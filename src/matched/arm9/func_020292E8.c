/*
 * function: func_020292E8
 * address:  0x020292E8
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020292E8.c \\
 *       --func func_020292E8 --addr 0x020292E8 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02029434(u8 *p);
extern void func_0202939C(u8 *p);
extern void func_02029344(void *obj, u32 value);
extern void func_02029364(u8 *p);

void func_020292E8(u8 *p)
{
    if (func_02029434(p) == 0) {
        return;
    }
    func_0202939C(p);
    func_02029344(p, 0);
    func_02029364(p);
}
