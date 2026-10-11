/*
 * file:     unit_06899DD8.c
 * unit:     yes
 * function: func_06899DD8, func_06899E2C, func_06899E48, func_06899E68, func_06899ED0, func_06899F28, func_06899F64, func_06899FD4, func_06899FDC, func_06899FE8, func_0689A008, func_0689A020, func_0689A028, func_0689A030
 * address:  0x06899DD8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02082A48  0x02082A48  arm
 *   func_021B8588  0x021B8588  thumb
 *   func_021B86B8  0x021B86B8  thumb
 *   func_021B8D8C  0x021B8D8C  thumb
 *   func_021B8E70  0x021B8E70  thumb
 *   func_021B8ED8  0x021B8ED8  thumb
 *   func_021B8FF4  0x021B8FF4  thumb
 *   func_021B9000  0x021B9000  thumb
 *   func_021B904C  0x021B904C  thumb
 *   func_021B98AC  0x021B98AC  thumb
 *   func_021B9AF8  0x021B9AF8  thumb
 *   func_021B9B94  0x021B9B94  thumb
 *   func_021B9C00  0x021B9C00  thumb
 *   func_021D3D84  0x021D3D84  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021D5444  0x021D5444  thumb
 *   func_021D5864  0x021D5864  thumb
 *   func_021D59B4  0x021D59B4  thumb
 *   func_021D5B68  0x021D5B68  thumb
 *   func_021D5B7C  0x021D5B7C  thumb
 *   func_021D62A8  0x021D62A8  thumb
 *   func_021F81EC  0x021F81EC  thumb
 *   func_0220270C  0x0220270C  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_022021F4  0x022021F4  thumb
 *   func_021D8434  0x021D8434  thumb
 *   func_0689A76C  0x0689A76C  thumb  ov095
 *   func_0689A84C  0x0689A84C  thumb  ov095
 *   func_0689A988 0x0689A988 thumb ov095
 *   func_0689A878 0x0689A878 thumb ov095
 *   func_0689ABA0  0x0689ABA0  thumb  ov095
 *   func_0689AB48  0x0689AB48  thumb  ov095
 *   func_0689B0D4  0x0689B0D4  thumb  ov095
 *   func_0689B1E4  0x0689B1E4  thumb  ov095
 */
#include "../../matched/include/Obj10162.h"
#include "../../matched/include/Obj07909.h"
#include "../../matched/include/Obj21887.h"
#include "../../matched/include/Obj07912.h"
#include "../../matched/include/Obj21889.h"
#include "../../matched/include/Obj07913.h"
#include "../../matched/include/Obj10164.h"
#include "../../matched/include/Obj13634.h"
#include "../../matched/include/Obj21890.h"

struct Q;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef int (*SlotFn)(void *, void *);

typedef struct Slot {
    SlotFn f0;
    SlotFn f1;
    void *arg;
    int data;
} Slot;

typedef struct Obj {
    u8 pad0[0x20];
    Slot tab[4];
    int n;
    u8 pad64[4];
    void *f68;
    void *f6c;
    void *f70;
    u8 pad74[8];
    void *f7c;
    u8 pad80[11];
    u8 f8b;
    u8 pad8c[5];
    u8 f91;
    u8 pad92[6];
    u32 f98;
} Obj;

typedef struct { u8 bytes[12]; } Rec;

typedef struct { Rec rows[2][6]; u32 f90, f94; u32 ids[3], names[3], values[3]; u32 fbc, fc0; u8 fc4, fc5, pad[2]; } Payload;

extern void func_0201C4C0(u32);
extern void func_02045808(u32);
extern void func_022021F4(u32);
extern void func_020307B0(void *);
extern int func_0689A76C(void *, void *);
extern int func_0689A84C(void *, void *);
extern int func_0689A988(void *, void *);
extern int func_0689A878(void *, void *);
extern int func_0689ABA0(void *, void *);
extern int func_0689AB48(void *, void *);
extern void func_021D8434(void *);
extern int func_0689B0D4(void *, void *);
extern int func_0689B1E4(void *, void *);
extern void func_02082A48(u32, void *, u32);
extern u8 func_021D5440(void *);
extern u32 func_021B8D8C(void *, void *, u32);
extern u8 func_021B8E70(void *, u32);
extern void func_021F81EC(u32);
extern u32 func_021B8588(void *);
extern u32 func_021B8FF4(void *);
extern u32 func_021B9000(void *);
extern void *func_021B9AF8(void *, int);
extern u32 func_021B9B94(void *);
extern u8 func_021B8ED8(void *, u32);
extern void *func_021B98AC(void *, u32);
extern int func_021D5B68(void *);
extern u32 func_021D5444(void *);
extern void *func_021D5864(void *);
extern u32 func_02017E1C(void *, int, int);
extern u32 func_021D59B4(void *, int);
extern u32 func_021B86B8(void *);
extern u8 func_021B904C(void *, int);
extern void *func_021B9C00(void *, u8);
extern int func_021D62A8(void *);
extern int func_021D5B7C(void *);
extern u8 func_021D3D84(void *);
extern void func_0220270C(void *, int, void *);
void func_06899DD8(unsigned char *p);
void func_06899E2C(Obj *p);
void func_06899E48(Obj *p, SlotFn a, SlotFn b);
int func_06899E68(Obj *q);
void func_06899ED0(Obj *o, void *a, u8 b, u8 c, void *d);
void func_06899F00(Obj *o, void *a, u8 b, void *c);
u32 func_06899F28(Obj *p);
void func_06899F40(Obj *p, void *a, void *b);
void func_06899F64(Obj *s, u8 *a, void *b);
int func_06899FD4(Obj *q);
void func_06899FDC(Obj *p);
void func_06899FE8(Obj *p, void *a, void *b);
void func_0689A008(Obj *p, void *a, void *b);
int func_0689A020(Obj *q);
void func_0689A028(Obj *p);
int func_0689A030(void *unused, void *arg);

void func_06899DD8(unsigned char *p) {
 func_0201C4C0(((struct Obj10162 *)p)->f14);
 func_02045808(((struct Obj10162 *)p)->fC);
 func_022021F4(((struct Obj10162 *)p)->fB0);
 func_020307B0(p);
}


void func_06899E2C(Obj *p) {
    int i;
    u32 zero;
    unsigned char *q;
    zero = 0;
    for (i = 0; i < 4; i++) {
        q = (unsigned char *)p + i * 16;
        ((struct Obj07909 *)q)->f20 = zero;
        ((struct Obj07909 *)q)->f24 = zero;
        ((struct Obj07909 *)q)->f28 = zero;
        ((struct Obj07909 *)q)->f2C = zero;
    }
    ((struct Obj21887 *)p)->f60 = zero;
}


void func_06899E48(Obj *p, SlotFn a, SlotFn b) {
    int i = p->n++;
    Slot *e = &p->tab[i];
    e->f0 = a;
    e->f1 = b;
    e->arg = p;
    e->data = 0;
}


int func_06899E68(Obj *q)
{
    Slot *e;
    int done;

    if (q->n != 0) {
    e = &q->tab[q->n - 1];
    if (e->f0 != 0) {
        if (e->f0(&e->data, e->arg) != 0) {
            e->f0 = 0;
            e->data = 0;
        }
        done = 0;
    } else if (e->f1 != 0) {
        if (e->f1(&e->data, e->arg) != 0) {
            e->f1 = 0;
            done = 1;
        } else {
            done = 0;
        }
    } else {
        done = 1;
    }
    if (done) {
        e->f0 = 0;
        e->f1 = 0;
        e->arg = 0;
        e->data = 0;
        q->n--;
    }
    return 0;
    }
    return 1;
}


void func_06899ED0(Obj *o, void *a, u8 b, u8 c, void *d)
{
    o->f6c = a;
    o->f70 = d;
    o->f98 = 0;
    o->f8b = b;
    o->f91 = c;
    func_06899E48(o, func_0689A030, func_0689A76C);
}


void func_06899F00(Obj *o, void *a, u8 b, void *c)
{
    o->f6c = a;
    o->f70 = c;
    o->f98 = 0;
    o->f8b = b;
    func_06899E48(o, func_0689A030, func_0689A84C);
}


u32 func_06899F28(Obj *p) {
    if (func_06899E68(p)) return p->f98;
    return 0;
}


void func_06899F40(Obj *p, void *a, void *b) {
    p->f6c = a;
    p->f70 = b;
    p->f98 = 0;
    p->f68 = (void *)func_0689A988;
    func_06899E48(p, func_0689A878, func_0689A988);
}


void func_06899F64(Obj *s, u8 *a, void *b)
{
    s->f98 = 0;
    s->f7c = a;
    s->f70 = b;
    s->f68 = (void *)func_0689ABA0;
    func_021D8434(b);
    func_021D8434(a + 0x18);
    func_021D8434(a + 0x1c);
    func_06899E48(s, func_0689AB48, func_0689ABA0);
}


int func_06899FD4(Obj *q)
{
    return func_06899E68(q);
}


void func_06899FDC(Obj *p)
{
    func_06899E48(p, 0, p->f68);
}


void func_06899FE8(Obj *p, void *a, void *b)
{
    p->f6c = a;
    p->f70 = b;
    p->f98 = 0;
    func_06899E48(p, func_0689A878, func_0689A84C);
}


void func_0689A008(Obj *p, void *a, void *b)
{
    p->f6c = a;
    p->f70 = b;
    func_06899E48(p, func_0689B0D4, func_0689B1E4);
}


int func_0689A020(Obj *q)
{
    return func_06899E68(q);
}


void func_0689A028(Obj *p)
{
    func_06899E2C(p);
}


/*
 *   Each is bx pc; mov r8,r8; ARM ldr ip,[pc]; bx ip; target+1.
 *   Four repeated groups call 021B8ED8,021B98AC,021D5B68,021D5444,
 *   021D5864,02017E1C,021D59B4. They have no label/seed evidence.
 * prototype: full r1 arguments at A4DC/A54C/A5BC/A62C avoid unwitnessed
 *   byte truncation; A70C retains the observed narrow argument.
 * shape: the 200-byte cleared payload fixes the record and trailer layout.
 */
int func_0689A030(void *unused, void *arg)
{
    u8 *p = arg;
    u16 n, pass, index;
    void *groups[2] = {0, 0};
    u16 counts[2] = {0, 0};
    u32 mode, first, second, side, slot;
    void *mon;
    Payload out;
    pass = 0;
    func_02082A48(0, &out, 200);
    out.fc0 = p[0x90];
    out.fc4 = p[0x91];
    first = func_021D5440(*(void **)(p + 0x6c));
    first = func_021B8D8C(*(void **)(p + 0xa0), *(void **)(p + 0xa4), first);
    out.fbc = func_021B8E70(*(void **)(p + 0xa0), first);
    func_021F81EC(out.fbc);
    mode = func_021B8588(*(void **)(p + 0xa0));
    for (; pass < 2; pass++) {
        groups[0] = 0;
        groups[1] = 0;
        if (pass == 0) {
            first = func_021B8FF4(*(void **)(p + 0xa0));
            second = func_021B9000(*(void **)(p + 0xa0));
            if (mode == 1 && second != 4) {
                if (first < second) {
                    groups[0] = func_021B9AF8(*(void **)(p + 0xa4), first);
                    counts[0] = func_021B9B94(groups[0]);
                    groups[1] = func_021B9AF8(*(void **)(p + 0xa4), second);
                    counts[1] = func_021B9B94(groups[1]);
                } else {
                    groups[0] = func_021B9AF8(*(void **)(p + 0xa4), second);
                    counts[0] = func_021B9B94(groups[0]);
                    groups[1] = func_021B9AF8(*(void **)(p + 0xa4), first);
                    counts[1] = func_021B9B94(groups[1]);
                }
            } else {
                groups[0] = *(void **)(p + 0xa8);
                counts[0] = func_021B9B94(groups[0]);
            }
            switch (mode) {
            case 0:
                slot = func_021B8ED8(*(void **)(p + 0xa0), 0);
                mon = func_021B98AC(*(void **)(p + 0xa4), slot);
                if (func_021D5B68(mon) == 0) {
                    out.ids[0] = func_021D5444(mon);
                    out.names[0] = func_02017E1C(func_021D5864(mon), 111, 0);
                    out.values[0] = func_021D59B4(mon, 18);
                }
                break;
            case 2:
                slot = func_021B8ED8(*(void **)(p + 0xa0), 6);
                mon = func_021B98AC(*(void **)(p + 0xa4), slot);
                if (func_021D5B68(mon) == 0) {
                    out.ids[2] = func_021D5444(mon);
                    out.names[2] = func_02017E1C(func_021D5864(mon), 111, 0);
                    out.values[2] = func_021D59B4(mon, 18);
                }
            case 1: case 3:
                slot = func_021B8ED8(*(void **)(p + 0xa0), 2);
                mon = func_021B98AC(*(void **)(p + 0xa4), slot);
                if (func_021D5B68(mon) == 0) {
                    out.ids[0] = func_021D5444(mon);
                    out.names[0] = func_02017E1C(func_021D5864(mon), 111, 0);
                    out.values[0] = func_021D59B4(mon, 18);
                }
                slot = func_021B8ED8(*(void **)(p + 0xa0), 4);
                mon = func_021B98AC(*(void **)(p + 0xa4), slot);
                if (func_021D5B68(mon) == 0) {
                    out.ids[1] = func_021D5444(mon);
                    out.names[1] = func_02017E1C(func_021D5864(mon), 111, 0);
                    out.values[1] = func_021D59B4(mon, 18);
                }
                break;
            default: break;
            }
        } else {
            if (func_021B86B8(*(void **)(p + 0xa0)) == 0 || func_021B86B8(*(void **)(p + 0xa0)) == 4) break;
            first = func_021B904C(*(void **)(p + 0xa0), 0);
            second = func_021B904C(*(void **)(p + 0xa0), 1);
            out.f94 = 1;
            groups[0] = func_021B9AF8(*(void **)(p + 0xa4), first);
            counts[0] = func_021B9B94(groups[0]);
            if (mode == 1 && first != second) {
                groups[1] = func_021B9AF8(*(void **)(p + 0xa4), second);
                counts[1] = func_021B9B94(groups[1]);
            }
        }
        if (groups[1] == 0) n = counts[0];
        else {
            if (counts[0] > 3) counts[0] = 3;
            if (counts[1] > 3) counts[1] = 3;
            n = counts[0] + counts[1];
        }
        for (index = 0; index < n; index++) {
            if (index < counts[0]) { side = 0; slot = index; }
            else { side = 1; slot = index - counts[0]; }
            mon = func_021B9C00(groups[side], slot);
            if (func_021D5B68(mon) == 0) {
                if (func_021D62A8(mon) != 0) out.rows[pass][side * 3 + slot].bytes[1] = 3;
                else if (func_021D5B7C(mon) == 0) out.rows[pass][side * 3 + slot].bytes[1] = 0;
                else out.rows[pass][side * 3 + slot].bytes[1] = 1;
            } else out.rows[pass][side * 3 + slot].bytes[1] = 2;
        }
    }
    out.f90 = p[0x8b];
    out.fc5 = func_021D3D84(*(void **)(p + 0x10));
    p += 0xb0;
    func_0220270C(*(void **)p, 1, &out);
    return 1;
}
