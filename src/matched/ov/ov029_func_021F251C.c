/*
 * function: func_021F251C
 * address:  0x021F251C
 * packet:   pkt_ov029_021F251C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wave D5 lane 02): arm9 func_02035010/func_02035040 and their setters func_02035004/func_02035034 are now filed in src/matched/arm9/; the wrappers show MATCH only until the labels exist. Re-run after the integrator labels them.
 * 2026-10-04 (wD2 lane 09): bytes are identical; 3 of 41 relocations open.
 * Filed leaf func_021F24FC as matched ov029_func_021F24FC.c (EXACT).
 * Open: ABS32 +01C0 to 021F24FC (witness index not yet regenerated),
 * and THM_CALL +0128/+0130 to unlabelled arm9 02035010 and 02035040 (arm9 wrappers:
 * r2=*(0x021469BC), tail call to 02035004/02035034 style stubs, no source or label yet).
 *
 * Byte-correct.  Blocked by two unlabelled ARM9 leaves (Ilias's), so the
 * overlay leaf 0x021F24FC is not filed either:
 *   +0128 func_02035010 (arm): verified MATCH with `one --arm`, capped
 *     only by its own unlabelled tail-call target 0x02035004
 *     (str r1,[r0,#0x14]; str r2,[r0,#0x28]; bx lr):
 *       extern void *d_021469BC;
 *       void func_02035010(void *cb, void *arg)
 *       { func_02035004(d_021469BC, cb, arg); }
 *   +0130 func_02035040 (arm): the same wrapper over 0x02035034
 *     (str r1,[r0,#0x10]; str r2,[r0,#0x28]; bx lr), MATCH likewise:
 *       void func_02035040(void *cb, void *arg)
 *       { func_02035034(d_021469BC, cb, arg); }
 *   +01C0 ABS32 func_021F24FC (ov029): unlabelled leaf
 *     `void func_021F24FC(u8 *p) { p[0x451] = 2; }` (ldr r1,=0x451;
 *     movs r2,#2; strb r2,[r0,r1]; bx lr).
 * Levers: r = 0 at the top shares the zero register with the 0x214/0x218
 * stores; t = 1 assigned after the func_02021518 store keeps t in a stack
 * slot and 0x1C0 in r7; p is u8 * (ldrb of 0x45A); func_021F3144's second
 * argument is int here (no narrowing before the call).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040 (no source change possible here).
 *
 * symbols:
 *   func_0201214C  0x0201214C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F21F8  0x021F21F8  thumb  ov029
 *   func_021F2180  0x021F2180  thumb  ov029
 *   func_021F0298  0x021F0298  thumb  ov029
 *   func_021F1624  0x021F1624  thumb  ov029
 *   func_021F1DE8  0x021F1DE8  thumb  ov029
 *   func_02009100  0x02009100  thumb
 *   func_021F23CC  0x021F23CC  thumb  ov029
 *   func_021F15FC  0x021F15FC  thumb  ov029
 *   func_021F0A0C  0x021F0A0C  thumb  ov029
 *   func_02021518  0x02021518  thumb
 *   func_02021EE4  0x02021EE4  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_021F0DB4  0x021F0DB4  thumb  ov029
 *   func_02021D50  0x02021D50  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_021F2508  0x021F2508  thumb  ov029
 *   func_02035010  0x02035010  arm
 *   func_021F24C0  0x021F24C0  thumb  ov029
 *   func_02035040  0x02035040  arm
 *   func_021F24FC  0x021F24FC  thumb  ov029
 *   func_021F2E10  0x021F2E10  thumb  ov029
 *   func_021F1CD8  0x021F1CD8  thumb  ov029
 *   func_021F1F80  0x021F1F80  thumb  ov029
 *   func_020120D8  0x020120D8  thumb
 *   func_021F3144  0x021F3144  thumb  ov029
 *   func_021F2D84  0x021F2D84  thumb  ov029
 *   func_02030D28  0x02030D28  arm
 *   func_02012138  0x02012138  thumb
 *   func_021585E0  0x021585E0  thumb  ov010
 *   func_02158614  0x02158614  thumb  ov010
 *   d_021F3554     0x021F3554  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int d_021F3554;

extern u8 func_0201214C(int a);
extern int func_020490F4(unsigned int id, u16 heap);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heap, u32 size, u32 flag, void *file, u32 line);
extern int func_02030CBC(u32 n, void *mem);
extern void func_021EFEF8(u8 *p, void (*f)(void), int a);
extern void func_021F21F8(u8 *p);
extern void func_021F2180(void);
extern void func_021F0298(u8 *p);
extern void func_021F1624(u8 *p);
extern void func_021F1DE8(u8 *p, int flag);
extern int func_02009100(int a);
extern int func_021F23CC(u8 *p, int a);
extern void func_021F15FC(u8 *p, int a);
extern void func_021F0A0C(u8 *p);
extern int func_02021518(int heap);
extern void func_02021EE4(int a, int b);
extern void func_0202155C(int h, int a, int b, int c);
extern void func_020216D4(int h, int a, int b, int c);
extern void func_021F0DB4(u8 *p, int mode);
extern void func_02021D50(int h);
extern int func_020056A0(void *callback, void *ctx, int a2);
extern void func_021F2508(void);
extern void func_02035010(void *callback, void *ctx);
extern void func_021F24C0(void);
extern void func_02035040(void *callback, void *ctx);
extern void func_021F24FC(void);
extern void func_021F2E10(u8 *p, void *q);
extern void func_021F1CD8(u8 *p);
extern void func_021F1F80(u8 *p);
extern int func_020120D8(int a);
extern void func_021F3144(u8 *p, int v);
extern void func_021F2D84(u8 *p);
extern void func_02030D28(int a);
extern int func_02012138(int a);
extern int func_021585E0(int a);
extern void func_02158614(int a);

void func_021F251C(u8 *p, int a1, int a2, int a3, int e)
{
    int r = 0;
    int t;
    int h;

    *(u16 *)(p + 0xc) = 0x70;
    *(int *)(p + 0x20) = a1;
    *(int *)(p + 0x18) = a2;
    *(int *)(p + 0x1c) = a3;
    p[0x454] = 1;
    p[0x45A] = func_0201214C(a3);
    p[0x45B] = 1;
    *(int *)(p + 0x214) = 0;
    *(int *)(p + 0x218) = 0;
    *(int *)(p + 0x24) = func_020490F4(0x1e, 0x70);
    *(void **)(p + 0x20C) = func_02030734(0x70, func_02030CB0(4), 1, &d_021F3554, 4280);
    *(int *)(p + 0x204) = func_02030CBC(4, *(void **)(p + 0x20C));
    if (e != 0) {
        func_021EFEF8(p, (void (*)(void))func_021F21F8, 4284);
    } else {
        func_021F0298(p);
        func_021EFEF8(p, func_021F2180, 4287);
    }
    func_021F1624(p);
    func_021F1DE8(p, e);
    if (func_02009100(*(int *)(p + 0x20)) != 0)
        r = func_021F23CC(p, a3);
    func_021F15FC(p, r);
    func_021F0A0C(p);
    *(int *)(p + 0x210) = func_02021518(0x70);
    t = 1;
    func_02021EE4(*(int *)(p + 0x210), 1);
    func_0202155C(*(int *)(p + 0x210), 3, 0x1C0, 0x70);
    func_0202155C(*(int *)(p + 0x210), 1, 0x1C0, 0x70);
    func_020216D4(*(int *)(p + 0x210), 3, 0, 0x1C0);
    func_020216D4(*(int *)(p + 0x210), 1, 0, 0x1C0);
    func_021F0DB4(p, p[0x45A]);
    func_02021D50(*(int *)(p + 0x210));
    *(int *)(p + 0x208) = func_020056A0((void *)func_021F2508, p, 1);
    func_02035010((void *)func_021F24C0, p);
    func_02035040((void *)func_021F24FC, p);
    func_021F2E10(p, p + 0x21C);
    func_021F1CD8(p);
    func_021F1F80(p);
    if (e == 0) {
        if (func_020120D8(a3) != 0)
            t = 0;
        func_021F3144(p, t);
        func_021F2D84(p);
    } else {
        func_021F21F8(p);
    }
    if (*(int *)(p + 0x204) != 0)
        func_02030D28(*(int *)(p + 0x204));
    h = func_02012138(a3);
    if (h != 0 && func_021585E0(h) == 2)
        func_02158614(h);
}
