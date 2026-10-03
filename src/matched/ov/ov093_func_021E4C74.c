/*
 * unit: yes
 * function: func_021E4C74, func_021E4D8C
 * address: 0x021E4C74
 * packet: pkt_ov093_021E4C74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F2724 0x021F2724 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(void *, int);
extern u8 *func_021C8120(void *, int);
extern int func_021D59B4(u8 *p, int k);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern int d_021F2724[];

void func_021E4C74(int unused, void *s, int k)
{
    u8 v;
    void *a;
    void *b;
    u32 *t;
    int i;
    u8 *p;
    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        a = func_021C7CF4(s, v);
        b = func_021C7CF4(s, k);
        t = (u32 *)func_021C8120(s, 28);
        for (i = 1; i <= 7; i++) {
            t[i - 1] = func_021D59B4(b, i);
        }
        p = func_021C88A4(s, 15, k);
        p[4] = k;
        p[5] = func_021D59B4(a, 1);
        p[6] = func_021D59B4(a, 2);
        p[7] = func_021D59B4(a, 3);
        p[8] = func_021D59B4(a, 4);
        p[9] = func_021D59B4(a, 5);
        p[10] = func_021D59B4(a, 6);
        p[11] = func_021D59B4(a, 7);
        func_021C88C8(s, p);
        p = func_021C88A4(s, 15, k);
        p[4] = v;
        p[5] = t[0];
        p[6] = t[1];
        p[7] = t[2];
        p[8] = t[3];
        p[9] = t[4];
        p[10] = t[5];
        p[11] = t[6];
        func_021C88C8(s, p);
        p = func_021C88A4(s, 4, k);
        func_021C8838(p + 4, 2, 673);
        func_021C8860(p + 4, k);
        func_021C88C8(s, p);
    }
}

int *func_021E4D8C(int *p)
{
    *p = 1;
    return d_021F2724;
}
