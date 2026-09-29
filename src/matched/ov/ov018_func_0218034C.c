/*
 * function: func_0218034C
 * address:  0x0218034C
 * packet:   pkt_ov018_0218034C
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
 *   func_02180978  0x02180978  thumb ov018
 *   d_02183B30  0x02183B30  data ov018 a1
 *   d_02183B44  0x02183B44  data ov018 a1
 *   d_021837C4  0x021837C4  data ov018 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern char d_02183B30[];
extern char d_02183B44[];
extern void (*d_021837C4[])(int, void *);

void *func_02030734(int a, int b, int c, const char *file, int line);
void func_020307B0(void *p);
void func_02034714(const char *file, int line, const char *msg);
void MI_CpuCopy8(const void *src, void *dst, unsigned int n);
void func_021829F8(int x, void *p);
void func_02180978(int x, void *p);

void func_0218034C(int x, u8 *y)
{
    void *p = func_02030734((u16)((*(u16 *)y & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x354);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        func_02180978(x, p);
    } else if (c == 1) {
        func_021829F8(x, p);
    } else if (c == 2) {
        func_02180978(x, p);
    } else if (c >= 3) {
        if (d_021837C4[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_021837C4[y[0x41] - 8](x, p);
    } else {
        func_02180978(x, p);
    }
    func_020307B0(p);
}
