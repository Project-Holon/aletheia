/*
 * function: func_02206A3C
 * address:  0x02206A3C
 * packet:   pkt_02206A3C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020437AC 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 */

struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020307B0(void *);

void func_02206A3C(char *p)
{
    func_020437AC(*(void **)(p + 0x10));
    func_020307B0(*(void **)(p + 8));
    func_020307B0(*(void **)(p + 0xc));
    func_020307B0(p);
}
