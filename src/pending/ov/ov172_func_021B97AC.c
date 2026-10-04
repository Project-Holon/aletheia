/*
 * function: func_021B97AC
 * address: 0x021B97AC
 * packet: pkt_ov172_021B97AC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-04): 520 bytes, 10 differing bytes, scheduling only. Residue: in the func_021B9E5C call (case 1) the
 *   original emits `movs r2,#2; str r0,[sp]; movs r0,#3; lsls r2; lsls r0; str r0,[sp,#4]`; mine emits
 *   `str r0,[sp]; movs r0,#3; movs r2,#2; lsls r0; lsls r2; str r0,[sp,#4]` (same instructions, order of the two
 *   constant loads differs). Tried: local for the func_021BA15C result, local for func_021BA170 + 0x800, 0x800 + v,
 *   inline call arguments. Levers that mattered: failure paths `break` (switch default becomes `bhi island`),
 *   success paths `return` (inline epilogue), entry test as `if (r == 1) return;`, and
 *   `(u8 *)func_021BA170() + (b18 << 11)` for the add operand order in case 2.
 * symbols:
 *   func_021B9F4C 0x021B9F4C thumb ov172
 *   func_021B9DF8 0x021B9DF8 thumb ov172
 *   func_021BA0BC 0x021BA0BC thumb ov172
 *   func_021B69E0 0x021B69E0 thumb ov172
 *   func_021B9E3C 0x021B9E3C thumb ov172
 *   func_0203630C 0x0203630C arm
 *   func_021BA120 0x021BA120 thumb ov172
 *   func_021BA158 0x021BA158 thumb ov172
 *   func_021BA170 0x021BA170 thumb ov172
 *   func_021BA15C 0x021BA15C thumb ov172
 *   func_021B9E5C 0x021B9E5C thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021B8C34 0x021B8C34 thumb ov172
 *   func_021B8B74 0x021B8B74 thumb ov172
 *   func_021BA174 0x021BA174 thumb ov172
 *   func_021B891C 0x021B891C thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct St {
    u32 state;
    u32 sub;
    u8 pad08[5];
    u8 b0d;
    u8 pad0e[2];
    u32 *f10;
    u32 f14;
    u8 b18;
    u8 pad19[7];
    struct Rec *f20;
    void *f24;
    u8 pad28[4];
    void *f2c;
    u8 pad30[0x74];
    u32 fa4;
};

extern int func_021B9F4C(void *ctx, struct St *st, int mode);
extern int func_021B9DF8(void *ctx, struct St *st);
extern int func_021BA0BC(u32 *p);
extern void func_021B69E0(void);
extern void func_021B9E3C(void *ctx, struct St *st);
extern u32 func_0203630C(void);
extern int func_021BA120(u32 *p);
extern u32 func_021BA158(u32 *p);
extern u32 func_021BA170(u32 *p);
extern u32 func_021BA15C(u32 *p);
extern void func_021B9E5C(void *ctx, struct St *st, u32 a, int b, u32 c, u32 d);
extern u32 func_021BDFE4(void *ctx);
extern int func_021B8C34(void *ctx, u32 id);
extern int func_021B8B74(void *ctx, u32 id);
extern int func_021BA174(u32 *a, u8 *b, void *c, u32 n);
extern int func_021B891C(void *ctx, u32 id, struct Rec *r);
extern int func_021B8740(void *ctx, u32 id, u8 c, u32 d);
extern u32 func_021BDFEC(void *ctx);
extern u32 func_021BA244(u32 v);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *p, int v);
extern void func_02045334(void *p);

void func_021B97AC(void *ctx, struct St *st)
{
    int mode = func_021B9F4C(ctx, st, 1);
    u32 id;
    u32 pos;
    int busy;
    u32 v;

    if (func_021B9DF8(ctx, st) == 1)
        return;
    switch (st->sub) {
    case 0:
        if (func_021BA0BC(st->f10) == 1) {
            st->fa4 = 1;
            st->sub = 1;
            st->b18 = 0;
            st->f14 = 0;
            func_021B69E0();
            func_021B9E3C(ctx, st);
            return;
        }
        break;
    case 1:
        if (mode != 1 && (func_0203630C() & 0x101) == 0)
            func_021BA120(st->f10);
        if (func_021BA158(st->f10) == 0) {
            st->sub = 2;
            st->fa4 = 2;
        }
        v = func_021BA170(st->f10);
        func_021B9E5C(ctx, st, v + 0x800, 9, func_021BA15C(st->f10), 0xC000);
    case 2:
        id = func_021BDFE4(ctx);
        if (func_021B8C34(ctx, id) != 1)
            break;
        busy = func_021B8B74(ctx, id);
        pos = func_021BA15C(st->f10);
        if (st->f14 == 0 && busy == 0) {
            if (pos >= (u32)(st->b18 + 1) << 11 || st->sub == 2) {
                int n = func_021BA174(st->f10, (u8 *)func_021BA170(st->f10) + (st->b18 << 11), st->f24, 0x800);
                st->f20->b5 = st->b18;
                st->f20->h0 = n;
                st->f20->h2 = pos;
                st->f20->b6 = st->b0d;
                st->f20->b4 = (st->sub == 2 && pos <= (u32)(st->b18 + 1) << 11) ? 1 : 0;
                st->f14 = 1;
            }
        }
        if (st->f14 == 1) {
            if (func_021B891C(ctx, id, st->f20) == 1) {
                st->b18++;
                st->f14 = 0;
                if (st->f20->b4 == 1) {
                    st->sub = 3;
                    return;
                }
            }
        }
        break;
    case 3:
        id = func_021BDFE4(ctx);
        if (func_021B8B74(ctx, id) != 0)
            break;
        if (func_021B8740(ctx, id, 7, 0) == 1) {
            st->sub = 4;
            func_02043B5C(func_02045770(st->f2c), 0);
            func_02045334(st->f2c);
            return;
        }
        break;
    case 4:
        if (st->f20->h2 > 0x20) {
            if (func_021BA244(func_021BDFEC(ctx)) == 1) {
                st->sub = 5;
                return;
            }
        } else {
            st->state = 5;
            return;
        }
        break;
    case 5:
        id = func_021BDFE4(ctx);
        if (func_021BA244(func_021BDFEC(ctx)) == 0) {
            if (func_021B8740(ctx, id, 8, 0) == 1)
                st->state = 5;
        }
        break;
    }
}
