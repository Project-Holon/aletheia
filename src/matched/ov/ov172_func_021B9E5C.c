/*
 * function: func_021B9E5C
 * address:  0x021B9E5C
 * packet:   pkt_ov172_021B9E5C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Renders idx*0x7b/v steps of a waveform bar by bar with func_021B9AB8, advancing the counters at +0x30/+0x31.
 *
 * symbols:
 *   func_02045334  0x02045334  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021B9AB8  0x021B9AB8  thumb  ov172
 *   d_021C6F6E     0x021C6F6E  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern int func_0209C0A4(int a, u16 b);
struct Bmp;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02045334(struct Descriptor *);
extern void func_021B9AB8(int a0, char *obj, void *dev, int a3, u8 s0, u8 s1, u8 s2, int s3);
extern u8 d_021C6F6E[];

void func_021B9E5C(int a0, char *obj, s16 *tbl, int a3, int idx, u16 v)
{
    u32 n;
    void *dev;
    int flag;
    u32 c;
    int h;
    int x;
    u32 c1;

    if (idx < 0)
        return;
    n = func_0209C0A4(idx * 0x7B, v);
    dev = func_020437D4(func_02045770(*(void **)(obj + 0x2C)));
    flag = 0;
    c = *(u8 *)(obj + 0x30);
    if (c < n) {
        flag = 1;
        while (c < n) {
            c1 = c + 1;
            x = c1 * v;
            h = ((tbl[x / 128 / 2] + 0x8000) << 6) / 0x10000;
            if (c < 0xB) {
                u32 t = 0x20 - d_021C6F6E[c - 3];
                if (h < t)
                    h = t;
            }
            if (c > 0x72) {
                u32 t = 0x20 - d_021C6F6E[(u8)(0x7A - c)];
                if (h < t)
                    h = t;
            }
            func_021B9AB8(a0, obj, dev, c, *(u8 *)(obj + 0x31), (u8)c1, (u8)h, a3);
            *(u8 *)(obj + 0x30) += 1;
            *(u8 *)(obj + 0x31) = (u8)h;
            c = *(u8 *)(obj + 0x30);
        }
    }
    if (flag == 1)
        func_02045334((struct Descriptor *)*(int *)(obj + 0x2C));
}
