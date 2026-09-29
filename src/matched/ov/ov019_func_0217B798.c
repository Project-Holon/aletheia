/*
 * function: func_0217B798
 * address:  0x0217B798
 * packet:   pkt_ov019_0217B798
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BBA70 0x021BBA70  thumb  ov021
 *   func_02087C6C 0x02087C6C  arm
 *   memcmp        0x0203EFC8  arm
 *   func_0217B8F0 0x0217B8F0  thumb  ov019
 *   func_021734A8 0x021734A8  thumb  ov012
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021BBA70(char *, u8 *, int, int);
extern void func_02087C6C(void *);
extern int memcmp(const void *a, const void *b, int n);
extern int func_0217B8F0(char *, int);
extern void func_021734A8(char *, int, u8 *);

void func_0217B798(char *base, u8 *p)
{
    u8 *q = (u8 *)base + 0x2830;
    u8 buf[6];

    func_021BBA70(base, p, 0, 0);
    if (q[1] == 0 && q[0x71] == 0 && p[0xa] == 5 && *(u16 *)(p + 0x6c) != 0) {
        func_02087C6C(buf);
        if (memcmp(p, buf, 6) == 0 && func_0217B8F0(base, 6) == 1) {
            func_021734A8(base, 2, p);
            func_021734A8(base, 0, p);
        }
    }
}
