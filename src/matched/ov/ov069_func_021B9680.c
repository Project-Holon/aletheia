/*
 * function: func_021B9680
 * address:  0x021B9680
 * packet:   pkt_ov069_021B9680
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9F58  0x021B9F58  thumb  ov069
 *   func_021B9DE8  0x021B9DE8  thumb  ov069
 *   func_021B9CD8  0x021B9CD8  thumb  ov069
 *   func_021B9BF0  0x021B9BF0  thumb  ov069
 *   func_021B9A44  0x021B9A44  thumb  ov069
 *   func_021B9888  0x021B9888  thumb  ov069
 *   func_021B9784  0x021B9784  thumb  ov069
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern int func_021B9F58(char *p);
extern void func_021B9DE8(u8 *p);
extern void func_021B9CD8(u8 *p);
extern void func_021B9BF0(char *p);
extern void func_021B9A44(void *p);
extern void func_021B9888(void *p);
extern void func_021B9784(u8 *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(unsigned int heap);

int func_021B9680(u32 a, u32 b, u32 c, void *p)
{
    func_021B9F58(p);
    func_021B9DE8(p);
    func_021B9CD8(p);
    func_021B9BF0(p);
    func_021B9A44(p);
    func_021B9888(p);
    func_021B9784(p);
    func_020315D4((struct S020315D4 *)a);
    func_0203084C(0x80);
    func_020306F0(0x80);
    return 1;
}
