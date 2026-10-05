/*
 * function: func_021DEFAC
 * address: 0x021DEFAC
 * packet: pkt_ov121_021DEFAC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, lane R9, pengy's share): 1336 B plus a 12 B tail pool; written
 *   bottom-up from the listing (the show tool stops at the mid-function pool).  Same
 *   game routine as ov010 02157E9C / ov121 021DD24C (gift mon builder), here a
 *   validator that returns an error count:
 *   - count is a plain int kept in memory ([sp+0x3c]); `type = r->fB3` is a u8 local,
 *     the switch runs on it, and the three fB3 re-tests are separate const-pointer
 *     predicates (chk1/chk2/chk3, inlined) so they reload the byte; with plain
 *     `r->fB3` in the body the compiler folds the tests (reload gone, 8 B short);
 *   - the build part uses separate guard ifs each with `res = 0; goto end;` (the
 *     ov010 form: `beq next; b far` islands);
 *   - chk2/chk3 return int and are stored in a u16 `t` (truncation after the merge);
 *     their first test is an early return, the rest an && chain;
 *   - res is not initialised before the guards (it lives in r4 after r is dead);
 *   - table at 0x021DFB2C (ribbon ids), threshold 0x800 at +0xB0, species table
 *     bound 0x289 and item bound 0x272 as in the twins.
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_020056EC 0x020056EC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_020186C8 0x020186C8 thumb
 *   func_02017588 0x02017588 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017FA8 0x02017FA8 thumb
 *   func_0201808C 0x0201808C thumb
 *   func_020180F4 0x020180F4 thumb
 *   func_02018A00 0x02018A00 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020185F0 0x020185F0 thumb
 *   func_0202F2AC 0x0202F2AC thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   g0209DF08 0x0209DF08 data a1
 *   g0209DF0C 0x0209DF0C data a1
 *   d_021DFB2C 0x021DFB2C data a4
 *   gMsgBank 0x020A7370 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

struct Rec {
    s32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 mv[4];
    u16 species;
    u8 form;
    u8 f1D;
    u16 f1E;
    u8 pad20[0x14];
    u8 f34;
    u8 f35;
    u8 f36;
    u8 f37;
    u16 f38;
    u16 f3A;
    u8 f3C;
    u8 f3D;
    u8 f3E;
    u8 f3F;
    u8 f40;
    u8 f41;
    u8 pad42;
    u8 iv0, iv1, iv2, iv6, iv7, iv3;
    u8 pad49;
    u16 f4A;
    u8 pad4C[0xE];
    u8 f5A;
    u8 f5B;
    u8 f5C;
    u8 pad5D[3];
    u16 name[0x25];
    u8 pad_AA[2];
    u32 fAC;
    u16 fB0;
    u8 fB2;
    u8 fB3;
};

extern const u32 d_021DFB2C[];
extern u8 g0209DF08;
extern u8 g0209DF0C;
extern void *gMsgBank;

extern u32 func_020056EC(u32 range);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const u8 *p);
extern void *func_020173F0(u16 species, u16 level, u32 otId, u32 a3, u32 heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(void *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017FA8(void *p);
extern u16 func_0201808C(void *p, u16 move);
extern void func_020180F4(void *p, u16 move);
extern void func_02018A00(void *p, u32 species, u32 arg);
extern u16 func_02045A98(void);
extern u16 *func_020084F4(const u8 *p);
extern u32 func_02008550(const u8 *p);
extern void func_020307B0(void *p);
extern void *func_020185F0(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_020185C4(void *p);
extern void *func_02045EC0(void *bank, u32 idx);
extern void func_02045808(void *p);

static inline int chk1(const struct Rec *r)
{
    return r->fB3 == 1;
}

static inline int chk2(const struct Rec *r)
{
    if (r->fB3 != 2)
        return 0;
    if (r->f0 > 0 && r->f0 <= 0x272)
        return r->f0;
    return 0;
}

static inline int chk3(const struct Rec *r)
{
    if (r->fB3 != 3)
        return 0x30;
    if (r->f0 >= 0x21 && r->f0 <= 0x26)
        return r->f0;
    return 0x30;
}

int func_021DEFAC(struct Rec *r, void *gs, u16 heap)
{
    int count;
    u8 type;
    u16 t;
    int bad;
    int i;
    void *res;
    void *mon;
    u16 mv[4];
    u8 iv[6];
    u32 k;
    u32 ivs;
    u8 day;
    u32 month;
    u16 year;
    u32 mode;
    u32 gender;
    u64 rnd;
    u32 species;
    u16 level;
    u32 id;
    u64 id64;

    count = 0;
    bad = 1;
    for (i = 0; i < 0x25; i++) {
        if (r->name[i] == func_02045A98())
            bad = 0;
    }
    if (bad)
        count++;
    if (r->fB0 >= 0x800)
        count++;
    type = r->fB3;
    if (type == 0 || type >= 4)
        count++;
    switch (type) {
    case 1:
        level = r->f5B;
        id = r->f0;
        species = r->species;
        gender = r->f35;
        mode = r->f36;
        iv[0] = r->iv0;
        iv[1] = r->iv1;
        iv[2] = r->iv2;
        iv[3] = r->iv7;
        iv[4] = r->iv3;
        iv[5] = r->iv6;
        mv[0] = r->mv[0];
        mv[1] = r->mv[1];
        mv[2] = r->mv[2];
        mv[3] = r->mv[3];
        if (!chk1(r)) {
            res = 0;
            goto end;
        }
        if (species > 0x289) {
            res = 0;
            goto end;
        }
        if (species == 0) {
            res = 0;
            goto end;
        }
        if (level > 0x64) {
            res = 0;
            goto end;
        }
        if (r->f10 > 0x272) {
            res = 0;
            goto end;
        }
        {
            if (level == 0)
                level = (u16)(func_020056EC(0x64) + 1);
            if (r->f0 == 0)
                id = func_02008530(func_02012944(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = func_020056EC(0x20);
            }
            id64 = id;
            mon = func_020173F0((u16)species, level, id, 0, heap);
            ivs = (iv[0] & 31) | ((iv[1] & 31) << 5) | ((iv[2] & 31) << 10) | ((iv[3] & 31) << 15) | ((iv[4] & 31) << 20) | ((iv[5] & 31) << 25);
            if (mode == 4)
                mode = (u8)func_020056EC(3);
            switch (mode) {
            case 0:
                i = 0;
                break;
            case 1:
                i = 1;
                break;
            case 2:
                i = 0;
                break;
            case 3:
                i = 2;
                break;
            default:
                res = 0;
                goto end;
            }
            if (r->f8 != 0)
                rnd = r->f8;
            else {
                if (r->f37 == 0)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 0);
                else if (r->f37 == 1)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 2);
                else if (r->f37 == 2)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 1);
            }
            func_02017588(mon, r->species, level, id64, ivs, rnd);
            func_02017E40(mon, 6, r->f10);
            func_02017FA8(mon);
            for (i = 0; i < 4; i++) {
                u16 m = mv[i];
                if (m != 0 && m < 0x230) {
                    if (func_0201808C(mon, m) == 0xffff)
                        func_020180F4(mon, m);
                }
            }
            if (r->f8 == 0 && mode == 2)
                func_02018A00(mon, species, r->form);
            func_02017E40(mon, 0x6f, r->form);
            if (r->fE != 0 && r->fE <= 0x19)
                func_02017E40(mon, 0x98, r->fE);
            else
                func_02017E40(mon, 0x98, 4);
            if (r->f3C != 0)
                func_02017E40(mon, 0x99, r->f3C);
            func_02017E40(mon, 0x13, r->f3D);
            func_02017E40(mon, 0x14, r->f3E);
            func_02017E40(mon, 0x15, r->f3F);
            func_02017E40(mon, 0x16, r->f40);
            func_02017E40(mon, 0x17, r->f41);
            func_02017E40(mon, 0x18, r->f41);
            for (k = 0; k < 15; k++) {
                if (r->fC & (1 << k))
                    func_02017E40(mon, d_021DFB2C[k], 1);
            }
            if (r->f4 == 0)
                func_02017E40(mon, 0x77, g0209DF08);
            else
                func_02017E40(mon, 0x77, r->f4);
            if (r->f1D == 0)
                func_02017E40(mon, 0xc, g0209DF0C);
            else
                func_02017E40(mon, 0xc, r->f1D);
            if (r->f1E == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f1E != func_02045A98())
                func_02017E40(mon, 0x74, (u32)&r->f1E);
            {
                u32 v = r->f34;
                if (v == 0xff)
                    v = (u8)func_020056EC(0x19);
                func_02017E40(mon, 0x70, v);
            }
            func_02017E40(mon, 0x95, r->f38);
            func_02017E40(mon, 0x96, r->f3A);
            if (r->f4A == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f4A == func_02045A98())
                func_02017E40(mon, 0x8e, (u32)func_020084F4(func_02012944(gs)));
            else
                func_02017E40(mon, 0x8e, (u32)&r->f4A);
            {
                u32 v = r->f5A;
                if (v <= 2)
                    func_02017E40(mon, 0x9a, v);
                else {
                    v = func_02008550(func_02012944(gs));
                    func_02017E40(mon, 0x9a, v);
                }
            }
            if (r->f5C != 0) {
                void *s;
                func_02017E40(mon, 0x4c, 1);
                s = func_02045EC0(gMsgBank, 0x28a);
                func_02017E40(mon, 0x73, (u32)s);
                func_02045808(s);
                func_02017E40(mon, 9, 10);
            }
            {
                int w = r->fAC;
                u32 loc;
                year = w >> 16;
                month = (u8)(w >> 8);
                day = w;
                loc = r->f5C ? r->f38 : r->f3A;
                func_0202F2AC(func_020185F0(mon), loc, year - 2000, month, day);
            }
            func_020185C4(mon);
            res = 0;
            if (func_02017E1C(mon, 3, 0) != 0)
                func_020307B0(mon);
            else
                res = mon;
        }
    end:
        if (res == 0)
            count++;
        else
            func_020307B0(res);
        break;
    case 2:
        t = chk2(r);
        if (t == 0)
            count++;
        break;
    case 3:
        t = chk3(r);
        if (t == 0x30)
            count++;
        break;
    }
    return count;
}
