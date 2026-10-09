/*
 * file:     wifibattlematch_view_p02.c
 * unit:     yes
 * function: func_021E65FC, func_021E6718, func_021E6940, func_021E6BE8, func_021E6E8C, func_021E6EFC, func_021E6F20, func_021E7270, func_021E72FC, func_021E73B8, func_021E73E4, func_021E7454, func_021E7464, func_021E74FC, func_021E7520, func_021E7710, func_021E7774, func_021E777C, func_021E78B0, func_021E7AE0, func_021E7B44, func_021E7B68, func_021E7C14, func_021E7C3C, func_021E7CD0, func_021E7CF0, func_021E7D20, func_021E7DF0, func_021E7E08, func_021E7E0C, func_021E7E3C, func_021E82BC, func_021E8338, func_021E8420, func_021E84F8, func_021E8568, func_021E8628, func_021E867C, func_021E8738, func_021E8754, func_021E8844, func_021E8848, func_021E8870, func_021E888C
 * address:  0x021E65FC
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E8D36 0x021E8D36 data a1
 *   d_021E8CCE 0x021E8CCE data a1
 *   func_021E5ADC 0x021E5ADC thumb ov177
 *   d_021E8D0E 0x021E8D0E data a1
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_0200B214 0x0200B214 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_0202DC08 0x0202DC08 thumb
 *   func_02040618 0x02040618 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021E8CEE 0x021E8CEE data a1
 *   func_0202DBC4 0x0202DBC4 thumb
 *   func_0202DC98 0x0202DC98 thumb
 *   func_02030734 0x02030734 arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C440  0x0201C440  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021E8DD4     0x021E8DD4  data
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02034714  0x02034714  arm
 *   func_02028470  0x02028470  thumb
 *   func_02028590  0x02028590  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   d_021E8DEC     0x021E8DEC  data
 *   func_021E88B0  0x021E88B0  thumb  ov177
 */
#include "../../matched/include/Obj10708.h"
#include "../../matched/include/Obj24447.h"
#include "../../matched/include/Obj00133.h"
#include "../../matched/include/Obj02224.h"
#include "../../matched/include/Obj10709.h"
#include "../../matched/include/Obj24448.h"
#include "../../matched/include/Obj10710.h"
#include "../../matched/include/Obj14374.h"
#include "../../matched/include/Obj06582.h"
#include "../../matched/include/Obj14375.h"
#include "../../matched/include/Obj03873.h"
#include "../../matched/include/Obj08288.h"
#include "../../matched/include/Obj03326.h"
#include "../../matched/include/Obj06583.h"
#include "../../matched/include/Obj10713.h"
#include "../../matched/include/Obj01960.h"
#include "../../matched/include/Obj00842.h"
#include "../../matched/include/Obj24449.h"

struct Actor;
struct PtS;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Strbuf;
struct PrintSys;
struct Obj;
struct Rec1E;
struct PmsDraw;
struct Sub0200852CObj;
struct Vec2;
struct Obj0202DC98;
struct StrObj;
struct Tcbl;
struct Rec3;
struct S02031140;
struct Ctx;
struct Blk;
typedef struct { short x, y; } Pt;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef short s16;

typedef struct { void *win; u8 shown; u8 pad[3]; } Slot;

typedef struct {
    unsigned count;      /* 0x000 */
    void *wins[30];      /* 0x004 */
    Slot slots[30];      /* 0x07c */
    void *objs[22];      /* 0x16c */
    void *chr[6];        /* 0x1c4 */
    char pad1dc[4];
    void *cell;          /* 0x1e0 */
    void *pal;           /* 0x1e4 */
    char pad1e8[0x1f4 - 0x1e8];
    void *pal2;          /* 0x1f4 */
    void *chr2;          /* 0x1f8 */
    void *cell2;         /* 0x1fc */
    unsigned objCount;   /* 0x200 */
    short baseX[22];     /* 0x204 */
    u8 bg;               /* 0x230 */
    u8 palette;          /* 0x231 */
    u8 palSlot;          /* 0x232 */
    u8 pad233;
    u32 layer;           /* 0x234 */
} Work;


typedef struct {
    unsigned f0;
    u16 h4;
    u16 pad6;
    unsigned f8;
    unsigned fC;
    u16 h10;
    u16 h12;
} Info_021E65FC;

typedef struct { u8 a, b, c, d; } WinDef;

typedef struct { u16 heap; } HeapArg;

typedef struct {
    char pad0[0x94];
    unsigned date1;      /* 0x94 */
    unsigned date2;      /* 0x98 */
    unsigned pad9c;
    u16 hA0;             /* 0xa0 */
    u16 padA2;
    unsigned uA4;        /* 0xa4 */
    u16 hA8;             /* 0xa8 */
} Info_021E6940;

typedef struct {
    char pad0[0x94];
    unsigned date1;      /* 0x94 */
    unsigned date2;      /* 0x98 */
    unsigned pad9c;
    u16 hA0;             /* 0xa0 */
    u16 hA2;             /* 0xa2 */
    u16 hA4;             /* 0xa4 */
    u16 hA6;             /* 0xa6 */
} Info;

typedef struct { short x, y; u16 id; u8 a, flag; } Request_021E6F20;

typedef signed int     s32;

typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request_021E7270;

typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;

typedef struct { void *win; unsigned char shown; } Entry_021E72FC;

typedef struct {
    u32 owner;           /* 0x00 */
    void *win[8];        /* 0x04 */
    Entry_021E72FC ent[7];        /* 0x24 */
    char pad5c[0x64 - 0x5c];
    void *main;          /* 0x64 */
    void *obj[5];        /* 0x68 */
    void *menu;          /* 0x7c */
    char pad80[0x88 - 0x80];
    unsigned count;      /* 0x88 */
    unsigned short base; /* 0x8c */
    unsigned short objBase[5]; /* 0x8e */
    u32 mode;            /* 0x98 */
} Work_021E72FC;

typedef struct {
    char pad0[0x28];
    unsigned score;      /* 0x28 */
    u32 f2c;             /* 0x2c */
    void *f30;           /* 0x30 */
    unsigned count;      /* 0x34 */
    char name[1];        /* 0x38 */
} Record;

typedef struct { unsigned char bg, x, y, w; } WinTemplate;

typedef struct {
    void *pal;
    void *chr[7];
    void *cell;
    void *chrB;
    void *palB;
    void *cellB;
    void *spr[14];
    void *win[6];
    Entry_021E72FC ent[6];
    unsigned count;
    short base[14];
} Work_021E7E3C;

typedef struct {
    char pad0[0x30];
    void *obj[14];
    char pad68[0xb0 - 0x68];
    unsigned count;
    short base[14];
} Work_021E8338;

typedef struct {
    char pad0[0x30];
    void *obj[14];
    char pad68[0xb0 - 0x68];
    unsigned count;
    short base[14];
} Work_021E8420;

typedef struct {
    char           pad0[4];
    int            f4;
    char           pad1[4];
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad2[3];
    int            f28;
    int            f2c;
} S_021E7CD0;

typedef struct {
    int            f0;
    int            f4;
    int            f8;
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad0[3];
    int            f28;
    int            f2c;
    int            f30;
    int            f34;
    char           f38[1];
} S_021E8754;

typedef struct {
    char pad0[0x10];
    int  f10;
    int  f14;
    char pad1[0x18];
    int  f30;
} S_021E8848;

typedef struct {
    char           pad0[0x14];
    int            f14;
    char           pad1[4];
    unsigned short f1c;
} S_021E8870;

typedef struct {
    char           pad0[0x1c];
    unsigned int f1c;
} S_021E888C;

extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(void *, const Pt *, unsigned short);
extern void func_020061E4(unsigned);
extern unsigned func_0209C2B0(unsigned, unsigned);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_020457B0(unsigned, u16);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *print, void *bmp, short x, short y, void *str, int font, int color);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02008500(void *, void *);
extern void func_0201F230(struct WordSet *p, u32 i, u32 v);
extern void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0200B214(struct Rec1E *p, u32 id, u8 n);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern unsigned func_0204A6C8(void *, unsigned, unsigned, unsigned, unsigned short);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern unsigned func_0204AC18(void *, unsigned, unsigned, unsigned short, unsigned short, unsigned short, unsigned short);
extern void func_02082BCC(void *, u32, u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, unsigned);
extern u32 func_0201BB5C(u32, u32, u32, u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_021E5978(int *p, int i);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0202DE68(struct PmsDraw *p, u32 v);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_0204162C(int);
extern void func_020410D0(u32, u32, u32, u32, u8, u32, u8, u8, u8, u8);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_0202DC08(struct Obj *p);
extern u32 func_020307B0(void *p);
extern const void *func_020084F4(const void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0202DE64(struct PmsDraw *p, u16 v);
extern void func_0202DC48(void *, void *, const void *, unsigned);
extern void func_0202DBC4(u8 *p);
extern u32 func_0202DC98(struct Obj0202DC98 *o);
extern void func_020456F8(struct Descriptor *d);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_020061F8(int i);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_0200BAF4(int a0, int a1);
extern unsigned func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern void *func_020185F4(void *);
extern unsigned func_0201BA68(void *);
extern int func_0201BBE8(void *a0);
extern void *func_0201EC64(u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_020407E8(u32 layer);
extern u32 func_0201C440(void *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(unsigned char *p);
extern int func_02028604(int p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *p, unsigned kind);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_020310C4(struct Tcbl *p);
extern void func_0201C6EC(struct PrintSys *p);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02028470(u8 *p, u32 v);
extern int  func_02028590(int, int, int, int);
extern signed char func_02012FFC(void);
extern int  func_0201CCE4(int, int, int, int, int, int, int, int, int, int);
extern void func_021E88B0(S_021E888C *, int, unsigned char, int, int, int);
int func_021E65FC(Work *w);
void func_021E6718(Work *w, unsigned a1, const Info_021E65FC *info, void *a3, int a4, void *a5, void *a6, void *a7, int a8, HeapArg h);
void func_021E6940(Work *w, unsigned a1, const Info_021E6940 *info, void *a3, int a4, void *a5, void *a6, void *a7, u16 heap);
void func_021E6BE8(Work *w, const Info *info, void *a3, int a4, void *a5, void *a6, void *a7, u16 heap);
int func_021E6E8C(unsigned char *p, void *mgr);
void func_021E6EFC(unsigned *p);
void func_021E6F20(Work *w, void *owner, void *rec, u16 heap);
void func_021E7270(char *p);
void func_021E72FC(unsigned char *p, unsigned idx, void *owner, u16 heap);
void func_021E73B8(char *p);
void func_021E73E4(char *p, void *owner, void *table, unsigned heap);
void func_021E7454(int *p);
void func_021E7464(char *p, char *desc, void *owner, void *table, unsigned heap);
void func_021E74FC(char *p);
Work_021E72FC *func_021E7520(const Record *rec, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, u32 mode, u32 owner, int style, u16 heap);
void func_021E7710(char *p);
int func_021E7774(void *p, void *mgr);
int func_021E777C(Work_021E72FC *p);
void func_021E78B0(Work_021E72FC *p, const Record *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap);
int func_021E7AE0(unsigned char *p, void *mgr);
void func_021E7B44(Work_021E72FC *p);
void func_021E7B68(char *p, unsigned idx, void *owner, u16 heap);
void func_021E7C14(char *p);
void func_021E7C3C(char *p,char *q,void *x,void *data,unsigned heap);
void func_021E7CD0(Work_021E72FC *p);
unsigned func_021E7CF0(void *p, unsigned v, unsigned w);
void **func_021E7D20(void *owner, void *src, unsigned heap);
void func_021E7DF0(int *p);
void func_021E7E08(int p);
void func_021E7E0C(void **p, int on);
Work_021E7E3C *func_021E7E3C(void *src, void *owner, int unused, unsigned font, void *print, void *msg, unsigned heap);
void func_021E82BC(char *p);
int func_021E8338(Work_021E8338 *p);
int func_021E8420(Work_021E8420 *p);
int func_021E84F8(char *p, void *q);
S_021E7CD0 *func_021E8568(int a, int b, unsigned short c, unsigned short d, int e, int f, unsigned short heap);
void func_021E8628(char *p);
void func_021E867C(char *p);
void func_021E8738(int *p, int a, int b, int c);
void func_021E8754(S_021E8754 *p, int mode);
int func_021E8844(const int *p);
void func_021E8848(S_021E8848 *p);
void func_021E8870(S_021E8870 *p);
void func_021E888C(S_021E888C *p, int a);
extern const WinDef d_021E8D36[];
extern const WinDef d_021E8CCE[];
extern const WinDef d_021E8D0E[];
extern const unsigned char d_021E8CBE[];
extern const char d_021E8DBC[];
extern const WinTemplate d_021E8CEE[];
extern unsigned char d_021E8DD4[];
extern unsigned char d_021E8DEC[];




int func_021E65FC(Work *w)
{
    int ret = 0;
    int level;
    int i;
    Pt cur, pos;
    if (w->objCount == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                func_0204B454(w->objs[i], (struct PtS *)&cur, (unsigned short)w->layer);
                w->baseX[i] = cur.x;
            }
        }
        func_020061E4(0x63b);
    }
    level = func_0209C2B0(w->objCount << 8, 20);
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            func_0204B454(w->objs[i], (struct PtS *)&pos, (unsigned short)w->layer);
            pos.x = w->baseX[i] - func_0209C2B0(w->objCount << 8, 20);
            func_0204B404(w->objs[i], &pos, w->layer);
        }
    }
    if (w->objCount++ >= 20) {
        level = 0x100;
        w->objCount = 0;
        ret = 1;
    }
    func_02041EE4((unsigned char)(w->bg + 1), (int)0, (int)level);
    func_02041EE4((unsigned char)w->bg, (int)0, (int)level);
    return ret;
}




void func_021E6718(Work *w, unsigned a1, const Info_021E65FC *info, void *a3, int a4, void *a5, void *a6, void *a7, int a8, HeapArg h)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 11;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)func_020450F0(5, d_021E8D36[i].a, d_021E8D36[i].b, d_021E8D36[i].c, d_021E8D36[i].d, 0xf, 1);
        func_02043B5C(func_02045770(w->wins[i]), 0);
        win = w->wins[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = func_020457B0(0x80, h.heap);
    s2 = func_020457B0(0x80, h.heap);
    for (j = 0; j < 11; j++) {
        color = (a8 == 1) ? 0x3c40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            func_02045CAC(a6, a1, s2);
            color = 0x3c40;
            break;
        case 1:
            func_02045CAC(a6, info->f0 + 2, s2);
            color = 0x3c40;
            break;
        case 2:
            func_02045CAC(a6, 7, s1);
            func_0201F02C(a7, 0, a3);
            func_0201F250(a7, s2, s1);
            color = 0x3c40;
            break;
        case 3:
            if (a1)
                func_02045CAC(a6, 8, s2);
            else
                draw = 0;
            break;
        case 4:
            if (a1) {
                func_02045CAC(a6, 9, s1);
                func_0201EFA4(a7, 0, info->h4, 4, 1, 1);
                func_0201F250(a7, s2, s1);
            } else {
                draw = 0;
            }
            break;
        case 5:
            func_02045CAC(a6, 10, s2);
            break;
        case 6:
            func_02045CAC(a6, 11, s1);
            func_0201EFA4(a7, 0, info->fC, 6, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 7:
            func_02045CAC(a6, 12, s2);
            break;
        case 8:
            func_02045CAC(a6, 13, s1);
            func_0201EFA4(a7, 0, info->h10, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 9:
            func_02045CAC(a6, 14, s2);
            break;
        case 10:
            func_02045CAC(a6, 15, s1);
            func_0201EFA4(a7, 0, info->h12, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        }
        if (draw) {
            func_0201C724(a5, func_02045770(w->slots[j].win), 0, 0, s2, a4, color);
            w->slots[j].shown = 1;
        }
    }
    func_02045808(s1);
    func_02045808(s2);
}



void func_021E6940(Work *w, unsigned a1, const Info_021E6940 *info, void *a3, int a4, void *a5, void *a6, void *a7, u16 heap)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 8;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)func_020450F0(w->bg, d_021E8CCE[i].a, d_021E8CCE[i].b, d_021E8CCE[i].c, d_021E8CCE[i].d, w->palette, 1);
        func_02043B5C(func_02045770(w->wins[i]), 0);
        win = w->wins[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = func_020457B0(0x80, heap);
    s2 = func_020457B0(0x80, heap);
    for (j = 0; j < 8; j++) {
        unsigned d1, d2;
        draw = 1;
        color = 0x440;
        switch (j) {
        case 0:
            func_02045924(s2, (const u16 *)info);
            color = 0x3c40;
            break;
        case 1:
            d1 = info->date1;
            d2 = info->date2;
            func_02045CAC(a6, 0x10, s1);
            func_0201EFA4(a7, 0, (u16)((u8)(d1 >> 24) + 2000), 4, 0, 1);
            func_0201F230(a7, 1, (u8)(d1 >> 16));
            func_0201EFA4(a7, 2, (u8)(d1 >> 8), 2, 0, 1);
            func_0201EFA4(a7, 3, (u16)((u8)(d2 >> 24) + 2000), 4, 0, 1);
            func_0201F230(a7, 4, (u8)(d2 >> 16));
            func_0201EFA4(a7, 5, (u8)(d2 >> 8), 2, 0, 1);
            func_0201F250(a7, s2, s1);
            color = 0x3c40;
            break;
        case 2:
            func_02008500(a3, s2);
            color = 0x3c40;
            break;
        case 3:
            func_02045CAC(a6, 8, s2);
            break;
        case 4:
            func_02045CAC(a6, 9, s1);
            func_0201EFA4(a7, 0, info->hA0, 4, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 5:
            func_02045CAC(a6, 10, s2);
            break;
        case 6:
            if (a1) {
                func_021E5ADC((u32 *)(&w->slots[j]), a5, a4, info->uA4, info->hA8, heap);
                draw = 0;
            } else {
                func_02045CAC(a6, 11, s1);
                func_0201EFA4(a7, 0, info->uA4, 6, 1, 1);
                func_0201F250(a7, s2, s1);
            }
            break;
        case 7:
            func_02045CAC(a6, 0x11, s2);
            color = 0x3c40;
            break;
        }
        if (draw) {
            func_0201C724(a5, func_02045770(w->slots[j].win), 0, 0, s2, a4, color);
            w->slots[j].shown = 1;
        }
    }
    func_02045808(s1);
    func_02045808(s2);
}



void func_021E6BE8(Work *w, const Info *info, void *a3, int a4, void *a5, void *a6, void *a7, u16 heap)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 10;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)func_020450F0(w->bg, d_021E8D0E[i].a, d_021E8D0E[i].b, d_021E8D0E[i].c, d_021E8D0E[i].d, w->palette, 1);
        func_02043B5C(func_02045770(w->wins[i]), 0);
        win = w->wins[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = func_020457B0(0x80, heap);
    s2 = func_020457B0(0x80, heap);
    for (j = 0; j < 10; j++) {
        unsigned d1, d2;
        draw = 1;
        color = 0x440;
        switch (j) {
        case 0:
            func_02045924(s2, (const u16 *)info);
            color = 0x3c40;
            break;
        case 1:
            d1 = info->date1;
            d2 = info->date2;
            func_02045CAC(a6, 0x10, s1);
            func_0201EFA4(a7, 0, (u16)((u8)(d1 >> 24) + 2000), 4, 0, 1);
            func_0201F230(a7, 1, (u8)(d1 >> 16));
            func_0201EFA4(a7, 2, (u8)(d1 >> 8), 2, 0, 1);
            func_0201EFA4(a7, 3, (u16)((u8)(d2 >> 24) + 2000), 4, 0, 1);
            func_0201F230(a7, 4, (u8)(d2 >> 16));
            func_0201EFA4(a7, 5, (u8)(d2 >> 8), 2, 0, 1);
            func_0201F250(a7, s2, s1);
            color = 0x3c40;
            break;
        case 2:
            func_02008500(a3, s2);
            color = 0x3c40;
            break;
        case 3:
            func_02045CAC(a6, 12, s2);
            break;
        case 4:
            func_02045CAC(a6, 13, s1);
            func_0201EFA4(a7, 0, info->hA0, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 5:
            func_02045CAC(a6, 14, s2);
            break;
        case 6:
            func_02045CAC(a6, 15, s1);
            func_0201EFA4(a7, 0, info->hA2, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 7:
            func_02045CAC(a6, 10, s2);
            break;
        case 8:
            func_021E5ADC((u32 *)(&w->slots[j]), a5, a4, info->hA4, info->hA6, heap);
            draw = 0;
            break;
        case 9:
            func_02045CAC(a6, 0x11, s2);
            color = 0x3c40;
            break;
        }
        if (draw) {
            func_0201C724(a5, (void *)((u32)func_02045770(w->slots[j].win)), 0, 0, (void *)((u32)s2), a4, color);
            w->slots[j].shown = 1;
        }
    }
    func_02045808(s1);
    func_02045808(s2);
}



/*
 * lever: signed inner index cast keeps cleanup address apart from unsigned polling address.
 */
int func_021E6E8C(unsigned char *p, void *mgr)
{
    unsigned i;
    int result = 1;
    for (i = 0; i < ((struct Obj24447 *)p)->f0; i++) {
        if (*(void **)(p + i * 4 + 4)) {
            unsigned char *e = p + i * 8;
            if (e[0x80] != 0) {
                if (func_0201C6C4(mgr, func_02045770(((struct Obj10708 *)e)->f7C)) == 0) {
                    func_02045334(*(void **)((unsigned)p + (int)i * 8 + 0x7c));
                    *(unsigned char *)((unsigned)p + (int)i * 8 + 0x80) = 0;
                }
            }
            result &= e[0x80] == 0;
        }
    }
    return result;
}



void func_021E6EFC(unsigned *p)
{
    unsigned i;
    for (i = 0; i < p[0]; i++) {
        if ((void *)p[i + 1] != 0)
            func_020452E8((void *)p[i + 1]);
    }
}



void func_021E6F20(Work *w, void *owner, void *rec, u16 heap)
{
    u8 form;
    u8 shown;
    void *h;
    u16 species;
    u8 gender;
    int i;
    Request_021E6F20 req, sub;
    h = func_020490F4(7, heap);
    w->pal = (void *)func_0204ACEC(h, func_0201BC3C(), w->layer, (u16)(w->palSlot << 5), (heap & 0x7fff) | 0x8000);
    w->cell = (void *)func_0204AF28(h, func_0201BC40(), func_0201BCB4(), heap);
    for (i = 0; i < 6; i++) {
        species = func_0200B214(rec, 0, i);
        form = func_0200B214(rec, 1, i);
        gender = func_0200B214(rec, 3, i);
        w->chr[i] = (void *)func_0204A6C8(h, func_0201BABC((u16)(species != 0 ? species : 1), form, gender, 0), 0, w->layer, (heap & 0x7fff) | 0x8000);
    }
    func_02049238(h);
    h = func_020490F4(func_020275E4(), heap);
    w->pal2 = (void *)func_0204AC18(h, func_02027694(), w->layer, (u16)((w->palSlot + 3) << 5), (u32)0, (u32)1, (heap & 0x7fff) | 0x8000);
    w->chr2 = (void *)func_0204A6C8(h, func_02027698(), 0, w->layer, (heap & 0x7fff) | 0x8000);
    w->cell2 = (void *)func_0204AF28(h, func_0202769C(2), func_020276A0(2), heap);
    func_02049238(h);
    func_02082BCC(&req, 0, 8);
    req.y = 0xa8;
    req.id = 1;
    req.flag = 1;
    req.a = 1;
    for (i = 0; i < 6; i++) {
        species = func_0200B214(rec, 0, i);
        form = func_0200B214(rec, 1, i);
        gender = func_0200B214(rec, 3, i);
        shown = func_0200B214(rec, 2, i);
        if (species != 0) {
            req.x = (i << 5) + 0x120;
            w->objs[i] = func_0204B294(owner, (unsigned int)w->chr[i], (unsigned int)w->pal, (unsigned int)w->cell, &req, w->layer, heap);
            func_0204B6F4(w->objs[i], func_0201BB5C(species, form, gender, 0), 0);
            if (shown != 0) {
                sub = req;
                sub.x += 12;
                sub.y += 8;
                sub.a = 0;
                sub.id = 0;
                w->objs[i + 15] = func_0204B294(owner, (unsigned int)w->chr2, (unsigned int)w->pal2, (unsigned int)w->cell2, &sub, w->layer, heap);
            } else {
                w->objs[i + 15] = 0;
            }
        } else {
            w->objs[i] = 0;
            w->objs[i + 15] = 0;
        }
    }
}



void func_021E7270(char *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x16c)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
        if (*(void **)(p + i * 4 + 0x1a8)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x1a8));
            *(void **)(p + i * 4 + 0x1a8) = 0;
        }
    }
    for (i = 0; i < 6; i++)
        func_0204A8D4(*(unsigned *)(p + i * 4 + 0x1c4));
    func_0204AFD8(*(unsigned *)&((struct Obj00133 *)p)->f1E0);
    func_0204ADA4(*(unsigned *)&((struct Obj00133 *)p)->f1E4);
    func_0204A8D4(*(unsigned *)&((struct Obj00133 *)p)->f1F8);
    func_0204ADA4(*(unsigned *)&((struct Obj00133 *)p)->f1F4);
    func_0204AFD8(*(unsigned *)&((struct Obj00133 *)p)->f1FC);
}








/*
 * lever: full flag byte times 32 narrowed by fourth callee parameter; no three-bit mask.
 */
void func_021E72FC(unsigned char *p, unsigned idx, void *owner, u16 heap)
{
    void *handle;
    Request req;
    handle = func_020490F4(0x20, heap);
    ((struct Obj02224 *)p)->f1E8 = func_0204AC18(handle, 0, ((struct Obj02224 *)p)->f234, p[0x233] * 32, d_021E8CBE[idx], 1, heap);
    ((struct Obj02224 *)p)->f1EC = func_0204A6C8(handle, idx + 0x31, 0, ((struct Obj02224 *)p)->f234, heap);
    ((struct Obj02224 *)p)->f1F0 = func_0204AF28(handle, 0x41, 0x42, heap);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.y = 0;
    req.x = 0;
    req.flag = 1;
    ((struct Obj02224 *)p)->f188 = func_0204B294(owner, ((struct Obj02224 *)p)->f1EC, ((struct Obj02224 *)p)->f1E8, ((struct Obj02224 *)p)->f1F0, &req, ((struct Obj02224 *)p)->f234, heap);
    func_0204B6F4(((struct Obj02224 *)p)->f188, 0, 1);
}








void func_021E73B8(char *p)
{
    func_0204B3B4(((struct Obj00133 *)p)->f188);
    func_0204A8D4((u32)(((struct Obj00133 *)p)->f1EC));
    func_0204AFD8((u32)(((struct Obj00133 *)p)->f1F0));
    func_0204ADA4((u32)(((struct Obj00133 *)p)->f1E8));
}








void func_021E73E4(char *p, void *owner, void *table, unsigned heap)
{
    Request req;
    unsigned v, a, b, c;
    func_02082BCC(&req, 0, 8);
    req.x = 0x118;
    req.y = 0x98;
    req.id = 7;
    req.flag = 1;
    v = ((struct Obj10709 *)p)->f234;
    a = func_021E5978(table, v + 2);
    b = func_021E5978(table, ((struct Obj10709 *)p)->f234);
    c = func_021E5978(table, v + 4);
    ((struct Obj10709 *)p)->f18C = func_0204B294(owner, a, b, c, &req, v, heap);
}









void func_021E7454(int *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj24448 *)p)->f18C));
}








void func_021E7464(char *p, char *desc, void *owner, void *table, unsigned heap)
{
    unsigned n, i, a, b, c;
    Request req;
    n = func_021E7CF0(((struct Obj10710 *)desc)->fC, ((struct Obj10710 *)desc)->f10, ((struct Obj10710 *)desc)->f12);
    func_02082BCC(&req, 0, 8);
    req.x = 0x100;
    req.y = 0x10;
    for (i = 0; i < n; i++) {
        req.x += 0x10;
        req.id = i + 2;
        a = func_021E5978(table, 3);
        b = func_021E5978(table, 1);
        c = func_021E5978(table, 5);
        *(void **)(p + i * 4 + 0x190) = func_0204B294(owner, a, b, c, &req, 1, heap);
    }
}







void func_021E74FC(char *p)
{
    int i;
    for (i = 9; i < 14; i++) {
        if (*(void **)(p + i * 4 + 0x16c) != 0) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
    }
}







Work_021E72FC *func_021E7520(const Record *rec, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, u32 mode, u32 owner, int style, u16 heap)
{
    Work_021E72FC *w;
    u32 kind;
    int alt;
    w = func_02030734(heap, 0x9c, 0, d_021E8DBC, 0x952);
    func_02082BCC(w, 0, 0x9c);
    w->owner = owner;
    w->mode = mode;
    w->menu = func_0202DB0C((u32)a1, 0, (u32)a4, (u32)a3, 5, 1, heap);
    func_0202DE68(w->menu, 1);
    func_0202DE5C(w->menu, 0);
    kind = func_021E7CF0(rec->f30, rec->score, rec->f2c);
    alt = 0;
    if (mode - 2 <= 1)
        alt = kind == 5;
    func_021E78B0(w, rec, (unsigned)a3, a4, a5, a6, alt, heap);
    func_021E7B68((char *)w, func_02008554((const struct Sub0200852CObj *)rec), a1, heap);
    func_0204989C(0x85, 9, 2, 0, 0, 0, (heap & 0x7fff) | 0x8000);
    switch (mode) {
    case 2:
    case 3:
        func_021E7C3C((char *)w, (char *)rec, a1, a2, heap);
        func_020413B0(2, 0, 0, 0x20, 2, 1);
        func_020413B0(2, 0, 3, 0x20, 0x20, kind + 3);
        func_020413B0(2, 0, 3, 1, 2, 1);
        func_020413B0(2, 0x1f, 3, 1, 2, 1);
        break;
    case 0:
    case 1:
        func_020410D0(2, 0, 0, 0x20, 2, func_0204162C(2), 0, 0x18, 0x20, 0x20);
        switch (style) {
        case 0:
            func_020413B0(2, 0, 0, 0x20, 2, 1);
            func_020413B0(2, 0, 3, 0x20, 0x20, 3);
            func_020413B0(2, 0, 3, 1, 2, 1);
            func_020413B0(2, 0x1f, 3, 1, 2, 1);
            break;
        case 1:
            func_020413B0(2, 0, 0, 0x20, 2, 1);
            func_020413B0(2, 0, 3, 0x20, 0x20, 7);
            func_020413B0(2, 0, 3, 1, 2, 1);
            func_020413B0(2, 0x1f, 3, 1, 2, 1);
            break;
        }
        break;
    }
    func_020409B4(2);
    func_02040618(2, 0, ~0xff);
    func_02040618(1, 0, ~0xff);
    func_0207D63C((void *)0x04000050, 4, 8, 0xf, 3);
    return w;
}







/*
 * volatile: 0x021E7718 writes hardware 0x04000050
 */
void func_021E7710(char *p)
{
    *(volatile unsigned short *)0x04000050 = 0;
    switch (((struct Obj14374 *)p)->f98) {
    case 0: case 1: break;
    case 2: case 3: func_021E7CD0((Work_021E72FC *)p); break;
    }
    func_021E7C14(p);
    func_021E7B44((Work_021E72FC *)p);
    func_0202DC08(((struct Obj14374 *)p)->f7C);
    func_02040618(2, 0, -256);
    func_02040618(1, 0, -256);
    func_020307B0(p);
}







int func_021E7774(void *p, void *mgr)
{
    return func_021E7AE0(p, mgr);
}






int func_021E777C(Work_021E72FC *p)
{
    int done;
    int shift;
    Pt pos[2];
    int i;
    done = 0;
    if (p->count == 0) {
        if (p->main != 0) {
            func_0204B454(p->main, (struct PtS *)&pos[1], done);
            p->base = pos[1].x;
        }
        for (i = 0; i < 5; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], (struct PtS *)&pos[1], 0);
                p->objBase[i] = pos[1].x;
            }
        }
        func_020061E4(0x63B);
    }
    shift = func_0209C2B0(p->count << 8, 20) - 0x100;
    if (p->main != 0) {
        func_0204B454(p->main, (struct PtS *)&pos[0], 0);
        pos[0].x = p->base - func_0209C2B0(p->count << 8, 20);
        func_0204B404(p->main, &pos[0], 0);
    }
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->objBase[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], &pos[0], 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0;
        p->count = 0;
        done = 1;
    }
    func_02041EE4(2, 0, shift);
    func_02041EE4(1, 0, shift);
    return done;
}






void func_021E78B0(Work_021E72FC *p, const Record *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap)
{
    void *str;
    void *buf;
    int j;
    u16 color;
    int draw;
    void *win;
    int i;
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)func_020450F0(1, d_021E8CEE[i].bg, d_021E8CEE[i].x, d_021E8CEE[i].y, d_021E8CEE[i].w, 15, 1);
        func_02043B5C(func_02045770(p->win[i]), 0);
        win = p->win[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        if (i != 7) {
            p->ent[i].win = p->win[i];
            p->ent[i].shown = 0;
        }
    }
    buf = func_020457B0(0x80, heap);
    str = func_020457B0(0x80, heap);
    for (j = 0; j < 8; j++) {
        color = alt == 1 ? 0x3C40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            func_02045924(str, func_020084F4(data));
            color = 0x3C40;
            break;
        case 1:
            if (p->mode == 3) {
                func_02045CAC(msg, 12, str);
                color = 0x3C40;
            } else if (p->owner != 0) {
                func_02045CAC(msg, 8, str);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 2:
            if (p->mode == 3) {
                func_02045CAC(msg, 13, buf);
                func_0201EFA4(fmt, 0, data->score, 5, 1, 1);
                func_0201F250(fmt, str, buf);
                color = 0x3C40;
            } else if (p->owner != 0) {
                func_02045CAC(msg, 9, buf);
                func_0201EFA4(fmt, 0, data->count, 4, 1, 1);
                func_0201F250(fmt, str, buf);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 3:
            func_02045CAC(msg, 20, str);
            color = 0x3C40;
            break;
        case 4:
            func_02045CAC(msg, 22, buf);
            func_0201F048(fmt, 0, func_0200856C((const struct Sub0200852CObj *)data));
            func_0201F250(fmt, str, buf);
            break;
        case 5:
            func_02045CAC(msg, 23, buf);
            func_0201F094(fmt, 0, func_0200856C((const struct Sub0200852CObj *)data), func_02008570((const struct Sub0200852CObj *)data));
            func_0201F250(fmt, str, buf);
            break;
        case 6:
            func_02045CAC(msg, 21, str);
            color = 0x3C40;
            break;
        case 7:
            func_0202DE64(p->menu, color);
            func_0202DC48(p->menu, p->win[j], data->name, 0);
            draw = 0;
            break;
        }
        if (draw) {
            func_0201C724(print, func_02045770(p->ent[j].win), 0, 0, str, font, color);
            p->ent[j].shown = 1;
        }
    }
    func_02045808(buf);
    func_02045808(str);
}






static inline int poll_entry(unsigned char *e, void *mgr)
{
    if (e[0x28] != 0) {
        if (func_0201C6C4(mgr, func_02045770(((struct Obj06582 *)e)->f24)) == 0) {
            func_02045334(((struct Obj06582 *)e)->f24);
            e[0x28] = 0;
        }
    }
    return e[0x28] == 0;
}






/*
 * lever: repeat result accumulation in each branch; hoisting through done changes cross-jump and allocation.
 */
int func_021E7AE0(unsigned char *p, void *mgr)
{
    int i;
    unsigned result = 1;
    for (i = 0; i < 8; i++) {
        unsigned done;
        if (i != 7) {
            result &= poll_entry(p + i * 8, mgr);
        } else {
            func_0202DBC4(((struct Obj14375 *)p)->f7C);
            result &= func_0202DC98(((struct Obj14375 *)p)->f7C);
        }
    }
    return result;
}






void func_021E7B44(Work_021E72FC *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->win[i] != 0) {
            func_020456F8(p->win[i]);
            func_020452E8(p->win[i]);
        }
    }
}






void func_021E7B68(char *p, unsigned idx, void *owner, u16 heap)
{
    void *handle;
    Request req;
    handle = func_020490F4(0x20, heap);
    ((struct Obj03873 *)p)->f80 = func_0204AC18(handle, 0, 0, 0x140, d_021E8CBE[idx], 1, heap);
    ((struct Obj03873 *)p)->f82 = func_0204A6C8(handle, idx + 0x31, 0, 0, heap);
    ((struct Obj03873 *)p)->f84 = func_0204AF28(handle, 0x41, 0x42, heap);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.x = 0x120;
    req.y = 0x2c;
    ((struct Obj03873 *)p)->f64 = func_0204B294(owner, ((struct Obj03873 *)p)->f82, ((struct Obj03873 *)p)->f80, ((struct Obj03873 *)p)->f84, &req, 0, heap);
    func_0204B6F4(((struct Obj03873 *)p)->f64, 0, 1);
}





void func_021E7C14(char *p)
{
    func_0204B3B4(((struct Obj08288 *)p)->f64);
    func_0204A8D4(((struct Obj08288 *)p)->f82);
    func_0204AFD8(((struct Obj08288 *)p)->f84);
    func_0204ADA4(((struct Obj08288 *)p)->f80);
}





void func_021E7C3C(char *p,char *q,void *x,void *data,unsigned heap)
{
 unsigned i,n;
 Request b;
 n=func_021E7CF0(*(void **)&((struct Obj03326 *)q)->f30,((struct Obj03326 *)q)->f28,((struct Obj03326 *)q)->f2C);
 func_02082BCC(&b,0,8);
 b.x=0x100;b.y=0x10;
 for(i=0;i<n;i++) {
 int a,c,d;
 b.x+=0x10;b.id=i+2;
 a=func_021E5978(data,2);c=func_021E5978(data,0);d=func_021E5978(data,4);
 *(void **)(p+i*4+0x68)=func_0204B294(x,a,c,d,&b,0,heap);
 }
}









void func_021E7CD0(Work_021E72FC *p)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            func_0204B3B4(p->obj[i]);
            p->obj[i] = 0;
        }
    }
}









unsigned func_021E7CF0(void *p, unsigned v, unsigned w)
{
    if (v >= 1000) {
        return 5;
    }
    if (v >= 500) {
        return 4;
    }
    if (v >= 200) {
        return 3;
    }
    if (v >= 100) {
        return 2;
    }
    if (v >= 50) {
        return 1;
    }
    return 0;
}









void **func_021E7D20(void *owner, void *src, unsigned heap)
{
    void **objs;
    Request req;
    objs = func_02030734(heap, 8, 0, d_021E8DBC, 0xBEF);
    func_02082BCC(objs, 0, 8);
    func_02082BCC(&req, 0, 8);
    req.x = 0x80;
    req.y = 0x60;
    req.id = 1;
    req.a = 1;
    req.flag = 1;
    objs[0] = func_0204B294(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), (const Request *)&req, 0, heap);
    func_0204B92C(objs[0], 1);
    req.id = 0;
    req.a = 0;
    req.flag = 1;
    objs[1] = func_0204B294(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), (const Request *)&req, 0, heap);
    func_0204B92C(objs[1], 1);
    return objs;
}










void func_021E7DF0(int *p)
{
    func_0204B3B4((struct Obj *)(*(int *)((char *)p + 4)));
    func_0204B3B4((struct Obj *)(*(int *)p));
    func_020307B0(p);
}









/*
 * extent: bx lr followed by two bytes zero alignment and existing labelled 021E7E0C.
 */
void func_021E7E08(int p) {}









void func_021E7E0C(void **p, int on)
{
    if (on == 1) {
        func_020061E4(0x80D);
    } else {
        func_020061F8(2);
    }
    func_0204B3DC(p[0], on);
    func_0204B3DC(p[1], on);
}









static inline unsigned HeapTemp(unsigned heap)
{
    heap &= 0x7FFF;
    heap |= 0x8000;
    return heap;
}









/*
 * The temporary heap id is formed twice: once through an inline that
 * rewrites its own parameter (the image copies heap before the and), held
 * in r7 for the first block; then as a plain expression, which the
 * compiler CSEs into a temporary slot below the loop pointers. One shared
 * expression or one shared local CSEs both blocks together.
 */
Work_021E7E3C *func_021E7E3C(void *src, void *owner, int unused, unsigned font, void *print, void *msg, unsigned heap)
{
    Work_021E7E3C *work;
    void *party;
    void *handle;
    void *mon;
    u8 x;
    void *fmt;
    void *buf;
    void *sLevel;
    void *sMale;
    void *sFemale;
    void *win;
    u8 level;
    int i;
    unsigned h;
    Request req;
    Request req2;
    Pt pos;
    work = func_02030734(heap, sizeof(Work_021E7E3C), 0, d_021E8DBC, 0xC8A);
    func_02082BCC(work, 0, sizeof(Work_021E7E3C));
    h = HeapTemp(heap);
    party = func_0200BAF4((int)src, (u16)h);
    func_0204989C((int)0x85, (int)7, (int)2, (int)0, (int)0, (int)0, h);
    handle = func_020490F4(7, (unsigned)heap);
    work->pal = (void *)func_0204ACEC(handle, func_0201BC3C(), 0, 0xA0, h);
    work->cell = (void *)func_0204AF28(handle, func_0201BC40(), func_0201BCB4(), (u16)h);
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, (int)i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            work->chr[i] = (void *)func_0204A6C8(handle, func_0201BA68(func_020185F4(mon)), 0, 0, h);
        }
    }
    func_02049238(handle);
    handle = func_020490F4(func_020275E4(), (unsigned)heap);
    work->chrB = (void *)func_0204AC18(handle, func_02027694(), 0, 0x100, 0, 1, (heap & 0x7FFF) | 0x8000);
    work->cellB = (void *)func_0204AF28(handle, func_0202769C((int)2), func_020276A0((int)2), (u16)((heap & 0x7FFF) | 0x8000));
    work->palB = (void *)func_0204A6C8(handle, func_02027698(), 0, 0, (heap & 0x7FFF) | 0x8000);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.x = 0x18;
    req.y = 0x2C;
    req.id = 1;
    req.a = 1;
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, (int)i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            req.x = i * 0x28 + 0x18;
            work->spr[i] = func_0204B294(owner, (unsigned)(work->chr[i]), (unsigned)work->pal, (unsigned)work->cell, (const Request *)&req, 0, heap);
            func_0204B6F4(work->spr[i], func_0201BBE8(func_020185F4(mon)), 0);
            if (func_02017E1C(mon, 6, 0) != 0) {
                req2 = req;
                req2.x += 12;
                req2.y += 8;
                req2.a = 0;
                req2.id = 0;
                work->spr[i + 7] = func_0204B294(owner, (unsigned)work->palB, (unsigned)work->chrB, (unsigned)work->cellB, (const Request *)&req2, 0, heap);
            }
        }
    }
    fmt = func_0201EC64((u16)((heap & 0x7FFF) | 0x8000));
    buf = func_020457B0(0x80, (u16)((heap & 0x7FFF) | 0x8000));
    sLevel = func_02045EC0(msg, 0x63);
    sMale = func_02045EC0(msg, 0x64);
    sFemale = func_02045EC0(msg, 0x65);
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, (int)i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            work->win[i] = (void *)func_020450F0((unsigned char)1, (unsigned char)(i * 5 + 1), (unsigned char)4, (unsigned char)5, 6, 15, 1);
            win = work->win[i];
            func_02045334(win);
            func_02045374(win);
            func_020409B4((int)func_02045730(win));
            work->ent[i].win = work->win[i];
            work->ent[i].shown = 0;
            if (func_02017E1C(mon, 0x6E, 0) == 0) {
                func_0201C724(print, func_02045770(work->ent[i].win), 0x20, 0, sMale, font, 0x14C0);
                work->ent[i].shown = 1;
            } else if (func_02017E1C(mon, 0x6E, 0) == 1) {
                func_0201C724(print, func_02045770(work->ent[i].win), 0x20, 0, sFemale, font, 0xC80);
                work->ent[i].shown = 1;
            }
            level = func_02017E1C(mon, 0x9E, 0);
            func_0201EFA4(fmt, 0, level, 3, 1, 1);
            func_0201F250(fmt, buf, sLevel);
            x = 20 - func_0201D304(buf, font, 0) / 2;
            func_0201C724(print, func_02045770(work->ent[i].win), x, 0x24, buf, font, 0x440);
            work->ent[i].shown = 1;
        }
    }
    func_02045808(sFemale);
    func_02045808(sMale);
    func_02045808(sLevel);
    func_02045808(buf);
    func_0201ED04(fmt);
    for (i = 0; i < 14; i++) {
        if (work->spr[i] != 0) {
            func_0204B454(work->spr[i], (struct PtS *)&pos, 0);
            pos.x += 0x100;
            func_0204B404(work->spr[i], &pos, 0);
        }
    }
    func_02040618((int)2, (int)0, (int)(-0x100));
    func_02040618((int)1, (int)0, (int)(-0x100));
    func_020307B0(party);
    func_0207D63C((void *)0x04000050, 4, 8, 15, 3);
    return work;
}









/*
 * volatile: hardware write 021E82C4.
 */
void func_021E82BC(char *p)
{
 int i;
 *(volatile unsigned short *)0x04000050 = 0;
 for(i=0;i<6;i++) {if(*(void **)(p+i*4+0x68)!=0){func_020456F8(*(void **)(p+i*4+0x68));func_020452E8(*(void **)(p+i*4+0x68));}}
 for(i=0;i<14;i++)if(*(void **)(p+i*4+0x30)!=0)func_0204B3B4(*(void **)(p+i*4+0x30));
 func_0204A8D4((u32)(((struct Obj06583 *)p)->f28));func_0204AFD8((u32)(((struct Obj06583 *)p)->f2C));func_0204ADA4((u32)(((struct Obj06583 *)p)->f24));
 for(i=0;i<6;i++)if(*(void **)(p+i*4+0x30)!=0)func_0204A8D4((u32)(*(void **)(p+i*4+4)));
 func_0204AFD8((u32)(((struct Obj06583 *)p)->f20));func_0204ADA4((u32)(((struct Obj06583 *)p)->f0));func_020307B0(p);
}









int func_021E8338(Work_021E8338 *p)
{
    int done;
    int shift;
    Pt pos[2];
    int i;
    if (func_020407E8(2) == 0) {
        return 1;
    }
    done = 0;
    if (p->count == 0) {
        for (i = done; i < 14; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], (struct PtS *)&pos[1], 0);
                p->base[i] = pos[1].x;
            }
        }
    }
    shift = func_0209C2B0(p->count << 8, 20) - 0x100;
    for (i = 0; i < 14; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->base[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], &pos[0], 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0;
        p->count = 0;
        done = 1;
    }
    func_02041EE4(2, 0, shift);
    func_02041EE4(1, 0, shift);
    return done;
}








int func_021E8420(Work_021E8420 *p)
{
    int done;
    int shift;
    Pt pos[2];
    int i;
    done = 0;
    if (p->count == 0) {
        for (i = done; i < 14; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], (struct PtS *)&pos[1], 0);
                p->base[i] = pos[1].x;
            }
        }
    }
    shift = func_0209C2B0(p->count << 8, 20);
    for (i = 0; i < 14; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->base[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], &pos[0], 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0x100;
        p->count = 0;
        done = 1;
    }
    func_02041EE4(2, 0, shift);
    func_02041EE4(1, 0, shift);
    return done;
}








int func_021E84F8(char *p, void *q)
{
 int result=1;
 unsigned i;
 for(i=0;(int)i<6;i++) {
 if(*(void **)(p+i*4+0x68)!=0) {
 unsigned char *e=(unsigned char *)p+i*8;
 if(e[0x84]!=0) {
 if(func_0201C6C4(q,func_02045770(((struct Obj10713 *)e)->f80))==0) {
 func_02045334(*(void **)((unsigned)p+(int)i*8+0x80));*(unsigned char *)((unsigned)p+(int)i*8+0x84)=0;
 }
 }
 result &= e[0x84]==0;
 }
 }
 return result;
}









/*
 * note 2026-10-02: only prologue scheduling (orig spills r2,r3 before ldr r5 heap, mine
 *   after) and tail ldr r3/str order differ (10 lines). Tried u8 param, local copies,
 *   decl order, init-at-decl, heap types.
 *
 * note 2026-10-05: re-checked the listing: c and d are spilled (str r2,[sp,#0xc]; str r3,[sp,#0x10]) BEFORE
 * the heap load (ldr r5,[sp,#0x30]); ours spills r3 then r2 after the heap load, and loads r3 for the last call
 * above the w->fc store (orig after). Both are scheduler order only, 20 bytes. No source form tried this
 * round changed it (arguments are used in place, no stand-in casts). Still DIFF.
 *
 * note 2026-10-05 (wD9 lane15): 20 -> 8 bytes. `unsigned short c` (docs/idioms/a-narrow-spilled-parameter-keeps-
 *   its-reload-below-a-store.md) fixes the tail: the reload of c now stays below the w->fc store. Left: the
 *   prologue, original `str r2; str r3; ldr r5,[sp,#0x30]; adds r6`, ours `ldr r5; adds r6; str r2; str r3`.
 *   Tried: a struct-by-value (c, d) pair (pushes r0-r3, worse), K&R definition (same 20), d as u16/u8/s16/s8
 *   (10, d's store then drifts below adds r6), a and b as u16 (no change), heap u8/u16 (186, original loads it
 *   as a word), the callee third parameter u16 as in other matched callers (worse). c as u8 is 33 (the original
 *   truncates c at the call).
 *
 * note 2026-10-05 (wD9r lane17, pengy draft): still 8 bytes, prologue only. Hypothesis: c and d are address-taken
 *   so their stores block the heap load. `*&c`/`*&d` at the call: folded, 8. `*(int *)&c` with int c: 38 (homes
 *   r0-r3 in the caller area, push {r0-r3}), so the original does not take their address. Also tried: a local
 *   copy of heap (8), local copies of c and d at the top (8), heap as unsigned int (145).
 * note 2026-10-05 (wD9r lane31): still 8 bytes, prologue only. New tries: c and d as one 64-bit parameter
 *   (20), e/f/heap as a struct passed by value on the stack (8), c and d copied into an `int lc[2]` array local
 *   (8, scalarised), a or b as u8 (113/119), e as u16/u8 (8), f as u16 (158), c as short/signed char (8),
 *   d unsigned int (8), callee 4th parameter u8 with plain c (8; with d u16: 10/12), a..d all u16 (10),
 *   c,d,e u16 (10). With c and d both u16 the c store goes to the front (str r2 matches) but d's store and the
 *   heap load drift down (str r2; adds r6; str r3; movs; adds r7; ldr r5). Left DIFF.
 * note 2026-10-05 (wD9r lane39): still 8 bytes, prologue only. New tries: d as void * / u16 * with the callee
 *   third parameter a pointer (8), an extra unused 8th stack parameter (8), void * return type (8), const heap
 *   (145, heap is reloaded from the stack at each use). Left DIFF.
 * note 2026-10-05 (wD9r lane58): still 8 bytes, prologue only. New tries: the allocation and clear in a
 *   static inline Alloc(heap) helper (8, the inlined copy of heap is propagated), the last call in a static
 *   inline Frame(w, d, c) helper (27). Checked for a matched twin (callers of func_0201F73C and func_020450F0
 *   in src/matched): none has this shape. Left DIFF.
 * note 2026-10-05 (wD9r lane68): EXACT. Fix: heap is a u16 parameter (it is stored with strh to f1e) with the
 *   house callee prototypes (func_02030734 u32 heap, u16 tag; func_020457B0 u32, u32; func_0203101C u32 heap,
 *   u16 tag, so heap goes to both), and d is a u16 parameter passed to the u16 third parameter of
 *   func_0201F73C. The u16 heap keeps the word ldr and moves it below the c home store (8 -> 6), and the u16 d
 *   moves its home store to the front (6 -> 0). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 */
S_021E7CD0 *func_021E8568(int a, int b, unsigned short c, unsigned short d, int e, int f, unsigned short heap)
{
    S_021E7CD0 *w;
    int h;

    w = func_02030734(heap, 0x40, 0, (const char *)d_021E8DD4, 0x5e);
    func_02082BCC(w, 0, 0x40);
    w->f1c = 0xf;
    w->f4 = f;
    w->f28 = func_0201C440((void *)heap);
    w->f2c = 3;
    w->f1e = heap;
    w->f18 = (int)func_020457B0(0x300, heap);
    w->f14 = func_020450F0((unsigned char)a, 1, 0x13, 0x1e, 4, (unsigned char)b, 1);
    w->f20 = w->f14;
    w->f24 = 0;
    func_02043B5C(func_02045770((struct Descriptor *)w->f14), (unsigned char)w->f1c);
    h = w->f14;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
    w->fc = (int)func_0203101C(heap, heap, 1, 0x20);
    func_0201F73C((void *)w->f14, 0, d, (unsigned char)c);
    return w;
}








void func_021E8628(char *p)
{
    if (((struct Obj01960 *)p)->f8 != 0) {
        func_0201CE48(((struct Obj01960 *)p)->f8);
        ((struct Obj01960 *)p)->f8 = 0;
    }
    if (*(unsigned char * *)&((struct Obj01960 *)p)->f10 != 0) {
        func_0202F038(*(unsigned char * *)&((struct Obj01960 *)p)->f10);
        ((struct Obj01960 *)p)->f10 = 0;
    }
    if (((struct Obj01960 *)p)->f34 != 0)
        func_02028604(((struct Obj01960 *)p)->f34);
    func_02031140(((struct Obj01960 *)p)->fC);
    func_0201F7A8(((struct Obj01960 *)p)->f14, 0);
    func_020452E8(((struct Obj01960 *)p)->f14);
    func_02045808(((struct Obj01960 *)p)->f18);
    func_0201C4C0(((struct Obj01960 *)p)->f28);
    func_020307B0(p);
}








void func_021E867C(char *p)
{
 void *q;
 func_0201C4E4(((struct Obj00842 *)p)->f28);
 switch(((struct Obj00842 *)p)->f2C) {
 case 2:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && func_0201C6C4(q,(void *)((unsigned)func_02045770(((struct Obj00842 *)p)->f20)))==0) {
 func_02045334(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 break;
 case 0:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && func_0201C6C4(q,(void *)((unsigned)func_02045770(((struct Obj00842 *)p)->f20)))==0) {
 func_02045334(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 ((struct Obj00842 *)p)->f30=((struct Obj00842 *)p)->f24==0;
 break;
 case 1:
 if(((struct Obj00842 *)p)->f8!=0) {
 if(((struct Obj00842 *)p)->f34!=0)func_020286C4(((struct Obj00842 *)p)->f34,((struct Obj00842 *)p)->f8,((struct Obj00842 *)p)->f14);
 if(func_02028484((struct Blk *)(p+0x38),((struct Obj00842 *)p)->f8)!=0)((struct Obj00842 *)p)->f30=1;
 }
 break;
 case 3:break;
 }
 func_020310C4(((struct Obj00842 *)p)->fC);
}







void func_021E8738(int *p, int a, int b, int c)
{
    func_02045CAC((struct MsgBank *)a, b, (void *)(((struct Obj24449 *)p)->f18));
    func_021E8754((S_021E8754 *)p, c);
}







/*
 * note 2026-10-02: all code matches except the case 2 arm: original ends it with an
 *   explicit `b` onto the immediately following case 0 block (+2 bytes, 238 vs 240).
 *   Fallthrough case 2 -> case 0 emits no such branch. Tried default arm, goto, guarded if.
 *
 * note 2026-10-05: orig layout is dispatch (cmp 0 beq A; cmp 1 beq B; cmp 2 bne end), case 2 block,
 * `b .+2` (0xE7FF), case 0 block A, case 1 block B, join store. Tried: if/else chain with `goto L0` into A (240 B
 * but A laid out first, wrong order); switch with case 2 first and `goto L0` before `case 0: L0:` (the
 * goto to the next label is deleted, 236 B); case 0 body under `if (mode == 0 || mode == 2)` (244 B).
 * None emits the branch to the next instruction. Still DIFF (residue is the 2-byte branch plus shifted offsets).
 *
 * note 2026-10-05 (wD9 lane20): EXACT. Case 2 repeats the whole case 0 body and its own break; cross-jumping
 *   then replaces that copy with a branch to the case 0 block, which is laid out next (the `b .+2`).
 */
void func_021E8754(S_021E8754 *p, int mode)
{
    int q;

    func_0201C6EC((struct PrintSys *)p->f28);
    func_02043B5C(func_02045770((struct Descriptor *)p->f14), (unsigned char)p->f1c);
    if (p->f8 != 0) {
        func_0201CE48((struct Rec3 *)p->f8);
        p->f8 = 0;
    }
    if (p->f34 != 0) {
        func_02028604(p->f34);
        p->f34 = 0;
    }
    func_021E8848((S_021E8848 *)((S_021E8754 *)p));
    switch (mode) {
    case 2:
        p->f10 = (int)func_0202EE30((void *)func_020056BC(), (void *)p->f14, (unsigned char)p->f1c, 0x10, p->f1e);
        q = p->f28;
        func_0201C6FC((struct PrintSys *)q, (u32)func_02045770((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 0:
        q = p->f28;
        func_0201C6FC((struct PrintSys *)q, (u32)func_02045770((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 1:
        if (p->f34 != 0) {
            func_02034714((const char *)d_021E8DEC, 0, (const char *)d_021E8DEC);
        }
        func_02028470((u8 *)p->f38, 2);
        p->f34 = func_02028590(p->f1c, 1, 0, p->f1e);
        p->f8 = func_0201CCE4(p->f14, 0, 0, p->f18, p->f4, func_02012FFC(), p->fc, 0, p->f1e, p->f1c);
        p->f2c = 1;
        break;
    }
    p->f30 = 0;
}






int func_021E8844(const int *p)
{
    return p[0x30 / 4];
}






void func_021E8848(S_021E8848 *p)
{
    p->f30 = 1;
    if (p->f10 != 0) {
        func_0202F038((u8 *)p->f10);
        p->f10 = 0;
        func_02045374((struct Cfg *)p->f14);
        func_020409B4(func_02045730((struct Descriptor *)p->f14));
    }
}






void func_021E8870(S_021E8870 *p)
{
    int r = (int)func_02045770((struct Descriptor *)p->f14);

    func_02043B5C((struct CharBuf *)r, (unsigned char)p->f1c);
    func_02045334((struct Descriptor *)p->f14);
}






void func_021E888C(S_021E888C *p, int a)
{
    int v = (p->f1c & 0x7f) << 1;

    func_021E88B0(p, 0x13, 0x11 - v, 0xc, v, a);
}
