/*
 * file:     field_nogrid_mapper.c
 * unit:     yes
 * function: func_021B8848, func_021B8870, func_021B8894, func_021B88B8, func_021B88DC, func_021B9164, func_021B919C, func_021B91A8, func_021B91AC, func_021B91C8, func_021B91F8, func_021B9238, func_021B9278, func_021B9280, func_021B9338, func_021B9368, func_021B93D4, func_021B9404, func_021B9434, func_021B9464, func_021B9478, func_021B949C, func_021B94C0, func_021B94D8, func_021B9510, func_021B9530, func_021B95C0, func_021B960C, func_021B963C, func_021B96AC, func_021B9768, func_021B976C, func_021B977C, func_021B97D0, func_021B97FC, func_021B9828, func_021B9A50, func_021B9B24, func_021B9B7C, func_021B9C28, func_021B9D60, func_021B9E84, func_021B9FC8, func_021BA25C, func_021BA2B4, func_021BA310, func_021BA348, func_021BA494, func_021BA4C4, func_021BA4FC, func_021BA550, func_021BA6E8, func_021BA7B0, func_021BA7E0, func_021BA8E0, func_021BA9B4, func_021BAA30, func_021BAA9C, func_021BAB30, func_021BABB4, func_021BABDC, func_021BAC04, func_021BAC74, func_021BACA8, func_021BAE7C, func_021BB014, func_021BB088, func_021BB0A4, func_021BB0B4, func_021BB11C, func_021BB13C, func_021BB188, func_021BB1A0, func_021BB1AC, func_021BB1B8, func_021BB1C4, func_021BB1D0, func_021BB1DC, func_021BB1E8, func_021BB1F4, func_021BB240, func_021BB260, func_021BB278, func_021BB2F8, func_021BB348, func_021BB36C, func_021BB388, func_021BB394, func_021BB3A0, func_021BB3AC, func_021BB3B8, func_021BB3C4, func_021BB3D0, func_021BB3DC, func_021BB3E8, func_021BB480, func_021BB484, func_021BB4A8, func_021BB4BC, func_021BB504, func_021BB528
 * address:  0x021B8848
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
 *   d_021D9A30     0x021D9A30  data  a4
 *   func_021B8514  0x021B8514  thumb  ov021
 *   func_021B854C  0x021B854C  thumb  ov021
 *   func_021B8674  0x021B8674  thumb  ov021
 *   func_021B868C  0x021B868C  thumb  ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 *   d_021D9A0C     0x021D9A0C  data  a4
 *   func_021B8820  0x021B8820  thumb  ov021
 *   _s32_div_f  0x0209C0A4  arm
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 *   func_021B87FC  0x021B87FC  thumb
 *   func_021B86A4  0x021B86A4  thumb
 *   d_021DE2B0     0x021DE2B0  data  a4
 *   d_021DE2B4     0x021DE2B4  data  a4
 *   d_021DE2BC     0x021DE2BC  data  a4
 *   VEC_Subtract     0x0207CA00  arm
 *   VEC_Mag          0x0207CBD0  arm
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   FX_Div           0x0207C768  arm
 *   _ll_mul          0x0209C054  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   VEC_Add          0x0207C9D0  arm
 *   func_020520A4    0x020520A4  arm
 *   d_020A1B38       0x020A1B38  data   a2
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_021B82F4  0x021B82F4  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B8300  0x021B8300  thumb  ov021
 *   func_021B8308  0x021B8308  thumb  ov021
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_021D9A54     0x021D9A54  data  ov021  a4
 *   func_021B835C  0x021B835C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   d_021D9A60     0x021D9A60  data  a4
 *   func_021B8224  0x021B8224  thumb  ov021
 *   func_021B8230  0x021B8230  thumb  ov021
 *   func_021B823C  0x021B823C  thumb  ov021
 *   func_021B8248  0x021B8248  thumb  ov021
 *   func_021B8250  0x021B8250  thumb  ov021
 *   func_021B8378  0x021B8378  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_0207CF3C  0x0207CF3C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021B824C  0x021B824C  thumb  ov021
 *   func_021B8304  0x021B8304  thumb  ov021
 *   func_0207CA68  0x0207CA68  arm
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B8314  0x021B8314  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_021B836C  0x021B836C  thumb  ov021
 *   func_021B82F0  0x021B82F0  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_0207CC30  0x0207CC30  arm
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   VEC_Distance      0x0207CF3C  arm
 *   func_021B8328  0x021B8328  thumb  ov021
 *   d_021DE2C4     0x021DE2C4  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_0204A298  0x0204A298  arm
 *   func_02030734  0x02030734  arm
 *   func_021B7884  0x021B7884  thumb  ov021
 *   func_0219EF44  0x0219EF44  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 *   func_021B791C  0x021B791C  thumb  ov021
 *   func_0219EF6C  0x0219EF6C  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 *   func_02049030  0x02049030  arm
 *   func_0219EF7C  0x0219EF7C  thumb  ov021
 *   func_0219F018  0x0219F018  thumb  ov021
 *   func_021B7934  0x021B7934  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 *   func_020490A8  0x020490A8  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021B7954  0x021B7954  thumb  ov021
 *   func_0219EFFC  0x0219EFFC  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021B79E4  0x021B79E4  thumb  ov021
 *   func_021B79F0  0x021B79F0  thumb  ov021
 *   func_021B7970  0x021B7970  thumb
 *   func_021B79AC  0x021B79AC  thumb
 *   func_021B79C4  0x021B79C4  thumb  ov021
 *   func_021B79CC  0x021B79CC  thumb  ov021
 *   func_021B7D68  0x021B7D68  thumb ov021
 *   func_021B7C04  0x021B7C04  thumb  ov021
 *   func_02013C9C  0x02013C9C  thumb
 *   func_021B7C58  0x021B7C58  thumb  ov021
 *   d_021DE2E8     0x021DE2E8  data  a4
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 *   d_021D9A6C     0x021D9A6C  data  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021BB778  0x021BB778  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A7C     0x021D9A7C  data  a4
 */
#include "../../matched/include/Obj01358.h"
#include "../../matched/include/Obj18138.h"
#include "../../matched/include/Obj09186.h"
#include "../../matched/include/G_Elem.h"
#include "../../matched/include/Obj00454.h"
#include "../../matched/include/Obj20083.h"
#include "../../matched/include/Obj18139.h"
#include "../../matched/include/Obj02052.h"
#include "../../matched/include/Obj02659.h"
#include "../../matched/include/Obj04891.h"
#include "../../matched/include/Obj03136.h"
#include "../../matched/include/Obj01203.h"
#include "../../matched/include/Obj09187.h"
#include "../../matched/include/Obj04250.h"
#include "../../matched/include/Obj20089.h"
#include "../../matched/include/Obj12865.h"
#include "../../matched/include/Obj09633.h"
#include "../../matched/include/Obj09634.h"
#include "../../matched/include/Obj09635.h"
#include "../../matched/include/Obj05053.h"
#include "../../matched/include/Obj07529.h"
#include "../../matched/include/Obj09638.h"
#include "../../matched/include/Obj07530.h"
#include "../../matched/include/Obj20092.h"
#include "../../matched/include/Obj09191.h"
#include "../../matched/include/Obj01663.h"
#include "../../matched/include/Obj18166.h"
#include "../../matched/include/Obj18167.h"
#include "../../matched/include/Obj18168.h"
#include "../../matched/include/Obj18169.h"
#include "../../matched/include/Obj18170.h"
#include "../../matched/include/Obj18171.h"
#include "../../matched/include/Obj02715.h"

#define FX32_ONE ((int)0x00001000L)
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
struct Sub;
struct Vec3;
struct Obj;
struct S;
struct Rec;
struct Tagged;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 b[0x24];
} Elem;

typedef struct {
    u16 h0;
    u16 h2;
    u16 n4;
    u16 n6;
    u16 n8;
    u16 na;
    u16 nc;
    u16 he;
    u8 pad10[8];
    Elem *p18;
    Elem *p1c;
    void **p20;
    void **p24;
    void **p28;
} Table;

typedef struct {
    int f00;
    int f04;
    int f08;
} Ov021Seg;

typedef struct {
    int f00;
    Ov021Seg *f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    void *f24;
    void *f28;
} Ov021Mover;

typedef struct {
    u8 pad[0x2C];
    void *x2c;
} Src;

typedef struct {
    char pad[0x10];
    void *f10;
    char pad2[0x28];
    void *f3C;
} Info;


typedef enum { MODE_0, MODE_1, MODE_2 } Mode;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 a, b, c; } V3;

typedef void (*Fn)(void *, void *);

typedef struct { u16 a; u8 t; u8 c; u16 e; u16 d; } Out;

typedef struct { u16 t; u16 pad; void *p4; int p8; int pc; int p10; int p14; int p18; int p1c; u32 p20; void *p24; } In;

typedef signed int     s32;

typedef struct { u8 b[0x48]; } E48_021B8848;

typedef struct { u16 f0; volatile u16 n; u8 pad[0x10]; E48_021B8848 *arr; } SR;

typedef struct {
    char b[0x70];
} E70;


typedef struct {
    u16 id;
    u8 f2;
    u8 f3;
    s16 f4;
    s16 f6;
} Rec;

typedef struct { u32 key[4]; u32 val[4]; } T;

typedef struct FieldNogridMapperWork {
    u16 h0;
    u16 h2;
    Info *f4;
    u16 h8;
    u16 ha;
    int fC;
    int f10;
    int f14;
    int f18;
    void *f1C;
    int f20;
    Src *f24;
    u8 *f28;
    u8 b2c;
    u8 pad2D[0x30 - 0x2D];
    char f30[1];
    u8 pad31[0x32 - 0x31];
    u8 b32;
    u8 b33;
    u8 pad34[0x74 - 0x34];
    u8 b74;
    u8 pad75[0x78 - 0x75];
    u8 *f78;
} FieldNogridMapperWork;

typedef struct {
    char b[0x48];
} E48_021B977C;

typedef struct {
    u16 h0;
    volatile u16 h2;
    char pad[0x10];
    E48_021B977C *f14;
} Obj_021B97FC;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef long long      s64;


typedef struct {
    int x0;
    int ang;
    int r;
    VecFx32 pos;
} Cam;

typedef struct { u32 x, y, z; } V_021BAC74;

typedef struct { int x, y, z; } V_021BACA8;

typedef long long fx64;

typedef struct FieldNogridMapperWork2 {
    u16 h0;
    u8 pad02[0xC - 0x2];
    void *fC;
    E70 *f10;
    int f14;
    u8 pad18[0x30 - 0x18];
    VecFx32 f30;
} FieldNogridMapperWork2;

typedef struct {
    void *f0;
    char pad[0x10];
    int f14;
} Obj_021BB36C;

typedef struct {
    int f0;
    void *a4[4];
    void *a14[4];
    void *a24[4];
} Obj;

u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7);
int func_021B8674(u8 *p, u32 *q, u32 v);
int func_021B868C(u8 *p, u32 *q, void *v);
u8 *func_021B87D8(u8 *p, u32 idx);
extern void *func_021B8820(void *a, void *b);
void func_021B7EE4(void *o, Rec *r);
void func_021B80E0(u32 a, u32 b, u32 c);
void func_021B810C(struct Sub *o);
void func_021B8028(u32 a, u32 b);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
int func_021B7DE0(u32 a, u32 b);
u8 *func_021B87FC(u8 *p, u32 idx);
void func_021B86A4(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern fx32 VEC_Mag(const VecFx32 *v);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
extern u16 FX_AcosIdx(int x);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst);
int func_0207CBD0(VecFx32 *a);
void func_0207CEE4(int s, VecFx32 *a, VecFx32 *b, VecFx32 *c);
u32 func_021B82F4(u8 *p);
u32 func_021B82F8(u8 *p);
u32 func_021B82FC(u8 *p);
u32 func_021B8300(u8 *p);
u32 func_021B8308(u8 *p);
u8 *func_021B833C(u8 *p);
u8 *func_021B834C(u8 *p);
int func_0207C768(int a, int b);
void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);
void func_0207CAE8(VecFx32 *a, VecFx32 *b, VecFx32 *c);
void func_0207CCA4(const VecFx32 *a, VecFx32 *b);
u8 *func_021B835C(void *p);
void func_0207C9D0(VecFx32 *a, VecFx32 *b, VecFx32 *c);
int *func_021B8224(void *p, int k);
int *func_021B8230(void *p, int a);
void func_021B823C(u8 *p, int k);
u32 func_021B8248(u8 *p);
void func_021B8250(void *p, Rec *r, Rec *o);
int func_021B8378(int x);
int func_021B7D38(void *p, Rec *r, int c);
int func_0207CF3C(const VecFx32 *a, const VecFx32 *b);
u32 func_021B824C(u8 *p);
u32 func_021B8304(u8 *p);
int func_0207CA68(VecFx32 *a, VecFx32 *b);
u32 func_021B8220(u8 *p);
void *func_021B830C();
void func_021B79D4(void **o, void *out);
u32 func_021B821C(u8 *p);
void func_0218E124(u8 *a, u32 s);
void func_0218ECF4(u32 a, VecFx32 *v);
int func_0218EC60(u32 a);
void func_0218ED48(u8 *p, u32 v);
void func_0218ED34(u8 *p, u16 v);
void func_0218ED58(u8 *p, u32 v);
extern void func_0218EC54(u8 *p);
extern void func_021B8314(void *p, void *buf);
extern void func_0218EC90(u32, u32 *);
int *func_021B836C(u32 q, u32 k);
u16 func_021B82F0(u8 *p);
int func_0207CFB8(int a, int b);
void func_021B8050(struct Sub *o, s16 *out);
extern int func_0207CC30(s16 *);
extern void func_0218ECD4(u32, u32 *);
extern void func_0218F05C(unsigned char *a);
extern fx32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void func_021B8328(u32, u32, u32 *);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern u32 func_020307B0(void *p);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern struct Obj *func_021B7884(u16 heap, u32 n, int a2);
extern u8 *func_0219EF44(u32 heap);
extern void func_0219EF6C(u8 *p);
extern void func_021B791C(void **o);
extern void func_021AB75C(u8 *p, u32 v);
extern u32 func_02049030(u32 a);
extern void func_0219EF7C(struct S *p, u32 b, u32 c);
extern u8 *func_0219F018(u8 *p);
extern int func_021B7934(u32 a, u32 b);
extern void func_021AB840(u32, int, u32, u16);
extern u32 func_021AB880(u8 *p);
extern u32 func_021AB884(u8 *p);
extern u32 func_021AB888(u32);
extern void func_021AB634(u32, u32, u32, u32);
extern u32 func_020490A8(u32 a, u32 b);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern int func_0219EFFC(u32 a);
extern u32 func_021AB650(u32);
extern u32 func_021AB868(u32);
extern u32 func_021B7954(u32);
extern void func_021B79E4(unsigned short *p);
extern int func_021B79F0(struct Obj_021BB36C *o, int flag);
extern void func_021B7970();
extern void func_021B79AC();
extern void func_021B79C4(u32 *p, u32 v);
extern void func_021B79CC(u32 *p);
extern void func_021B7D68(struct Obj *o, void *r);
extern void func_021B7C04(u8 *o, int k, int flag);
extern int func_02013C9C(u16 key);
extern void func_021B7C58(u32, u32, u32, u32, u32, u32);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_021ABEA0(u32 a, u32 b);
extern int func_0216E1A4(int a0, int a1);
extern u32 func_021ABE14(u8 *p);
extern void func_021BB778(int n);
extern void func_021ABFA8(u32, void *, int, int, void *, int);
Elem *func_021B8848(Table *t, u32 i);
void *func_021B8870(Table *t, u16 i);
void *func_021B8894(Table *t, u32 i);
void *func_021B88B8(Table *t, u16 i);
int func_021B88DC(Ov021Mover *p, int dir, int d);
void func_021B9164(FieldNogridMapperWork *o, Src *s, u8 *b);
void func_021B919C(u8 *p, u32 a);
u16 func_021B91A8(u8 *p);
int func_021B91AC(u32 a);
void *func_021B91C8(FieldNogridMapperWork *p);
void func_021B91F8(u8 *p, V3 *out);
void func_021B9238(const In *p, Out *out);
int func_021B9278(void *e, int a, void *map);
int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
int func_021B9338(u8 *p, u8 *base, u32 arg3, int arg4);
int func_021B9368(u8 *p, u32 a1, u32 a2, int a3, u32 a5);
int func_021B93D4(int dir);
int func_021B9404(int dir);
int func_021B9434(int dir);
u16 *func_021B9464(u16 *p);
void func_021B9478(u16 *p, u16 v);
void func_021B949C(u16 *p, u16 v);
int func_021B94C0(u16 *p, u16 v);
int func_021B94D8(u16 *r, E48_021B8848 *e, SR *sr);
u8 *func_021B9510(u16 *p, u8 *q, u32 v);
void func_021B9530(u16 *t, u8 *p, int dx, int dy, int a6);
int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6);
u32 func_021B960C(T *t, int b, u32 c);
int func_021B963C(u8 *a, u8 *b);
int func_021B96AC(u8 *a, u8 *b);
void func_021B9768(void *a, void *b);
void func_021B976C(void *a, void *b, void *c);
void func_021B977C(u8 *p);
int func_021B97D0(FieldNogridMapperWork2 *p, E70 *e);
int func_021B97FC(Obj_021B97FC *p, E48_021B977C *e);
int func_021B9828(VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *d, VecFx32 *e, VecFx32 *out);
void func_021B9A50(VecFx32 *out, VecFx32 *a, VecFx32 *b, int t);
void func_021B9B24(VecFx32 *a, VecFx32 *b, VecFx32 *c, int k);
void func_021B9B7C(void *p, VecFx32 *out);
void func_021B9C28(void *p, VecFx32 *out);
void func_021B9D60(void *p, VecFx32 *out);
int func_021B9E84(int a, void *p, const VecFx32 *pos, Rec *out, int arg);
int func_021B9FC8(int a, void *p, const VecFx32 *pos, Rec *out, int arg);
void func_021BA25C(u8 *p);
void func_021BA2B4(u8 *p);
void func_021BA310(void *p);
void func_021BA348(u32 p);
void func_021BA494(u32 a);
void func_021BA4C4(u8 *p);
void func_021BA4FC(u8 *p);
void func_021BA550(u32 p);
void func_021BA6E8(u32 p);
void func_021BA7B0(u8 *p);
void func_021BA7E0(u32 p, u16 ang, int r, VecFx32 *pos);
void func_021BA8E0(u32 p);
void func_021BA9B4(u8 *p);
void func_021BAA30(u8 *p);
void func_021BAA9C(u32 a);
void func_021BAB30(u32 a);
void func_021BABB4(void *p);
void func_021BABDC(void *p);
void func_021BAC04(u32 a);
void func_021BAC74(u32 p);
void func_021BACA8(u32 p);
int func_021BAE7C(FieldNogridMapperWork2 *a, FieldNogridMapperWork2 *b, const VecFx32 *c, VecFx32 *out, fx32 *t, VecFx32 *axis);
void func_021BB014(u32 a, unsigned char *b, u32 c);
void *func_021BB088(int a);
void func_021BB0A4(u8 *p, u32 a1, u32 a2, u32 a3);
void func_021BB0B4(u32 *a, u32 b, u32 c);
void func_021BB11C(u32 *p);
int func_021BB13C(char *a, char *b);
int func_021BB188(u16 a);
int func_021BB1A0(int x);
int func_021BB1AC(int x);
int func_021BB1B8(int x);
int func_021BB1C4(int x);
int func_021BB1D0(int x);
int func_021BB1DC(int x);
int func_021BB1E8(int x);
u32 *func_021BB1F4(u32 a, u32 b, u32 c, u32 d);
int func_021BB240(void *a, u32 b, u32 c, u32 d);
void func_021BB260(FieldNogridMapperWork2 *p, int b);
void func_021BB278(u32 *a, u16 *b, u32 c);
void func_021BB2F8(u32 a, u32 b, u32 c);
void func_021BB348(u32 a);
void func_021BB36C(Obj_021BB36C *p);
int func_021BB388(void **h);
void func_021BB394(u8 *p);
void func_021BB3A0(u8 *p, u32 a1);
void func_021BB3AC(u8 *p, u32 b);
void func_021BB3B8(u8 *p);
u32 func_021BB3C4(u8 *p, char *a1);
void func_021BB3D0(void **h, void *r);
void func_021BB3DC(u32 *p, int b, int c);
void func_021BB3E8(u32 *a, u32 b, u16 c, u16 d, u16 e, u32 f, u16 g);
void *func_021BB480(void *p);
Obj *func_021BB484(int a, int b);
void func_021BB4A8(u32 a, u8 *p);
void func_021BB4BC(u32 *p);
void func_021BB504(Obj *p);
void func_021BB528(u32 a, u32 b, u32 c, u32 d);
extern Elem d_021D9A30;
extern struct Elem d_021D9A0C;
extern u8 d_021DE2B0[];
extern u8 d_021DE2B4[];
extern u8 d_021DE2BC[];
extern s16 d_020A1B38[];
extern VecFx32 d_021D9A54;
extern VecFx32 d_021D9A60;
extern int d_021DE2C4;
extern int d_021DE2D0;
extern int d_021DE2E8;
extern u32 d_021D9A6C[];
extern int d_021D9A7C;




















Elem *func_021B8848(Table *t, u32 i)
{
    if (t->n6 > i) {
        return &t->p1c[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return &d_021D9A30;
}




















void *func_021B8870(Table *t, u16 i)
{
    if (t->n8 > i) {
        return t->p20[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return t->p20[0];
}




















void *func_021B8894(Table *t, u32 i)
{
    if (t->na > i) {
        return t->p24[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return t->p24[0];
}




















void *func_021B88B8(Table *t, u16 i)
{
    if (t->nc > i) {
        return t->p28[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return t->p28[0];
}




















/*
 * closed 2026-10-02 (share-A lane A2-09).  Three source facts turned the
 * 2026-09-27 near miss (end spilled, frame 0x54) into the image's allocation
 * (end in r7 for the whole body, frame 0x6c):
 *  - arm 93D4: flag = 0 is assigned after the 9404 call, through a local
 *    (r = 9404(dir); flag = 0; e1 = 8514(row, r, ...)); with flag = 0 ahead
 *    of the nested call, flag takes r6 and end is spilled.
 *  - arm 93D4: the e2 probe is two sequential ifs (8674, then 868C), not an
 *    else-if as in the other two-way probes of arms f08/93D4.
 *  - arms 9404/9434: each half has its own row/e locals; in arm 9434 the two
 *    spilled 8674-path lengths are block-level locals declared second-half
 *    first (the image has the first half's at the lower slot).
 * Arm-subset compiles (only f08, f08+9404, f08+9434) matched the image's
 * allocation exactly, which isolated the 93D4 arm as the cause.
 */
int func_021B88DC(Ov021Mover *p, int dir, int d)
{
    int end;
    Ov021Seg *seg;
    int r;

    seg = p->f04;
    end = p->f10;
    if (dir == seg->f08) {
        void *row;
        void *e0;
        void *e1;
        void *e2;
        int flag;

        row = func_021B87D8(p->f24, seg->f04);
        flag = 0;
        e0 = func_021B8514(row, dir, p->f24, p->f28, flag);
        e1 = func_021B8514(row, func_021B9434(dir), p->f24, p->f28, flag);
        e2 = func_021B8514(row, func_021B9404(dir), p->f24, p->f28, flag);
        func_021B9530(p->f28, (u8 *)p, d, 0, dir);
        if (p->f0C < end) {
            r = func_021B9280((u8 *)seg, p->f0C, end, p->f24);
            if (r >= (p->f14 < 0 ? -p->f14 : p->f14)) {
                return dir;
            }
            flag = 1;
        }
        if (e0 != 0 && flag == 0) {
            int len;
            int pos;
            func_021B96AC(row, p->f24);
            len = func_021B9278(e0, p->f1C, p->f24);
            pos = func_021B9280(e0, p->f0C - end, len, p->f24);
            r = func_021B854C((u8 *)p, e0, dir, p->f0C - end, p->f14, len, pos);
            if (r != 0) {
                return r;
            }
        }
        if (e1 != 0 && p->f14 <= 0) {
            if (func_021B8674(p->f24, e1, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, -p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, -p->f14, p->f0C - end, len, pos);
                if (r != 0) {
                    return r;
                }
            } else if (func_021B868C(p->f24, e1, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, len + p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, len + p->f14, -(p->f0C - end), len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (e2 != 0 && p->f14 >= 0) {
            if (func_021B8674(p->f24, e2, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, p->f14, -(p->f0C - end), len, pos);
                if (r != 0) {
                    return r;
                }
            } else if (func_021B868C(p->f24, e2, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, len - p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, len - p->f14, p->f0C - end, len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (flag) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        if (p->f0C <= end) {
            return dir;
        }
        p->f0C = p->f0C - d;
        return 0;
    } else if (dir == func_021B93D4(seg->f08)) {
        void *row;
        void *e1;
        void *e2;
        void *e0;
        int flag;

        row = func_021B87D8(p->f24, seg->f00);
        r = func_021B9404(dir);
        flag = 0;
        e1 = func_021B8514(row, r, p->f24, p->f28, flag);
        e2 = func_021B8514(row, func_021B9434(dir), p->f24, p->f28, flag);
        e0 = func_021B8514(row, dir, p->f24, p->f28, flag);
        func_021B9530(p->f28, (u8 *)p, -d, 0, dir);
        if (p->f0C >= 0) {
            r = func_021B9280((u8 *)seg, p->f0C, end, p->f24);
            if (r >= (p->f14 < 0 ? -p->f14 : p->f14)) {
                return dir;
            }
            flag = 1;
        }
        if (e0 != 0 && flag == 0) {
            int len;
            int pos;
            func_021B96AC(row, p->f24);
            len = func_021B9278(e0, p->f1C, p->f24);
            pos = func_021B9280(e0, len - (p->f0C < 0 ? -p->f0C : p->f0C), len, p->f24);
            r = func_021B854C((u8 *)p, e0, dir, len - (p->f0C < 0 ? -p->f0C : p->f0C), p->f14, len, pos);
            if (r != 0) {
                return r;
            }
        }
        if (e1 != 0 && p->f14 <= 0) {
            if (func_021B8674(p->f24, e1, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, -p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, -p->f14, p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            } else if (func_021B868C(p->f24, e1, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, len + p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, len + p->f14, -p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (e2 != 0 && p->f14 >= 0) {
            if (func_021B8674(p->f24, e2, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, p->f14, -p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            }
            if (func_021B868C(p->f24, e2, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, len - p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, len - p->f14, p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (flag) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        p->f0C = p->f0C + d;
        return 0;
    } else if (dir == func_021B9404(seg->f08)) {
        func_021B9530(p->f28, (u8 *)p, 0, d, dir);
        if (p->f14 > 0 && p->f14 % 16 == 0) {
            void *row;
            void *e;
            void *row2;
            void *e2;

            row = func_021B87D8(p->f24, seg->f00);
            e = func_021B8514(row, dir, p->f24, p->f28, 0);
            if (e != 0) {
                if (func_021B8674(p->f24, e, (u32)row)) {
                    int len;
                    int pos;
                    func_021B96AC(row, p->f24);
                    len = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, p->f14, -p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e, row)) {
                    int len;
                    int pos;
                    func_021B96AC(row, p->f24);
                    len = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, len - p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, len - p->f14, p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
            row2 = func_021B87D8(p->f24, seg->f04);
            e2 = func_021B8514(row2, dir, p->f24, p->f28, 0);
            if (e2 != 0) {
                if (func_021B8674(p->f24, e2, (u32)row2)) {
                    int len;
                    int pos;
                    func_021B96AC(row2, p->f24);
                    len = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, p->f14, end - p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e2, row2)) {
                    int len;
                    int pos;
                    func_021B96AC(row2, p->f24);
                    len = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, len - p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, len - p->f14, -(end - p->f0C), len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
        }
        if (p->f14 > 0 && p->f14 <= p->f18) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        return dir;
    } else if (dir == func_021B9434(seg->f08)) {
        func_021B9530(p->f28, (u8 *)p, 0, -d, dir);
        if (p->f14 < 0 && (p->f14 < 0 ? -p->f14 : p->f14) % 16 == 0) {
            void *row;
            void *e;
            void *row2;
            void *e2;
            int lenB;
            int lenA;

            row = func_021B87D8(p->f24, seg->f00);
            e = func_021B8514(row, dir, p->f24, p->f28, 0);
            if (e != 0) {
                if (func_021B8674(p->f24, e, (u32)row)) {
                    int pos;
                    func_021B96AC(row, p->f24);
                    lenA = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, (p->f14 < 0 ? -p->f14 : p->f14), lenA, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, (p->f14 < 0 ? -p->f14 : p->f14), p->f0C, lenA, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e, row)) {
                    int len;
                    int pos;
                    func_021B96AC(row, p->f24);
                    len = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, len - (p->f14 < 0 ? -p->f14 : p->f14), len, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, len - (p->f14 < 0 ? -p->f14 : p->f14), -p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
            row2 = func_021B87D8(p->f24, seg->f04);
            e2 = func_021B8514(row2, dir, p->f24, p->f28, 0);
            if (e2 != 0) {
                if (func_021B8674(p->f24, e2, (u32)row2)) {
                    int pos;
                    func_021B96AC(row2, p->f24);
                    lenB = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, (p->f14 < 0 ? -p->f14 : p->f14), lenB, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, (p->f14 < 0 ? -p->f14 : p->f14), -(end - p->f0C), lenB, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e2, row2)) {
                    int len;
                    int pos;
                    func_021B96AC(row2, p->f24);
                    len = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, len - (p->f14 < 0 ? -p->f14 : p->f14), len, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, len - (p->f14 < 0 ? -p->f14 : p->f14), end - p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
        }
        if (p->f14 < 0 && (p->f14 < 0 ? -p->f14 : p->f14) <= p->f18) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        return dir;
    }
    return 0;
}




















/*
 * The mode value 2 is an enum-typed local initialised at declaration: the enum
 * keeps it out of constant propagation, so it is materialised at entry, overlaps
 * s and the loaded x2c (r1) and takes r3, which the later zero then reuses.
 */
void func_021B9164(FieldNogridMapperWork *o, Src *s, u8 *b)
{
    Mode m = MODE_2;
    o->f24 = s;
    o->f1C = s->x2c;
    o->h0 = m;
    o->b33 = 0;
    o->b32 = 0;
    o->b2c = 0;
    o->f78 = b;
    o->f4 = 0;
    o->fC = 0;
    o->f14 = 0;
    o->f20 = 0;
    o->f28 = b + 0x50;
    o->b74 = 0;
    o->h8 = 0;
}





















void func_021B919C(u8 *p, u32 a)
{
    func_021B9164((FieldNogridMapperWork *)p, (Src *)a, (u8 *)*(u32 *)&((struct Obj01358 *)p)->f78);
}





















u16 func_021B91A8(u8 *p)
{
    return ((struct Obj18138 *)p)->f2;
}





















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B91AC(u32 a)
{
if (((struct Obj09186 *)((u8 *)(a)))->f0 < 2) {
    if (((struct Obj09186 *)((u8 *)(a)))->f4 != 0) {
        if (((struct Obj09186 *)((u8 *)(a)))->f2 != 0) {
            return 1;
        }
    }
}
return 0;
}





















void *func_021B91C8(FieldNogridMapperWork *p)
{
    switch (p->h0) {
    case 0:
        return func_021B8820(p->f24, p->f4->f3C);
    case 1:
        return func_021B8820(p->f24, p->f4->f10);
    }
    return &(*(int *)&d_021D9A0C);
}





















/*
 * Addresses are Black-image addresses.
 */
void func_021B91F8(u8 *p, V3 *out)
{
    Fn f;

    if (((struct Obj00454 *)p)->f0 == 0) {
        *out = *(V3 *)(*(u8 * *)&((struct Obj00454 *)p)->f4 + 0x30);
        return;
    }
    if (((struct Obj00454 *)p)->f0 == 1) {
        u32 *r = (u32 *)func_021B8848((Table *)(((struct Obj00454 *)p)->f24), ((struct Obj20083 *)(*(u8 * *)&((struct Obj00454 *)p)->f4))->fC);
        f = (Fn)func_021B8894((Table *)(((struct Obj00454 *)p)->f24), *r);
        if (f)
            f(p, out);
    }
}





















void func_021B9238(const In *p, Out *out)
{
    int v;
    u32 t;

    t = p->t;
    out->t = t;
    if (t == 0)
        v = func_021B97D0((FieldNogridMapperWork2 *)p->p24, (E70 *)p->p4);
    else
        v = func_021B97FC(p->p24, p->p4);
    out->a = v;
    out->d = p->pc / 16;
    out->e = p->p14 / 16;
    out->c = p->p20;
}





















int func_021B9278(void *e, int a, void *map)
{
return (((struct Obj18139 *)((u8 *)(e)))->f14 << 4);
}





















int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl)
{
    u8 *row1 = *(u8 * *)&((struct Obj02659 *)tbl)->f10 + ((struct Obj02052 *)a)->f0 * 0x70;
    u8 *row2 = *(u8 * *)&((struct Obj02659 *)tbl)->f10 + ((struct Obj02052 *)a)->f4 * 0x70;
    int sC;
    int s8;
    int num;
    int i;

    s8 = -1;
    sC = -1;
    for (i = 0; i < 4; i++) {
        u32 v1 = *(u32 *)(row1 + i * 4);
        if (v1 != 0xFFFF) {
            if (a == *(u8 * *)&((struct Obj02659 *)tbl)->f14 + v1 * 0x48)
                sC = *(int *)(row1 + i * 4 + 0x20);
        }
        {
            u32 v2 = *(u32 *)(row2 + i * 4);
            if (v2 != 0xFFFF) {
                if (a == *(u8 * *)&((struct Obj02659 *)tbl)->f14 + v2 * 0x48)
                    s8 = *(int *)(row2 + i * 4 + 0x20);
            }
        }
    }
    if (sC < 0)
        sC = s8;
    if (s8 < 0)
        s8 = sC;
    if (arg2 > arg3 - 0x10)
        arg2 = arg3 - 0x10;
    num = s8 - sC;
    if (arg3 - 0x10 != 0)
        num = (int)((u32)num * arg2) / (int)(arg3 - 0x10);
    return num + sC;
}





















int func_021B9338(u8 *p, u8 *base, u32 arg3, int arg4)
{
    int r = func_021B9280(base, ((struct Obj04891 *)p)->fC, arg3, *(u8 * *)&((struct Obj04891 *)p)->f24);
    int f = ((struct Obj04891 *)p)->f14;

    ((struct Obj04891 *)p)->f18 = r;
    if ((f < 0 ? -f : f) >= r) {
        if (f > 0)
            ((struct Obj04891 *)p)->f14 = r;
        else
            ((struct Obj04891 *)p)->f14 = -r;
    }
    return arg4;
}





















int func_021B9368(u8 *p, u32 a1, u32 a2, int a3, u32 a5)
{
    int i;

    func_021B7EE4((void *)((struct Obj03136 *)p)->f1C, (Rec *)a1);
    func_021B80E0(((struct Obj03136 *)p)->f1C, 4, a2);
    func_021B810C((struct Sub *)(((struct Obj03136 *)p)->f1C));
    func_021B80E0(((struct Obj03136 *)p)->f1C, 0, a2);
    for (i = 0; i < 16; i++) {
        if (a3 == i)
            func_021B8028(((struct Obj03136 *)p)->f1C, a5);
        func_021B810C((struct Sub *)(((struct Obj03136 *)p)->f1C));
    }
    if (func_0203EFC8((void *)a1, (void *)(((struct Obj03136 *)p)->f1C + 0x5c), 8) == 0)
        return 0;
    return func_021B7DE0(((struct Obj03136 *)p)->f1C, ((struct Obj03136 *)p)->f1C + 0x5c);
}




















int func_021B93D4(int dir)
{
    switch (dir) {
    case 1: return 3;
    case 3: return 1;
    case 4: return 2;
    case 2: return 4;
    }
    return 0;
}




















int func_021B9404(int dir)
{
    switch (dir) {
    case 1: return 2;
    case 3: return 4;
    case 4: return 1;
    case 2: return 3;
    }
    return 0;
}




















int func_021B9434(int dir)
{
    switch (dir) {
    case 1: return 4;
    case 3: return 2;
    case 4: return 3;
    case 2: return 1;
    }
    return 0;
}





















u16 *func_021B9464(u16 *p)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        p[i] = 0xFFFF;
    }
    return p;
}





















void func_021B9478(u16 *p, u16 v)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (p[i] == 0xFFFF) {
            p[i] = v;
            return;
        }
    }
}





















void func_021B949C(u16 *p, u16 v)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (v == p[i]) {
            p[i] = 0xFFFF;
            return;
        }
    }
}





















int func_021B94C0(u16 *p, u16 v)
{
    int i;
    for (i = 0; i < 0x12; i++)
        if (p[i] == v)
            return 1;
    return 0;
}




















/*
 * The element count is a volatile u16: the original reads it once for the
 * loop entry guard and again on every bottom test, while the array base is
 * hoisted.  A plain u16 count is CSEd into one register (6 bytes shorter).
 */
int func_021B94D8(u16 *r, E48_021B8848 *e, SR *sr)
{
    int i;
    int found = 0;
    for (i = 0; i < sr->n; i++) {
        if (e == &sr->arr[i])
            found = i;
    }
    return func_021B94C0(r, found);
}





















u8 *func_021B9510(u16 *p, u8 *q, u32 v)
{
    if (func_021B94C0(p, (u16)v) == 0)
        return func_021B87FC(q, v);
    return 0;
}



















void func_021B9530(u16 *t, u8 *p, int dx, int dy, int a6)
{
    if (func_021B94D8(t, (E48_021B8848 *)(*(u8 * *)&((struct Obj01203 *)p)->f4), (SR *)(*(u8 * *)&((struct Obj01203 *)p)->f24)) != 0) {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj01203 *)p)->f24, **(u32 * *)&((struct Obj01203 *)p)->f4);
        u8 *res = func_021B8514(row, a6, *(u8 * *)&((struct Obj01203 *)p)->f24, t, 0);
        u32 out1, out2;

        func_021B86A4(*(u8 * *)&((struct Obj01203 *)p)->f24, (const u32 *)(*(u8 * *)&((struct Obj01203 *)p)->f4), (int *)(&out1), (int *)(&out2),
                      (u16 *)t, ((struct Obj01203 *)p)->f1C);
        ((struct Obj01203 *)p)->fC += dx;
        ((struct Obj01203 *)p)->f14 += dy;
        if (((struct Obj01203 *)p)->fC > (int)out1)
            ((struct Obj01203 *)p)->fC = out1;
        if (res == 0) {
            int f = ((struct Obj01203 *)p)->f14;
            int a = f < 0 ? -f : f;
            if (a > (int)out2) {
                if (f > 0)
                    ((struct Obj01203 *)p)->f14 = out2;
                else
                    ((struct Obj01203 *)p)->f14 = -(int)out2;
            }
        }
        return;
    }
    ((struct Obj01203 *)p)->fC += dx;
    ((struct Obj01203 *)p)->f14 += dy;
}



















int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6)
{
    u32 c, d;

    if (func_021B94D8((u16 *)p, (E48_021B8848 *)q, (SR *)sr) == 0)
        goto ok;
    func_021B86A4(sr, (u32 *)q, (int *)(&c), (int *)(&d), (u16 *)((u32)p), a6);
    if (a3 > (int)c)
        goto fail;
    if (a4 < 0)
        a4 = -a4;
    if (a4 > (int)d)
        goto fail;
    return 1;
fail:
    return 0;
ok:
    return 1;
}


















u32 func_021B960C(T *t, int b, u32 c)
{
    int i;
    int r;
    for (i = 0; i < 4; i++) {
        r = (int)func_021B87FC((u8 *)c, t->key[i]);
        if (r == b)
            return t->val[i];
    }
    return 0;
}



















int func_021B963C(u8 *a, u8 *b)
{
    u8 *row1, *row2;
    u32 r1, r2;

    if (((struct Obj02052 *)a)->f0 == 0xFFFF || ((struct Obj02052 *)a)->f4 == 0xFFFF)
        return 0;
    row1 = func_021B87D8(b, ((struct Obj02052 *)a)->f0);
    row2 = func_021B87D8(b, ((struct Obj02052 *)a)->f4);
    r1 = func_021B960C((T *)((u32 *)row1), (int)a, (u32)b);
    if (r1 == 0)
        return 0;
    if (r1 != ((struct Obj02052 *)a)->f8)
        return 0;
    r2 = func_021B960C((T *)((u32 *)row2), (int)a, (u32)b);
    if (r2 == 0)
        return 0;
    if (r2 != (u32)func_021B93D4(((struct Obj02052 *)a)->f8))
        return 0;
    return 1;
}



















int func_021B96AC(u8 *a, u8 *b)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        u32 val = *(u32 *)(a + i * 4 + 0x10);
        u32 key = *(u32 *)(a + i * 4);
        u8 *row;
        u8 *r4;
        u8 *r0;

        if ((val == 0) != (key == 0xFFFF))
            return 0;
        if (key == 0xFFFF)
            continue;
        row = func_021B87FC(b, key);
        r4 = func_021B87D8(b, ((struct Obj09187 *)row)->f0);
        r0 = func_021B87D8(b, ((struct Obj09187 *)row)->f4);
        if (r4 != a && r0 != a)
            return 0;
        if (*(u32 *)(a + i * 4 + 0x10) == 0)
            continue;
        for (j = i + 1; j < 4; j++) {
            if (*(u32 *)(a + i * 4 + 0x10) == (u32)func_021B93D4(*(u32 *)(a + j * 4 + 0x10))) {
                if (((struct Obj09187 *)row)->f8 != *(u32 *)(func_021B87FC(b, *(u32 *)(a + j * 4)) + 8))
                    return 0;
            }
        }
    }
    return 1;
}



















void func_021B9768(void *a, void *b)
{
}


















void func_021B976C(void *a, void *b, void *c)
{
    if (b != 0) {
        func_021B9768(a, ((FieldNogridMapperWork *)b)->f30);
    }
}



















void func_021B977C(u8 *p)
{
    void *x;
    void *y;

    if (((struct Obj04250 *)p)->f0 == 0) {
        func_021B976C(0, ((struct Obj04250 *)p)->f4, d_021DE2B0);
    } else if (((struct Obj04250 *)p)->f0 == 1) {
        x = func_021B87D8(((struct Obj04250 *)p)->f24, **(u32 * *)&((struct Obj04250 *)p)->f4);
        y = func_021B87D8(((struct Obj04250 *)p)->f24, ((struct Obj20089 *)(*(u8 * *)&((struct Obj04250 *)p)->f4))->f4);
        func_021B976C(d_021DE2B4, x, 0);
        func_021B976C(d_021DE2BC, y, d_021DE2B0);
    }
}



















int func_021B97D0(FieldNogridMapperWork2 *p, E70 *e)
{
    int i;

    for (i = 0; i < p->h0; i++) {
        if (e == &p->f10[i]) {
            return i;
        }
    }
    return 0;
}


















/*
 * 2026-10-02: the per-iteration reload of the count (ldrh in the loop) that
 * kept the earlier draft at DIFF comes from a volatile count field; every
 * non-volatile spelling hoists it like func_021B97D0.
 */
int func_021B97FC(Obj_021B97FC *p, E48_021B977C *e)
{
    int i;

    for (i = 0; i < p->h2; i++) {
        if (e == &p->f14[i]) {
            return i;
        }
    }
    return 0;
}

















static inline int FX_Mul(int a, int b)
{
    return (int)(((long long)a * b + 0x800LL) >> 12);
}

















static inline void VEC_Set(VecFx32 *v, fx32 x, fx32 y, fx32 z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

















/*
 * Segment/plane intersection: the plane through c spanned by a and b, the
 * segment from d to e; writes the hit point to out and returns 1.
 * The hit point is computed z, y, x and stored x, y, z: an inline VEC_Set
 * evaluates its arguments last to first
 * (docs/idioms/an-inline-wrappers-arguments-are-evaluated-last-to-first.md).
 *
 * Addresses are Black-image addresses.
 */
int func_021B9828(VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *d, VecFx32 *e, VecFx32 *out)
{
    VecFx32 n;
    VecFx32 s;
    VecFx32 u;
    VecFx32 v;
    int len;
    int num;
    int den;
    int t;

    VEC_Subtract(e, d, &s);
    len = VEC_Mag(&s);
    VEC_Normalize(&s, &s);
    VEC_Normalize(a, &u);
    VEC_Normalize(b, &v);
    VEC_CrossProduct(&u, &v, &n);
    VEC_Normalize(&n, &n);
    num = (FX_Mul(n.x, c->x) + FX_Mul(n.y, c->y) + FX_Mul(n.z, c->z))
        - (FX_Mul(n.x, d->x) + FX_Mul(n.y, d->y) + FX_Mul(n.z, d->z));
    den = FX_Mul(n.x, s.x) + FX_Mul(n.y, s.y) + FX_Mul(n.z, s.z);
    if (den == 0) {
        return 0;
    }
    t = FX_Div(num, den);
    if (t > len) {
        return 0;
    }
    if (t <= 0x1000) {
        return 0;
    }
    VEC_Set(out, d->x + FX_Mul(s.x, t), d->y + FX_Mul(s.y, t),
            d->z + FX_Mul(s.z, t));
    return 1;
}

















void func_021B9A50(VecFx32 *out, VecFx32 *a, VecFx32 *b, int t)
{
    VecFx32 na;
    VecFx32 nb;
    u16 w;
    int s;
    int aw;

    VEC_Normalize(a, &na);
    VEC_Normalize(b, &nb);
    w = FX_AcosIdx(VEC_DotProduct(&na, &nb));
    s = ((u16 *)d_020A1B38)[(w >> 4) * 2];
    if (s == 0) {
        *out = nb;
        return;
    }
    aw = w << 12;
    func_020520A4((const struct Vec3 *)(&na), FX_Div(((u16 *)d_020A1B38)[(FX_Mul(aw, FX32_ONE - t) >> 16) * 2], s), (struct Vec3 *)(&na));
    func_020520A4((const struct Vec3 *)(&nb), FX_Div(((u16 *)d_020A1B38)[(FX_Mul(aw, t) >> 16) * 2], s), (struct Vec3 *)(&nb));
    VEC_Add(&na, &nb, out);
    VEC_Normalize(out, out);
}

















void func_021B9B24(VecFx32 *a, VecFx32 *b, VecFx32 *c, int k)
{
    VecFx32 t = {0, 0, 0};
    int m1;
    int m2;
    int d;

    func_021B9A50(a, b, c, k);
    m1 = func_0207CBD0(b);
    m2 = func_0207CBD0(c);
    d = m2 - m1;
    func_0207CEE4(m1 + (int)(((s64)d * k + 0x800) >> 12), a, &t, a);
}
















void func_021B9B7C(void *p, VecFx32 *out)
{
    VecFx32 t;
    VecFx32 w;
    VecFx32 u;
    int s;
    VecFx32 *a;
    u8 *b;
    int m;
    int k;

    func_021B82F4(p);
    s = (u32)func_0207C768((int)(func_021B82F8(p) << 12), (int)(func_021B82FC(p) << 12));
    a = (VecFx32 *)func_021B833C(p);
    b = func_021B834C(p);
    a = (VecFx32 *)((u8 *)a + 0x30);
    func_0207CA00((VecFx32 *)(b + 0x30), a, &t);
    func_0207CEE4(s, &t, a, out);
    w = d_021D9A54;
    m = func_021B8300(p);
    k = func_021B8308(p);
    func_0207CAE8(&t, &w, &u);
    func_0207CCA4(&u, &u);
    func_0207CEE4((int)(((s64)(m << 12) * k + 0x800) >> 12), &u, out, out);
}
















void func_021B9C28(void *p, VecFx32 *out)
{
    VecFx32 c;
    VecFx32 d;
    VecFx32 e;
    VecFx32 g;
    VecFx32 f;
    VecFx32 h;
    VecFx32 i;
    int s;
    int t2;
    int t1;
    VecFx32 *a;
    VecFx32 *b;
    u8 *q;
    int r;

    func_021B82F4(p);
    a = (VecFx32 *)func_021B833C(p);
    b = (VecFx32 *)func_021B834C(p);
    a = (VecFx32 *)((u8 *)a + 0x30);
    b = (VecFx32 *)((u8 *)b + 0x30);
    t1 = func_021B82F8(p);
    t2 = func_021B82FC(p);
    s = (u32)func_0207C768((int)((u32)t1 << 12), (int)((u32)t2 << 12));
    out->y = b->y - a->y;
    out->y = (u32)func_0207C768((int)(FX_Mul(out->y, t1 << 12)), (int)(t2 << 12));
    out->y += a->y;
    q = func_021B835C(p);
    c.x = ((struct Obj12865 *)q)->f4;
    c.y = out->y;
    c.z = ((struct Obj12865 *)q)->fC;
    func_0207CA00(a, &c, &d);
    func_0207CA00(b, &c, &e);
    d.y = 0;
    e.y = 0;
    func_0207CA00(&e, &d, &f);
    f.y = 0;
    func_0207CCA4(&f, &f);
    func_021B9B24(&g, &d, &e, s);
    func_0207C9D0(&c, &g, out);
    r = (int)(((s64)((int)func_021B8300(p) << 12) * (int)func_021B8308((u8 *)p) + 0x800) >> 12);
    func_0207CCA4(&g, &h);
    func_0207CAE8(&h, &f, &i);
    if (i.y < 0) {
        func_0207CEE4(-r, &h, out, out);
    } else {
        func_0207CEE4(r, &h, out, out);
    }
}
















void func_021B9D60(void *p, VecFx32 *out)
{
    VecFx32 c;
    VecFx32 d;
    VecFx32 e;
    VecFx32 g;
    VecFx32 f;
    VecFx32 h;
    VecFx32 i;
    VecFx32 w;
    int s;
    VecFx32 *a;
    VecFx32 *b;
    u8 *q;
    u8 *ta;
    u8 *tb;
    int r;

    func_021B82F4(p);
    ta = func_021B833C(p);
    tb = func_021B834C(p);
    a = (VecFx32 *)(ta + 0x30);
    b = (VecFx32 *)(tb + 0x30);
    s = (u32)func_0207C768((int)(func_021B82F8(p) << 12), (int)(func_021B82FC(p) << 12));
    q = func_021B835C(p);
    c.x = ((struct Obj09633 *)q)->f4;
    c.y = ((struct Obj09633 *)q)->f8;
    c.z = ((struct Obj09633 *)q)->fC;
    func_0207CA00(a, &c, &d);
    func_0207CA00(b, &c, &e);
    func_0207CA00(&e, &d, &f);
    func_0207CCA4(&f, &f);
    func_021B9B24(&g, &d, &e, s);
    func_0207C9D0(&c, &g, out);
    r = (int)(((s64)((int)func_021B8300(p) << 12) * (int)func_021B8308((u8 *)p) + 0x800) >> 12);
    if (g.x != 0 && g.z != 0) {
        g.y = 0;
    } else {
        w = d_021D9A60;
        func_0207CA00(b, a, &g);
        func_0207CAE8(&g, &w, &g);
    }
    func_0207CCA4(&g, &h);
    func_0207CAE8(&h, &f, &i);
    if (i.y < 0) {
        func_0207CEE4(-r, &h, out, out);
    } else {
        func_0207CEE4(r, &h, out, out);
    }
}















/*
 * Builds the 8-byte record for id `a` at pos between the two entries of
 * func_021B8230's link: horizontal distance and height offset scaled by
 * func_021B8248 and rounded by func_021B8378; returns 0 when out of range,
 * else 1 when the record round-trips unchanged through func_021B8250 and
 * func_021B7D38.
 * pos->x and pos->z go through locals: stored straight into m, the y = 0
 * stores interleave with them and the loads split; the out-of-range
 * `return 0` is the fall-out of an if around the rest (it sits after the
 * final epilogue). The spill slots follow h0, h1, L, dist, diff declared
 * in that order.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9E84(int a, void *p, const VecFx32 *pos, Rec *out, int arg)
{
    VecFx32 A;
    VecFx32 C;
    VecFx32 m;
    VecFx32 n;
    int B;
    Rec buf;
    int *info;
    int k;
    int *e0;
    int *e1;
    int h0;
    int h1;
    u32 L;
    u32 dist;
    int diff;
    int i;
    int x;
    int z;

    info = func_021B8230(p, a);
    e0 = func_021B8224(p, info[0]);
    e1 = func_021B8224(p, info[1]);
    k = func_021B8248(p);
    if (func_021BAE7C((FieldNogridMapperWork2 *)e0, (FieldNogridMapperWork2 *)e1, pos, &A, (fx32 *)&B, &C) == 0) {
        return 0;
    }
    x = pos->x;
    z = pos->z;
    m.x = x;
    n.x = A.x;
    m.z = z;
    n.z = A.z;
    m.y = 0;
    n.y = 0;
    dist = (int)(u32)func_0207C768((int)func_0207CF3C(&m, &n), (int)k) >> 12;
    func_021B823C(p, info[3]);
    L = info[5] << 4;
    diff = L - ((int)(u32)func_0207C768((int)B, (int)k) >> 12);
    for (i = 0; i < 4; i++) {
        if (a == e0[i]) {
            h0 = e0[i + 8];
        }
        if (a == e1[i]) {
            h1 = e1[i + 8];
        }
    }
    if (dist <= h0 + (h1 - h0) * diff / L + 0x10) {
        out->id = a;
        out->f2 = 1;
        out->f3 = 3;
        if (C.y >= 0) {
            out->f4 = func_021B8378(dist);
        } else {
            out->f4 = -func_021B8378(dist);
        }
        out->f6 = func_021B8378(diff);
        func_021B8250(p, out, &buf);
        func_021B7D38(p, &buf, arg);
        if (func_0203EFC8((const u8 *)out, (const u8 *)(&buf), 8) == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}














int func_021B9FC8(int a, void *p, const VecFx32 *pos, Rec *out, int arg)
{
    VecFx32 P;
    VecFx32 Q;
    VecFx32 D;
    VecFx32 E;
    VecFx32 F;
    VecFx32 A;
    VecFx32 C;
    VecFx32 R;
    VecFx32 S;
    VecFx32 G;
    VecFx32 H;
    int B;
    Rec buf;
    int len;
    u32 lim;
    u32 n;
    int k;
    u32 i;
    int *info;
    int *e0;
    int *e1;
    void *obj;
    int m;
    int t;
    int d;
    int u;
    u32 dist;
    int x;
    int z;

    info = func_021B8230(p, a);
    e0 = func_021B8224(p, info[0]);
    e1 = func_021B8224(p, info[1]);
    if (func_021BAE7C((FieldNogridMapperWork2 *)e0, (FieldNogridMapperWork2 *)e1, pos, &A, (fx32 *)&B, &C) == 0) {
        return 0;
    }
    out->id = a;
    out->f2 = 1;
    out->f3 = 3;
    out->f4 = 0;
    out->f6 = 0;
    obj = (void *)func_021B824C(p);
    func_021B7EE4(obj, out);
    n = func_021B82FC(obj) >> 4;
    func_021B8028((u32)obj, (u32)&P);
    Q.x = P.x;
    Q.y = P.y;
    Q.z = P.z;
    k = func_021B8248(p);
    for (i = 1; i < n; i++) {
        out->f6 = i;
        func_021B7EE4(obj, out);
        func_021B8028((u32)obj, (u32)&P);
        lim = func_021B8304(obj);
        func_0207CA00(&Q, &P, &D);
        func_0207CA00(pos, &P, &E);
        func_0207CCA4(&D, &F);
        len = func_0207CBD0(&D);
        func_0207CCA4(&D, &G);
        func_0207CCA4(&E, &H);
        func_0207CAE8(&G, &H, &C);
        D = F;
        m = func_0207CBD0(&E);
        func_0207CCA4(&E, &E);
        t = func_0207C768(m, len);
        E.x = FX_Mul(E.x, t);
        E.y = FX_Mul(E.y, t);
        E.z = FX_Mul(E.z, t);
        d = func_0207CA68(&D, &E);
        if (d <= 0x1000 && d >= 0) {
            u = FX_Mul(d, len);
            A.x = FX_Mul(F.x, u);
            A.y = FX_Mul(F.y, u);
            A.z = FX_Mul(F.z, u);
            func_0207C9D0(&P, &A, &A);
            x = pos->x;
            z = pos->z;
            R.x = x;
            R.z = z;
            R.y = 0;
            S.x = A.x;
            S.y = 0;
            S.z = A.z;
            dist = func_0207C768(func_0207CF3C(&R, &S), k) >> 12;
            lim += 0x10;
            if (lim >= dist) {
                if (C.y >= 0) {
                    out->f4 = func_021B8378(dist);
                } else {
                    out->f4 = -func_021B8378(dist);
                }
                func_021B8250(p, out, &buf);
                func_021B7D38(p, out, arg);
                if (func_0203EFC8((const u8 *)out, (const u8 *)(&buf), 8) == 0) {
                    return 1;
                }
                return 0;
            }
        }
        Q.x = P.x;
        Q.y = P.y;
        Q.z = P.z;
    }
    return 0;
}















void func_021BA25C(u8 *p)
{
    VecFx32 v;
    u8 *q;

    func_021B8220(p);
    q = func_021B830C();
    func_021B79D4((void **)p, &v);
    func_0218E124((u8 *)func_021B821C(p), 2);
    v.x += ((struct Obj09634 *)q)->f4;
    v.y += ((struct Obj09634 *)q)->f8;
    v.z += ((struct Obj09634 *)q)->fC;
    func_0218ECF4(func_021B821C(p), &v);
    func_0218EC60(func_021B821C(p));
}















void func_021BA2B4(u8 *p)
{
    VecFx32 v;
    u8 *q;
    u32 o;
    u16 x, y;
    u32 z;

    o = func_021B821C(p);
    func_021B8220(p);
    q = func_021B830C();
    func_0218E124((u8 *)o, 0);
    func_0218EC60(func_021B821C(p));
    func_021B79D4((void **)p, &v);
    x = ((struct Obj09635 *)q)->f4;
    y = ((struct Obj09635 *)q)->f8;
    z = ((struct Obj09635 *)q)->fC;
    func_0218ED48((u8 *)o, y);
    func_0218ED34((u8 *)o, x);
    func_0218ED58((u8 *)o, z);
}















void func_021BA310(void *p)
{
    void *a;
    void *b;
    int buf[3];

    a = (void *)func_021B8220(p);
    b = (void *)func_021B821C(p);
    func_021BA2B4(p);
    func_0218EC54(b);
    func_021B8314(a, buf);
    func_0218EC90((u32)b, (u32 *)buf);
}













/*
 * Twin of func_021BACA8 without the vector part.  The angle and scalar
 * locals are int with explicit (u16) casts: as u16 locals the k0 loads
 * reorder and the ratio stays in a register pair instead of its
 * [sp]/[sp+4] spill.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA348(u32 p)
{
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    u32 h;
    int s;
    int d;
    int t;
    int x0;
    int y0;
    int z0;
    int y1;
    int z1;
    int dx;
    int dy;
    u16 x;
    u16 y;

    q = func_021B8220((u8 *)p);
    a = (u32)func_021B833C((u8 *)q);
    b = (u32)func_021B834C((u8 *)q);
    h = func_021B821C((u8 *)p);
    func_0218E124((u8 *)h, 0);
    func_0218EC60(func_021B821C((u8 *)p));
    k0 = func_021B836C(q, a);
    k1 = func_021B836C(q, b);
    d = func_021B82FC((u8 *)q);
    t = func_021B82F8((u8 *)q);
    s = (u32)func_0207C768((int)(t << 12), (int)(d << 12));
    x0 = (u16)k0[1];
    y0 = (u16)k0[2];
    z0 = k0[3];
    y1 = (u16)k1[2];
    z1 = k1[3];
    dx = (u16)k1[1] - x0;
    if (dx >= 0x8000)
        dx -= 0x10000;
    else if (dx <= -0x8000)
        dx += 0x10000;
    x = x0 + (FX_Mul(dx << 12, s) >> 12);
    dy = y1 - y0;
    if (dy >= 0x8000)
        dy -= 0x10000;
    else if (dy <= -0x8000)
        dy += 0x10000;
    y = y0 + (FX_Mul(dy << 12, s) >> 12);
    func_0218ED48((u8 *)h, y);
    func_0218ED34((u8 *)h, x);
    func_0218ED58((u8 *)h, z0 + FX_Mul(z1 - z0, s));
}













void func_021BA494(u32 a)
{
    u32 h = func_021B821C((u8 *)a);
    u32 v[3];

    func_021BA348(a);
    func_0218EC54((u8 *)h);
    func_021B79D4((void **)a, v);
    func_0218EC90(h, v);
}













void func_021BA4C4(u8 *p)
{
    VecFx32 v;
    u32 q;
    u32 o;

    q = func_021B8220(p);
    o = func_021B821C(p);
    func_021BA348((u32)p);
    func_0218EC54((u8 *)o);
    func_021B8314((void *)q, &v);
    func_0218EC90(o, (u32 *)&v);
}













void func_021BA4FC(u8 *p)
{
    VecFx32 a;
    VecFx32 b;
    u8 *q;
    u32 o;

    func_021B8220(p);
    q = func_021B830C();
    o = func_021B821C(p);
    func_0218E124((u8 *)o, 2);
    func_0218EC54((u8 *)func_021B821C(p));
    a.x = ((struct Obj05053 *)q)->f4;
    a.y = ((struct Obj05053 *)q)->f8;
    a.z = ((struct Obj05053 *)q)->fC;
    b.x = ((struct Obj05053 *)q)->f10;
    b.y = ((struct Obj05053 *)q)->f14;
    b.z = ((struct Obj05053 *)q)->f18;
    func_0218ECF4(o, &a);
    func_0218EC90(o, (u32 *)&b);
}












void func_021BA550(u32 p)
{
    VecFx32 m;
    VecFx32 n;
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    u32 h;
    int d;
    int t;

    q = func_021B8220((u8 *)p);
    h = func_021B821C((u8 *)p);
    a = (u32)func_021B833C((u8 *)q);
    b = (u32)func_021B834C((u8 *)q);
    k0 = func_021B836C(q, a);
    k1 = func_021B836C(q, b);
    func_0218E124((u8 *)h, 2);
    func_0218EC54((u8 *)func_021B821C((u8 *)p));
    d = func_021B82FC((u8 *)q);
    t = func_021B82F8((u8 *)q);
    m.x = (u32)func_0207C768((int)(FX_Mul(k1[1] - k0[1], t << 12)), (int)(d << 12));
    m.y = (u32)func_0207C768((int)(FX_Mul(k1[2] - k0[2], t << 12)), (int)(d << 12));
    m.z = (u32)func_0207C768((int)(FX_Mul(k1[3] - k0[3], t << 12)), (int)(d << 12));
    n.x = (u32)func_0207C768((int)(FX_Mul(k1[4] - k0[4], t << 12)), (int)(d << 12));
    n.y = (u32)func_0207C768((int)(FX_Mul(k1[5] - k0[5], t << 12)), (int)(d << 12));
    n.z = (u32)func_0207C768((int)(FX_Mul(k1[6] - k0[6], t << 12)), (int)(d << 12));
    m.x += k0[1];
    m.y += k0[2];
    m.z += k0[3];
    n.x += k0[4];
    n.y += k0[5];
    n.z += k0[6];
    func_0218ECF4(h, &m);
    func_0218EC90(h, (u32 *)&n);
}










void func_021BA6E8(u32 p)
{
    VecFx32 v;
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    int d;
    int t;
    u16 x;
    int x0;
    int y;

    q = func_021B8220((u8 *)p);
    func_021B821C((u8 *)p);
    if (func_021B82F0((u8 *)q) == 1) {
        a = (u32)func_021B833C((u8 *)q);
        b = (u32)func_021B834C((u8 *)q);
        k0 = func_021B836C(q, a);
        k1 = func_021B836C(q, b);
        d = func_021B82FC((u8 *)q);
        t = func_021B82F8((u8 *)q);
    } else {
        k0 = func_021B830C(q);
        k1 = func_021B830C(q);
        d = 1;
        t = 0;
    }
    x0 = k0[1];
    x = x0 + (k1[1] - x0) * t / d;
    y = k0[2] + (u32)func_0207C768((int)(FX_Mul(k1[2] - k0[2], t << 12)), (int)(d << 12));
    v.x = k0[3];
    v.y = k0[4];
    v.z = k0[5];
    func_021BA7E0(p, x, y, &v);
}









void func_021BA7B0(u8 *p)
{
    Cam *c;
    u16 ang;
    int r;
    VecFx32 pos;

    func_021B8220(p);
    c = func_021B830C();
    ang = c->ang;
    r = c->r;
    pos.x = c->pos.x;
    pos.y = c->pos.y;
    pos.z = c->pos.z;
    func_021BA7E0((u32)p, ang, r, &pos);
}









void func_021BA7E0(u32 p, u16 ang, int r, VecFx32 *pos)
{
    VecFx32 d;
    VecFx32 c;
    VecFx32 n;
    VecFx32 out;
    u32 h;
    int save;
    int i;
    int cr;

    h = func_021B821C((u8 *)p);
    func_0218E124((u8 *)h, 2);
    func_0218EC54((u8 *)h);
    c = *pos;
    save = c.y;
    c.y = 0;
    func_021B79D4((void **)p, &d);
    d.y = 0;
    func_0207CA00(&d, &c, &d);
    func_0207CCA4(&d, &n);
    i = (ang >> 4) * 2;
    out.y = FX_Mul(d_020A1B38[i], r);
    cr = FX_Mul(d_020A1B38[i + 1], r);
    out.x = FX_Mul(n.x, cr);
    out.z = FX_Mul(n.z, cr);
    out.x += c.x;
    out.y += save;
    out.z += c.z;
    func_0218EC90(h, (u32 *)pos);
    func_0218ECF4(h, &out);
}









void func_021BA8E0(u32 p)
{
    VecFx32 v;
    int *k;
    u32 q;
    int d;
    int t;
    u16 x;
    int y;

    q = func_021B8220((u8 *)p);
    func_021B82F0((u8 *)q);
    d = func_021B82FC((u8 *)q);
    t = func_021B82F8((u8 *)q);
    k = func_021B830C(q);
    x = k[1];
    y = k[2];
    v.x = k[3] + (u32)func_0207C768((int)(FX_Mul(k[6] - k[3], t << 12)), (int)(d << 12));
    v.y = k[4] + (u32)func_0207C768((int)(FX_Mul(k[7] - k[4], t << 12)), (int)(d << 12));
    v.z = k[5] + (u32)func_0207C768((int)(FX_Mul(k[8] - k[5], t << 12)), (int)(d << 12));
    func_021BA7E0(p, x, y, &v);
}








void func_021BA9B4(u8 *p)
{
    VecFx32 w;
    VecFx32 v;
    u8 *q;
    u32 o;
    int h;

    func_021B8220(p);
    q = func_021B830C();
    o = func_021B821C(p);
    func_0218E124((u8 *)o, 0);
    func_0218EC60(func_021B821C(p));
    func_021B79D4((void **)p, &v);
    v.y = 0;
    w.x = ((struct Obj07529 *)q)->fC;
    w.y = 0;
    w.z = ((struct Obj07529 *)q)->f10;
    func_0207CA00(&v, &w, &v);
    func_0207CCA4(&v, &v);
    h = func_0207CFB8(v.x, v.z);
    func_0218ED34((u8 *)o, ((struct Obj07529 *)q)->f4);
    func_0218ED58((u8 *)o, ((struct Obj07529 *)q)->f8);
    func_0218ED48((u8 *)o, h);
}








void func_021BAA30(u8 *p)
{
    s16 v[4];
    u8 *q;
    u32 a;
    u32 o;
    int h;

    a = func_021B8220(p);
    q = func_021B830C();
    o = func_021B821C(p);
    func_0218E124((u8 *)o, 0);
    func_0218EC60(func_021B821C(p));
    func_021B8050((struct Sub *)a, v);
    h = func_0207CFB8(-v[0], -v[2]);
    func_0218ED34((u8 *)o, ((struct Obj09638 *)q)->f8);
    func_0218ED58((u8 *)o, ((struct Obj09638 *)q)->fC);
    func_0218ED48((u8 *)o, (u16)(h + ((struct Obj09638 *)q)->f4));
}








void func_021BAA9C(u32 a)
{
    s16 b[6];
    u32 t, h;
    u32 *r;
    int x, y;

    t = func_021B8220((u8 *)a);
    r = func_021B830C(t);
    h = func_021B821C((u8 *)a);
    func_0218E124((u8 *)h, 0);
    func_0218EC60(func_021B821C((u8 *)a));
    func_021B8050((struct Sub *)t, &b[3]);
    x = func_0207CFB8(-b[3], -b[5]);
    b[0] = b[3];
    b[2] = b[5];
    b[1] = 0;
    y = func_0207CFB8(-b[4], func_0207CC30(b));
    func_0218ED34((u8 *)h, y + r[2]);
    func_0218ED58((u8 *)h, r[3]);
    func_0218ED48((u8 *)h, (u16)(x + r[1]));
}








void func_021BAB30(u32 a)
{
    s16 v[4];
    u32 loc[3];
    u32 t, h;
    u32 *r;
    int ang;

    t = func_021B8220((u8 *)a);
    r = func_021B830C(t);
    h = func_021B821C((u8 *)a);
    func_0218E124((u8 *)h, 0);
    func_0218EC54((u8 *)func_021B821C((u8 *)a));
    func_021B8050((struct Sub *)t, v);
    ang = func_0207CFB8(-v[0], -v[2]);
    func_0218ED34((u8 *)h, r[2]);
    func_0218ED58((u8 *)h, r[3]);
    func_0218ED48((u8 *)h, (u16)(ang + r[1]));
    func_021B8314((void *)t, loc);
    func_0218EC90(func_021B821C((u8 *)a), loc);
}








void func_021BABB4(void *p)
{
    void *a = (void *)func_021B8220(p);
    int b = func_021B82F0(a);
    int c = (int)func_021B833C(a);

    if (b == 1) {
        func_021BB014((u32)p, (unsigned char *)a, c);
    }
}








void func_021BABDC(void *p)
{
    void *a = (void *)func_021B8220(p);
    int b = func_021B82F0(a);
    int c = (int)func_021B834C(a);

    if (b == 1) {
        func_021BB014((u32)p, (unsigned char *)a, c);
    }
}








void func_021BAC04(u32 a)
{
    u32 loc[3];
    u32 s[3];
    u32 h;
    u32 *r;
    u16 x, y;
    u32 z;

    h = func_021B821C((u8 *)a);
    r = func_021B830C(func_021B8220((u8 *)a));
    func_0218E124((u8 *)h, 0);
    func_0218EC60(func_021B821C((u8 *)a));
    func_021B79D4((void **)a, loc);
    x = r[1];
    y = r[2];
    z = r[3];
    func_0218ED48((u8 *)h, y);
    func_0218ED34((u8 *)h, x);
    func_0218ED58((u8 *)h, z);
    s[0] = r[4];
    s[1] = r[5];
    s[2] = r[6];
    func_0218ECD4(h, s);
}






void func_021BAC74(u32 p)
{
    V_021BAC74 v;
    u32 h = func_021B821C((u8 *)p);

    func_021BAC04(p);
    func_0218EC54((u8 *)h);
    func_021B79D4((void **)p, &v);
    func_0218EC90(h, (u32 *)&v);
    func_0218F05C((unsigned char *)h);
}






/*
 * Keyframe lerp between two func_021B836C records: two wrapped 16-bit
 * angles (+4, +8), a scalar (+0xC) and a vector (+0x10..+0x18).  The
 * angle and scalar locals are int with explicit (u16) casts: as u16
 * locals the x0 load sinks below the k1 loads and every spill slot moves.
 * k1 is declared before k0 to put k0 in r5.
 *
 * Addresses are Black-image addresses.
 */
void func_021BACA8(u32 p)
{
    V_021BACA8 v;
    int *k1;
    int *k0;
    u32 q;
    u32 a;
    u32 b;
    u32 h;
    int s;
    int d;
    int t;
    int x0;
    int y0;
    int z0;
    int y1;
    int z1;
    int dx;
    int dy;
    u16 x;
    u16 y;

    q = func_021B8220((u8 *)p);
    a = (u32)func_021B833C((u8 *)q);
    b = (u32)func_021B834C((u8 *)q);
    h = func_021B821C((u8 *)p);
    func_0218E124((u8 *)h, 0);
    func_0218EC60(func_021B821C((u8 *)p));
    k0 = func_021B836C(q, a);
    k1 = func_021B836C(q, b);
    d = func_021B82FC((u8 *)q);
    t = func_021B82F8((u8 *)q);
    s = (u32)func_0207C768((int)(t << 12), (int)(d << 12));
    x0 = (u16)k0[1];
    y0 = (u16)k0[2];
    z0 = k0[3];
    y1 = (u16)k1[2];
    z1 = k1[3];
    dx = (u16)k1[1] - x0;
    if (dx >= 0x8000)
        dx -= 0x10000;
    else if (dx <= -0x8000)
        dx += 0x10000;
    x = x0 + (FX_Mul(dx << 12, s) >> 12);
    dy = y1 - y0;
    if (dy >= 0x8000)
        dy -= 0x10000;
    else if (dy <= -0x8000)
        dy += 0x10000;
    y = y0 + (FX_Mul(dy << 12, s) >> 12);
    func_0218ED48((u8 *)h, y);
    func_0218ED34((u8 *)h, x);
    func_0218ED58((u8 *)h, z0 + FX_Mul(z1 - z0, s));
    v.x = k0[4] + FX_Mul(k1[4] - k0[4], s);
    v.y = k0[5] + FX_Mul(k1[5] - k0[5], s);
    v.z = k0[6] + FX_Mul(k1[6] - k0[6], s);
    func_0218ECD4(h, (u32 *)&v);
}






/*
 * EXACT*: 406 bytes compiled against a 408-byte extent (trailing pad).
 * The result vector is written through the SDK's inline VEC_Set, whose
 * arguments are evaluated z, y, x before the three stores.
 *
 * Addresses are Black-image addresses.
 */
int func_021BAE7C(FieldNogridMapperWork2 *a, FieldNogridMapperWork2 *b, const VecFx32 *c, VecFx32 *out, fx32 *t, VecFx32 *axis)
{
    VecFx32 d1;
    VecFx32 d2;
    VecFx32 d1n;
    VecFx32 n1;
    VecFx32 n2;
    fx32 len1;
    fx32 len2;
    fx32 inv;
    fx32 s;
    fx32 dy;

    VEC_Subtract(&a->f30, &b->f30, &d1);
    VEC_Subtract(c, &b->f30, &d2);
    VEC_Normalize(&d1, &d1n);
    len1 = VEC_Mag(&d1);
    d1 = d1n;
    len2 = VEC_Mag(&d2);
    VEC_Normalize(&d2, &d2);
    inv = (fx32)FX_Div((int)len2, (int)len1);
    d2.x = FX_MUL(d2.x, inv);
    d2.y = FX_MUL(d2.y, inv);
    d2.z = FX_MUL(d2.z, inv);
    *t = VEC_DotProduct(&d1, &d2);
    if (*t > 0x1000) {
        return 0;
    }
    if (*t < 0) {
        return 0;
    }
    *t = FX_MUL(*t, len1);
    VEC_Normalize(&d1, &n1);
    VEC_Normalize(&d2, &n2);
    VEC_CrossProduct(&n1, &n2, axis);
    s = *t;
    VEC_Set(out, FX_MUL(d1n.x, s), FX_MUL(d1n.y, s), FX_MUL(d1n.z, s));
    VEC_Add((VecFx32 *)&b->f30, (VecFx32 *)out, (VecFx32 *)out);
    if (VEC_Distance(c, out) >= 0x100000) {
        return 0;
    }
    dy = c->y - out->y;
    if (dy < 0) {
        dy = -dy;
    }
    if (dy > 0x8000) {
        return 0;
    }
    return 1;
}







void func_021BB014(u32 a, unsigned char *b, u32 c)
{
    u32 loc[3];
    u32 x;
    u32 *r;
    u32 h;
    u32 k;

    k = (u32)func_021B833C(b);
    if (k == c)
        x = 0;
    else
        x = func_021B82FC((u8 *)b);
    func_021B8328((u32)b, x, loc);
    r = (u32 *)func_021B836C((u32)b, c);
    h = func_021B821C((u8 *)a);
    func_0218E124((u8 *)h, 0);
    func_0218EC54((u8 *)h);
    func_0218EC90(h, loc);
    func_0218ED34((u8 *)h, r[1]);
    func_0218ED48((u8 *)h, (u16)r[2]);
    func_0218ED58((u8 *)h, r[3]);
}







void *func_021BB088(int a)
{
    return func_02030734((u16)a, 0x10, 1, (const char *)&d_021DE2C4, 0x5C);
}







/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB0A4(u8 *p, u32 a1, u32 a2, u32 a3)
{
    func_021BB11C((u32 *)p);
    func_020307B0(p);
}






void func_021BB0B4(u32 *a, u32 b, u32 c)
{
    u32 i = 0;
    u32 off;

    a[0] = (u32)func_0204A298(0x4f, (u32)b, 0, (u16)c, &a[1]);
    a[2] = *(u32 *)a[0];
    a[3] = (u32)func_02030734((u16)c, a[2] * 4, 1, (const char *)&d_021DE2C4, 0x86);
    off = 4;
    for (i = 0; i < a[2]; i++) {
        u16 *q;

        ((u32 *)a[3])[i] = a[0] + off;
        q = (u16 *)((u32 *)a[3])[i];
        off += q[0] * q[1] * 4 + 4;
    }
}






void func_021BB11C(u32 *p)
{
    if (p[0] != 0) {
        func_020307B0((void *)p[3]);
        func_020307B0((void *)p[0]);
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;
    }
}






int func_021BB13C(char *a, char *b)
{
    int r = -1;
    if (((struct Obj07530 *)b)->f2 == 1) {
        unsigned idx = ((struct Obj07530 *)b)->f0;
        if (((struct Obj20092 *)a)->f8 > idx) {
            unsigned short *e = (*(unsigned short ***)(a + 0xc))[idx];
            unsigned w = e[0];
            int x = ((struct Obj07530 *)b)->f4 + (w >> 1);
            int y = ((struct Obj07530 *)b)->f6;
            if ((int)w > x && e[1] > y && x >= 0 && y >= 0)
                r = *(int *)((char *)e + (x + w * y) * 4 + 4);
        }
    }
    return r;
}






int func_021BB188(u16 a)
{
    if ((u16)(a + 0xFF60) <= 1) {
        return 1;
    }
    return 0;
}






int func_021BB1A0(int x)
{
    if (x == 163)
        return 1;
    return 0;
}






int func_021BB1AC(int x)
{
    if (x == 165)
        return 1;
    return 0;
}






int func_021BB1B8(int x)
{
    if (x == 164)
        return 1;
    return 0;
}







int func_021BB1C4(int x)
{
    if (x == 167)
        return 1;
    return 0;
}







int func_021BB1D0(int x)
{
    if (x == 166)
        return 1;
    return 0;
}







int func_021BB1DC(int x)
{
    if (x == 168)
        return 1;
    return 0;
}







int func_021BB1E8(int x)
{
    if (x == 176)
        return 1;
    return 0;
}







u32 *func_021BB1F4(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)func_02030734((u16)a, 0x18, 1, (const char *)&d_021DE2D0, 0x47);

    p[0] = (u32)func_021B7884(a, 0x30, b);
    p[1] = (u32)func_0219EF44(a);
    p[3] = c;
    p[4] = d;
    p[2] = (u32)func_021BB088(a);
    return p;
}







int func_021BB240(void *a, u32 b, u32 c, u32 d)
{
func_021BB0A4((u8 *)(((struct Obj09191 *)((u8 *)(a)))->f8), b, c, d);
func_021B791C((void **)(((struct Obj09191 *)((u8 *)(a)))->f0));
func_0219EF6C((u8 *)(((struct Obj09191 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}







void func_021BB260(FieldNogridMapperWork2 *p, int b)
{
    if (b != 0) {
        p->f14 = 0;
    } else {
        p->f14 = 1;
    }
    func_021AB75C(p->fC, b);
}







void func_021BB278(u32 *a, u16 *b, u32 c)
{
    func_021BB348((u32)a);
    if (b[0] != 0xFFFF) {
        u32 n = func_02049030(0x4f);

        func_0219EF7C((struct S *)a[1], b[0], c);
        func_021B7934(a[0], (u32)func_0219F018((u8 *)a[1]));
        func_021BB0B4((u32 *)a[2], b[0] + (n >> 1), c);
    }
    if (b[1] != 0xFFFF) {
        u32 t, u, v;

        func_021AB840(a[4], 0, b[1], c);
        t = func_021AB880((u8 *)a[4]);
        u = func_021AB884((u8 *)a[4]);
        v = func_021AB888(a[4]);
        func_021AB634(a[3], t, u, v);
    }
}







void func_021BB2F8(u32 a, u32 b, u32 c)
{
    int n = func_020490A8(0x6d, b);
    void *p = func_02030734((u16)(((u16)c & 0x7FFF) | 0x8000), n, 1, (const char *)&d_021DE2D0, 0xdd);

    func_02048F4C(p, 0x6d, b);
    func_021BB278((u32 *)a, p, c);
    func_020307B0(p);
}







void func_021BB348(u32 a)
{
func_021AB650(((struct Obj01663 *)((u8 *)(a)))->fC);
func_021B7954(((struct Obj01663 *)((u8 *)(a)))->f0);
func_0219EFFC(((struct Obj01663 *)((u8 *)(a)))->f4);
func_021AB868(((struct Obj01663 *)((u8 *)(a)))->f10);
func_021BB11C((u32 *)((struct Obj01663 *)((u8 *)(a)))->f8);
}







void func_021BB36C(Obj_021BB36C *p)
{
    func_021B79E4(p->f0);
    if (p->f14 == 0) {
        func_021B79F0(p->f0, 0);
    }
}






int func_021BB388(void **h) { return func_021B79F0(*h, 1); }







/*
 * Tail-call thunk: the object's word at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB394(u8 *p)
{
    func_021B7970(((struct Obj18166 *)p)->f0);
}







void func_021BB3A0(u8 *p, u32 a1)
{
    func_021B79AC(((struct Obj18167 *)p)->f0);
}







void func_021BB3AC(u8 *p, u32 b)
{
    func_021B79C4((u32 *)(((struct Obj18168 *)p)->f0), b);
}







void func_021BB3B8(u8 *p)
{
    func_021B79CC((u32 *)(((struct Obj18169 *)p)->f0));
}







u32 func_021BB3C4(u8 *p, char *a1)
{
    return func_021BB13C((char *)(((struct Obj18170 *)p)->f8), a1);
}






void func_021BB3D0(void **h, void *r) { func_021B7D68(*h, r); }







void func_021BB3DC(u32 *p, int b, int c)
{
    func_021B7C04((u8 *)(*p), b, c);
}






void func_021BB3E8(u32 *a, u32 b, u16 c, u16 d, u16 e, u32 f, u16 g)
{
    u16 id;
    u16 *p;
    u32 h;

    id = (g & 0x7FFF) | 0x8000;
    p = (u16 *)func_02030734(id, func_020490A8(0x6d, func_02013C9C(b)), 1, (const char *)&d_021DE2D0, 0x1c9);
    func_02048F4C(p, 0x6d, func_02013C9C(b));
    h = (u32)func_0219EF44(id);
    func_0219EF7C((struct S *)h, p[0], id);
    func_021B7C58(a[0], (u32)func_0219F018((u8 *)h), c, d, e, f);
    func_0219EF6C((u8 *)h);
    func_020307B0(p);
}






void *func_021BB480(void *p)
{
    return ((struct Obj18171 *)p)->f0;
}






Obj *func_021BB484(int a, int b)
{
    Obj *q = func_02030734(b, 0x38, 1, (const char *)&d_021DE2E8, 0x6F);

    q->f0 = a;
    func_021BB4BC((u32 *)q);
    return q;
}





void func_021BB4A8(u32 a, u8 *p)
{
    func_021BB504((Obj *)p);
    func_020307B0(p);
}





void func_021BB4BC(u32 *p)
{
    u32 h = func_021ABE24((u8 *)p[0]);
    int i;

    for (i = 0; i < 4; i++) {
        p[1 + i] = (u32)func_02046E24(h, d_021D9A6C[i]);
        func_02046FF8((int *)p[1 + i]);
        p[5 + i] = (u32)func_02047400((void *)p[1 + i], 0, (void *)p[1 + i]);
        p[9 + i] = (u32)func_0204767C(p[5 + i], 0, 0);
    }
    ((struct Obj02715 *)p)->f34 = 4;
}



void func_021BB504(Obj *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02047738(p->a24[i]);
        func_02047504(p->a14[i]);
        func_02046EFC(p->a4[i]);
    }
}



void func_021BB528(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[7];

    s[0] = c;
    s[1] = d;
    s[2] = func_021ABEA0(a, 4);
    s[3] = b;
    func_0216E1A4(b, (int)(&s[4]));
    s[6] = func_021ABE14((u8 *)a);
    if (d == 1)
        func_021BB778(c);
    func_021ABFA8(a, &d_021D9A7C, 0, 0, s, 0);
}
