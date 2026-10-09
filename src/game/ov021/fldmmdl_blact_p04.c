/*
 * file:     fldmmdl_blact_p04.c
 * unit:     yes
 * function: func_0219CB64, func_0219CB98, func_0219CBD4, func_0219CBE0, func_0219CC80, func_0219CCF0, func_0219CD68, func_0219CDAC, func_0219CE60, func_0219CEAC, func_0219CF00, func_0219CF54, func_0219CFB0, func_0219D064, func_0219D0F4, func_0219D144, func_0219D184, func_0219D1F8, func_0219D208, func_0219D2CC, func_0219D2F4, func_0219D324, func_0219D390, func_0219D3B4, func_0219D3E4, func_0219D3F0, func_0219D448, func_0219D488, func_0219D49C, func_0219D4AC, func_0219D4EC, func_0219D524, func_0219D558, func_0219D584, func_0219D604, func_0219D634, func_0219D680, func_0219D6B8, func_0219D6CC, func_0219D724, func_0219D738, func_0219D780, func_0219D7AC, func_0219D7D0, func_0219D7F0, func_0219D824, func_0219D85C, func_0219D8DC, func_0219D930, func_0219D990, func_0219D9D8, func_0219DA20, func_0219DA80, func_0219DAA4, func_0219DAD0, func_0219DB04
 * address:  0x0219CB64
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
 *   func_0216E3C8  0x0216E3C8  thumb  ov010
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *   func_0219CB24  0x0219CB24  thumb  ov021
 *   func_0219CA98  0x0219CA98  thumb  ov021
 *   func_02050278  0x02050278  arm
 *   func_0219C52C  0x0219C52C  thumb  ov021
 *   func_0219CA6C  0x0219CA6C  thumb  ov021
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DDD70     0x021DDD70  data ov021 a4
 *   func_020307B0  0x020307B0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_0219C7B4  0x0219C7B4  thumb  ov021
 *   func_0219C780  0x0219C780  thumb  ov021
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0219C880  0x0219C880  thumb  ov021
 *   func_02050468  0x02050468  arm
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   d_021D7F68  0x021D7F68  data  ov021
 *   func_0219C4AC  0x0219C4AC  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D8064     0x021D8064  data a2
 *   d_021D75C4     0x021D75C4  data ov021 a2
 *   func_0216D524  0x0216D524  thumb  ov010
 *   d_021DDD80     0x021DDD80  data ov021 a4
 *   func_0216D528  0x0216D528  thumb  ov010
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216E3CC  0x0216E3CC  thumb  ov010
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0216D6F4  0x0216D6F4  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   d_021D80E4     0x021D80E4  data   ov021  a1
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0219E334  0x0219E334  thumb  ov021
 *   func_0216D7E0  0x0216D7E0  thumb  ov010
 *   func_0216D7D8  0x0216D7D8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_0219DB5C  0x0219DB5C  thumb  ov021
 *   func_0219DB0C  0x0219DB0C  thumb  ov021
 *   func_0219DBC8  0x0219DBC8  thumb  ov021
 *   func_0219DB44  0x0219DB44  thumb  ov021
 *   func_0219DB48  0x0219DB48  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0219DC08  0x0219DC08  thumb  ov021
 *   func_021AC760  0x021AC760  thumb  ov021
 *   func_021BBDD4  0x021BBDD4  thumb  ov021
 */
#include "../../matched/include/Obj19659.h"
#include "../../matched/include/Obj00429.h"
#include "../../matched/include/Obj02077.h"
#include "../../matched/include/Obj03116.h"
#include "../../matched/include/Obj02698.h"
#include "../../matched/include/Obj04225.h"
#include "../../matched/include/Obj06000.h"
#include "../../matched/include/Obj19662.h"
#include "../../matched/include/Obj12672.h"
#include "../../matched/include/Obj03579.h"
#include "../../matched/include/Obj04224.h"
#include "../../matched/include/Obj05011.h"
#include "../../matched/include/Obj19665.h"
#include "../../matched/include/Obj03580.h"
#include "../../matched/include/Obj12673.h"
#include "../../matched/include/Obj03117.h"
#include "../../matched/include/Obj07477.h"
#include "../../matched/include/Obj09512.h"
#include "../../matched/include/Obj12675.h"
#include "../../matched/include/Obj06001.h"
#include "../../matched/include/Obj12676.h"
#include "../../matched/include/Obj01353.h"
#include "../../matched/include/Obj03118.h"
#include "../../matched/include/Obj00808.h"
#include "../../matched/include/Obj07478.h"
#include "../../matched/include/Obj02699.h"
#include "../../matched/include/Obj03119.h"
#include "../../matched/include/Obj02700.h"
#include "../../matched/include/Obj04226.h"
#include "../../matched/include/Obj17972.h"
#include "../../matched/include/Obj06002.h"
#include "../../matched/include/Obj09515.h"
#include "../../matched/include/Obj09517.h"
#include "../../matched/include/Obj07479.h"

struct BbActSys;
struct Tagged;
struct BbActRec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 id; u8 pad[5]; u8 f7; u8 f8; } D;

typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;

typedef struct { int n; Ent *e; } Tbl;

typedef struct { u16 id; u8 pad[10]; } A;

typedef struct { u8 pad[16]; u32 f10; } B;

typedef struct { u32 f0; u8 pad[12]; u32 f10; u8 pad2[20]; } C;

typedef struct { u8 pad[4]; u16 n0; u16 n1; u16 n2; u16 pad2; A *a; B *b; C *c; } R;

typedef struct { u32 a, b, c; } E12;

typedef struct { int a; int b; int c; } S3;

typedef struct { u32 p; u16 id; u16 pad; u32 x; } Slot;

typedef struct { u16 a; u16 b; } E4;

extern void *func_0216E3C8(void *p);
extern u32 func_0216D518(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_0219CB24(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1);
extern int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern void func_0219C52C(u32 a, u32 b);
extern void func_0219CA6C(Tbl *t, u16 k);
extern u32 func_0216D4F8(u8 *p);
extern u16 func_0216D4F0(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern void func_02046EFC(struct Tagged *p);
extern u32 func_0219C7B4(u32, u32, u32);
extern u32 func_0219C780(u32, int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void func_0216D758(void *a0);
extern void func_02082BCC(u8 *p, u32 a, u32 b);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern u16 func_0216D598(void *p);
extern void func_0216E204(char *a, u32 v);
extern void func_0219C880(u8 *o, u32 a, u32 b, u32 c);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern int func_0216DA30(int a0, int a1);
extern int func_0219C4AC(u32 a, u32 b, u32 c, u32 d);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_0216D524(void *p, void *v);
extern u32 func_0216D528(u8 *p);
extern void func_021C6580(u8 *p, int i);
extern void func_021C6AE0(u32 a);
extern void func_021C6AF0(u32 *, u32, u16);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *, u16);
extern u32 func_021C6574(u32, u32 *, u32);
extern void *func_0216E3C4(void *p);
extern u8 *func_0216E3CC(u8 *p);
extern u32 func_021C6590(u32, u32, u32, u32);
extern void func_021C6628(u32, u32);
extern int func_0216DFC4(void *a, u32 id);
extern u32 *func_0216D548(u32 *p, u32 v);
extern void func_0216D6F4(void *a0);
extern int func_0216DA20(void *p, unsigned int v);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_02197EB4(u32);
extern int func_0216DB10(void *a0);
extern void func_0216D708(void *a0);
extern u32 func_0216D530(u32);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern u16 func_0216D5F8(void *p);
extern u32 func_0219E784(u32, u32, s16 *);
extern void func_0207CDB8(s16 *, s16 *);
extern int func_0207CFB8(int, int);
extern int func_0216DA5C(void *a0);
extern u16 func_0216D5A0(void *p);
extern void func_0216DA70(void *a0);
extern char *func_0216D570(char *p, u32 v);
extern int func_0216DCB4(void *a0);
extern void func_0219E2F4(void *o, void *out);
extern int func_0219E334(u32 a, u32 b);
extern void func_0216D7E0(void *p, u32 v);
extern void func_0216D7D8(void *p, u32 v);
extern void *func_0216D568(void *p, u32 v);
extern int func_0216DB24(int a0);
extern u32 func_0216D7DC(void *p);
extern u32 func_0216D7E4(void *p);
extern void func_0219DB5C(void *a, u32 b, u32 c, u8 *d);
extern u32 func_0219DB0C(u32, u32, u32, u32);
extern void func_0219DBC8(void *a, u32 b, u32 c, u8 *d);
extern void func_0219DB44(u32, u32, u32, u32);
extern int func_0219DB48(u32 a, u32 b, u32 c, u32 d);
extern u16 func_021AB0F8(u32 attr);
extern int func_0219DC08(u32 a);
extern void func_021AC760(u32 a, u32 b, u32 c, int d);
extern void func_021BBDD4(int a, int b, int c);
void func_0219CB64(u8 *s, const D *d, u32 g);
void func_0219CB98(u8 *s, u16 k);
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
void func_0219CBE0(u8 *o);
void func_0219CC80(u8 *o);
int func_0219CCF0(u8 *s);
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e);
void func_0219CDAC(u8 *o);
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w);
void func_0219CEAC(int *obj);
int func_0219CF00(int *t, unsigned int id, unsigned short *out);
int func_0219CF54(int *t, unsigned int id);
void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7);
void func_0219D064(int *obj, int *rec);
void func_0219D0F4(int *obj);
int func_0219D144(int *obj, unsigned int a, int b);
void func_0219D184(int *obj, int key);
void func_0219D1F8(u8 *p);
void func_0219D208(int a, unsigned int id);
void func_0219D2CC(int *obj);
void func_0219D2F4(u8 *s);
void func_0219D324(int *obj, int *rec);
void func_0219D390(u8 *s);
int func_0219D3B4(u8 *s, u32 p, u16 id);
char *func_0219D3E4(int i);
unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
void func_0219D448(int a, int b);
void func_0219D488(u32 a);
u32 func_0219D49C(u32 a);
void func_0219D4AC(int *obj, int a);
void func_0219D4EC(u8 *s);
u16 func_0219D524(u32 *s, u32 b, u32 a);
u16 func_0219D558(u8 *s, u16 k);
u32 func_0219D584(u32 a, u32 *b, u32 c, u16 *d);
void func_0219D604(u8 *s, u16 k);
u32 func_0219D634(u32 a);
void func_0219D680(u32 a, u32 b);
int func_0219D6B8(u32 *a, u32 b, u32 c, u32 d);
void func_0219D6CC(u32 a);
int func_0219D724(u32 a, char *b);
u32 func_0219D738(u32 a, int b);
int func_0219D780(u32 a);
void func_0219D7AC(u32 a);
void func_0219D7D0(u32 a);
void func_0219D7F0(u32 a);
void func_0219D824(u32 a);
u32 func_0219D85C(u32 a);
void func_0219D8DC(void *a);
void func_0219D930(void *a);
void func_0219D990(void *a);
void func_0219D9D8(void *a);
void func_0219DA20(void *a);
void func_0219DA80(u32 a, u32 b, u32 a2, u32 a3);
void func_0219DAA4(u32 a, u32 b, u32 a2, u32 a3);
void func_0219DAD0(u32 a, u32 x, u32 b, u8 *p);
int func_0219DB04(u32 a, u32 b, u32 c, u32 d);
extern unsigned char d_021DDD70[];
extern char d_021D7F68[];
extern unsigned short d_021D8064[];
extern unsigned short d_021D75C4[];
extern unsigned char d_021DDD80[];
extern u8 d_021D80E4[];










void func_0219CB64(u8 *s, const D *d, u32 g)
{
    u16 *q = func_0216E3C8((void *)d);
    func_0219CB24(s, (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj19659 *)s)->f10)), *q), d->id, d->f7, d->f8, g);
}










void func_0219CB98(u8 *s, u16 k)
{
    u16 t[2];
    func_0219CA98((u32 *)(s + 0x14), k, &t[0], &t[1]);
    if (t[1] & 2) {
        func_02050278((struct BbActSys *)(((struct Obj00429 *)s)->f4), t[0], 1);
    } else {
        func_0219C52C(((struct Obj00429 *)s)->f4, t[0]);
    }
    func_0219CA6C((Tbl *)(s + 0x14), k);
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d)
{
return func_0219CA98((u32 *)(a + 20), b, (u16 *)c, (u16 *)d);
}










/*
 * Addresses are Black-image addresses.
 */
void func_0219CBE0(u8 *o)
{
    u32 h = func_0216D4F8((u8 *)(((struct Obj03116 *)o)->f10));
    u8 *p = func_02030734(h, 0x18, 1, (const char *)d_021DDD70, 1491);
    u16 *e;
    int i;
    ((struct Obj02077 *)p)->f4 = ((struct Obj03116 *)o)->f2;
    ((struct Obj02077 *)p)->f8 = func_0216D4F0((void *)(((struct Obj03116 *)o)->f10));
    ((struct Obj02077 *)p)->f6 = 1;
    e = (u16 *)func_02030734(h, 0xc * ((struct Obj02077 *)p)->f4, 1, (const char *)d_021DDD70, 1498);
    *(u16 * *)&((struct Obj02077 *)p)->fC = e;
    i = 0;
    if (i < ((struct Obj02077 *)p)->f4) {
        for (; i < ((struct Obj02077 *)p)->f4; i++, e += 6)
            *e = 0xFFFF;
    }
    ((struct Obj02077 *)p)->f10 = (u32)func_02030734(h, 0x14 * ((struct Obj02077 *)p)->f6, 1, (const char *)d_021DDD70, 1511);
    ((struct Obj02077 *)p)->f14 = (u32)func_02030734(h, 0x28 * ((struct Obj02077 *)p)->f8, 1, (const char *)d_021DDD70, 1513);
    ((struct Obj02077 *)p)->f0 = 1;
    *(u8 * *)&((struct Obj03116 *)o)->f1C = p;
}










void func_0219CC80(u8 *o)
{
    u8 *c = *(u8 * *)&((struct Obj04225 *)o)->f1C;
    u32 i;
    u32 n;
    u8 *p;
    if (c == 0) return;
    i = 0;
    ((struct Obj02698 *)c)->f0 = i;
    func_020307B0((void *)(((struct Obj02698 *)c)->fC));
    p = *(u8 * *)&((struct Obj02698 *)c)->f10;
    if (i < ((struct Obj02698 *)c)->f6) {
        for (; i < ((struct Obj02698 *)c)->f6; i++, p += 0x14) {
            if (((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f10));
    i = 0;
    p = *(u8 * *)&((struct Obj02698 *)c)->f14;
    if (i < ((struct Obj02698 *)c)->f8) {
        for (; i < ((struct Obj02698 *)c)->f8; i++, p += 0x28) {
            if (((struct Obj06000 *)p)->f0 != 0 && ((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f14));
    func_020307B0((void *)((u32)c));
    *(u32 *)&((struct Obj04225 *)o)->f1C = 0;
}










/*
 * The record pointers are const: mwcc then rereads each u16 count inside its
 * loop and keeps r in r0 instead of hoisting the count into a register.
 */
int func_0219CCF0(u8 *s)
{
    const R *r = *(const R * *)&((struct Obj19662 *)s)->f1C;
    u32 i;
    const A *a;
    const B *b;
    const C *c;

    a = r->a;
    for (i = 0; i < r->n0; i++, a++) {
        if (a->id != 0xFFFF) {
            return 1;
        }
    }
    b = r->b;
    for (i = 0; i < r->n1; i++, b++) {
        if (b->f10 != 0) {
            return 1;
        }
    }
    c = r->c;
    for (i = 0; i < r->n2; i++, c++) {
        if (c->f0 != 0 && c->f10 != 0) {
            return 1;
        }
    }
    return 0;
}










/*
 * Fills the first free 0xC-byte entry (tag 0xFFFF... see pool) of the table.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e)
{
    u8 *ctx = *(u8 * *)&((struct Obj00429 *)o)->f1C;
    u32 i;
    u32 n = ((struct Obj12672 *)ctx)->f4;
    o = *(u8 * *)&((struct Obj12672 *)ctx)->fC;
    for (i = 0; i < n; i++, o += 0xc) {
        if (((struct Obj00429 *)o)->f0 == 0xFFFF) {
            ((struct Obj00429 *)o)->f0 = a;
            *(u8 *)&((struct Obj00429 *)o)->f4 = b;
            *(u8 *)(o + 5) = c;
            ((struct Obj00429 *)o)->f2 = d;
            ((struct Obj00429 *)o)->f8 = e;
            return;
        }
    }
}










/*
 * Commits pending 0xC-byte entries through func_0219CE60, then compacts the
 * table so the free (0xFFFF) entries sit at the end.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CDAC(u8 *o)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u32 j = 0;
    u32 k = 0;
    u8 *e = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
    u8 *base;
    for (; j < ((struct Obj05011 *)ctx)->f4; j++, e += 0xc) {
        if (((struct Obj04224 *)e)->f0 != 0xFFFF) {
            if (func_0219CE60(o, ((struct Obj04224 *)e)->f0, e[4], e[5], ((struct Obj04224 *)e)->f2, ((struct Obj04224 *)e)->f8) == 0)
                break;
            ((struct Obj04224 *)e)->f0 = 0xFFFF;
            k++;
            if (k >= ((struct Obj05011 *)ctx)->f6)
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
        for (; j < (u32)((struct Obj05011 *)ctx)->f4 - 1; j++) {
            E12 *ent = (E12 *)(base + 12 * j);
            if (((struct Obj19665 *)ent)->f0 == 0xFFFF) {
                for (k = j + 1; k < ((struct Obj05011 *)ctx)->f4; k++) {
                    if (*(u16 *)(base + 12 * k) != 0xFFFF) {
                        *ent = *(E12 *)(base + 12 * k);
                        *(u16 *)(base + 12 * k) = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}










/*
 * Claims the first free 0x14-byte slot of the table at *(*(+0x1c)+0x10).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u8 *p = *(u8 * *)&((struct Obj12673 *)ctx)->f10;
    u32 i;
    for (i = 0; i < ((struct Obj12673 *)ctx)->f6; i++, p += 0x14) {
        if (((struct Obj03580 *)p)->f10 == 0) {
            ((struct Obj03580 *)p)->f0 = 0;
            ((struct Obj03580 *)p)->f8 = a;
            ((struct Obj03580 *)p)->fA = b;
            ((struct Obj03580 *)p)->fB = c;
            ((struct Obj03580 *)p)->f4 = w;
            ((struct Obj03580 *)p)->f10 = (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj03579 *)o)->f10)), e);
            ((struct Obj03580 *)p)->f0 = 1;
            return 1;
        }
    }
    return 0;
}










void func_0219CEAC(int *obj)
{
    unsigned int i;
    int *p;
    int *t;

    t = (int *)obj[7];
    if (t != 0 && t[0] == 1) {
        i = 0;
        p = (int *)t[4];
        if (!(i < ((struct Obj07477 *)t)->f6)) {
            return;
        }
        for (; i < ((struct Obj07477 *)t)->f6; i++, p += 5) {
            if (p[4] != 0 && ((struct Obj03117 *)p)->f0 == 1) {
                ((struct Obj03117 *)p)->f0 = 0;
                func_0219CB24((u8 *)obj, p[4], ((struct Obj03117 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), p[1]);
                p[4] = 0;
            }
        }
    }
}










int func_0219CF00(int *t, unsigned int id, unsigned short *out)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12675 *)p)->f0 == id) {
            *out = ((struct Obj12675 *)p)->f8;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (((struct Obj09512 *)q)->f8 == id && ((struct Obj09512 *)q)->f10 != 0) {
            *out = ((struct Obj09512 *)q)->f4;
            return 1;
        }
    }
    return 0;
}










int func_0219CF54(int *t, unsigned int id)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12676 *)p)->f0 == id) {
            ((struct Obj12676 *)p)->f0 = 0xFFFF;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (*(int *)&((struct Obj06001 *)q)->f10 != 0 && ((struct Obj06001 *)q)->f8 == id) {
            *q = 0;
            func_02046EFC(((struct Obj06001 *)q)->f10);
            *(int *)&((struct Obj06001 *)q)->f10 = 0;
            return 1;
        }
    }
    return 0;
}










void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short v[2];
    unsigned short *t;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] == 0) {
            *((unsigned char *)p + 0xd) = 0;
            p[1] = a1;
            p[0] = a3;
            ((struct Obj01353 *)p)->f8 = ((struct Obj03118 *)src)->f0;
            *((unsigned char *)p + 0xa) = src[7];
            *((unsigned char *)p + 0xb) = src[8];
            *((unsigned char *)p + 0xc) = src[9];
            func_0219CBD4((u32)obj, ((struct Obj01353 *)p)->f8, (u32)(&v[1]), (u32)(&v[0]));
            if (v[1] == 0xFFFF && func_0219CF00(obj, ((struct Obj01353 *)p)->f8, &v[0]) == 0) {
                t = func_0216E3C8(src);
                v[0] = 1;
                func_0219CD68((u8 *)obj, ((struct Obj01353 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), *t, 1);
            }
            p[5] = a5;
            p[6] = a6;
            if (a7 != 0) {
                *(S3 *)(p + 7) = *a7;
            }
            *((unsigned char *)p + 0xd) = 1;
            return;
        }
    }
}










void func_0219D064(int *obj, int *rec)
{
    unsigned short x[3];
    u32 r;

    x[0] = 0xFFFF;
    *((unsigned char *)rec + 0xd) = 0;
    if (rec[4] != 0) {
        x[2] = func_0219D3F0(obj, ((struct Obj00808 *)rec)->f8, *((unsigned char *)rec + 0xa),
                             *((unsigned char *)rec + 0xb), rec[4], 1);
        rec[4] = 0;
        func_0219CBD4((u32)obj, ((struct Obj00808 *)rec)->f8, (u32)(&x[0]), (u32)(&x[1]));
    } else {
        func_0219CBD4((u32)obj, ((struct Obj00808 *)rec)->f8, (u32)(&x[2]), (u32)(&x[1]));
    }
    if (rec[1] != 0) {
        r = func_0219C7B4(rec[1], x[2], x[0]);
    } else {
        r = func_0219C780(obj[4], (int)(rec + 7), *((unsigned char *)rec + 0xa),
                          *((unsigned char *)rec + 0xc), x[2], x[0]);
    }
    *(unsigned short *)rec[0] = r;
    if (rec[5] != 0) {
        ((void (*)(unsigned int, int))rec[5])(*(unsigned short *)rec[0], rec[6]);
    }
    if (rec[1] != 0) {
        func_0216D758((void *)rec[1]);
    }
}










void func_0219D0F4(int *obj)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short sp[2];

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    if (n == 0) {
        return;
    }
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && *((unsigned char *)p + 0xd) == 1) {
            if (func_0219CBD4((u32)obj, ((struct Obj00808 *)p)->f8, (u32)(&sp[0]), (u32)(&sp[1])) == 1) {
                func_0219D064(obj, p);
                func_0219D1F8((u8 *)p);
            }
        }
    }
}










int func_0219D144(int *obj, unsigned int a, int b)
{
    unsigned int i;
    unsigned int n;
    int *p;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] != 0 && p[1] != b && ((struct Obj07478 *)p)->f8 == a) {
            return 1;
        }
    }
    return 0;
}










void func_0219D184(int *obj, int key)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short s;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] == key) {
            *((unsigned char *)p + 0xd) = 0;
            if (func_0219CF00(obj, ((struct Obj02699 *)p)->f8, &s) == 1 && (s & 1)) {
                if (func_0219D144(obj, ((struct Obj02699 *)p)->f8, p[1]) == 0) {
                    func_0219CF54(obj, ((struct Obj02699 *)p)->f8);
                }
            }
            if (p[4] != 0) {
                func_02046EFC((void *)p[4]);
                p[4] = 0;
            }
            func_0219D1F8((u8 *)p);
            return;
        }
    }
}










/*
 * Clears the byte at +0xd, then tail calls with 0 and 0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_0219D1F8(u8 *p)
{
    *((u8 *)p + 0xd) = 0;
    func_02082BCC(p, 0, 0x28);
}










void func_0219D208(int a, unsigned int id)
{
    int *ctx;
    int i;
    unsigned char *r;
    unsigned short h;
    unsigned short v[2];

    ctx = (int *)func_0216D520(func_0216D67C((void *)a));
    r = (unsigned char *)ctx[8];
    func_0219CBD4((u32)ctx, id, (u32)(&v[1]), (u32)(&v[0]));
    if (v[1] != 0xFFFF && !(v[0] & 2)) {
        func_0216E204((char *)a, id);
        return;
    }
    i = 0;
    h = func_0216D7A8((void *)a, 0);
    if (h == 0xFFFF) {
        func_0216E204((char *)a, id);
        return;
    }
    for (; i < 4; i++) {
        if (((struct Obj03119 *)r)->f0 == 0) {
            break;
        }
    }
    if (i >= 4) {
        func_0216E204((char *)a, id);
        return;
    }
    ((struct Obj03119 *)r)->f0 = a;
    ((struct Obj03119 *)r)->f4 = h;
    ((struct Obj03119 *)r)->f6 = func_0216D598((void *)a);
    ((struct Obj03119 *)r)->f8 = id;
    func_0216E204((char *)a, id);
    i = 0;
    if (func_0216D7A8((void *)a, 0) != 0xFFFF) {
        func_0219C880((u8 *)ctx, a, ((struct Obj03119 *)r)->f4, ((struct Obj03119 *)r)->f6);
        func_02050468((struct BbActSys *)ctx[1], ((struct Obj03119 *)r)->f4, 1);
        ((struct Obj03119 *)r)->f0 = i;
    }
}









/*
 * Promoted 2026-09-27 (lane ov010 blocker tree).  The call at +0x08 is a
 * Thumb `bl` (d0 f7 10 f9), not an interworking `blx`: the target must be
 * Thumb.  The old header called 0x0216D4F8 `arm ov009`, but ov009's byte
 * there is an ARM fragment with no start, while ov010 holds an EXACT Thumb
 * getter (src/matched/func_0216D4F8.c, shard layout/matched/ov010/
 * pkt_0216D4F8.json).  With the region/ISA hint fixed to `thumb ov010` the
 * site resolves as `matched` and the entry is EXACT.
 */
void func_0219D2CC(int *obj)
{
    ((struct Obj03116 *)obj)->f20 =
        (int)func_02030734(func_0216D4F8((u8 *)obj[4]), 0x30, 1, (const char *)d_021DDD70, 0x979);
}









void func_0219D2F4(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj04225 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_02050468((struct BbActSys *)(((struct Obj04225 *)s)->f4), e->id, 1);
                e->p = 0;
            }
        }
        func_020307B0(((struct Obj04225 *)s)->f20);
    }
}









void func_0219D324(int *obj, int *rec)
{
    int h;
    unsigned int n;

    h = rec[0];
    if (func_0216DA30(h, (int)rec) == 0) {
        func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, *((unsigned short *)(rec + 1) + 1));
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
        return;
    }
    if ((unsigned short)func_0216D7A8((void *)h, 0) != 0xFFFF) {
        n = *((unsigned short *)(rec + 1) + 1);
        if (n != func_0216D598((void *)h)) {
            func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, n);
        }
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
    }
}









void func_0219D390(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj03579 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_0219D324((int *)s, (int *)e);
            }
        }
    }
}









int func_0219D3B4(u8 *s, u32 p, u16 id)
{
    Slot *e = *(Slot * *)&((struct Obj00429 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0 && e->p == p && e->id == id) {
                return 1;
            }
        }
    }
    return 0;
}









/*
 * Indexes an array of 8-byte records based at 0x021D7F68.
 */
char *func_0219D3E4(int i)
{
    return d_021D7F68 + i * 8;
}









unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5)
{
    unsigned short *q;
    struct {
        int w0;
        unsigned char b4;
        unsigned char b5;
        unsigned char b6;
        unsigned char b7;
        int w2;
    } s;

    if (a5 == -1) {
        return (unsigned short)func_0219C4AC(o[1], a4, a2, a3);
    }
    s.w0 = a4;
    s.b4 = 0;
    s.b5 = d_021D8064[a3];
    q = d_021D75C4 + a2 * 2;
    s.b6 = q[0];
    s.b7 = q[1];
    s.w2 = a5;
    return func_020500F0((struct BbActSys *)o[1], (const struct BbActRec *)(&s), 1);
}







void func_0219D448(int a, int b)
{
    int h;
    int *p;

    h = func_0216D4F8((u8 *)a);
    p = (int *)func_02030734(h, 0x10, 1, (const char *)d_021DDD80, 0x48);
    p[0] = a;
    p[1] = b;
    ((struct Obj04226 *)p)->f8 = func_0216D4F0((void *)a);
    func_0219D4AC(p, h);
    func_0216D524((void *)a, p);
}






void func_0219D488(u32 a)
{
    void *s = (void *)func_0216D528((u8 *)a);
    func_0219D4EC(s);
    func_020307B0(s);
}






/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D528 (0x0216D528) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219D49C(u32 a)
{
return ((struct Obj17972 *)((u8 *)(func_0216D528((u8 *)((u32)func_0216D67C((void *)a))))))->f4;
}







/*
 * Allocates n*4 bytes (n = *(u16 *)(obj+8)), stores the pointer at obj+0xc,
 * then writes 0xFFFF into the high halfword of each 4-byte entry.
 */
void func_0219D4AC(int *obj, int a)
{
    int i;
    *(int *)&((struct Obj04226 *)obj)->fC =
        (int)(unsigned short *)func_02030734(a, ((struct Obj04226 *)obj)->f8 * 4,
                                             1, (const char *)d_021DDD80, 0x7f);
    for (i = 0; i < (int)((struct Obj04226 *)obj)->f8; i++) {
        unsigned short *p = *(unsigned short * *)&((struct Obj04226 *)obj)->fC;
        p[i * 2 + 1] = 0xFFFF;
    }
}







void func_0219D4EC(u8 *s)
{
    int i = 0;
    E4 *e = *(E4 * *)&((struct Obj06002 *)s)->fC;
    if (i < ((struct Obj06002 *)s)->f8) {
        for (; i < ((struct Obj06002 *)s)->f8; i++, e++) {
            if (e->b != 0xFFFF) {
                func_021C6580((u8 *)(((struct Obj06002 *)s)->f4), e->a);
            }
        }
    }
    func_020307B0(((struct Obj06002 *)s)->fC);
}







u16 func_0219D524(u32 *s, u32 b, u32 a)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09515 *)s)->fC;
    int n = ((struct Obj09515 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == 0xFFFF) {
            e->b = b;
            e->a = a;
            return i;
        }
    }
    return 0;
}







u16 func_0219D558(u8 *s, u16 k)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09517 *)s)->fC;
    int n = ((struct Obj09517 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            return e->a;
        }
    }
    return 0xFFFF;
}





/*
 * Addresses are Black-image addresses.
 */
u32 func_0219D584(u32 a, u32 *b, u32 c, u16 *d)
{
    u32 buf[9];
    u32 t;
    u32 r;
    int i;
    t = func_0216D518((u8 *)a);
    func_021C6AE0((u32)buf);
    if (d[0] != 0xFFFF) {
        func_021C6AF0(buf, t, d[0]);
    }
    if (d[1] != 0xFFFF) {
        func_021C6AF0(buf, t, d[1]);
    }
    func_021C6AF8((u32 *)buf, t);
    for (i = 0; i < 3; i++) {
        if (d[i + 2] != 0xFFFF) {
            func_021C6AFC(buf, d[i + 2]);
        }
    }
    r = func_021C6574(b[1], buf, 0);
    func_0219D524(b, c, r);
    return r;
}





void func_0219D604(u8 *s, u16 k)
{
    int i;
    int n = ((struct Obj07479 *)s)->f8;
    E4 *e = *(E4 * *)&((struct Obj07479 *)s)->fC;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            func_021C6580((u8 *)(((struct Obj07479 *)s)->f4), e->a);
            e->b = 0xFFFF;
            return;
        }
    }
}





u32 func_0219D634(u32 a)
{
    u16 *p;
    u32 b;
    u32 *s;
    u32 r;
    p = func_0216E3C4((void *)a);
    b = (u32)func_0216D67C((void *)a);
    s = (u32 *)func_0216D528((u8 *)b);
    r = func_0219D558((u8 *)s, *p);
    if (r == 0xFFFF) {
        r = func_0219D584(b, s, *p, (u16 *)func_0216E3CC((u8 *)p));
    }
    return func_021C6590(s[1], r, 0, 0);
}





void func_0219D680(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0216D528(func_0216D67C((void *)a));
    u16 v = func_0216D598((void *)a);
    func_021C6628(((struct Obj07479 *)s)->f4, b);
    if (func_0216DFC4((void *)a, v) == 0) {
        func_0219D604(s, v);
    }
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219D6B8(u32 *a, u32 b, u32 c, u32 d)
{
func_0216D6F4((void *)a);
return (int)func_0216D548(a, 2);
}





void func_0219D6CC(u32 a)
{
    u32 k = 2;
    if (func_0216DA20((void *)a, 2) == 0) {
        func_0219D7AC(a);
        func_0219D7D0(a);
        if (func_0216D57C((void *)a, k << 8) != 0) {
            func_02197EB4(a);
        } else if (func_0216DB10((void *)a) == 0 && func_0219D780(a) == 1) {
            func_0216D708((void *)a);
        }
        func_0219D7F0(a);
        func_0219D824(a);
    }
}





/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D530 (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219D724(u32 a, char *b)
{
return func_021BB3C4((u8 *)func_0216D530((u32)func_0216D67C((void *)a)), b);
}





u32 func_0219D738(u32 a, int b)
{
    s16 v[4];
    int r;
    func_0219E784(a, func_0216D5F8((void *)a), v);
    v[1] = 0;
    func_0207CDB8(v, v);
    r = func_0207CFB8(v[0], v[2]) - b;
    if (r < 0) {
        r += 0x10000;
    }
    return d_021D80E4[r >> 12];
}





int func_0219D780(u32 a)
{
    if (func_0216DA5C((void *)a) == 1) {
        return 1;
    }
    if (func_0216D57C((void *)a, 0x800) == 0) {
        return 1;
    }
    func_0216D5A0((void *)a);
    return 1;
}





void func_0219D7AC(u32 a)
{
    if (func_0216D57C((void *)a, 0x800) != 0 && func_0219D85C(a) == 1) {
        func_0216DA70((void *)a);
    }
}





void func_0219D7D0(u32 a)
{
    if (func_0216D57C((void *)a, 0x20) != 0) {
        func_0219D8DC((void *)a);
    }
    func_0216D570((char *)a, 0xA0);
}





void func_0219D7F0(u32 a)
{
    if (func_0216D57C((void *)a, 0x80) != 0) {
        func_0219D990((void *)a);
    } else if (func_0216D57C((void *)a, 0x20) != 0) {
        func_0219D930((void *)a);
    }
    func_0216D570((char *)a, 0xA0);
}





void func_0219D824(u32 a)
{
    if (func_0216D57C((void *)a, 0x100) != 0) {
        func_0219DA20((void *)a);
    } else if (func_0216D57C((void *)a, 0x40) != 0) {
        func_0219D9D8((void *)a);
    }
    func_0216D570((char *)a, 0x140);
}





/*
 * Addresses are Black-image addresses.
 */
u32 func_0219D85C(u32 a)
{
    u32 v1[2];
    u32 v0[2];
    u32 r6 = -1;
    u32 r5 = -1;
    u32 t;
    if (func_0216DCB4((void *)a) == 0) {
        t = (u32)(void *)func_0216D530((u32)(func_0216D67C((void *)a)));
        func_0219E2F4((void *)a, v0);
        func_0219E334(a, (u32)v1);
        r6 = func_021BB3C4((u8 *)t, (char *)v1);
        r5 = func_021BB3C4((u8 *)t, (char *)v0);
    }
    func_0216D7E0((void *)a, r6);
    func_0216D7D8((void *)a, r5);
    if (r5 == -1) {
        func_0216D568((void *)a, 0x800);
        return 0;
    }
    func_0216D570((char *)a, 0x800);
    return 1;
}





void func_0219D8DC(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DA80((u32)a, b, c, d);
        func_0219DB04((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}





void func_0219D930(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DAA4((u32)a, b, c, d);
        func_0219DAD0((u32)a, b, c, (u8 *)d);
        func_0219DB0C((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}





void func_0219D990(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DB0C((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}





void func_0219D9D8(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DBC8(a, b, c, (u8 *)d);
        func_0219DB44((u32)a, b, c, d);
    }
}





void func_0219DA20(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DBC8(a, b, c, (u8 *)d);
        func_0219DB44((u32)a, b, c, d);
        func_0219DAA4((u32)a, b, c, d);
        func_0219DB48((u32)a, b, c, d);
    }
}





void func_0219DA80(u32 a, u32 b, u32 a2, u32 a3)
{
    if (func_021AB0F8(b) & 0x20)
        func_021AC760(func_0219DC08(a), a, 0, 0);
}





void func_0219DAA4(u32 a, u32 b, u32 a2, u32 a3)
{
    if (b != 0xFFFFFFFF && (func_021AB0F8(b) & 0x20))
        func_021AC760(func_0219DC08(a), a, 1, 0);
}





void func_0219DAD0(u32 a, u32 x, u32 b, u8 *p)
{
    u32 h;
    int f;
    if (b != 0xFFFFFFFF && (func_021AB0F8(b) & 8)) {
        h = func_0219DC08(a);
        f = 0;
        if (p[5] == 2)
            f = 1;
        func_021BBDD4(a, h, f);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DB04(u32 a, u32 b, u32 c, u32 d)
{
return func_0219DB0C(a, b, c, d);
}
