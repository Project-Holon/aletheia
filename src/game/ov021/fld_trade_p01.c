/*
 * file:     fld_trade_p01.c
 * unit:     yes
 * function: func_021CBFB0, func_021CC040, func_021CC060, func_021CC068, func_021CC070, func_021CC098
 * address:  0x021CBFB0
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
 *   func_02030734  0x02030734  arm
 *   func_02048F88  0x02048F88  arm
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_020084D4  0x020084D4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   d_021DE59C  0x021DE59C  data  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201862C  0x0201862C  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_021CC23C  0x021CC23C  thumb  ov021
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0202F190  0x0202F190  thumb
 *   func_020185C4  0x020185C4  thumb
 */
#include "../../matched/include/Obj20247.h"
#include "../../matched/include/Obj20248.h"
#include "../../matched/include/Obj01219.h"
#include "../../matched/include/Obj18350.h"
#include "../../matched/include/Obj18351.h"

struct U16Vec;
struct Sub0200852CObj;
struct MsgBank;
struct Rec;
struct Mon;
struct Personal;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Obj_021CBFB0 {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 *f8;
    void *fC;
    int f10;
} Obj_021CBFB0;

typedef struct Obj_021CC040 {
    unsigned char pad0[8];
    void *f8;
    void *fC;
    void *f10;
} Obj_021CC040;

typedef unsigned long long u64;

typedef struct {
    u32 f00;
    u32 species;    /* 0x04 */
    u32 level;      /* 0x08 */
    u32 f0C;
    u32 f10[6];     /* 0x10..0x24: fields 0x46..0x4b */
    u32 sel;        /* 0x28 */
    u32 f2C;
    u32 f30;
    u32 id;         /* 0x34 */
    u32 f38[5];     /* 0x38..0x48: fields 0x13..0x17 */
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5C;
    u32 f60;
    u32 f64;
    u32 f68;
} Spec;

extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *);
extern void func_02045A38(struct U16Vec *, u16 *, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200854C(int, u32);
extern u32 func_020307B0(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201862C(u32 id, u16 species, u16 level, u8 a3, u8 a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *mon, u32 field, u32 v);
extern void func_021CC23C(int obj);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u8 *func_02012944(void *p);
extern void func_0202F190(void *mon, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_020185C4(void *mon);
Obj_021CBFB0 *func_021CBFB0(u32 a, u32 b);
void func_021CC040(Obj_021CC040 *o);
u32 func_021CC060(u8 *p);
u32 func_021CC068(u8 *p);
void *func_021CC070(u32 file, u32 index);
void func_021CC098(void *sys, u16 b, void *mon, Spec *d);
extern const char d_021DE59C[];


Obj_021CBFB0 *func_021CBFB0(u32 a, u32 b)
{
    Obj_021CBFB0 *p;
    int r;
    char buf[0x100];

    p = func_02030734((u16)a, 0x14, 1, d_021DE59C, 0x5d);
    p->f0 = (u16)a;
    p->f4 = b;
    p->f8 = func_02048F88(0xa5, b, (u16)a, 0, (u32 *)0x6c);
    p->fC = func_02030734((u16)a, 0xdc, 0, d_021DE59C, 0x65);
    p->f10 = (int)func_0200846C(a);
    func_020084A0((struct Sub0200852CObj *)p->f10);
    r = (int)func_021CC070(a, ((struct Obj20247 *)(p->f8))->f68);
    func_02045A38((struct U16Vec *)r, (u16 *)buf, 0x80);
    func_02045808((struct U16Vec *)r);
    func_020084D4(p->f10, buf);
    func_0200854C(p->f10, ((struct Obj20248 *)(p->f8))->f50);
    return p;
}


/*
 * Frees the three buffers held by a battle-subway mon object and then the object itself.
 *
 * Addresses are Black-image addresses.
 */
void func_021CC040(Obj_021CC040 *o)
{
    func_020307B0(o->f8);
    func_020307B0(o->fC);
    func_020307B0(o->f10);
    func_020307B0(o);
}


/*
 * Follows the pointer at +0x8, then loads the 32-bit word at +0x5c of its target.
 */
u32 func_021CC060(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj01219 *)p)->f8;

    return ((struct Obj18350 *)q)->f5C;
}


/*
 * Follows the pointer at +0x8, then loads the 32-bit word at +0x60 of its target.
 */
u32 func_021CC068(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj01219 *)p)->f8;

    return ((struct Obj18351 *)q)->f60;
}


/*
 * Opens message bank 0x23 for a given file, fetches one string and closes the bank.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CC070(u32 file, u32 index)
{
    void *bank = func_02045B38(0, 2, 0x23, (u16)file);
    void *s = func_02045EC0(bank, index);
    func_02045C04(bank);
    return s;
}


void func_021CC098(void *sys, u16 b, void *mon, Spec *d)
{
    u32 pid;
    u32 s;
    u32 x;
    u32 v[3];

    pid = func_0201862C(d->id, d->species, d->level, d->f30, 0, 0);
    func_02017588(mon, d->species, d->f0C, d->id, 0xFFFFFFFF, pid);
    func_02017E40(mon, 0x6F, d->level);
    func_021CC23C((int)mon);
    s = (u32)func_021CC070(b, d->f64);
    func_02017E40(mon, 0x73, s);
    func_02045808((struct U16Vec *)s);
    func_02017E40(mon, 0x46, d->f10[0]);
    func_02017E40(mon, 0x47, d->f10[1]);
    func_02017E40(mon, 0x48, d->f10[2]);
    func_02017E40(mon, 0x49, d->f10[3]);
    func_02017E40(mon, 0x4A, d->f10[4]);
    func_02017E40(mon, 0x4B, d->f10[5]);
    x = (u32)func_0201ADE4((u16)d->species, (u16)d->level, b);
    v[0] = func_0201AE1C((const struct Personal *)x, 0x1A);
    v[1] = func_0201AE1C((const struct Personal *)x, 0x1B);
    v[2] = func_0201AE1C((const struct Personal *)x, 0x1C);
    func_0201AE14((void *)x);
    switch (d->sel) {
    case 0:
        break;
    case 1:
        v[0] = v[1];
        break;
    case 2:
        v[0] = v[2];
        break;
    }
    func_02017E40(mon, 0xA, v[0]);
    func_02017E40(mon, 0x70, d->f2C);
    func_02017E40(mon, 0x13, d->f38[0]);
    func_02017E40(mon, 0x14, d->f38[1]);
    func_02017E40(mon, 0x15, d->f38[2]);
    func_02017E40(mon, 0x16, d->f38[3]);
    func_02017E40(mon, 0x17, d->f38[4]);
    func_02017E40(mon, 0x6, d->f4C);
    s = (u32)func_021CC070(b, d->f68);
    func_02017E40(mon, 0x8D, s);
    func_02045808((struct U16Vec *)s);
    func_02017E40(mon, 0x9A, d->f50);
    func_02017E40(mon, 0xC, d->f58);
    func_0202F190(mon, 1, (u32)func_02012944(sys), 0x7532, b);
    func_021CC23C((int)mon);
    func_020185C4(mon);
}
