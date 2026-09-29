/*
 * function: func_02186670
 * address:  0x02186670
 * packet:   pkt_ov020_02186670
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02186278  0x02186278  thumb
 *   func_021867C4  0x021867C4  thumb
 *   func_0218682C  0x0218682C  thumb
 *   func_02186818  0x02186818  thumb
 *   func_02186804  0x02186804  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_02186278(char *, int);
extern int func_021867C4(int, int);
extern char *func_0218682C(int);
extern void func_02186818(int, int);
extern void func_02186804(int);

void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id)
{
    unsigned t;
    unsigned lim;
    int k;
    int num;
    int i;
    int h;
    char *r;
    char *q;

    t = func_02186278(base, 0);
    k = n * 2;
    lim = k + 2;
    if (lim > t)
        lim = t;
    num = lim - k;
    i = 0;
    h = func_021867C4(0, id);
    r = func_0218682C(h);
    *cnt = 0;
    if (num > 0) {
        q = base + k * 0x18;
        do {
            func_02186818(h, (u8)q[i * 0x18 + 9]);
            *(u16 *)(out + *cnt * 8) = *(u16 *)(r + 0x28);
            *(int *)(out + *cnt * 8 + 4) = *(u16 *)(r + 0x2a);
            *cnt = *cnt + 1;
            i++;
        } while (i < num);
    }
    func_02186804(h);
}
