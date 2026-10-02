/*
 * function: func_021D8288
 * address: 0x021D8288
 * packet: pkt_ov131_021D8288
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 relaunch R8. The 0 passed as the number style to the
 *   later SetNumber calls is the same u8 local that later holds the best
 *   row index (stack slot 0x14); max is seeded from it before the table
 *   copies, and the loop counter is zeroed before the row lookup.
 *   func_0201EC74 takes an int heap here (no u8 narrowing in the caller).
 * symbols:
 *   func_021D8784 0x021D8784 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   d_021DC24C 0x021DC24C data
 *   d_021DC264 0x021DC264 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern u32 func_02017E88(void *, u32, u32);
extern u32 func_0202F498(void *, u32);
extern void *func_02012944(void *);
extern u32 func_02018488(void *, void *);
extern void *func_02045EC0(void *, u32);
extern void *func_02045770(void *);
extern void func_02045808(void *);
extern void *func_020457B0(u32, u32);
extern void *func_0201EC74(int, int, int);
extern void func_0201C724(void *, void *, s16, s16, void *, void *, u16);
extern void func_0201EFA4(void *, u32, u32, u32, u32, u32);
extern void func_0201EE0C(void *, u32, const void *, u32, u32, u32);
extern void func_0201F250(void *, void *, void *);
extern void func_0201ED04(void *);
extern int sub_0201D2C8(void *);
extern void *func_021D8784(void *, u8 *, u32);
extern const u32 d_021DC24C[6];
extern const u8 d_021DC264[6][6];

struct Tbl6 { u32 v[6]; };
struct Tbl36 { u8 v[6][6]; };

void func_021D8288(u8 *a, u8 *p, void *mon)
{
    void *s6c;
    void *s68;
    u32 v5c;
    int y;
    u32 known;
    u32 isEgg;
    u32 v4c;
    u32 v48;
    u32 v44;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u32 v2c;
    u32 v28;
    u32 v24;
    u32 v20;
    u32 flags;
    void *str;
    void *ws;
    void *t;
    u32 f96;
    u32 fl0;
    u32 fl1;
    u32 fl2;
    u32 fl3;
    u16 msg;
    u16 msgAlt;
    u8 best;

    y = 0;
    isEgg = func_02017E88(mon, 0x4c, 0);
    v5c = func_02017E88(mon, 0x70, 0);
    v4c = func_02017E88(mon, 9, 0);
    v48 = func_02017E88(mon, 0x8f, 0);
    v44 = func_02017E88(mon, 0x90, 0);
    v40 = func_02017E88(mon, 0x91, 0);
    v3c = func_02017E88(mon, 0x92, 0);
    v38 = func_02017E88(mon, 0x93, 0);
    v34 = func_02017E88(mon, 0x94, 0);
    v30 = func_02017E88(mon, 0x99, 0);
    v2c = func_02017E88(mon, 0x6d, 0);
    v28 = func_02017E88(mon, 0x77, 0);
    v24 = func_02017E88(mon, 0, 0);
    v20 = func_02017E88(mon, 0x95, 0);
    f96 = func_02017E88(mon, 0x96, 0);
    fl0 = func_0202F498(mon, 0);
    fl1 = func_0202F498(mon, 1);
    fl2 = func_0202F498(mon, 2);
    fl3 = func_0202F498(mon, 3);
    flags = fl0 | fl1 | fl2 | fl3;
    known = func_02018488(mon, func_02012944(*(void **)(*(u8 **)(a + 8) + 8)));

    if (isEgg == 0) {
        t = func_02045EC0(*(void **)(p + 0x38), v5c);
        func_0201C724(*(void **)(a + 0x84), func_02045770(*(void **)(p + 0x34)), 1, 1, t, *(void **)(a + 0x80), 0x440);
        func_02045808(t);
        y = 0x10;
    }
    str = func_020457B0(0x100, *(u16 *)a);
    ws = func_0201EC74(10, 0x20, *(u16 *)a);
    if (isEgg == 0) {
        if (f96 == 0x7531) {
            msgAlt = 0x29;
            msg = 0x2b;
            if (v2c == 1) {
                msgAlt = 0x2d;
                msg = 0x2f;
            }
            switch (v28) {
            case 1: case 2: case 3:
                f96 = 0x7536;
                break;
            case 4: case 5:
                f96 = 0x7534;
                break;
            case 7: case 8:
                f96 = 0x7535;
                msg = msgAlt;
                break;
            case 10: case 11: case 12:
                f96 = 0x7537;
                msg = msgAlt;
                break;
            case 15:
                f96 = 0x7538;
                break;
            default:
                v20 = 0x7539;
                msg = msgAlt;
                break;
            }
        } else if (f96 >= 0x753a && f96 <= 0x753d && flags == 1) {
            switch (f96 - 0x753a) {
            case 0: msg = 0x31; break;
            case 1: msg = 0x32; break;
            case 2: msg = 0x33; break;
            case 3: msg = 0x34; break;
            }
        } else if (v2c == 0) {
            if (v20 == 0) {
                if (f96 == 0x7532) {
                    msg = 0x1b;
                } else {
                    msg = 0x19;
                }
            } else if (v20 <= 60000) {
                msg = 0x1d;
            } else {
                msg = 0x1f;
            }
        } else {
            msg = 0x21;
            if (v20 != 0) {
                msg = 0x23;
            }
        }
        if (known == 0) {
            if (f96 < 0x753a || f96 > 0x753d) {
                msg++;
            }
        }
    } else if (v2c == 0) {
        if (known == 1) {
            msg = 0x53;
        } else {
            msg = 0x54;
        }
    } else {
        msg = 0x55;
        if (known != 1) {
            msg = 0x56;
        }
    }
    s68 = func_021D8784(a, p, v20);
    s6c = func_021D8784(a, p, f96);
    func_0201EFA4(ws, 0, v3c, 2, 2, 1);
    best = 0;
    func_0201EFA4(ws, 1, v38, 2, best, 1);
    func_0201EFA4(ws, 2, v34, 2, best, 1);
    func_0201EFA4(ws, 3, v30, 3, best, 1);
    func_0201EE0C(ws, 4, s6c, 0, 1, 2);
    func_0201EFA4(ws, 5, v48, 2, 2, 1);
    func_0201EFA4(ws, 6, v44, 2, best, 1);
    func_0201EFA4(ws, 7, v40, 2, best, 1);
    func_0201EE0C(ws, 8, s68, best, 1, 2);
    t = func_02045EC0(*(void **)(p + 0x38), msg);
    func_0201F250(ws, str, t);
    func_0201C724(*(void **)(a + 0x84), func_02045770(*(void **)(p + 0x34)), 1, y + 1, str, *(void **)(a + 0x80), 0x440);
    func_0201ED04(ws);
    y += sub_0201D2C8(str) << 4;
    func_02045808(s68);
    func_02045808(s6c);
    func_02045808(t);
    func_02045808(str);
    if (isEgg == 0) {
        struct Tbl6 ids;
        struct Tbl36 rows;
        u8 max;
        u8 i;
        const u8 *row;
        u32 v;
        max = best;
        ids = *(const struct Tbl6 *)d_021DC24C;
        rows = *(const struct Tbl36 *)d_021DC264;
        i = 0;
        row = rows.v[(u8)(v24 % 6)];
        for (; i < 6; i++) {
            v = func_02017E88(mon, ids.v[row[i]], 0);
            if (max < v) {
                max = v;
                best = row[i];
            }
        }
        t = func_02045EC0(*(void **)(p + 0x38), best * 5 + 0x35 + max % 5);
        func_0201C724(*(void **)(a + 0x84), func_02045770(*(void **)(p + 0x34)), 1, y + 1, t, *(void **)(a + 0x80), 0x440);
        func_02045808(t);
    } else {
        u32 id;
        if (v4c <= 5) {
            id = 0x57;
        } else if (v4c <= 10) {
            id = 0x58;
        } else if (v4c <= 40) {
            id = 0x59;
        } else {
            id = 0x5a;
        }
        t = func_02045EC0(*(void **)(p + 0x38), id);
        func_0201C724(*(void **)(a + 0x84), func_02045770(*(void **)(p + 0x34)), 1, y + 1, t, *(void **)(a + 0x80), 0x440);
        func_02045808(t);
    }
}
