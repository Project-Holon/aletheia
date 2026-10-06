/*
 * unit: yes
 * function: func_021E4EC4, func_021E4FE8
 * address: 0x021E4EC4
 * packet: pkt_ov093_021E4EC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F26BC 0x021F26BC data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern int d_021F26BC[];

void func_021E4EC4(int unused, void *s, int k)
{
    u8 v;
    void *a;
    void *b;
    u32 x;
    u32 y;
    u8 *p;
    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        a = func_021C7CF4(s, v);
        b = func_021C7CF4(s, k);
        x = func_021D59B4(b, 2);
        y = func_021D59B4(b, 4);
        p = func_021C88A4(s, 15, k);
        p[4] = k;
        p[5] = func_021D59B4(b, 1);
        p[7] = func_021D59B4(b, 3);
        p[6] = func_021D59B4(a, 2);
        p[8] = func_021D59B4(a, 4);
        p[9] = func_021D59B4(b, 5);
        p[10] = func_021D59B4(b, 6);
        p[11] = func_021D59B4(b, 7);
        func_021C88C8(s, p);
        p = func_021C88A4(s, 15, k);
        p[4] = v;
        p[5] = func_021D59B4(a, 1);
        p[7] = func_021D59B4(a, 3);
        p[6] = x;
        p[8] = y;
        p[9] = func_021D59B4(a, 5);
        p[10] = func_021D59B4(a, 6);
        p[11] = func_021D59B4(a, 7);
        func_021C88C8(s, p);
        p = func_021C88A4(s, 4, k);
        func_021C8838(p + 4, 2, 679);
        func_021C8860((struct S *)(p + 4), k);
        func_021C88C8(s, p);
    }
}

int *func_021E4FE8(int *p)
{
    *p = 1;
    return d_021F26BC;
}
