/*
 * file:     unit_021BF050_p11.c
 * unit:     yes
 * function: func_021C0C7C, func_021C0C88, func_021C0E60, func_021C0F70
 * address:  0x021C0C7C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02156BC4  0x02156BC4  thumb  ov009
 *   func_020200CC  0x020200CC  thumb
 *   func_021BF050  0x021BF050  thumb  ov099
 *   func_021B97F4  0x021B97F4  thumb  ov099
 *   func_021BE2A8  0x021BE2A8  thumb  ov099
 *   func_0203CB00  0x0203CB00  arm
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_021B9AE0  0x021B9AE0  thumb  ov099
 *   func_021BE900  0x021BE900  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_020061E4  0x020061E4  thumb
 *   func_021BDD54  0x021BDD54  thumb  ov099
 *   func_0202EB14  0x0202EB14  thumb
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BDDD0  0x021BDDD0  thumb  ov099
 *   func_021BDD60  0x021BDD60  thumb  ov099
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   func_021C27E0  0x021C27E0  thumb  ov099
 *   func_0201AC80 0x0201AC80 thumb
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_0203C3EC 0x0203C3EC arm
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_02156D5C 0x02156D5C thumb ov009
 *   func_0203C5EC 0x0203C5EC arm
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../../matched/include/Obj03224.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32_021C0C7C;

typedef int s32_021C0C7C;

typedef unsigned long  u32_021C0C88;

struct P { char a[0x1cc]; u32_021C0C88 f1cc; char b[0x7c]; char f24c[4]; };

typedef signed int     s32_021C0C88;

extern void func_02156BC4(int);
extern s32_021C0C88 func_020200CC(struct Obj *o);
extern int func_021BF050(char *p);
extern u8 func_021B97F4(char *p);
extern void *func_021BE2A8(char *p, int key);
extern int func_0203CB00(void);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32_021C0C88 func_0201F868(void *p);
extern void func_021B9AE0(void *w, u8 *s);
extern void func_021BE900(char *p);
extern void func_021BA8EC(char *p);
extern void func_020061E4(u32_021C0C88 a);
extern int func_021BDD54(char *p, char *s);
extern int func_0202EB14(void);
extern u32_021C0C88 func_0202EB0C(void);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_021BDDD0(char *p);
extern int func_021BDD60(int x);
extern void func_021BCC4C(void *a);
extern int func_021BDDF4(char *p);
extern int func_021C27E0(void *p);
extern unsigned func_0201AC80(void *);
extern int func_021C23B8(int i);
extern unsigned char func_021BDD48(char *, void *);
extern void func_021BA874(char *, int);
extern unsigned char func_021C23C0(void *a);
extern int func_021C23C8(void *a, void *b);
extern void func_021BDE30(void *, int, int);
extern void func_021C18C8(char *, int, int);
extern void func_021BAADC(char *, int, int);
extern void func_021BC090(void *);
extern int func_021BA928(void *);
extern int func_0203C3EC(void);
extern int func_02156A3C(void);
extern unsigned func_02156D5C(void);
extern int func_0203C5EC(void);
extern int func_021C282C(unsigned char *);
extern void func_021BE6E4(char *);
extern void func_021BA7D8(void *p);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
void func_021C0C7C(void);
int func_021C0C88(char *p, int v);
int func_021C0E60(char *p, int ret);
int func_021C0F70(char *p, int ret);

/*
 * Unblocked (was MATCH on one witness).
 * +0008 ABS32 func_02156BC4          -> resolved as `matched` by
 * src/matched/ov009_func_02156BC4.c after fixing the ISA/region hint: the
 * target is Thumb code in ov009 (ov010 decodes to a pop with no push), declared
 * as `func_02156BC4 0x02156BC4 thumb ov009` below.
 */
void func_021C0C7C(void) { func_02156BC4(0); }


/*
 * note: 2026-10-05 (wD9r lane72): EXACT 472/472, 31 of 31 relocations. The fix is a pointer local
 *   `st = p + 0x24c;` set at the top of the function (before the first call) and passed to
 *   func_021BDD54 and to the first func_021C27E0. With the field address written at each use, mwcc
 *   made 0x24C one constant temp in r6 and derived 0x1CC from it (`subs r6,#0x80`) in the r4 == 5 and
 *   0x76 paths. The early pointer local is propagated after that pass, so each use rebuilds
 *   `movs #0x93; lsls #2` and every 0x1CC store is fresh, as in the image. Same idiom as ov223
 *   021BB18C (docs/idioms/a-spilled-offset-derived-at-the-top-is-an-early-pointer-local.md). The
 *   pointer set just before the func_021BDD54 call instead gives 464 B DIFF. Earlier DIFF notes
 *   (wD4 to wD9r) tried struct fields, raw and integer offsets, inline helpers, switch and goto shapes;
 *   the enum-local form from lane61 is not used.
 */
int func_021C0C88(char *p, int v)
{
    int r6;
    int r4;
    int r7;
    char *st;
    u16 t;

    st = p + 0x24c;
    r6 = func_020200CC((struct Obj *)(*(u32_021C0C88 *)(p + 0xbc)));
    if (func_021BF050(p)) {
        r6 = -2;
    }
    t = func_021B97F4(p + 0x274);
    *(u16 *)(p + 0x242) = t;
    r7 = (int)func_021BE2A8(p, t);
    if (func_0203CB00()) {
        *(u32_021C0C88 *)(p + 0x1a4) = func_021BA8BC((void *)(*(u32_021C0C88 *)(p + 0x1a4)));
        func_0202020C((struct Obj *)(*(u32_021C0C88 *)(p + 0xbc)), 0, 0);
        func_0201F868((void *)(*(u32_021C0C88 *)(p + 0xb8)));
        if (r7) {
            func_021B9AE0(p + 0x274, (u8 *)r7);
        }
        func_021BE900(p);
        return v;
    }
    if (r6 != -1) {
        func_021BA8EC(p);
        *(u32_021C0C88 *)(p + 0x1a4) = func_021BA8BC((void *)(*(u32_021C0C88 *)(p + 0x1a4)));
        func_0202020C((struct Obj *)(*(u32_021C0C88 *)(p + 0xbc)), 0, 0);
        func_0201F868((void *)(*(u32_021C0C88 *)(p + 0xb8)));
    }
    switch (r6) {
    case -1:
        return v;
    case -2:
        func_020061E4(0x551);
        ((struct P *)p)->f1cc = 0xb;
        goto end;
    }
    func_020061E4(0x54c);
    r4 = func_021BDD54(p, st);
    if (r4 == 5 && !func_0202EB14() && func_0202EB0C()) {
        func_021BAAB8(p, 0x95, 0);
        ((struct P *)p)->f1cc = 0xa2;
        return v;
    }
    if (r4 == 6 && !func_021BDDD0(p)) {
        func_021BAAB8(p, 0x79, 0);
        ((struct P *)p)->f1cc = 0x71;
        goto end;
    }
    if (func_021BDD60(r4)) {
        *(u16 *)(p + 0x134c) = (r4 - 7) / 2;
        *(u16 *)(p + 0x134e) = (r4 - 7) % 2;
        func_021BCC4C(p);
        if (!func_021BDDF4(p)) {
            func_021BAAB8(p, 0x68, 0);
            ((struct P *)p)->f1cc = 0x71;
        }
    }
    *(u32_021C0C88 *)(p + 0x135c) = 2;
    r4 = func_021C27E0(st);
    if (r4 == func_021C27E0(*(void **)(p + 8))) {
        ((struct P *)p)->f1cc = 0x76;
    } else {
        if (func_021C27E0(*(void **)(p + 8))) {
            func_021BAAB8(p, 0x49, 0);
        } else {
            func_021BAAB8(p, 0x48, 0);
        }
        ((struct P *)p)->f1cc = 0x37;
    }
end:
    if (r7) {
        func_021B9AE0(p + 0x274, (u8 *)r7);
    }
    return v;
}

/*
 * lever: signed int locals with the witnessed byte return prevent index-minus-one hoisting.
 * prototype: C23B8 forwards the visible index to 56860 and returns its pointer.
 */
int func_021C0E60(char *p, int ret)
{
    int index;
    void *state;
    int kind, value, flag;
    index = ((struct Obj03224 *)p)->f242;
    func_0201AC80(((struct Obj03224 *)p)->fC8);
    if (((struct Obj03224 *)p)->f242 == 0) {
        func_021BAAB8(p, 0x4a, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
    }
    state = (void *)func_021C23B8(index - 1);
    kind = func_021BDD48(p, state);
    value = func_021BDD54(p, state);
    flag = func_021C27E0(state);
    if (kind != func_021BDD48(p, p + 0x24c) ||
        value != func_021BDD54(p, p + 0x24c) ||
        flag != func_021C27E0(p + 0x24c) || kind == 6) {
        func_021BA874(p, index - 1);
        func_021BAAB8(p, 13, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
        return ret;
    }
    func_021C23C0((void *)(index - 1));
    if (func_021C23C8(p, (void *)(index - 1))) {
        ((struct Obj03224 *)p)->f1C4 = 0xe10;
        func_021BDE30(p, 3, value);
        func_021C18C8(p, 3, value);
        func_021BA874(p, index - 1);
        func_021BAADC(p, 14, 0);
        func_021BC090(p);
        ((struct Obj03224 *)p)->f242 = index;
        ((struct Obj03224 *)p)->f1CC = 37;
    } else {
        func_021BA874(p, index - 1);
        func_021BAAB8(p, 13, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
    }
    return ret;
}

/*
 *   extern char *d_021469DC;
 *   int func_0203C5EC(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   but its function: header lists only CF4; no duplicate leaf permitted.
 * extent-policy: no follower C filed while ARM9 also blocks this caller.
 * extent: 236-byte lead followed by two 4-byte return-r1 stubs at 105C/1060.
 * prototype: D7B0/D7BC preserve the caller's visible integer input through veneers.
 */
int func_021C0F70(char *p, int ret)
{
    void *selection;
    func_021BA928(p);
    if (--*(int *)(p + 0x1c4) < 0) {
        selection = func_021BE2A8(p, func_021B97F4(p + 0x274));
        if (selection) func_021B9AE0(p + 0x274, selection);
        *(int *)(p + 0x1cc) = 61;
    } else if (func_0203C3EC() == 5) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (func_02156D5C() == 5) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 12, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (func_02156D5C() == 4 || func_0203C5EC() != 0) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (func_0203C3EC() == 1) {
        func_021C282C(*(unsigned char **)(p + 8));
        func_021BE6E4(p);
        func_021BDD48(p, *(void **)(p + 8));
        *(int *)(p + 0x1cc) = 41;
        func_021BA8EC(p);
        func_021BA7D8(p);
        *(int *)(p + 0x1e0) = 30;
        func_0203D7B0(1);
        func_0203D7BC(1);
    }
    return ret;
}
