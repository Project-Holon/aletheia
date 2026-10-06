/*
 * function: func_020291E8
 * address:  0x020291E8
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020291E8.c \\
 *       --func func_020291E8 --addr 0x020291E8 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct T;
extern int func_02005E50(void);
extern void func_020293D8(struct T *p);
extern void func_02029374(u8 *p);
extern void func_02029344(void *obj, u32 value);

void func_020291E8(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    func_020293D8((struct T *)p);
    func_02029374(p);
    func_02029344(p, 7);
}
