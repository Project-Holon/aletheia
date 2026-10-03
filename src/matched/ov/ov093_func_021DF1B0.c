/*
 * unit: yes
 * function: func_021DF1B0, func_021DF240, func_021DF24C, func_021DF258, func_021DF264, func_021DF270, func_021DF27C
 * address: 0x021DF1B0
 * packet: pkt_ov093_021DF1B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F138C 0x021F138C data a4
 *   d_021F1434 0x021F1434 data a4
 *   d_021F15A4 0x021F15A4 data a4
 *   d_021F1554 0x021F1554 data a4
 *   d_021F15B4 0x021F15B4 data a4
 *   d_021F15C4 0x021F15C4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern u32 func_021DCFF8(int a, int k);
extern int func_021D7B74(void *m, u32 k);
extern int func_021C8010(void *p, int x);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern u16 func_021D70A8(void *p);
extern void func_021C88C8(void *a, void *b);
void func_021DF1B0(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == func_021D775C(2)) {
        m = func_021C7CF4(b, c);
        r = (u8 *)func_021C88A4(b, 7, c);
        r[6] = c;
        *(u16 *)(r + 4) = func_021D7B74(m, func_021DCFF8(a, 2));
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
extern u8 d_021F138C[], d_021F1434[], d_021F15A4[], d_021F1554[], d_021F15B4[], d_021F15C4[];
void *func_021DF240(int *p) { *p = 1; return d_021F138C; }
void *func_021DF24C(int *p) { *p = 1; return d_021F1434; }
void *func_021DF258(int *p) { *p = 1; return d_021F15A4; }
void *func_021DF264(int *p) { *p = 1; return d_021F1554; }
void *func_021DF270(int *p) { *p = 1; return d_021F15B4; }
void *func_021DF27C(int *p) { *p = 1; return d_021F15C4; }
