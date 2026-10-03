/*
 * unit: yes
 * function: func_021DEFC4, func_021DF0B8
 * address: 0x021DEFC4
 * packet: pkt_ov093_021DEFC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C83D4 0x021C83D4 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F154C 0x021F154C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int key);
extern int func_021C83D4(void *p);
extern u16 func_021D57FC(void *p);
extern int func_021E8D24(u16, int);
extern void *func_021C7CF4(void *a, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern u32 func_021DCFF8(int a, int k);
extern int func_021D7B74(void *m, u32 k);
extern int func_021C8010(void *p, int x);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern u16 func_021D70A8(void *p);
extern void func_021C88C8(void *a, void *b);
void func_021DEFC4(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == func_021D775C(2) && func_021C83D4(b) == 0) {
        m = func_021C7CF4(b, c);
        if (func_021E8D24(func_021D57FC(m), 3)) {
            r = (u8 *)func_021C88A4(b, 5, c);
            r[6] = c;
            *(u16 *)(r + 4) = func_021D7B74(m, func_021DCFF8(a, 2));
            func_021C8838(r + 8, 2, 0x392);
            func_021C8860(r + 8, c);
            func_021C8860(r + 8, func_021D70A8((void *)a));
            func_021C88C8(b, r);
        } else {
            r = (u8 *)func_021C88A4(b, 7, c);
            r[6] = c;
            *(u16 *)(r + 4) = func_021D7B74(m, 8);
            r[7] |= 2;
            *(u16 *)(r + 8) = 0x25f;
            r[10] = func_021C8010(b, c);
            r[11] = 6;
            func_021C8838(r + 12, 2, 0x40e);
            func_021C8860(r + 12, c);
            func_021C8860(r + 12, func_021D70A8((void *)a));
            func_021C88C8(b, r);
        }
    }
}
extern u8 d_021F154C[];
void *func_021DF0B8(int *p) { *p = 1; return d_021F154C; }
