/*
 * file:     bsubway_scr_p07.c
 * unit:     yes
 * function: func_021C8D3C, func_021C8D74, func_021C8DC4, func_021C8DD4
 * address:  0x021C8D3C
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
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021C8CF8  0x021C8CF8  thumb  ov021
 *   func_021C8D08  0x021C8D08  thumb  ov021
 *   func_021C8DF4  0x021C8DF4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021AD598  0x021AD598  thumb  ov021
 *   func_021C8E14  0x021C8E14  thumb  ov021
 *   func_021C8B9C  0x021C8B9C  thumb  ov021
 *   func_021C8D18  0x021C8D18  thumb  ov021
 *   func_021C8BD8  0x021C8BD8  thumb  ov021
 */
struct T;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;

extern int func_021C8D08(u32 a);
extern int func_021C8CF8(u32 a);
extern void func_0216D410(u32 a, u32 b);
extern void func_021C8DF4(P *p);
extern u32 func_02188CD0(u8 *p);
extern int func_021ABE8C(struct T *a, int id);
extern void func_021ABE30(int a, int *b, int c);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021AD598(u32 a, u32 b, u32 c);
extern void func_021C8E14(int *p);
extern u16 func_021C8D18(P *p);
extern void *func_021C8B9C(u16 id);
extern void *func_021C8BD8(u16 id);
void func_021C8D3C(P *p);
void func_021C8D74(int *p);
void func_021C8DC4(P *p);
void func_021C8DD4(P *p);

void func_021C8D3C(P *p)
{
    if (p->f14 != 0) {
        func_0216D410(p->fC, func_021C8D08((u32)p));
        func_021C8DF4(p);
        p->f18 = 1;
        return;
    }
    if (p->f10 != 0)
        func_0216D410(p->fC, func_021C8CF8((u32)p));
}


void func_021C8D74(int *p)
{
    int buf[3];
    int v;
    int r5;

    if (p[5] != 0) {
        r5 = func_02188CD0((u8 *)p[1]);
        v = 9;
        if (func_021ABE8C((struct T *)r5, v) == 0) {
            func_021ABE30(r5, &v, 1);
        }
        func_021A3038((unsigned char *)p[2], (struct VecFx32 *)buf);
        func_021AD598(r5, 0, (u32)buf);
        func_021C8E14(p);
        p[5] = 0;
        p[6] = 0;
    }
}

void func_021C8DC4(P *p)
{
    p->f10 = func_021C8B9C(func_021C8D18(p));
}

void func_021C8DD4(P *p)
{
    p->f14 = func_021C8BD8(func_021C8D18(p));
}
