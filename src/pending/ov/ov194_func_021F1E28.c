/*
 * function: func_021F1E28
 * address:  0x021F1E28
 * packet:   pkt_ov194_021F1E28
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD5 lane14): still DIFF, same 4 bytes (entry spills b then a). Tried: the b store
 *   (0x22) before the c store (0x34): the c spill moves after the memset arguments but a stays before b
 *   (15 bytes), so the spill order does not follow store order. Not a register or slot problem.
 *
 * note 2026-10-05 (wD6 lane10): still DIFF 4 (entry spill order). Tried param types int/short b,
 *   short/u16 a with u16 b, int/int: no change. Spill store order is not param order, not first-use order.
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020457B0  0x020457B0  arm
 *   func_021F4DBC  0x021F4DBC  thumb  ov194
 *   func_021F4F50  0x021F4F50  thumb  ov194
 *   func_021F1998  0x021F1998  thumb  ov194
 *   func_020458F8  0x020458F8  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02045A38  0x02045A38  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B95C  0x0204B95C  arm
 *   func_021F1FB4  0x021F1FB4  thumb  ov194
 */

/*
 * 2026-10-04 (wave D2 lane05): DIFF, one residue: 338 compiled bytes plus the 2-byte pad at 0x021F1F7A equal the 340-byte extent; every instruction matches except the two entry spills, which the original stores as str r2,[sp,#0x10] then str r1,[sp,#0xc] (b before a) and this build stores in order a, b. Slots are identical. Tried param types for a and b (int, u32, u16). Prototype notes: func_021F4DBC is called with 2 arguments (declared with 2 here, the matched file has 3); func_020409B4 takes no visible argument; params are (p, a, b u16, c, d, e, f); pos[2] is a u16 stack array passed to func_0204B404.
 *
 * 2026-10-05 (wD4 lane09): still DIFF, the same 4 bytes (entry spill order b then a). Tried: a copied into a
 * local `int a = a0;` (declared first or last), b copied into a u16 local, param types u8/u16/int for a and
 * int for b: no change. The order is not the first-use order (c is used first but spilled last).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *p, int v, int n);
extern int func_020450F0(int, int, int, int, int, int, int);
extern void func_02045334(int);
extern void func_02045374(int);
extern void func_02045730(int);
extern void func_020409B4(void);
extern int func_020457B0(int a, int b);
extern int func_021F4DBC(int a, int b);
extern int func_021F4F50(int a);
extern int func_021F1998(u8 *p, u32 i);
extern u16 func_020458F8(int);
extern u16 func_02045A98(void);
extern void func_02045A38(int, void *, int);
extern void func_0204B878(int, int);
extern void func_0204B92C(int, int);
extern void func_0204B404(int, void *, int);
extern void func_0204B3DC(int, int);
extern void func_0204B95C(int);
extern void func_021F1FB4(u8 *p);
void func_021F1E28(u8 *p, int a, u16 b, int c, int d, u8 *e, int f)
{
    u16 pos[2];
    int i;
    int h;
    int base;
    func_02082BCC(p, 0, 0x94);
    i = 0;
    *(int *)(p + 0x34) = c;
    *(u16 *)(p + 0x22) = b;
    *(int *)(p + 0x38) = d;
    h = func_020450F0(0, 8, 2, 0x18, 2, 15, 1);
    *(int *)(p + 0x40) = h;
    func_02045334(h);
    func_02045374(h);
    func_02045730(h);
    func_020409B4();
    *(int *)(p + 0x2c) = *(int *)(p + 0x40);
    *(u8 *)(p + 0x30) = i;
    *(int *)(p + 0x3c) = func_020457B0(0xe, f);
    for (i = 0; i < 3; i++) {
        *(int *)(p + i * 4 + 0x84) = func_021F4DBC(i, f);
    }
    *(int *)(p + 0x90) = func_021F4F50(f);
    for (i = 0; i < 16; i++) {
        *(int *)(p + i * 4 + 0x44) = (int)func_021F1998(e, i);
    }
    if (func_020458F8(a) == 0) {
        *(u16 *)p = func_02045A98();
    } else {
        func_02045A38(a, p, b + 1);
        *(u16 *)(p + 0x1e) = func_020458F8(a);
    }
    pos[1] = 0x25;
    base = 0x40 - (*(u16 *)(p + 0x22) * 14) / 2;
    if (base < 0) {
        base = 0;
    }
    base += 0x40;
    for (i = 0; i < 16; i++) {
        pos[0] = base + i * 14;
        func_0204B878(*(int *)(p + i * 4 + 0x44), 1);
        func_0204B92C(*(int *)(p + i * 4 + 0x44), 1);
        func_0204B404(*(int *)(p + i * 4 + 0x44), pos, 0);
        func_0204B3DC(*(int *)(p + i * 4 + 0x44), 1);
    }
    for (i = *(u16 *)(p + 0x22); i < 16; i++) {
        func_0204B3DC(*(int *)(p + i * 4 + 0x44), 0);
    }
    func_0204B95C(*(int *)(p + *(u16 *)(p + 0x1e) * 4 + 0x44));
    *(int *)(p + 0x28) = 1;
    func_021F1FB4(p);
}
