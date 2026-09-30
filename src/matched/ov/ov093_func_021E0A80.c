/*
 * unit: yes
 * function: func_021E0A80, func_021E0B5C
 * address: 0x021E0A80
 * packet: pkt_ov093_021E0A80
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E0B5C store-return stub included; consecutive guards spelled separately.
 * symbols:
 *   data_021F2D78 0x021F2D78 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D6D54 0x021D6D54 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D5750 0x021D5750 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(void *, int);
extern int func_021D6D54(void *);
extern u16 func_021D67A8(void *);
extern u16 func_021D67B8(void *);
extern int func_021D5750(void *, int);
extern u8 func_021D5778(void *, u16);
extern u16 func_021D70A8(void *);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
void func_021E0A80(void *a, void *q, int id)
{
    void *m;
    void *t;
    int move;
    int other;
    int slot;
    int text;
    u8 *r;
    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        t = func_021C7CF4(q, (u8)func_021D775C(6));
        move = func_021D67A8(t);
        other = func_021D67B8(t);
        if (other != move) move = other;
        if (move == 0) return;
        if (move == 166) return;
        if (move == 165) return;
        text = 448;
        if (move == text || func_021D5750(m, move) != 0 || func_021D6D54(m) != 0) return;
        slot = func_021D5778(m, func_021D70A8(a));
        if (slot == 4) return;
        r = func_021C88A4(q, 37, id);
        r[4] = id;
        r[5] = slot;
        *(u16 *)(r + 8) = move;
        r[6] = 0;
        r[7] = 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 4, id);
        text += 240;
        func_021C8838(r + 4, 2, text);
        func_021C8860(r + 4, id);
        func_021C8860(r + 4, move);
        func_021C88C8(q, r);
    }
}
extern u32 data_021F2D78[];
u32 *func_021E0B5C(u32 *p)
{
    *p = 4;
    return data_021F2D78;
}
