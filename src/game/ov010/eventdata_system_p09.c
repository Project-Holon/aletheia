/*
 * file:     eventdata_system_p09.c
 * unit:     yes
 * function: func_02163090, func_021630F4, func_0216310C, func_02163130, func_02163154, func_02163188, func_021631C0
 * address:  0x02163090
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
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D564  0x0216D564  thumb  ov010
 *   func_0216DB68  0x0216DB68  thumb  ov010
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_021640B0 0x021640B0 thumb ov010
 *   func_0216DA70 0x0216DA70 thumb ov010
 *   func_021641C8 0x021641C8 thumb ov010
 *   func_02163230 0x02163230 thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 *   func_021632F0 0x021632F0 thumb ov010
 *   func_02163288 0x02163288 thumb ov010
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

typedef unsigned int u32;

typedef signed short s16;

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

extern int func_0216DA5C(void *a0);
extern u32 func_0216D57C(void *p, u32 v);
extern u16 func_0216D5A0(void *p);
extern u32 func_0216D564(void *p);
extern int func_0216DB68(void *a0);
extern int func_0216DCB4(void *a0);
extern int func_02164010(int a);
extern int func_021640B0(int p);
extern void func_0216DA70(void *a0);
extern void func_021641C8(void *a);
extern void func_02163230(int a0);
extern char *func_0216D570(char *p, u32 v);
extern void func_021632F0(int a0);
extern void func_02163288(int a0);
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
int func_02163090(int a0, int a1);
int func_021630F4(int a0, int a1);
/* * trailing: two-byte zero alignment at 0x0216312E before func_02163130. */ void func_0216310C(char *p);
void func_02163130(char *p);
/* * trailing: two-byte zero alignment at 0x02163186 before func_02163188. */ void func_02163154(char *p);
/* * trailing: two-byte zero alignment at 0x021631BE before func_021631C0. */ void func_02163188(char *p);
void func_021631C0(int a, S *s);



int func_02163090(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_0216DA5C((void *)a0);
loc_02163098:
    if (a0 != 0) goto loc_021630F0;
loc_0216309C:
a1 = 6;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_021630A6:
    if (a0 != 0) goto loc_021630AE;
loc_021630AA:
a0 = 1;
    return a0;
loc_021630AE:
a0 = t5 + 0;
    a0 = func_0216D5A0((void *)a0);
loc_021630B4:
    if (a0 != 0x32) goto loc_021630BC;
loc_021630B8:
a0 = 1;
    return a0;
loc_021630BC:
a0 = t5 + 0;
    a0 = func_0216D564((void *)a0);
loc_021630C2:
t4 = a0 + 0;
a0 = 1;
a0 = a0 << 0xc;
    if ((a0 & t4) == 0) goto loc_021630DA;
loc_021630CC:
a0 = t5 + 0;
    a0 = func_0216DB68((void *)a0);
loc_021630D2:
    if (a0 != 0) goto loc_021630DA;
loc_021630D6:
a0 = 0;
    return a0;
loc_021630DA:
a0 = 2;
a0 = a0 << 0xa;
    if ((a0 & t4) == 0) goto loc_021630F0;
loc_021630E2:
a0 = t5 + 0;
    a0 = func_0216DCB4((void *)a0);
loc_021630E8:
    if (a0 != 0) goto loc_021630F0;
loc_021630EC:
a0 = 0;
    return a0;
loc_021630F0:
a0 = 1;
    return a0;}




int func_021630F4(int a0, int a1)
{
    int t4;

a1 = 1;
a1 = a1 << 0xc;
t4 = a0 + 0;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163100:
    if (a0 == 0) goto loc_0216310A;
loc_02163104:
a0 = t4 + 0;
    a0 = func_02164010(a0);
loc_0216310A:
    return a0;}



/*
 * trailing: two-byte zero alignment at 0x0216312E before func_02163130.
 */
void func_0216310C(char *p)
{
    if (func_0216D57C(p, 0x800) != 0 && func_021640B0((int)p) == 1)
        func_0216DA70(p);
}



void func_02163130(char *p)
{
    if (func_0216D57C(p, 0x20)) {
        func_021641C8(p);
        func_02163230((int)p);
    }
    func_0216D570(p, 0xa0);
}


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
