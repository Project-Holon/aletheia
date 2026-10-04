/*
 * function: func_021B95D0
 * address:  0x021B95D0
 * packet:   pkt_ov227_021B95D0
 * region:   ov227
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02031324  0x02031324  arm
 */

extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern int func_0203159C(int, int, int);
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_02031324(int);

struct s { char pad[0x38]; };

int func_021B95D0(int a)
{
    struct s *p;

    func_0203064C(1, 0x8b, 0x1000);
    p = (struct s *)func_0203159C(a, 0x38, 0x8b);
    *(int *)((char *)p + 4) = (int)func_020457B0(0x20, 0x8b);
    *(int *)p = 0;
    *(int *)((char *)p + 0x28) = 0;
    *(int *)((char *)p + 0x2c) = 0;
    *(unsigned short *)((char *)p + 0x30) = 0x8b;
    *(int *)((char *)p + 0x34) = func_02031324(*(unsigned short *)((char *)p + 0x30));
    return 1;
}
