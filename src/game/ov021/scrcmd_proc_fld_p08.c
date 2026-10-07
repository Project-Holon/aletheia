/*
 * file:     scrcmd_proc_fld_p08.c
 * unit:     yes
 * function: func_021B4984, func_021B49EC, func_021B4AA4, func_021B4BA4, func_021B4BEC, func_021B4C14, func_021B4C34, func_021B4C54, func_021B4C98, func_021B4CDC, func_021B4D14, func_021B4D60, func_021B4E58, func_021B4E9C, func_021B4EE0, func_021B4F1C, func_021B4F68, func_021B4FB0, func_021B5008, func_021B503C, func_021B5094, func_021B50D0, func_021B50F8, func_021B5128, func_021B5154, func_021B5190, func_021B51BC, func_021B52A4, func_021B52E0, func_021B52FC, func_021B536C, func_021B538C, func_021B53A4, func_021B53BC, func_021B542C, func_021B5498, func_021B54D4, func_021B54FC, func_021B5528, func_021B55C8, func_021B55F0, func_021B5610, func_021B5650, func_021B568C
 * address:  0x021B4984
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
 *   func_021B4878 0x021B4878 thumb ov021
 *   func_021B4894 0x021B4894 thumb ov021
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020212B0 0x020212B0 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021B42D0 0x021B42D0 thumb ov021
 *   func_021B4804 0x021B4804 thumb ov021
 *   func_02041300  0x02041300  arm
 *   d_021D9654     0x021D9654  data  a4
 *   func_02012138  0x02012138  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021896F4  0x021896F4  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CE4  0x02009CE4  thumb
 *   func_02009A34  0x02009A34  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020124AC  0x020124AC  thumb
 *   abs_id_6       0x00000006  data
 *   func_02154C20  0x02154C20  thumb  ov006
 *   abs_id_4       0x00000004  data
 *   func_021542C0  0x021542C0  thumb  ov004
 *   abs_id_01        0x00000001  data
 *   func_02154694  0x02154694  thumb  ov001
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BB58  0x0200BB58  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0200BBFC  0x0200BBFC  thumb
 *   func_02014840  0x02014840  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE220     0x021DE220  data  a1
 *   ov170_id       0x000000AA  data  a1
 *   d_021EF78C     0x021EF78C  data  ov170  a4
 *   func_021CD2A4  0x021CD2A4  thumb  ov021
 *   func_02011290  0x02011290  thumb
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_0215F8A8  0x0215F8A8  thumb  ov010
 *   func_02009210  0x02009210  thumb
 *   func_020090D8  0x020090D8  thumb
 *   func_02168BBC  0x02168BBC  thumb  ov010
 *   func_020146F8  0x020146F8  thumb
 *   abs_id_DB      0x000000DB  data
 *   d_02185F0C     0x02185F0C  data  ov219  a4
 *   func_021C5BD0  0x021C5BD0  thumb  ov021
 *   func_021D30B8  0x021D30B8  thumb  ov021
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA0A0  0x021AA0A0  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012A44  0x02012A44  thumb
 *   func_0216EFCC  0x0216EFCC  thumb  ov010
 *   func_0216E95C  0x0216E95C  thumb  ov010
 *   func_021AAB48  0x021AAB48  thumb  ov021
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0215E440  0x0215E440  thumb  ov010
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02005728  0x02005728  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   d_021DE234     0x021DE234  data  a1
 *   d_021D98D0     0x021D98D0  data  a2
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02159144  0x02159144  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218FA40  0x0218FA40  thumb  ov021
 *   func_021D2D50  0x021D2D50  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_021F36C8  0x021F36C8  thumb  ov056
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   ov56_id        0x00000038  data  a1
 *   g_021F4344     0x021F4344  data  ov056  a4
 *   g_021F4374     0x021F4374  data  ov056  a4
 *   g_021F438C     0x021F438C  data  ov056  a4
 *   g_021F435C     0x021F435C  data  ov056  a4
 */
#include "../../matched/include/Obj01121.h"
#include "../../matched/include/Obj00030.h"

struct WordSet;
struct Ctx;
struct Sub020097BCObj;
struct BigObj;
struct Pair;
struct Desc;
struct Big;
struct Blk37;
struct Obj;
struct Sub02008700Obj;
struct ScriptVm;
struct Sub020090B0Obj;
struct Sub02009210Obj;
struct Blk38;
struct Stream;
struct Cursor;
struct Blk021D2D50;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
} Rect;

typedef signed char    s8;

typedef struct {
    void *a;
    u32 b;
} Pair;

typedef struct {
    u8  pad0[8];
    u32 f8;
    u8  pad1[0x18];
    u32 f24;
    u16 f28;
} Sub;

typedef struct {
    u32 a;
    u16 *out;
    Sub *s;
} Work;

/* 0x2c-byte work block built here and handed to the ov170 process */
typedef struct {
    void *w;            /* 0x00 */
    u32 f04;            /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0C;            /* 0x0c */
    u8 *f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1C;            /* 0x1c */
    u32 f20;            /* 0x20 */
    u32 kind;           /* 0x24 */
    u32 f28;            /* 0x28 */
} Work021B4D60;

/* 0xc-byte record passed alongside it */
typedef struct {
    void *w;                /* 0x00 */
    unsigned short *name;   /* 0x04 */
    Work021B4D60 *work;     /* 0x08 */
} Rec021B4D60;

typedef struct {
    u16 id : 11;
    u16 lv : 5;
    u16 pad;
} Ent;

typedef struct {
    u8  pad0[5];
    u8  hasA;
    u8  hasB;
    u8  pad7[0xc0 - 7];
    Ent a[5];
    Ent b[5];
} Rec_021B51BC;

typedef struct {
    u32 pad0[3];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 pad18[3];
    u16 h24;
    u16 h26;
    u32 f28;
    u32 pad2c;
    u32 w30[6];
} Out_021B53BC;

typedef struct { u32 w[3]; } V12;

typedef struct { u32 w[6]; } V24;

typedef struct {
    u16 h0;
    u16 h2;
    u32 f4;
    V12 v8;
    V24 v14;
} Src;

typedef struct {
    u32 pad0[3];
    V12 v0c;
    u32 pad18[3];
    u16 h24;
    u16 h26;
    u32 f28;
    u32 pad2c;
    V24 v30;
} Out_021B542C;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    u16 hc;
    u8 be;
    u8 bf;
    u32 w10;
    u32 w14;
} Rec_021B5528;

typedef enum { B_FALSE, B_TRUE } Bool;

extern int func_021B4878(u32 a);
extern void func_021B4894(char *w, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_020212B0(u32 a);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 se);
extern void func_021B42D0(char *w, u32 a, u32 b);
extern void func_021B4804(char *w, u32 b);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012138(const struct Ctx *p);
extern int func_021896F4(void *p);
extern u32 func_02009CE4(struct Sub020097BCObj *obj);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_0215A5E4(void *a0);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void *func_0215A5F4(void *p);
extern void func_0215897C(void *a, void *b);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int func_02154C20(int x, struct Pair *p);
extern int func_021542C0(int x, struct Pair *p);
extern void *func_02154694(void *p, int a);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void func_0200BB58(u8 *a0, u8 *a1);
extern u32 func_020307B0(void *p);
extern u32 func_02159B10(void *c, void *vm);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_0201293C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern u32 func_0200BBFC(struct Obj *p, u32 mask);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d);
extern void *func_0215F8A8(void *p, int a1);
extern void func_0215898C(int a, int b);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090D8(struct Sub020090B0Obj *obj, u8 value);
extern void *func_02168BBC(void *a, void *b);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void *func_021C5BD0(void *a, u32 b, u32 c);
extern void *func_021D30B8(void *, u16 *);
extern void *func_02158F54(void *p);
extern int func_02158F58(int a0);
extern u32 func_02188CE8(u8 *p);
extern u32 func_021AA0A0(u32 a, u32 b, u32 c, u32 d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_02012A44(const struct BigObj *p);
extern u8 func_0216EFCC(int i);
extern void *func_0216E95C(void *sys, u32 arg, u32 heap);
extern u16 func_021AAB48(char *p);
extern void *func_0200D418(void *sys);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern void func_0215E440(void *sys, u8 which);
extern int func_0215E2B8(Rec_021B51BC *r, void *h, u32 k, u32 x);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_02005728(u32 range);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *h);
extern u32 func_02159168(u32);
extern u32 func_02188C5C(u8 *p);
extern u32 func_02188CFC(u8 *p);
extern void func_0218F05C(unsigned char *a);
extern int func_0218F0F8(u8 *a);
extern void func_0218F878(u8 *a);
extern u32 func_021BB260(u32, u32);
extern void *func_02188C58(void *p);
extern void func_02159144(int n);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0218F0A8(u8 *a);
extern void func_0218F818(u8 *a);
extern void func_0218EC54(u8 *p);
extern int func_0218EC60(u32 a);
extern u16 func_02011330(struct Stream *s);
extern u32 func_0201134C(struct Cursor *p);
extern void func_0218F900(u8 *a, void *p, int n);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0218F9C4(void *, u32 *, u32);
extern void func_0218FA40(u8 *p, u16 v);
extern void *func_021D2D50(void *a, struct Blk021D2D50 *src);
extern void *func_020124E4(struct Obj *p);
extern u32 func_0218F0E8(u8 *a);
extern int func_0218FE50(u8 *a);
extern void *func_021F36C0(void *a, u8 *b, u32 c);
extern u32 func_021F36C8(u32 idx);
extern void func_0218E17C(u32 *p, u32 v);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
void func_021B4984(char *w, u32 a, u32 b, u32 c);
int func_021B49EC(s16 *p, int max, int key);
int func_021B4AA4(char *w);
void func_021B4BA4(int i);
int func_021B4BEC(u32 a, u32 b);
int func_021B4C14(u32 a, u32 b);
int func_021B4C34(u32 a, u32 b);
int func_021B4C54(u32 a, u32 b);
int func_021B4C98(u32 a, u32 b);
int func_021B4CDC(u32 a, u32 b);
void func_021B4D14(volatile Work *w);
/* c arrives as the command object and is then reused for the new work block (one register; a separate local changes codegen) */ int func_021B4D60(Work021B4D60 *c, void *vm);
int func_021B4E58(u32 a, u32 b);
int func_021B4E9C(u32 a, u32 b);
int func_021B4EE0(u32 a, u32 b);
int func_021B4F1C(u32 a, u32 b);
int func_021B4F68(u32 a, u32 b);
int func_021B4FB0(u32 a, u32 b);
int func_021B5008(u32 a, u32 b);
int func_021B503C(u32 a, u32 b);
int func_021B5094(u32 a, u32 b);
int func_021B50D0(u32 a, u32 b);
int func_021B50F8(u32 a, u32 b);
int func_021B5128(u32 a, u32 b);
int func_021B5154(u32 a, u32 b);
u16 func_021B5190(u16 *arr, u16 n, u16 v);
int func_021B51BC(void *a, void *b);
int func_021B52A4(void *a, u32 b);
int func_021B52E0(void **p);
int func_021B52FC(u32 a, u32 b);
int func_021B536C(u32 a, u32 b);
int func_021B538C(u32 a, u32 b, u32 c, u32 d);
int func_021B53A4(u32 a, u32 b, u32 c, u32 d);
int func_021B53BC(struct Cursor *a0, int a1);
int func_021B542C(int a0, int a1);
int func_021B5498(u32 a, u32 b);
int func_021B54D4(u32 a, u32 b, u32 c, u32 d);
int func_021B54FC(void *a, void *b);
int func_021B5528(int a0, int a1);
int func_021B55C8(void *a);
int func_021B55F0(void *a);
int func_021B5610(void *a0, void *a1);
int func_021B5650(void *a, void *b);
int func_021B568C(int a0, int a1);
extern const Rect d_021D9654[];
extern u8 abs_id_6[];
extern u8 abs_id_4[];
extern u8 abs_id_01[];
extern const char d_021DE220[];
extern char ov170_id[];
extern const u8 d_021EF78C[];
extern u8 abs_id_DB[];
extern u8 d_02185F0C[];
extern const char d_021DE234[];
extern const u16 d_021D98D0[];
extern u8 ov56_id[];
extern u32 g_021F4344[];
extern u32 g_021F4374[];
extern u32 g_021F438C[];
extern u32 g_021F435C[];


void func_021B4984(char *w, u32 a, u32 b, u32 c)
{
    func_021B4878(((struct Obj01121 *)w)->f17C);
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 0, b - 327, 2, 2, 1);
    func_0201EF34((struct WordSet *)(((struct Obj01121 *)w)->f190), 1, func_020212B0(b));
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 2, c, 5, 0, 1);
    func_021B4894((char *)((u32)w), a);
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B49EC(s16 *p, int max, int key)
{
    int s = *p;
    switch (key) {
    case -1:
        *p = s - 1;
        if (*p <= 0) *p = max;
        if (*p == s) return 0;
        return 2;
    case -10:
        *p = s - 10;
        if (*p <= 0) *p = 1;
        if (*p == s) return 0;
        return 2;
    case 1:
        *p = s + 1;
        if (*p > max) *p = 1;
        if (*p == s) return 0;
        return 1;
    case 10:
        *p = s + 10;
        if (*p > max) *p = max;
        if (*p == s) return 0;
        return 1;
    }
    return 0;
}


int func_021B4AA4(char *w)
{
    if (func_0203633C() & 0x40) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, 1) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    } else if (func_0203633C() & 0x80) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, -1) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    } else if (func_0203633C() & 0x20) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, -10) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    } else if (func_0203633C() & 0x10) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, 10) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    }
    if (func_020362DC() & 1) {
        func_020061E4(0x54C);
        func_021B4804(w, ((struct Obj00030 *)w)->f162);
        *(u8 *)&((struct Obj00030 *)w)->f1 = 6;
        return 10;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        return 4;
    }
    return 3;
}


/*
 * d_021D9654 is a const table of 16-byte {x, y, w, h} records (two of them
 * in the listing: {0,12,32,12}, {0,12,32,6}). Without const the loads for
 * the register arguments cannot pass the first stack-argument store and
 * are issued after it; func_02041300's u8 parameters follow the ldrb reads
 * of its stack arguments (as in src/matched/arm9/func_0201F628.c).
 * Addresses are Black-image addresses.
 */
void func_021B4BA4(int i)
{
    func_02041300(1, 0, d_021D9654[i].x, d_021D9654[i].y, d_021D9654[i].w, d_021D9654[i].h, 0);
}


int func_021B4BEC(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_021896F4((void *)func_02012138(d));
    return 1;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B4C14(u32 a, u32 b)
{
*func_02159AE8((void *)a, (void *)b) = func_02009CE4((struct Sub020097BCObj *)func_0201283C(func_0215A5E4((void *)b)));
return 0;
}


int func_021B4C34(u32 a, u32 b)
{
*func_02159AE8((void *)a, (void *)b) = func_02009A34((struct Sub020097BCObj *)func_0201283C(func_0215A5E4((void *)b)));
return 0;
}


int func_021B4C54(u32 a, u32 b)
{
    Pair p;
    void *r5;
    void *r4;

    r5 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    p.a = func_0201210C((void *)r4);
    p.b = 0;
    func_0215897C(r5, func_020124AC(r4, (u32)abs_id_6, (void *)func_02154C20, (u32)(&p)));
    return 1;
}


int func_021B4C98(u32 a, u32 b)
{
    Pair p;
    void *r5;
    void *r4;

    r5 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    p.a = func_0201210C((void *)r4);
    p.b = 0;
    func_0215897C(r5, func_020124AC(r4, (u32)abs_id_4, (void *)func_021542C0, (u32)(&p)));
    return 1;
}


/*
 * 2026-10-02: closed by seeding ov001 0x02154694 (Thumb tail-call thunk to
 * func_0215466C, filed as ov001_func_02154694.c). Old note: it sat inside ov001 pool_02154690
 * (ldr r3,[pc]; bx r3; .word func_0215466C+1) so sole-ref/code finds no func_ label;
 * abs_id_01 is the overlay id 1 that func_020124AC loads (not an OVERLAY_ID_CONSUMER).
 *
 * Addresses are Black-image addresses.
 */
int func_021B4CDC(u32 a, u32 b)
{
    void *r5;
    void *r4;

    r5 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    func_0215897C(r5, func_020124AC(r4, (u32)abs_id_01, (u32 (*)(void *, u32))func_02154694, (u32)func_0201210C((void *)r4)));
    return 1;
}


void func_021B4D14(volatile Work *w)
{
    u32 r1;
    u32 v;
    Sub *s;

    if (w->s->f24 == 4) {
        func_0200BB58(func_0200BAC8(func_02012EBC((struct Big *)w->a)), (u8 *)w->s->f8);
    }
    s = w->s;
    if (s->f24 == 4) {
        func_020307B0((void *)s->f8);
    }
    v = w->s->f28;
    if (v == 0 || v != 1)
        r1 = 0;
    else
        r1 = 1;
    *w->out = r1;
    func_020307B0(w->s);
}


/* c arrives as the command object and is then reused for the new work block (one register; a separate local changes codegen) */
/*
 * Script command: builds a 0x2C-byte work (save handles, the hand-off kind
 * at +0x24) and a 12-byte hand-off record, then launches overlay 0xAA
 * (ov170) over them through func_02014840 with the func_021B4D14 callback
 * and parks the task in the script's slot.  Same shape as the ov010
 * pending func_0215C7E0.
 *
 * The work pointer is written back into the first parameter (c): with a
 * separate local, c/work and the save handle w swap r4/r5 whatever the
 * declaration order (docs/idioms/reassigning-a-parameter-to-the-callee-
 * result-keeps-its-register.md).
 *
 * Blocker (MATCH, every concrete byte right, 24 of 25 sites resolved): the
 * pool word 0x000000AA (ov170_id, +0xF0) has no witness.  It is the
 * overlay-id argument (r2) of func_02014840, which is not in
 * OVERLAY_ID_CONSUMERS; func_02014840 (EXACT, arm9) stores its a2 as
 * p[2] of the item func_020122C0 creates, the same shape as the
 * func_02012444 case ov000 func_021542C0's header describes.  Adding
 * 0x02014840 with register 2 to OVERLAY_ID_CONSUMERS (integrator's call,
 * after reading the item's state machine) would resolve it.  ov021 holds
 * one other 0xAA pool word (0x021D5598), yet match.py still reports no
 * witness: a small overlay-id value resolves only through that consumer
 * table, so no cut helps.
 *
 * Addresses are Black-image addresses.
 */
int func_021B4D60(Work021B4D60 *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    void *y;
    void *z;
    unsigned short *r7;
    u32 kind;
    Rec021B4D60 *h;
    void *s;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_02012EBC(w);
    y = func_0200CA1C(w);
    z = func_0201210C(sys);
    r7 = func_02159AE8(c, vm);
    kind = func_02159B10(c, vm);
    c = func_02030734(4, 0x2c, 0, d_021DE220, 0x7c);
    c->w = w;
    c->f04 = func_0201293C(w);
    c->f08 = func_02012934(w);
    c->f0C = (u32)func_0201292C(w);
    c->f10 = func_02012944(w);
    c->f18 = (u32)func_0200873C(x);
    c->f1C = func_0200CA38(y);
    c->kind = kind;
    c->f14 = 0;
    if (kind == 4) {
        s = func_0200BAC8(x);
        c->f08 = func_0200BAF4((int)s, 4);
        c->f14 = func_0200BBFC(s, 3);
    }
    h = func_02030734(4, 0xc, 0, d_021DE220, 0x90);
    h->w = w;
    h->name = r7;
    h->work = c;
    func_0215897C(slot, func_02014840(sys, (int)z, (u32)ov170_id, (int)d_021EF78C, (int)c, (int)((void *)func_021B4D14), (int)h));
    return 1;
}


int func_021B4E58(u32 a, u32 b)
{
    void *r6;
    void *r7;
    void *z;

    r6 = func_0215A5F4((void *)b);
    r7 = func_0215A5DC((void *)b);
    z = func_0201210C((void *)r7);
    func_0215897C(r6, (void *)func_021CD2A4((u32)r7, (u32)z, 0, 5, (u32)func_02159AE8((void *)a, (void *)b)));
    return 1;
}


int func_021B4E9C(u32 a, u32 b)
{
    void *r6;
    void *r7;
    void *z;

    r6 = func_0215A5F4((void *)b);
    r7 = func_0215A5DC((void *)b);
    z = func_0201210C((void *)r7);
    func_0215897C(r6, (void *)func_021CD2A4((u32)r7, (u32)z, 0, 6, (u32)func_02159AE8((void *)a, (void *)b)));
    return 1;
}


int func_021B4EE0(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);

    func_0201210C((void *)d);
    func_0215898C((int)s, (int)func_0215F8A8(d, func_02159B10((void *)a, (void *)b)));
    func_02011290((struct ScriptVm *)a);
    return 1;
}


int func_021B4F1C(u32 a, u32 b)
{
    u32 r7;
    u32 r5;
    void *r6;
    void *r4;

    r7 = (u32)func_02009210(func_02012EBC(func_0215A5E4((void *)b)));
    r5 = func_02159B10((void *)a, (void *)b);
    r6 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    func_020090D8((struct Sub020090B0Obj *)r7, 1);
    func_0215897C(r6, func_02168BBC(r4, (void *)r5));
    return 1;
}


int func_021B4F68(u32 a, u32 b)
{
    void *r5;
    void *r4;
    void *r6;

    r5 = func_0215A5DC((void *)b);
    r4 = func_0215A5F4((void *)b);
    r6 = func_0201210C((void *)r5);
    func_0215897C(r4, func_020146F8(r5, (int)r6, (int)abs_id_DB, (int)d_02185F0C, (int)func_020120F4(r5)));
    return 1;
}


int func_021B4FB0(u32 a, u32 b)
{
    void *r0;
    void *r7;
    u32 r4;
    unsigned short *x;
    u32 y;

    r0 = func_0215A5F4((void *)b);
    r7 = func_0215A5DC((void *)b);
    func_02012EBC(func_020120F4(r7));
    func_0201210C((void *)r7);
    r4 = func_02159B10((void *)a, (void *)b);
    x = func_02159AE8((void *)a, (void *)b);
    if (r4 == 0 || r4 != 1)
        y = 0;
    else
        y = 1;
    func_0215897C(r0, func_021C5BD0(r7, y, (u32)x));
    return 1;
}


int func_021B5008(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);

    func_0215897C(s, func_021D30B8(d, func_02159AE8((void *)a, (void *)b)));
    return 1;
}


int func_021B503C(u32 a, u32 b)
{
    void *r4;
    u32 s0;
    u32 r7;
    u32 r5;

    r4 = func_0215A5F4((void *)b);
    s0 = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159B10((void *)a, (void *)b);
    func_02158F54(r4);
    func_0215897C(r4, (void *)func_021AA0A0(func_02188CE8((u8 *)(((u32 *)func_02158F58((int)r4))[1])), s0, (u8)r7, r5));
    return 1;
}


int func_021B5094(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);

    func_0215897C(s, (void *)func_021BE92C(d, (int)func_0201210C((void *)d), 0, 0, 1, 0, 0));
    return 1;
}


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021B50D0(u32 a, u32 b)
{
    u32 x = func_02012A44(func_0215A5E4((void *)b));
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_0216EFCC(x);
    return 0;
}


int func_021B50F8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);

    func_0215897C(s, func_0216E95C(d, (u32)func_0201210C((void *)d), 4));
    return 1;
}


int func_021B5128(u32 a, u32 b)
{
    void *w = func_0201210C(func_0215A5DC((void *)b));
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_021AAB48((char *)func_02188CE8(w));
    return 0;
}


int func_021B5154(u32 a, u32 b)
{
    void *e = func_0215A5E4((void *)b);
    u32 g = (u32)func_0200D418(func_02012EBC(e));
    u8 k = func_02159B10((void *)a, (void *)b);

    if (func_0200D488((struct Blk38 *)g, k) == 0) {
        func_0215E440(e, k);
    }
    return 0;
}


u16 func_021B5190(u16 *arr, u16 n, u16 v)
{
    int i;

    for (i = 0; i < n; i++) {
        if (v == arr[i]) {
            return n;
        }
    }
    arr[n] = v;
    return n + 1;
}


/*
 * func_0215E2B8 clears and fills a 0xE8-byte record (its own memset size).
 *
 * Addresses are Black-image addresses.
 */
int func_021B51BC(void *a, void *b)
{
    Rec_021B51BC rec;
    u32 x;
    u16 i;
    void *h;
    u16 *out;
    void *sys;
    u16 *list;
    u16 j;
    u16 n;

    n = 0;
    sys = func_0215A5E4(b);
    out = func_02159AE8(a, b);
    x = func_02012984(sys);
    h = func_020490F4(0x7e, 0x8015);
    list = func_02030734(0x8015, 0x78, 1, d_021DE234, 0xf8);
    for (i = 0; i < 6; i++) {
        if (func_0215E2B8(&rec, h, d_021D98D0[i], x)) {
            if (rec.hasA) {
                for (j = 0; j < 5; j++) {
                    n = func_021B5190(list, n, rec.a[j].id);
                }
            }
            if (rec.hasB) {
                for (j = 0; j < 5; j++) {
                    n = func_021B5190(list, n, rec.b[j].id);
                }
            }
        }
    }
    *out = list[func_02005728(n)];
    func_020307B0(list);
    func_02049238(h);
    return 0;
}


int func_021B52A4(void *a, u32 b)
{
func_0218F878((u8 *)b);
if (func_0218F0F8((u8 *)b) != 0) {
    func_0218F05C((unsigned char *)b);
}
if (func_02188CFC((u8 *)a) == 1) {
    func_021BB260(func_02188C5C((u8 *)a), 1);
}
return func_02159168(0);
}


int func_021B52E0(void **p)
{
    void *w = func_0201210C(p[0]);

    func_021B52A4(w, (u32)func_02188C58(w));
    return 1;
}


int func_021B52FC(u32 a, u32 b)
{
    void *r6;
    void *r4;
    void *r5;

    r6 = func_0215A5DC((void *)b);
    r4 = func_0201210C((void *)r6);
    r5 = func_02188C58(r4);
    func_02159144(0);
    if (func_0218F0F8(r5) != 0) {
        func_0218F0A8(r5);
        r5 = func_0215A5F4((void *)b);
        func_0215897C(r5, func_020122C0(r6, 0, (void *)func_021B55C8, 0));
        if (func_02188CFC(r4) == 1) {
            func_021BB260(func_02188C5C(r4), 0);
        }
    } else {
        func_0218F818(r5);
    }
    return 1;
}


int func_021B536C(u32 a, u32 b)
{
    void *w = func_0201210C(func_0215A5DC((void *)b));

    func_021B52A4(w, (u32)func_02188C58(w));
    return 0;
}


int func_021B538C(u32 a, u32 b, u32 c, u32 d)
{
func_0218EC54(func_02188C58(func_0201210C(func_0215A5DC((void *)b))));
return 0;
}


int func_021B53A4(u32 a, u32 b, u32 c, u32 d)
{
func_0218EC60((u32)func_02188C58(func_0201210C(func_0215A5DC((void *)b))));
return 0;
}


int func_021B53BC(struct Cursor *a0, int a1)
{
    Out_021B53BC o;
    int r4;

    r4 = (int)func_02188C58(func_0201210C(func_0215A5DC((void *)a1)));
    o.h24 = func_02011330((struct Stream *)a0);
    o.h26 = func_02011330((struct Stream *)a0);
    o.f28 = func_0201134C(a0);
    o.f0c = func_0201134C(a0);
    o.f10 = func_0201134C(a0);
    o.f14 = func_0201134C(a0);
    o.w30[0] = 0;
    o.w30[1] = 1;
    o.w30[2] = 1;
    o.w30[3] = 1;
    o.w30[4] = 0;
    o.w30[5] = 1;
    func_0218F900((u8 *)r4, &o, func_02011330((struct Stream *)a0));
    return 0;
}


int func_021B542C(int a0, int a1)
{
    Src s;
    Out_021B542C o;
    int r5;
    int r6;
    int r4;

    r5 = (int)func_02188C58(func_0201210C(func_0215A5DC((void *)a1)));
    r6 = func_02011330((struct Stream *)a0);
    r4 = func_02011330((struct Stream *)a0);
    func_02048F4C(&s, 0xa3, r6);
    o.h24 = s.h0;
    o.h26 = s.h2;
    o.f28 = s.f4;
    o.v0c = s.v8;
    o.v30 = s.v14;
    func_0218F900((u8 *)r5, &o, r4);
    return 0;
}


int func_021B5498(u32 a, u32 b)
{
    u32 v[6];
    void *x = func_02188C58(func_0201210C(func_0215A5DC((void *)b)));
    u32 k = func_02011330((struct Stream *)a);

    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 1;
    v[5] = 1;
    func_0218F9C4(x, v, k);
    return 0;
}


int func_021B54D4(u32 a, u32 b, u32 c, u32 d)
{
func_0218FA40(func_02188C58(func_0201210C(func_0215A5DC((void *)b))), func_02011330((struct Stream *)a));
return 0;
}


int func_021B54FC(void *a, void *b)
{
    void *s = func_0215A5F4(b);
    void *d = func_0215A5DC(b);

    func_0215897C(s, func_020122C0(d, 0, func_021B55F0, 0));
    return 1;
}


int func_021B5528(int a0, int a1)
{
    int v0 = func_02159B10((void *)a0, (void *)a1);
    int v1 = func_02159B10((void *)a0, (void *)a1);
    int v2 = func_02159B10((void *)a0, (void *)a1);
    int v3 = func_02159B10((void *)a0, (void *)a1);
    int v4 = func_02159B10((void *)a0, (void *)a1);
    int v5 = func_02159B10((void *)a0, (void *)a1);
    int v6 = func_02159B10((void *)a0, (void *)a1);
    int v7 = func_02159B10((void *)a0, (void *)a1);
    void *r;
    void *o;
    Rec_021B5528 s;

    r = func_0215A5F4((void *)a1);
    o = func_0215A5DC((void *)a1);
    s.h0 = v0;
    s.h2 = v1;
    s.w10 = v2;
    s.bf = v3;
    s.be = v3;
    s.w14 = 0;
    s.h4 = v4;
    s.h6 = v5;
    s.h8 = v6;
    s.ha = 0;
    s.hc = v7;
    func_0215897C(r, func_021D2D50((void *)o, (struct Blk021D2D50 *)(&s)));
    return 1;
}


int func_021B55C8(void *a)
{
    u8 *x = func_02188C58(func_0201210C(func_020124E4(a)));

    if (func_0218F0E8(x) == 0) {
        func_0218F818(x);
        return 1;
    }
    return 0;
}


int func_021B55F0(void *a)
{
    int x = func_0218FE50(func_02188C58(func_0201210C(func_020124E4(a))));

    return x != 0 ? B_FALSE : B_TRUE;
}


int func_021B5610(void *a0, void *a1)
{
    void *r6 = func_0215A5F4(a1);
    void *r7 = func_0215A5DC(a1);
    u8 *t = func_0201210C(r7);
    unsigned int v = func_02159B10(a0, a1);

    func_0215897C(r6, func_021F36C0(r7, t, (u16)(v - 1)));
    return 1;
}


/*
 * func_021F36C8 is the ov056 slot-table lookup (src/matched/ov/ov056_func_021F36C8.c).
 */
int func_021B5650(void *a, void *b)
{
    void *w = func_0201210C(func_0215A5DC(b));
    unsigned int k = func_02159B10(a, b);
    u32 *x = func_02188C58(w);

    func_0218E17C(x, func_021F36C8((u16)(k - 1)));
    return 0;
}


int func_021B568C(int a0, int a1)
{
    int r4 = func_02188D24(func_0201210C(func_0215A5DC((void *)a1)));

    switch (func_02159B10((void *)a0, (void *)a1)) {
    case 0:
        break;
    case 1:
        func_021BB990((int)ov56_id, (int *)r4, (const int *)g_021F4344);
        break;
    case 2:
        func_021BB990((int)ov56_id, (int *)r4, (const int *)g_021F4374);
        break;
    case 3:
        func_021BB990((int)ov56_id, (int *)r4, (const int *)g_021F438C);
        break;
    case 4:
        func_021BB990((int)ov56_id, (int *)r4, (const int *)g_021F435C);
        break;
    }
    return 0;
}
