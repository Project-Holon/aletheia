/*
 * file:     btl_server_p75.c
 * unit:     yes
 * function: func_021C6948, func_021C69B8, func_021C6A04, func_021C6A9C, func_021C6B5C, func_021C6BB8, func_021C6BF8, func_021C6CAC, func_021C6DD0, func_021C6E00, func_021C6E3C, func_021C6F0C, func_021C6F34
 * address:  0x021C6948
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5C08  0x021D5C08  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   sub_0201C1F4  0x0201C1F4  thumb
 *   sub_0201BD28  0x0201BD28  thumb
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021BF324  0x021BF324  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   sub_0201C284  0x0201C284  thumb
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   func_021D7930  0x021D7930  thumb  ov093
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_0201BD28 0x0201BD28 thumb
 *   func_0201C1BC 0x0201C1BC thumb
 *   func_021D7B3C 0x021D7B3C thumb ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_021E8DA8 0x021E8DA8 thumb ov093
 *   func_021C7038 0x021C7038 thumb ov093
 *   func_021D79E8 0x021D79E8 thumb ov093
 *   func_021C5750 0x021C5750 thumb ov093
 *   func_021C6FC0 0x021C6FC0 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021C6FB0  0x021C6FB0  thumb  ov093
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Q { u16 h0; u8 pad[6]; u32 w8; };

typedef enum { KIND_NONE, KIND_FIRST, KIND_SECOND } Kind;

extern u32 func_021D5C08(struct UtilWork *p);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u32 sub_0201C1F4(u16 id);
extern u32 sub_0201BD28(u16 id, u32 field);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern u32 func_021D7B10(u32 a, u32 b);
extern int func_021D59B4(u8 *p, int k);
extern int func_021BF324(u8 *p, u8 *a, u8 *b);
extern u32 func_021D78AC(u32 range);
extern void func_021D75A8(int key, u32 val);
extern u8 func_021D5F14(struct UtilWork *p);
extern int func_021D7930(int i);
extern int func_021B911C(int a, int b);
extern u32 sub_0201C284(u16 id);
extern u32 func_0201BD28(u32 v, u32 n);
extern u32 func_0201C1BC(u16);
extern u32 func_021D7B3C(u32, u32);
extern void func_021D70E4(void *a, int id);
extern u16 func_021D57FC(void *);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int);
extern int func_021E8DA8(int);
extern int func_021C7038(u8 *, u8 *, u8 *, u32, u8);
extern int func_021D79E8(int, int);
extern void func_021C5750(u8 *, u8 *);
extern void func_021C6FC0(u8 *, u8 *);
extern int func_021EF948(int);
extern int func_021D5814(void *p, int k);
extern void func_021C6FB0(u8 *p, u8 *a);
int func_021C6948(u8 *p, u8 *a, u8 *b, u32 v);
int func_021C69B8(u8 *p, u8 *a, u32 c, u16 id);
int func_021C6A04(u8 *p, u8 *a, u8 *b, struct Q *q);
int func_021C6A9C(u8 *p, u8 *a, u8 *b, u16 id);
int func_021C6B5C(u8 *p, u8 *a, u8 *b, u8 *q);
void func_021C6BB8(u8 *p, u8 *a, u8 *b);
int func_021C6BF8(u8 *p, u8 *a, u8 *b, u16 q);
int func_021C6CAC(u8 *p, u8 *a, u16 b, int amount, int *out);
void func_021C6DD0(u8 *p, u8 *a);
void func_021C6E00(u8 *p, u8 *a, u8 k);
int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
int func_021C6F0C(u8 *p, u8 *a, int k);
int func_021C6F34(u8 *p, u8 *a, int f);




int func_021C6948(u8 *p, u8 *a, u8 *b, u32 v)
{
    int r = 0;
    u32 t = func_021D5C08((struct UtilWork *)b);
    if (t != 0x10) {
        func_021D74F8(11765);
        func_021D75EC(3, func_021D5440(a));
        func_021D75EC(4, func_021D5440(b));
        func_021D75EC(0x21, t);
        func_021D7630(0x42, 1);
        func_021D70F0(p, 0x99);
        if (func_021D775C(0x42)) r = 1;
        func_021D7540(11775);
    }
    return r;
}





int func_021C69B8(u8 *p, u8 *a, u32 c, u16 id)
{
    int r = sub_0201C1F4(id);
    if (r == 0) {
        func_021D74F8(0x2E15);
        func_021D75EC(3, func_021D5440(a));
        func_021D7630(0x51, 0);
        func_021D70F0(p, 0x32);
        r = func_021D775C(0x51);
        func_021D7540(0x2E1A);
    }
    return r;
}





int func_021C6A04(u8 *p, u8 *a, u8 *b, struct Q *q)
{
    int x, y;
    u32 t = sub_0201BD28(q->h0, 4);
    func_021D74F8(0x2E2F);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, q->h0);
    func_021D75EC(0x1a, q->w8);
    func_021D7630(0x2b, t);
    func_021D7674(0x35, 4 << 10, 0x19A, 4 << 15);
    func_021D70F0(p, 0x34);
    x = func_021D775C(0x2b);
    y = func_021D775C(0x35);
    func_021D7540(0x2E39);
    return func_021D7B10(x, y);
}





int func_021C6A9C(u8 *p, u8 *a, u8 *b, u16 id)
{
    u8 x, y, c;
    int r, t;
    x = func_021D59B4(a, 15);
    y = func_021D59B4(b, 15);
    if (x < y) return 0;
    func_021D74F8(0x2E5A);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    r = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x70);
    t = func_021D775C(0x41);
    func_021D7540(0x2E60);
    if (t) return r;
    if (func_021BF324(p, a, b)) {
        r = 1;
    } else {
        c = sub_0201BD28(id, 4);
        c += (u8)(x - y);
        if (func_021D78AC(100) < c) r = 1;
    }
    return r;
}





int func_021C6B5C(u8 *p, u8 *a, u8 *b, u8 *q)
{
    int r;
    func_021D74F8(11907);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x16, q[6]);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x30);
    r = func_021D775C(0x51);
    func_021D7540(11914);
    return r;
}





void func_021C6BB8(u8 *p, u8 *a, u8 *b)
{
    func_021D74F8(11928);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D70F0(p, 0x31);
    func_021D7540(11932);
}





#pragma opt_lifetimes off




/*
 * note 2026-10-05 (wave P13 B10): the older DIFF (12 B, p and h/r in each other's
 *   r4/r5) closed with #pragma opt_lifetimes off around the function, see
 *   docs/idioms/a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.md.
 *   Source is unchanged from the old draft. Plain literals already (11952, 0x2c).
 *   Callees: func_021D5F14 returns u8, func_021D7930 takes u8 (both matched);
 *   sub_0201BD28 and sub_0201C284 return u32 (matched arm9 units).
 */
int func_021C6BF8(u8 *p, u8 *a, u8 *b, u16 q)
{
    int r, n;
    u16 h;
    h = sub_0201BD28(q, 7);
    h = h + func_021D5F14((struct UtilWork *)a);
    func_021D74F8(11952);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75A8(0x2c, h);
    r = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x36);
    if (func_021D775C(0x41) == 0) {
        if (sub_0201C284(q)) {
            r = 1;
        } else {
            n = func_021D775C(0x2c);
            if (n > 4) n = 4;
            r = func_021D7930((u8)((u16)n));
        }
        if (func_021B911C(*(int *)(p + 4), 3)) r = 1;
    }
    func_021D7540(11975);
    return r;
}





#pragma opt_lifetimes reset




/*
 * note 2026-10-05 (wave P8): earlier DIFF (288 vs 292 B) closed by local declaration
 *   order (line, n, v, t, y, z, x, then kind); spill slots follow it. Plain literals
 *   12019 and 12032 are EXACT, so no line local. Also EXACT with --lang c.
 */
int func_021C6CAC(u8 *p, u8 *a, u16 b, int amount, int *out)
{
    u8 n, v;
    u8 t, y, z, x;
    int kind;
    n = func_021D5440(a);
    v = func_0201BD28((u32)b, 30);
    kind = 0;
    *out = kind;
    if (v) kind = KIND_FIRST;
    else {
        v = func_0201BD28((u32)b, 31);
        if (v) kind = KIND_SECOND;
    }
    if (func_0201C1BC(b) == 8) return 0;
    func_021D74F8(12019);
    func_021D75EC(3, n);
    func_021D75A8(0x35, v);
    func_021D75A8(0x36, 0);
    func_021D7630(0x41, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x50);
    x = func_021D775C(0x35);
    y = func_021D775C(0x41);
    z = func_021D775C(0x51);
    t = func_021D775C(0x36);
    func_021D7540(12032);
    if (z == 0 && y == 1) return 0;
    x += t;
    if (x) {
        if (kind == KIND_SECOND) {
            amount = func_021D7B3C(func_021D59B4(a, 14), x);
            if (amount < 1) amount = 1;
        } else if (amount != 0) {
            amount = func_021D7B3C(amount, x);
            if (amount < 1) amount = 1;
        }
        *out = z;
        return amount;
    }
    return 0;
}



void func_021C6DD0(u8 *p, u8 *a)
{
    int line = 12077;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 114);
    func_021D7540(line + 3);
}



void func_021C6E00(u8 *p, u8 *a, u8 k)
{
    int line = 12093;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(3, k);
    func_021D70E4(p, 115);
    func_021D7540(line + 4);
}



int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag)
{
    int r, x;
    int changed = 0;
    if (q[6] == 17) return 3;
    x = func_021D57FC(b);
    r = func_021C7038(p, a, b, q[6], func_021E8CFC(x));
    if (func_021E8DA8(x) == 0)
        r = func_021D79E8(r, func_021C7038(p, a, b, q[6], func_021E8D04(x)));
    if (r != 0) {
        if (q[6] != 4) return r;
        changed = func_021C6F0C(p, b, 0);
        if (changed == 0) return r;
        r = 0;
    } else if (q[6] == 4) {
        if (func_021C6F0C(p, b, 1) == 0) return 3;
    }
    if (r == 0 && flag != 0) {
        if (changed == 0) func_021C5750(p, b);
        else func_021C6FC0(p, b);
    }
    return r;
}



int func_021C6F0C(u8 *p, u8 *a, int k)
{
    if (func_021EF948(2) == 0 && func_021C6F34(p, a, k) != 0)
        return 1;
    return 0;
}


int func_021C6F34(u8 *p, u8 *a, int f)
{
    int t;
    u8 x, y;
    if (f) {
        t = func_021D5814(a, 2);
    } else {
        t = 0;
    }
    func_021D74F8(12220);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, (u8)t);
    func_021D7630(0x41, (u8)0);
    func_021D70F0(p, 0x12);
    func_021C6FB0(p, a);
    x = func_021D775C(0x51);
    y = func_021D775C(0x41);
    func_021D7540(12228);
    if (y) return 0;
    return x;
}
