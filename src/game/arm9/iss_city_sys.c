/*
 * file:     iss_city_sys.c
 * unit:     yes
 * function: func_0202A994, func_0202A9F4, func_0202AAF4, func_0202AB28, func_0202AB38, func_0202AB4C, func_0202AB54, func_0202AB5C, func_0202AB64, func_0202AB7C, func_0202AB84, func_0202AB8C, func_0202ABD0, func_0202ABF8, func_0202ABFC, func_0202AC00, func_0202AC4C, func_0202AC60, func_0202ACBC, func_0202ACC8, func_0202ACCC, func_0202ACFC, func_0202AD10, func_0202AD44, func_0202AD78, func_0202AD88, func_0202AD8C, func_0202ADA0, func_0202ADB4, func_0202ADD8, func_0202AE04, func_0202AE08, func_0202AE34, func_0202AE60, func_0202AE64, func_0202AE68, func_0202AE9C, func_0202AEB8, func_0202AEBC, func_0202AED0, func_0202AEEC, func_0202AF28, func_0202AF30, func_0202AF34, func_0202AF3C, func_0202AF74, func_0202AFAC, func_0202AFFC, func_0202B04C, func_0202B0A4, func_0202B0D4, func_0202B104, func_0202B134, func_0202B154, func_0202B174, func_0202B194
 * address:  0x0202A994
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185B0  0x020185B0  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02019C90  0x02019C90  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   sub_020307B0   0x020307B0  arm
 *   func_02049030  0x02049030  arm
 *   func_02030734  0x02030734  arm
 *   g_020A76E8     0x020A76E8  data
 *   g_020A76F8     0x020A76F8  data
 *   func_020307B0  0x020307B0  arm
 *   func_02012AC8  0x02012AC8  thumb
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AC04   0x0209AC04  arm
 *   _d2s            0x0209C508  arm
 */
struct Personal;
struct Node;
struct Rec44;
struct Vec12;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

/* One 0x28-byte record, filled from archive 0x84. */
struct CityBand {
    u16 id;
    u16 pad02;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u8 a[6];
    u8 b[6];
    u8 c[6];
    u8 d[6];
};

struct CitySys {
    struct Rec44 *owner;
    u32 enabled;
    u32 mode;
    u32 vol;
    u32 level;
    struct CityBand **bands;
    u8 count;
    u8 cur;
};

extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32  func_02017E1C(void *rec, u32 id, u32 slot);
extern void func_02017E40(void *rec, u32 id, u32 val);
extern void func_020185B0(void *rec, u32 val);
extern void func_02018A00(void *rec, u32 species, u32 arg);
extern u32  func_02019C90(u32 species, u16 arg, u32 sel);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 sub_020307B0(void *p);
extern void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode, u32 size);
extern u32 func_02049030(u32 a);
extern u32 func_020307B0(void *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void func_02005F24(u32 a0, u32 a1);
extern double _s32_to_double(s32 v);
extern double func_0209AC04(double a, double b);
extern s32 _d2s(double d);
void func_0202A994(u32 a, u32 b, int c, u32 *out, u16 d);
void func_0202A9F4(u32 a0, void *rec, u32 a2, u32 a3);
struct Node *func_0202AAF4(u32 a, void *heapId);
void func_0202AB28(void *p);
void func_0202AB38(u8 *p);
void func_0202AB4C(u8 *p);
void func_0202AB54(u8 *p);
void func_0202AB5C(struct CitySys *s, u32 a1);
void func_0202AB64(struct CitySys *s, u32 unused, struct Rec44 *owner);
void func_0202AB7C(struct CitySys *s, u32 heapId);
void func_0202AB84(struct CitySys *s);
void func_0202AB8C(struct CitySys *s, u32 heapId);
void func_0202ABD0(struct CitySys *s);
u32 func_0202ABF8(struct CitySys *s);
void func_0202ABFC(struct CitySys *s, u32 mode);
void func_0202AC00(struct CitySys *s);
int func_0202AC4C(struct CitySys *s);
void func_0202AC60(struct CitySys *s, u32 key);
u32 func_0202ACBC(struct CitySys *s);
u32 func_0202ACC8(struct CitySys *s);
void func_0202ACCC(struct CitySys *s);
void func_0202ACFC(struct CitySys *s);
void func_0202AD10(struct CitySys *s);
void func_0202AD44(struct CitySys *s);
struct CityBand *func_0202AD78(struct CitySys *s);
u32 func_0202AD88(struct CitySys *s);
int func_0202AD8C(struct CitySys *s);
int func_0202ADA0(struct CitySys *s, u32 key);
int func_0202ADB4(struct CitySys *s, u32 key);
u8 func_0202ADD8(struct CitySys *s, u32 key);
u32 func_0202AE04(struct CitySys *s);
int func_0202AE08(struct CitySys *s);
int func_0202AE34(struct CitySys *s);
void func_0202AE60(struct CitySys *s, u32 level);
u32 func_0202AE64(struct CitySys *s);
int func_0202AE68(struct CitySys *s);
int func_0202AE9C(struct CitySys *s);
void func_0202AEB8(struct CitySys *s, u32 vol);
void func_0202AEBC(struct CitySys *s);
int func_0202AED0(struct CitySys *s);
struct CityBand *func_0202AEEC(u32 heapId, u32 member);
void func_0202AF28(struct CityBand *band);
u32 func_0202AF30(struct CityBand *band);
u8 func_0202AF34(const struct CityBand *band, const s32 *pos);
void func_0202AF3C(const struct CityBand *src, struct CityBand *dst);
u8 func_0202AF74(const struct CityBand *band, const s32 *pos);
u8 func_0202AFAC(const struct CityBand *band, const s32 *pos);
u8 func_0202AFFC(const struct CityBand *band, const s32 *pos);
u8 func_0202B04C(const struct CityBand *band, const s32 *pos);
u32 func_0202B0A4(const struct CityBand *band, const s32 *pos);
u32 func_0202B0D4(const struct CityBand *band, const s32 *pos);
u32 func_0202B104(const struct CityBand *band, const s32 *pos);
s32 func_0202B134(const struct CityBand *band);
s32 func_0202B154(const struct CityBand *band);
s32 func_0202B174(const struct CityBand *band);
s32 func_0202B194(s32 a, s32 b, s32 c, s32 d, s32 e);
extern const char g_020A76E8[];
extern const char g_020A76F8[];





void func_0202A994(u32 a, u32 b, int c, u32 *out, u16 d)
{
    u32 t = c & 0xf;
    u32 u = (c & 0xf0) >> 4;
    u32 v;

    if (c == 0)
        return;

    v = (u32)func_0201ADE4((u16)a, (u16)b, d);

    if (t != 0) {
        *out = func_0201AE1C((const struct Personal *)v, 0x14);
        if (t == 1)
            *out = *out + 2;
        else
            *out = *out - 2;
    }

    if (u == 1)
        *out &= ~(u32)1;
    else if (u == 2)
        *out |= (u32)1;

    func_0201AE14((void *)v);
}





/*
 * tr_tool.c: finish one trainer party member.  Field 9 (friendship) is
 * 0xFF unless one of the four moves (fields 0x36..0x39) is 0xDA, then 0;
 * field 0x6F takes a2; the 0xF0 nibble of a3 selects a form path
 * (0x30: func_02018A00, otherwise func_02019C90 with selector 0x1A or
 * 0x1B); two trainer/species pairs force a fixed nature, the rest take
 * (personality >> 8) % 25.
 *
 * What closed the old 248-byte near miss (docs/notes/func_0202A9F4.c.txt):
 * the register the note read as a copy of the loop counter (`adds r6, r4,
 * #0` before the loop) is the constant 0, kept in r6 for the call's third
 * argument and for `found = 0`.  That zero occupies the fourth callee-saved
 * register across the loop, which is what spills species to sp+0xC.  The
 * tail is the remainder of _s32_div_f (r1), so `% 25`, not `/ 25`.
 */
void func_0202A9F4(u32 a0, void *rec, u32 a2, u32 a3)
{
    s32 slot;
    u32 found = 0xff;
    u32 species;
    u32 sel;
    u32 alt;
    u32 masked;
    u32 base;

    species = (u16)func_02017E1C(rec, 5, 0);
    for (slot = 0; slot < 4; slot++) {
        if (func_02017E1C(rec, 0x36 + slot, 0) == 0xda) {
            found = 0;
        }
    }
    func_02017E40(rec, 9, found);
    func_02017E40(rec, 0x6f, a2);

    masked = a3 & 0xf0;
    if (masked == 0x30) {
        func_02018A00(rec, species, a2);
    } else if (masked != 0) {
        sel = 0x1a;
        alt = 0x1b;
        if (func_02019C90(species, (u16)a2, 0x1b) != 0 && masked == 0x20) {
            sel = alt;
        }
        func_02017E40(rec, 0xa, func_02019C90(species, (u16)a2, sel));
    }

    base = 0x24a;
    if (a0 == base && species == base + 0x39) {
        func_020185B0(rec, 0xd);
        return;
    }
    base = 0x24b;
    if (a0 == base && species == base + 0x39) {
        func_020185B0(rec, 0xa);
        return;
    }
    func_020185B0(rec, (u8)(((s32)func_02017E1C(rec, 0, 0) >> 8) % 0x19));
}





/*
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * Allocates a 0x1c-byte node with the allocator entry point and runs the
 * two initialisers func_0202AB64 and func_0202AB7C over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AAF4.c \
 *       --func func_0202AAF4 --addr 0x0202AAF4 --thumb --cc 1.1p1
 */
struct Node *func_0202AAF4(u32 a, void *heapId)
{
    struct Node *p = (struct Node *)func_02030734((u32)heapId, 0x1c, 0,
                                                  (const void *)0x020A76E8, 0x92);

    func_0202AB64((struct CitySys *)p, (u32)heapId, (struct Rec44 *)a);
    func_0202AB7C((struct CitySys *)p, (u32)heapId);
    return p;
}




void func_0202AB28(void *p)
{
    func_0202AB84((struct CitySys *)p);
    sub_020307B0(p);
}



/*
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * When func_0202ACC8 reports non-zero, runs func_0202ACCC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AB38.c \
 *       --func func_0202AB38 --addr 0x0202AB38 --thumb --cc 1.1p1
 */
void func_0202AB38(u8 *p)
{
    if (func_0202ACC8((struct CitySys *)p) != 0) {
        func_0202ACCC((struct CitySys *)p);
    }
}



void func_0202AB4C(u8 *p)
{
    func_0202AC00((struct CitySys *)p);
}



void func_0202AB54(u8 *p)
{
    func_0202AC4C((struct CitySys *)p);
}


/*
 * iss_city_sys.c: an unlabelled forwarding leaf, a pool-word tail call to
 * func_0202AC60 with the caller's arguments passed through untouched.
 */
void func_0202AB5C(struct CitySys *s, u32 a1)
{
    func_0202AC60(s, a1);
}


/* The second argument is never read; the compiler reuses its register as the zero source. */
void func_0202AB64(struct CitySys *s, u32 unused, struct Rec44 *owner)
{
    s->enabled = 0;
    s->mode = 0;
    s->vol = 0;
    s->level = 0;
    s->bands = 0;
    s->count = 0;
    s->owner = owner;
    s->cur = 0xff;
}


/*
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * A bare tail-call thunk to func_0202AB8C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AB7C.c \
 *       --func func_0202AB7C --addr 0x0202AB7C --thumb --cc 1.1p1
 */
void func_0202AB7C(struct CitySys *s, u32 heapId)
{
    func_0202AB8C(s, heapId);
}


void func_0202AB84(struct CitySys *s)
{
    func_0202ABD0(s);
}


/*
 * Graduated from src/pending/; promoted once its blocker became a manifest entry.
 *
 * Previously blocked at MATCH on `label`: func_0202AEEC has exactly one branch reference
 * image-wide, this function's own call, so no witness exists outside the
 * compared range and no cut helps.  It closes when func_0202AEEC (pkt_0202AEEC)
 * acquires a manifest entry or a second caller appears.
 *
 * closed:   blocker 0202AEEC is now a manifest entry (matched class)
 */
void func_0202AB8C(struct CitySys *s, u32 heapId)
{
    s32 n = func_02049030(0x84);
    s32 i;
    s->count = n;
    s->bands = func_02030734(heapId, n << 2, 0, g_020A76E8, 0x14d);
    for (i = 0; i < n; i++) {
        s->bands[i] = func_0202AEEC(heapId, i);
    }
}


void func_0202ABD0(struct CitySys *s)
{
    int i;
    int count = s->count;
    for (i = 0; i < count; i++) {
        func_0202AF28(s->bands[i]);
    }
    func_020307B0(s->bands);
    s->bands = 0;
}


u32 func_0202ABF8(struct CitySys *s)
{
    return s->mode;
}


void func_0202ABFC(struct CitySys *s, u32 mode)
{
    s->mode = mode;
}


void func_0202AC00(struct CitySys *s)
{
    if (func_0202ACC8(s) != 0)
        return;
    s->enabled = 1;
    func_0202AEB8(s, 0);
    func_0202AEBC(s);
    func_0202ADB4(s, func_0202ACBC(s));
    if (func_0202AD8C(s) == 1)
        func_0202ABFC(s, 1);
    else
        func_0202ABFC(s, 0);
}


int func_0202AC4C(struct CitySys *s)
{
    int r = func_0202ACC8(s);
    if (r != 0) {
        s->enabled = 0;
        return 0;
    }
    return r;
}


void func_0202AC60(struct CitySys *s, u32 key)
{
    if (func_0202ACC8(s) == 0) {
        return;
    }
    if (func_0202AD8C(s) == 1) {
        if (func_0202ADA0(s, key) == 1) {
            func_0202AC4C(s);
            return;
        }
    }
    func_0202ADB4(s, key);
    if (func_0202AD8C(s) == 1) {
        func_0202AE60(s, 0);
        func_0202ABFC(s, 1);
        return;
    }
    func_0202ABFC(s, 2);
}


u32 func_0202ACBC(struct CitySys *s)
{
    return func_02012AC8(s->owner);
}


u32 func_0202ACC8(struct CitySys *s)
{
    return s->enabled;
}


/* One switch on the call result puts it straight into r0 for all three compares. */
/*
 * Dispatches on the state word returned by func_0202ABF8 over a three-way
 * state machine.  One `switch` on the call result is what puts the result
 * straight into r0 for all three `cmp`s: a named local would have stored it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ACCC.c \
 *       --func func_0202ACCC --addr 0x0202ACCC --thumb --cc 1.1p1
 */
void func_0202ACCC(struct CitySys *s)
{
    switch (func_0202ABF8(s)) {
    case 0:
        func_0202ACFC(s);
        break;
    case 1:
        func_0202AD10(s);
        break;
    case 2:
        func_0202AD44(s);
        break;
    }
}


void func_0202ACFC(struct CitySys *s)
{
    if (func_0202AE68(s) != 0) {
        func_0202AEBC(s);
    }
}


void func_0202AD10(struct CitySys *s)
{
    int a = func_0202AE08(s);
    int b = func_0202AE68(s);
    if (a != 0 || b != 0) {
        func_0202AEBC(s);
    }
    if ((int)func_0202AE04(s) >= 0x7f) {
        func_0202ABFC(s, 0);
    }
}


void func_0202AD44(struct CitySys *s)
{
    int a = func_0202AE34(s);
    int b = func_0202AE68(s);
    if (a != 0 || b != 0) {
        func_0202AEBC(s);
    }
    if ((int)func_0202AE04(s) <= 0) {
        func_0202ABFC(s, 0);
    }
}


struct CityBand *func_0202AD78(struct CitySys *s)
{
    return s->bands[func_0202AD88(s)];
}


u32 func_0202AD88(struct CitySys *s)
{
    return s->cur;
}


int func_0202AD8C(struct CitySys *s)
{
    if (func_0202AD88(s) != 0xff) {
        return 1;
    }
    return 0;
}


int func_0202ADA0(struct CitySys *s, u32 key)
{
    if (func_0202ADD8(s, key) != 0xff) {
        return 1;
    }
    return 0;
}


int func_0202ADB4(struct CitySys *s, u32 key)
{
    u32 cur = func_0202AD88(s);
    u8 idx = func_0202ADD8(s, key);
    if (cur == idx) {
        return 0;
    }
    s->cur = idx;
    return 1;
}


u8 func_0202ADD8(struct CitySys *s, u32 key)
{
    int i;
    u8 count = s->count;
    for (i = 0; i < count; i++) {
        if (key == func_0202AF30(s->bands[i])) {
            return (u8)i;
        }
    }
    return 0xff;
}


u32 func_0202AE04(struct CitySys *s)
{
    return s->level;
}


int func_0202AE08(struct CitySys *s)
{
    s32 val = (s32)func_0202AE04(s) + 2;
    if (val >= 0x7f) {
        val = 0x7f;
    }
    if (val == (s32)func_0202AE04(s)) {
        return 0;
    }
    func_0202AE60(s, val);
    return 1;
}


int func_0202AE34(struct CitySys *s)
{
    s32 val = (s32)func_0202AE04(s) - 2;
    if (val <= 0) {
        val = 0;
    }
    if (val == (s32)func_0202AE04(s)) {
        return 0;
    }
    func_0202AE60(s, val);
    return 1;
}


void func_0202AE60(struct CitySys *s, u32 level)
{
    s->level = level;
}


/*
 * closed:   blocker func_02020F0C.c is now a manifest entry (matched class)
 *
 * Plain field read: the word at 0xc.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202AE64.c \
 *       --func func_0202AE64 --addr 0x0202AE64 --thumb --cc 1.1p1
 */
u32 func_0202AE64(struct CitySys *s)
{
    return s->vol;
}


/*
 * Blocked: 0202AE9C (thumb, from name) has no witness outside 0202AE68..0202AE9A. Every concrete byte reproduces.
 */
int func_0202AE68(struct CitySys *s)
{
    int v;
    if (func_0202AD8C(s) == 0) {
        return 0;
    }
    v = func_0202AE9C(s);
    if (v == func_0202AE64(s)) {
        return 0;
    }
    func_0202AEB8(s, v);
    return 1;
}


/*
 * Blocked: call target func_0202AF34 is unlabelled and unmatched (it lives in
 * another lane's packet, pkt_0202AF34). Every concrete byte reproduces.
 */
int func_0202AE9C(struct CitySys *s)
{
    return func_0202AF34(func_0202AD78(s), (const s32 *)func_02012AA0(s->owner));
}


void func_0202AEB8(struct CitySys *s, u32 vol)
{
    s->vol = vol;
}


void func_0202AEBC(struct CitySys *s)
{
    func_02005F24(3 << 8, func_0202AED0(s));
}


int func_0202AED0(struct CitySys *s)
{
    return (s32)func_0202AE64(s) * (s32)func_0202AE04(s) / 0x7f;
}


/*
 * Allocates a 0x28-byte node with func_02030734, wraps it with func_02048F88,
 * runs func_0202AF3C over the pair and releases the wrapper.  The pair is
 * passed as (wrapper, node): r0 is left holding the wrapper from the second
 * allocation when func_0202AF3C is reached, with the node moved into r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AEEC.c \
 *       --func func_0202AEEC --addr 0x0202AEEC --thumb --cc 1.1p1
 */
struct CityBand *func_0202AEEC(u32 heapId, u32 member)
{
    struct CityBand *node = func_02030734(heapId, 0x28, 0, g_020A76F8, 0x6c);
    struct CityBand *wrap = func_02048F88(0x84, member, heapId, 0, 0x28);
    func_0202AF3C(wrap, node);
    func_020307B0(wrap);
    return node;
}


void func_0202AF28(struct CityBand *band)
{
    func_020307B0(band);
}


u32 func_0202AF30(struct CityBand *band)
{
    return band->id;
}


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * A bare tail-call thunk to func_0202AF74 (ldr r3, pool; bx r3; .word
 * 0x0202AF75).  Blocked at MATCH on `literal`: the pointer word 0x0202AF75
 * appears in exactly one literal pool image-wide, this thunk's own at
 * 0x0202AF38, so the ABS32 site has no outside witness.  There is no branch
 * to 0x0202AF74 anywhere else in the image either, so the `label` class is
 * empty too.  Closes when func_0202AF74 acquires a manifest entry that is
 * not this file's own (a second reader of the thunk, or a matched
 * func_0202AF74 elsewhere).
 *
 * THE BODY BELOW IS NEW (third band pass).  The file carried the note alone
 * because the shape had been reported as a linker veneer with no C spelling:
 * it is not.  A plain tail call reproduces all 8 bytes - 4 of code plus the
 * pool word - byte for byte, and the IRQ-window `ldr r3, [pc, #0]` + `bx r3`
 * is exactly what this front end emits for it.  The one relocation therefore
 * stays a wildcard (its own pool word is inside the compared range), which is
 * the MATCH cap and the only thing that keeps this entry out of the manifest.
 *
 * It is the last link of this lane's 0x0202AE68 chain: src/pending/
 * func_0202AE9C.c is capped on this address's `label`, which is empty while
 * this file cannot be an EXACT entry.  The whole chain needs func_0202AF74
 * (50 bytes, in another packet) filed.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202AF34.c \
 *       --func func_0202AF34 --addr 0x0202AF34 --cc 1.1p1 --thumb
 */
u8 func_0202AF34(const struct CityBand *band, const s32 *pos)
{
    return func_0202AF74(band, pos);
}


void func_0202AF3C(const struct CityBand *src, struct CityBand *dst)
{
    int i;
    dst->id = src->id;
    dst->unk04 = src->unk04;
    dst->unk08 = src->unk08;
    dst->unk0C = src->unk0C;
    for (i = 0; i < 6; i++) {
        dst->a[i] = src->a[i];
        dst->b[i] = src->b[i];
        dst->c[i] = src->c[i];
        dst->d[i] = src->d[i];
    }
}


/* Product of the three axis levels (0..127 each), renormalised by 127 * 127. */
/*
 * The head of the three-axis attenuation family: multiplies the X, Y and
 * Z band responses (func_0202AFAC / func_0202AFFC / func_0202B04C, each a
 * 0..127 level) and renormalises by 127*127 == 0x3f01, so the product of
 * three 7-bit levels comes back as one 7-bit level.  The result is
 * truncated to u8 by the caller-visible return type.
 *
 * Blocked at MATCH: every concrete byte is right.  The three THM_CALL
 * sites at +0x06, +0x10 and +0x1a have no witness outside
 * 0x0202AF74..0x0202AFAC -- this is the only caller of any of the three
 * axis routines in the whole image, so `label` refuses them and `matched`
 * has nothing to point at while func_0202AFAC / func_0202AFFC /
 * func_0202B04C stay unfiled (each is a 6-to-13 byte scheduling near
 * miss, see docs/notes/func_0202AFAC.c.txt and its two twins).
 * --suggest-split cannot help: the compared range is one function.
 * Blocking evidence class: none available (needs an EXACT manifest entry
 * at 0x0202AFAC / 0x0202AFFC / 0x0202B04C, or a second caller).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AF74.c \
 *       --func func_0202AF74 --addr 0x0202AF74 --cc 1.1p1 --thumb
 */
u8 func_0202AF74(const struct CityBand *band, const s32 *pos)
{
    s32 x;
    s32 y;
    s32 z;
    x = func_0202AFAC(band, pos);
    y = func_0202AFFC(band, pos);
    z = func_0202B04C(band, pos);
    return (u8)(z * (x * y) / 0x3f01);
}


/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the first axis: pos[0], radius table at +0x16.
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/func_0202AFAC.c.txt: the
 * stacked fifth argument stored to [sp] before the pp/pc address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const u8 *obj`, `const s32 *pos`, const-pointee callees and
 * const pp/pc.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AFAC.c  *       --func func_0202AFAC --addr 0x0202AFAC --thumb --cc 1.1p1
 */
u8 func_0202AFAC(const struct CityBand *band, const s32 *pos)
{
    u32 cur;
    u32 prev;
    s32 v;
    s32 d;
    const u8 *obj = (const u8 *)band;
    const u8 *pp;
    const u8 *pc;
    cur = func_0202B0A4(band, pos);
    if (cur == 0)
        prev = 0;
    else
        prev = (u8)(cur - 1);
    if (cur == prev)
        return (obj + cur)[0x10];
    v = pos[0] >> 12;
    d = v - func_0202B134(band);
    if (d < 0)
        d = -d;
    pp = obj + prev;
    pc = obj + cur;
    return (u8)func_0202B194(pc[0x16] << 4, pc[0x10],
                             pp[0x16] << 4, pp[0x10], d);
}


/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the second axis: pos[1], radius table at +0x1c.
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/func_0202AFFC.c.txt: the
 * stacked fifth argument stored to [sp] before the pp/pc address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const u8 *obj`, `const s32 *pos`, const-pointee callees and
 * const pp/pc.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AFFC.c  *       --func func_0202AFFC --addr 0x0202AFFC --thumb --cc 1.1p1
 */
u8 func_0202AFFC(const struct CityBand *band, const s32 *pos)
{
    u32 cur;
    u32 prev;
    s32 v;
    s32 d;
    const u8 *obj = (const u8 *)band;
    const u8 *pp;
    const u8 *pc;
    cur = func_0202B0D4(band, pos);
    if (cur == 0)
        prev = 0;
    else
        prev = (u8)(cur - 1);
    if (cur == prev)
        return (obj + cur)[0x10];
    v = pos[1] >> 12;
    d = v - func_0202B154(band);
    if (d < 0)
        d = -d;
    pp = obj + prev;
    pc = obj + cur;
    return (u8)func_0202B194(pc[0x1c] << 4, pc[0x10],
                             pp[0x1c] << 4, pp[0x10], d);
}


/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the third axis: pos[2], radius table at +0x22
 * (past the ldrb reach, hence one `adds` per load).
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/func_0202B04C.c.txt: the
 * stacked fifth argument stored to [sp] before the pp/pc address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const u8 *obj`, `const s32 *pos`, const-pointee callees and
 * const pp/pc.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B04C.c  *       --func func_0202B04C --addr 0x0202B04C --thumb --cc 1.1p1
 */
u8 func_0202B04C(const struct CityBand *band, const s32 *pos)
{
    u32 cur;
    u32 prev;
    s32 v;
    s32 d;
    const u8 *obj = (const u8 *)band;
    const u8 *pp;
    const u8 *pc;
    cur = func_0202B104(band, pos);
    if (cur == 0)
        prev = 0;
    else
        prev = (u8)(cur - 1);
    if (cur == prev)
        return (obj + cur)[0x10];
    v = pos[2] >> 12;
    d = v - func_0202B174(band);
    if (d < 0)
        d = -d;
    pp = obj + prev;
    pc = obj + cur;
    return (u8)func_0202B194(pc[0x22] << 4, pc[0x10],
                             pp[0x22] << 4, pp[0x10], d);
}


u32 func_0202B0A4(const struct CityBand *band, const s32 *pos)
{
    s32 i;
    s32 v = pos[0] >> 12;
    s32 d = v - func_0202B134(band);
    const u8 *a0 = (const u8 *)band;
    if (d < 0) d = -d;
    for (i = 0; i < 6; i++) {
        if ((a0[i + 0x16] << 4) <= d) return (u8)i;
    }
    return 0;
}


u32 func_0202B0D4(const struct CityBand *band, const s32 *pos)
{
    s32 i;
    s32 v = pos[1] >> 12;
    s32 d = v - func_0202B154(band);
    const u8 *a0 = (const u8 *)band;
    if (d < 0) d = -d;
    for (i = 0; i < 6; i++) {
        if ((a0[i + 0x1c] << 4) <= d) return (u8)i;
    }
    return 0;
}


u32 func_0202B104(const struct CityBand *band, const s32 *pos)
{
    s32 i;
    s32 v = pos[2] >> 12;
    s32 d = v - func_0202B174(band);
    const u8 *a0 = (const u8 *)band;
    if (d < 0) d = -d;
    for (i = 0; i < 6; i++) {
        if ((a0[i + 0x22] << 4) <= d) return (u8)i;
    }
    return 0;
}


s32 func_0202B134(const struct CityBand *band)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(band->unk04 << 4))));
}


s32 func_0202B154(const struct CityBand *band)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(band->unk08 << 4))));
}


s32 func_0202B174(const struct CityBand *band)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(band->unk0C << 4))));
}


s32 func_0202B194(s32 a, s32 b, s32 c, s32 d, s32 e)
{
    return b + (d - b) * (e - a) / (c - a);
}
