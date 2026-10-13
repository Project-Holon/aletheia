/*
 * file:     unit_021DC860.c
 * unit:     yes
 * function: func_021DC860, func_021DC86C, func_021DC888, func_021DC914, func_021DC93C, func_021DCB48
 * address:  0x021DC860
 * region:   ov134
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   func_0203A574 0x0203A574 arm
 *   func_021DCC48 0x021DCC48 thumb ov134
 *   tbl_021DCC9C 0x021DCC9C data a4
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   ov90_id 0x0000005A data a1
 *   func_021B6108 0x021B6108 thumb ov090
 *   func_02034A5C 0x02034A5C arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_021B6114 0x021B6114 thumb ov090
 *   func_02034AC4 0x02034AC4 arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   gPartyListProcData 0x021BED00 data a4 ov091
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov91_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201A2A8 0x0201A2A8 thumb
 *   func_0200873C 0x0200873C thumb
 *   func_021B6100 0x021B6100 thumb ov090
 */
#include "../../matched/include/Obj05411.h"
#include "../../matched/include/Obj23343.h"
#include "../../matched/include/Obj00310.h"
#include "../../matched/include/Obj06506.h"

struct Entry;
struct Link;
struct Obj0203159C;
struct S020314B8;
struct S020315D4;
struct Party;
struct PartyMon;
struct Big;
struct Sub02008700Obj;
typedef struct {
    char pad0[0xF0];
    int tbl[1];
} Tbl;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[11]; } Args_021DC860;

typedef struct { u8 *a; void *party; u32 f8; u8 fC, padD[3]; u32 f10; void *save; u8 tail[20]; } Args_021DC914;

typedef struct {
    void *party;
    u32 f4, f8, fC, f10;
    u8 *a;
    u8 pad18[24];
    u16 f30, pad32;
    u32 f34, f38, f3C, f40;
    u16 f44, f46;
    u8 f48, marks[6], pad4F;
    u32 f50;
    u16 f54, pad56;
    u32 f58, pad5C;
    u16 f60, pad62;
    u32 f64;
    u8 pad68[12];
    u32 f74, f78;
    u8 f7C, pad7D[15];
    u32 f8C, f90;
    u8 f94;
} Output;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern void *PROCSYS_Create(int a0);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_021DCC48(u8 *p, void *unused, u8 *out);
extern void func_021B6108(void *);
extern void func_02034A5C(int);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021B6114(u8 *);
extern int func_02034AC4(int);
extern void PROCSYS_Push(void *, int, const void *, void *);
extern u32 PROCSYS_Main(void *);
extern void *func_0201AB28(void *, u32);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern u32 func_0200FB24(void);
extern int func_0203CD98(void);
extern int DWC_RAPCOMMON_HandleNetError(int, int);
extern void *func_02012EBC(struct Big *p);
extern void func_0201A2A8(void *, void *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_021B6100(u8 *);
int func_021DC860(int i, Tbl *p);
void func_021DC86C(u32 value,u32 a,u32 b,u32 c,void *expected);
int func_021DC888(void *ctx, int unused, const Args_021DC860 *args);
int func_021DC914(void *p,u32 a,u32 b,char *ctx);
int func_021DC93C(void *unused0, void *unused1, u8 *q, u8 *p);
void func_021DCB48(Args_021DC914 *p, void *unused, Output *out);
extern const u32 tbl_021DCC9C[];
extern u32 g_02FFFC3C;
extern const char ov90_id[];
extern const u32 gPartyListProcData[], gPokeStatusProcData[];
extern const char ov91_id[], ov131_id[];



int func_021DC860(int i, Tbl *p)
{
    return p->tbl[i];
}


/*
 * extent: trailing 2-byte alignment padding; early return keeps the final unused compare.
 */
void func_021DC86C(u32 value,u32 a,u32 b,u32 c,void *expected) { if(expected==func_020399A8()) { if(value!=func_0203D1A4((struct Link *)func_020399A8())) return; } }


int func_021DC888(void *ctx, int unused, const Args_021DC860 *args)
{
    u8 *p;
    p = func_0203159C(ctx, 0x100, 4);
    func_02082BCC(p, 0, 0x100);
    *(Args_021DC860 *)(p + 0xd0) = *args;
    ((struct Obj05411 *)p)->fFC = 4;
    ((struct Obj05411 *)p)->fCC = PROCSYS_Create(((struct Obj05411 *)p)->fFC);
    func_0203A574(0x2f00, (u32)tbl_021DCC9C, 1, (u32)p);
    func_021DCB48((Args_021DC914 *)args, p, (Output *)(p + 4));
    func_021DCC48((u8 *)args, p, p + 0x9c);
    p[0xc4] = 0;
    ((struct Obj05411 *)p)->fC8 = g_02FFFC3C;
    ((struct Obj05411 *)p)->f0 = 0;
    return 1;
}


int func_021DC914(void *p,u32 a,u32 b,char *ctx) { func_021B6108(ctx+4); func_02034A5C((int)ov90_id); func_0203133C(((struct Obj23343 *)ctx)->fCC); func_020315D4(p); return 1; }


int func_021DC93C(void *unused0, void *unused1, u8 *q, u8 *p)
{
    u32 frame;
    u8 elapsed;
    u8 i;
    void *ctx;
    int code;
    if (((struct Obj00310 *)p)->f94 == 1 && ((struct Obj00310 *)p)->f64 != 0) {
        frame = g_02FFFC3C;
        elapsed = frame - ((struct Obj00310 *)p)->fC8;
        p[196] += elapsed;
        ((struct Obj00310 *)p)->fC8 = frame;
        if (p[196] > 60) {
            ((struct Obj00310 *)p)->f64 -= 1;
            p[196] -= 60;
        }
    }
    func_021B6114(p + 4);
    switch (((struct Obj00310 *)p)->f0) {
    case 0:
        func_02034AC4((int)ov91_id);
        PROCSYS_Push(((struct Obj00310 *)p)->fCC, -1, gPartyListProcData, p + 4);
        ((struct Obj00310 *)p)->f0 = 1;
        break;
    case 1:
        if (PROCSYS_Main(((struct Obj00310 *)p)->fCC) == 0) ((struct Obj00310 *)p)->f0 = 2;
        break;
    case 2:
        func_02034A5C((int)ov91_id);
        if (((struct Obj00310 *)p)->f44 == 1) {
            p[171] = ((struct Obj00310 *)p)->f40;
            ((struct Obj00310 *)p)->f0 = 3;
        } else {
            ((struct Obj06506 *)q)->f28 = 0;
            ((struct Obj00310 *)p)->f0 = 6;
        }
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            if (p[77 + i] != 0) {
                void *mon;
                mon = func_0201AB28(((struct Obj06506 *)q)->f4, p[77 + i] - 1);
                func_0201A98C(((struct Obj06506 *)q)->f1C, mon);
            }
        }
        ((struct Obj00310 *)p)->f0 = 7;
        break;
    case 7:
        ctx = func_020399A8();
        code = POKE_REGULATION_GetDataSize();
        if (func_0203D3F8((u32)ctx, 255, 0x2f00, code, *(u32 *)&((struct Obj06506 *)q)->f1C, 0, 0, 1) != 0) {
            func_02039C68((struct Link *)func_020399A8(), 20, 47);
            ((struct Obj00310 *)p)->f0 = 8;
        }
        break;
    case 8:
        if (func_02039CB4((struct Link *)func_020399A8(), 20, 47) != 0) return 1;
        break;
    case 3:
        func_02034AC4((int)ov131_id);
        PROCSYS_Push(((struct Obj00310 *)p)->fCC, -1, gPokeStatusProcData, p + 156);
        ((struct Obj00310 *)p)->f0 = 4;
        break;
    case 4:
        if (((struct Obj00310 *)p)->f94 == 1 && ((struct Obj00310 *)p)->f64 == 0) ((struct Obj00310 *)p)->fC0 = 1;
        if (func_0200FB24() != 0) ((struct Obj00310 *)p)->fC0 = 1;
        if (PROCSYS_Main(((struct Obj00310 *)p)->fCC) == 0) ((struct Obj00310 *)p)->f0 = 5;
        break;
    case 5:
        func_02034A5C((int)ov131_id);
        ((struct Obj00310 *)p)->f40 = p[171];
        ((struct Obj00310 *)p)->f0 = 0;
        break;
    }
    if (func_0203CD98() != 0 && ((struct Obj00310 *)p)->f0 != 1 && ((struct Obj00310 *)p)->f0 != 2 && ((struct Obj00310 *)p)->f0 != 4 && ((struct Obj00310 *)p)->f0 != 5) {
        if (DWC_RAPCOMMON_HandleNetError(1, 1) != 0) {
            ((struct Obj06506 *)q)->f28 = 1;
            return 1;
        }
    }
    return 0;
}


void func_021DCB48(Args_021DC914 *p, void *unused, Output *out)
{
    u8 *a;
    void *b;
    u8 i;
    a = p->a;
    b = func_02012EBC(p->save);
    out->party = p->party;
    func_0201A2A8(a, out->party);
    out->f4 = 0;
    out->f8 = 0;
    out->fC = (u32)func_0200873C(b);
    out->f10 = 0;
    out->f30 = 0;
    out->f34 = 26;
    out->a = a;
    switch (a[0xba]) {
    case 0:
        out->f38 = 0;
        out->f64 = 1;
        break;
    case 1:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 2:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 3:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 4:
        out->f38 = 2;
        out->f64 = 2;
        break;
    }
    out->f44 = 0;
    out->f46 = 0;
    out->f48 = 0;
    out->f3C = 0;
    out->f40 = 0;
    for (i = 0; i < 6; i++) out->marks[i] = 0;
    out->f50 = 0;
    out->f58 = 0;
    out->f54 = 0;
    out->f74 = p->f10;
    out->f78 = p->f8;
    out->f7C = p->fC;
    out->f8C = a[184];
    if (a[185] != 0) {
        out->f90 = 1;
        out->f60 = a[185];
    } else {
        out->f90 = 0;
        out->f60 = 0;
    }
    out->f94 = 0;
    func_02034AC4((int)ov90_id);
    func_021B6100((u8 *)out);
}
