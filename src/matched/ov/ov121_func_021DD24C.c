/*
 * function: func_021DD24C
 * address: 0x021DD24C
 * packet: pkt_ov121_021DD24C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, lane P8b, pengy's share, written bottom-up from the
 *   listing; 1844 B incl. an inline pool at 0x021DD598).  Closed with the
 *   matched twin ov010 02157E9C (same game routine, gift mon builder):
 *   - id is a u32 `id` plus a separate `u64 id64 = id;` assigned just before
 *     func_020173F0 (the high word is then a spilled constant at sp+0x18);
 *   - the inner-block locals are declared at function scope in the order
 *     gs, day, month, year, mode, gender, rnd, species, level, hid, id16, id,
 *     id64 (spill slots follow declaration order); `u16 level`, `u32 month`
 *     with `month = (u8)(w >> 8)` (the twin's form), `u8 day`, `u16 year`;
 *   - unsigned loop counter `k` for the 15 ribbon loop (blo);
 *   - the otGender call is written in each arm:
 *     `if (v <= 2) call(v); else { v = f(); call(v); }`.
 *   The six per-function pragmas were checked on the earlier draft and none
 *   closed it; none is needed now.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DBDF4 0x021DBDF4 thumb ov121
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021DA338 0x021DA338 thumb ov121
 *   func_021DA3EC 0x021DA3EC thumb ov121
 *   func_021DC024 0x021DC024 thumb ov121
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
 *   func_02045A98 0x02045A98 arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020185F0 0x020185F0 thumb
 *   func_0202F2AC 0x0202F2AC thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D060 0x0202D060 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0202D6F4 0x0202D6F4 thumb
 *   func_02049238 0x02049238 arm
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DFA14 0x021DFA14 data a4
 *   d_021DF8C0 0x021DF8C0 data a4
 *   g0209DF08 0x0209DF08 data a1
 *   g0209DF0C 0x0209DF0C data a1
 *   gMsgBank 0x020A7370 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

typedef struct { u32 w[51]; } Record;
typedef struct { u32 f0; u32 f4; void *f8; u32 fC; u16 f10; u16 f12; u16 f14; u16 pad; } DE;
typedef struct { DE e[5]; } Desc;

struct Rec {
    u32 f0;
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
    u8 pad5D[0x4F];
    u32 fAC;
    u8 padB0[2];
    u8 fB2;
    u8 fB3;
    u8 fB4a:1;
    u8 fB4b:1;
};

struct Ctx {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

struct CtxB {
    u32 f0;
    u8 pad4[0xB4];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
};

struct Out {
    u8 pad0[0xE0];
    u32 fE0;
    u16 fE4;
    u16 fE6;
    u8 padE8[0x118 - 0xE8];
    u16 heap;
    u8 pad11A[2];
    struct CtxB *b;
    struct Rec *a;
    void *c;
    u8 pad128[0xC];
    u32 f134;
    u32 f138;
    void *f13C;
    void *f140;
    void *f144;
};

extern char d_021DFBB0[];
extern const Desc d_021DFA14;
extern const u32 d_021DF8C0[];
extern u8 g0209DF08;
extern u8 g0209DF0C;
extern void *gMsgBank;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern void func_021DBDF4(void *out, const Record *src, void *p, u16 heap);
struct Mon;
struct MsgBank;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_021DA338(char *p, u16 heap);
extern void func_021DA3EC(char *p, char *desc, void *dst);
extern int func_021DC024(void *p);
extern u32 func_020056EC(u32 range);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_020173F0(u16 species, u16 level, u32 otId, u32 a3, u32 heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, u16 move);
extern void func_02018A00(void *p, u32 species, u32 arg);
extern u16 func_02045A98(void);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_020307B0(void *p);
extern void *func_020185F0(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_020185C4(void *p);
extern int func_0202D7C8(int a0);
extern int func_0202D060(void);
extern u32 func_02017EAC(void *p);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_020185F4(void *p);
extern u32 func_0202D6F4(void *a0, void *mon, u32 a2, u32 a3);
extern void func_02049238(void *p);

struct Out *func_021DD24C(Record *a, struct CtxB *b, void *c, u16 heap)
{
    struct Out *out;
    struct Ctx ctx;
    Desc desc;
    void *res;
    u16 idx;
    void *t4;
    int flags;
    void *mon;
    void *gs;
    u8 day;
    u32 month;
    u16 year;
    u32 mode;
    u32 gender;
    u64 rnd;
    u32 species;
    u16 level;
    u16 hid;
    u32 id16;
    u32 id;
    u64 id64;

    out = func_02030734(heap, 0x148, 0, d_021DFBB0, 0xDD4);
    func_02082BCC(out, 0, 0x148);
    out->heap = heap;
    out->a = (struct Rec *)a;
    out->b = b;
    out->c = c;
    func_02082BCC(&ctx, 0, 0x24);
    ctx.f0 = 0;
    ctx.f8 = b->fB8;
    ctx.fC = b->fBC;
    ctx.f10 = b->fC4;
    ctx.f14 = b->fC8;
    ctx.f18 = b->fCC;
    ctx.f1C = b->fC0;
    ctx.f20 = (u32)c;
    func_021DBDF4(out, a, &ctx, heap);
    desc = d_021DFA14;
    id16 = (heap & 0x7fff) | 0x8000;
    desc.e[1].f8 = func_020457B0(0x25, (u16)id16);
    func_02045994(desc.e[1].f8, (const u16 *)((char *)out->a + 0x60), 0x24);
    if (out->a->fB4b)
        idx = out->a->fB2 + 0x19d;
    else
        idx = out->a->fB2 + 0x9d;
    desc.e[2].f8 = func_02045EC0((void *)b->fC0, idx);
    desc.e[4].f8 = func_020457B0(0x80, heap);
    flags = out->a->fAC;
    t4 = func_02045EC0((void *)b->fC0, 0x9a);
    res = 0;
    func_0201EFA4((void *)b->fCC, 0, (u16)(flags >> 16), 4, 1, 1);
    func_0201EFA4((void *)b->fCC, 1, (u8)(flags >> 8), 2, 0, 1);
    func_0201EFA4((void *)b->fCC, 2, (u8)flags, 2, 0, 1);
    func_0201F250((void *)b->fCC, desc.e[4].f8, t4);
    out->f144 = func_021DA338(*(void **)b, heap);
    func_021DA3EC(out->f144, (char *)(&desc), (void *)b->fC8);
    func_02045808(desc.e[1].f8);
    func_02045808(desc.e[2].f8);
    func_02045808(desc.e[4].f8);
    func_02045808(t4);
    if (func_021DC024(out) == 1) {
        struct Rec *r = out->a;
        u16 mv[4];
        u8 iv[6];
        int i;
        u32 k;
        u32 ivs;

        gs = out->c;
        hid = id16;
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
        if (r->fB3 == 1 && species <= 0x289 && species != 0 && level <= 0x64 && r->f10 <= 0x289 - 0x17) {
            if (level == 0)
                level = (u16)(func_020056EC(0x64) + 1);
            if (r->f0 == 0)
                id = func_02008530((const struct Sub0200852CObj *)func_02012944(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = func_020056EC(0x20);
            }
            id64 = id;
            mon = func_020173F0((u16)species, level, id, 0, hid);
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
                    func_02017E40(mon, d_021DF8C0[k], 1);
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
                    v = func_02008550((const struct Sub0200852CObj *)func_02012944(gs));
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
            goto end;
        }
    end:
        {
            void *arc = (void *)func_0202D7C8((u16)id16);
            u32 a0, a1, a2, a3;
            out->fE4 = r->species;
            out->fE6 = r->form;
            out->fE0 = r->f5C;
            a0 = func_0202D060();
            a1 = func_02017E1C(res, 5, 0);
            a2 = func_02017E1C(res, 0x6f, 0);
            a3 = func_02017E1C(res, 0x6e, 0);
            idx = func_0202D0D4(a0, a1, a2, a3, func_02017EAC(res), 0, func_02017E1C(res, 0x4c, 0));
            out->f13C = func_02049F78(arc, idx, (u32)(&out->f140), out->heap);
            out->f134 = (u32)func_0202D6F4(&out->f138, func_020185F4(res), 0, out->heap);
            func_020307B0(res);
            func_02049238(arc);
        }
    }
    return out;
}
