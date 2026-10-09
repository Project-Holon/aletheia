/*
 * file:     fld_trade_p02.c
 * unit:     yes
 * function: func_021CD050, func_021CD184, func_021CD1AC, func_021CD1C8, func_021CD1F0, func_021CD204, func_021CD214, func_021CD2A4, func_021CD348, func_021CD3A4, func_021CD400, func_021CD440, func_021CD48C, func_021CD5A4, func_021CD60C, func_021CD624, func_021CD688, func_021CD6D0, func_021CDAB8, func_021CDD5C, func_021CDF18, func_021CE12C, func_021CE1F4, func_021CE24C, func_021CE2BC, func_021CE36C, func_021CE3D8
 * address:  0x021CD050
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
 *   func_021CD004  0x021CD004  thumb  ov021
 *   func_02190788  0x02190788  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190764  0x02190764  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_021CCBE0  0x021CCBE0  thumb  ov021
 *   func_021CCE48  0x021CCE48  thumb  ov021
 *   func_021CD038  0x021CD038  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DE5D4  0x021DE5D4  data  ov021
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204932C  0x0204932C  arm
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0204ED4C  0x0204ED4C  arm
 *   func_0204ED80  0x0204ED80  arm
 *   func_0204ED8C  0x0204ED8C  arm
 *   func_0204ED98  0x0204ED98  arm
 *   func_0204EDA4  0x0204EDA4  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012A54  0x02012A54  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0200C1F4  0x0200C1F4  thumb
 *   func_0200C20C  0x0200C20C  thumb
 *   func_02045924  0x02045924  arm
 *   d_021DB44C     0x021DB44C  data  a1
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov075  a4
 *   func_0200C1F8  0x0200C1F8  thumb
 *   func_02027198  0x02027198  thumb
 *   func_0200C210  0x0200C210  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_02045838  0x02045838  arm
 *   func_02165844  0x02165844  thumb  ov010
 *   d_021DB450  0x021DB450  data  ov021  a2
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02045EC0  0x02045EC0  arm
 *   func_02008494  0x02008494  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_021CF164  0x021CF164  thumb  ov021
 *   func_0203D798  0x0203D798  arm
 *   func_0203D650  0x0203D650  arm
 *   d_021DE5E8     0x021DE5E8  data   ov021  a1
 *   func_021CE760  0x021CE760  thumb  ov021
 *   func_021CE81C  0x021CE81C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_021CF17C  0x021CF17C  thumb  ov021
 *   func_021CEA84  0x021CEA84  thumb  ov021
 *   func_021CEAB0  0x021CEAB0  thumb  ov021
 *   d_021DB498  0x021DB498  data
 *   func_021CE7AC  0x021CE7AC  thumb  ov021
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_021CF1AC  0x021CF1AC  thumb  ov021
 *   func_021CE41C  0x021CE41C  thumb  ov021
 *   func_021CE78C  0x021CE78C  thumb  ov021
 *   func_021CE73C  0x021CE73C  thumb  ov021
 *   func_021CEA28  0x021CEA28  thumb  ov021
 *   func_021CE52C  0x021CE52C  thumb  ov021
 *   func_021CE5AC  0x021CE5AC  thumb  ov021
 *   func_021CF2F0  0x021CF2F0  thumb  ov021
 *   func_021CE6F0  0x021CE6F0  thumb  ov021
 *   func_021CF3B0  0x021CF3B0  thumb  ov021
 *   func_021CF378  0x021CF378  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_021CF12C  0x021CF12C  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D01C  0x0203D01C  arm
 *   func_020392B8  0x020392B8  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021CEB64  0x021CEB64  thumb  ov021
 *   func_021CEB20  0x021CEB20  thumb  ov021
 *   func_0203D010  0x0203D010  arm
 *   func_021CEB84  0x021CEB84  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021CF068  0x021CF068  thumb  ov021
 *   func_021CF0F4  0x021CF0F4  thumb  ov021
 *   func_021CF32C  0x021CF32C  thumb  ov021
 *   func_021CE9A0  0x021CE9A0  thumb  ov021
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   data_021DB498  0x021DB498  data   ov021
 *   func_021CF220  0x021CF220  thumb  ov021
 *   func_021CF288  0x021CF288  thumb  ov021
 *   func_021CF3FC  0x021CF3FC  thumb  ov021
 *   func_021CE8B0  0x021CE8B0  thumb  ov021
 *   func_021CE8F4  0x021CE8F4  thumb  ov021
 *   func_021CE934  0x021CE934  thumb  ov021
 *   func_021CE84C  0x021CE84C  thumb  ov021
 *   func_021CE3E8  0x021CE3E8  thumb  ov021
 */
#include "../../matched/include/Obj18362.h"
#include "../../matched/include/Obj01220.h"
#include "../../matched/include/Obj03150.h"
#include "../../matched/include/Obj06099.h"
#include "../../matched/include/Obj02098.h"
#include "../../matched/include/Obj00011.h"
#include "../../matched/include/Obj02098.h"
#include "../../matched/include/Obj00011.h"

#define U32(o) (*(u32 *)(p + (o)))
struct MsgBank;
struct WordSet;
struct U16Vec;
struct ArcFile;
struct Big;
struct BigObj;
struct Blk34;
struct Ctx;
struct Desc;
struct Strbuf;
struct Sub0200852CObj;
struct Obj_021CD1AC;
struct Evt;
struct Obj00020;
struct Fx;
struct Obj2;
struct Rec;
struct Entry_021CD050;
struct Link;
struct Req;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 padE[0xA0 - 0xE];
    u32 fA0;
    u32 fA4;
    u32 fA8;
    u32 fAC;
    u32 fB0;
    u32 fB4;
    u32 fB8;
} Obj_021CD050;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
} Obj_021CD184;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    void *arc;
} Holder_021CD1C8;

typedef struct {
    void *arc;
    u32 f4;
} Holder_021CD204;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u16 f20;
    u8 pad22[0x12];
    u32 f34;
    u8 pad38[4];
    u32 f3c;
    u8 pad40[4];
    u32 f44;
    u16 f48;
    u8 pad4a[2];
    u32 f4c;
} Obj_021CD1AC;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 r;
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u8 f30[0x51B - 0x30];
    u8 f51B;
    u8 f51C;
    u8 f51D;
    u8 f51E;
    u8 f51F;
    u8 f520;
    u8 pad521[0x528 - 0x521];
    u16 f528;
    u8 pad52A[0x554 - 0x52A];
    u8 f554[0x572 - 0x554];
    signed char f572;
    u8 pad573;
    u16 f574;
    u8 pad576[0x580 - 0x576];
} Work_021CD050;

typedef struct {
    u8 pad[0x26];
    u16 f26;
} Disp;

typedef struct {
    u8 pad[0x18];
    Disp *(*f18)(u32 a);
} Sys;

typedef struct {
    u8 pad000[0x488];
    void *f488;
    void *f48c;
    void *f490;
} Obj_021CD48C;

typedef struct {
    u8  pad0[0x14];
    u32 h;              /* 0x014 */
    u8  pad18[0x14];
    u32 x2C;            /* 0x02C */
    u8  sub[0x4E4];     /* 0x030 */
    u8  x514;           /* 0x514 */
    u8  pad515[6];
    u8  x51B;           /* 0x51B */
    u8  x51C;           /* 0x51C */
    u8  x51D;           /* 0x51D */
    u8  state;          /* 0x51E */
    u8  pad51F;
    u8  x520;           /* 0x520 */
    u8  pad521[5];
    u8  x526;           /* 0x526 */
    u8  pad527[0x4C];
    u8  x573;           /* 0x573 */
    u16 x574;           /* 0x574 */
    u8  pad576[2];
    u8  x578;           /* 0x578 */
} Work_021CD6D0;

typedef struct {
    u8  pad0[8];
    u16 f8;
    u8  padA[2];
} Entry_021CD050;

typedef struct {
    u8  pad0[0x26];
    u16 f26;
} Obj_021CD050x;

typedef struct {
    u8  pad0[0x18];
    Obj_021CD050x *(*get)(u32);
} Vtbl;

typedef struct {
    u8 state;
    u8 pad1[0x2b];
} Entry_021CE2BC;

typedef struct {
    u8 pad0[0x70];
    Entry_021CE2BC ent[4];
} Mgr;

extern void func_021CD004(Obj_021CD050 *p);
extern void func_02190788(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02190764(u32 a, u16 b, u32 c, void *d, u16 e, u32 f);
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern void func_021CCBE0(u8 *s, int flag);
extern u32 func_021CCE48(u8 *s, int flag);
extern u32 func_021CD038(u32, u32, u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_020307B0(void *p);
extern void func_02049238(u32 arc);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_0207CDB8(u16 *a, u16 *b);
extern void func_0204ED4C(u8 *a0, short *a1);
extern void func_0204ED80(u8 *dst, u16 *src);
extern void func_0204ED8C(u8 *dst, u16 *src);
extern void func_0204ED98(u8 *dst, u16 *src);
extern void func_0204EDA4(u8 *dst, u16 *src);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj_021CD1AC *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern u8 *func_02012944(void *p);
extern u32 func_02012A54(const struct BigObj *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u16 *func_0200C1F4(struct Blk34 *p);
extern u16 *func_0200C20C(struct Blk34 *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0200C1F8(struct Blk34 *p, const u16 *src);
extern void func_02027198(void);
extern void func_0200C210(struct Blk34 *p, const u16 *src);
extern int func_020275C4(void *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02165844(void *v);
extern u16 func_02188C9C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u32 func_02188C54(u8 *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_021904B0(u32 a, u32 b);
extern struct Obj2 *func_02190F64(struct Fx *a, u32 b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02008494(void *src, void *dst);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_0203D7BC(u8 a0);
extern void func_021CF164(u32 a);
extern void *func_0203D798(void);
extern u32 func_0203D650(void);
extern u32 func_021CE760(u8 *p);
extern void func_021CE81C(u32 *p);
extern int func_021909BC(void *a);
extern int func_02190E40(u32 a);
extern u32 func_021904C8(struct Rec *a0);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_0203CD98(void);
extern void func_021CF17C(void);
extern void func_021CEA84(u8 *p, int n);
extern void func_021CEAB0(u8 *p);
extern void func_021CE7AC(u32 *p);
extern void func_021CE9E4(Work_021CD6D0 *p, int n);
extern void func_0203D01C(void);
extern int func_020392B8(void);
extern int func_02039ACC(void);
extern u32 func_020362DC(void);
extern struct Entry_021CD050 *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern u32 func_021CF1AC(u32 a, u32 b, u32 c);
extern void func_021CE41C(u32 *p);
extern int func_021CE78C(u32 a);
extern int func_021CE73C(Work_021CD6D0 *p);
extern void func_021CEA28(Work_021CD6D0 *p);
extern int func_0203D1B4(void);
extern int func_021CE52C(u32 *p);
extern void func_0203D1E8(u32 unused, void *arg);
extern u32 func_021CE5AC(u32 *p);
extern int func_021CF2F0(int a);
extern u32 func_0203D1A4(struct Link *p);
extern void func_021CE6F0(Work_021CD6D0 *p, int a);
extern u32 func_0203D1C0(u32 index);
extern u32 func_02080D24(int a);
extern int func_021CF3B0(int a);
extern int func_021CF378(int a);
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
extern u32 func_02190EF0(u32 *p);
extern int func_021CF12C(int a);
extern u32 func_0200FB24(void);
extern void func_021CEB64(u8 *p);
extern void func_021CEB20(u8 *p);
extern void func_0203D010(void);
extern u32 func_021CEB84(u8 *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern int func_021CF068(u8 *p);
extern void func_021CF0F4(u8 *p);
extern u32 func_021CF32C(u32 flag);
extern void func_021CE9A0(u8 *p);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u32 func_021CF220(u32 a, u32 flag, u32 c);
extern u32 func_021CF288(u32 a, u32 flag, u32 c);
extern u32 func_021CF3FC(u32 a, u32 b, int c);
extern void func_021CE8B0(u8 *p, u8 *e, int i);
extern void func_021CE8F4(u8 *p, u8 *e, int i);
extern void func_021CE934(u8 *p, u8 *e, int i);
extern int func_021CE84C(u32 *p, int n);
extern int func_021CE3E8(u8 *p, u8 *e);
void func_021CD050(Obj_021CD050 *p, void *party);
void func_021CD184(Obj_021CD184 *o, u32 sel);
int func_021CD1AC(u32 a, u32 b, u32 c, u32 d);
Holder_021CD1C8 *func_021CD1C8(u32 heap);
int func_021CD1F0(void *a);
void func_021CD204(Holder_021CD204 *h, u32 a);
void func_021CD214(u8 *s, void *o);
u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d);
int func_021CD348(int a, int *st, u8 *c);
void func_021CD3A4(u8 *a, u8 *b);
u32 func_021CD400(u32 a, int b, int c);
int func_021CD440(void *a, u16 *out);
Work_021CD050 *func_021CD48C(u32 a0, u32 a1, u32 a2, u32 a3, u32 heap, u32 a5, u32 a6, void *a7);
u32 func_021CD5A4(u32 *p);
void func_021CD60C(Obj_021CD48C *p, void *a, void *b, void *c);
void func_021CD624(u8 *p, int i, u32 a, u32 b, void *c);
u32 func_021CD688(u8 *p);
int func_021CD6D0(Work_021CD6D0 *p);
int func_021CDAB8(u8 *p);
int func_021CDD5C(u8 *p);
int func_021CDF18(u8 *p);
void func_021CE12C(u8 *p);
u8 func_021CE1F4(u8 *p);
void func_021CE24C(u8 *p);
void func_021CE2BC(u8 *p);
void func_021CE36C(u8 *p);
void func_021CE3D8(Mgr *m, int i);
extern const char d_021DE5D4[];
extern const u8 d_021DB44C[];
extern char d_021F5580;
extern unsigned char abs_id_C2[];
extern const Ent d_021DB450[];
extern u8 d_021DE5E8[];
extern Entry_021CD050 d_021DB498[];
extern u8 data_021DB498[];






void func_021CD050(Obj_021CD050 *p, void *party)
{
    void *buf1;
    void *buf2;
    int n;
    int i;
    void *mon;
    u32 v5;
    u32 v6e;
    u32 v9e;
    u32 vad;
    int x;

    func_021CD004((Obj_021CD050 *)p);
    func_02190788((u8 *)p->fB4);
    buf1 = func_020457B0(0x40, p->heap);
    buf2 = func_020457B0(0x40, p->heap);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4c, 0) != 0) {
            continue;
        }
        v5 = func_02017E1C(mon, 5, 0);
        vad = func_02017E1C(mon, 0xad, 0);
        v9e = func_02017E1C(mon, 0x9e, 0);
        v6e = func_02017E1C(mon, 0x6e, 0);
        func_02045CAC((struct MsgBank *)p->fA8, 4, buf2);
        func_0201EFA4((struct WordSet *)p->fA0, 0, v9e, 3, 0, 1);
        func_0201F250((struct WordSet *)p->fA0, buf1, buf2);
        x = i * 0x28;
        func_02190764(p->fB4, x, 0x20, buf1, 0x440, p->fB8);
        if (v6e == 2) {
            continue;
        }
        if ((v5 == 0x1d || v5 == 0x20) && vad == 0) {
            continue;
        }
        if (v6e == 0) {
            func_02190740(p->fB4, (u16)(x + 0x1f), 0x10, 5);
        } else {
            func_02190740(p->fB4, (u16)(x + 0x1f), 0x10, 6);
        }
    }
    func_02045808(buf1);
    func_02045808(buf2);
}






/*
 * Selector 0 or 1 path of func_021CCF60: applies the +4 or +8 entry, then refreshes the two per-selector views.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD184(Obj_021CD184 *o, u32 sel)
{
    func_021CD050((Obj_021CD050 *)o, sel == 0 ? o->f4 : o->f8);
    func_021CCBE0((u8 *)o, sel);
    func_021CCE48((u8 *)o, sel);
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CD1AC(u32 a, u32 b, u32 c, u32 d)
{
func_021CD038(a, b, c, d);
func_021CCBE0((u8 *)a, 2);
return func_021CCE48((u8 *)a, 2);
}










/*
 * Allocates a 0x28-byte zeroed holder on the given heap and opens archive 0xAF into its first word.
 *
 * Addresses are Black-image addresses.
 */
Holder_021CD1C8 *func_021CD1C8(u32 heap)
{
    Holder_021CD1C8 *h = func_02030734(heap, 0x28, 1, d_021DE5D4, 0x5b);
    h->arc = func_020490F4(0xaf, heap);
    return h;
}










int func_021CD1F0(void *a)
{
func_02049238(((struct Obj18362 *)((u8 *)(a)))->f0);
return func_020307B0(a);
}










/*
 * Forwards to func_0204932C with the holder's archive, the caller's argument and the holder's +4 field.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD204(Holder_021CD204 *h, u32 a)
{
    func_0204932C(h->arc, a, &h->f4);
}










void func_021CD214(u8 *s, void *o)
{
    u16 v[3];
    u16 c[4];

    v[0] = ((struct Obj01220 *)s)->f4;
    v[1] = ((struct Obj01220 *)s)->f8;
    v[2] = ((struct Obj01220 *)s)->fC;
    func_0207CDB8(v, v);
    func_0204ED4C(o, (short int *)v);
    c[3] = ((struct Obj01220 *)s)->f10 | (((struct Obj01220 *)s)->f12 << 5) | (((struct Obj01220 *)s)->f14 << 10);
    func_0204ED80(o, &c[3]);
    c[2] = ((struct Obj01220 *)s)->f16 | (((struct Obj01220 *)s)->f18 << 5) | (((struct Obj01220 *)s)->f1A << 10);
    func_0204ED8C(o, &c[2]);
    c[1] = ((struct Obj01220 *)s)->f1C | (((struct Obj01220 *)s)->f1E << 5) | (((struct Obj01220 *)s)->f20 << 10);
    func_0204ED98(o, &c[1]);
    c[0] = ((struct Obj01220 *)s)->f22 | (((struct Obj01220 *)s)->f24 << 5) | (((struct Obj01220 *)s)->f26 << 10);
    func_0204EDA4(o, &c[0]);
}










u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d)
{
    u32 h;
    Obj_021CD1AC *o;

    h = (u32)func_020122C0((void *)a, (void *)x, func_021CD348, 0x50);
    o = func_020124E8((struct Obj_021CD1AC *)h);
    o->f00 = a;
    o->f04 = (u32)func_020120F4((const struct Ctx *)a);
    o->f10 = b;
    o->f18 = d;
    o->f4c = c;
    o->f48 = 4;
    o->f08 = (u32)func_0200C0F0(func_02012EBC((struct Big *)o->f04));
    o->f0c = (u32)func_02012944((void *)o->f04);
    o->f14 = func_02012A54((const struct BigObj *)o->f04);
    o->f1c = c;
    o->f20 = func_02008550((const struct Sub0200852CObj *)o->f0c);
    o->f44 = o->f08;
    o->f34 = d_021DB44C[c - 5];
    o->f3c = (u32)func_020457B0(o->f34 + 1, o->f48);
    switch (c) {
    case 5:
        func_02045924((struct Strbuf *)o->f3c, func_0200C1F4((struct Blk34 *)o->f08));
        break;
    case 6:
        func_02045924((struct Strbuf *)o->f3c, func_0200C20C((struct Blk34 *)o->f08));
        break;
    case 7:
        break;
    }
    return h;
}










/*
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed to func_020146F8, not
 * in match.py's OVERLAY_ID_CONSUMERS; no other pool word holds 0x000000C2
 * outside this range (same blocker as pending ov021_func_021C5A54).
 */
int func_021CD348(int a, int *st, u8 *c)
{
    int r;

    switch (*st) {
    case 0:
        r = (int)func_020146F8((char *)(((struct Obj03150 *)c)->f0), ((struct Obj03150 *)c)->f10, (int)abs_id_C2, (int)(&d_021F5580), (int)(c + 0x1c));
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        func_021CD3A4(c, c + 0x1c);
        func_02045808((struct U16Vec *)(((struct Obj03150 *)c)->f3C));
        return 1;
    }
    return 0;
}










/*
 * Callee witnesses filed in wave A1 (witness lane).
 */
void func_021CD3A4(u8 *a, u8 *b)
{
    u16 *q = *(u16 * *)&((struct Obj03150 *)a)->f18;

    if (q) {
        if (((struct Obj06099 *)b)->f1C == 0)
            *q = 1;
        else
            *q = 0;
    }
    if (((struct Obj06099 *)b)->f1C == 1)
        return;
    switch (((struct Obj03150 *)a)->f4C) {
    case 5:
        func_0200C1F8((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        func_02027198();
        return;
    case 6:
        func_0200C210((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        return;
    case 7:
        func_02045838((struct U16Vec *)func_020275C4((void *)(((struct Obj03150 *)a)->f14)), (struct U16Vec *)(((struct Obj03150 *)a)->f3C));
        func_02165844((void *)(((struct Obj06099 *)b)->f20));
        return;
    }
}










u32 func_021CD400(u32 a, int b, int c)
{
    u32 i;
    const Ent *e = d_021DB450;

    for (i = 0; i < 4; i++, e++) {
        if (e->a == a && e->b <= (u32)b && b < e->b + 3 && e->c <= (u32)c && c < e->c + 3)
            return e->r;
    }
    return 0x1ab;
}










int func_021CD440(void *a, u16 *out)
{
    u16 x;
    void *o;
    u16 h;
    u16 w;

    x = func_02188C9C(a);
    o = func_021A3074(func_02188CB4(a));
    h = func_0216D83C(o);
    w = func_0216D86C(o);
    *out = func_021CD400(x, h, w);
    if (*out != 0x1ab)
        return 1;
    *out = x;
    return 0;
}









Work_021CD050 *func_021CD48C(u32 a0, u32 a1, u32 a2, u32 a3, u32 heap, u32 a5, u32 a6, void *a7)
{
    u32 t;
    Work_021CD050 *w;
    Sys *s;

    t = func_02188C54((u8 *)a1);
    w = func_02030734(heap, 0x580, 1, (const char *)d_021DE5E8, 0x179);
    w->f4 = (u32)func_0201EC64(heap);
    w->f8 = func_021904B0(t, 0x1e);
    w->f14 = (u32)func_02190F64((struct Fx *)t, w->f8);
    w->f18 = (u32)func_020457B0(0x64, heap);
    w->f1C = (u32)func_02045EC0((struct MsgBank *)w->f8, 7);
    w->f20 = (u32)func_020457B0(0x40, heap);
    if (a6 == 1) {
        w->f24 = (u32)func_02045EC0((struct MsgBank *)w->f8, 3);
    } else {
        w->f24 = (u32)func_02045EC0((struct MsgBank *)w->f8, 2);
    }
    w->f28 = (u32)func_020457B0(0x20, heap);
    w->f51C = a2;
    w->f51D = a3;
    w->f0 = a1;
    w->f51F = a5;
    w->f520 = a6;
    w->f528 = heap;
    w->f572 = -1;
    w->f574 = 0xffff;
    func_02008494((void *)a0, w->f30);
    if (a7 != 0) {
        func_02082D44(a7, w->f554, 6);
    }
    func_0203D7BC(0);
    func_021CF164((u32)w);
    if (a6 == 1) {
        w->f51B = 1;
    }
    s = func_0203D798();
    s->f18(func_0203D650())->f26 = 0x3a0b;
    return w;
}









/*
 * Addresses are Black-image addresses.
 */
u32 func_021CD5A4(u32 *p)
{
    u32 r;

    r = func_021CE760((u8 *)p);
    func_021CE81C(p);
    if (p[0x4c]) {
        func_021909BC((void *)p[0x4c]);
        p[0x4c] = 0;
    }
    func_02045808((struct U16Vec *)p[10]);
    func_02045808((struct U16Vec *)p[9]);
    func_02045808((struct U16Vec *)p[8]);
    func_02045808((struct U16Vec *)p[7]);
    func_02045808((struct U16Vec *)p[6]);
    func_02190E40(p[5]);
    func_021904C8((struct Rec *)p[2]);
    func_0201ED04((struct WordSet *)p[1]);
    if (func_0203CD98() == 1) {
        func_021CF17C();
    }
    func_020307B0(p);
    return r;
}









void func_021CD60C(Obj_021CD48C *p, void *a, void *b, void *c)
{
    p->f488 = a;
    p->f48c = b;
    p->f490 = c;
}







/*
 * ldr r3,=0x02082D44; movs r2,#0x20; bx r3) has no witness outside the range.
 * Verified C for the leaf: void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 * (verified EXACT, 12 bytes, thumb, with func_02082D44 0x02082D44 arm.)
 *
 * Addresses are Black-image addresses.
 */
void func_021CD624(u8 *p, int i, u32 a, u32 b, void *c)
{
    u8 *e;

    e = p + 0x50 + i * 0x2c;
    func_02008494((void *)a, e);
    e[0x20] = 1;
    e[0x21] = b;
    func_02082D44(c, e + 0x23, 6);
    func_021CEA84(p, (u8)i);
    func_021CEAB0(p);
    if (((struct Obj02098 *)p)->f48C) {
        (*(void (**)(u32, u32, void *))(p + 0x48c))(((struct Obj02098 *)p)->f488, a, c);
    }
}






u32 func_021CD688(u8 *p)
{
    int r;

    switch (p[0x51f]) {
    case 0:
        r = func_021CD6D0((Work_021CD6D0 *)p);
        break;
    case 1:
        r = func_021CDAB8(p);
        break;
    case 2:
        r = func_021CDD5C(p);
        break;
    case 3:
        r = func_021CDF18(p);
        break;
    }
    if (r == 1) {
        return ((struct Obj00011 *)p)->f2C;
    }
    return 0;
}




/*
 * Per-frame state machine (state byte at 0x51E, 20 cases). Closed:
 * case 8 placed after case 12 (image layout), case 1 written with the
 * `== 0` arm first, case 14 through an Entry pointer local (keeps the +8
 * out of the pool word), loop condition `(i < 4) ? 1 : 0` (branch to the
 * bottom test), `1u << i` in the x526 test only (an identical `1 << i`
 * there is CSEd across the call and spills the mask), and `1 << (u32)i` in
 * the x578 test: with the plain int promotion of i the shift is evaluated
 * before the x578 load, so `movs r0,#1` is live across the reload of the
 * spilled 0x578 offset and the reload lands in r1; the u32 count orders the
 * load first and the reload takes r0 (2026-10-02).
 */
int func_021CD6D0(Work_021CD6D0 *p)
{
    int n;
    u16 saved;
    u8 mask;
    u8 i;

    if (p->state != 0) {
        func_021CE24C((u8 *)p);
        func_021CE2BC((u8 *)p);
        func_021CE12C((u8 *)p);
    }

    switch (p->state) {
    case 0:
        func_021CE7AC((u32 *)p);
        func_021CE9E4((Work_021CD6D0 *)p, 8);
        p->state++;
        break;
    case 1:
        if (p->x520 == 0) {
            p->state = 4;
        } else {
            func_0203D01C();
            p->state++;
        }
        break;
    case 2:
        if (func_020392B8() > 1) {
            if (func_02039ACC() == 1) {
                p->state++;
            }
        } else if (func_020362DC() & 2) {
            p->state = 7;
            p->x2C = 2;
            p->state = 0x13;
        }
        break;
    case 3:
        if (func_020399B8((u8 *)((u32)(struct Entry *)func_020399A8())) == 1) {
            p->state = 4;
        }
        break;
    case 4:
        if (func_021CF1AC((u32)p->sub, 1, p->x51B) == 1) {
            p->state++;
        }
        break;
    case 5:
        func_021CE36C((u8 *)p);
        func_021CE41C((u32 *)p);
        if (func_021CE78C((u32)p) == 1) {
            n = func_021CE73C((Work_021CD6D0 *)p);
            saved = p->x574;
            p->x574 = 0xFFFF;
            if (n >= p->x51D || (n >= p->x51C && (func_020362DC() & 1))) {
                func_021CEA28((Work_021CD6D0 *)p);
                p->state = 6;
            } else if (func_020362DC() & 2) {
                p->state = 7;
            } else if (p->x520 == 0 && func_0203D1B4() <= 1) {
                p->state = 0x11;
            } else if (saved != 0xFFFF) {
                func_021CE9E4((Work_021CD6D0 *)p, saved);
            }
        }
        break;
    case 6:
        n = func_021CE52C((u32 *)p);
        if (n == 1) {
            func_0203D1E8((u32)(struct Entry *)func_020399A8(), 0);
            p->state = 9;
        } else if (n == 2) {
            if (func_021CE73C((Work_021CD6D0 *)p) >= p->x51D) {
                p->state = 7;
            } else {
                p->state = 5;
                if (func_021CE73C((Work_021CD6D0 *)p) > 1 && p->x520 == 1) {
                    p->x574 = 9;
                } else {
                    p->x574 = 8;
                }
            }
        }
        break;
    case 7:
        n = func_021CE5AC((u32 *)p);
        if (n == 1) {
            func_0203D1E8((u32)(struct Entry *)func_020399A8(), 0);
            p->state = 0xD;
        } else if (n == 2) {
            p->state = 5;
        }
        break;
    case 9:
        if (func_021CF2F0(p->x51B) == 1) {
            func_021CE6F0((Work_021CD6D0 *)p, func_0203D1A4((struct Link *)((u32)(struct Entry *)func_020399A8())));
            p->x526 = p->x514;
            func_0203D7BC(1);
            p->state = 10;
        }
        break;
    case 10:
        mask = 1 << func_0203D1A4((struct Link *)((u32)(struct Entry *)func_020399A8()));
        for (i = 0; (i < 4) ? 1 : 0; i++) {
            if (i != func_0203D1A4((struct Link *)((u32)(struct Entry *)func_020399A8())) && (p->x526 & (1u << i))) {
                if (func_0203D1C0(i) == 1) {
                    if (p->x578 & (1 << (u32)i)) {
                        mask |= (u8)(1 << i);
                    }
                } else {
                    p->state = 0xB;
                    break;
                }
            }
        }
        if (p->x526 == mask) {
            if (func_02080D24(p->x578) < p->x51C) {
                p->state = 0xB;
            } else {
                p->state = 0xC;
            }
        }
        break;
    case 11:
        if (func_021CF3B0(p->x51B) == 1) {
            p->x526 = p->x514;
            p->x2C = 2;
            p->state = 0xE;
        }
        break;
    case 12:
        if (func_021CF378(p->x51B) == 1) {
            p->x2C = 1;
            p->state = 8;
            p->x573 = func_02080D24(p->x578);
            func_02039C68((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27);
        }
        break;
    case 8:
        if (p->x573 != func_020392B8() || p->x51C > func_020392B8()) {
            if (func_021CF3B0(p->x51B) == 1) {
                p->x526 = p->x514;
                p->x2C = 2;
                p->state = 0xE;
            }
        } else if (func_02039CB4((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27) == 1) {
            Vtbl *v;

            p->x2C = 1;
            p->state = 0x13;
            v = func_0203D798();
            v->get(func_0203D650())->f26 = 0;
        }
        break;
    case 13:
        if (func_021CF3B0(p->x51B) == 1) {
            p->x526 = p->x514;
            p->x2C = 2;
            p->state = 0x10;
        }
        break;
    case 14:
        {
            Entry_021CD050 *e = &d_021DB498[p->x520];

            func_021CE9E4((Work_021CD6D0 *)p, e->f8);
        }
        p->state = 0xF;
        break;
    case 15:
        if (func_02190EF0((u32 *)p->h) == 1) {
            p->state = 0x10;
        }
        break;
    case 16:
        if (func_021CF12C(p->x526) == 0) {
            p->state = 0x13;
        }
        break;
    case 17:
        func_021CE9E4((Work_021CD6D0 *)p, 0x14);
        p->state = 0x12;
        break;
    case 18:
        if (func_02190EF0((u32 *)p->h) == 1) {
            p->x2C = 2;
            p->state = 0x13;
        }
        break;
    case 19:
        func_021CE81C((u32 *)p);
        return 1;
    }

    if (func_0200FB24() != 0) {
        p->x2C = 4;
        return 1;
    }
    return 0;
}




int func_021CDAB8(u8 *p)
{
    switch (p[0x51E]) {
    case 0:
        func_021CE9E4((Work_021CD6D0 *)p, *(u16 *)(data_021DB498 + p[0x520] * 12 + 10));
        p[0x51E]++;
        break;
    case 1:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            p[0x51E]++;
        }
        break;
    case 2:
        func_021CEB64(p);
        func_021CE81C((u32 *)p);
        U32(0x404) = 0;
        func_021CEB20(p);
        func_0203D010();
        p[0x51E]++;
        break;
    case 3:
        switch (func_021CEB84(p)) {
        case 1:
            func_021CEB64(p);
            if (p[0x519] == 1) {
                p[0x51E] = 6;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 8;
            } else {
                func_0201F02C((struct WordSet *)U32(4), 0, (void *)U32(0x404));
                func_021CE9E4((Work_021CD6D0 *)p, 0x21);
                p[0x51E] = 4;
            }
            break;
        case 2:
            func_021CEB64(p);
            p[0x51E] = 10;
            break;
        case 3:
            func_021CEB64(p);
            p[0x51E] = 0xe;
            break;
        }
        break;
    case 4:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            func_021CE9E4((Work_021CD6D0 *)p, 0x22);
            func_021CE7AC((u32 *)p);
            p[0x51E]++;
        }
        break;
    case 5:
        if (func_021CF068(p) == 2) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 0xe;
            break;
        }
        if (p[0x577] == 1) {
            if (func_021CF32C(p[0x51B]) == 1) {
                p[0x577] = 0;
            }
        }
        func_021CE9A0(p);
        if (p[0x519] == 1) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 6;
        } else if (p[0x51A] == 1) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 8;
        }
        break;
    case 6:
        if (p[0x520] == 0) {
            func_021CE9E4((Work_021CD6D0 *)p, 0x1e);
        }
        p[0x51E] = 7;
        func_02039C68((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27);
        break;
    case 7:
        if (p[0x520] != 0 || func_02190EF0((u32 *)U32(0x14)) == 1) {
            if (func_02039CB4((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27) == 1) {
                U32(0x2c) = 1;
                p[0x51E] = 0xf;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 8;
            }
        }
        break;
    case 8:
        func_021CE9E4((Work_021CD6D0 *)p, *(u16 *)(data_021DB498 + p[0x520] * 12 + 8));
        p[0x51E] = 9;
        break;
    case 9:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            p[0x51E] = 0xe;
        }
        break;
    case 10:
        U32(0x484) = func_0203D650();
        func_02082D44(func_0203D798(), p + 0x414, 0x70);
        func_021CF17C();
        func_0203CEAC(0);
        func_0201F02C((struct WordSet *)U32(4), 0, (void *)((int)(p + 0x530)));
        func_021CE9E4((Work_021CD6D0 *)p, 0x1f);
        p[0x51E] = 0xb;
        break;
    case 11:
        if (func_0203CDBC() == 1 && func_02190EF0((u32 *)U32(0x14)) == 1) {
            p[0x51E] = 0xc;
        }
        break;
    case 12:
        func_0203CBAC((struct Req *)(p + 0x414), 0, (u32)((void *)U32(0x484)));
        p[0x51E] = 0xd;
        break;
    case 13:
        if (func_0203CD98() == 1) {
            func_021CF164((u32)p);
            p[0x51E] = 0;
        }
        break;
    case 14:
        U32(0x2c) = 2;
        p[0x51E] = 0xf;
        break;
    case 15:
        func_021CEB64(p);
        func_021CE81C((u32 *)p);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(p);
        func_021CEB64(p);
        U32(0x2c) = 4;
        return 1;
    }
    return 0;
}




int func_021CDD5C(u8 *p)
{
    switch (p[0x51E]) {
    case 0:
        func_021CE9E4((Work_021CD6D0 *)p, 0x15);
        p[0x51E]++;
        break;
    case 1:
        if (func_021CF1AC((u32)(p + 0x30), 1, p[0x51B]) == 1) {
            p[0x51E]++;
        }
        break;
    case 2:
        func_021CE7AC((u32 *)p);
        p[0x51E]++;
        break;
    case 3:
        if (func_021CF068(p) == 2) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 10;
            break;
        }
        if (p[0x577] == 1) {
            if (func_021CF32C(p[0x51B]) == 1) {
                p[0x577] = 0;
            }
        }
        func_021CE9A0(p);
        if (p[0x519] == 1) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 4;
        } else if (p[0x51A] == 1) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 6;
        }
        break;
    case 4:
        if (p[0x520] == 0) {
            func_021CE9E4((Work_021CD6D0 *)p, 0x1e);
        }
        p[0x51E] = 5;
        func_02039C68((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27);
        break;
    case 5:
        if (p[0x520] != 0 || func_02190EF0((u32 *)U32(0x14)) == 1) {
            if (func_02039CB4((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27) == 1) {
                U32(0x2c) = 1;
                p[0x51E] = 0xb;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 6;
            }
        }
        break;
    case 6:
        func_021CE9E4((Work_021CD6D0 *)p, *(u16 *)(data_021DB498 + p[0x520] * 12 + 8));
        p[0x51E] = 7;
        break;
    case 7:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            U32(0x2c) = 2;
            p[0x51E] = 0xb;
        }
        break;
    case 8:
        func_0203CEAC(0);
        func_0201F02C((struct WordSet *)U32(4), 0, (void *)U32(0x404));
        func_021CE9E4((Work_021CD6D0 *)p, 0x1f);
        p[0x51E] = 9;
        break;
    case 9:
        if (func_0203CDBC() == 1 && func_02190EF0((u32 *)U32(0x14)) == 1) {
            U32(0x2c) = 3;
            p[0x51E] = 0xb;
        }
        break;
    case 10:
        U32(0x2c) = 2;
        p[0x51E] = 0xb;
        break;
    case 11:
        func_021CE81C((u32 *)p);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(p);
        U32(0x2c) = 4;
        return 1;
    }
    return 0;
}




/*
 * Case 2's r == 2 arm really calls func_021CF0F4 twice: the original's
 * branch lands on case 4's second-call tail after its own call.
 *
 * Addresses are Black-image addresses.
 */
int func_021CDF18(u8 *p)
{
    switch (p[0x51E]) {
    case 0:
        func_021CE9E4((Work_021CD6D0 *)p, 0x15);
        p[0x51E]++;
        break;
    case 1:
        U32(0x52C) = 0;
        if (func_021CF1AC((u32)(p + 0x30), 0, p[0x51B]) == 1) {
            p[0x51E] = 2;
        }
        break;
    case 2:
        if (func_021CF068(p) == 2) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            func_021CF0F4(p);
            p[0x51E] = 0xb;
            break;
        }
        if (U32(0x52C) == 1) {
            p[0x51E] = 3;
            func_021CF0F4(p);
        } else if (U32(0x52C) == 2) {
            p[0x51E] = 9;
            func_021CF0F4(p);
        } else if (p[0x519] == 1) {
            p[0x51E] = 5;
            func_021CF0F4(p);
        } else if (p[0x51A] == 1) {
            p[0x51E] = 0xb;
            func_021CF0F4(p);
        }
        break;
    case 3:
        func_021CE7AC((u32 *)p);
        p[0x51E]++;
        break;
    case 4:
        if (func_021CF068(p) == 2) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 0xb;
            break;
        }
        if (p[0x577] == 1) {
            if (func_021CF32C(p[0x51B]) == 1) {
                p[0x577] = 0;
            }
        }
        func_021CE9A0(p);
        if (p[0x519] == 1) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 5;
        } else if (p[0x51A] == 1) {
            func_021CE81C((u32 *)p);
            func_021CF0F4(p);
            p[0x51E] = 7;
        }
        break;
    case 5:
        if (p[0x520] == 0) {
            func_021CE9E4((Work_021CD6D0 *)p, 0x1e);
        }
        p[0x51E] = 6;
        func_02039C68((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27);
        break;
    case 6:
        if (p[0x520] != 0 || func_02190EF0((u32 *)U32(0x14)) == 1) {
            if (func_02039CB4((struct Link *)(struct Entry *)func_020399A8(), 1, 0x27) == 1) {
                U32(0x2c) = 1;
                p[0x51E] = 0xc;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 7;
            }
        }
        break;
    case 7:
        func_021CE9E4((Work_021CD6D0 *)p, *(u16 *)(data_021DB498 + p[0x520] * 12 + 8));
        p[0x51E] = 8;
        break;
    case 8:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            U32(0x2c) = 2;
            p[0x51E] = 0xc;
        }
        break;
    case 9:
        func_0203CEAC(0);
        func_0201F02C((struct WordSet *)U32(4), 0, (void *)((int)(p + 0x530)));
        func_021CE9E4((Work_021CD6D0 *)p, 0x1f);
        p[0x51E] = 10;
        break;
    case 10:
        if (func_0203CDBC() == 1 && func_02190EF0((u32 *)U32(0x14)) == 1) {
            U32(0x2c) = 3;
            p[0x51E] = 0xc;
        }
        break;
    case 11:
        U32(0x2c) = 2;
        p[0x51E] = 0xc;
        break;
    case 12:
        func_021CE81C((u32 *)p);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(p);
        U32(0x2c) = 4;
        return 1;
    }
    return 0;
}




void func_021CE12C(u8 *p)
{
    u8 i;
    int bit;
    u8 n;

    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        if (p[0x521] & bit) {
            if (func_021CF220(i, p[0x51B], (u32)(p + 0x30)) == 1)
                p[0x521] ^= (u8)bit;
        } else if (p[0x522] & bit) {
            if (func_021CF288(i, p[0x51B], (u32)(p + 0x30)) == 1)
                p[0x522] ^= (u8)bit;
        }
    }
    if (p[0x523] == 1 && p[0x525] == 0) {
        n = func_021CE1F4(p);
        if (n > 1) {
            if (func_021CF3FC((u32)(p + 0x494), n, p[0x51B]) == 1) {
                p[0x523] = 0;
                p[0x525] = 1;
            }
        }
    }
}




/*
 * ldr r3,=0x02082D44; movs r2,#0x20; bx r3) has no witness outside the range.
 * Verified C for the leaf: void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 * (verified EXACT, 12 bytes, thumb, with func_02082D44 0x02082D44 arm; leaf not filed here.)
 *
 * Addresses are Black-image addresses.
 */
u8 func_021CE1F4(u8 *p)
{
    u8 i;
    u8 mask;
    u8 *buf;
    u8 *e;

    mask = 0;
    i = 0;
    e = p + 0x50;
    buf = p + 0x494;
    for (; i < 4; i++) {
        if (p[0x70 + i * 0x2c]) {
            func_02008494(e + i * 0x2c, buf + i * 32);
            mask |= 1 << i;
        }
    }
    p[0x514] = mask;
    return 1 | mask;
}




void func_021CE24C(u8 *p)
{
    u8 i;
    int off;

    for (i = 0; i < 4; i++) {
        off = i * 0x2c;
        if (p[0x70 + off] && !func_0203D1C0(i)) {
            void (*cb)(u32, u8 *, u8 *) = *(void (**)(u32, u8 *, u8 *))(p + 0x490);

            if (cb) {
                cb(((struct Obj02098 *)p)->f488, p + 0x50 + off, p + 0x73 + off);
            }
            func_021CE3D8((Mgr *)p, i);
            func_021CEA84(p, i);
            func_021CEAB0(p);
        }
    }
}



void func_021CE2BC(u8 *p)
{
    u8 *e;
    int i;
    int n;

    n = 0;
    i = 0;
    e = p + 0x50;
    for (; i < 4; i++) {
        if (p[0x70 + i * 0x2c]) {
            func_021CE8B0(p, e + i * 0x2c, i);
            n++;
        } else {
            func_021CE8F4(p, e + i * 0x2c, i);
        }
    }
    if (n == 0) {
        func_021CE934(p, p + 0x30, 0);
        n++;
    }
    if (*(s8 *)&((struct Obj00011 *)p)->f572 != n) {
        if (func_021CE84C((u32 *)p, n) == 1) {
            p[0x572] = n;
            if (p[0x520] == 1 && n == 1) {
                p[0x579] = 1;
            }
        }
    }
    if (p[0x579] == 1) {
        if (func_021CE78C((u32)p) == 1 && ((struct Obj00011 *)p)->f130 == 0) {
            if (n == 1) {
                func_021CE9E4((Work_021CD6D0 *)p, 8);
            }
            p[0x579] = 0;
        }
    }
}



void func_021CE36C(u8 *p)
{
    u8 *e;
    u8 j;

    e = p + 0x50;
    for (j = 0; j < 4; j++, e += 0x2c) {
        switch (e[0x20]) {
        case 1:
            if (e[0x21] == 1) {
                e[0x20] = 4;
                p[0x521] |= 1 << j;
            } else {
                e[0x20] = 2;
            }
            break;
        case 2:
            if (func_021CE3E8(p, e) == 1) {
                e[0x20] = 3;
            }
            break;
        }
    }
}



/*
 * Clears the state byte of entry i of the four 0x2C-byte entries at +0x70.
 *
 * Addresses are Black-image addresses.
 */
void func_021CE3D8(Mgr *m, int i)
{
    m->ent[i].state = 0;
}
