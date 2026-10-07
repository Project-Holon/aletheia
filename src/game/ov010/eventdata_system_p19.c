/*
 * file:     eventdata_system_p19.c
 * unit:     yes
 * function: func_02163154, func_02163188, func_021631C0
 * address:  0x02163154
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D57C 0x0216D57C thumb ov010
 *   func_021632F0 0x021632F0 thumb ov010
 *   func_02163288 0x02163288 thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 *   func_021633A8 0x021633A8 thumb ov010
 *   func_02163340 0x02163340 thumb ov010
 *   func_02082C60  0x02082C60  arm
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE28  0x021ABE28  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
    void *g;
    int h;
    u8 i;
} S;

extern u32 func_0216D57C(void *p, u32 v);
extern void func_021632F0(int a0);
extern void func_02163288(int a0);
extern char *func_0216D570(char *p, u32 v);
extern void func_021633A8(int a0);
extern void func_02163340(int a0);
extern void func_02082C60();
extern u32 func_0216D7E4(void *p);
extern u32 func_0216D7DC(void *p);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern void *func_0216E3C4(void *p);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
extern u8 func_021ABE28(u8 *p);
void func_02163154(char *p);
void func_02163188(char *p);
void func_021631C0(int a, S *s);

/*
 * trailing: two-byte zero alignment at 0x02163186 before func_02163188.
 */
void func_02163154(char *p)
{
    if (func_0216D57C(p, 0x80)) func_021632F0((int)p);
    else if (func_0216D57C(p, 0x20)) func_02163288((int)p);
    func_0216D570(p, 0xa0);
}

/*
 * trailing: two-byte zero alignment at 0x021631BE before func_021631C0.
 */
void func_02163188(char *p)
{
    if (func_0216D57C(p, 0x100)) func_021633A8((int)p);
    else if (func_0216D57C(p, 0x40)) func_02163340((int)p);
    func_0216D570(p, 0x140);
}


void func_021631C0(int a, S *s)
{
    int b;
    u32 h;

    func_02082C60(s, 0, 0x1c);
    s->a = func_0216D7E4((void *)a);
    b = func_0216D7DC((void *)a);
    s->b = b;
    if (b != -1) {
        s->d = func_021AB0F0(b);
        s->f = func_021AB0F8(s->b);
    }
    if (s->a != -1) {
        s->c = func_021AB0F0(s->a);
        s->e = func_021AB0F8(s->a);
    }
    s->g = func_0216E3C4((void *)a);
    h = func_02188CD0((u8 *)func_0216D534((void *)func_0216D67C((void *)a)));
    s->h = h;
    s->i = func_021ABE28((u8 *)h);
}
