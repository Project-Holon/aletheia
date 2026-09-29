/*
 * function: func_021B6100
 * address:  0x021B6100
 * packet:   pkt_ov067_021B6100
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Allocates the 0x10-byte record func_021B6144 steps (fields named there).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021B9540     0x021B9540  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *arr;
    void *f4;
    u16 idx;
    u16 fA;
    u8 fC;
    u8 pad[3];
} S;

extern const char d_021B9540[];

extern S *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02082BCC(void *p, u32 v, u32 n);

S *func_021B6100(u32 heap, void *arr, u8 c, u16 idx, void *f4)
{
    S *p;

    p = func_02030734(heap, 0x10, 0, d_021B9540, 0x4e);
    func_02082BCC(p, 0, 0x10);
    p->arr = arr;
    p->fC = c;
    p->f4 = f4;
    p->idx = idx;
    p->fA = 0xFFFF;
    return p;
}
