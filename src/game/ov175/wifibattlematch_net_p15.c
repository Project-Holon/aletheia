/*
 * file:     wifibattlematch_net_p15.c
 * unit:     yes
 * function: func_021D9A50, func_021D9A9C, func_021D9B18, func_021D9B2C, func_021D9BC4, func_021D9C34, func_021D9D40, func_021D9D50, func_021D9DC8, func_021D9EA0, func_021D9ED0, func_021D9ED4
 * address:  0x021D9A50
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_0201A918 0x0201A918 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_021DC194  0x021DC194  thumb  ov175
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CC0  0x02009CC0  thumb
 *   func_0200B078  0x0200B078  thumb
 *   func_0200B1C4  0x0200B1C4  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021B9A64  0x021B9A64  thumb  ov114
 *   func_021B9A94  0x021B9A94  thumb  ov114
 *   func_021B9A1C  0x021B9A1C  thumb  ov114
 *   func_021B9A8C  0x021B9A8C  thumb  ov114
 *   func_020185F0  0x020185F0  thumb
 *   func_020173E8  0x020173E8  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_020362DC                0x020362DC  arm
 *   func_021E8738                0x021E8738  thumb  ov177
 *   func_021E8844                0x021E8844  thumb  ov177
 *   func_021D98E4                0x021D98E4  thumb
 *   func_021D9A08                0x021D9A08  thumb
 *   func_021D99F4                0x021D99F4  thumb
 *   func_021DA434                0x021DA434  thumb
 *   func_021E7E0C                0x021E7E0C  thumb  ov177
 *   func_021DA36C                0x021DA36C  thumb
 *   func_0200FB24                0x0200FB24  thumb
 *   func_0203CD98                0x0203CD98  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   func_0200DFD8  0x0200DFD8  thumb
 *   func_0200DFE4  0x0200DFE4  thumb
 *   func_02030734 0x02030734 arm
 *   func_02009860 0x02009860 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_02034714 0x02034714 arm
 *   func_0203A574 0x0203A574 arm
 *   func_0203D644 0x0203D644 arm
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021DC5C8 0x021DC5C8 thumb ov175
 *   func_021DC5F8 0x021DC5F8 thumb ov175
 *   d_021E2EE0 0x021E2EE0 data a4
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2C90 0x021E2C90 data a4
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 */
#include "../../matched/include/Obj00013.h"
#include "../../matched/include/Obj24310.h"
#include "../../matched/include/Obj24311.h"
#include "../../matched/include/Obj01067.h"
#include "../../matched/include/Obj00594.h"
#include "../../matched/include/Obj24319.h"
#include "../../matched/include/Obj24320.h"
#include "../../matched/include/Obj24321.h"
#include "../../matched/include/Obj24322.h"
#include "../../matched/include/Obj24323.h"
#include "../../matched/include/Obj24324.h"
#include "../../matched/include/Obj24325.h"
#include "../../matched/include/Obj24326.h"
#include "../../matched/include/Obj14331.h"

struct Big;
struct BigObj;
struct Rec0200E6FC;
struct Reg2;
struct Sub0200852CObj;
struct Entry;
struct Link;
typedef unsigned int   u32_021D9A50;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_021D9A9C;

struct Save {
    u8  pad_00[8];
    u32_021D9A9C *sav;
    u8  pad_0c[0x28];
    u32_021D9A9C *blk;
};

typedef signed int     s32;

typedef unsigned int u32_021D9B2C;

typedef unsigned long u32_021D9BC4;

typedef unsigned long u32_021D9C34;

typedef unsigned long u32_021D9D40;

typedef unsigned long u32_021D9D50;

typedef unsigned int u32_021D9DC8;

typedef unsigned int u32_021D9EA0;

typedef unsigned long u32_021D9ED4;

extern void func_02082BCC(void *, int, int);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern void *func_0200BAF4(int a0, int a1);
extern void *func_0201A948(void *);
extern int func_0201A918(void *);
extern void func_02082D44(const void *, void *, int);
extern u32_021D9A50 func_020307B0(void *p);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *src, void *dst);
extern void *func_0200E6E8(u32_021D9A9C a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32_021D9A9C func_021DC194(char *obj);
extern u32_021D9A9C func_0201283C(const struct BigObj *p);
extern int func_02009CC0(void *a0);
extern s32 func_0200B078(struct Reg2 *p, u32_021D9A9C id);
extern u16 func_0200B1C4(struct Reg2 *p);
extern u32_021D9B2C func_020173EC(void);
extern u32_021D9B2C func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32_021D9B2C idx);
extern u8 *func_021B9A64(int a, int b, int c);
extern void func_021B9A94(int p, int a, u32_021D9B2C b, int n);
extern int func_021B9A1C(void *a, int b, int c, char *d, u16 e);
extern void func_021B9A8C(void *buf);
extern u8 *func_020185F0(u32_021D9BC4 entry);
extern u32_021D9BC4 func_020173E8(void);
extern int func_0203EFC8(const u8 *a, const u8 *b, u32_021D9BC4 n);
extern u32_021D9C34 func_020362DC(void);
extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *p);
extern void func_021D98E4(u32_021D9C34 *p, int mode);
extern int func_021D9A08(char *obj);
extern void func_021D99F4(char *obj);
extern int func_021DA434(u32_021D9C34 h);
extern void func_021E7E0C(void **p, int on);
extern void func_021DA36C(u32_021D9C34 h);
extern u32_021D9C34 func_0200FB24(void);
extern int func_0203CD98(void);
extern void DWC_CloseAllConnectionsHard(void);
extern u32_021D9D50 func_0200DFD8(u32_021D9D50 save, u32_021D9D50 table, u32_021D9D50 slot);
extern void func_0200DFE4(u32_021D9D50 save, u32_021D9D50 table, u32_021D9D50 slot, u32_021D9D50 value);
extern void *func_02030734(u32_021D9DC8 heapId, u32_021D9DC8 size, int clear, const char *site, u16 tag);
extern u32_021D9DC8 func_02009860(void);
extern u32_021D9DC8 func_0200853C(const struct Sub0200852CObj *obj);
extern void func_02034714(const char *expr, u32_021D9DC8 line, const char *file);
extern void func_0203A574(u32_021D9DC8, u32_021D9DC8, u32_021D9DC8, u32_021D9DC8);
extern void func_0203D644(int);
extern void func_02156DC4(int, int);
extern void func_02156DE0(int, int);
extern void func_021DC5C8(void *, int, int);
extern u32_021D9DC8 func_021DC5F8(char *p, int a, int kind);
extern void func_0203A5E4(u32_021D9EA0);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
void func_021D9A50(char *dest, char *ctx);
void func_021D9A9C(char *dst, char *obj);
void func_021D9B18(char *save, char *response);
u32_021D9B2C func_021D9B2C(char *obj, void *list, u32_021D9B2C heapId);
int func_021D9BC4(u32_021D9BC4 a, u32_021D9BC4 b);
int func_021D9C34(char *obj, int trigger, int go);
void func_021D9D40(char *obj);
int func_021D9D50(char *obj, u32_021D9D50 *rec);
char *func_021D9DC8(u32_021D9DC8 a, void *save, u32_021D9DC8 b, u16 heap);
void func_021D9EA0(u8 *p);
void func_021D9ED0(int a0);
void func_021D9ED4(char *obj, u32_021D9ED4 v);
extern const char d_021E2EE0[], d_021E2EF8[];
extern const u32_021D9DC8 d_021E2C90[];

void func_021D9A50(char *dest, char *ctx)
{
    void *records;
    func_02082BCC(dest, 0, 212);
    records = func_0200BAF4((int)func_0200BAC8(func_02012EBC(**(void ** *)&((struct Obj24311 *)(*(char * *)&((struct Obj00013 *)ctx)->f104))->f8)), 87);
    func_02082D44(records, dest + 212, func_0201A918(func_0201A948(dest + 212)));
    func_020307B0(records);
    ((struct Obj24310 *)dest)->f44 = 100;
}


/*
 * Fills a profile record from the save data reached through +0x104: name, a 0x38 record, three words of the +0x34 block, the +0x34 id, a derived word and two values of the +0x108 block.
 *
 *     (MI_CpuCopy8 with size 0x20) with no witness. Seed and match it and this
 *     file is EXACT.
 */
void func_021D9A9C(char *dst, char *obj)
{
    u32_021D9A9C st = (u32_021D9A9C)func_02012EBC((struct Big *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav));
    u32_021D9A9C h;

    func_02008494(func_02012944((void *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav)), dst);
    func_0200E6FC(func_0200E6E8(st), 0, (struct Rec0200E6FC *)(dst + 0x38));
    {
        const struct Save *s = *(struct Save * *)&((struct Obj00013 *)obj)->f104;
        ((struct Obj01067 *)dst)->f28 = s->blk[2];
        ((struct Obj01067 *)dst)->f2C = s->blk[3];
        ((struct Obj01067 *)dst)->f34 = s->blk[4];
    }
    ((struct Obj01067 *)dst)->f4C = func_021DC194((char *)(*(u32_021D9A9C *)&((struct Obj00013 *)obj)->f34));
    ((struct Obj01067 *)dst)->f48 = func_02009CC0((void *)func_0201283C((const struct BigObj *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav)));
    h = ((struct Obj00013 *)obj)->f108;
    ((struct Obj01067 *)dst)->f40 = func_0200B078((struct Reg2 *)h, 2);
    ((struct Obj01067 *)dst)->f50 = func_0200B1C4((struct Reg2 *)h);
}

/*
 * leaf: copy128 bytes from response+0x1c to save+0x54.
 */
void func_021D9B18(char *save, char *response)
{
    func_02082D44(response + 0x1c, save + 0x54, 128);
}


u32_021D9B2C func_021D9B2C(char *obj, void *list, u32_021D9B2C heapId)
{
    int heap = (heapId & 0x7fff) | 0x8000;
    u32_021D9B2C size = func_020173EC();
    void *buf = func_021B9A64(size, func_0201AA18(list), (u16)heap);
    int i;
    u32_021D9B2C ret;

    for (i = 0; i < (int)func_0201AA18(list); i++) {
        void *e = func_0201AB28(list, i);
        func_021B9A94((int)buf, (int)e, func_020173EC(), i);
    }
    size = func_020173EC();
    ret = func_021B9A1C(buf, size, func_0201AA18(list), obj + 0x54, (u16)heap);
    func_021B9A8C(buf);
    return ret;
}


int func_021D9BC4(u32_021D9BC4 a, u32_021D9BC4 b)
{
    u32_021D9BC4 n = func_0201AA18((void *)a);
    u32_021D9BC4 i;

    if (n == func_0201AA18((void *)b)) {
        for (i = 0; i < n; i++) {
            u32_021D9BC4 ea = (u32_021D9BC4)func_0201AB28((void *)a, i);
            u32_021D9BC4 eb = (u32_021D9BC4)func_0201AB28((void *)b, i);
            u8 *pa = func_020185F0(ea);
            u8 *pb = func_020185F0(eb);
            if (func_0203EFC8(pa, pb, func_020173E8()) != 0)
                return 0;
        }
        return 1;
    }
    return 0;
}


/*
 * Quit-confirmation dialog step (state at +0xec): waits for the trigger and the button, prints the question, waits for the message, opens the yes/no window, then on yes prints the goodbye and closes the connection (returns 3 when finished), on no returns 2; returns 1 while the dialog is active and 0 when idle.
 *
 * Closed: the final state test is a switch, which keeps the `return 0` arm as the
 *     fall-through where every if/else spelling inverts it (EXACT* once the
 *     ov177 getter 0x021E8844 got its label).
 */
int func_021D9C34(char *obj, int trigger, int go)
{
    int r;

    switch (((struct Obj00594 *)obj)->fEC) {
    case 0:
        if (trigger == 0)
            break;
        if (!(func_020362DC() & 2))
            break;
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 1:
        func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x23, 1);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 2:
        if (!func_021E8844((const int *)(((struct Obj00594 *)obj)->f2C)))
            break;
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 3:
        func_021D98E4((u32_021D9C34 *)obj, 0);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 4:
        r = func_021D9A08(obj);
        if (r == -1)
            break;
        func_021D99F4(obj);
        switch (r) {
        case 0:
            ((struct Obj00594 *)obj)->fEC = 5;
            break;
        case 1:
            func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x21, 0);
            ((struct Obj00594 *)obj)->fEC = 0;
            return 2;
        }
        break;
    case 5:
        func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x2b, 2);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 6:
        if (go == 0)
            break;
        func_021DA434(((struct Obj00594 *)obj)->f34);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        func_021E7E0C((void **)(((struct Obj00594 *)obj)->f28), 0);
        func_021DA36C(((struct Obj00594 *)obj)->f34);
        if (!func_0200FB24() && func_0203CD98())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct Obj00594 *)obj)->fEC = 0;
        return 3;
    }
    switch (((struct Obj00594 *)obj)->fEC) {
    case 0:
        return 0;
    default:
        return 1;
    }
}


/*
 * Clears the +0xec last-read length and tail-calls the +0x30 release path
 *     func_021D99F4, so nothing is saved.  Mirrors func_021D6954.
 */
void func_021D9D40(char *obj)
{
    ((struct Obj24319 *)obj)->fEC = 0;
    func_021D99F4(obj);
}


/*
 * Syncs three words of a record (+0x10, +0x8, +0xc) into slots 0..2 of table 10 of the save block at +0x104; returns 1 when any of them differed from what was stored.
 *
 * Both callees 0x0200DFD8 and 0x0200DFE4 resolve since seeds_2 labelled and
 *     matched them (src/matched/unit_0200DFD8.c).
 */
int func_021D9D50(char *obj, u32_021D9D50 *rec)
{
    int changed = 0;

    if (rec[4] != func_0200DFD8(((struct Obj24320 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0)
        || rec[2] != func_0200DFD8(((struct Obj24321 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1)
        || rec[3] != func_0200DFD8(((struct Obj24322 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2))
        changed = 1;
    func_0200DFE4(((struct Obj24323 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0, rec[4]);
    func_0200DFE4(((struct Obj24324 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1, rec[2]);
    func_0200DFE4(((struct Obj24325 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2, rec[3]);
    return changed;
}

/*
 *   extern void func_020394F0(int);
 *   void func_0203D644(int value) { func_020394F0(value); }
 *   Its target stores its one word input at global +0x1ac; no extra input.
 *   Leaf returns *(u32 *)(p+0x1458) for kind 3 or 6, otherwise 0.
 * lever: u16 heap fixes allocator spill order; 02009860 leaves r0 live,
 *   and caller stores that return word despite the callee's void declaration.
 * note 2026-10-04 (lane 20, D2): leaf func_021DC5F8 is now filed EXACT as
 * src/matched/ov/ov175_func_021DC5F8.c (24 bytes). The tool still says "no witness" for it until
 * the integrator runs the manifest. The other blocker, ARM9 func_0203D644 (veneer-like 12-byte
 * tail call), is the arm9 label lane's. Body is byte-correct; expect EXACT after manifest + label.
 */
char *func_021D9DC8(u32_021D9DC8 a, void *save, u32_021D9DC8 b, u16 heap) {
    char *p;
    p = func_02030734(heap, 0x149c, 0, d_021E2EE0, 0x2b0);
    func_02082BCC(p, 0, 0x149c);
    *(u32_021D9DC8 *)(p + 4) = func_0201283C(save);
    *(u32_021D9DC8 *)p = func_02009860();
    *(void **)(p + 0xc) = (void *)func_0200853C((const struct Sub0200852CObj *)func_02012944(save));
    *(void **)(p + 8) = save;
    *(u32_021D9DC8 *)(p + 0x10) = b;
    *(u32_021D9DC8 *)(p + 0x1464) = a;
    *(int *)(p + 0x19c) = 0x573;
    *(char **)(p + 0x190) = func_02030734(heap, 0x260, 0, d_021E2EE0, 0x2c0);
    func_02082BCC(*(void **)(p + 0x190), 0, 0x260);
    if (!func_0203CD98()) func_02034714(d_021E2EF8, 0, d_021E2EF8);
    func_0203A574(0x2400, (u32_021D9DC8)d_021E2C90, 6, (u32_021D9DC8)p);
    func_0203D644(0);
    func_02156DC4((int)func_021DC5C8, (int)p);
    func_02156DE0((int)func_021DC5F8, (int)p);
    return p;
}

void func_021D9EA0(u8 *p) { func_02156DE0(0,0); func_02156DC4(0,0); func_0203A5E4(0x2400); func_020307B0(((struct Obj24326 *)p)->f190); func_020307B0(p); }

/*
 * Empty stub sitting between the func_021D9EA0 teardown and
 *     func_021D9ED4; nothing calls into it, disasm.py labelled it from its
 *     alignment padding.
 */
void func_021D9ED0(int a0)
{
}


/*
 * Stores the caller's word at +0x14 and forwards its low byte to
 *     0x02039C68 with the tick/state from 0x020399A8 and line 0x24.  The byte
 *     is re-read from the field after the first call, which is why the listing
 *     reloads +0x14.  func_021D9EEC is the same shape for the flush path.
 */
void func_021D9ED4(char *obj, u32_021D9ED4 v)
{
    ((struct Obj14331 *)obj)->f14 = v;
    func_02039C68((struct Link *)func_020399A8(), (unsigned char)((struct Obj14331 *)obj)->f14, 0x24);
}
