/*
 * function: func_0215D504
 * address:  0x0215D504
 * packet:   pkt_ov010_0215D504
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: read a one-byte query id from the script cursor, one
 * argument word and a result slot, and store the answer of the query
 * (save-data counters 0..15, link-result queries 30..39) into the slot.
 *
 * Closed once the tool accepted the sole-ref witnesses of func_021569A4
 * and func_021569EC. Levers: the per-case
 * best/second locals at function scope in declaration order with op
 * declared last (sets the stack slots), max initialised before best,
 * case 10 loops over its own block-local j, case 7 tests == 0 first.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_021568E0  0x021568E0  thumb  ov010
 *   func_02156954  0x02156954  thumb  ov010
 *   func_02156978  0x02156978  thumb  ov010
 *   func_02156934  0x02156934  thumb  ov010
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_02156908  0x02156908  thumb  ov010
 *   func_0215699C  0x0215699C  thumb  ov010
 *   func_021569A4  0x021569A4  thumb  ov010
 *   func_021569EC  0x021569EC  thumb  ov010
 *   func_02012F44  0x02012F44  thumb
 *   func_02012F80  0x02012F80  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0200A628  0x0200A628  thumb
 *   func_0200A640  0x0200A640  thumb
 *   func_0200A644  0x0200A644  thumb
 *   func_0200A75C  0x0200A75C  thumb
 *   func_0200A780  0x0200A780  thumb
 *   func_0200A7A0  0x0200A7A0  thumb
 *   func_0200A7B8  0x0200A7B8  thumb
 *   func_0200A7C8  0x0200A7C8  thumb
 *   func_0200A7D4  0x0200A7D4  thumb
 *   func_0200A7E0  0x0200A7E0  thumb
 *   func_021F6744  0x021F6744  thumb  ov112
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx;

typedef struct Rec {
    u8 kind;
    u8 pad01[5];
} Rec;

typedef struct Flags {
    u32 pad0 : 16;
    u32 n : 5;
    u32 pad1 : 11;
} Flags;

extern void *func_0215A5F4(void *vm);
extern unsigned int func_02159B10(void *a0, void *a1);
struct Big;
struct BigObj;
struct Work;
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *vm);
extern u8 func_021568E0(struct Work *w);
extern u16 func_02156954(struct Work *w);
extern u16 func_02156978(struct Work *w);
extern u8 func_02156934(struct Work *w, u8 idx);
extern u8 func_021568E8(void *w, u8 idx);
extern u8 func_02156908(struct Work *w);
extern u8 func_0215699C(struct Work *w, u8 i);
extern u8 func_021569A4(struct Work *w, u8 idx);
extern u8 func_021569EC(struct Work *w, u8 j);
extern void *func_02012F44(void *h);
struct Big;
extern int func_02012F80(char *base);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *list);
extern void *func_0201AB28(void *p, u32 idx);
extern u8 *func_0200A628(struct Big *p);
extern Flags *func_0200A640(void *sv);
extern u32 func_0200A644(struct Big *p, u8 index);
extern u16 func_0200A75C(struct Big *p);
extern u16 func_0200A780(struct Big *p);
extern u8 func_0200A7A0(struct Big *p, u32 index);
extern u8 func_0200A7B8(struct Big *p);
extern u8 func_0200A7C8(struct Big *p);
extern void func_0200A7D4(struct Big *p, u8 value);
extern u8 func_0200A7E0(struct Big *p);
extern int func_021F6744(void *p);

int func_0215D504(Ctx *c, void *vm)
{
    u32 arg;
    u16 *dst;
    void *h;
    void *sv;
    void *w;
    u8 i;
    u8 max;
    u8 best3;
    u8 best8;
    u8 best9;
    u8 best10;
    u8 second;
    u8 next;
    void *list;
    u8 op;

    func_0215A5F4(vm);
    op = *c->pc;
    c->pc++;
    arg = func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    h = func_0215A5E4(vm);
    sv = func_02012F44(h);
    w = 0;
    if (op >= 30) {
        void **pw = (void **)func_02012F80(h);

        if (pw == 0) {
            *dst = 0;
            return 0;
        }
        w = *pw;
    }
    switch (op) {
    case 0:
        *dst = func_0200A75C(sv);
        break;
    case 1:
        *dst = func_0200A780(sv);
        break;
    case 2:
        *dst = func_0200A7B8(sv);
        break;
    case 3: {
        max = 0;
        best3 = 4;

        for (i = 0; i < 4; i++) {
            u8 v = func_0200A7A0(sv, i);

            if (v > max) {
                max = v;
                best3 = i;
            } else if (v == max) {
                best3 = 4;
            }
        }
        *dst = best3;
        break;
    }
    case 4:
        *dst = func_0200A7C8(sv);
        break;
    case 5:
        func_0200A7D4(sv, arg);
        break;
    case 6:
        *dst = 0;
        for (i = 0; i < 4; i++) {
            if (func_0200A7A0(sv, i) != 0)
                *dst = 1;
        }
        break;
    case 7:
        if (func_0200A640(sv)->n == 0)
            *dst = 0;
        else
            *dst = 1;
        break;
    case 8: {
        max = 0xFF;
        best8 = 4;

        for (i = 0; i < 4; i++) {
            u8 v = func_0200A7A0(sv, i);

            if (v <= max) {
                max = v;
                best8 = i;
            }
        }
        *dst = best8;
        break;
    }
    case 9: {
        max = 0;
        best9 = 4;

        for (i = 0; i < 4; i++) {
            u8 v = func_0200A7A0(sv, i);

            if (v > max) {
                max = v;
                best9 = i;
            }
        }
        *dst = best9;
        break;
    }
    case 10: {
        u8 j;

        best10 = 4;
        second = 0;
        max = 0;
        next = 4;

        for (j = 0; j < 4; j++) {
            u8 v = func_0200A7A0(sv, j);

            if (v > max) {
                if (second == max) {
                    next = 4;
                } else {
                    second = max;
                    next = best10;
                }
                max = v;
                best10 = j;
            }
        }
        *dst = next;
        break;
    }
    case 11: {
        u8 count = 0;
        u8 n;

        list = func_02012934(h);
        n = func_0201AA18(list);

        for (i = 0; i < n; i++) {
            if ((u32)func_021F6744(func_0201AB28(list, (int)i)) == 1)
                count++;
        }
        *dst = count;
        break;
    }
    case 12:
        if ((u32)func_021F6744(func_0201AB28(func_02012934(h), (int)arg)) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 13: {
        Rec *r = (Rec *)func_0200A628(sv);

        *dst = 0;
        for (i = 0; i < 8; i++) {
            if (r[i].kind != 10)
                *dst = 1;
        }
        break;
    }
    case 14:
        if (func_0200A7E0(sv) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 15:
        if (func_0200A644(sv, (u8)arg) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 30:
        *dst = func_021568E0(w);
        break;
    case 31:
        *dst = func_02156954(w);
        break;
    case 32:
        *dst = func_02156978(w);
        break;
    case 33:
        *dst = func_02156934(w, arg);
        break;
    case 35:
        *dst = func_021568E8(w, arg);
        break;
    case 36:
        *dst = func_02156908(w);
        break;
    case 37:
        *dst = func_0215699C(w, arg);
        break;
    case 38:
        *dst = func_021569A4(w, arg);
        break;
    case 39:
        *dst = func_021569EC(w, arg);
        break;
    }
    return 0;
}
