/*
 * function: func_021E5A34
 * address: 0x021E5A34
 * packet: pkt_ov093_021E5A34
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021E5B3C 0x021E5B3C thumb ov093
 *   func_021E5B4C 0x021E5B4C thumb ov093
 *   func_021E5B5C 0x021E5B5C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern unsigned char func_021B9A40(unsigned int x);
extern int func_021E5B3C(int, int);
extern int func_021E5B4C(int, int);
extern int func_021E5B5C(int, int);
void func_021E5A34(void *x, void *a, int c)
{
    void *m;
    u8 *p;
    int v;
    u8 b, d, e;
    u32 i;
    if (c == BTL_EVENT_GetVar(3)) {
        m = func_021C7CF4(a, c);
        if (BTL_POKEPARAM_HasSick(m, 18) != 0) {
            p = func_021C88A4(a, 11, c);
            p[20] = 1;
            p[8] = c;
            *(int *)(p + 4) = 18;
            func_021C88C8(a, p);
        }
        if (BTL_POKEPARAM_HasSick(m, 8) != 0) {
            p = func_021C88A4(a, 11, c);
            p[20] = 1;
            p[8] = c;
            *(int *)(p + 4) = 8;
            func_021C88C8(a, p);
        }
        v = func_021B9A40(c);
        b = func_021E5B3C(v, 6);
        d = func_021E5B4C(v, 7);
        e = func_021E5B5C(v, 8);
        if (b || d || e) {
            p = func_021C88A4(a, 26, c);
            p[7] = v;
            p[4] = 3;
            for (i = 1; i < 3; i++)
                p[4 + i] = 0;
            if (b && p[4] > 1)
                p[5] |= 0x40;
            if (d && p[4] > 1)
                p[5] |= 0x80;
            if (e && p[4] > 2)
                p[6] |= 1;
            func_021C88C8(a, p);
        }
    }
}
