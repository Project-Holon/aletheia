/*
 * file:     unit_02184C78.c
 * unit:     yes
 * function: func_02184C78, func_02184CEC, func_02184D38, func_02184D90, func_02184DE8, func_02184E40, func_02184E94, func_02184EEC, func_02184F40, func_02184F88, func_02184FD4, func_02185050, func_021850A8, func_021850FC, func_02185140, func_02185214, func_021852F0, func_02185360, func_02185410, func_02185458, func_021854B0, func_021854CC, func_02185534, func_02185588, func_0218562C, func_02185694, func_0218571C, func_02185758, func_02185788, func_021857C0, func_021858E4, func_02185928, func_021859F0, func_021859FC, func_02185A34, func_02185A68, func_02185B70, func_02185B88, func_02185B9C, func_02185BFC, func_02185C4C, func_02185C8C, func_02185D38
 * address:  0x02184C78
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02173744  0x02173744  thumb  ov012
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BF66C  0x021BF66C  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAAF0  0x021AAAF0  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02184388  0x02184388  thumb  ov020
 *   func_020141A8  0x020141A8  thumb
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02184730  0x02184730  thumb  ov020
 *   func_020128B8  0x020128B8  thumb
 *   func_021847CC  0x021847CC  thumb  ov020
 *   func_02185F18  0x02185F18  thumb  ov020
 *   func_02184894  0x02184894  thumb  ov020
 *   func_02012914  0x02012914  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02159F94  0x02159F94  thumb  ov010
 *   func_0218495C  0x0218495C  thumb  ov020
 *   func_02012894  0x02012894  thumb
 *   func_02184A14  0x02184A14  thumb  ov020
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0201289C  0x0201289C  thumb
 *   func_02184AB4  0x02184AB4  thumb  ov020
 *   func_02184B54  0x02184B54  thumb  ov020
 *   func_02184BF8  0x02184BF8  thumb  ov020
 *   func_020128E4  0x020128E4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02176230  0x02176230  thumb  ov011
 *   func_020128DC  0x020128DC  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026484  0x02026484  thumb
 *   func_02012B78  0x02012B78  thumb
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A36BC  0x021A36BC  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02012870  0x02012870  thumb
 *   func_02013E7C  0x02013E7C  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02162694  0x02162694  thumb  ov010
 *   func_021625E8  0x021625E8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02185EB0  0x02185EB0  thumb  ov020
 *   func_02184410  0x02184410  thumb  ov020
 *   func_02012B2C  0x02012B2C  thumb
 *   func_02184584  0x02184584  thumb  ov020
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0218466C  0x0218466C  thumb  ov020
 *   func_02159FA8  0x02159FA8  thumb  ov010
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_0216446C  0x0216446C  thumb  ov010
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_0202C110  0x0202C110  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_020145FC  0x020145FC  thumb
 *   func_021625FC 0x021625FC thumb ov010
 *   func_02012844  0x02012844  thumb
 *   func_02014454  0x02014454  thumb
 *   func_02012AC4  0x02012AC4  thumb
 *   func_02012ACC  0x02012ACC  thumb
 *   func_020141DC  0x020141DC  thumb
 *   func_02012A90  0x02012A90  thumb
 *   func_02012AA4  0x02012AA4  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_0202B544  0x0202B544  thumb
 *   func_02012854  0x02012854  thumb
 *   func_02012900  0x02012900  thumb
 *   func_0202C83C  0x0202C83C  thumb
 *   func_0201405C  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02159FE0  0x02159FE0  thumb  ov010
 *   func_021643E8  0x021643E8  thumb  ov010
 *   func_0215A014  0x0215A014  thumb  ov010
 *   func_02158AE0  0x02158AE0  thumb  ov010
 *   func_0216E29C  0x0216E29C  thumb  ov010
 *   func_0216CCCC  0x0216CCCC  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 *   func_0201444C  0x0201444C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_020127E0  0x020127E0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02186538  0x02186538  thumb  ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02186854  0x02186854  thumb  ov020
 *   func_021868B8  0x021868B8  thumb  ov020
 *   func_0216CF6C  0x0216CF6C  thumb
 *   func_02186470 0x02186470 thumb ov020
 *   func_021864DC 0x021864DC thumb ov020
 *   func_02013F6C 0x02013F6C thumb
 *   func_02014468 0x02014468 thumb
 *   func_0201446C 0x0201446C thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02014450  0x02014450  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013DF0  0x02013DF0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_020129AC  0x020129AC  thumb
 *   func_020129B8  0x020129B8  thumb
 *   func_02012974  0x02012974  thumb
 *   func_02013B44  0x02013B44  thumb
 *   func_02162408  0x02162408  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B37C  0x0200B37C  thumb
 *   func_0200B394  0x0200B394  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_020493D4  0x020493D4  arm
 *   func_02049238  0x02049238  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021BE9F0  0x021BE9F0  thumb  ov021
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_02158630  0x02158630  thumb  ov010
 *   func_021D2750  0x021D2750  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02026400  0x02026400  thumb
 *   func_0217574C  0x0217574C  thumb  ov011
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02175B4C  0x02175B4C  thumb  ov011
 *   func_02039338  0x02039338  arm
 */
#include "../../matched/include/Obj00248.h"
#include "../../matched/include/Obj19456.h"
#include "../../matched/include/Obj05969.h"

struct Evt;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
struct t;
struct Rec1C;
struct Rec44;
struct SaveBlock;
struct Vec12;
struct Big;
struct Obj00020;
struct Obj18028;
struct Sub02014444Obj;
struct H4;
struct Rec020141DC;
struct Rec94;
struct Struct_0200B37C;
struct ArcFile;
struct Comm;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

typedef struct { u16 f0; u16 f2; s16 f4; u16 f6; } Q;

typedef struct { int x, y, z; } Vec;

typedef struct { int f[7]; } S7;

typedef struct { int w[7]; } V28;

typedef unsigned long long u64;

typedef struct { int f0; int f4; int f8; } S3_02184C78;

typedef struct { int f00; u16 f04, f06; int f08[5]; } Rec;

typedef struct { u16 a, b; s16 c; u16 d; } H4;

typedef struct { int a, b, c; } S3_02185214;

typedef struct E { char pad[0x86]; u16 lo : 3; u16 hi : 13; } E;

typedef struct V3 { u32 x, y, z; } V3;

typedef struct { void *owner; void *object; unsigned char payload[0x1c]; } Work;

typedef struct { int kind; s16 h4; u16 h6; s16 h8; u16 ha; int c, d, e, f; } Record;

typedef struct { int id; u16 v; u16 pad; } Ent;

typedef signed int     s32;

typedef struct {
    u8 pad00[0x1c];
    int f1c;
    int f20;
    int f24;
    int f28;
    u8 b2c;
} Ctx;

void func_02012374(struct Evt *evt, struct Evt **out);
void func_02034A5C(int id);
int func_02034AC4(signed int id);
void *func_02161824(void *a, void *b);
void func_02173744(int a);
void *func_02184360(u8 *p, int value);
void *func_021BF66C(int a0, void *p, int a2);
void *func_020120F4(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
u8 func_02012984(const struct BigObj *p);
u16 func_02188C9C(u8 *p);
u32 func_02188CE8(u8 *p);
void func_021AAAF0(int x, int y);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
u32 func_020142A4(u32 idx);
int func_02184388(int a, int *state, u8 *p);
void func_02014184(void *d, int a, s16 b, int c, int e, int f);
void func_020141A8(struct t *p, int b, int d, u16 g, u16 i, s16 h);
int func_02184504(int a, int *state, u8 *p);
int func_02184730(int ctx, int *state, u8 *p);
struct Rec1C *func_020128B8(const struct BigObj *p);
int func_021847CC(int ctx, int *state, u8 *p);
void func_02185F18(void *a, void *b);
int func_02184894(void *a, int *state, struct Obj *o);
u16 func_02012914(const struct BigObj *p);
u16 func_02159F94(int a);
void func_02014204(struct t *p, int id);
int func_0218495C(int ctx, int *state, u8 *p);
struct Rec1C *func_02012894(const struct BigObj *p);
int func_02184A14(int ctx, int *state, u8 *p);
void *func_020127A4(struct SaveBlock *p);
struct Vec12 *func_02012AA0(struct Rec44 *p);
u16 func_02012AC8(const struct Rec44 *p);
u32 func_02012AE4(const struct Rec44 *p);
void func_0201289C(struct BigObj *p, const struct Rec1C *src);
int func_02184AB4(int ctx, int *state, u8 *p);
int func_02184B54(int ctx, int *state, u8 *p);
int func_02184BF8(void *ctx, int *st, int *p);
void func_020128E4(struct BigObj *p, const struct Rec1C *src);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *sys);
int func_02012FCC(int p0);
unsigned long long func_0200BFA4(u8 *p, void *q, u32 mode);
u32 func_02012138(const struct Ctx *p);
u8 func_02012B58(const struct BigObj *p);
int func_02158344(int a0);
int func_02158590(void *p);
u8 func_02176230(u8 *p, u8 *q);
Rec *func_020128DC(void *p);
int func_02013DD0(int v);
u32 func_0202648C(void *p);
u32 func_02026454(void *obj);
void func_02026484(void *p);
struct BigObj *func_02012B78(struct BigObj *p, u8 v);
void func_02012B64(struct BigObj *p, int v);
void func_02012B8C(struct BigObj *p, u32 v);
void func_02012B4C(struct BigObj *p, u8 v);
void *func_02188CB4(struct Obj00020 *p);
int func_021A3238(u8 *p);
void func_0217BCDC(u8 *a, void *b, int c, u8 d, u8 e);
u32 func_02188CFC(u8 *p);
void *func_021A3074(u8 *p);
void func_021A36BC(struct Obj18028 *p, void *a1);
void *func_0216D888(void *p);
struct Rec1C *func_02012870(const struct BigObj *p);
u32 func_02013E7C(u32 id);
void func_020128C0(struct BigObj *p, const struct Rec1C *src);
void *func_02012B38(const struct BigObj *p);
u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
int func_021625E8(int a0);
int func_02162694(int a0, int a1, int a2);
u8 func_021626E8(u8 *p);
void func_02185EB0(int a, u16 *p);
int func_02184410(int a, int *state, u8 *p);
void func_02012B2C(struct Rec44 *p, u32 v);
int func_02184584(int ctx, int *state, u8 *p);
extern u32 func_02013D5C(u32 id);
extern int func_0218466C(int ctx, int *state, u8 *p);
void func_02159FA8(int a, int b);
void func_0202735C(u32 a0, u32 a1);
void func_02168EEC(int a);
int func_0216446C(int a, int b);
u32 func_02012134(u32 *p);
u32 func_0202B578(u32 *p);
void func_0202C110(void *p);
unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
void *func_020298A0(void *a, u32 b, u32 c, u32 d);
int func_020145FC(int a);
extern int func_021625FC(const u8 *q, int *out, int id, int k);
unsigned int func_02012844(const struct BigObj *p);
void func_02014454(struct Sub02014444Obj *o, u8 v);
struct Rec44 *func_02012AC4(struct Rec44 *p, u16 v);
void func_02012ACC(struct Rec44 *p, int v);
int func_020141DC(const struct Rec020141DC *p);
void func_02012A90(struct Rec44 *p, const struct Vec12 *src);
void func_02012AA4(struct Rec44 *p, const struct H4 *src);
void func_02012ABC(struct Rec44 *p, u8 v);
void func_0202B544(u32 a, u16 b);
void func_02012854(struct BigObj *p, const struct Rec1C *src);
void func_02012900(const struct BigObj *p, u16 v);
int func_0202C83C(int a0, int a1);
u8 func_0201405C(u32 id);
u32 func_02012964(const struct BigObj *p);
int func_02159FE0(int v);
void func_021643E8(void *p, u16 v);
void func_0215A014(void *p, int v);
void func_02158AE0(void *a0, void *a1);
void func_0216E29C(struct Obj *o, int v);
void func_0216CCCC(struct Obj *o);
u32 func_0201296C(const struct BigObj *p);
u16 func_02162744(u8 *p);
u32 func_02162740(u8 *p);
void func_0216CEAC(u32 a, u8 *p, u32 b, u32 n, u32 c);
u32 func_0201444C(struct Sub02014444Obj *o);
u8 *func_020127C4(void *p);
u8 *func_020127D0(u8 *o, u32 idx);
int func_020127E0(int a);
u32 func_020307B0(void *p);
int func_02186538(unsigned short *a, int b, int c);
int func_02186278(char *p, int which);
int func_02186854(u16 *p);
int func_021868B8(int a, int b, int c, int d);
void func_0216CF6C(int x);
extern void func_02186470(int a0);
extern void func_021864DC(u8 *p);
extern unsigned int func_02013F6C(unsigned int id);
extern u8 func_02014468(struct Sub02014444Obj *o);
extern void func_0201446C(void *p, unsigned int value);
int func_02012B70(const struct BigObj *p);
void func_02014450(struct Sub02014444Obj *o, u32 v);
u32 func_02013CC8(u32 id);
u32 func_02013CE0(u32 id);
u32 func_02013DF0(u32 id);
u32 func_02013D20(u32 id);
u8 func_020129AC(const struct BigObj *p);
void func_020129B8(struct BigObj *p, u32 v);
u32 func_02012974(const struct BigObj *p);
u32 func_02013B44(u32 id);
int func_02162408(int a0, int a1, int a2);
int func_02159B94(int a0, int a1, int a2, int a3);
void func_02159CC4(u32 *a, int b, int c);
extern void func_0216DAC8(unsigned int *, unsigned int);
u8 *func_02012EC4(struct Big *p);
void func_0200B37C(struct Struct_0200B37C *p);
s32 *func_0200B394(struct Rec94 *p, s32 value);
void *func_020490F4(unsigned int id, unsigned int heap);
void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
u32 func_020493D4(struct ArcFile *arc, u32 member);
void func_02049238(void *h);
void func_020061E4(u32 a);
int func_02189A08(unsigned char *p);
void func_021CF498(struct Ctx *c, u32 x, int idx);
void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4);
extern int func_0217C070(u8 *o);
extern int func_02158630(int h);
extern int func_021D2750(u32 a);
extern u16 func_02188C84(u8 *p);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void func_02026400(struct Comm *p);
extern void func_0217574C(u8 *o, u32 v);
extern void func_02175710(u8 *o, u32 v);
extern void func_02175B4C(u8 *o, u8 *p);
extern int func_02039338(int a);
int func_02184C78(void *ctx, int *st, int *p);
void func_02184CEC(void **o, void *p);
void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);
void *func_02184D90(void *p, int unused, int a, const Q *q, u16 s, int t);
void *func_02184DE8(void *p, int unused, int a, const Q *q, u16 s, int t);
void *func_02184E40(void *p, int u, const Vec *v, s16 b, const int *s);
void *func_02184E94(int u, void *p);
void *func_02184EEC(void *p);
void *func_02184F40(void *p);
void *func_02184F88(void *p);
void *func_02184FD4(void *p, u16 id);
void *func_02185050(void *p, int u, int b, const int *s, u16 x);
void *func_021850A8(void *p);
void *func_021850FC(void *p, u8 *pos);
void *func_02185140(void *a, int b, S3_02184C78 *c, int d);
void *func_02185214(void *a);
void func_021852F0(void *dst, int x);
void *func_02185360(void *p, int u, int a, int b);
void *func_02185410(void *p, int u, int a, int b);
void *func_02185458(void *p, int u, int b, s16 a, const int *s, u16 x);
void *func_021854B0(void *p, int u, s16 a, const int *s, u16 x);
void *func_021854CC(void *p, int u, int u2, const S7 *src, u16 h);
void *func_02185534(void *p, int a1, int a2, const S3_02185214 *a3, short a4);
void *func_02185588(void *owner, u16 id, const V3 *pos);
void func_0218562C(int a);
int func_02185694(int a0, int *st, int *p);
void *func_0218571C(void *owner);
int func_02185758(int value);
void func_02185788(void *p, Record *source, Record *dest);
void func_021857C0(void *a, Record *b);
void func_021858E4(int a, const short *p);
void func_02185928(void *a, const short *p);
void func_021859F0(int a);
void func_021859FC(void *p, const short *s);
void func_02185A34(void *p, unsigned int id);
void func_02185A68(void *a, int b);
void func_02185B70(void *p);
void func_02185B88(void *p, unsigned int v);
void func_02185B9C(int a0, int id);
void *func_02185BFC(void *p, int a1, S7 *a2, int a3, int a4);
void *func_02185C4C(void *p, int a1, S7 *a2);
int func_02185C8C(int a0, int *st, int *p);
int func_02185D38(int a0, int *state, Ctx *c);
extern char ov011_id[];
extern char ov012_id[];






int func_02184C78(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];

    switch (*st) {
    case 0:
        func_02012374(ctx, func_02161824((void *)a, (void *)b));
        (*st)++;
        break;
    case 1:
        func_02034A5C((int)ov011_id);
        func_02034AC4((int)ov012_id);
        func_02012374(ctx, func_02184360((u8 *)p, 4));
        (*st)++;
        break;
    case 2:
        func_02173744(a);
        (*st)++;
        break;
    case 3:
        func_02012374(ctx, func_021BF66C((int)ctx, (void *)a, b));
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}






void func_02184CEC(void **o, void *p)
{
    void *a = func_020120F4(p);
    void *b = func_0201210C(p);
    u16 c = func_02012984(a);

    o[0] = p;
    o[1] = a;
    o[2] = b;
    ((struct Obj00248 *)o)->fC = func_02188C9C(b);
    ((struct Obj00248 *)o)->f40 = 0;
    ((struct Obj00248 *)o)->f44 = 0;
    ((struct Obj00248 *)o)->f48 = c;
    ((struct Obj00248 *)o)->f4A = c;
    func_021AAAF0(func_02188CE8(o[2]), 1);
}






/*
 * The ARM9 leaf 0x02014184 is resolved by its matched shard.
 *
 * What made it byte-correct: `const int *q` (see the EXACT twins
 * ov020_func_02184D90.c / ov020_func_02184DE8.c).
 */
void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    s = func_020142A4(s);
    func_02014184(r4 + 0x10, a, (s16)s, q[0], q[1], q[2]);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}






/*
 * Allocator with callback (0x9c-byte work area), then the 0x18-byte record
 * at +0x10 initialised by func_020141A8 from three u16 fields of q.
 * What closed it: `const Q *q`. Without const the q field loads are kept
 * below the outgoing stack-argument stores and `adds r1,r7` is scheduled
 * first; const lets them hoist (docs/notes/pkt_ov020_02184D38.c.txt has
 * the earlier near miss). The u16 stack parameter s fixes the frame.
 */
void *func_02184D90(void *p, int unused, int a, const Q *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    s = func_020142A4(s);
    func_020141A8((struct t *)(r4 + 0x10), a, (s16)s, q->f0, q->f6, q->f4);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}






void *func_02184DE8(void *p, int unused, int a, const Q *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    s = func_020142A4(s);
    func_020141A8((struct t *)(r4 + 0x10), a, (s16)s, q->f0, q->f6, q->f4);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}





static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x; d->y = y; d->z = z;
}





void *func_02184E40(void *p, int u, const Vec *v, s16 b, const int *s)
{
    void *r0v = func_020122C0(p, 0, func_02184730, 0x9c);
    char *r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    func_02014184(r4 + 0x10, b, 1, s[0], s[1], s[2]);
    vset((Vec *)(r4 + 0x34), v->x, v->y, v->z);
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}






void *func_02184E94(int u, void *p)
{
    void *r0v = func_020122C0(p, 0, func_021847CC, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC((void **)r4, p);
    src = (S7 *)func_020128B8(((struct Obj00248 *)r4)->f4);
    *(S7 *)(r4 + 0x10) = *src;
    func_02185F18(((struct Obj00248 *)r4)->f4, r4 + 0x10);
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = 1;
    return r0v;
}






void *func_02184EEC(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184894, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC((void **)r4, p);
    src = (S7 *)func_020128B8(((struct Obj00248 *)r4)->f4);
    *(S7 *)(r4 + 0x10) = *src;
    func_02185F18(((struct Obj00248 *)r4)->f4, r4 + 0x10);
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = 1;
    return r0v;
}






void *func_02184F40(void *p)
{
    void *r6 = (void *)func_02012914(func_020120F4(p));
    void *r0v = func_020122C0(p, 0, func_0218495C, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    func_02014204((struct t *)(r4 + 0x10), func_02159F94((int)r6));
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}






/*
 * Allocator + base init, copies a seven-word record fetched through the node's
 * fourth word, then fills status fields.
 */
void *func_02184F88(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184A14, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC((void **)r4, p);
    src = (S7 *)func_02012894((const struct BigObj *)(*(int *)&((struct Obj00248 *)r4)->f4));
    *(S7 *)(r4 + 0x10) = *src;
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f18 = 2;
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}





/*
 * Thumb leaf, sole caller in range). Evidence class: label / sole-ref/code.
 * Leaf 0x02014184 (arm9, Thumb, EXACT with match.py one, Ilias's to file):
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 */
void *func_02184FD4(void *p, u16 id)
{
    V28 v;
    void *r0v = func_020122C0(p, 0, func_02184AB4, 0x9c);
    char *r5 = func_020124E8(r0v);
    int r6, r7;
    int *r4;

    func_02184CEC((void **)r5, p);
    func_02014204((struct t *)(r5 + 0x10), id);
    *(int *)(r5 + 0x2c) = 0;
    *(u16 *)(r5 + 0x18) = 1;
    r6 = (int)func_020127A4(*(void **)(r5 + 4));
    r4 = (int *)func_02012AA0((struct Rec44 *)r6);
    r7 = func_02012AC8((const struct Rec44 *)r6);
    func_02014184(&v, r7, (s16)func_02012AE4((const struct Rec44 *)r6), r4[0], r4[1], r4[2]);
    func_0201289C(*(void **)(r5 + 4), (const struct Rec1C *)(&v));
    return r0v;
}





void *func_02185050(void *p, int u, int b, const int *s, u16 x)
{
    void *r0v = func_020122C0(p, 0, func_02184B54, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    x = func_020142A4(x);
    func_02014184(r4 + 0x10, b, x, s[0], s[1], s[2]);
    *(int *)(r4 + 0x2c) = 5;
    *(int *)(r4 + 0x40) = 0;
    return r0v;
}






void *func_021850A8(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184C78, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    func_02014184(r4 + 0x10, 0x1A6, func_020142A4(0), 0x2E << 14, 0, 0x3E << 14);
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}






/*
 * Allocator with callback, then a seven-word record copied from a global-ish
 * accessor into offset 0x10.
 */
void *func_021850FC(void *p, u8 *pos)
{
    S7 *r5 = (S7 *)func_02012894(func_020120F4(p));
    void *r0v = func_020122C0(p, 0, func_02184BF8, 0x9C);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    *(S7 *)(r4 + 0x10) = *r5;
    return r0v;
}






/*
 *           witness: an unlabelled arm9 Thumb leaf (printed as .word data
 *           after func_020140F8), Ilias's to file. Evidence class: label /
 *           sole-ref/code. Verified C for the leaf, per
 *           ov020_func_021852F0.c:
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 */
void *func_02185140(void *a, int b, S3_02184C78 *c, int d)
{
    int h;
    void *r4;
    S3_02184C78 t;
    S7 w;
    S7 out;
    int r6;
    int r5;
    int r2;
    void *q;
    u8 *r7;

    h = (int)func_0201210C(a);
    r4 = func_020120F4(a);
    t = *c;
    r6 = 0;
    func_021852F0(&w, h);
    func_020128E4(r4, (const struct Rec1C *)(&w));
    q = func_0200BE48(func_02012EBC(r4));
    func_0200BFA4(q, (void *)func_02012FCC((int)r4), 0);
    r7 = (u8 *)func_02158344(func_02012138(a));
    if (r7 == 0 || func_02158590(r4) == 0) {
        r5 = 0;
        r2 = 0;
    } else {
        r5 = func_02176230(r7, r7 + 0x1AC);
        r2 = r5 - func_02012B58(r4);
        if (r2 < 0)
            r2 += r7[0x902];
        r6 = 0x10000;
    }
    t.f0 += r6 + (r2 << 22);
    func_02014184(&out, b, func_020142A4(0), t.f0, t.f4, t.f8);
    return func_02185BFC(a, h, &out, d, r5);
}






static inline void create_result(void *a, void *r6, Rec *s, void **out)
{
    *out = func_02185C4C(a, (int)r6, (S7 *)s);
}






static inline void *finish(void *a, void *r4, void *r6, void *ret)
{
    u16 *t;
    void *h;
    t = func_0200BE48(func_02012EBC(r4));
    func_0200BFA4((u8 *)t, (void *)func_02012FCC((int)r4), 1);
    h = (void *)func_02012138(a);
    func_0202648C(h);
    if (func_02026454(h) == 0)
        func_02026484(h);
    if (func_021A3238(func_02188CB4(r6)) == 0)
        func_0217BCDC(0, a, 0, 0, 0);
    func_02012B78(r4, 0);
    if (func_02158344(func_02012138(a)) == 0) {
        func_02012B64(r4, 0);
        func_02012B8C(r4, 0);
        func_02012B4C(r4, 1);
    }
    return ret;
}






/*
 * Lever: func_0202648C reads its pointer argument in the matched ARM9
 * unit_02026454.c. The original forwards func_02012138(a) in r0 with
 * no intervening argument setup. Explicitly passing h restores the
 * return-value spill and all frame/register choices (DIFF22 -> EXACT).
 * Runs this retry: 2; the prior consumed permuter was not repeated.
 */
void *func_02185214(void *a)
{
    void *r4;
    void *r6;
    Rec s;
    void *ret;
    r4 = func_020120F4(a);
    r6 = func_0201210C(a);
    s = *func_020128DC(r4);
    if (func_02013DD0(s.f04) == 1)
        func_02014204((struct t *)(&s), s.f04);
    create_result(a, r6, &s, &ret);
    return finish(a, r4, r6, ret);
}







void func_021852F0(void *dst, int x)
{
    H4 h;
    int r5 = (int)func_02188CB4((struct Obj00020 *)x);

    if (func_02188CFC((u8 *)x) == 0) {
        int *v;

        v = func_0216D888(func_021A3074((u8 *)r5));
        func_02014184(dst, func_02188C9C((u8 *)x), 1, v[0], v[1], v[2]);
        return;
    }
    func_021A36BC((struct Obj18028 *)r5, &h);
    func_020141A8(dst, func_02188C9C((u8 *)x), 2, h.a, h.d, h.c);
}







void *func_02185360(void *p, int u, int a, int b)
{
    char *r4;
    void *r5 = func_020120F4(p);
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    u16 *r6;

    r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    if (func_021625E8(a) != 0) {
        *(S7 *)(r4 + 0x10) = *(S7 *)func_02012894((const struct BigObj *)r5);
    } else {
        func_02162694(a, (int)(r4 + 0x10), b);
    }
    ((struct Obj00248 *)r4)->f2C = func_021626E8((u8 *)a);
    r6 = (u16 *)func_02012870(r5);
    if (func_02013E7C(r6[2]) == 1 && func_02013E7C(((struct Obj00248 *)r4)->f14) == 0) {
        func_020128C0(r5, (const struct Rec1C *)r6);
    }
    func_02185EB0((int)r5, (u16 *)(r4 + 0x10));
    func_0201447C(func_02012B38(r5), 2);
    return r0v;
}







void *func_02185410(void *p, int u, int a, int b)
{
    void *r0v;
    char *r4;

    func_020120F4(p);
    r0v = func_020122C0(p, 0, func_02184410, 0x9c);
    r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    func_02162694(a, (int)(r4 + 0x10), b);
    ((struct Obj00248 *)r4)->f2C = func_021626E8((u8 *)a);
    return r0v;
}







void *func_02185458(void *p, int u, int b, s16 a, const int *s, u16 x)
{
    void *r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    x = func_020142A4(x);
    func_02014184(r4 + 0x10, a, x, s[0], s[1], s[2]);
    *(int *)(r4 + 0x2c) = 0;
    *(u8 *)(r4 + 0x30) = b;
    return r0v;
}






void *func_021854B0(void *p, int u, s16 a, const int *s, u16 x)
{
    return func_02185458(p, u, 0, a, s, x);
}







void *func_021854CC(void *p, int u, int u2, const S7 *src, u16 h)
{
    void *r7 = func_020120F4(p);
    void *r0v;
    char *r4;

    func_02012B2C(func_020127A4(r7), 0);
    r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    *(S7 *)(r4 + 0x10) = *src;
    ((struct Obj00248 *)r4)->f18 = h;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f30 = 1;
    func_02185EB0((int)r7, (u16 *)(r4 + 0x10));
    return r0v;
}







/*
 * Blocked (evidence class: none, unresolved callee site) by unlabelled arm9 leaf
 * 0x02014184 (Ilias's), verified EXACT in a scratch file with `one --region arm9 --thumb`:
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 * Lever: `const S3_02185214 *a3` (as in ov020 func_02184E40) and the callee's third
 * parameter declared short.
 */
void *func_02185534(void *p, int a1, int a2, const S3_02185214 *a3, short a4)
{
    void *r0v = func_020122C0(p, 0, func_02184584, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    *(u16 *)&a4 = func_020142A4(*(u16 *)&a4);
    func_02014184(r4 + 0x10, a2, a4, a3->a, a3->b, a3->c);
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}







/*
 * 2026-10-05 (wD9r lane42): EXACT. Two source facts closed the last 18 bytes:
 *   (1) id is a u16 parameter, and func_02014184 takes a u16 id (its matched definition in
 *       src/matched/arm9/func_02014184.c). This fixed the asrs/ldr order at the 02014184 call.
 *   (2) the e->lo bitfield is read into its own block local (`int lo = e->lo; r = lo - getter;`),
 *       the same shape as sibling 02185140 (`r2 = r5 - func_02012B58(r4)`). This fixed the
 *       owner/r colour swap (owner r4, r r5).
 */
void *func_02185588(void *owner, u16 id, const V3 *pos)
{
    V3 v = *pos;
    void *ctx = func_020120F4((const struct Ctx *)owner);
    void *node = func_020122C0(owner, 0, (void *)func_0218466C, 0x9C);
    char *x = func_020124E8((struct Obj *)node);
    int r = 0;

    if (func_02013D5C(id) == 1) {
        E *e = (E *)func_02158344(func_02012138((const struct Ctx *)owner));
        if (e != 0) {
            int lo = e->lo;
            r = lo - func_02012B58(ctx);
            if (r < 0)
                r += *(u8 *)((char *)e + 0x902);
        }
        v.x += (u32)r << 22;
    }
    func_02184CEC((void **)x, owner);
    func_02014184(x + 0x10, id, (s16)func_020142A4(0), v.x, v.y, v.z);
    *(u32 *)(x + 0x2C) = 0;
    *(u32 *)(x + 0x40) = 0;
    return node;
}







void func_0218562C(int a)
{
    int r4 = (int)func_020120F4((const struct Ctx *)a);
    struct { char b[0x1c]; int f; u16 h; char pad[0x16]; } l;

    func_02159FA8(func_02012914((const struct BigObj *)r4), (int)(&l.f));
    func_02014204((struct t *)l.b, func_02159F94(func_02012914((const struct BigObj *)r4)));
    func_020128C0((struct BigObj *)r4, (const struct Rec1C *)l.b);
    func_02185B70((void *)a);
    func_02185A68((void *)a, l.h);
    func_021857C0((void *)a, (Record *)&l.f);
    func_0202735C(l.h, r4);
    func_02168EEC(r4);
    func_0216446C(r4, l.h);
}







/*
 * Blocked (evidence class: none, unresolved callee sites) by two unlabelled arm9
 * leaves inside labelled arm9 functions (Ilias's), each verified EXACT in a
 * scratch file with `one --region arm9 --thumb`:
 *   0x0202B578: int func_0202B578(int *p) { return p[8]; }
 *   0x02029DF4: void func_02029DF4(void) { func_02029EB4(); }   (thumb tail-call
 *               stub, .word 0x02029EB5)
 */
int func_02185694(int a0, int *st, int *p)
{
    int r;

    switch (st[0]) {
    case 0:
        func_0218562C(p[0]);
        st[0]++;
        break;
    case 1:
        func_02012B2C(func_020127A4(func_020120F4((const struct Ctx *)p[0])), 0);
        func_0202C110((void *)func_0202B578((u32 *)func_02012134((u32 *)p[0])));
        r = func_02029DF4((void *)p[1], ((short *)p)[6], func_02012984((const struct BigObj *)p[1]));
        r = (int)func_020298A0((void *)p[0], r, 0, 0x3c);
        func_02012374((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 2:
        r = func_020145FC(p[0]);
        func_02012374((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}





void *func_0218571C(void *owner)
{
    void *task;
    Work *w;
    func_020120F4(owner);
    task = func_020122C0(owner, 0, (void *)func_02185694, sizeof(Work));
    w = func_020124E8(task);
    w->owner = owner;
    w->object = func_020120F4(owner);
    func_02159FA8(func_02012914(w->object), (int)w->payload);
    return task;
}





int func_02185758(int value)
{
    switch (value) {
    case 0:
    case 1:
    default: return 0;
    case 3: return 0x4000;
    case 2: return 0x8000;
    case 4: return 0xc000;
    }
}





void func_02185788(void *p, Record *source, Record *dest)
{
    if (source->kind == 1) {
        *dest = *source;
    } else {
        if (func_021625FC(p, (int *)dest, source->h6, source->ha) == 0) {
            func_02014204((struct t *)dest, (u16)source->h4);
        }
    }
}








void func_021857C0(void *a, Record *b)
{
    void *r5;
    void *r4;
    int t;
    Record s;
    u16 v;
    int n;
    void *q;

    r5 = func_020120F4(a);
    r4 = func_020127A4(r5);
    t = (int)func_02012844(r5);
    func_02014454(func_02012B38(r5), 1);
    func_02185788((void *)t, b, &s);
    if (s.kind == 3)
        func_0201289C(r5, func_02012870(r5));
    func_02012AC4(r4, s.h4);
    func_02012ACC(r4, func_02185758(s.h8));
    if (func_020141DC((const struct Rec020141DC *)(&s)) == 0) {
        func_02012A90(r4, (const struct Vec12 *)(&s.d));
        func_02012ABC(r4, 0);
    } else {
        func_02012AA4(r4, (const struct H4 *)(&s.d));
        func_02012ABC(r4, 1);
    }
    func_0202B544((u32)func_02012134(a), s.h4);
    func_02012854(r5, (const struct Rec1C *)(&s));
    v = func_02159FE0(s.h4);
    if (v != 0)
        func_02012900(r5, v);
    func_02185B9C((int)r5, s.h4);
    func_02168EEC((int)r5);
    func_021643E8(r5, s.h4);
    func_0215A014(r5, s.h4);
    func_02158AE0(a, (void *)4);
    func_021858E4((int)r5, (const short int *)b);
    func_02185A34(r5, (u16)s.h4);
    func_021859FC(r5, (const short int *)(&s));
    func_0202C83C((int)a, s.h4);
    n = (int)func_0201405C((u16)s.h4);
    q = (void *)func_02012964(r5);
    if (n < 16)
        func_0216E29C(q, n);
    else
        func_0216CCCC(q);
}








void func_021858E4(int a, const short *p)
{
    int t = func_02012844((const struct BigObj *)a);
    int v = func_02162744((u8 *)t);

    if (v != 0) {
        int r6 = func_0201296C((const struct BigObj *)a);
        int r5 = func_02012964((const struct BigObj *)a);
        int r1 = func_02162740((u8 *)t);
        int s = p[2];
        func_0216CEAC(r5, (u8 *)r1, s, v, r6);
    }
}








/*
 *           the THM_CALL to func_02013DD0 (arm9) has no witness: 0x02013DD0
 *           is an unlabelled arm9 leaf (Ilias's, inside func_02013D9C's
 *           listing extent; see unit_02013D9C.c's near-miss note). Verified
 *           C for it, per ov018_func_0217EC7C.c:
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 */
void func_02185928(void *a, const short *p)
{
    int r6;
    int r5;
    int r4;
    int ip;
    int sc;
    int s8;
    unsigned short *r7;

    if (func_02013DD0((unsigned short)p[2]) == 0)
        return;

    r6 = (int)func_0201444C(func_02012B38((const struct BigObj *)a));
    sc = (int)func_02012964((const struct BigObj *)a);
    s8 = (int)func_0201296C((const struct BigObj *)a);
    if (r6 == 0)
        r7 = (short unsigned int *)func_020127C4(a);
    else
        r7 = (short unsigned int *)func_020127D0((u8 *)a, (int)0);

    r5 = func_02186538(r7, r6, 1);
    ip = func_02186278((char *)r7, r6);
    if (r5 != 0 && ip != 0)
        func_0216CEAC((int)sc, (u8 *)r5, (int)p[2], (int)ip, (int)s8);
    if (r5 != 0)
        func_020307B0((void *)r5);

    r5 = func_020127E0((int)a);
    r4 = func_02186854((u16 *)r5);
    r5 = func_021868B8(r5, r6, r7[1], 1);
    if (r5 != 0 && r4 != 0)
        func_0216CEAC((int)sc, (u8 *)r5, (int)p[2], (int)r4, (int)s8);
    if (r5 != 0)
        func_020307B0((void *)r5);
}








void func_021859F0(int a)
{
    func_0216CF6C(func_02012964((const struct BigObj *)a));
}







void func_021859FC(void *p, const short *s)
{
    func_02186470((int)p);
    if (func_02013DD0(*(const u16 *)&((struct Obj19456 *)s)->f4) != 0) {
        func_02185928((void *)p, s);
        if (func_0201444C(func_02012B38(p)) == 0) {
            func_021864DC(func_020127C4(p));
        }
    }
}







/*
 * interface: 0201446C's full-word input matches the absent call-site truncation.
 */
void func_02185A34(void *p, unsigned int id)
{
    void *object;
    unsigned int flags;
    object = func_02012B38(p);
    flags = func_02013F6C(id);
    if ((flags & 1) && func_02014468(object)) {
        flags &= ~1;
        flags |= 2;
    }
    func_0201446C(object, flags);
}








void func_02185A68(void *a, int b)
{
    void *r4;
    void *r7;
    int st;

    r4 = func_020120F4(a);
    r7 = (void *)func_02012844(r4);
    func_0201210C(a);
    if (func_02012B70(r4) == 1 && func_02013D5C(b) == 0)
        func_02014450(func_02012B38(r4), 1);
    else
        func_02014450(func_02012B38(r4), 0);

    if (func_02013CC8(b) != 0) {
        func_020129B8(r4, 2);
    } else if (func_02013CE0(b) != 0 || func_02013DF0(b) != 0 || func_02013D20(b) != 0) {
        func_020129B8(r4, 5);
    } else {
        if (func_02012B70(r4) == 1 && func_020129AC(r4) != 3)
            func_020129B8(r4, 3);
        else if (func_02012B70(r4) == 0 && func_020129AC(r4) == 3)
            func_020129B8(r4, 0);
        st = func_020129AC(r4);
        if (st != 3 && st != 4 && st != 6)
            func_020129B8(r4, 0);
    }

    func_02162408((int)r7, b, func_02012984(r4));
    r7 = (void *)func_02012974(r4);
    func_02159B94((int)r7, func_02013B44(b), b, 0x8001);
    func_02159CC4(r7, (int)a, 0x8001);
    func_02185A34(r4, b);
}







/*
 * interface: 021859F0 forwards incoming r0 to 02012964.
 */
void func_02185B70(void *p)
{
    void *q = func_020120F4(p);
    func_0201210C(p);
    func_021859F0((int)q);
}






void func_02185B88(void *p, unsigned int v)
{
    func_0216DAC8(func_021A3074(func_02188CB4(p)), v);
}







void func_02185B9C(int a0, int id)
{
    unsigned n, i;
    int r0 = (int)func_02012EC4((struct Big *)a0);
    void *h;
    int c = 0x8001;
    Ent *e;

    func_0200B37C((struct Struct_0200B37C *)r0);
    h = func_020490F4(0x65, c);
    e = func_02049250(h, 0, c);
    n = func_020493D4(h, 0) >> 3;
    for (i = 0; i < n; i++) {
        if (id == e[i].id) {
            func_0200B394((struct Rec94 *)r0, e[i].v);
            break;
        }
    }
    func_020307B0(e);
    func_02049238(h);
}







/*
 * Allocator with callback, copies a seven-word record then fills link fields.
 */
void *func_02185BFC(void *p, int a1, S7 *a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_02185D38, 0x30);
    char *r4 = func_020124E8(r0v);

    *(S7 *)r4 = *a2;
    ((struct Obj05969 *)r4)->f1C = (int)p;
    ((struct Obj05969 *)r4)->f20 = (int)func_020120F4(p);
    ((struct Obj05969 *)r4)->f24 = a1;
    ((struct Obj05969 *)r4)->f28 = a3;
    ((struct Obj05969 *)r4)->f2C = a4;
    return r0v;
}





/*
 * Allocator with callback, copies a seven-word record from the third argument
 * plus two link fields.
 */
void *func_02185C4C(void *p, int a1, S7 *a2)
{
    void *r0v = func_020122C0(p, 0, func_02185C8C, 0x30);
    int *r4 = func_020124E8(r0v);

    *(S7 *)r4 = *a2;
    r4[7] = (int)p;
    r4[8] = (int)func_020120F4(p);
    r4[9] = a1;
    return r0v;
}



int func_02185C8C(int a0, int *st, int *p)
{
    int r7 = p[7];
    int r6 = p[9];
    void *h;
    int *n;

    switch (st[0]) {
    case 0:
        func_020061E4(0x773);
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)r6), a0, 0x24);
        st[0]++;
        break;
    case 1:
        h = func_020122C0((void *)r7, 0, func_02184504, 0x9c);
        n = func_020124E8(h);
        func_02184CEC((void **)n, (void *)r7);
        *(S7 *)(n + 4) = *(S7 *)p;
        n[0xb] = 0;
        n[0x10] = 0;
        func_02012374((struct Evt *)a0, h);
        st[0]++;
        break;
    case 2:
        func_02012374((struct Evt *)a0, func_021BE9F0((void *)r7, r6, 0, 0, 2));
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}



int func_02185D38(int a0, int *state, Ctx *c)
{
    int r;
    int h;
    int flag;
    int id;
    u8 *obj;

    h = func_02012138((const struct Ctx *)c->f1c);
    switch (*state) {
    case 0:
        obj = (u8 *)func_02158344(h);
        flag = 0;
        r = 0;
        if (obj != 0) {
            r = func_0217C070(obj);
            if (func_02158630(h) == 3)
                flag = 1;
        }
        if (r == 0 && func_021D2750(c->f1c) != 0) {
            id = !flag ? 0x279A : 0x279B;
            func_02158780((void *)a0, id, 0, 0, func_02188C84((u8 *)c->f24));
            if (func_02158590((void *)c->f20) == 0)
                func_02026400((struct Comm *)h);
            *state = 1;
        } else {
            id = !r ? 0x279C : 0x279D;
            func_02158780((void *)a0, id, 0, 0, func_02188C84((u8 *)c->f24));
            *state = 3;
        }
        break;
    case 1:
        if (func_02158590((void *)c->f20) == 0) {
            if (func_02026454((void *)h) != 0)
                break;
            func_02026484((void *)h);
        }
        if (c->f28 == 1 && func_02158630(h) != 3) {
            func_02158780((void *)a0, 0x279F, 0, 0, func_02188C84((u8 *)c->f24));
            *state = 3;
            break;
        }
        obj = (u8 *)func_02158344(h);
        if (obj != 0) {
            func_0217574C(obj, 1);
            func_02175710(obj, c->b2c);
            if (c->f28 == 1)
                func_02175B4C(obj, obj + 0x1AC);
        }
        func_02012B64((struct BigObj *)c->f20, func_02039338((int)func_02012B78((struct BigObj *)c->f20, 1)));
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185C4C((void *)c->f1c, c->f24, (S7 *)c));
        *state = 2;
        break;
    case 2:
        obj = (u8 *)func_02158344(h);
        if (obj != 0)
            func_0217574C(obj, 0);
        *state = 3;
        break;
    case 3:
        return 1;
    }
    return 0;
}
