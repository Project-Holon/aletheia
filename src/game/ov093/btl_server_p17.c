/*
 * file:     btl_server_p17.c
 * unit:     yes
 * function: func_021BDE18, func_021BDE48, func_021BDE98
 * address:  0x021BDE18
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
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
 *   func_021D5C08 0x021D5C08 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021BE518 0x021BE518 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021BE924 0x021BE924 thumb ov093
 *   func_021C001C 0x021C001C thumb ov093
 *   func_021C62D8 0x021C62D8 thumb ov093
 *   func_021C5604 0x021C5604 thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   func_021C07AC 0x021C07AC thumb ov093
 *   func_021C0450 0x021C0450 thumb ov093
 *   func_021BEBD8 0x021BEBD8 thumb ov093
 *   func_021BE3A8 0x021BE3A8 thumb ov093
 *   func_021BE338 0x021BE338 thumb ov093
 *   func_021BE348 0x021BE348 thumb ov093
 *   func_021BE358 0x021BE358 thumb ov093
 *   func_021BE368 0x021BE368 thumb ov093
 *   func_021BE378 0x021BE378 thumb ov093
 *   func_021BE388 0x021BE388 thumb ov093
 *   func_021BE398 0x021BE398 thumb ov093
 *   func_021BE66C 0x021BE66C thumb ov093
 *   func_021BE620 0x021BE620 thumb ov093
 *   func_021C6458 0x021C6458 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021C024C 0x021C024C thumb ov093
 *   func_021BE7E4 0x021BE7E4 thumb ov093
 *   func_021BE6EC 0x021BE6EC thumb ov093
 *   func_021BEAB4 0x021BEAB4 thumb ov093
 *   func_021BE550 0x021BE550 thumb ov093
 *   func_021BEC58 0x021BEC58 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021BFE60 0x021BFE60 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021BFF60 0x021BFF60 thumb ov093
 *   func_021BE994 0x021BE994 thumb ov093
 *   func_021E0394 0x021E0394 thumb ov093
 *   func_021BE400 0x021BE400 thumb ov093
 */
#define F(o) (*(u8 **)(p + (o)))
struct Unk021D62A8;
struct UtilWork;
struct Msg;
struct O;
struct Out64B4;
struct Slot;
struct Unk021BD1E0;
struct Unk021BDE48;
struct Unk021BE518;
struct Unk021D82D0;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Unk021BDE48 { u32 lo : 7; u32 species : 16; u32 hi : 9; };

union Unk021E8B80 {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    u32 w;
} Action;

struct Out { u8 c0; u8 pad; u16 c2; u8 c4; };

struct Cell { u32 w[5]; };

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Unk021E8B80 func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Unk021E8B80 v);
extern int func_021D55A0(struct UtilWork *p, int id);
extern u32 func_021D5C08(struct UtilWork *p);
extern void func_021BD1E0(struct Unk021BD1E0 *p);
extern void func_021BE518(struct Unk021BE518 *p);
extern int func_021D80BC(void *p, int a, int m, u16 move);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int func_021E02DC(u8 *, u16, u32);
extern void func_021BE924(u8 *, u8 *, u32);
extern int func_021C001C(u8 *, u8 *, u16, u16);
extern int func_021C62D8(u8 *p, u8 *a, u32 unused, u32 c, struct O *out);
extern void func_021C5604(u8 *, u8 *, int);
extern void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern int func_021CA7F4(u8 *, u8 *, u16, const u8 *, void *);
extern int func_021C07AC(u8 *, u8 *, u16, u16, int);
extern void func_021C0450(u8 *, u8 *, u16, int);
extern void func_021BEBD8(u8 *, u8 *, int, int);
extern int func_021BE3A8(u8 *, u8 *, u16 *);
extern void func_021BE338(void *);
extern void func_021BE348(void *);
extern u32 func_021BE358(void *);
extern void func_021BE368(void *);
extern void func_021BE378(void *, void *);
extern void func_021BE388(void *, u32);
extern void func_021BE398(void *, u16, u32, u32);
extern void func_021BE66C(u8 *p, u8 *a, u8 *c, int k);
extern void func_021BE620(u8 *p, u8 *a, u8 *c);
extern int func_021C6458(u8 *, u8 *, u32, u32, u8 *);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C8810(u8 *);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern int func_021C024C(u8 *, u8 *, u32);
extern int func_021BE7E4(u8 *, u8 *, u32, u32, u8 *);
extern int func_021BE6EC(u8 *, u8 *, u16, u32);
extern int func_021BEAB4(u8 *, u8 *, int, int, u8 *);
extern void func_021BE550(u8 *, u8 *, u16, void *);
extern int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d);
extern void func_021D6744(u8 *, u8, int, u8, u16, u16);
extern void func_021CD4B0(void *, volatile u32, ...);
extern u8 func_021D69AC(u8 *, int);
extern void func_021C0780(u8 *, u8 *, int, u8);
extern void func_021BFE60(u8 *, u8 *);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void func_021BFF60(u8 *, u8 *, int);
extern void func_021BE994(u8 *, u8 *, u32, u32);
extern void func_021E0394(u8 *, int);
extern void func_021BE400(u8 *, u16);
void func_021BDE18(u8 *p, u8 *a);
u16 func_021BDE48(void *p, struct Unk021BDE48 *m);
void func_021BDE98(u8 *p, u8 *a, Action *act, u32 key);


void func_021BDE18(u8 *p, u8 *a)
{
    func_021D74F8(3348);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 0x54);
    func_021D7540(3351);
}



u16 func_021BDE48(void *p, struct Unk021BDE48 *m)
{
    u16 r = 0x17;
    if (func_021D62C4(p, 0x17) && m->species != 0xA5) {
        r = func_021E8B80(func_021D6314(p, r));
        if (r != m->species && func_021D55A0(p, r)) return r;
    }
    return 0;
}


static inline void ev18(void *w, u32 x, u32 s, u32 c, u32 b, u32 i2, u32 i1)
{
    func_021CD4B0(w, 0x18, x, s, c, b, i2, i1);
}


void func_021BDE98(u8 *p, u8 *a, Action *act, u32 key)
{
    int k;
    u8 sel;
    u32 prev;
    int chk1, chk2;
    int found;
    u8 flag;
    u8 pr;
    u16 m;
    u16 id;
    u16 id2;
    struct Out o;

    prev = func_021D5C08((struct UtilWork *)a);
    func_021BD1E0((struct Unk021BD1E0 *)F(0x4a8));
    func_021BE518((struct Unk021BE518 *)F(0x4b0));
    o.c2 = 0;
    o.c4 = 6;
    m = func_021BDE48(a, (struct Unk021BDE48 *)act);
    if (m != 0) {
        func_021D82D0((struct Unk021D82D0 *)act, m, func_021D80BC(*(void **)(p + 4), *(int *)(p + 8), (int)a, m));
    }
    id = act->full.move;
    pr = func_021D5778((struct UtilWork *)a, id);
    id2 = id;
    sel = (u8)act->full.select;
    flag = 0;
    o.c0 = 0;
    chk1 = (u8)func_021D62C4((struct Unk021D62A8 *)a, 0x19);
    chk2 = (u8)func_021D62C4((struct Unk021D62A8 *)a, 0x1a);
    func_021E02DC(a, id, key);
    func_021BE924(p, a, id);
    if (func_021C001C(p, a, id, (u8)((chk1 != 0 || chk2 != 0) ? 1 : flag)) != 0) goto end;
    if (func_021C62D8(p, a, id, sel, (struct O *)(&o.c2)) == 0) {
        func_021C5604(p, a, id);
        func_021C64B4(p, id, a, (struct Out64B4 *)F(0x1ab4));
        func_021CA7F4(p, a, sel, F(0x1ab4), F(0x850));
        func_021C07AC(p, a, id, pr, (int)F(0x850));
        flag = 1;
        func_021C0450(p, a, id, 0x1a);
        goto end;
    }
    found = (u8)((o.c2 != 0) ? 1 : 0);
    if (found) {
        func_021C5604(p, a, id);
        func_021BEBD8(p, a, id, sel);
        func_021E02DC(a, o.c2, key);
        id2 = o.c2;
        sel = o.c4;
    } else {
        id2 = id;
    }
    func_021C64B4(p, id, a, (struct Out64B4 *)F(0x1ab4));
    if (found) {
        func_021C64B4(p, id2, a, (struct Out64B4 *)F(0x1ab0));
        ((u32 *)F(0x1ab0))[4] |= 4;
        ((u16 *)F(0x1ab0))[1] = id;
        if (func_021BE3A8(p, a, (u16 *)F(0x1ab0)) != 0) {
            func_021C07AC(p, a, id, pr, (int)F(0x850));
            flag = 1;
            goto end;
        }
    } else {
        *(struct Cell *)F(0x1ab0) = *(struct Cell *)F(0x1ab4);
    }
    func_021BE338(F(0x850));
    func_021BE348(F(0x854));
    func_021CA7F4(p, a, sel, F(0x1ab0), F(0x850));
    {
        u32 v = (u8)func_021BE358(F(0x850));
        func_021BE368(F(0x850));
        func_021BE378(F(0x850), F(0x854));
        func_021BE388(F(0x854), v);
    }
    if (chk1 == 0 && chk2 == 0 && pr != 4) {
        func_021C07AC(p, a, id, pr, (int)F(0x850));
        flag = 1;
    }
    {
        k = 0x1ab4;
        func_021BE66C(p, a, *(void **)(p + k), 0x22);
        func_021BE620(p, a, *(void **)(p + k - 4));
        if (func_021C6458(p, a, id, id2, p + k + 0x30) != 0) {
            func_021C99A0(p, (const struct Msg *)(p + k + 0x30));
            k += 0x30;
            func_021C8810(p + k);
        } else {
            func_021C5604(p, a, id2);
        }
    }
    *(u16 *)(p + 0x1f74) = id2;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x22) != 0) {
        func_021C5620(p, a, 0x22, 0);
        func_021D5FC0((struct UtilWork *)a, 0xe);
    }
    if (func_021C024C(p, a, id2) == 0
        && func_021BE7E4(p, a, id2, sel, (u8 *)&o) == 0
        && func_021BE6EC(p, a, id2, sel) == 0) {
        func_021BE398(p + 0x1c, id2, *(u32 *)(p + 0x10), func_021D5440(a));
        func_021BE66C(p, a, F(0x1ab0), 0x23);
        if (func_021BEAB4(p, a, id2, *(int *)(p + 0x854), F(0x4ac)) != 0) {
            func_021BE550(p, a, id2, F(0x854));
        } else {
            o.c0 = func_021BEC58(p, a, id2, F(0x854));
        }
    }
end:
    func_021D5FC0((struct UtilWork *)a, 3);
    if (flag != 0 || chk1 != 0 || id2 == 0xa5) {
        func_021D6744(a, sel, o.c0, F(0x1ab0)[6], id2, id);
        ev18(*(void **)(p + 0xc), func_021D5440(a), sel, o.c0, F(0x1ab0)[6], id2, id);
    } else if (func_021D69AC(a, 3) != 0) {
        func_021C0780(p, a, 3, 0);
    }
    if (prev != 0x10 && func_021D5C08((struct UtilWork *)a) != 0x10) func_021BFE60(p, a);
    if (func_021D5BB0((struct UtilWork *)a, 0xb) != 0) {
        func_021CD4B0(*(void **)(p + 0xc), 0x31, func_021D5440(a), 0);
        func_021BFF60(p, a, 0);
    }
    func_021BE994(p, a, id2, o.c0);
    if (o.c2 != 0) func_021E0394(a, o.c2);
    func_021E0394(a, id);
    func_021BE400(p, id2);
}
