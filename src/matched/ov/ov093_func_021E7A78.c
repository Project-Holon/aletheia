/*
 * unit: yes
 * function: func_021E7A78, func_021E7B34
 * address: 0x021E7A78
 * packet: pkt_ov093_021E7A78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the byte-valued count remains u8; +7 is a one-bit field assignment.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D34 0x021C7D34 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F2634 0x021F2634 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern int func_021C7D34(int, int);
extern u8 func_021C7F68(int *, int, u8 *);
extern void *func_021C7CF4(int, int);
extern u8 *func_021C88A4(int, int, int);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(int, u8 *);
extern int d_021F2634[];

void func_021E7A78(int a, int b, int c)
{
    u8 list[4];
    u8 k, i;
    u8 n;
    int slot;
    u8 *x;
    u8 *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(4);
        slot = func_021C7D34(b, k);
        if (slot != 6) {
            n = func_021C7F68((int *)b, (u16)(0x900 | slot), list);
            for (i = 0; i < n; i++) {
                if (list[i] != k) {
                    x = func_021C7CF4(b, list[i]);
                    p = func_021C88A4(b, 7, c);
                    p[6] = list[i];
                    *(u16 *)(p + 4) = func_021D7B74(x, 16);
                    ((struct Flag { u8 bit : 1; } *)(p + 7))->bit = 1;
                    func_021C8838(p + 12, 2, 0x451);
                    func_021C8860((struct S *)(p + 12), p[6]);
                    func_021C88C8(b, p);
                }
            }
        }
    }
}

int *func_021E7B34(int *p)
{
    *p = 1;
    return d_021F2634;
}
