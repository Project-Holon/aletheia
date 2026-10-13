/*
 * file:     x.c
 * unit:     yes
 * function: func_022079C0, func_02207B4C, func_02207B68, func_02207B84, func_02207BAC, func_02207C94, func_02207CC4, func_02207D04, func_02207D60, func_02207D78, func_02207DA0, func_02207E1C, func_02207EA8, func_02207EF0, func_02207F6C, func_02208034, func_022080B0, func_022080F4, func_02208268, func_022082FC, func_02208420, func_02208550, func_02208650, func_0220868C, func_022086F8, func_022087C4, func_02208814, func_02208870, func_022088F4, func_02208900, func_02208918, func_02208924, func_0220893C, func_02208958, func_022089AC, func_022089BC, func_022089D4, func_02208B10, func_02208BFC, func_02208D24, func_02208D38, func_02208D50, func_02208DAC, func_02209068, func_022090A4, func_022090B4, func_02209214
 * address:  0x022079C0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AAD0  0x0220AAD0  data  ov094  a2
 *   d_0220AAC0  0x0220AAC0  data  ov094  a2
 *   d_0220AAD8  0x0220AAD8  data  ov094  a2
 *   d_0220AB0C  0x0220AB0C  data  ov094  a2
 *   d_0220AB2C  0x0220AB2C  data  ov094  a2
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02018584 0x02018584 thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   func_0220793C  0x0220793C  thumb  ov094
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02017E1C 0x02017E1C thumb
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_020437D4 0x020437D4 arm
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_02082A60 0x02082A60 arm
 *   func_02045808 0x02045808 arm
 *   func_020437AC 0x020437AC arm
 *   func_0202D034 0x0202D034 thumb
 *   func_0201F35C 0x0201F35C thumb
 *   func_020061E4 0x020061E4 thumb
 *   tbl_020A1B38  0x020A1B38  data
 *   d_0220AAF0     0x0220AAF0  data   ov094  a4
 *   func_0204B878  0x0204B878  arm
 *   d_0220AAB8     0x0220AAB8  data  ov094  a2
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   func_021F882C 0x021F882C thumb ov094
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   d_0220AB4C 0x0220AB4C data a4
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_02049238 0x02049238 arm
 *   d_0220AED0 0x0220AED0 data a4
 *   d_0220AB6C 0x0220AB6C data a4
 *   d_0220AB7C 0x0220AB7C data a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0200616C 0x0200616C thumb
 *   func_021F89BC 0x021F89BC thumb ov094
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 */
#include "../../matched/include/Obj01911.h"
#include "../../matched/include/Obj18617.h"

struct Obj;
struct Vec2_022079C0;
struct S;
struct QF;
struct Actor;
struct PtS;
struct Bmp;
struct StrObj;
struct Struct36;
struct U16Vec;
struct CharBuf;
struct Obj020437AC;
struct O_022086F8;
struct Node;
struct Bank;
struct PalAnmSlot;
typedef short s16;

typedef struct Point { s16 x, y; } Point;

typedef struct { Point p[2]; } P2;

typedef struct { Point p[6]; } P6;

typedef struct { Point p[8]; } P8;

typedef struct {
    void *h0;
    void *h1;
    void *h2;
    char pc[0x10 - 0xc];
    void *h4;
    void *h3;
    char p18[0x40 - 0x18];
    int state;
    char p44[0x80 - 0x44];
} Ent;

typedef struct {
    char p0[0x40];
    Ent e[1];
} W_022079C0;

typedef unsigned int   u32;

typedef struct {
    char pad[0x70];
    u32 a : 8;
    u32 b : 8;
    u32 c : 12;
    u32 d : 1;
    u32 e : 3;
    char pad2[0x80 - 0x74];
} E_02207B84;

typedef struct {
    char pad[0x40];
    E_02207B84 e[1];
} W_02207B84;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    char p0[0x48];
    int f48, f4c, f50, f54, f58, f5c;
    char p60[8];
    int f68;
    u8 f6c;
    char p6d[3];
    u32 lo : 2;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 f4 : 4;
    u32 f8 : 8;
    u32 mid : 12;
    u32 b28 : 1;
    u32 hi : 3;
    char p74[12];
} E_02207BAC;

typedef struct { char pad[0x40]; E_02207BAC e[8]; } O_022079C0;

struct Flags_022079C0 { u32 bit0:1; u32 bit1:1; u32 bit2:1; u32 middle:25; u32 bit28:1; u32 high:3; };

typedef enum { I0 = 0 } Idx;

typedef struct E_022079C0 {
    char p0[0x44];
    int f44;
    char p48[0x28];
    u32 lo : 3;
    u32 b3 : 1;
    u32 hi : 28;
    char p74[12];
} E_022079C0;

typedef struct O_02207CC4 {
    char pad[0x40];
    E_022079C0 e[8];
} O_02207CC4;

typedef struct E_02207D04 {
    int f0;
    char p4[12];
    int f10;
    int f14;
    char p18[0x58];
    u32 lo : 29;
    u32 flag : 1;
    u32 hi : 2;
    char p74[12];
} E_02207D04;

typedef struct O_02207D04 {
    char pad[0x40];
    E_02207D04 e[8];
} O_02207D04;

struct Flags_02207D04 { u32 low:3; u32 bit3:1; u32 high:28; };

typedef struct {
    unsigned int b0 : 27;
    unsigned int b27 : 1;
    unsigned int b28 : 4;
} Bits;

typedef struct S {
    char p0[8];
    void *f8;
    void *fc;
    char p10[0x38];
    int f48;
    int f4c;
    u32 f50;
    int f54;
    int f58;
    int pad5c;
    int f60;
    int f64;
    int f68;
    u8 f6c;
    u8 pad6d[3];
    u32 lo : 1;
    u32 b1 : 1;
    u32 hi : 30;
    char p74[4];
    int f78;
} S;

typedef struct E_02207E1C {
    char p0[0x48];
    int f48;
    int f4c;
    int f50;
    char p54[0x14];
    int f68;
    int p6c;
    u32 b0 : 1;
    u32 mid : 20;
    u32 x : 5;
    u32 y : 1;
    u32 hi : 5;
    int f74;
    char p78[8];
} E_02207E1C;

typedef struct O_02207E1C {
    char pad[0x40];
    E_02207E1C e[8];
} O_02207E1C;

typedef struct E {
    char p0[0x54];
    int f54;
    int f58;
    int p5c;
    int f60;
    int f64;
    char p68[8];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 hi : 30;
    char p74[12];
} E;

typedef struct O_02207EF0 {
    char pad[0x40];
    E e[8];
} O_02207EF0;

typedef signed short s16_02207EF0;

typedef struct { int w[9]; } Struct36;

typedef struct { void *f0; char p4[0x40]; int f44; } E_022080F4;

typedef struct { void *f0; char p4[0x44 - 4]; int f44; char p48[0x6d - 0x48]; u8 f6d; } E_02208268;

typedef struct { char p0[0x14]; char *f14; } O_02208268;

typedef struct E_022082FC {
    void *f0, *f4, *f8, *fc, *f10;
    char p14[0x34];
    int f48, f4c;
    u32 f50;
    int f54, f58, f5c, f60;
    u32 f64;
    int f68;
    u8 f6c;
    char p6d[0x13];
} E_022082FC;

typedef struct O_022082FC {
    char p0[0x14];
    char *f14;
    char p18[0x28];
    E_022082FC e[8];
    u32 lo:4, b4:1, hi:27;
} O_022082FC;

typedef struct { char p0[0x14]; char *f14; } O_02208420;

typedef struct { char p0[4]; void *f4; char p8[0x44]; int f4c; } E_02208420;

typedef struct { void *f0; char p4[0x40]; int f44; char p48[0x24]; u8 f6c; } E_02208550;

typedef struct { char p0[8]; void *f8; char pc[0x43c]; u16 heap; } O_02208550;

typedef struct { void *f0; char p4[0x6f - 4]; u8 f6f; } E_02208650;

typedef struct { char p0[0x14]; char *f14; } O_02208650;

typedef struct { char p0[0xc]; void *fc; char p10[0x78 - 0x10]; int f78; } E_0220868C;

typedef struct { char p0[0x14]; char *f14; } O_0220868C;

typedef struct E_022086F8 {
    char p0[0x48];
    int f48, f4c, f50, f54, f58, f5c, f60, f64;
    char p68[8];
    u32 b0:1, b1:1, b2:1, b3:1, phase:4, hi:24;
    char p74[12];
} E_022086F8;

typedef struct { char p0[0x40]; E_022086F8 e[8]; } O_022086F8;

typedef short s16_02208650;

typedef struct Ang {
    u32 lo : 5;
    u32 ang : 16;
    u32 hi : 11;
} Ang;

typedef struct E_02208814 {
    int h;
    char pad[124];
} E_02208814;

typedef struct O_02208814 {
    char pad[0x54];
    E_02208814 e[8];
} O_02208814;

typedef struct T7 {
    u32 w[7];
} T7;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef struct {
    int f00;                /* 0x40 in the work area */
    char pad04[0x70 - 0x04];
    struct {
        u32 lo : 3;
        u32 b3 : 1;
        u32 mid : 16;
        u32 b20 : 1;
        u32 hi : 9;
        u32 b30 : 1;
        u32 b31 : 1;
    } flags;                /* 0xb0 */
    char pad74[0x80 - 0x74];
} Row_02207EF0;

typedef struct {
    char pad00[0x40];
    Row_02207EF0 r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 hi : 11;
    } flags;                /* 0x440 */
} W_02208870;

typedef struct {
    char pad[0x440];
    unsigned int a : 2;
    unsigned int f : 1;
} S88F4;

typedef struct {
    char pad[0x440];
    unsigned int a : 2;
    unsigned int b : 1;
} S8900;

typedef struct {
    char pad[0x440];
    unsigned int a : 3;
    unsigned int b : 1;
} S8924;

typedef struct {
    char pad[0x440];
    u32 a : 21;
    u32 b : 1;
    u32 c : 10;
} W_0220893C;

typedef struct {
    int f00;                /* 0x40 in the work area */
    int h04;                /* 0x44 */
    int h08;                /* 0x48 */
    char pad0c[0x14 - 0x0c];
    int h14;                /* 0x54 */
    char pad18[0x40 - 0x18];
    int state;              /* 0x80 */
    char pad44[0x48 - 0x44];
    int f48;                /* 0x88 */
    int f4c;                /* 0x8c */
    char pad50[0x70 - 0x50];
    struct {
        u32 lo : 3;
        u32 b3 : 1;
        u32 mid : 16;
        u32 b20 : 1;
        u32 hi : 9;
        u32 b30 : 1;
        u32 b31 : 1;
    } flags;                /* 0xb0 */
    char pad74[0x80 - 0x74];
} Row_02208958;

typedef struct {
    char pad00[0x40];
    Row_02208958 r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 b21 : 1;
        u32 b22 : 1;
        u32 hi : 9;
    } flags;                /* 0x440 */
} W_02207EF0;

typedef struct { char p0[0x40]; int f40, f44, f48, f4c; char p50[0x20]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; char p74[12]; } E_022089D4;

typedef struct { char p0[0x40]; E_022089D4 e[8]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; int f444; } O_02208958;

typedef struct E_02208B10 {
    void *f0, *f4, *f8, *fc, *f10, *f14;
    char p18[0x2c];
    int f44;
    char p48[0x28];
    unsigned int lo:16, count:4, hi:12;
    char p74[8];
    void *f7c;
} E_02208B10;

typedef struct { int bits[8]; } Masks;

typedef struct { int health; char pad4[4]; u32 active:1; char padc[0x74]; } EntryFlags;

typedef struct { char pad[0xa8]; EntryFlags entries[8]; } Owner;

typedef struct { Owner *owner; int state, mask, count; } State;

typedef struct {
    int f00;                /* 0x40 in the work area */
    int h04;                /* 0x44 */
    int h08;                /* 0x48 */
    char pad0c[0x40 - 0x0c];
    int state;              /* 0x80 */
    char pad44[0x80 - 0x44];
} Row;

typedef struct {
    char pad00[0x40];
    Row r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 hi : 11;
    } flags;                /* 0x440 */
} W_02208D38;

typedef short s16_02208D38;

typedef struct { s16_02208D38 x, y, z, w; } Pos;

typedef struct { s16_02208D38 x, y; } Vec2_022079C0;

typedef struct { void *h; int goal, home, step, frame, wait; Vec2_022079C0 pos; } Entry;

typedef struct {
    u32 h0, h4, h8, hc;
    Entry e[7];
    int state, active, sound;
    u16 heap;
} Work_022079C0;

typedef struct { int side; int idx[6]; } Arg;

typedef struct { s16_02208D38 x0, y0, x1, y1; } Origin;

typedef signed int     s32;

typedef struct {
    int h0;
    int h4;
    int h8;
    int hc;
    struct { int f10; char pad[0x18]; } e[7];
} W_02209068;

typedef struct { char pad[0x10]; Entry entries[7]; int state, active, sound; u16 heap; } Work_02209068;

typedef struct { Work_02209068 *owner; } Context;

typedef struct { char pad[0xd8]; int fd8; } W_02209214;

extern void func_0204B404(struct Obj *p, const struct Vec2_022079C0 *delta, u32 which);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021D5444(struct QF *p);
extern u32 func_02018584(u16, u16, u16);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0220793C(char *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02017E1C(void *, u32, u32);
extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *, s16_02207EF0, s16_02207EF0, void *, void *);
extern void *func_020437D4(const struct Bmp *bmp);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void func_02082A60(const void *, void *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *p);
extern int func_0202D034(u32, u32);
extern void func_0201F35C(void *, int, u32, u32, u32);
extern void func_020061E4(u32 a);
extern void func_0204B878(struct Obj *p, u16 value);
extern int GFL_USE_IsBgmFading(void);
extern int GFL_USE_PopBgm(void);
extern int func_021F882C(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void GFL_USE_FadeInBgmFull(u32);
extern int GFL_USE_PushBgm(void);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32);
extern void func_02030EAC(struct Node *n);
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int PALANM_RequestFade(void *, u16, u16, s16_02207EF0, u8, u8, u16, void *);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern int func_0200F300(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int func_0209C2B0(int a, int b);
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern void func_0200616C(void *, int);
extern void func_021F89BC(void *);
extern W_02209214 **func_02030EE8(void *h);
void func_022079C0(W_022079C0 *p, int i, Point *off);
void func_02207B4C(char *p, int i, int n);
void func_02207B68(char *p, int i, int n);
void func_02207B84(W_02207B84 *p, int i, int c);
void func_02207BAC(O_022079C0 *o, void *q, int idx);
int func_02207C94(u8 *p);
void func_02207CC4(O_02207CC4 *obj, int a, int c);
void func_02207D04(O_02207D04 *obj, int a, int idx);
int func_02207D60(u8 *p, int index);
int func_02207D78(char *p, int i);
void func_02207DA0(void *obj, S *q, int n);
void func_02207E1C(O_02207E1C *obj, int idx);
void func_02207EA8(S *p, int a);
void func_02207EF0(O_02207EF0 *obj, int idx);
int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
u8 func_02208034(u32 a, int b, int c, u32 *pp, u8 *out, u8 n);
int func_022080B0(int a, int b, int c, unsigned int d);
void func_022080F4(char *o, E_022080F4 *e, void *data);
void func_02208268(O_02208268 *o, E_02208268 *e);
void func_022082FC(O_022082FC *o, int idx, int k);
void func_02208420(const O_02208420 *o, E_02208420 *e, int v);
void func_02208550(O_02208550 *o, E_02208550 *e);
void func_02208650(O_02208650 *o, E_02208650 *e);
void func_0220868C(O_0220868C *o, E_0220868C *e, int c);
void func_022086F8(O_022086F8 *o, int i);
void func_022087C4(char *obj, int a);
void func_02208814(O_02208814 *obj, int k, int idx);
void func_02208870(W_02208870 *w, int sel);
unsigned int func_022088F4(S88F4 *p);
void func_02208900(S8900 *p, int v);
void func_02208918(char *p, int v);
void func_02208924(S8924 *p, int v);
void func_0220893C(W_0220893C *p, int v);
int func_02208958(W_02207EF0 *w, int i, int *o1, int *o2);
void func_022089AC(W_02207EF0 *w);
void func_022089BC(char *p, int i);
void func_022089D4(O_02208958 *o);
void func_02208B10(void *h, E_02208B10 *e);
void func_02208BFC(void *unused, State *s);
void func_02208D24(int a);
int func_02208D38(int a, int b, int c);
void func_02208D50(W_02208D38 *w, int i, int b);
Work_022079C0 *func_02208DAC(const Arg *arg, u32 heapId);
void func_02209068(W_02209068 *w);
int func_022090A4(int *p);
void func_022090B4(void *task, void *arg);
void func_02209214(void *h);
extern const P2 d_0220AAD0;
extern const P2 d_0220AAC0;
extern const P6 d_0220AAD8;
extern const P8 d_0220AB0C;
extern const P8 d_0220AB2C;
extern s16_02208650 tbl_020A1B38[];
extern T7 d_0220AAF0;
extern const Pt d_0220AAB8;
extern const Masks d_0220AB4C;
extern const char d_0220AED0[];
extern const Origin d_0220AB6C[];
extern const u32 d_0220AB7C[][5];








void func_022079C0(W_022079C0 *p, int i, Point *off)
{
    P6 tC;
    P8 tD;
    P8 tE;
    Point pos;
    P2 tA;
    P2 tB;
    int x;
    int y;

    tA = d_0220AAD0;
    tB = d_0220AAC0;
    tC = d_0220AAD8;
    tD = d_0220AB0C;
    tE = d_0220AB2C;
    if (p->e[i].state == 2) {
        x = tD.p[i].x;
        y = tD.p[i].y;
    } else if (p->e[i].state == 3) {
        x = tE.p[i].x;
        y = tE.p[i].y;
    } else {
        x = tC.p[i].x;
        y = tC.p[i].y;
    }
    if (off != 0) {
        x += off->x;
        y += off->y;
    }
    pos.x = x;
    pos.y = y;
    func_0204B404(p->e[i].h0, (const struct Vec2_022079C0 *)(&pos), 0);
    if ((i & 1) == 0 && p->e[i].state == 0) {
        pos.x = x + 16;
        pos.y = y + 13;
        func_0204B404(p->e[i].h1, (const struct Vec2_022079C0 *)(&pos), 0);
    } else if ((i & 1) == 0 && p->e[i].state != 1) {
        pos.x = x + 16;
        pos.y = y + 7;
        func_0204B404(p->e[i].h1, (const struct Vec2_022079C0 *)(&pos), 0);
    }
    pos.x = x + tA.p[i & 1].x;
    pos.y = y + tA.p[i & 1].y;
    func_0204B404(p->e[i].h2, (const struct Vec2_022079C0 *)(&pos), 0);
    pos.x = x + tB.p[i & 1].x;
    pos.y = y + tB.p[i & 1].y;
    func_0204B404(p->e[i].h3, (const struct Vec2_022079C0 *)(&pos), 0);
    if (p->e[i].h4 != 0) {
        pos.x = x + 8;
        pos.y = y + 21;
        func_0204B404(p->e[i].h4, (const struct Vec2_022079C0 *)(&pos), 0);
    }
}








/*
 * lane O10 candidate
 */
void func_02207B4C(char *p, int i, int n)
{
    func_02207DA0(p, (struct S *)(p + 0x40 + (i << 7)), n);
    *(int *)(p + (i << 7) + 0xb4) = 1;
}








void func_02207B68(char *p, int i, int n)
{
    func_02207DA0(p, (struct S *)(p + 0x40 + (i << 7)), n);
    *(int *)(p + (i << 7) + 0xb4) = 0;
}








void func_02207B84(W_02207B84 *p, int i, int c)
{
    p->e[i].b = 0;
    p->e[i].d = 1;
    func_02207EA8((struct S *)(&p->e[i]), c);
}







/*
 * extent: matched ov094_func_02207C94.c and its existing shard cover the
 *   48-byte follower at 02207C94; retain this lead as a single function.
 */
void func_02207BAC(O_022079C0 *o, void *q, int idx)
{
    int delta;
    u32 next;
    delta = o->e[idx].f58 - o->e[idx].f54;
    o->e[idx].f48 = func_021D59B4(q, 13);
    o->e[idx].f4c = func_021D59B4(q, 14);
    o->e[idx].f50 = (int)0x80000000;
    o->e[idx].f68 = 0;
    o->e[idx].f6c = func_021D59B4(q, 15);
    next = func_02018584(func_021D5444(q), func_021D59B4(q, 19), func_021D59B4(q, 15) + 1);
    o->e[idx].f5c = next - func_02018584(func_021D5444(q), func_021D59B4(q, 19), func_021D59B4(q, 15));
    o->e[idx].f4 = 0;
    o->e[idx].b2 = 1;
    o->e[idx].f8 = 0;
    o->e[idx].b28 = 1;
    func_02207EA8((struct S *)(&o->e[idx]), delta);
}






int func_02207C94(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        struct Flags_022079C0 *f;
        f = (struct Flags_022079C0 *)(p + 0xb0 + (i << 7));
        if (f->bit0 || f->bit1 || f->bit2 || f->bit28) return 1;
    }
    return 0;
}






/*
 * Lever: an enum-typed loop counter keeps the entry guard (cmp r4,#8; bge)
 * that a plain int counter rotates away.
 */
void func_02207CC4(O_02207CC4 *obj, int a, int c)
{
    Idx i;

    for (i = I0; i < 8; i = (Idx)(i + 1)) {
        if (c == 2 || c == obj->e[i].f44) {
            if (obj->e[i].b3) {
                func_02207D04((O_02207D04 *)obj, a, (int)i);
            }
        }
    }
}






void func_02207D04(O_02207D04 *obj, int a, int idx)
{
    obj->e[idx].flag = a;
    func_0204B3DC((struct Obj *)obj->e[idx].f0, a);
    func_02208D50((W_02208D38 *)obj, idx, a);
    if (obj->e[idx].f10 != 0) {
        func_0204B3DC((struct Obj *)obj->e[idx].f10, a);
    }
    if (obj->e[idx].f14 != 0) {
        if (CLACT_GetActorAnimSeq((struct Obj *)obj->e[idx].f14) != 0) {
            func_0204B3DC((struct Obj *)obj->e[idx].f14, a);
        }
    }
}






int func_02207D60(u8 *p, int index)
{
    if (((struct Flags_02207D04 *)(p + (index << 7) + 0xb0))->bit3) return 1;
    return 0;
}







/*
 * lane S13 leaf of func_0220680C
 */
int func_02207D78(char *p, int i)
{
    int r = 0;

    if (*(int *)(p + i * 128 + 0x40) != 0) {
        Bits *q = (Bits *)(p + 0xb0 + i * 128);

        r = q->b27;
        q->b27 = 0;
    }
    return r;
}







/*
 * Lever: q->f48 is read from the struct in both statements (no local), so
 * the load stays after the 0x50 store.
 */
void func_02207DA0(void *obj, S *q, int n)
{
    s16 v[2];

    q->f50 = 0x80000000;
    q->f68 = q->f48 - n;
    if (q->f48 < 0) {
        q->f48 = 0;
    }
    if (q->f48 > q->f4c) {
        q->f48 = q->f4c;
    }
    q->lo = 1;
    if (q->f68 > 0) {
        func_0220793C((char *)q);
        func_0204B454(q->f8, (struct PtS *)v, 0);
        v[0] = v[0] - (s16)(0x30 - q->f78);
        func_0204B404(q->fc, (const struct Vec2_022079C0 *)v, 0);
        func_0204B3DC(q->fc, 1);
        func_0220868C((O_0220868C *)obj, (E_0220868C *)q, q->f78);
    }
}





void func_02207E1C(O_02207E1C *obj, int idx)
{
    E_02207E1C *e;
    int r;

    e = &obj->e[idx];
    r = func_02207F6C(e->f4c, e->f48, e->f68, &e->f50, (int)6, (u16)e->f74);
    func_022082FC((O_022082FC *)obj, idx, 0);
    if (r == -1) {
        e->f48 = e->f48 - e->f68;
        func_02208420((O_02208420 *)obj, (E_02208420 *)e, e->f48);
        e->b0 = 0;
        e->f50 = 0;
        if (e->f68 > 0) {
            e->x = 18;
            e->y = 1;
        }
    } else {
        func_02208420((O_02208420 *)obj, (E_02208420 *)e, r);
    }
}





/*
 * Lever: the clamp bound p->f58 is read from the struct twice (no local).
 */
void func_02207EA8(S *p, int a)
{
    int t;
    int x;

    if (p->f6c != 100) {
        t = p->f54;
        p->f64 = 0x80000000;
        x = t + a;
        if (x < 0) {
            a -= x;
        }
        x = t + a;
        if (x > p->f58) {
            a -= x - p->f58;
        }
        p->f60 = -a;
        if (p->f54 < 0) {
            p->f54 = 0;
        }
        if (p->f54 > p->f58) {
            p->f54 = p->f58;
        }
        p->b1 = 1;
    }
}









void func_02207EF0(O_02207EF0 *obj, int idx)
{
    E *e;
    int k;
    int q;
    int r;

    e = &obj->e[idx];
    k = func_022080B0(e->f54, e->f60, e->f58, 10);
    if (k == 0) {
        k = 1;
    }
    q = e->f60 / k;
    if (q < 0) {
        q = -q;
    }
    if (q == 0) {
        q = 1;
    }
    r = func_02207F6C(e->f58, e->f54, e->f60, &e->f64, (int)10, (u16)q);
    func_022082FC((O_022082FC *)obj, idx, 1);
    if (r == -1) {
        e->f54 = e->f54 - e->f60;
        e->b1 = 0;
        e->f64 = 0;
    }
}









int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed)
{
    u8 lim;
    int t;
    int v;
    int d;

    lim = x * 8;
    if (*cur == (int)0x80000000) {
        if (n < lim)
            *cur = target << 8;
        else
            *cur = target;
    }
    t = target - delta;
    if (t < 0)
        t = 0;
    else if (t > n)
        t = n;
    if (n < lim) {
        if (t == (*cur >> 8) && (*cur & 0xff) == 0)
            return -1;
    } else if (t == *cur) {
        return -1;
    }
    if (n < lim) {
        d = (n << 8) / lim;
        if (delta < 0) {
            *cur += d;
            v = *cur >> 8;
            if (v >= t || speed == 0) {
                *cur = t << 8;
                return t;
            }
        } else {
            *cur -= d;
            v = *cur >> 8;
            if ((*cur & 0xff) > 0)
                v++;
            if (v <= t || speed == 0) {
                *cur = t << 8;
                return t;
            }
        }
    } else {
        if (delta < 0) {
            *cur += speed;
            if (*cur > t || speed == 0)
                *cur = t;
        } else {
            *cur -= speed;
            if (*cur < t || speed == 0)
                *cur = t;
        }
        v = *cur;
    }
    return v;
}









/*
 * Levers: n is a u8 stack parameter (ldrb [sp,#0x1c]); the return value is a
 * separate copy `ret` of the running count (declared before the loop index j
 * so ret takes r2 and j r3).
 */
u8 func_02208034(u32 a, int b, int c, u32 *pp, u8 *out, u8 n)
{
    int lim;
    int i;
    u32 total;
    u32 v;
    u32 ret;
    int j;

    lim = b - c;
    if (lim < 0) {
        lim = 0;
    } else if (lim > (int)a) {
        lim = a;
    }
    total = n * 8;
    for (i = 0; i < n; i++) {
        out[i] = 0;
    }
    if (a < total) {
        v = (*pp * total) / a >> 8;
    } else {
        v = (*pp * total) / a;
    }
    ret = v;
    if (v == 0 && lim > 0) {
        ret = 1;
        out[0] = 1;
    } else {
        for (j = 0; j < n; j++) {
            if (v >= 8) {
                out[j] = 8;
                v -= 8;
            } else {
                out[j] = v;
                break;
            }
        }
    }
    return ret;
}








int func_022080B0(int a, int b, int c, unsigned int d)
{
    int k;
    int x;
    int p;
    int q;
    int r;

    k = (d << 27) >> 24;
    x = a - b;
    if (x < 0) {
        x = 0;
    } else if (x > c) {
        x = c;
    }
    p = (a * k) / c;
    q = (x * k) / c;
    r = (signed char)p - (signed char)q;
    r = (signed char)r;
    if (r < 0) {
        r = -r;
    }
    return r;
}








/*
 * lever: an enum VRAM base assigned in both copy arms prevents folding
 *   each base-plus-offset into a separate literal pool word.
 */
void func_022080F4(char *o, E_022080F4 *e, void *data)
{
    void *v, *bmp;
    char *pixels;
    Struct36 buf;
    u8 c[3];
    enum { VRAM_BASE = 0x06400000 } vram;
    v = func_020457B0(12, (u16)((((struct Obj01911 *)o)->f448 & 0x7fff) | 0x8000));
    bmp = func_02043678(8, 2, 32, (u16)((((struct Obj01911 *)o)->f448 & 0x7fff) | 0x8000));
    func_02043B5C(bmp, 0);
    func_02017E1C(data, 0x73, (u32)v);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 4, 0);
    if ((int)func_0201D304(v, (u32)(((struct Obj01911 *)o)->f8), (int)0) > 48)
        func_0201C7A4(bmp, 2, 5, v, ((struct Obj01911 *)o)->f8);
    else
        func_0201C7A4(bmp, 8, 5, v, ((struct Obj01911 *)o)->f8);
    func_0201DD78(c[2], c[1], c[0]);
    pixels = func_020437D4(bmp);
    CLACT_GetActorImageProxy(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        vram = VRAM_BASE;
        func_02082A60(pixels, (void *)(vram + 0x40 + buf.w[1]), 0xc0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x140 + buf.w[1]), 0xc0);
        func_02082A60(pixels + 0xc0, (void *)(vram + 0x400 + buf.w[1]), 0x40);
        func_02082A60(pixels + 0x1c0, (void *)(vram + 0x500 + buf.w[1]), 0x40);
    } else {
        vram = VRAM_BASE;
        func_02082A60(pixels, (void *)(vram + 0x20 + buf.w[1]), 0xe0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x120 + buf.w[1]), 0xe0);
        func_02082A60(pixels + 0xe0, (void *)(vram + 0x400 + buf.w[1]), 0x20);
        func_02082A60(pixels + 0x1e0, (void *)(vram + 0x500 + buf.w[1]), 0x20);
    }
    func_02045808(v);
    func_020437AC(bmp);
}









void func_02208268(O_02208268 *o, E_02208268 *e)
{
    Struct36 buf;
    int off1;
    int off2;
    enum { VRAM_BASE = 0x06400000 } vram;

    off1 = e->f6d * 64 + 0x380;
    off2 = e->f6d * 64 + 0x3a0;
    if (e->f6d == 2) {
        off1 = 0x660;
        off2 = 0x660;
    }
    CLACT_GetActorImageProxy(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        vram = VRAM_BASE;
        func_02082A60(o->f14 + off1, (void *)(vram + 0x440 + buf.w[1]), 0x20);
        func_02082A60(o->f14 + off2, (void *)(vram + 0x540 + buf.w[1]), 0x20);
    } else {
        vram = VRAM_BASE;
        func_02082A60(o->f14 + off1, (void *)(vram + 0x420 + buf.w[1]), 0x20);
        func_02082A60(o->f14 + off2, (void *)(vram + 0x520 + buf.w[1]), 0x20);
    }
}








/*
 * trailing: 0220841E..02208420 is two bytes of zero alignment padding.
 * lever: u8 count retains the result spill; enum VRAM base preserves add
 *   order and register home; zero the loop counter before assigning base.
 */
void func_022082FC(O_022082FC *o, int idx, int k)
{
    E_022082FC *e;
    u8 a[10];
    Struct36 buf;
    int color, val;
    u8 n, i;
    enum { VRAM = 0x06400000 } base;
    e = &o->e[idx];
    switch (k) {
    case 0:
        if (o->b4 && !(idx & 1)) break;
        CLACT_GetActorImageProxy(e->f8, (struct Struct36 *)(&buf));
        n = func_02208034(e->f4c, e->f48, e->f68, &e->f50, a, 6);
        val = e->f50;
        if (e->f4c < 48) val >>= 8;
        switch (func_0202D034(val, e->f4c)) {
        case 0: color = 0; break;
        case 1: color = 0x120; break;
        case 2:
        default: color = 0x240; break;
        }
        for (i = 0; i < 6; i++) {
            base = VRAM;
            func_02082A60(o->f14 + (color + a[i] * 32), (void *)(buf.w[1] + (base + (i + 1) * 32)), 32);
        }
        if (e->f68 > 0) func_0220868C((O_0220868C *)o, (E_0220868C *)e, n);
        break;
    case 1:
        if (e->f10 == 0) break;
        CLACT_GetActorImageProxy(e->f10, (struct Struct36 *)(&buf));
        func_02208034(e->f58, e->f54, e->f60, &e->f64, a, 10);
        if (e->f6c == 100) {
            for (i = 0; i < 10; i++) a[i] = 0;
        }
        i = 0;
        base = VRAM;
        for (; i < 10; i++) {
            func_02082A60(o->f14 + (a[i] * 32 + 0x400), (void *)(buf.w[1] + (base + (i + 1) * 32)), 32);
        }
        break;
    }
}








void func_02208420(const O_02208420 *o, E_02208420 *e, int v)
{
    Struct36 buf;
    u16 current[3];
    u16 maximum[3];
    int i, n, j;
    enum { VRAM = 0x06400000 } base;
    if (e->f4 != 0) {
        CLACT_GetActorImageProxy(e->f4, (struct Struct36 *)(&buf));
        for (i = 0; i < 3; i++) {
            current[i] = 0x660;
            maximum[i] = 0x660;
        }
        if (v >= 100) {
            current[0] = v / 100 * 32 + 0x520;
            v %= 100;
        }
        if (v >= 10 || current[0] != 0x660) {
            current[1] = v / 10 * 32 + 0x520;
            v %= 10;
        }
        current[2] = v * 32 + 0x520;
        n = e->f4c;
        j = 0;
        if (n >= 100) {
            maximum[j] = n / 100 * 32 + 0x520;
            n %= 100;
            j++;
        }
        if (n >= 10 || j != 0) {
            maximum[j] = n / 10 * 32 + 0x520;
            n %= 10;
            j++;
        }
        maximum[j] = n * 32 + 0x520;
        i = 0;
        base = VRAM;
        for (; i < 3; i++) {
            func_02082A60(o->f14 + current[i], (void *)(buf.w[1] + (base + i * 32)), 32);
            func_02082A60(o->f14 + maximum[i], (void *)(buf.w[1] + (base + (i + 4) * 32)), 32);
        }
    }
}








/*
 * lever: initialize the reusable heap offset; assign enum VRAM in each
 *   copy arm; split addr = base; addr = addr + off and add buf.w[1] last.
 */
void func_02208550(O_02208550 *o, E_02208550 *e)
{
    void *v, *bmp;
    char *pixels;
    Struct36 buf;
    u8 c[3];
    u32 off = 0x448;
    int addr;
    enum { VRAM = 0x06400000 } base;
    v = func_020457B0(4, (u16)((*(u16 *)((char *)o + off) & 0x7fff) | 0x8000));
    bmp = func_02043678(3, 2, 32, (u16)((*(u16 *)((char *)o + off) & 0x7fff) | 0x8000));
    func_02043B5C(bmp, 0);
    func_0201F35C(v, e->f6c, 3, 0, 0);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 4, 0);
    func_0201C7A4(bmp, 0, 5, v, o->f8);
    func_0201DD78(c[2], c[1], c[0]);
    pixels = func_020437D4(bmp);
    CLACT_GetActorImageProxy(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        base = VRAM;
        off += 0x38;
        addr = base;
        addr = addr + off;
        func_02082A60(pixels, (void *)(addr + buf.w[1]), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x580 + buf.w[1]), 0x60);
    } else {
        base = VRAM;
        off += 0x18;
        addr = base;
        addr = addr + off;
        func_02082A60(pixels, (void *)(addr + buf.w[1]), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x560 + buf.w[1]), 0x60);
    }
    func_02045808(v);
    func_020437AC(bmp);
}








void func_02208650(O_02208650 *o, E_02208650 *e)
{
    Struct36 buf;
    int off;
    enum { VRAM_BASE = 0x06400000 } vram;

    off = 0x360;
    if (e->f6f == 0)
        off = 0x660;
    CLACT_GetActorImageProxy(e->f0, (struct Struct36 *)(&buf));
    vram = VRAM_BASE;
    func_02082A60(o->f14 + off, (void *)(vram + 0x120 + buf.w[1]), 0x20);
}








void func_0220868C(O_0220868C *o, E_0220868C *e, int c)
{
    u8 cnt[6];
    Struct36 buf;
    int n;
    int i;
    enum { VRAM_BASE = 0x06400000 } vram;

    n = e->f78 - c;
    for (i = 0; i < 6; i++)
        cnt[i] = 8;
    for (i = 5; i >= 0; i--) {
        if (n >= 8) {
            cnt[i] = 0;
            n -= 8;
        } else {
            cnt[i] = 8 - n;
            break;
        }
    }
    CLACT_GetActorImageProxy(e->fc, (struct Struct36 *)(&buf));

    i = 0;
    vram = VRAM_BASE;
    for (; i < 6; i++)
        func_02082A60(o->f14 + (cnt[i] * 32 + 0x6a0), (void *)(vram + i * 32 + buf.w[1]), 0x20);
}







void func_022086F8(O_022086F8 *o, int i)
{
    E_022086F8 *e;
    e = &o->e[i];
    if (e->b1 == 0) {
        switch (e->phase) {
        case 0:
            func_020061E4(0x56e);
            e->phase++;
            break;
        case 1:
            e->phase++;
            break;
        case 2:
            e->f54 = 0;
            e->f58 = e->f5c;
            e->f64 = 0x80000000;
            e->f60 = 0;
            func_02207F6C(e->f4c, e->f48, 0, &e->f50, 6, 1);
            func_02207F6C(e->f58, e->f54, 0, &e->f64, 10, 1);
            func_022082FC((O_022082FC *)((struct O_022086F8 *)o), i, 0);
            func_022082FC((O_022082FC *)((struct O_022086F8 *)o), i, 1);
            func_02208420((const O_02208420 *)o, (E_02208420 *)e, e->f48);
            func_02208550((O_02208550 *)o, (E_02208550 *)e);
            e->b2 = 0;
            break;
        }
    }
}








/*
 * Levers: the angle is read into an int local (asrs, not lsrs); the
 * increment goes through a second cast pointer expression so the word is
 * reloaded instead of CSE'd.
 */
void func_022087C4(char *obj, int a)
{
    s16_02208650 v[2];
    Ang *f;
    int i;

    f = (Ang *)(obj + 0x440);
    v[0] = -16;
    i = f->ang;
    v[1] = tbl_020A1B38[2 * (i >> 4)] / 0x800;
    ((Ang *)(obj + 0x440))->ang += 0x400;
    func_022079C0((W_022079C0 *)obj, a, (Point *)v);
}








void func_02208814(O_02208814 *obj, int k, int idx)
{
    T7 t = d_0220AAF0;

    if (obj->e[idx].h != 0) {
        if (k == 0) {
            func_0204B3DC((struct Obj *)obj->e[idx].h, 0);
            func_0204B878((struct Obj *)obj->e[idx].h, 0);
        } else {
            func_0204B3DC((struct Obj *)obj->e[idx].h, 1);
            func_0204B878((struct Obj *)obj->e[idx].h, t.w[k]);
        }
    }
}







void func_02208870(W_02208870 *w, int sel)
{
    Pt b;
    Pt a = d_0220AAB8;
    int i;

    for (i = 0; i < 8; i++) {
        if (w->r[i].f00 != 0 && w->r[i].flags.b20) {
            b = a;
            w->r[i].flags.b20 = 0;
            func_022079C0((W_022079C0 *)w, i, (Point *)&b);
        }
    }
    if (sel != 8) {
        w->r[sel].flags.b20 = 1;
        w->flags.mid = 0;
    }
}







unsigned int func_022088F4(S88F4 *p)
{
    return p->f;
}







void func_02208900(S8900 *p, int v)
{
    p->b = v;
}







void func_02208918(char *p, int v)
{
    ((struct Obj18617 *)p)->f444 = v;
}







void func_02208924(S8924 *p, int v)
{
    p->b = v;
}







void func_0220893C(W_0220893C *p, int v)
{
    p->b = v;
}






int func_02208958(W_02207EF0 *w, int i, int *o1, int *o2)
{
    if (w->r[i].f00 == 0 || !w->r[i].flags.b3 || w->r[i].flags.b30) {
        *o1 = 0;
        *o2 = 8;
        return 0;
    }
    *o1 = func_0202D034(w->r[i].f48, w->r[i].f4c);
    *o2 = CLACT_GetActorAnimSeq((struct Obj *)w->r[i].h14);
    if (*o2 == 0)
        *o2 = 8;
    return 1;
}






void func_022089AC(W_02207EF0 *w)
{
    w->flags.b22 = 1;
}





void func_022089BC(char *p, int i)
{
    if (*(int *)(p + (i << 7) + 0x40) != 0)
        *(unsigned int *)(p + 0xb0 + (i << 7)) |= 0x40000000;
}





void func_022089D4(O_02208958 *o)
{
    int busy, found, i;
    if (o->b1) {
        if (GFL_USE_IsBgmFading() != 0) return;
        o->b1 = 0;
        if (o->b2) {
            GFL_USE_PopBgm();
            if (!o->b3 && func_021F882C() != 0) {
                GFL_USE_CancelChangeAndPlayBgm(o->f444, 0xffff);
                o->b3 = 1;
            } else {
                func_02208D24(0);
            }
            GFL_USE_FadeInBgmFull(24);
        } else {
            func_02208D24(1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x47a, 0xffff);
        }
        o->b2 ^= 1;
        return;
    }
    busy = 0;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (o->e[i].b0 || o->e[i].b1 || o->e[i].b2) {
            busy = 1;
        } else if (o->e[i].f44 == 0 && o->e[i].b3 && o->e[i].f40 != 4) {
            if (func_0202D034(o->e[i].f48, o->e[i].f4c) == 2) found = 1;
        }
    }
    if (!o->b2 && o->f444 != GFL_USE_GetBgmNo()) return;
    if (busy != 0) return;
    if ((o->b2 && found == 0) || (!o->b2 && found == 1)) {
        o->b1 = 1;
        GFL_USE_FadeOutBgm(8);
    }
}





void func_02208B10(void *h, E_02208B10 *e)
{
    int step;
    s16_02207EF0 v[2];
    if (e->f44 != 0) step = 8;
    else step = -8;
    func_0204B454(e->f0, (struct PtS *)v, 0);
    v[0] += (s16_02207EF0)step;
    func_0204B404(e->f0, (const struct Vec2_022079C0 *)v, 0);
    func_0204B454(e->f8, (struct PtS *)v, 0);
    v[0] += (s16_02207EF0)step;
    func_0204B404(e->f8, (const struct Vec2_022079C0 *)v, 0);
    func_0204B454(e->f14, (struct PtS *)v, 0);
    v[0] += (s16_02207EF0)step;
    func_0204B404(e->f14, (const struct Vec2_022079C0 *)v, 0);
    if (e->f44 == 0) {
        func_0204B454(e->f4, (struct PtS *)v, 0);
        v[0] += (s16_02207EF0)step;
        func_0204B404(e->f4, (const struct Vec2_022079C0 *)v, 0);
    }
    if (e->f10 != 0) {
        func_0204B454(e->f10, (struct PtS *)v, 0);
        v[0] += (s16_02207EF0)step;
        func_0204B404(e->f10, (const struct Vec2_022079C0 *)v, 0);
    }
    e->count--;
    if (e->count == 0) {
        func_02030EAC(h);
        e->f7c = 0;
    }
}





/*
 * lever: owner->entries[i] preserves the base/index register ordering;
 *   raw-offset EntryFlags casts and a named raw owner leave four bytes out.
 */
void func_02208BFC(void *unused, State *s)
{
    Masks masks = d_0220AB4C;
    int i;
    void *pal;
    switch (s->state) {
    case 0:
        s->mask = 0;
        for (i = 0; i < 8; i++) {
            if (s->owner->entries[i].active && s->owner->entries[i].health > 0)
                s->mask |= masks.bits[i];
        }
        if (s->mask) {
            pal = (void *)func_021F86E0();
            PALANM_RequestFade(pal, 4, s->mask, 0, 0, 8, 16, func_021F86D4());
            s->state = 1;
        }
        break;
    case 1:
        if (!PALANM_GetFadeRequestBits((const char *)func_021F86E0())) {
            pal = (void *)func_021F86E0();
            PALANM_RequestFade(pal, 4, s->mask, 0, 8, 0, 16, func_021F86D4());
            s->state = 2;
        }
        break;
    case 2:
        if (!PALANM_GetFadeRequestBits((const char *)func_021F86E0())) {
            s->count++;
            if (s->count == 3) {
                s->count = 0;
                s->state = 3;
            } else {
                s->state = 0;
            }
        }
        break;
    case 3:
        for (i = 0; i < 8; i++) {
            if (s->owner->entries[i].active)
                break;
        }
        if (i == 8)
            s->state = 0;
        break;
    }
}






void func_02208D24(int a)
{
    if (func_0200F300() != 1)
        GFL_USE_SetBgmPlayerParam((void *)a);
}





int func_02208D38(int a, int b, int c)
{
    int r = func_0209C2B0(a * c, b);
    if (r == 0 && a != 0)
        r = 1;
    return r;
}





/*
 * Lever: the flag word at 0x440 is a bitfield struct (bit 4 read as
 * lsls #27 / lsrs #31); a plain u32 with `(f >> 4) & 1` gives lsrs/ands
 * and a different register assignment.
 */
void func_02208D50(W_02208D38 *w, int i, int b)
{
    if ((w->r[i].state == 2 || w->r[i].state == 3) && b == 1 && (i & 1) == 0) {
        func_0204B3DC((struct Obj *)w->r[i].h04, w->flags.b4);
        func_0204B3DC((struct Obj *)w->r[i].h08, w->flags.b4 ? 0 : 1);
    } else {
        func_0204B3DC((struct Obj *)w->r[i].h04, b);
        func_0204B3DC((struct Obj *)w->r[i].h08, b);
    }
}




/*
 * lever: const Arg * lets the side load schedule above the pos zero stores;
 *   pos is initialised in an inner block (a top-level initializer is
 *   emitted at function entry); the stack locals are declared arc, heap,
 *   base so they land at 0x1c, 0x18, 0x14.
 */
Work_022079C0 *func_02208DAC(const Arg *arg, u32 heapId)
{
    void *arc;
    int heap;
    int base;
    Work_022079C0 *w;
    Work_022079C0 **ctx;
    int i;

    heap = (heapId & 0x7fff) | 0x8000;
    w = func_02030734(heap, 0xe4, 1, d_0220AED0, 0x7a);
    arc = func_020490F4(0xb, (u16)heap);
    w->heap = heap;
    w->h0 = (u32)func_0204B100(7, 0, w->heap);
    w->h4 = func_0204A6C8(arc, 0xbd, 0, 0, w->heap);
    w->h8 = func_0204AF28(arc, 0xbf, 0xc0, w->heap);
    w->hc = func_0204ABF0(arc, 0xbe, 0, 0xc0, w->heap);
    func_020216D4((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(w->hc, 0) >> 1), 0x20);
    {
    Pos pos = {0, 0, 0, 0};
    int side = arg->side;
    base = d_0220AB6C[side].x0;
    pos.x = base + (side == 0 ? 0x80 : -0x80);
    pos.y = d_0220AB6C[arg->side].y0;
    for (i = 0; i < 6; i++) {
        w->e[i].h = func_0204B294((void *)w->h0, w->h4, w->hc, w->h8, &pos, 0, w->heap);
        func_0204B454(w->e[i].h, (struct PtS *)&w->e[i].pos, 0);
        func_0204B92C(w->e[i].h, 1);
        func_0204B878(w->e[i].h, d_0220AB7C[arg->side][arg->idx[i]]);
        w->e[i].frame = d_0220AB7C[2][arg->idx[i]];
        w->e[i].wait = (i + 1) * 6;
        w->e[i].home = base;
        w->e[i].goal = base + (i + 1) * (arg->side == 0 ? -2 : 2);
        w->e[i].step = arg->side == 0 ? -12 : 12;
        base += arg->side == 0 ? 15 : -15;
    }
    pos.x = d_0220AB6C[arg->side].x1 + (arg->side == 0 ? 0x80 : -0x80);
    pos.y = d_0220AB6C[arg->side].y1;
    w->e[i].h = func_0204B294((void *)w->h0, w->h4, w->hc, w->h8, &pos, 0, w->heap);
    func_0204B454(w->e[i].h, (struct PtS *)&w->e[i].pos, 0);
    func_0204B92C(w->e[i].h, 1);
    func_0204B878(w->e[i].h, d_0220AB7C[arg->side][4]);
    w->e[i].frame = d_0220AB7C[arg->side][4];
    w->e[i].wait = 0;
    w->e[i].home = w->e[i].goal = d_0220AB6C[arg->side].x1;
    w->e[i].step = arg->side == 0 ? -0x10 : 0x10;
    ctx = func_02030734(heap, 4, 0, d_0220AED0, 0xec);
    *ctx = w;
    func_021F896C(func_02030DA8(func_021F86D4(), func_022090B4, ctx, 0), func_02209214, 0);
    w->active = 1;
    func_02049238(arc);
    func_020061E4(0x570);
    return w;
    }
}



void func_02209068(W_02209068 *w)
{
    int i;

    for (i = 0; i < 7; i++)
        func_0204B3B4((struct Obj *)w->e[i].f10);
    func_0204A8D4(w->h4);
    func_0204ADA4(w->hc);
    func_0204AFD8(w->h8);
    func_0204B1CC((struct Bank *)w->h0);
    func_020307B0(w);
}



int func_022090A4(int *p)
{
    if (p[0xd8 / 4 + 0] != 0)
        return 1;
    return 0;
}


/*
 * lever: set busy before decrementing the delay; reversed statements
 *   interchange the movs and str at +002C/+002E.
 */
void func_022090B4(void *task, void *arg)
{
    Context *c = arg;
    int i;
    int busy = 0;
    int sound;
    switch (c->owner->state) {
    case 0:
        for (i = 0; i < 7; i++) {
            if (c->owner->entries[i].wait != 0) {
                busy = 1;
                c->owner->entries[i].wait--;
            } else if (c->owner->entries[i].step != 0) {
                c->owner->entries[i].pos.x += (s16)c->owner->entries[i].step;
                busy = 1;
                if (c->owner->entries[i].step > 0) {
                    if (c->owner->entries[i].pos.x >= c->owner->entries[i].goal) {
                        c->owner->entries[i].pos.x = c->owner->entries[i].goal;
                        c->owner->entries[i].step = 0;
                    }
                } else {
                    if (c->owner->entries[i].pos.x <= c->owner->entries[i].goal) {
                        c->owner->entries[i].pos.x = c->owner->entries[i].goal;
                        c->owner->entries[i].step = 0;
                    }
                }
                func_0204B404(c->owner->entries[i].h, (const struct Vec2_022079C0 *)(&c->owner->entries[i].pos), 0);
                if (c->owner->entries[i].step == 0) {
                    func_0204B878(c->owner->entries[i].h, c->owner->entries[i].frame);
                    switch (c->owner->entries[i].frame) {
                    case 9: sound = 0x572; break;
                    case 10:
                    case 11: sound = 0; break;
                    default: sound = 0x571; break;
                    }
                    if (sound != 0) {
                        func_0200616C((void *)sound, c->owner->sound);
                        c->owner->sound ^= 1;
                    }
                }
            }
        }
        if (!busy) c->owner->state++;
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            if (c->owner->entries[i].pos.x < c->owner->entries[i].home) {
                c->owner->entries[i].pos.x += 2;
                if (c->owner->entries[i].pos.x >= c->owner->entries[i].home)
                    c->owner->entries[i].pos.x = c->owner->entries[i].home;
                busy = 1;
            } else if (c->owner->entries[i].pos.x > c->owner->entries[i].home) {
                c->owner->entries[i].pos.x -= 2;
                if (c->owner->entries[i].pos.x <= c->owner->entries[i].home)
                    c->owner->entries[i].pos.x = c->owner->entries[i].home;
                busy = 1;
            }
            func_0204B404(c->owner->entries[i].h, (const struct Vec2_022079C0 *)(&c->owner->entries[i].pos), 0);
        }
        if (!busy) func_021F89BC(task);
        break;
    }
}



void func_02209214(void *h)
{
    (*func_02030EE8(h))->fd8 = 0;
}
