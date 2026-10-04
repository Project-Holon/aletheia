/*
 * function: func_021802A8
 * address:  0x021802A8
 * packet:   pkt_ov018_021802A8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021829F8  0x021829F8  thumb ov018
 *   func_021808C4  0x021808C4  thumb ov018
 *   d_02183B30  0x02183B30  data ov018 a1
 *   d_02183B44  0x02183B44  data ov018 a1
 *   d_0218374C  0x0218374C  data ov018 a4
 */
#include "../include/Obj12502.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern char d_02183B30[];
extern char d_02183B44[];
extern void (*d_0218374C[])(int, void *);

typedef unsigned int   u32;
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_020307B0(void *p);
void func_02034714(const char *expr, u32 line, const char *file);
void MI_CpuCopy8(const void *src, void *dst, unsigned int n);
void func_021829F8(void *a, void *b);
void func_021808C4(void *task, const void *src);

void func_021802A8(int x, u8 *y)
{
    void *p = func_02030734((u16)((((struct Obj12502 *)y)->f0 & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x329);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        func_021808C4((void *)x, p);
    } else if (c == 1) {
        func_021829F8((void *)x, p);
    } else if (c == 2) {
        func_021808C4((void *)x, p);
    } else if (c >= 3) {
        if (d_0218374C[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_0218374C[y[0x41] - 8](x, p);
    } else {
        func_021808C4((void *)x, p);
    }
    func_020307B0(p);
}
