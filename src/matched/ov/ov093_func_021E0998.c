/*
 * function: func_021E0998
 * address: 0x021E0998
 * packet: pkt_ov093_021E0998
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: move stays int; the caller passes the full value to func_021D5778 without narrowing.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D6D54 0x021D6D54 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021E0A64 0x021E0A64 thumb ov093
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
struct QL;
struct QQ;
struct R5;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D6D54(struct R5 *p);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D67B8(u8 *p);
extern int func_021E0A64(int);
extern u8 func_021D5778(void *, int);
extern u16 func_021D70A8(struct QQ *p);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *, u32);
void func_021E0998(void *a, void *q, int id)
{
    void *m;
    void *t;
    int move;
    int other;
    int slot;
    u8 *r;
    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        if (func_021D6D54(m) != 0) return;
        t = func_021C7CF4(q, (u8)func_021D775C(6));
        move = func_021D67A8(t);
        other = func_021D67B8(t);
        if (other != move) move = other;
        if (move == 0 || func_021E0A64(move) != 0 || func_021D5778(m, move) != 4) return;
        slot = func_021D5778(m, func_021D70A8(a));
        if (slot == 4) return;
        r = func_021C88A4(q, 37, id);
        r[4] = id;
        r[5] = slot;
        *(u16 *)(r + 8) = move;
        r[6] = 0;
        r[7] = 0;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 4, id);
        func_021C8838(r + 4, 2, 0x2b0);
        func_021C8860((struct S *)(r + 4), id);
        func_021C8860((struct S *)(r + 4), move);
        func_021C88C8(q, r);
    }
}
