/*
 * unit: yes
 * function: func_021DA624, func_021DA6D4, func_021DA6E0
 * address: 0x021DA624
 * packet: pkt_ov093_021DA624
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D54 0x021C7D54 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F09B0 0x021F09B0 data a4
 *   d_021F0B00 0x021F0B00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern u8 func_021C7D54(void *, int, u8 *);
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_021D78AC(u32);
extern void func_021C88B4(void *, int, int);
extern void *func_021C88A4(void *, int, int);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *, void *);
void func_021DA624(int a, void *b, int c)
{
    u16 values[4];
    u8 buf[4];
    u8 n;
    u8 count;
    u8 i;
    u8 choice;
    u8 *p;
    void *q;
    if (c != func_021D775C(2)) return;
    n = func_021C7D54(b, c, buf);
    count = 0;
    for (i = 0; i < n; i++) {
        q = func_021C7CF4(b, buf[i]);
        values[count] = func_021D5B40(q);
        if (values[count] != 0) count++;
    }
    if (count == 0) return;
    choice = func_021D78AC(count);
    func_021C88B4(b, 2, c);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 0x1b7);
    func_021C8860((struct S *)(p + 4), c);
    func_021C8860((struct S *)(p + 4), values[choice]);
    func_021C88C8(b, p);
    func_021C88B4(b, 3, c);
}
extern int d_021F09B0, d_021F0B00;
int *func_021DA6D4(int *p) { *p = 2; return &d_021F09B0; }
int *func_021DA6E0(int *p) { *p = 3; return &d_021F0B00; }
