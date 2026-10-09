/*
 * file:     fldmmdl_p02.c
 * unit:     yes
 * function: func_0216C2FC, func_0216C44C, func_0216C484, func_0216C538, func_0216C640, func_0216C680, func_0216C6E8, func_0216C7FC, func_0216C860, func_0216C888, func_0216C8B0, func_0216C8CC, func_0216C978, func_0216C9CC, func_0216C9F4, func_0216CAA8, func_0216CAD4, func_0216CAF4, func_0216CB48, func_0216CC30, func_0216CC40, func_0216CC58, func_0216CCB0, func_0216CCCC, func_0216CCDC, func_0216CD30
 * address:  0x0216C2FC
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
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020114D0  0x020114D0  thumb
 *   func_02011558  0x02011558  thumb
 *   func_0216C270  0x0216C270  thumb  ov010
 *   func_0216C280  0x0216C280  thumb  ov010
 *   func_0216C2A4  0x0216C2A4  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021F3714  0x021F3714  thumb  ov050
 *   func_021F37B8  0x021F37B8  thumb  ov050
 *   func_021F3758  0x021F3758  thumb  ov050
 *   func_021F3808  0x021F3808  thumb  ov050
 *   func_021F3744  0x021F3744  thumb  ov050
 *   func_021F3788  0x021F3788  thumb  ov050
 *   func_021BE92C  0x021BE92C  thumb
 *   func_021D2D50  0x021D2D50  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C58 0x02188C58 thumb ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200B400  0x0200B400  thumb
 *   func_021CBD08  0x021CBD08  thumb  ov021
 *   func_0216E8CC  0x0216E8CC  thumb  ov010
 *   func_02191388  0x02191388  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   sub_02045B38   0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021B09D8  0x021B09D8  thumb
 *   func_021B09EC  0x021B09EC  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_02012EFC  0x02012EFC  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_020146F8  0x020146F8  thumb
 *   id_00000045    0x00000045  data  a1
 *   d_021BA650     0x021BA650  data  a4 ov069
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02031324  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02031330  0x02031330  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D594  0x0203D594  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D5A0  0x0203D5A0  arm
 *   func_02031348  0x02031348  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   id_0000005D    0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  a4 ov093
 *   d_021EFDAC     0x021EFDAC  data  a4 ov026
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_02172548     0x02172548  data  ov010  a4
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_02029C00  0x02029C00  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021CBD84   0x021CBD84  thumb  ov021
 *   sub_020122C0   0x020122C0  thumb
 *   sub_020124E8   0x020124E8  thumb
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02030734  0x02030734  arm
 *   func_0216E280  0x0216E280  thumb  ov010
 *   d_02172B48     0x02172B48  data  ov010  a1
 *   func_0216E290  0x0216E290  thumb  ov010
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0216D4DC  0x0216D4DC  thumb  ov010
 *   func_02030DA4  0x02030DA4  arm
 *   func_02049238  0x02049238  arm
 *   func_0216D4E4  0x0216D4E4  thumb  ov010
 */
#include "../../matched/include/Obj05905.h"
#include "../../matched/include/Obj02353.h"
#include "../../matched/include/Obj12397.h"
#include "../../matched/include/Obj12055.h"
#include "../../matched/include/Obj17769.h"
#include "../../matched/include/Obj07205.h"
#include "../../matched/include/Obj09165.h"
#include "../../matched/include/Obj04949.h"
#include "../../matched/include/Obj12056.h"
#include "../../matched/include/Obj02669.h"
#include "../../matched/include/Obj09166.h"

struct Evt;
struct IcaAnime;
struct Obj00020;
struct Desc;
struct Obj;
struct BigObj;
struct Ctx;
struct Blk37;
struct S;
struct U16Vec;
struct Actor;
struct MsgBank;
struct Rec;
struct Ent;
struct RecSlot;
struct S020314B8;
struct S020315D4;
struct Entry;
struct Big;
struct Sub020071CCCtrl;
struct Q;
struct Buf3FC;
struct Rec94;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32_0216C2FC;

typedef s32_0216C2FC fx32_0216C2FC;

typedef struct VecFx32 {
    fx32_0216C2FC x;
    fx32_0216C2FC y;
    fx32_0216C2FC z;
} VecFx32;

typedef struct Param {
    u16 f00;            /* 0x00 */
    u16 f02;            /* 0x02 */
    u16 f04;            /* 0x04 */
    u16 f06;            /* 0x06 */
    u16 f08;            /* 0x08 */
    u16 f0a;            /* 0x0A */
    u16 f0c;            /* 0x0C */
    u8 f0e;             /* 0x0E */
    u8 f0f;             /* 0x0F */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
} Param;

typedef struct Work_0216C2FC {
    u16 f00;            /* 0x00 */
    void *sys;          /* 0x04 */
    void *field;        /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
} Work_0216C2FC;

typedef struct Work_0216C44C Work_0216C44C;

typedef struct SummaryArgs {
    void *party;        /* 0x08 */
    u32 f04;
    void *p;            /* 0x10 */
    u8 f0c;             /* 0x14 */
    u8 f0d;             /* 0x15 */
    u8 count;           /* 0x16 */
    u8 pad0f;
    u8 f10;             /* 0x18 */
    u8 pad11[7];
    void *f18;          /* 0x20 */
    u8 pad1c[0xC];
} SummaryArgs;

typedef struct PartyArgs {
    void *party;        /* 0x30 */
    u8 pad04[0x10];
    void *f14;          /* 0x44 */
    u8 pad18[0x1C];
    u32 f34;            /* 0x64 */
    u32 f38;            /* 0x68 */
    u8 pad3c[0x5C];
} PartyArgs;

typedef struct PartyTaskWork {
    void *sys;          /* 0x00 */
    void *q;            /* 0x04 */
    SummaryArgs sum;    /* 0x08 */
    PartyArgs pa;       /* 0x30 */
    void *outC8;        /* 0xC8 */
    void *outCC;        /* 0xCC */
    void *outD0;        /* 0xD0 */
    u8 padD4[4];
} PartyTaskWork;

typedef struct PartyCaller {
    u8 pad00[9];
    u8 kind;            /* 0x009 */
    u8 pad0A[0x72];
    u8 f7c[6];          /* 0x07C */
    u16 f82;            /* 0x082 */
    u16 f84;            /* 0x084 */
    u8 pad86[0x7C8 - 0x86];
    void *party;        /* 0x7C8 */
} PartyCaller;

typedef struct S { char p0[9]; unsigned char k; char p1[0x7CC - 10]; int f; } S;

typedef struct Spawn {
    void *sys;          /* 0x00 */
    u8 pad04[4];
    VecFx32 pos;        /* 0x08 */
    void *obj;          /* 0x14 */
    void *name;         /* 0x18 */
    u16 id;             /* 0x1C */
} Spawn;

typedef u32 (*TaskFn)(void *task, u32 *state, Spawn *work);

typedef signed int     s32_0216C8CC;

typedef int            s32_0216CB48;

typedef s32_0216CB48            fx32_0216C8CC;

typedef struct Work {
    void   *owner;      /* 0x00 */
    u32     field04;    /* 0x04 */
    VecFx32 pos;        /* 0x08 */
    u32     field14;    /* 0x14 */
    void   *field18;    /* 0x18 */
} Work;

typedef signed int     s32_0216CC40;

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

extern int func_02188D2C(int *);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_020114D0(u32 heap, u32 a1, u32 a2);
extern void func_02011558(struct IcaAnime *p);
extern int func_0216C270(Work_0216C2FC *w);
extern void *func_0216C280(void *p);
extern void func_0216C2A4(Work_0216C2FC *w);
extern void func_02163E58(void *a, VecFx32 *v, fx32_0216C2FC *y);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021F3714(int *p);
extern void func_021F37B8(int a);
extern int func_021F3758(int *p);
extern int func_021F3808(int *p);
extern void func_021F3744(int *p);
extern void func_021F3788(int *p);
extern void *func_021BE92C(void *, void *, u32, u32, u32, u32, u32);
extern void *func_021D2D50(void *sys, Param *p);
extern void *func_021A3074(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern int func_02006148(u32 a0);
extern void func_020061F8(int i);
extern void func_020061E4(u32 se);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern struct Desc *func_020122C0(void *, void *, void *, unsigned int);
extern void *func_020124E8(struct Obj *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *);
extern void *func_021BE8D4(void *, void *, u32, u32);
extern int func_020144DC(int, int);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *a0);
extern void func_02082D44(void *, void *, int);
extern int func_020307B0(void *);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_0201A354(int a, int b);
extern void *func_0200CA1C(void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern void func_0200B400(u32 heap);
extern u32 func_021CBD08(u8 *p, int a);
extern int func_0216E8CC(int, int, int);
extern int func_02191388();
extern void func_021914CC(struct S *s);
extern u32 func_020362DC(void);
extern int func_021912D8(u32);
extern int func_021912F8();
extern int func_02045808();
extern u32 func_02188C54(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DE94(void *p, u32 id);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u32 func_0218EC2C(u8 *p);
extern void func_021B09D8(VecFx32 *, VecFx32 *, void *, void *, void *);
extern void func_021B09EC(int, int *, int *);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void *func_02012EFC(void **p);
extern int func_0200DF40(struct RecSlot *p);
extern u8 func_0200DF4C(struct RecSlot *p);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern int func_0203159C();
extern void *func_02031324(int a0);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern unsigned int func_02031330(void *p);
extern int func_02034AC4(s32_0216C8CC handle);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern void func_0203D594(int, int);
extern u32 func_0200FB24(void);
extern int func_0203D5A0(int, int);
extern void func_02031348(int, int, char *, int);
extern void func_0203A5E4(u32 key);
extern void func_02034A5C(s32_0216C8CC handle);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_02161824(void *a, void *b);
extern void *func_02029BCC(void *a, u32 b);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int);
extern int func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern void *func_02029C00(void *a);
extern void *func_02029CC0(void *a);
extern void *func_021CBD84(void *a);
extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern void *sub_020124E8(struct Obj *p);
extern void *func_0216DEE0(void *a0);
extern int func_021B0A40(u32 a, struct Q *q);
extern void *func_02012EBC(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern void *func_0215A5DC(void *a0);
extern u8 *func_02012EC4(struct Big *p);
extern s32_0216CC40 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0216E280(int a0, int a1);
extern int func_0216E290(char *);
extern u32 func_02030CB0(u32 idx);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_020490F4(u32, u32);
extern void func_0216D4DC(void *, int);
extern int func_02030DA4();
extern void func_02049238(void *arc);
extern u32 *func_0216D4E4(u32 *p, u32 v);
int func_0216C2FC(void *evt, u32 *state, Work_0216C2FC *w);
void *func_0216C44C(void *a,void *b);
int func_0216C484(int a, int *st, int *o);
void *func_0216C538(PartyCaller *c, void *sys, u8 useOwn);
void func_0216C640(S *a, int b, int c);
int func_0216C680(int a, int *st, int *o, u32 a3);
void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir);
int func_0216C7FC(int a, int *st, int *o);
void *func_0216C860(void *a);
int func_0216C888(int a0, int a1, int a2);
int func_0216C8B0(void *a, int b, int c, void **d);
int func_0216C8CC(int a, int *st, int *o, int *x);
int func_0216C978(int a, int *st, int *o);
void *func_0216C9CC(void *a,void *b,void *c);
int func_0216C9F4(int a, int *st, int *o);
void *func_0216CAA8(void *a,void *b,void *c,void *d);
void func_0216CAD4(void *a0, void *a1, void *a2);
int func_0216CAF4(int a0, int a1, int a2);
void *func_0216CB48(void *owner, int idx, u8 arg);
int func_0216CC30(int a0, int a1);
int func_0216CC40(void *a);
char *func_0216CC58(int a, int b, int c);
int func_0216CCB0(int a0);
void func_0216CCCC(Obj *o);
void func_0216CCDC(char *a, int b, int c, int d, int e, int f);
void func_0216CD30(u32 *a0, int a1);
extern char d_021BA650[];
extern char id_00000045[];
extern char id_0000005D[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_02172548[];
extern char d_02172B48[];




/*
 * Seven-state proc of a field event in ov010: animate the actor until it
 * lands on the grid, push the result screen with a fixed Param, then
 * settle the ov050 gimmick and drop the object back to the ground height.
 * First draft; the 0x021F37xx callees are declared ov050, the only
 * overlay that labels all six.
 */
int func_0216C2FC(void *evt, u32 *state, Work_0216C2FC *w){
    Param p;
    VecFx32 v;
    fx32_0216C2FC y;
    int done;
    void *q;
    void *a;

    func_02188D2C(w->field);
    switch (*state) {
    case 0:
        w->anim = func_020114D0(w->f00, 0x9D, 0x19);
        func_0216C280(w);
        func_0216C2A4(w);
        func_0218F0A8(w->f0c);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(w->f0c) == 0)
            (*state)++;
        break;
    case 2:
        func_021F3714(w->field);
        func_021F37B8((int)w->field);
        func_02012374(evt, func_021BE92C(w->sys, w->field, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 3:
        done = func_0216C270(w);
        if (done == 0) {
            func_0216C280(w);
            func_0216C2A4(w);
        }
        if (done != 0) {
            func_02011558(w->anim);
            func_020061F8(func_02006148(1953));
            func_020061E4(1775);
            p.f00 = 2;
            p.f02 = 0;
            p.f10 = 3;
            p.f0f = 2;
            p.f0e = 2;
            p.f14 = 0;
            p.f04 = 0;
            p.f06 = 1;
            p.f08 = 0;
            p.f0a = 0;
            p.f0c = 2;
            func_02012374(evt, func_021D2D50(w->sys, &p));
            (*state)++;
        }
        break;
    case 4:
        if (func_021F3758(w->field) && func_021F3808(w->field)) {
            func_021F3744(w->field);
            func_021F3788(w->field);
            (*state)++;
        }
        break;
    case 5:
        q = func_02188CB4(w->field);
        a = func_021A3074(q);
        func_021A3038(q, &v);
        func_02163E58(a, &v, &y);
        v.y = y;
        func_021A3044(q, &v);
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}





void *func_0216C44C(void *a,void *b) {
    void *t; u8 *p;
    t=func_020122C0(a,0,(void *)func_0216C2FC,0x14); p=func_020124E8(t);
    ((struct Obj05905 *)p)->f0=func_02188C84(b); ((struct Obj05905 *)p)->f4=a; ((struct Obj05905 *)p)->f8=b;
    ((struct Obj05905 *)p)->fC=func_02188C58(b); ((struct Obj05905 *)p)->f10=0; return t;
}






int func_0216C484(int a, int *st, int *o)
{
    int x = o[0];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, (void *)o[1], 0, 0));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, o[1]));
        (*st)++;
        break;
    case 2:
        func_02012374((struct Evt *)a, func_02014910((char *)x, o[1], (int)((char *)o + 0x30), (int)((char *)o + 8)));
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, (void *)o[1], 0, 0, 1, 0, 0));
        func_02082D44((char *)o + 0x79, ((struct Obj02353 *)o)->fD0, 6);
        **(short * *)&((struct Obj02353 *)o)->fCC = o[0x6c / 4];
        **(short * *)&((struct Obj02353 *)o)->fC8 = o[0x70 / 4];
        func_020307B0((void *)o[0x44 / 4]);
        (*st)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}






/*
 * Starts the func_0216C484 task over a 0xD8-byte work: points it at the
 * caller's result fields, picks the party (the player's, or the one at
 * +0x7C8 when `useOwn` is set), and fills the party-screen and summary
 * argument blocks; the screen mode (0x14, 0x15 or 0x16) follows the
 * caller's kind at +9.
 *
 * MATCH (2026-09-28 tree_ov010_4; levers: declaration order q, task, p
 * for the frame slots, the summary block pointer formed before the
 * func_0200CA1C call). The one wildcard is arm9 0x0201A354, an unlabelled
 * Thumb thunk (`movs r0, #0x69; bx` to 0x02048F60) inside the listing's
 * ARM data run: a seed for the ARM9 session.
 */
void *func_0216C538(PartyCaller *c, void *sys, u8 useOwn)
{
    void *q;
    void *task;
    void *p;
    PartyTaskWork *w;
    void *party;
    PartyArgs *pa;
    SummaryArgs *sum;
    void *h;
    u32 mode;
    u32 sel;

    p = func_020120F4(sys);
    q = func_0201210C(sys);
    task = func_020122C0(sys, 0, func_0216C484, sizeof(PartyTaskWork));
    w = func_020124E8(task);
    w->sys = sys;
    w->q = q;
    w->outD0 = c->f7c;
    w->outCC = &c->f82;
    w->outC8 = &c->f84;
    if (useOwn == 0)
        party = func_02012934(p);
    else
        party = c->party;
    mode = 0x14;
    sel = 0;
    pa = &w->pa;
    MI_CpuFill8(pa, 0, sizeof(PartyArgs));
    pa->party = party;
    switch (c->kind) {
    case 1:
    case 6:
        mode = 0x15;
        sel = 1;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        mode = 0x16;
        sel = 2;
        break;
    }
    pa->f14 = func_0201A354(mode, 4);
    pa->f34 = 0x16;
    pa->f38 = sel;
    sum = &w->sum;
    h = func_0200CA1C(p);
    MI_CpuFill8(sum, 0, sizeof(SummaryArgs));
    sum->party = party;
    sum->f0c = 1;
    sum->count = func_0201AA18(party);
    sum->f0d = 0;
    sum->f10 = 0;
    sum->p = p;
    sum->f18 = (void *)func_0200CA38(h);
    return task;
}






/*
 * lever: The result of func_021CBD08 remains live in r2 and is the third argument of func_0216E8CC.
 *
 * DIFF: original keeps the call result in r2 (adds r2,r0) and loads the 0x7CC offset into r0;
 * ours loads the offset into r1 and stores r0. Tried a local, a struct field, unsigned char.
 */
void func_0216C640(S *a, int b, int c)
{
    int t;
    func_0200B400(4);
    t = func_021CBD08((u8 *)a, b);
    a->f = t;
    if (a->k == 3 || a->k == 8) {
        func_0216CAD4(a, (void *)b, (void *)c);
        return;
    }
    func_0216E8CC(b, c, t);
}






int func_0216C680(int a, int *st, int *o, u32 a3)
{
    switch (*st) {
    case 0:
        if (!func_02191388((u32 *)o[5]))
            break;
        (*st)++;
    case 1:
        func_021914CC((struct S *)o[5]);
        if ((func_020362DC() & 3) == 0)
            break;
        func_020061E4(0x547);
        func_021912D8(o[5]);
        (*st)++;
        break;
    case 2:
        if (func_021912F8(o[5], (u32)st, (u32)o, a3) == 1) {
            func_02045808((struct U16Vec *)o[6]);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * unit_02045C44.c omits func_02045CAC from function:. Singleton TU split
 * leaves this caller OUT. No overlay leaves filed.
 * EXACT 344 bytes through the ov070 blocker evidence; not recompiled here.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * lever: task, ctx, x, proc declaration order restores pointer spill slots.
 */
void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir)
{
    VecFx32 ofs;
    u32 a;
    u32 b;
    void *task;
    void *ctx;
    void *x;
    void *proc;
    Spawn *t;
    void *bank;
    void *m;
    u16 n;

    ctx = func_020120F4(sys);
    proc = func_0201210C(sys);
    x = (void *)func_02188C54(proc);
    task = func_020122C0(sys, 0, func_0216C680, 0xD8);
    t = func_020124E8(task);
    t->sys = sys;
    t->id = id;
    if (*(u16 *)((u32)d + 0xA0 + idx * 0x120) == 0xFFFF) {
        t->name = func_020457B0(0x300, 4);
        bank = sub_02045B38(0, 2, 0xB8, 4);
        n = *(u16 *)((u32)d + 0xA2 + idx * 0x120);
        if (n >= 0x3AE)
            n = 0;
        func_02045CAC(bank, n, t->name);
        func_02045C04(bank);
    } else {
        t->name = func_0202435C((u16 *)((u32)d + 0xA0 + idx * 0x120), 4);
    }
    func_0216D88C(func_0216DE94((void *)func_02012964(ctx), t->id), &t->pos);
    m = func_02188C58(proc);
    func_021B09D8(&t->pos, &ofs, (void *)(func_0218EC2C(m)), (void *)m, (void *)dir);
    t->pos.x += ofs.x;
    t->pos.y += ofs.y;
    t->pos.z += ofs.z;
    func_021B09EC(dir, (int *)(&a), (int *)(&b));
    t->obj = func_0219129C(x, a, (u32)(&t->pos), (u32)t->name, 0, b);
    return task;
}






/*
 * blockers: func_02012EFC (unlabelled arm9 leaf, no witness), id_00000045 (pooled small
 * constant, a symbol; no witness), d_021BA650 (pointer into another overlay, no witness)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C7FC(int a, int *st, int *o)
{
    int t;
    switch (*st) {
    case 0:
        o[2] = (int)func_020120F4((const struct Ctx *)o[1]);
        t = (int)func_02012EFC((void **)o[2]);
        o[3] = func_0200DF40((struct RecSlot *)t);
        o[4] = func_0200DF4C((struct RecSlot *)t);
        func_02012374((struct Evt *)a, func_020146F8((char *)o[1], o[0], (int)id_00000045, (int)d_021BA650, (int)(&o[2])));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}





void *func_0216C860(void *a) {
    void *v; void *t; void **p;
    v=func_0201210C(a); t=func_020122C0(a,0,(void *)func_0216C7FC,0x14); p=func_020124E8(t);
    p[1]=a; ((struct Obj12397 *)p)->f0=v; return t;
}






int func_0216C888(int a0, int a1, int a2)
{
    int t4;

a2 = 1;
t4 = a0 + 0;
a0 = 1;
a1 = 0x76;
a2 = a2 << 0xe;
    func_0203064C(a0, a1, a2);
loc_0216C898:
a0 = t4 + 0;
a1 = 4;
a2 = 0x76;
    a0 = func_0203159C(a0, a1, a2);
loc_0216C8A2:
t4 = a0 + 0;
a0 = 0x76;
    a0 = (int)func_02031324(a0);
loc_0216C8AA:
((struct Obj12055 *)((char *)t4))->f0 = a0;
a0 = 1;
    return a0;}





/*
 * extent: zero alignment halfword at 0x0216C8CA, then labelled 0x0216C8CC.
 */
int func_0216C8B0(void *a, int b, int c, void **d) {
    func_0203133C(*d); func_020315D4(a); func_020306F0(0x76); return 1;
}




/*
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C8CC(int a, int *st, int *o, int *x)
{
    int r = func_02031330((void *)x[0]);
    switch (*st) {
    case 0:
        func_02034AC4((s32_0216C8CC)id_0000005D);
        func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
        func_0203D594((int)func_020399A8(), 0xc8);
        *st = 1;
        break;
    case 1:
        if (func_0200FB24() != 0) {
            *st = 4;
            break;
        }
        if (func_0203D5A0((int)func_020399A8(), 0xc8) == 0)
            break;
        *st = 2;
        break;
    case 2:
        func_02031348(x[0], ~0, d_021EFDAC, o[1]);
        *st = 3;
        break;
    case 3:
        if (r == 1)
            break;
        *st = 4;
        break;
    case 4:
        func_0203A5E4(0x100);
        func_02034A5C((s32_0216C8CC)id_0000005D);
        *st = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}




int func_0216C978(int a, int *st, int *o)
{
    int x = o[0];
    int *t;
    switch (*st) {
    case 0:
        t = o + 3;
        o[3] = (int)func_020120F4((const struct Ctx *)x);
        t[1] = o[1];
        t[2] = o[2];
        func_020120B4((struct IcaAnime *)x, ~0, d_02172548, t);
        (*st)++;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)x) == 0)
            return 1;
        break;
    }
    return 0;
}



void *func_0216C9CC(void *a,void *b,void *c) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)func_0216C978,0x3c); p=func_020124E8(t);
    p[0]=a; p[1]=b; p[2]=c; return t;
}




int func_0216C9F4(int a, int *st, int *o)
{
    int x = o[0];
    int y = o[1];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_02161824((void *)x, (void *)y));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, func_02029BCC((void *)x, *(unsigned short *)(o[2] + 0x18)));
        (*st)++;
        break;
    case 2:
        func_021AAABC(func_02188CE8((u8 *)y));
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)o[1]), a, 9);
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, y));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, func_0216C9CC((void *)x, (void *)o[2], (void *)o[3]));
        (*st)++;
        break;
    case 5:
        func_02012374((struct Evt *)a, func_02029C00((void *)x));
        (*st)++;
        break;
    case 6:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 7:
        func_02012374((struct Evt *)a, func_02029CC0((void *)x));
        (*st)++;
        break;
    case 8:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, (void *)y, 0, 0, 1, 0, 0));
        (*st)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}



void *func_0216CAA8(void *a,void *b,void *c,void *d) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)func_0216C9F4,0x10); p=func_020124E8(t);
    p[0]=a; p[2]=c; p[3]=d; p[1]=b; return t;
}




/*
 * unblocked: func_021CBD84 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021CBD84; the `ov021` token then resolves the site as
 *   `matched, overlay`.
 *
 * The record's far field (0x7CC) and the arm9 probe result are the last
 * two arguments of the four-argument overlay call.
 */
void func_0216CAD4(void *a0, void *a1, void *a2)
{
    int v = (int)func_021CBD84(a0);

    func_0216CAA8(a1, a2, (void *)(((struct Obj17769 *)a0)->f7CC), (void *)v);
}




int func_0216CAF4(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09165 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216CB0A;
loc_0216CB00:
    if (a0 == 1) goto loc_0216CB1C;
loc_0216CB04:
    if (a0 == 2) goto loc_0216CB2E;
loc_0216CB08:
    goto loc_0216CB42;
loc_0216CB0A:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_02191388(a0);
loc_0216CB10:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB14:
a0 = ((struct Obj09165 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09165 *)((char *)t5))->f0 = a0;
    goto loc_0216CB42;
loc_0216CB1C:
    a0 = func_020362DC();
loc_0216CB20:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_0216CB42;
loc_0216CB26:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_021912D8(a0);
loc_0216CB2C:
    goto loc_0216CB14;
loc_0216CB2E:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_021912F8(a0);
loc_0216CB34:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB38:
a0 = ((struct Obj07205 *)t4)->f18;
    a0 = func_02045808(a0);
loc_0216CB3E:
a0 = 1;
    return a0;
loc_0216CB42:
a0 = 0;
    return a0;}




/*
 * The third parameter is u8: with it declared int the body is byte-identical
 * except that the w->owner store and the next call's argument move swap
 * places (4 bytes); the u8 spill to [sp,#8] changes nothing visible but the
 * schedule.  Found by tools/permuter.py --types.  The call to arm9
 * 0x0202435C (an unlabelled two-slot wrapper) is attested by its shard.
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x02168138), so the call
 * attests as `label`.
 */
void *func_0216CB48(void *owner, int idx, u8 arg)
{
    void *sys;
    void *anm;
    void *ctx;
    void *task;
    Work *w;
    void *mdl;
    void *m2;
    void *cam;
    VecFx32 ofs;
    s32_0216CB48 b;
    s32_0216CB48 c;
    u8 *tbl;

    sys = func_020120F4(owner);
    anm = func_0201210C(owner);
    ctx = (void *)func_02188C54(anm);
    task = sub_020122C0(owner, 0, func_0216CAF4, sizeof(Work));
    w = sub_020124E8(task);
    w->owner = owner;
    mdl = (void *)func_02012964(sys);
    m2 = func_0216DEE0(mdl);
    func_0216D88C(func_0216DE94(mdl, arg), &w->pos);
    mdl = (void *)func_021B0A40((u32)m2, (struct Q *)(&w->pos));
    cam = func_02188C58(anm);
    func_021B09D8(&w->pos, &ofs, (void *)func_0218EC2C(cam), cam, mdl);
    w->pos.x += ofs.x;
    w->pos.y += ofs.y;
    w->pos.z += ofs.z;
    tbl = (u8 *)func_0200DF58(func_020071CC(func_02012EBC(sys), 0x3b), 4);
    w->field18 = func_0202435C(tbl + idx * 0x22 + 0x18, 4);
    func_020307B0(tbl);
    func_021B09EC((int)mdl, &b, &c);
    w->field14 = (u32)func_0219129C(ctx, b, (u32)(&w->pos), (u32)w->field18, 0, c);
    return task;
}




int func_0216CC30(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216CC38:
    a0 = func_0216CC40(v0);
loc_0216CC3C:
a0 = 0;
    return a0;}



/*
 * extent: zero alignment halfword at 0x0216CC56, then labelled 0x0216CC58.
 * interface: r1=0x34 is visibly supplied to the accessor despite its body only reading r0.
 */
int func_0216CC40(void *a) {
    *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(a)),0x34)=1;
}




char *func_0216CC58(int a, int b, int c)
{
    char *p = (char *)func_02030734(a, 0x48, 1, d_02172B48, 0xc3);
    ((struct Obj04949 *)p)->f18 = (int)func_02030734(a, b << 8, 1, d_02172B48, 0xc4);
    ((struct Obj04949 *)p)->f4 = b;
    ((struct Obj04949 *)p)->f8 = a;
    ((struct Obj04949 *)p)->f2C = c;
    ((struct Obj04949 *)p)->fC = 0x80;
    func_0216E280((int)p, a);
    ((struct Obj04949 *)p)->f44 = (int)func_02030734(a, 0xc4 << 2, 1, d_02172B48, 0xcf);
    return p;
}




int func_0216CCB0(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216E290((char *)a0);
loc_0216CCB8:
a0 = ((struct Obj12056 *)t4)->f44;
    a0 = func_020307B0((void *)a0);
loc_0216CCBE:
a0 = ((struct Obj12056 *)t4)->f18;
    a0 = func_020307B0((void *)a0);
loc_0216CCC4:
a0 = t4 + 0;
    a0 = func_020307B0((void *)a0);
loc_0216CCCA:
    return a0;}




/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * clears the 0x310-byte buffer at +0x44, a tail call through a pool word.
 * Callee of ov020 func_021857C0.
 */
void func_0216CCCC(Obj *o)
{
    MI_CpuFill8(o->f44, 0, 0x310);
}




/*
 * lever: The allocation result is the second argument to func_02030CBC; its r1 live range orders the halfword reload.
 *
 * DIFF: original moves the alloc result to r1 (adds r1,r0) and stores it after the ldrh reload
 * (+2 B, pool shifts 4). Tried a result local and a halfword local.
 */
void func_0216CCDC(char *a, int b, int c, int d, int e, int f)
{
    int t;
    unsigned short h;
    ((struct Obj02669 *)a)->f34 = e;
    ((struct Obj02669 *)a)->fA = b;
    ((struct Obj02669 *)a)->f30 = c;
    ((struct Obj02669 *)a)->f3C = d;
    t = (int)func_02030734(b, func_02030CB0(((struct Obj02669 *)a)->f4), 0, d_02172B48, 0x109);
    h = ((struct Obj02669 *)a)->f4;
    ((struct Obj02669 *)a)->f1C = t;
    ((struct Obj02669 *)a)->f20 = (int)func_02030CBC(h, (struct Ctx *)t);
    ((struct Obj02669 *)a)->f10 = (int)func_020490F4(0x31, b);
    ((struct Obj02669 *)a)->f38 = f;
    func_0216D4DC(a, 0x10);
}




void func_0216CD30(u32 *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
a0 = (u32 *)(((struct Obj09166 *)t4)->f20);
    a0 = (u32 *)func_02030DA4(a0);
loc_0216CD3A:
a0 = (u32 *)(((struct Obj09166 *)t4)->f1C);
    a0 = (u32 *)func_020307B0(a0);
loc_0216CD40:
a0 = (u32 *)(((struct Obj09166 *)t4)->f10);
    func_02049238((void *)a0);
loc_0216CD46:
a0 = (u32 *)(t4 + 0);
a1 = 0x10;
    a0 = (u32 *)func_0216D4E4(a0, a1);
loc_0216CD4E:
    return;}
