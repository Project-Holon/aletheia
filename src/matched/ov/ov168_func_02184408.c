/*
 * function: func_02184408
 * address:  0x02184408
 * packet:   pkt_02184408
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02006D44  0x02006D44  thumb
 *   func_02034FB8  0x02034FB8  arm
 */

extern void func_020307B0(void *p);
extern void func_02006D44(void);
typedef unsigned int   u32;
extern void func_02034FB8(u32 v);

void func_02184408(int *p)
{
    func_020307B0((void *)(*(int *)((char *)p + 0x1c)));
    func_02006D44();
    func_02034FB8(8);
}
