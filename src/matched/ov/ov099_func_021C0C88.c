/*
 * function: func_021C0C88
 * address:  0x021C0C88
 * packet:   pkt_ov099_021C0C88
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * symbols:
 *   func_020200CC  0x020200CC  thumb
 *   func_021BF050  0x021BF050  thumb  ov099
 *   func_021B97F4  0x021B97F4  thumb  ov099
 *   func_021BE2A8  0x021BE2A8  thumb  ov099
 *   GFL_NET_STATE_IsFatalError  0x0203CB00  arm
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
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct P { char a[0x1cc]; u32 f1cc; char b[0x7c]; char f24c[4]; };
typedef signed int     s32;
struct Obj;
extern s32 func_020200CC(struct Obj *o);
extern int func_021BF050(char *p);
extern u8 func_021B97F4(char *p);
extern void *func_021BE2A8(char *p, int key);
extern int GFL_NET_STATE_IsFatalError(void);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_021B9AE0(void *w, u8 *s);
extern void func_021BE900(char *p);
extern void func_021BA8EC(char *p);
extern void func_020061E4(u32 a);
extern int func_021BDD54(char *p, char *s);
extern int func_0202EB14(void);
extern u32 func_0202EB0C(void);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_021BDDD0(char *p);
extern int func_021BDD60(int x);
extern void func_021BCC4C(void *a);
extern int func_021BDDF4(char *p);
extern int func_021C27E0(void *p);

int func_021C0C88(char *p, int v)
{
    int r6;
    int r4;
    int r7;
    char *st;
    u16 t;

    st = p + 0x24c;
    r6 = func_020200CC((struct Obj *)(*(u32 *)(p + 0xbc)));
    if (func_021BF050(p)) {
        r6 = -2;
    }
    t = func_021B97F4(p + 0x274);
    *(u16 *)(p + 0x242) = t;
    r7 = (int)func_021BE2A8(p, t);
    if (GFL_NET_STATE_IsFatalError()) {
        *(u32 *)(p + 0x1a4) = func_021BA8BC((void *)(*(u32 *)(p + 0x1a4)));
        func_0202020C((struct Obj *)(*(u32 *)(p + 0xbc)), 0, 0);
        func_0201F868((void *)(*(u32 *)(p + 0xb8)));
        if (r7) {
            func_021B9AE0(p + 0x274, (u8 *)r7);
        }
        func_021BE900(p);
        return v;
    }
    if (r6 != -1) {
        func_021BA8EC(p);
        *(u32 *)(p + 0x1a4) = func_021BA8BC((void *)(*(u32 *)(p + 0x1a4)));
        func_0202020C((struct Obj *)(*(u32 *)(p + 0xbc)), 0, 0);
        func_0201F868((void *)(*(u32 *)(p + 0xb8)));
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
    *(u32 *)(p + 0x135c) = 2;
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
