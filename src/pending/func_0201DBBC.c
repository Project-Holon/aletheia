/*
 * function: func_0201DBBC
 * address:  0x0201DBBC
 * packet:   pkt_0201DB20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44   0x02082D44  arm
 *   func_0201DC44   0x0201DC44  thumb
 *
 * Two calls on the same object: an ARM one whose two arguments are the
 * object's stride computation (offset + row * the halfword height at 0x76)
 * and the block pointer at 0x90, then the Thumb at 0x0201DC44 taking the
 * object, that same pointer, the halfword at 0x7C and the caller's a2/a3.
 * No literal pool: both callees are reached directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201DBBC.c \
 *       --func func_0201DBBC --addr 0x0201DBBC --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082D44(u32 a0, u32 a1);
extern void func_0201DC44(void *a0, u32 a1, u32 a2, int a3, int a4);

void func_0201DBBC(void *a0, int a1, int a2, int a3)
{
    func_02082D44(*(u32 *)((char *)a0 + 0xC)
                      + a1 * *(u16 *)((char *)a0 + 0x76),
                  *(u32 *)((char *)a0 + 0x90));
    func_0201DC44(a0, *(u32 *)((char *)a0 + 0x90),
                  *(u16 *)((char *)a0 + 0x7C), a2, a3);
}
