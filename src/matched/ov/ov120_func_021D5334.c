/*
 * function: func_021D5334
 * address: 0x021D5334
 * packet: pkt_ov120_021D5334
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021B6498 0x021B6498 thumb ov067
 *   func_021D702C 0x021D702C thumb ov120
 *   func_021D6D10 0x021D6D10 thumb ov120
 *   func_021D82F8 0x021D82F8 thumb ov120
 *   func_021D4F98 0x021D4F98 thumb ov120
 *   func_021D7260 0x021D7260 thumb ov120
 *   func_021D824C 0x021D824C thumb ov120
 *   func_021D7220 0x021D7220 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_020355D8 0x020355D8 arm
 *   func_0203633C 0x0203633C arm
 *   func_021D5284 0x021D5284 thumb ov120
 *   func_021D5230 0x021D5230 thumb ov120
 *   func_021D7020 0x021D7020 thumb ov120
 *   func_021D70C8 0x021D70C8 thumb ov120
 *   func_020061E4 0x020061E4 thumb
 *   func_021D733C 0x021D733C thumb ov120
 *   func_021D6A9C 0x021D6A9C thumb ov120
 *   func_021D5318 0x021D5318 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D51D4 0x021D51D4 thumb ov120
 *   func_021D52D4 0x021D52D4 thumb ov120
 *   func_021D5208 0x021D5208 thumb ov120
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   func_02035C08 0x02035C08 arm
 *   func_021D6E70 0x021D6E70 thumb ov120
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021D7374 0x021D7374 thumb ov120
 *   func_021D82A8 0x021D82A8 thumb ov120
 *   func_021D72A0 0x021D72A0 thumb ov120
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_02040588 0x02040588 arm
 *   func_021D6D48 0x021D6D48 thumb ov120
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   d_021D88D8 0x021D88D8 data
 *   d_021D88C8 0x021D88C8 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ctx {
    u8 pad0[0x2C];
    void *f2C;
    u8 pad30[4];
    void *f34;
    u8 pad38[4];
    u8 *f3C;
    void *f40;
    u8 pad44[0x148 - 0x44];
    int f148;
    u8 pad14C[4];
    int f150;
    u8 pad154[4];
    int f158;
    u8 pad15C[8];
    int f164;
} Ctx;
extern u32 func_021D6988(u8 *p);
struct S;
extern int func_021D7AF4(char *p);
extern int func_021B6498(u8 *p);
extern int func_021D702C(u8 *p, int *out);
extern void func_021D6D10(u8 *p, void *list, int first);
extern void func_021D82F8(char *p);
extern void *func_021D4F98(void **p, int i);
extern void func_021D7260(u8 *p, void *q);
extern void func_021D824C(char *p);
extern void func_021D7220(u8 *p, void *q);
extern u8 func_020355C4(void);
extern u32 func_020362DC(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_020355D8(u8 v);
extern u32 func_0203633C(void);
extern int func_021D5284(u8 *p);
extern int func_021D5230(u8 *p);
extern void func_021D7020(u8 *p);
extern void func_021D70C8(u8 *p, int flag);
extern void func_020061E4(u32 id);
extern void func_021D733C(u8 *p, int index, int count);
extern int func_021D6A9C(u8 *p, u32 n);
extern void func_021D5318(u8 *p);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D51D4(u8 *p);
extern void func_021D52D4(u8 *p);
extern void func_021D5208(u8 *p);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern int func_02035C08(const void *t);
extern void func_021D6E70(void *unused, int *p, int n);
extern int TOUCHPANEL_HitCont(const void *t);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int func_021D7374(char *p, int y, int count);
extern void func_021D82A8(char *p, void *q, int start);
extern void func_021D72A0(u8 *p, void *list, int n);
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D6D48(u8 *p);
extern void func_021D7D3C(char *p);
extern const u8 d_021D88D8[];
extern const u8 d_021D88C8[];
void func_021D5334(Ctx *p)
{
    int out;
    int r;
    int acc = 0;
    int i;
    int sel;
    int x, y;
    out = 0;
    r = func_021D6988(p->f3C);
    if (func_021D7AF4(p->f40) == 0)
        return;
    if (func_021B6498((u8 *)r) != 0)
        goto end;
    r = func_021D702C(p->f3C, &out);
    if (out == 1) {
        func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
        func_021D82F8(p->f40);
        func_021D7260(p->f3C, func_021D4F98(p->f2C, p->f158 - 2));
    } else if (out == 2) {
        func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
        func_021D824C(p->f40);
        func_021D7220(p->f3C, func_021D4F98(p->f2C, p->f158 + 3));
    }
    if (r != 0)
        return;
    if (func_020355C4() == 1 && func_020362DC() != 0) {
        func_021D69F4(p->f3C, 0, p->f164);
        func_020355D8(0);
        return;
    }
    if (func_0203633C() == 0x100) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = func_021D5284((u8 *)p);
            acc |= r;
            func_021D7020(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                func_021D70C8(p->f3C, 1);
                func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
                func_021D824C(p->f40);
                func_021D7220(p->f3C, func_021D4F98(p->f2C, p->f158 + 3));
                func_021D69F4(p->f3C, 0, p->f164);
            }
        }
    }
    if (func_0203633C() == 0x200) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = func_021D5230((u8 *)p);
            acc |= r;
            func_021D7020(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                func_021D69F4(p->f3C, 0, p->f164);
                func_021D70C8(p->f3C, 0);
                func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
                func_021D82F8(p->f40);
                func_021D7260(p->f3C, func_021D4F98(p->f2C, p->f158 - 2));
            }
        }
    }
    if (func_0203633C() == 0x40)
        acc = func_021D5230((u8 *)p);
    if (func_0203633C() == 0x80)
        acc = func_021D5284((u8 *)p);
    if (acc != 0) {
        func_020061E4(0x548);
        func_021D733C(p->f3C, p->f158 + p->f164 - 6, p->f150);
        func_021D69F4(p->f3C, 0, p->f164);
        return;
    }
    if (func_020362DC() == 1) {
        func_020061E4(0x54C);
        func_021D6A9C(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        func_021D5318((u8 *)p);
        func_021D4244((int *)p, (int)func_021D51D4, 0x760);
        return;
    }
    if (func_020362DC() == 8) {
        func_020061E4(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        func_021D4244((int *)p, (int)func_021D52D4, 0x766);
        return;
    }
    sel = func_02035C08(d_021D88D8);
    switch (sel) {
    case 3:
        func_020061E4(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        func_021D4244((int *)p, (int)func_021D52D4, 0x770);
        return;
    case 2:
        if (p->f150 < 3)
            break;
    case 1:
        if (p->f150 < 2)
            break;
    case 0:
        func_020355D8(1);
        p->f164 = sel + 6;
        func_021D69F4(p->f3C, 0, p->f164);
        func_021D6A9C(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        func_021D6E70(p->f3C, &p->f150, sel);
        func_021D733C(p->f3C, p->f158 + p->f164 - 6, p->f150);
        func_020061E4(0x54C);
        func_021D5318((u8 *)p);
        func_021D4244((int *)p, (int)func_021D51D4, 0x78B);
        return;
    }
    if (TOUCHPANEL_HitCont(d_021D88C8) != 0)
        goto end;
    if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) == 1) {
        r = func_021D7374((char *)p->f3C, y, p->f150);
        if (p->f158 != r) {
            p->f158 = r;
            func_021D82A8(p->f40, p->f2C, r - 2);
            func_021D72A0(p->f3C, p->f2C, p->f158 - 2);
            func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
            func_020061E4(0x548);
        }
    }
    return;
end:
    func_021B63D0((struct S *)func_021D6988(p->f3C));
    if (func_021B6448((u8 *)func_021D6988(p->f3C)) == 1) {
        func_02040588(4, 0);
        func_02040588(6, 0);
        func_021D5318((u8 *)p);
        func_021D69F4(p->f3C, p->f34, 9);
        func_021D6D48(p->f3C);
        func_021D7D3C(p->f40);
        func_021D4244((int *)p, (int)func_021D5208, 0x7AD);
    }
}
