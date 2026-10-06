/*
 * function: func_021B7234
 * address:  0x021B7234
 * packet:   pkt_ov071_021B7234
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_02030734  0x02030734  arm
 *   func_02041090  0x02041090  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021BABE4     0x021BABE4  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0xc];
    u16 n;
    u16 m;
} Counts;

extern const char d_021BABE4[];

typedef unsigned int   u32;
extern void *func_021B6F40(u8 **p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_020307B0(void *p);

void func_021B7234(void *a, int flag, int bg)
{
    Counts *c;
    u16 *buf;
    int y;
    int n, m;
    int left, right;
    int i;

    c = func_021B6F40(a);
    y = 0x14;
    if (flag) {
        y = 0xe;
    }
    n = c->n;
    m = c->m;
    if (n == m) {
        left = 0x78;
        right = 0x78;
    } else {
        left = n * 0xf0 / (n + m);
        if (m > 0) {
            right = 0xf0 - left;
        } else {
            right = 0;
            left = 0xf0;
        }
    }
    if (n > 0 && left == 0) {
        right--;
    } else if (m > 0 && right == 0) {
        right++;
    }
    buf = func_02030734(0x61, 0x3c, 1, d_021BABE4, 0x474);
    for (i = 0; right > 0; i++) {
        if (right >= 8) {
            buf[i] = 1;
            right -= 8;
        } else {
            buf[i] = 9 - right;
            right = 0;
        }
    }
    for (; i < 30; i++) {
        buf[i] = 9;
    }
    for (i = 0; i < 30; i++) {
        buf[i] |= 0x1000;
    }
    func_02041090((u8)bg, (u32)buf, (u8)1, (u8)y, 30, 1);
    func_020307B0(buf);
}
