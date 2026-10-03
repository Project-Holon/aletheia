/*
 * unit: yes
 * function: func_021E508C, func_021E5170
 * address: 0x021E508C
 * packet: pkt_ov093_021E508C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F2704 0x021F2704 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Rec {
    u8 pad[14];
    u8 id;
    u8 f0:1;
    u8 f1:1;
    u8 f2:1;
    u8 f3:1;
    u8 rest:4;
} Rec;
extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D58A8(u8 *p, int k);
extern void *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern u8 d_021F2704[];
void func_021E508C(void *x, void *a, int c)
{
    u8 k;
    void *m, *n;
    int first, second;
    Rec *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        m = func_021C7CF4(a, c);
        n = func_021C7CF4(a, k);
        first = (func_021D58A8(m, 8) + func_021D58A8(n, 8)) / 2;
        second = (func_021D58A8(m, 10) + func_021D58A8(n, 10)) / 2;
        p = func_021C88A4(a, 17, c);
        p->id = k;
        *(u16 *)((u8 *)p + 4) = first;
        *(u16 *)((u8 *)p + 8) = second;
        p->f0 = 1;
        p->f2 = 1;
        func_021C88C8(a, p);
        p = func_021C88A4(a, 17, c);
        p->id = c;
        *(u16 *)((u8 *)p + 4) = first;
        *(u16 *)((u8 *)p + 8) = second;
        p->f0 = 1;
        p->f2 = 1;
        func_021C8838((u8 *)p + 16, 2, 0x448);
        func_021C8860((u8 *)p + 16, c);
        func_021C88C8(a, p);
    }
}
void *func_021E5170(int *p)
{
    *p = 1;
    return d_021F2704;
}
