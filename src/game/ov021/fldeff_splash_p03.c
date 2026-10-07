/*
 * file:     fldeff_splash_p03.c
 * unit:     yes
 * function: func_021C49C0, func_021C4A00
 * address:  0x021C49C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 */
struct BbActRec;
struct BbActSys;
struct X;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct S_021C49C0 { u32 w0; u8 b4, b5, b6, b7; u32 w8; } S_021C49C0;

typedef struct P { u32 f0; u32 f4; u16 f8; } P;

typedef struct {
    u32 f0;
    u32 obj;
    u16 id;
} S_021C4A00;

extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
void func_021C49C0(P *p);
void func_021C4A00(S_021C4A00 *s);


void func_021C49C0(P *p)
{
    S_021C49C0 s;
    u32 x = func_021ABE24((u8 *)p->f0);

    s.b4 = 2;
    s.b5 = 0x13;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.w8 = 1;
    s.w0 = (u32)func_02046E24(x, 0x2d);
    func_021AC1F0((struct X *)p->f0, (void *)s.w0);
    p->f8 = func_020500F0((struct BbActSys *)p->f4, (const struct BbActRec *)(&s), 1);
}


void func_021C4A00(S_021C4A00 *s)
{
    func_02050278((struct BbActSys *)s->obj, s->id, 1);
}
