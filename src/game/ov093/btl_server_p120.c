/*
 * file:     btl_server_p120.c
 * unit:     yes
 * function: func_021CE7D4, func_021CE8F0, func_021CEA94, func_021CECB4, func_021CED4C, func_021CEDC0
 * address:  0x021CE7D4
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
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021BA004 0x021BA004 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021EA6B0 0x021EA6B0 thumb ov093
 *   func_021D7F38 0x021D7F38 thumb ov093
 *   func_021F87EC 0x021F87EC thumb ov094
 *   func_021F8774 0x021F8774 thumb ov094
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_0202A298 0x0202A298 thumb
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D7B60 0x021D7B60 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   d_021EFF78 0x021EFF78 data ov093 a2
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021CF524 0x021CF524 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 *   func_021E97BC 0x021E97BC thumb ov093
 *   func_021E9808 0x021E9808 thumb ov093
 *   func_021CE0BC 0x021CE0BC thumb ov093
 *   func_021E98AC 0x021E98AC thumb ov093
 *   func_021E98B4 0x021E98B4 thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021B9AB0 0x021B9AB0 thumb ov093
 *   func_021D832C 0x021D832C thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021CF5B0 0x021CF5B0 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   func_021CE3B4 0x021CE3B4 thumb ov093
 *   func_021D8340 0x021D8340 thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D7EF0 0x021D7EF0 thumb ov093
 *   func_021E98BC 0x021E98BC thumb ov093
 *   func_021E9920 0x021E9920 thumb ov093
 *   func_021E98E8 0x021E98E8 thumb ov093
 *   func_021E9858 0x021E9858 thumb ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021E9CE0  0x021E9CE0  thumb  ov093
 *   func_021E9B14  0x021E9B14  thumb  ov093
 *   func_021E9B20  0x021E9B20  thumb  ov093
 *   func_021CF8D4 0x021CF8D4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CEE98 0x021CEE98 thumb ov093
 *   func_021CEEA8 0x021CEEA8 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 */
#include "../../matched/include/Obj02785.h"
#include "../../matched/include/Obj03689.h"
#include "../../matched/include/Obj00434.h"
#include "../../matched/include/Obj21136.h"
#include "../../matched/include/Obj05199.h"
#include "../../matched/include/Obj03194.h"

struct Q1;
struct Unk021D82D0;
struct UtilWork;
struct Unk021D82FC;
struct S2;
struct QG;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 flag : 1; u8 rest : 7; } Flags;

typedef enum { OFFSET = 0x19a } Off;

struct Offsets { Off skip,ok0,ok1,ok2,ok3,invalid; };

typedef struct { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; } Record;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 *q; u8 f[4]; } Ent;

extern u8 func_021B904C(u8 *p, int k);
extern u16 func_021BA004(char *p, int i);
extern unsigned short func_021BA020(char *p, int i);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern int func_021EA6B0(char *, u16, u16);
extern int func_021D7F38(u32 n);
extern void func_021F87EC(u32);
extern int func_021F8774(void);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D90(u16, u16);
extern int func_021F7EB4(void);
extern int func_021EA710(u32 *p);
extern void func_021CE150(u8 *p, void *q);
extern int func_021CE4D0(u8 *p, u32 *st);
extern void *func_021B86B8(void ***);
extern char *func_021B9AEC(char *,int);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern int func_021D5B68(void *);
extern int func_021B99B8(void *pp, unsigned int b);
extern u32 func_0202A298(u32,u32,u32);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);
extern int func_021D5B48(u8 *p);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021B9B98(u8 *p);
extern u32 func_021B8588(void **p);
extern u32 func_021CF524(u32, void *, u32);
extern u32 func_021CF220(u8 *, int *);
extern int func_021CE3C8(u8 *, int *);
extern void func_021E97BC(char *p, u8 *a, int b);
extern void func_021E9808(char *p, u32 *q, int c);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E98AC(void *);
extern u32 func_021E98B4(void *);
extern u32 func_021D8454(u32 *);
extern int func_021B9AB0(int);
extern u32 func_021D832C(struct Unk021D82FC *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
extern void func_021EAF78(u8 *, u8);
extern void func_021CE3B4(u8 *p, void *q);
extern u32 func_021D8340(u32 *);
extern void func_021D83FC(u32 *p, u32 sub);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u32 func_021D7EF0(u32);
extern void func_021E98BC(char *p, u8 *a, int b);
extern void func_021E9920(void *);
extern int func_021E98E8(char *p);
extern void func_021E9858(char *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u16 func_021D54C0(u8 *p, int i);
extern void func_021E9CE0(u8 *p, u8 a, u8 b);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern u32 func_021CF8D4(u8 *, void *, u8 *, u16 *);
extern u8 func_021D5440(u8 *p);
extern void func_021E9A78(char *, const u8 *, int, int, u8 *);
extern u32 func_021CEE98(u8 *);
extern u32 func_021CEEA8(u8 *);
extern void func_021D8394(void *, u8, u32);
u32 func_021CE7D4(u8 *p, int *st);
u32 func_021CE8F0(const u8 *p, u16 *out);
int func_021CEA94(u8 *p, u32 *state);
void func_021CECB4(u8 *p, Ent *out);
u32 func_021CED4C(u8 *p, s32 *st);
u32 func_021CEDC0(u8 *p, int *st);
extern const u16 d_021EFF78[4];





u32 func_021CE7D4(u8 *p, int *st)
{
    u32 i;
    u16 k;
    u32 z;
    switch (*st) {
    case 0:
        z = 0;
        i = func_021B904C(((struct Obj02785 *)p)->f0, 0);
        k = func_021BA004(((struct Obj02785 *)p)->f0, i);
        func_021F7F58(func_021BA020(((struct Obj02785 *)p)->f0, i), 9, 0, 0, z);
        func_021F7998(0x270);
        func_021EA6B0(*(char * *)&((struct Obj02785 *)p)->f54, k, ((struct Obj02785 *)p)->f19E);
        if ((u16)(((struct Obj02785 *)p)->f19E + 0xffed) <= 1 &&
            func_021D7F38(func_021BA020(((struct Obj02785 *)p)->f0, i)) && !((Flags *)(p + 0x1b2))->flag) {
            func_021F87EC(0x47b);
            if (!func_021F8774()) {
                func_02005E30(8);
                *st = 1;
                break;
            }
        }
        *st = 2;
        break;
    case 1:
        if (!func_02005E50()) {
            func_02005D90(0x47b, 0xffff);
            p[0x1b2] = (p[0x1b2] & ~1) | 1;
            ++*st;
        }
        break;
    case 2:
        if (!func_021F7EB4() && func_021EA710(((struct Obj02785 *)p)->f54)) {
            func_021F7998(0x271);
            ++*st;
        }
        break;
    case 3:
        if (!func_021F7EB4()) func_021CE150(p, (void *)((u32)func_021CE4D0));
        break;
    }
    return 0;
}




static inline void init_offset(Off *value)
{
    *value = OFFSET;
    *value -= 0x88;
}




/*
 * lever: Six ordinary int offsets each receive 0x19a then 0x112;
 * a cached row pointer preserves their distinct stack homes and r5 base.
 * Reverse declarations and a full-word k local restore the spill order.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`invalid=0x19a;` before `invalid=0x112;`; `ok3=0x19a;` before
 * `ok3=0x112;` and 4 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
u32 func_021CE8F0(const u8 *p, u16 *out)
{
    u32 entry;
    int result;
    u32 count;
    u32 k;
    u32 key;
    u32 id, i;
    int a, b;
    u8 *mon;
    u8 *row;
    int skip,ok0,ok1,ok2,ok3,invalid;
    if ((u32)func_021B86B8(*(void *** *)&((struct Obj03689 *)p)->f0) != 1) goto fail;
    id = func_021B904C(((struct Obj03689 *)p)->f0,0);
    k = func_021BA004(((struct Obj03689 *)p)->f0,id);
    if (!k) goto fail;
    entry = (u32)func_021B9AEC(*(char * *)&((struct Obj03689 *)p)->f4,id);
    mon = func_021B990C(((struct Obj03689 *)p)->f4,id,(u8)0);
    if (func_021D5B68(mon)) {
        count = func_021B99B8(((struct Obj03689 *)p)->f0,id);
        for (i=1;i<count;i++) {
            mon = func_021B990C(((struct Obj03689 *)p)->f4,id,(u8)i);
            if (!func_021D5B68(mon)) break;
        }
    }
    result = -1;
    invalid=0x112;
    ok3=0x112;
    ok2=0x112;
    ok1=0x112;
    ok0=0x112;
    skip=0x112;
    for (i=0;i<4;i++) {
        row = (u8 *)p + i;
        if (!row[skip]) {
            key = d_021EFF78[i];
            if (func_0202A298(k,key,((struct Obj03689 *)p)->f19A)) {
                switch (key - 0x11) {
                case 1:
                    a = func_021D59B4(mon,13);
                    if ((u32)a <= func_021D7B60(mon,2)) { result = i; row[ok0] = 1; }
                    break;
                case 0:
                    if (!func_021D5B48(mon)) { result = i; row[ok1] = 1; }
                    break;
                case 2:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((u8 *)entry) == 1) { result = i; row[ok2] = 1; }
                    break;
                case 3:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((u8 *)entry) == 1) {
                        b = func_021D59B4(mon,13);
                        if ((u32)b <= func_021D7B60(mon,2)) { result = i; row[ok3] = 1; }
                    }
                    break;
                }
            } else row[invalid] = 1;
        }
    }
    if (result >= 0) { *out = d_021EFF78[result]; return 1; }
fail:
    return 0;
}




/*
 * witnesses: four ov093 blocker leaves 021E98AC, 021E98B4,
 * 021D7EF0, 021E9920 filed and individually shard-verified first.
 * lever: packed unsigned bitfields plus narrow caller extern CF5B0 move;
 * record declared before sub settles r6/r7 allocation (one variant).
 * interface: CF5B0 own source takes u32 move, but original narrows id at
 * 021CEBC6/021CEBCC; u16 extern preserves observed caller truncation.
 * CE3B4 ignores r1 but caller explicitly supplies p+0x58, retained here.
 * semantics: word bitfields use unsigned shifts; all dynamic address adds
 * and scaling are u32 modulo 2^32, without assuming selector/index bounds.
 * Byte increment is promoted in 0..255 then narrowed; all locals initialized
 * on each path to a use. The branch to state 4 has no uninitialized outputs.
 */
int func_021CEA94(u8 *p, u32 *state)
{
    void *m;
    u32 slot, k;
    u32 *record;
    u8 sub;
    switch (*state) {
    case 0:
        if (func_021B8588(((struct Obj00434 *)p)->f0) != 3) {
            if (func_021CF524((u32)p, ((struct Obj00434 *)p)->f8, *(u32 *)&((struct Obj00434 *)p)->fC))
                func_021CE150(p, (void *)((u32)func_021CF220));
            else *state = 1;
        } else {
            func_021CECB4(p, (Ent *)(p + 0xa4));
            *state = 2;
        }
        break;
    case 1:
        func_021E97BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 2:
        func_021E9808(((struct Obj00434 *)p)->f54, (u32 *)(p + 0xa4), *(int *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 3:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E98AC(((struct Obj00434 *)p)->f54);
            return 0;
        }
        if (func_021E98B4(((struct Obj00434 *)p)->f54)) {
            k = func_021D8454(*(u32 * *)&((struct Obj00434 *)p)->fC);
            if (k == 0) func_021CE150(p, (void *)((u32)func_021CE4D0));
            else if (k == 5) func_021CE150(p, (void *)((u32)func_021CF220));
            else {
                m = ((struct Obj00434 *)p)->f8;
                record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                sub = 0;
                slot = p[0x11d];
                if (func_021B8588(((struct Obj00434 *)p)->f0) == 3) {
                    sub = (u8)((Record *)(p + 0xbc))->sub;
                    slot = func_021B9AB0(sub);
                    m = *(void **)((u32)p + slot * 8U + 0xa4U);
                }
                if (func_021D832C((struct Unk021D82FC *)record)) {
                    p[0x1b0] = slot;
                    p[0x1b1] = func_021D5778(m, (u16)((Record *)record)->id);
                    if (p[0x1b1] != 4) {
                        func_021CE150(p, (void *)((u32)func_021CED4C));
                        return 0;
                    }
                }
                if (func_021CF5B0(p, m, (u16)((Record *)record)->id, p + 0x58)) {
                    func_021EAF78(p + 0x58, 0xff);
                    func_021CE3B4(p, p + 0x58);
                    *state = 7;
                } else {
                    if (func_021B8588(((struct Obj00434 *)p)->f0) == 3 && sub != 0 && sub != 1 && !func_021D5B68(m)) {
                        k = func_021D8340((u32 *)(p + 0xc0));
                        record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                        *(u32 *)&((struct Obj00434 *)p)->fC = (u32)record + 4U;
                        func_021D83FC(record, sub);
                        func_021D82D0(((struct Obj00434 *)p)->fC, k, 6);
                        ++p[0x1af];
                    }
                    *state = 4;
                }
            }
        }
        break;
    case 4:
        if (func_021D7EF0(func_021B8588(((struct Obj00434 *)p)->f0))) *state = 5;
        else func_021CE150(p, (void *)((u32)func_021CF220));
        break;
    case 5:
        func_021E98BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 6;
        break;
    case 6:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E9920(((struct Obj00434 *)p)->f54);
            return 0;
        }
        k = func_021E98E8(((struct Obj00434 *)p)->f54);
        if (k == 1) func_021CE150(p, (void *)((u32)func_021CF220));
        else if (k == 2) *state = 1;
        break;
    case 7:
        if (func_021EA710(((struct Obj00434 *)p)->f54)) {
            func_021E9858(((struct Obj00434 *)p)->f54);
            *state = 3;
        }
        break;
    }
    return 0;
}



void func_021CECB4(u8 *p, Ent *out)
{
    u32 i;
    u32 j;
    u8 *q;
    u32 n;
    u32 k;
    Ent *e;
    for (i = 0; i < 3; i++) {
        q = func_021B9C00(((struct Obj21136 *)p)->f118, (u8)i);
        e = out + i;
        e->q = q;
        for (j = 0; j < 4; j++) {
            e->f[j] = 0;
        }
        if (func_021D5B68(q) == 0) {
            n = func_021D5448((struct QG *)q);
            for (k = 0; k < n; k++) {
                if (func_021D5584((struct UtilWork *)q, (u8)k) == 0 || func_021CF5B0(p, q, (u32)func_021D54C0(q, (u8)k), 0) != 0) {
                    e->f[k] = 0;
                } else {
                    e->f[k] = 1;
                }
            }
        }
    }
}



u32 func_021CED4C(u8 *p, s32 *st)
{
    u32 r;
    switch (*st) {
    case 0:
        func_021E9CE0((u8 *)(((struct Obj05199 *)p)->f54), p[0x1b0], p[0x1b1]);
        *st = *st + 1;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0) != 0) {
            func_021E9B14((unsigned int *)(((struct Obj05199 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CEA94));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CE3C8));
        }
        break;
    }
    return 0;
}



u32 func_021CEDC0(u8 *p, int *st)
{
    u8 a;
    u16 b;
    u32 r, n;
    switch (*st) {
    case 0:
        r = 0;
        if ((u8)func_021CF8D4(p, ((struct Obj03194 *)p)->f8, &a, &b) != 4 ||
            a == func_021D5440(((struct Obj03194 *)p)->f8)) r = 1;
        func_021E9A78(*(char * *)&((struct Obj03194 *)p)->f54, p + 0x184, p[0x11d], r, p + 0x190);
        ++*st;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9B14((unsigned int *)(*(u32 *)&((struct Obj03194 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) {
            if (func_021CEE98(p + 0x190) == 0) {
                n = func_021CEEA8(p + 0x190);
                if (n < 6) {
                    func_021D8394(((struct Obj03194 *)p)->fC, p[0x11d], n);
                    func_021CE150(p, (void *)((u32)func_021CF220));
                    break;
                }
            }
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}
