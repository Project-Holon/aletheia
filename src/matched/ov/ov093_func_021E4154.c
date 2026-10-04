/*
 * unit: yes
 * function: func_021E4154, func_021E4214
 * address: 0x021E4154
 * packet: pkt_ov093_021E4154
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021D5D50 0x021D5D50 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F2B10 0x021F2B10 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
typedef signed char    s8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021D5D50(s8 *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern int d_021F2B10[];

void func_021E4154(int unused, void *s, int k)
{
    void *q;
    int n;
    int t;
    u8 *p;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(s, k);
        n = func_021D7B74(q, 2);
        t = func_021D5D50(q, 1);
        if (func_021D59B4(q, 13) > (u32)n && t != 0) {
            p = func_021C88A4(s, 8, k);
            p[4] = 1;
            p[6] = 1;
            p[7] = k;
            *(int *)(p + 16) = -n;
            func_021C88C8(s, p);
            p = func_021C88A4(s, 14, k);
            *(int *)(p + 4) = 1;
            p[12] = t;
            p[15] = 1;
            p[16] = k;
            p[13] = 1;
            p[14] = 1;
            func_021C88C8(s, p);
            p = func_021C88A4(s, 4, k);
            func_021C8838(p + 4, 2, 613);
            func_021C8860((struct S *)(p + 4), k);
            func_021C88C8(s, p);
            p = func_021C88A4(s, 33, k);
            p[4] = k;
            *(int *)(p + 8) = 1;
            func_021C88C8(s, p);
        }
    }
}

int *func_021E4214(int *p)
{
    *p = 3;
    return d_021F2B10;
}
