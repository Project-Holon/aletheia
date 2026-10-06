/*
 * function: func_02161B1C
 * address:  0x02161B1C
 * packet:   pkt_ov010_02161B1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   d_02171404     0x02171404  data  a1
 *   d_021713FC     0x021713FC  data  a1
 *   d_021713F4     0x021713F4  data  a1
 *   d_021713EC     0x021713EC  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char d_02171404[];
extern const char d_021713FC[];
extern const char d_021713F4[];
extern const char d_021713EC[];

struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void *func_0216D4B4(char *p);
extern int func_02197D3C(void *a, const char *b);

int func_02161B1C(void *a)
{
    const char *s;
    void *p;

    p = func_021A3074(func_02188CB4(a));
    switch (func_0216D5F8(p)) {
    case 0:
        s = d_02171404;
        break;
    case 1:
        s = d_021713FC;
        break;
    case 2:
        s = d_021713F4;
        break;
    case 3:
        s = d_021713EC;
        break;
    }
    func_0216D4B4(p);
    return func_02197D3C(p, s);
}
