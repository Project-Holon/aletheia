/*
 * function: func_021E3070
 * address:  0x021E3070
 * packet:   pkt_ov119_021E3070
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02050B80  0x02050B80  arm
 *   func_02030734  0x02030734  arm
 *   func_02050C04  0x02050C04  arm
 *   func_0205121C  0x0205121C  arm
 *   func_02051230  0x02051230  arm
 *   d_021E81C0  0x021E81C0  data a1
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02050B80(u16);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_02050C04(void *, int, int, u16);
extern void *func_0205121C(int, int, u16);
extern void func_02051230(void *, void *, int, int);
extern const char d_021E81C0[];

typedef struct {
    void *a[9];         /* 0x000 */
    void *b[6];         /* 0x024 */
    u16 pad3C[0x3F];    /* 0x03C */
    u16 heap;           /* 0x0BA */
} S;

void func_021E3070(S *p)
{
    int i;
    void *buf;
    void *h;
    void **q;

    func_02050B80(p->heap);
    for (i = 0; i < 6; i++) {
        q = &p->a[i];
        buf = func_02030734(p->heap, 0x4800, 1, d_021E81C0, 0x273);
        q[9] = buf;
        *q = func_02050C04(buf, 0x4800, 0, p->heap);
    }
    h = func_0205121C(0x68, 10, p->heap);
    for (i = 0; i < 6; i++)
        func_02051230(p->a[i], h, 1, 0);
}
