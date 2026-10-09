/*
 * file:     union_comm_p07.c
 * unit:     yes
 * function: func_02173518, func_02173524, func_0217357C, func_021735FC, func_02173614, func_02173650, func_0217365C, func_021736A0, func_021736C8, func_021736E0, func_02173744, func_021737A4, func_02173840, func_02173874, func_021738D4, func_0217391C, func_02173928, func_02173934, func_02173940, func_0217394C, func_02173984, func_021739A8, func_021739CC, func_021739E0, func_02173A04, func_02173A24, func_02173A48, func_02173A68, func_02173A90, func_02173AC4, func_02173AFC, func_02173B1C, func_02173B4C, func_02173B78, func_02173BB0, func_02173BFC, func_02173C64, func_02173C8C, func_02173CB4, func_02173CCC, func_02173D38, func_02173D7C, func_02173D88, func_02173DBC, func_02173DE4, func_02173E1C, func_02173E40, func_02173E68, func_02173E90, func_02173EC8, func_02173EEC, func_02173F20, func_02173F54, func_02173F90, func_02173FE0, func_02174010, func_0217403C, func_02174084, func_021740D4, func_0217410C, func_0217413C, func_0217416C
 * address:  0x02173518
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   memcmp        0x0203EFC8  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_0203D5AC  0x0203D5AC  arm
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02012944  0x02012944  thumb
 *   func_020263D8  0x020263D8  thumb
 *   func_021653C4  0x021653C4  thumb  ov010
 *   d_02175610     0x02175610  data   ov012  a1
 *   d_02175614     0x02175614  data   ov012  a1
 *   func_02026474  0x02026474  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0201212C  0x0201212C  thumb
 *   func_020123C4  0x020123C4  thumb
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0217B840  0x0217B840  thumb  ov019
 *   func_0217B75C  0x0217B75C  thumb  ov019
 *   func_0217B264  0x0217B264  thumb  ov019
 *   func_02012114 0x02012114 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188BE8 0x02188BE8 thumb ov021
 *   func_021A2E44  0x021A2E44  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013CC8  0x02013CC8  thumb
 *   func_0217B440  0x0217B440  thumb  ov019
 *   func_021676E4  0x021676E4  thumb  ov010
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_02167688  0x02167688  thumb  ov010
 *   d_02175624 0x02175624 data a1
 *   func_02172EDC 0x02172EDC thumb ov012
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02012950 0x02012950 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02008468 0x02008468 thumb
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021CD624  0x021CD624  thumb  ov021
 *   func_02183BE8  0x02183BE8  thumb  ov022
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02183F6C  0x02183F6C  thumb ov022
 *   func_02183F7C  0x02183F7C  thumb ov022
 *   func_02183F88  0x02183F88  thumb ov022
 *   func_02183F98  0x02183F98  thumb ov022
 *   func_021840A8 0x021840A8 thumb ov022
 *   func_02183FB8 0x02183FB8 thumb ov022
 *   func_02183FA8 0x02183FA8 thumb ov022
 *   func_02184060  0x02184060  thumb  ov022
 *   func_021840A4 0x021840A4 thumb ov022
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02012374  0x02012374  thumb
 *   d_0217549C     0x0217549C  data   ov012  a1
 *   d_02175498     0x02175498  data   ov012  a4
 *   d_0217549D     0x0217549D  data   ov012  a1
 */
#include "../../matched/include/Obj19230.h"
#include "../../matched/include/Obj09359.h"
#include "../../matched/include/Obj04170.h"
#include "../../matched/include/Obj09360.h"
#include "../../matched/include/Obj00610.h"
#include "../../matched/include/Obj19233.h"
#include "../../matched/include/Obj19234.h"
#include "../../matched/include/Obj09361.h"
#include "../../matched/include/Obj19235.h"
#include "../../matched/include/Obj19236.h"
#include "../../matched/include/Obj07338.h"
#include "../../matched/include/Obj19237.h"
#include "../../matched/include/Obj19238.h"
#include "../../matched/include/Obj07339.h"
#include "../../matched/include/Obj12444.h"
#include "../../matched/include/Obj19239.h"
#include "../../matched/include/Obj19240.h"
#include "../../matched/include/Obj19241.h"
#include "../../matched/include/Obj12445.h"
#include "../../matched/include/Obj19250.h"
#include "../../matched/include/Obj19251.h"
#include "../../matched/include/Obj19252.h"
#include "../../matched/include/Obj19253.h"
#include "../../matched/include/Obj12446.h"
#include "../../matched/include/Obj12447.h"
#include "../../matched/include/Obj19256.h"
#include "../../matched/include/Obj19258.h"
#include "../../matched/include/Obj19260.h"
#include "../../matched/include/Obj05918.h"
#include "../../matched/include/Obj12448.h"
#include "../../matched/include/Obj19262.h"
#include "../../matched/include/Obj19264.h"
#include "../../matched/include/Obj19265.h"
#include "../../matched/include/Obj19266.h"
#include "../../matched/include/Obj19267.h"
#include "../../matched/include/Obj09364.h"
#include "../../matched/include/Obj12449.h"
#include "../../matched/include/Obj09365.h"
#include "../../matched/include/Obj12450.h"
#include "../../matched/include/Obj19269.h"

struct Sub0200852CObj;
struct Ctx;
struct Comm;
struct Work_0;
struct Entry;
struct Link;
struct Sub24;
struct Rec44;
struct Desc;
struct Obj;
struct Evt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 mac[6];
    u8 f6;
    u8 b0 : 1;
    u8 b1 : 1;
} Rec;

typedef struct {
    struct { void *f0; } *head;
} Work_0;

typedef struct Entry { u8 mac[6]; u8 low6 : 4; u8 f6 : 4; u8 lo : 3; u8 used : 1; u8 hi : 4; u8 body[0x5c]; u8 mac2[6]; } Entry;

typedef struct { u8 pad[0xc8]; u8 f : 1; } S_02173874;

typedef struct { u8 pad[0xc8]; u8 f : 1; u8 pad2[0]; } S0;

typedef struct { u8 pad[0xc8]; u8 f; u8 g; } S_021738D4;

typedef struct { u8 pad0[0x282A]; u8 a; u8 pad1[0x355C-0x282B]; S_021738D4 *b; } T;

typedef struct { u8 pad[6]; u8 flag; u8 tail; } Packet;

typedef struct { u8 pad[0x5a]; u8 low:2; u8 mode:2; u8 high:4; } Sub_02173AC4;

typedef struct { u8 pad[0x5d]; u8 flag; } Sub_02173B78;

typedef struct { u8 pad[0x2830]; Sub_02173B78 sub; } Work_1;

typedef struct { int w[8]; } B32;

typedef struct { B32 a; unsigned char t[8]; } Msg;

typedef struct { int f0; int f4; u8 *f8; } Work;

typedef struct { int f0; int f4; int f8; u8 fc; } R;

typedef int (*Fn)(int, u8 *, int, int, int, int *, u8 *);

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_02087C6C(void *p);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int memcmp(const void *a, const void *b, int n);
extern void MI_CpuCopy8(const void *src, void *dst, int n);
extern void func_0203D5AC(int a, int b);
extern unsigned int func_02012138(const struct Ctx *a);
extern void *func_020120F4(const struct Ctx *p);
extern unsigned int func_02026454(void *obj);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_02012944(void *p);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern void func_021653C4(void);
extern unsigned int func_02026474(void *obj);
extern void *func_02188C80(void *p);
extern u8 func_0201212C(const struct Ctx *p);
extern int func_020123C4(void *v);
extern int func_02174268(u8 *p);
extern int func_0217B840(char *base, int r1);
extern void func_0217B75C(char *p);
extern void func_0217B264(u8 *w, void *sys, void *q);
extern u32 func_02012114(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *a);
extern void func_021A2E44(int a, unsigned int v);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013CC8(u32 id);
extern void func_0217B440(char *base, int x, void *y);
extern void func_021676E4(struct Work_0 *w);
extern void func_0217505C(int *p, int x);
extern void func_02167688(struct Work_0 *w);
extern void func_02172EDC(u8 *p);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02082D44(void *src, void *dst, u32 n);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008494(void *src, void *dst);
extern int func_02008468(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021CD624(u8 *p, int i, u32 a, u32 b, void *c);
extern int func_02183BE8(u8 *s, int i);
extern u32 func_0203D4D0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern u32 func_0203D378(void);
extern void func_02183F6C(u8 *p, u8 a);
extern void func_02183F7C(u8 *p);
extern void func_02183F88(u8 *p, u8 a);
extern void func_02183F98(void *p, const void *value);
extern u32 func_021840A8(u32);
extern void func_02183FB8(int, void *, u8, int);
extern void func_02183FA8(u8 *p, u8 index);
extern void func_02184060(u8 *s, int i);
extern void func_021840A4(int, u8);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0217F074(void *p);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern void func_02012374(struct Evt *evt, struct Evt **out);
void func_02173518(unsigned char *p);
void func_02173524(Work_0 *w, u8 *p);
int func_0217357C(u8 *self, const u8 *mac, u8 a2, u8 a3);
int func_021735FC(u8 *self, const Entry *p);
void func_02173614(u8 *self, const u8 *mac);
void func_02173650(int a, u8 *b);
void func_0217365C(u8 *p);
void func_021736A0(u8 *a, volatile u16 *s);
void func_021736C8(u8 *a, int v);
void func_021736E0(unsigned int x);
void func_02173744(int a);
void func_021737A4(void *a, int b);
int func_02173840(u8 *p);
void func_02173874(int a, u8 *p, void *q);
void func_021738D4(int a, T *p);
int func_0217391C(u8 *p);
int func_02173928(u8 *p);
void func_02173934(u8 *p, int v);
u8 func_02173940(u8 *p);
int func_0217394C(const struct Ctx *p);
u8 *func_02173984(int a, u8 *b, int c);
void func_021739A8(int a, int b, void *c, u8 *p);
int func_021739CC(void);
void func_021739E0(u32 a, int b, u32 *c, u8 *p);
int func_02173A04(int a, int b, int c, int d);
void func_02173A24(u32 a, int b, u32 *c, u8 *p);
int func_02173A48(int a, int b, int c, int d);
void func_02173A68(u32 a, int b, void *c, u8 *p);
int func_02173A90(void);
void func_02173AC4(u32 a, int b, u32 *c, u8 *p);
int func_02173AFC(int v);
void func_02173B1C(u32 a, int b, void *c, u8 *p);
int func_02173B4C(u8 *p);
void func_02173B78(u32 a, u32 b, const void *c, u8 *p);
u32 func_02173BB0(unsigned char *p);
void func_02173BFC(int a, int x, u8 *b, u8 *p);
void func_02173C64(int a, int b, u32 *value, u8 *p);
void func_02173C8C(int a, int b, int c, u8 *p);
int func_02173CB4(void);
void func_02173CCC(int a, int x, int y, u8 *p);
u32 func_02173D38(u8 *p);
void func_02173D7C(int a, int b, int c, u8 *p);
int func_02173D88(u32 a);
void func_02173DB0(int a, int b, int c, u8 *p);
int func_02173DBC(int a);
void func_02173DE4(int a, int b, int c, u8 *p);
u32 func_02173E1C(void);
void func_02173E40(int a, int b, int c, u8 *p);
u32 func_02173E68(u32 a);
void func_02173E90(int a, int b, int c, u8 *p);
int func_02173EC8(void);
void func_02173EEC(int a, int b, void *value, u8 *p);
u32 func_02173F20(void *p, u32 a);
void func_02173F54(int a, int x, int y, u8 *p);
void func_02173F90(int a, B32 *src);
void func_02173FE0(int a, int x, int y, u8 *p);
u32 func_02174010(u32 a, void *p);
void func_0217403C(int a, int x, int y, u8 *p);
void func_02174084(int a, B32 *src);
void func_021740D4(int a, int x, u8 *b, u8 *p);
void func_0217410C(u32 a, u8 b);
int func_0217413C(int a, int b, u8 *p);
int func_0217416C(int a, int *b, int *c);
extern char d_02175610[];
extern char d_02175614[];
extern const char d_02175624[];
extern u8 d_0217549C[];
extern u8 d_0217549D[];
extern u8 d_02175498[];





void func_02173518(unsigned char *p)
{
    p[0x19] = 0xff;
    p[0x1b] = 0xff;
    p[0x1a] = 0xff;
}






void func_02173524(Work_0 *w, u8 *p)
{
    Rec *r;

    func_02082BCC(p, 0, 0x4c);
    func_02173518(p);
    r = (Rec *)(p + 0x1c);
    func_02087C6C(r);
    r->f6 = func_02008554(w->head->f0);
    r->b0 = (u32)func_02008550(w->head->f0);
    r->b1 = 1;
    ((struct Obj19230 *)p)->f44 = 0xFFFF;
}






int func_0217357C(u8 *self, const u8 *mac, u8 a2, u8 a3)
{
    int j;
    Rec *r;
    int i;
    Rec *e;

    i = 0;
    r = (Rec *)(self + 0x1c);
    for (; i < 5; i++) {
        if (r[i].b1 == 1 && memcmp(mac, &r[i], 6) == 0) {
            return i;
        }
    }
    for (j = 0; j < 5; j++) {
        e = (Rec *)(self + 0x1c) + j;
        if (e->b1 == 0) {
            MI_CpuCopy8(mac, e, 6);
            e->f6 = a2;
            e->b0 = a3;
            e->b1 = 1;
            return j;
        }
    }
    return 0;
}





int func_021735FC(u8 *self, const Entry *p) { return func_0217357C(self, p->mac2, p->f6, p->used); }






void func_02173614(u8 *self, const u8 *mac)
{
    int i;
    Rec *r;

    i = 0;
    r = (Rec *)(self + 0x1c);
    for (; i < 5; i++) {
        if (r[i].b1 == 1 && memcmp(mac, &r[i], 6) == 0) {
            func_02082BCC(&r[i], 0, 8);
            return;
        }
    }
}






void func_02173650(int a, u8 *b)
{
    func_02173614((u8 *)a, b + 0x64);
}






void func_0217365C(u8 *p)
{
    int i;
    int v;

    func_02082BCC(p, 0, 0x448);
    for (i = 0; i < 30; i++) {
        func_02082BCC(p + i * 0x24 + 0x1a, 0xff, 6);
    }
    v = -1;
    ((struct Obj09359 *)p)->f43C = v;
    ((struct Obj09359 *)p)->f440 = v;
    ((struct Obj09359 *)p)->f444 = v;
}






/*
 * Unlabelled leaf (no lr save), called from ov019 func_0217BD9C. The two
 * trailing halfwords are both loaded before either is stored, in source
 * order; only a volatile source pointer keeps the scheduler from hoisting
 * s[3]'s load above s[2]'s (plain temporaries swap r1/r2).
 */
void func_021736A0(u8 *a, volatile u16 *s)
{
    u8 *p = a + 0x2830;
    u16 x, y;
    ((struct Obj04170 *)p)->f4 = s[0];
    ((struct Obj04170 *)p)->f6 = s[1];
    x = s[2];
    y = s[3];
    ((struct Obj04170 *)p)->f8 = x;
    ((struct Obj04170 *)p)->fA = y;
    p[0xf] = 0;
    (((struct Obj04170 *)p)->fC)++;
    p[0xe] = 1;
}






/*
 * Unlabelled leaf (no lr save) in the ov012 listing; callee of ov031
 * func_021F00D4 (a blocker of its MATCH). Same +0x2830 block as
 * func_021736A0.
 */
void func_021736C8(u8 *a, int v)
{
    u8 *p = a + 0x2830;
    p[0xf] = v;
    (((struct Obj09360 *)p)->fC)++;
    p[0xe] = 1;
}






void func_021736E0(unsigned int x)
{
    switch (x) {
    case 0x14:
        func_0203D5AC(0x17, 5);
        break;
    case 0x15:
        func_0203D5AC(0x18, 5);
        break;
    case 0x16:
        func_0203D5AC(0x19, 5);
        break;
    case 0x17:
        func_0203D5AC(0x1a, 5);
        break;
    case 3:
        func_0203D5AC(0x16, 5);
        break;
    case 0x19:
        func_0203D5AC(0x1b, 5);
        break;
    }
}






void func_02173744(int a)
{
    int r5;
    int r7;
    int *p;

    r5 = func_02012138((const struct Ctx *)a);
    r7 = (int)func_020120F4((const struct Ctx *)a);
    if (func_02026454((void *)r5) != 0) {
        func_02034714(d_02175610, 0, d_02175610);
    }
    p = func_02030734(5, 0x10, 1, d_02175614, 0x37);
    p[0] = (int)func_02012944((void *)r7);
    p[1] = r5;
    p[2] = r7;
    p[3] = a;
    func_020263D8((struct Comm *)r5, 3, (u32)p);
    func_021653C4();
}






void func_021737A4(void *a, int b)
{
    u8 *r4;
    u8 s;

    if (func_02026454(a) != 3) {
        return;
    }
    r4 = (u8 *)func_02026474(a);
    if (r4 == 0) {
        func_02034714((void *)0x02175610, 0, (void *)0x02175610);
    }
    if (func_0201212C(func_02188C80((void *)b)) == 1) {
        return;
    }
    if (func_020123C4((void *)((struct Obj19233 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->fC) == 1) {
        return;
    }
    if (func_02173840(r4) != 1) {
        return;
    }
    s = r4[0x2830];
    if (s >= 4 && s <= 0x17) {
        if (func_02174268(r4) != 0) {
            return;
        }
        func_0217B840((char *)r4, b);
        return;
    }
    if (s != 0 && s != 1) {
        return;
    }
    if (func_02174268(r4) != 0) {
        return;
    }
    func_0217B75C((char *)r4);
    func_0217B840((char *)r4, b);
    func_0217B264(r4, (void *)(((struct Obj19234 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->f8), (void *)b);
}





int func_02173840(u8 *p) { if(p[0x282a]==1 && func_02012114(*(const struct Ctx * *)&((struct Obj19235 *)(*(u8 * *)&((struct Obj09361 *)p)->f0))->fC)==1 && func_02188BE8(func_0201210C(*(const struct Ctx * *)&((struct Obj19236 *)(*(u8 * *)&((struct Obj09361 *)p)->f0))->fC))==1) return 1; return 0; }






/*
 * func_021A2E44(q, v) takes a second argument (it stores r1 at +0xc); its 1
 * is CSE'd with the stored 1, which is what puts that constant in r1 and
 * fixes the prologue schedule. Bitfield at +0xc8 needs lsls/lsrs #0x1f.
 */
void func_02173874(int a, u8 *p, void *q)
{
    S_02173874 *r4;

    r4 = *(S_02173874 * *)&((struct Obj07338 *)p)->f355C;
    p[0x282A] = 1;
    if (p[0x3563] == 1) {
        func_021A2E44((int)q, 1);
    }
    if (func_02013CC8(func_02188C9C(q)) == 1) {
        func_0217B440((char *)p, (int)func_020120F4((const struct Ctx *)(((struct Obj19238 *)(*(u8 * *)&((struct Obj07338 *)p)->f0))->fC)), q);
    }
    if (r4 != 0 && r4->f == 1) {
        func_021676E4(((struct Obj19237 *)r4)->f0);
    }
}






void func_021738D4(int a, T *p)
{
    S_021738D4 *o;

    o = p->b;
    if (o != 0) {
        if (o->g == 1) {
            func_0217505C((int *)o, ((struct Obj19239 *)(*(u8 * *)&((struct Obj07339 *)p)->f0))->fC);
            p->b = 0;
        } else if (((S0 *)o)->f == 1) {
            func_02167688(((struct Obj12444 *)o)->f0);
        }
    }
    p->a = 0;
}






/*
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x3568.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */
int func_0217391C(u8 *p)
{
    return ((struct Obj19240 *)p)->f3568;
}






/*
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x356C.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */
int func_02173928(u8 *p)
{
    return ((struct Obj19241 *)p)->f356C;
}





/*
 * Unlabelled leaf (no lr save) in the ov012 listing: stores the byte at
 * +0x2832. Callee of ov031 func_021F00D4 (a blocker of its MATCH).
 */
void func_02173934(u8 *p, int v)
{
    p[0x2832] = v;
}





/*
 * Unlabelled leaf (no lr save) in the ov012 listing: reads the byte at
 * +0x2832. Callee of ov031 func_021EFEC0 (a blocker of its MATCH).
 */
u8 func_02173940(u8 *p)
{
    return p[0x2832];
}




/*
 * 02012138 reads incoming r0; its u32 handle feeds 02026474(void *).
 */
int func_0217394C(const struct Ctx *p)
{
    u8 *w = (u8 *)func_02026474((void *)func_02012138(p));
    if (w == 0) return 0;
    if ((w[0x2831] == 0 || w[0x2831] == 0x2a) && w[0x3563] == 0) return 1;
    return 0;
}




u8 *func_02173984(int a, u8 *b, int c)
{
    if (c > 0x800) func_02034714(d_02175624, 0, d_02175624);
    return b + 4 + a * 0x800;
}




void func_021739A8(int a, int b, void *c, u8 *p)
{
    func_02172EDC(p);
    p[0x288e] |= (u8)(1 << a);
}




/*
 * Caller reads live r0 after 020399A8 and return from send wrapper.
 */
int func_021739CC(void)
{
    return func_0203D3A8(func_020399A8(), 0x1400, 0, 0);
}




void func_021739E0(u32 a, int b, u32 *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) q[0x2d] = *c;
}





int func_02173A04(int a, int b, int c, int d)
{
    return func_0203D3A8(func_020399A8(), 0x1401, 4, (u32)(&a));
}




/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Extent reaches existing matched func_02173A48's initial push.
 */
void func_02173A24(u32 a, int b, u32 *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) q[0x2e] = *c;
}





/*
 * Varargs function whose listing label (func_02173A4A) sits after the
 * push {r0-r3} home area; ov019 calls it at 0x02173A48.
 */
int func_02173A48(int a, int b, int c, int d)
{
    return func_0203D3A8(func_020399A8(), 0x1402, 4, (u32)(&a));
}




/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 */
void func_02173A68(u32 a, int b, void *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(c, q + 0x24, 8);
}




/*
 * 020399A8 leaves the used r0 payload live. Send forwards its pointer
 * unchanged as a full-word payload (matched send wrapper).
 */
int func_02173A90(void)
{
    Packet p;
    func_02082BCC(&p, 0, 8);
    func_02087C6C(&p);
    p.flag = 1;
    return func_0203D3A8(func_020399A8(), 0x1403, 8, (u32)&p);
}




/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Extent reaches existing matched func_02173AFC's initial push.
 */
void func_02173AC4(u32 a, int b, u32 *c, u8 *p)
{
    Sub_02173AC4 *q = (Sub_02173AC4 *)(p + 0x2830);
    if (a != func_0203D1A4((struct Link *)func_020399A8())) q->mode = (u8)*c;
}





/*
 * Opens with push {r0-r3} before the listing's func_02173AFE label: the
 * address of the register parameter is taken. Blocker of ov019
 * func_0217BE64's two calls.
 *
 * Addresses are Black-image addresses.
 */
int func_02173AFC(int v)
{
    return func_0203D3A8(func_020399A8(), 0x1404, 4, (u32)(&v));
}




void func_02173B1C(u32 a, int b, void *c, u8 *p)
{
    func_02008494(c, func_02012950(*(struct Sub24 * *)&((struct Obj19250 *)(*(u8 * *)&((struct Obj12445 *)p)->f0))->f8, a));
    p[0x288b] |= (u8)(1 << a);
}




/*
 * Live r0 return and narrowed third argument observed at send call;
 * matched wrapper copies fourth full-word payload unchanged.
 */
int func_02173B4C(u8 *p)
{
    u32 link;
    int n;
    link = (u32)func_020399A8();
    n = func_02008468();
    return func_0203D3A8((struct Entry *)link, (u16)0x1405, (u16)n, (u32)func_02012944(((struct Obj19252 *)(*(u8 * *)&((struct Obj19251 *)p)->f0))->f8));
}




/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Enum-typed local offset keeps 0x2830 and the +0x5d field add separate;
 * raw/nested pointer arithmetic and an inline setter folded to 0x288d.
 */
void func_02173B78(u32 a, u32 b, const void *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        enum { OFFSET = 0x2830 } off = OFFSET;
        Sub_02173B78 *q = (Sub_02173B78 *)(p + off);
        q->flag = 1;
        func_02082D44((void *)c, ((struct Obj19253 *)p)->f3544, b);
    }
}





u32 func_02173BB0(unsigned char *p)
{
    if (((struct Obj12446 *)p)->f3540 == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
    }
    return func_0203D3F8((u32)func_020399A8(), 0xff, 0x1406, 0x678, ((struct Obj12446 *)p)->f3540, 1, 0, 1);
}





void func_02173BFC(int a, int x, u8 *b, u8 *p)
{
    int *r4;
    int r7;
    int buf[2];

    r4 = *(int * *)&((struct Obj12447 *)p)->f355C;
    r7 = (int)func_020120F4((const struct Ctx *)(((struct Obj19256 *)(*(u8 * *)&((struct Obj12447 *)p)->f0))->fC));
    if (r4 == 0 || r4[0] == 0 || r4[0x5a] == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    func_02087C6C(buf);
    func_021CD624((u8 *)r4[0x5a], a, (int)func_02012944((void *)r7), b[0x27], buf);
}





void func_02173C64(int a, int b, u32 *value, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj19258 *)p)->f355C;
    if (q == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    q[0xDE] = *value;
}





void func_02173C8C(int a, int b, int c, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj19260 *)p)->f355C;
    if (q == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    q[0xCA] = 1;
}





int func_02173CB4(void)
{
    return func_0203D3A8(func_020399A8(), 0x1409, 0, 0);
}




void func_02173CCC(int a, int x, int y, u8 *p)
{
    if (((struct Obj05918 *)p)->f3528 == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        p[0x282D] |= (u8)(1 << a);
        return;
    }
    if (func_02183BE8((u8 *)(((struct Obj05918 *)p)->f3528), (u8)a) == 1) {
        p[0x282C] |= (u8)(1 << a);
        return;
    }
    p[0x282D] |= (u8)(1 << a);
}




u32 func_02173D38(u8 *p)
{
    p[0x282B] = 0;
    return func_0203D3F8((u32)func_020399A8(), 0, 0x140A, func_02008468(),
                  (u32)func_02012944((void *)(((struct Obj19262 *)(*(u8 * *)&((struct Obj12448 *)p)->f0))->f8)), 1, 0, 0);
}


void func_02173D7C(int a, int b, int c, u8 *p) { p[0x282b] = 2; }





int func_02173D88(u32 a)
{
    return func_0203D4D0((u32)func_020399A8(), a, 0x140B, 0, 0, 1, 0, 0);
}





void func_02173DB0(int a, int b, int c, u8 *p)
{
    p[0x282B] = 1;
}





int func_02173DBC(int a)
{
    return func_0203D4D0((u32)func_020399A8(), a, 0x140C, 0, 0, 1, 0, 0);
}





/*
 * lever:    Nested null recheck retains the original dead second bne.
 */
void func_02173DE4(int a, int b, int c, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 0) {
        q = *(u8 * *)&((struct Obj19264 *)p)->f3528;
        if (q == 0) {
            if (q == 0) {
                func_02034714((void *)0x02175624, 0, (void *)0x02175624);
                return;
            }
        } else {
            func_02183F6C(q, (u8)a);
        }
    }
}





u32 func_02173E1C(void)
{
    return func_0203D3F8((u32)func_020399A8(), 0, 0x140D, 0, 0, 1, 0, 0);
}





void func_02173E40(int a, int b, int c, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj19265 *)p)->f3528;
    if (q == 0) {
        if (q == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
    } else {
        func_02183F7C(q);
    }
}





u32 func_02173E68(u32 a)
{
    return func_0203D3F8((u32)func_020399A8(), a, 0x140E, 0, 0, 1, 0, 0);
}





void func_02173E90(int a, int b, int c, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 0) {
        q = *(u8 * *)&((struct Obj19266 *)p)->f3528;
        if (q == 0) {
            if (q == 0) {
                func_02034714((void *)0x02175624, 0, (void *)0x02175624);
                return;
            }
        } else {
            func_02183F88(q, (u8)a);
        }
    }
}





int func_02173EC8(void)
{
    return func_0203D3F8((u32)func_020399A8(), 0, 0x140F, 0, 0, 1, 0, 0);
}





void func_02173EEC(int a, int b, void *value, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 1) {
        q = *(u8 * *)&((struct Obj19267 *)p)->f3528;
        if (q == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
        func_02183F98(q, value);
    }
}



u32 func_02173F20(void *p, u32 a)
{
    u32 entry;
    u32 size;
    entry = (u32)func_020399A8();
    size = func_021840A8(entry);
    return func_0203D4D0(entry, a, 0x1410, size, (u32)p, 1, 0, 0);
}



void func_02173F54(int a, int x, int y, u8 *p)
{
    if (((struct Obj09364 *)p)->f3528 == 0) {
        func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
        return;
    }
    func_02183FB8(((struct Obj09364 *)p)->f3528, p, a, y);
    func_02183FA8((u8 *)(((struct Obj09364 *)p)->f3528), a);
}




void func_02173F90(int a, B32 *src)
{
    Msg m;

    func_02082BCC(&m, 0, 0x28);
    m.a = *src;
    func_02087C6C(m.t);
    func_0203D4D0((int)func_020399A8(), a, 0x1411, 0x28, (u32)(&m), 1, 0, 0);
}



void func_02173FE0(int a, int x, int y, u8 *p)
{
    if (((struct Obj12449 *)p)->f3528 == 0) {
        func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
        return;
    }
    func_02183FB8(((struct Obj12449 *)p)->f3528, p, a, y);
}



u32 func_02174010(u32 a, void *p)
{
    return func_0203D4D0((u32)func_020399A8(), a, 0x1412, 0x28, (u32)p, 1, 0, 0);
}




void func_0217403C(int a, int x, int y, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        if (((struct Obj09365 *)p)->f3528 == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
        func_02183FB8(((struct Obj09365 *)p)->f3528, p, (u8)a, y);
        func_02184060((u8 *)(((struct Obj09365 *)p)->f3528), (u8)a);
    }
}




void func_02174084(int a, B32 *src)
{
    Msg m;

    func_02082BCC(&m, 0, 0x28);
    m.a = *src;
    func_02087C6C(m.t);
    func_0203D4D0((int)func_020399A8(), a, 0x1413, 0x28, (u32)(&m), 1, 0, 0);
}



/*
 * Extent follower 0217410C is this lane's corrected-entry file, kept separate.
 * func_021840A4 receives both original loaded arguments despite its empty body.
 */
void func_021740D4(int a, int x, u8 *b, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((int)func_020399A8()))) {
        if (((struct Obj12450 *)p)->f3528 == 0) {
            func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
            return;
        }
        func_021840A4(((struct Obj12450 *)p)->f3528, *b);
    }
}



void func_0217410C(u32 a, u8 b)
{
    func_0203D4D0((u32)func_020399A8(), a, 0x1414, 1, (u32)&b, 1, 0, 0);
}



int func_0217413C(int a, int b, u8 *p)
{
    int task;
    Work *w;
    task = (int)func_020122C0((void *)a, 0, (void *)((int)func_0217416C), 12);
    w = func_020124E8((struct Obj *)task);
    w->f0 = a;
    w->f4 = b;
    w->f8 = p;
    ((struct Obj19269 *)p)->f3548 = 1;
    return task;
}




/*
 * func_021734A8 is a 3-argument field setter (case 4 is strb r2): the table
 * key loads straight into r2 because it is the third argument.
 */
int func_0217416C(int a, int *b, int *c)
{
    int first;
    u8 *base;
    R *r4;
    int loc;
    int k;

    first = c[0];
    base = (u8 *)c[2];
    r4 = (R *)(base + 0x3548);
    loc = 0;
    switch (*b) {
    case 0:
        func_0217F074(base);
        k = d_0217549C[r4->f4 * 8];
        if (k != 0x1b) {
            func_021734A8(base, 4, k);
        }
        (*b)++;
    case 1: {
        int r;
        r = (*(Fn *)(d_02175498 + r4->f4 * 8))(first, base, c[1], r4->f8, a, &loc, &r4->fc);
        if (loc != 0) {
            func_02012374((struct Evt *)a, (struct Evt **)loc);
        } else if (r == 1) {
            (*b)++;
        }
        break;
    }
    case 2:
        k = d_0217549D[r4->f4 * 8];
        if (k != 0x1b) {
            func_021734A8(base, 4, k);
        }
        r4->f4 = 0;
        r4->f8 = 0;
        r4->fc = 0;
        r4->f0 = 0;
        return 1;
    }
    return 0;
}
