/*
 * function: func_021BCA68
 * address: 0x021BCA68
 * packet: pkt_ov208_021BCA68
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BCE10 0x021BCE10 thumb
 *   func_021BCEC0 0x021BCEC0 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021BCC80 0x021BCC80 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA54 0x0200CA54 thumb
 *   func_021BD8C0 0x021BD8C0 thumb
 *   func_021BE710 0x021BE710 thumb
 *   func_021BC35C 0x021BC35C thumb
 *   func_021BCC84 0x021BCC84 thumb
 *   func_0204E720 0x0204E720 arm
 *   func_0203D34C 0x0203D34C arm
 * 2026-10-02: only func_021BCC80 (unlabelled bx lr stub, filed as ov208_func_021BCC80.c) lacks a witness; bytes match.
 * Callee func_021BC35C is declared void in its matched file but returns the new object (caller stores r0).
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Args { void *src; int f4; int f8; u16 fc; u16 fe; int f10; };
struct Ov208Main {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    int f20; int f24; int f28;
};
extern void func_0203064C(void *a, u32 heap, u32 size);
extern void *func_0203159C(void *owner, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern char *func_021BCE10(u32 display, u32 heap, int threeD);
extern void func_021BCEC0(char *p);
extern void *func_0201D7EC(int a, int b, int c, int d, u32 heap);
extern void *func_0201C440(u16 heap);
extern int func_020056A0(void (*fn)(void), void *arg, int n);
extern void func_021BCC80(void);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA54(void *a);
extern void *func_021BD8C0(u16 heap, u32 arg);
extern void *func_021BE710(u16 heap, void *arg);
extern void *func_021BC35C(u32 heap, void *a, void *b, void *c, void *d, void *e, void *f, int g, u16 h, void *i);
extern void func_021BCC84(struct Ov208Args *a, struct Ov208Main *m);
extern void func_0204E720(int a, int b, int c, int d);
extern void func_0203D34C(u32 a, u16 heap);
int func_021BCA68(void *owner, int unused, struct Ov208Args *args)
{
    struct Ov208Main *p;
    func_0203064C((void *)1, 0x95, 0x90000);
    p = func_0203159C(owner, 0x2c, 0x95);
    func_02082BCC(p, 0, 0x2c);
    p->heap = 0x95;
    args->f10 = 0;
    p->disp = func_021BCE10(0, p->heap, 1);
    func_021BCEC0(p->disp);
    p->disp = func_021BCE10(0, p->heap, 0);
    p->font = func_0201D7EC(0x17, 0, 0, 0, p->heap);
    p->gfx = func_0201C440(p->heap);
    p->task = func_020056A0(func_021BCC80, p, 1);

    p->f14 = func_021BD8C0(p->heap, func_0200CA54(func_0200CA1C(args->src)));
    p->f18 = func_021BE710(p->heap, p->font);
    p->fsm = func_021BC35C(p->heap, args->src, p->disp, p->font, p->gfx, p->f14, p->f18, args->f8, args->fc, &args->fe);
    p->f20 = 0;
    p->f24 = 0;
    func_021BCC84(args, p);
    p->f28 = 0;
    func_0204E720(3, 0, 0, 0);
    func_0203D34C(1, p->heap);
    return 1;
}
