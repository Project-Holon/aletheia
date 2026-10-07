/*
 * file:     ctvt_comm_p06.c
 * unit:     yes
 * function: func_021B8154, func_021B8448, func_021B8454
 * address:  0x021B8154
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203EA54 0x0203EA54 arm
 *   func_0203E758 0x0203E758 arm
 *   func_02082A90 0x02082A90 arm
 *   func_021C2B74 0x021C2B74 arm ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 *   func_021BE1A4 0x021BE1A4 thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021B8628 0x021B8628 thumb ov172
 *   func_021BE0F8 0x021BE0F8 thumb ov172
 *   func_021BE0FC 0x021BE0FC thumb ov172
 *   func_021BE0AC 0x021BE0AC thumb ov172
 *   func_021B7818 0x021B7818 thumb ov172
 *   func_021B785C 0x021B785C thumb ov172
 *   func_021B77B8 0x021B77B8 thumb ov172
 *   func_021B77E8 0x021B77E8 thumb ov172
 *   func_021B8A14 0x021B8A14 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021B8AD4 0x021B8AD4 thumb ov172
 *   func_02179650 0x02179650 thumb ov014
 *   func_0203D1C0 0x0203D1C0 arm
 *   func_0203E808 0x0203E808 arm
 *   func_0203E8C8 0x0203E8C8 arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_021BE058 0x021BE058 thumb ov172
 *   func_021BE0A8 0x021BE0A8 thumb ov172
 *   func_021B7B20 0x021B7B20 thumb ov172
 *   func_021B8614 0x021B8614 thumb ov172
 */
#define W(o) (*(int *)(b + (o)))
#define B(o) (*(u8 *)(b + (o)))
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 x[0x21]; } S21;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern int func_0203D1B4(void);
extern int func_0203EA54(void);
extern void func_0203E758(int, int, int, int);
extern void func_02082A90(const void *, void *, u32);
extern unsigned long func_021C2B74(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);
extern u32 func_021BDFDC(void *);
extern void func_021B7740(void *, char *, int, int);
extern void func_021BE1A4(char *p);
extern u32 func_021BE078(void *);
extern void func_021B8628(void *a, int b, int *t, int c);
extern u32 func_021BE0F8(void *);
extern void func_021BE0FC(void *, u32);
extern u32 func_021BE0AC(void *);
extern u32 func_021B7818(void *p, void *q);
extern u32 func_021B785C(void *, u32);
extern u32 func_021B77B8(void *, u32);
extern u32 func_021B77E8(void *, u32);
extern u32 func_021B8A14(int unused, char *q);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern int func_021B8AD4(int unused, char *base);
extern void func_02179650(u16 v);
extern u32 func_0203D1C0(u32 index);
extern void func_0203E808(u32 a, int b, u32 c, u32 d);
extern void func_0203E8C8(int a);
extern u16 func_021BE00C(u16 *p);
extern void func_021BE058(void *p, u32 v);
extern void func_021BE0A8(void *p, u32 v);
extern void func_021B7B20(int unused, char *base, int i);
extern void func_021B8614(int unused, int unused2, void *p);
void func_021B8154(void *a, char *b);
void func_021B8448(void *p, char *q);
void func_021B8454(void *a, char *q);

/*
 * note 2026-10-05 wD4 lane05: EXACT*. Three source fixes: the 0x21-byte copy b+0x40 -> b+0x80 is a struct copy
 *   (one-member u8[0x21] struct); the slot stores go in offset order (0x74 = 0, 0x78 = 0xff, 0x7c = 0);
 *   in the j loop `hit = 1` comes before the slot store.
 */
void func_021B8154(void *a, char *b)
{
    int busy;
    u8 i;
    u8 cur;
    u8 j;
    u32 r7;
    u32 s18, s1c, s20, s24;
    int res;
    int hit;
    busy = func_0203D1A4((struct Link *)func_020399A8());
    if (W(0x174) == 2) {
        if (W(0x64) == 0) {
            u32 v = func_021BDFDC(a);
            W(0x64) = 1;
            W(0x68) = 1;
            W(0x6c) = 1;
            W(0x70) = 1;
            W(0x74) = 0;
            B(0x78) = 0xff;
            W(0x7c) = 0;
            *(S21 *)(b + 0x80) = *(S21 *)(b + 0x40);
            B(0x2c) = 1;
            B(4) = 1;
            func_021B7740(a, (char *)v, 0, 0);
        }
    } else {
        cur = func_0203D1B4();
        if (B(4) != cur) {
            func_021B8454(a, b);
            func_021BE1A4(a);
            if (B(4) < cur && busy == 0) {
                W(0x3b8) = 1;
                W(0x3bc) = func_021BE078(a);
            }
            W(0x3b4) = 1;
            B(4) = cur;
            B(0x2c) = cur;
        }
    }
    for (i = 0; i < 4; i++) func_021B8628(a, (int)b, (int *)(b + 0x64 + i * 0x40), i);
    if (B(4) > 1) {
        if (W(0x184) == 1) {
            if (func_0203EA54() == 1) W(0x184) = 0;
        } else {
            u8 c1 = B(0x182);
            u8 c2 = B(0x183);
            if (c1 == (c1 & c2) && c1 != 0) {
                if (func_021BE0F8(a) == 0) {
                    func_021BE0FC(a, 1);
                    if (func_021BE0AC(a) == 0) {
                        r7 = func_021BDFDC(a);
                        s18 = func_021B7818(a, (void *)r7);
                        s1c = func_021B785C(a, r7);
                        func_02082A90((void *)s18, (void *)W(0x18c), s1c);
                        s20 = func_021B77B8(a, r7);
                        s24 = func_021B77E8(a, r7);
                        res = func_021C2B74((void *)W(0x18c), (unsigned char *)W(0x190), s1c, (unsigned char *)W(0x188), s20, s24, 0x46, 1, 4);
                        if (res != 0) {
                            func_0203E758(W(0x190), res, B(0x182), 0);
                            B(0x183) = 0;
                            W(0x184) = 1;
                        }
                    }
                    func_021BE0FC(a, 0);
                }
            }
        }
        if (B(0x1ac) != B(0x1ad)) {
            if (W(0x3c0) == 1) func_021B8A14((int)a, b);
        }
        if (W(0x3c4) == 1) {
            if (func_021B8740((int)a, (int)b, 4, 0) == 1) W(0x3c4) = 0;
        }
        if (W(0x3cc) == 1) {
            if (func_021B8740((int)a, (int)b, 5, 0) == 1) W(0x3cc) = 0;
        }
        if (W(0x3b4) == 1) {
            if (func_021B8AD4((int)a, b) == 1) W(0x3b4) = 0;
        }
    }
    if (busy == 0) {
        if (W(0x3b8) == 1) {
            if (func_021B8740((int)a, (int)b, 2, W(0x3bc)) == 1) W(0x3b8) = 0;
        }
        if (W(0x3b0) == 1) {
            hit = 0;
            for (j = 0; j < 4; j++) {
                if (*(int *)(b + j * 64 + 0x74) == 1) {
                    if (B(0x3d8) == 0xff) B(0x3d8) = j;
                    hit = 1;
                    *(int *)(b + j * 64 + 0x74) = 0;
                }
            }
            if (hit == 0) B(0x3d8) = 0xff;
            if (B(0x3d8) != B(0x3ae)) W(0x3d4) = 1;
            W(0x3b0) = 0;
        }
        cur = B(0x3d8);
        if (cur != 0xff) {
            if (*(int *)(b + cur * 64 + 0x64) == 0) {
                B(0x3d8) = 0xff;
                W(0x3d4) = 1;
                W(0x3b0) = 0;
            }
        }
        if (W(0x3d4) == 1) {
            if (func_021B8740((int)a, (int)b, 1, B(0x3d8)) == 1) W(0x3d4) = 0;
        }
    }
}

/*
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov014 leaf 02179650 (pengy range, no label) is unresolved.
 * note 2026-10-04 wD2 lane01: still MATCH. Symbols line already has `thumb ov014`; match.py still says no witness (ov009/ov014 overlap, 021797A8-area leaf func_02179650 unlabelled in pengy's ov014). Needs a matched/labelled leaf at 0x02179650 in ov014 (pengy range, not touched).
 * note 2026-10-02: byte-correct. Only open relocation: the tail-call target 0x02179650 (pool word 0x02179651)
 *   is an unlabelled thumb leaf in ov014 ("ldr r1, =g_021797A8; ldr r2, [r1]; ldr r1, =0x1EC2; strh r0, [r2, r1]; bx lr").
 *   ov014 is outside this lane (pengy range); seeding 0x02179650 there closes this one.
 * note 2026-10-05 (wD8 lane06): re-run, still MATCH. Only blocker: func_02179650, an unlabelled Thumb leaf in ov014
 *   (pengy's overlay, not same-overlay, so the witness exception does not apply). Seeding that label closes this.
 */
void func_021B8448(void *p, char *q)
{
    func_02179650(5);
}


/*
 * note 2026-10-05 wD4 lane05: EXACT. w is a u32 local (callee keeps its real u16 return) declared
 *   between me and base: declaration order me, w, base, e gives slots 0x10, 0xC, 8, 4.
 */
void func_021B8454(void *a, char *q)
{
    u32 count = 0;
    int flag = 0;
    u8 i;
    u32 me;
    u32 w;
    u32 base;
    char *e;

    me = func_0203D1A4((struct Link *)func_020399A8());
    w = func_021BE00C((u16 *)a);
    for (i = 0; i < 4; i++) {
        if (func_0203D1C0(i) == 1) {
            e = q + i * 64;
            if (*(u32 *)(e + 0x64) == 0) {
                base = func_021BDFDC(a);
                *(u32 *)(e + 0x64) = 1;
                if (i == me) {
                    *(u32 *)(e + 0x70) = 1;
                } else {
                    u8 j;
                    for (j = 0; j < 3; j++) {
                        u32 m = 1 << j;
                        if (!(m & *(u8 *)(q + 0x170))) {
                            func_0203E808(0xC000, i, w, *(u32 *)(q + j * 4 + 0x164));
                            *(u8 *)(q + 0x170) |= (u8)m;
                            *(u8 *)(e + 0x78) = j;
                            break;
                        }
                    }
                    *(u8 *)(q + 0x182) |= (u8)(1 << i);
                    *(u32 *)(e + 0x7C) = 1;
                }
                func_021B7B20((int)a, (char *)base, i);
                flag = 1;
            }
            count = (u8)(count + 1);
        } else {
            u32 off = i << 6;
            char *e2 = q + off;
            if (*(u32 *)(e2 + 0x64) == 1) {
                *(u32 *)(e2 + 0x64) = 0;
                if (*(u32 *)(e2 + 0x70) == 0) {
                    func_0203E8C8(i);
                    *(u8 *)(q + 0x170) -= (u8)(1 << *(u8 *)(e2 + 0x78));
                }
                if (*(u8 *)(q + 0x3AE) == i)
                    *(u32 *)(q + 0x194) = 0;
                flag = 1;
                *(u8 *)(q + 0x182) -= (u8)(flag << i);
                func_021B8614((int)a, (int)q, q + 0x64 + off);
            }
        }
    }
    if (flag == 1) {
        func_021BE058(a, count);
        func_021BE0A8(a, me);
    }
    func_021B7740(a, (char *)func_021BDFDC(a), 0, 1);
}
