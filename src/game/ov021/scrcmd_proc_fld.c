/*
 * file:     scrcmd_proc_fld.c
 * unit:     yes
 * function: func_021B3158, func_021B3258, func_021B331C, func_021B3350, func_021B3370, func_021B3470, func_021B34F4, func_021B3568, func_021B35A4, func_021B3834, func_021B385C, func_021B38E0, func_021B39C4, func_021B3A64, func_021B3B04, func_021B3B14, func_021B3B84, func_021B3BD8, func_021B3C58, func_021B3C78, func_021B3CFC, func_021B3D60, func_021B3DEC, func_021B3F00, func_021B3F3C, func_021B3FA0, func_021B40A8, func_021B40D4, func_021B41AC, func_021B4264, func_021B42D0, func_021B43EC, func_021B44CC, func_021B4510, func_021B45A0, func_021B468C, func_021B46FC, func_021B4710, func_021B4714, func_021B4804, func_021B4878, func_021B4894, func_021B4918, func_021B4984, func_021B49EC, func_021B4AA4, func_021B4BA4, func_021B4BEC, func_021B4C14, func_021B4C34, func_021B4C54, func_021B4C98, func_021B4CDC, func_021B4D14, func_021B4D60, func_021B4E58, func_021B4E9C, func_021B4EE0, func_021B4F1C, func_021B4F68, func_021B4FB0, func_021B5008, func_021B503C, func_021B5094, func_021B50D0, func_021B50F8, func_021B5128, func_021B5154, func_021B5190, func_021B51BC, func_021B52A4, func_021B52E0, func_021B52FC, func_021B536C, func_021B538C, func_021B53A4, func_021B53BC, func_021B542C, func_021B5498, func_021B54D4, func_021B54FC, func_021B5528, func_021B55C8, func_021B55F0, func_021B5610, func_021B5650, func_021B568C
 * address:  0x021B3158
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021B30C8  0x021B30C8  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021D9738     0x021D9738  data   ov021  a4
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0200C274  0x0200C274  thumb
 *   func_0200DABC  0x0200DABC  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0200823C  0x0200823C  thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020200CC 0x020200CC thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0200C29C  0x0200C29C  thumb
 *   func_0200DA98  0x0200DA98  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02020234  0x02020234  thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020310C4  0x020310C4  arm
 *   d_021D9440     0x021D9440  data   ov021  a4
 *   func_02021288  0x02021288  thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020212B0 0x020212B0 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201102C 0x0201102C thumb
 *   func_02045C04 0x02045C04 arm
 *   d_021D946C 0x021D946C data
 *   d_021D95DE 0x021D95DE data
 *   d_021DE1A8 0x021DE1A8 data
 *   d_021DE164     0x021DE164  data  a4
 *   d_021D9430     0x021D9430  data  a1
 *   func_02186670 0x02186670 thumb ov020
 *   func_0201F868  0x0201F868  thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020414EC 0x020414EC arm
 *   func_0204047C 0x0204047C arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021D96E0     0x021D96E0  data   ov021  a2
 *   d_021D96E8     0x021D96E8  data   ov021  a2
 *   d_021D96F0     0x021D96F0  data   ov021  a2
 *   d_021D96F8     0x021D96F8  data   ov021  a2
 *   d_021D9700     0x021D9700  data   ov021  a2
 *   func_0204B100  0x0204B100  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   d_021DE18C    0x021DE18C data ov021 a4
 *   d_021DE170    0x021DE170 data ov021 a4
 *   func_020450F0 0x020450F0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   d_021D945C    0x021D945C data a4
 *   func_0201F91C 0x0201F91C thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02020D0C 0x02020D0C thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_02007F68 0x02007F68 thumb
 *   func_020202FC 0x020202FC thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0202020C  0x0202020C  thumb
 *   func_0201EF6C  0x0201EF6C  thumb
 *   func_0201F14C  0x0201F14C  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   func_0203633C 0x0203633C arm
 *   func_02041300  0x02041300  arm
 *   d_021D9654     0x021D9654  data  a4
 *   func_02012138  0x02012138  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021896F4  0x021896F4  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CE4  0x02009CE4  thumb
 *   func_02009A34  0x02009A34  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
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
 *   d_021DE234     0x021DE234  data  a1
 *   d_021D98D0     0x021D98D0  data  a2
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218FA40  0x0218FA40  thumb  ov021
 *   func_021D2D50  0x021D2D50  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
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
#include "../../matched/include/Obj00037.h"
#include "../../matched/include/Obj09614.h"
#include "../../matched/include/Obj00030.h"
#include "../../matched/include/Obj00030.h"
#include "../../matched/include/Obj12842.h"
#include "../../matched/include/Obj05048.h"
#include "../../matched/include/Obj05049.h"
#include "../../matched/include/Obj19995.h"
#include "../../matched/include/Obj00037.h"
#include "../../matched/include/Obj12843.h"
#include "../../matched/include/Obj19996.h"
#include "../../matched/include/Obj03599.h"
#include "../../matched/include/Obj06037.h"
#include "../../matched/include/Obj02389.h"
#include "../../matched/include/Obj03132.h"
#include "../../matched/include/Obj00357.h"
#include "../../matched/include/Obj02711.h"
#include "../../matched/include/Obj12844.h"
#include "../../matched/include/Obj02712.h"
#include "../../matched/include/Obj07523.h"
#include "../../matched/include/Obj01502.h"
#include "../../matched/include/Obj02390.h"
#include "../../matched/include/Obj00810.h"
#include "../../matched/include/Obj19998.h"
#include "../../matched/include/Obj01503.h"
#include "../../matched/include/Obj01121.h"

struct Ctx;
struct MsgBank;
struct Blk1AC;
struct Blk34;
struct Cfg;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Rec;
struct Rec3;
struct Sub02008C20Obj;
struct Tcbl;
struct WordSet;
struct Slot;
struct U16Vec;
struct S02031140;
struct Sub0204A9D0;
struct Bank;
struct CharBuf;
struct Src;
struct Bmp;
struct StrObj;
struct Vec2;
struct Sub020097BCObj;
struct BigObj;
struct Pair;
struct Desc;
struct Big;
struct Blk37;
struct Sub02008700Obj;
struct ScriptVm;
struct Sub020090B0Obj;
struct Sub02009210Obj;
struct Blk38;
struct Stream;
struct Cursor;
struct Blk021D2D50;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Work_021B3158 {
    u8  state;
    u8  sub;
    u8  b2;
    u8  b3;
    u32 f04;
    u8  f08;
} Work_021B3158;

typedef struct Buf24 {
    u32 w[6];
} Buf24;

typedef signed int     s32;

typedef signed short   s16_021B3370;

typedef struct {
    u16 id;
    u16 pad;
    u32 val;
} Entry;

typedef struct {
    u8 _00[4];
    u16 heap;
    u8 _06[0x1a];
    Entry list[40];
    u16 count;
    u8 mode;
    u8 _163[0x1d];
    Entry *buf;
    u8 _184[4];
    u32 win;
} Obj;

typedef struct { u16 a, b, c; u8 d, e; } Rect_021B3158;

typedef short          s16_021B3D60;

typedef struct {
    u32 f0;
    u8  f4;
    u8  f5;
    u8  f6;
    u8  f7;
    u16 f8;
} WinTmpl;

typedef struct {
    void *arr;
    void *cb04;
    void *cb08;
    u32 w0c;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

typedef struct {
    u16 id;
    u16 pad;
    u32 v;
} Ent_021B3158;

typedef signed short   s16_021B4710;

typedef signed short   s16_021B4878;

typedef signed char    s8;

typedef short s16_021B4894;

typedef signed short   s16;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
} Rect_021B4878;

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
} Work_021B4878;

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
} Ent_021B4878;

typedef struct {
    u8  pad0[5];
    u8  hasA;
    u8  hasB;
    u8  pad7[0xc0 - 7];
    Ent_021B4878 a[5];
    Ent_021B4878 b[5];
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

extern void *func_0215A5F4(void *p);
extern void *func_02158FB4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *a);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021B30C8(u32 *p, u32 b, void *h);
extern int func_0218FE50(u8 *a);
extern void func_02193060(u32 a);
extern void func_0218F9C4(u8 *p, u8 *src, u16 v);
extern int func_0218EC60(u32 a);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218F878(u8 *a);
extern u32 func_020307B0(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02012F08(int *p);
extern int func_0200C258(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0200C274(struct Blk34 *p);
extern u16 func_0200DABC(struct Blk1AC *p);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_0200823C(u32 a);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *);
extern void func_020061E4(u32 a);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern void func_0200DA98(struct Blk1AC *p, u16 v);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02041B6C(u32 a);
extern void func_02020234(u8 *p);
extern u32 func_0201FDA0(const void *a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_0201FEBC(u8 *p);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_02021288(u32 id);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_020212B0(u32 a);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201F81C(int, int);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern u32 func_0201102C(u32 v);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id);
extern u32 func_0201F868(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_020414EC(u32 i);
extern void func_0204047C(int idx, unsigned short val);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern unsigned func_02020E60(unsigned a, unsigned b);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204ADEC(u32 a, u32 b, u32 c);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, unsigned int);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201C7D0(void *x, s16_021B3D60 y, s16_021B3D60 z, void *s, void *w, u16 v);
extern u32 func_0201C440(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_0201F91C(struct Slot *s);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02020D0C(u8 *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16_021B4710 a1, s16_021B4710 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern unsigned int func_0203633C(void);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012138(const struct Ctx *p);
extern int func_021896F4(void *p);
extern u32 func_02009CE4(struct Sub020097BCObj *obj);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_0215A5E4(void *a0);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void func_0215897C(void *a, void *b);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int func_02154C20(int x, struct Pair *p);
extern int func_021542C0(int x, struct Pair *p);
extern void *func_02154694(void *p, int a);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void func_0200BB58(u8 *a0, u8 *a1);
extern u32 func_02159B10(void *c, void *vm);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_0201293C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
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
extern u32 func_02159168(u32);
extern u32 func_02188C5C(u8 *p);
extern u32 func_02188CFC(u8 *p);
extern int func_0218F0F8(u8 *a);
extern u32 func_021BB260(u32, u32);
extern void func_02159144(int n);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0218F818(u8 *a);
extern void func_0218EC54(u8 *p);
extern u16 func_02011330(struct Stream *s);
extern u32 func_0201134C(struct Cursor *p);
extern void func_0218F900(u8 *a, void *p, int n);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0218FA40(u8 *p, u16 v);
extern void *func_021D2D50(void *a, struct Blk021D2D50 *src);
extern void *func_020124E4(struct Obj *p);
extern void *func_021F36C0(void *a, u8 *b, u32 c);
extern u32 func_021F36C8(u32 idx);
extern void func_0218E17C(u32 *p, u32 v);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
int func_021B3158(u32 a, u32 b);
void func_021B3258(int ctx, u8 *a, int b, int c);
void func_021B331C(u8 *w, int b);
u32 func_021B3350(u8 *w);
void func_021B3370(char *w);
void func_021B3470(char *p);
u8 func_021B34F4(u8 *p);
void func_021B3568(u8 *w, u32 b);
int func_021B35A4(u32 a, char *p, u32 c, u8 d);
u32 func_021B3834(u8 *p, int n);
void func_021B385C(char *p, int idx, int mode, int val, int arg);
void func_021B38E0(char *p, int a, int b, int c);
void func_021B39C4(Obj *p, int idx);
void func_021B3A64(char *p, int i);
void func_021B3B04(char *w);
int func_021B3B14(char *p, int a);
void func_021B3B84(char *p);
void func_021B3BD8(char *p);
void func_021B3C58(u8 *w);
void func_021B3C78(char *p);
void func_021B3CFC(char *w);
void func_021B3D60(char *w, u32 b);
void func_021B3DEC(char *w);
void func_021B3F00(u8 *w);
void func_021B3F3C(char *w);
void func_021B3FA0(char *w);
void func_021B40A8(u8 *w);
void func_021B40D4(char *w);
void func_021B41AC(char *w, u16 b);
void func_021B4264(char *w, u32 b);
void func_021B42D0(char *w, u32 a, u32 b);
void func_021B43EC(char *w);
void func_021B44CC(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g);
void func_021B4510(u8 *p, int a, u8 b);
void func_021B45A0(u32 ctx, int a, u8 b);
void func_021B468C(u32 a, u32 idx);
void func_021B46FC(u8 *w);
int func_021B4710(void);
void func_021B4714(u8 *p, u32 sel, u32 c, u32 d);
void func_021B4804(char *w, u32 a);
void func_021B4878(u32 a);
void func_021B4894(char *w, u32 b);
void func_021B4918(char *w, u32 a, u16 b, u32 c, u16 d);
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
void func_021B4D14(volatile Work_021B4878 *w);
int func_021B4D60(Work021B4D60 *c, void *vm);
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
extern const Buf24 d_021D9738;
extern const u8 d_021D9440[];
extern u8 d_021D946C[];
extern u8 d_021D95DE[];
extern u16 *d_021DE1A8[];
extern Entry *d_021DE164[];
extern u8 d_021D9430[];
extern const Rect_021B3158 d_021D96E0;
extern const Rect_021B3158 d_021D96E8;
extern const Rect_021B3158 d_021D96F0;
extern const Rect_021B3158 d_021D96F8;
extern const Rect_021B3158 d_021D9700;
extern WinTmpl *d_021DE18C[];
extern WinTmpl *d_021DE170[];
extern u32 d_021D945C[];
extern const Rect_021B4878 d_021D9654[];
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






/*
 * Task callback armed by func_021B2FD8; steps the 0x214-byte work block it
 * allocated.
 *
 * Addresses are Black-image addresses.
 */
int func_021B3158(u32 a, u32 b)
{
    Work_021B3158 **slot;
    Work_021B3158 *w;
    void *t;
    void *x;
    void *h;
    Buf24 buf;

    slot = func_02158FB4(func_0215A5F4((void *)b));
    w = *slot;
    t = func_0215A5DC((void *)b);
    x = func_0201210C((void *)t);
    h = func_02188C58(x);
    switch (w->state) {
    case 0:
        func_0218F0A8(h);
        w->state++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0) {
            w->state++;
        }
        break;
    case 2:
        func_021B30C8((u32 *)w, (u32)x, h);
        w->state++;
        break;
    case 3:
        if (func_0218FE50(h) == 0) {
            w->state++;
            w->f08 = 0;
            func_02193060(0);
        }
        break;
    case 4:
        if (func_021B35A4((u32)t, (char *)(&w->f08), w->b2, w->b3)) {
            w->state++;
        }
        break;
    case 5:
        buf = d_021D9738;
        func_0218F9C4(h, (u8 *)(&buf), 8);
        w->state++;
        w->sub = 0;
        break;
    case 6:
        if (func_0218FE50(h) == 0) {
            func_0218EC60((u32)h);
            func_0218F1AC(h, w->f04);
            func_0218F05C(h);
            func_0218F878(h);
            func_02193060(1);
            w->state++;
        }
        break;
    case 7:
        func_020307B0(*slot);
        return 1;
    }
    return 0;
}






void func_021B3258(int ctx, u8 *a, int b, int c)
{
    void *t = func_020120F4((void *)ctx);
    int r;

    func_02012944(t);
    a[354] = 0;
    b = func_021B3B14((char *)a, b);
    r = b;
    switch (r) {
    case 255:
        func_02012F08(t);
        func_021B38E0((char *)a, r, c, func_0200C258());
        break;
    case 254:
        func_021B39C4((Obj *)a, 0);
        a[355] = 1;
        break;
    case 253:
        a[355] = 1;
        a[354] = 1;
        func_021B39C4((Obj *)a, 1);
        break;
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
        func_021B3A64((char *)a, r);
        break;
    default:
        func_021B38E0((char *)a, r, c, 0);
        break;
    }
    func_021B331C(a, a[355]);
    func_021B3BD8((char *)a);
    func_021B3FA0((char *)a);
    func_021B3F00(a);
    func_021B40D4((char *)a);
    func_021B43EC((char *)a);
}





void func_021B331C(u8 *w, int b)
{
    if (b == 1) {
        ((struct Obj00037 *)w)->f194 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0xd);
    } else {
        ((struct Obj00037 *)w)->f194 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0xc);
    }
    ((struct Obj00037 *)w)->f1A0 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0xe);
}




u32 func_021B3350(u8 *w)
{
    if (w[0x163] == 0) {
        return func_0200C274((struct Blk34 *)(((struct Obj09614 *)w)->fC));
    } else {
        return func_0200DABC((struct Blk1AC *)(((struct Obj09614 *)w)->f18));
    }
}








void func_021B3370(char *w)
{
    u32 n;
    u32 k;
    u32 lim;

    n = func_021B3350((u8 *)w);
    k = func_02007FB8((u8 *)(((struct Obj00030 *)w)->f10), ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f4);
    if (func_02007E3C((u8 *)(((struct Obj00030 *)w)->f10), ((struct Obj00030 *)w)->f1FC, 1, ((struct Obj00030 *)w)->f4) == 0) {
        func_021B4714((u8 *)w, 10, ((struct Obj00030 *)w)->f1FC, 0);
        w[0] = 10;
        w[1] = 4;
        return;
    }
    lim = ((struct Obj00030 *)w)->f200;
    if (n < lim) {
        if (((struct Obj00030 *)w)->f163 == 0) {
            func_021B4714((u8 *)w, 3, ((struct Obj00030 *)w)->f1FC, 0);
        } else {
            func_021B4714((u8 *)w, 0x10, ((struct Obj00030 *)w)->f1FC, 0);
        }
        w[0] = 10;
        w[1] = 4;
    } else if (n >= lim && n < lim * 2) {
        func_021B4804(w, ((struct Obj00030 *)w)->f162);
        w[0] = 10;
        w[1] = 5;
    } else if (((struct Obj00030 *)w)->f162 == 0) {
        func_021B4714((u8 *)w, 4, ((struct Obj00030 *)w)->f1FC, 0);
        w[0] = 10;
        w[1] = 2;
        ((struct Obj00030 *)w)->f204 = n / ((struct Obj00030 *)w)->f200;
        if (((struct Obj00030 *)w)->f204 > 99) {
            ((struct Obj00030 *)w)->f204 = 99;
        }
        if (((struct Obj00030 *)w)->f204 + k > func_0200823C(((struct Obj00030 *)w)->f1FC)) {
            ((struct Obj00030 *)w)->f204 = func_0200823C(((struct Obj00030 *)w)->f1FC) - k;
        }
    } else {
        func_021B4804(w, ((struct Obj00030 *)w)->f162);
        w[0] = 10;
        w[1] = 6;
    }
}









void func_021B3470(char *p)
{
    void *q;
    int r;
    char *e;

    if (func_0201C6B4(((struct Obj00030 *)p)->f1B0) == 0) {
        return;
    }
    if (((struct Obj00030 *)p)->f20A == 0) {
        q = ((struct Obj00030 *)p)->f16C;
        func_02045334(q);
        func_02045374(q);
        func_020409B4(func_02045730(q));
        ((struct Obj00030 *)p)->f20A = ((struct Obj00030 *)p)->f20A + 1;
    }
    r = func_020200CC(((struct Obj00030 *)p)->f1A4);
    if (r == -1) {
        return;
    }
    if (r == -2) {
        *p = 11;
        return;
    }
    e = p + r * 8;
    ((struct Obj00030 *)p)->f1FC = ((struct Obj12842 *)e)->f20;
    *(int *)&((struct Obj00030 *)p)->f200 = ((struct Obj12842 *)e)->f24;
    ((struct Obj00030 *)p)->f208 = 1;
    func_021B3370(p);
}









u8 func_021B34F4(u8 *p)
{
    int r = func_0201CE30(((struct Obj05048 *)p)->f1B8);

    if (r == 2) {
        func_0201CE48(((struct Obj05048 *)p)->f1B8);
        return p[1];
    }
    if (r == 0) {
        if ((func_0203630C() & 1) || (func_0203630C() & 2)) {
            func_0201CE5C(((struct Obj05048 *)p)->f1B8, 0);
        }
    } else if (r == 1) {
        if ((func_020362DC() & 1) || (func_020362DC() & 2)) {
            func_0201CE38(((struct Obj05048 *)p)->f1B8);
            func_020061E4(1351);
        }
    }
    return p[0];
}









void func_021B3568(u8 *w, u32 b)
{
    if (w[0x163] == 0) {
        func_0200C29C((struct Blk34 *)(((struct Obj05049 *)w)->fC), b);
        func_02008DAC((struct Sub02008C20Obj *)(((struct Obj05049 *)w)->f14), 0x16, b);
    } else {
        func_0200DA98((struct Blk1AC *)(((struct Obj05049 *)w)->f18), b);
        func_02008DAC((struct Sub02008C20Obj *)(((struct Obj05049 *)w)->f14), 0x22, b);
    }
    func_02008DF0((struct Sub02008C20Obj *)(((struct Obj05049 *)w)->f14), 0x15);
}









/*
 * Addresses are Black-image addresses.
 */
int func_021B35A4(u32 a, char *p, u32 c, u8 d)
{
    int r;
    u32 q;

    switch (((struct Obj00030 *)p)->f0) {
    case 0:
        func_021B3258(a, (u8 *)p, c, d);
        (((struct Obj00030 *)p)->f0)++;
        break;
    case 1:
        func_021B3470(p);
        break;
    case 2:
        func_021B41AC(p, ((struct Obj00030 *)p)->f1FC);
        func_021B42D0(p, ((struct Obj00030 *)p)->f208, ((struct Obj00030 *)p)->f200);
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 1);
        ((struct Obj00030 *)p)->f0 = 3;
        break;
    case 3:
        ((struct Obj00030 *)p)->f0 = func_021B4AA4(p);
        break;
    case 4:
        func_021B4BA4(0);
        func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_02045374((struct Cfg *)(((struct Obj00030 *)p)->f178));
        func_02041B6C(1);
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        func_02020234((u8 *)(*(u32 *)&((struct Obj00030 *)p)->f1A4));
        ((struct Obj00030 *)p)->f0 = 1;
        break;
    case 5:
        func_021B4BA4(1);
        func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        ((struct Obj00030 *)p)->f184 = func_0201FDA0(d_021D9440, 1, 9, 0, ((struct Obj00030 *)p)->f4);
        if (((struct Obj00030 *)p)->f162 != 1) {
            func_021B41AC(p, ((struct Obj00030 *)p)->f1FC);
        }
        ((struct Obj00030 *)p)->f0 = 7;
        break;
    case 6:
        func_021B4BA4(1);
        func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        ((struct Obj00030 *)p)->f184 = func_0201FDA0(d_021D9440, 1, 9, 0, ((struct Obj00030 *)p)->f4);
        ((struct Obj00030 *)p)->f0 = 7;
        break;
    case 7:
        r = func_0201FEBC((u8 *)(((struct Obj00030 *)p)->f184));
        if (r == -1) {
        } else if (r == 0) {
            ((struct Obj00030 *)p)->f0 = 8;
            func_021B4BA4(1);
            func_02020234((u8 *)(*(u32 *)&((struct Obj00030 *)p)->f1A4));
            func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
            func_02041B6C(1);
        } else if (r == -2) {
            ((struct Obj00030 *)p)->f0 = 4;
        }
        break;
    case 8:
        func_020061E4(0x655);
        func_021B4714((u8 *)p, 9, ((struct Obj00030 *)p)->f1FC, *(s16_021B3370 *)&((struct Obj00030 *)p)->f208 > 1);
        func_021B3568((u8 *)p, ((struct Obj00030 *)p)->f200 * *(s16_021B3370 *)&((struct Obj00030 *)p)->f208);
        func_021B40D4(p);
        func_02007E50((u8 *)(((struct Obj00030 *)p)->f10), ((struct Obj00030 *)p)->f1FC, ((struct Obj00030 *)p)->f208, ((struct Obj00030 *)p)->f4);
        ((struct Obj00030 *)p)->f0 = 10;
        *(u8 *)&((struct Obj00030 *)p)->f1 = 9;
        break;
    case 9:
        if (((struct Obj00030 *)p)->f1FC == 4 && *(s16_021B3370 *)&((struct Obj00030 *)p)->f208 >= 10) {
            func_021B4714((u8 *)p, 15, ((struct Obj00030 *)p)->f1FC, *(s16_021B3370 *)&((struct Obj00030 *)p)->f208 > 1);
            func_02007E50((u8 *)(((struct Obj00030 *)p)->f10), 12, 1, ((struct Obj00030 *)p)->f4);
            func_02008DF0((struct Sub02008C20Obj *)(((struct Obj00030 *)p)->f14), 0x1F);
            ((struct Obj00030 *)p)->f0 = 10;
            *(u8 *)&((struct Obj00030 *)p)->f1 = 4;
        } else {
            ((struct Obj00030 *)p)->f0 = 4;
        }
        break;
    case 10:
        ((struct Obj00030 *)p)->f0 = func_021B34F4((u8 *)p);
        break;
    case 11:
        func_021B46FC((u8 *)p);
        func_021B3F3C(p);
        func_021B40A8((u8 *)p);
        func_021B3C58((u8 *)p);
        func_021B3B04(p);
        func_021B3B84(p);
        return 1;
    }
    func_0201C4E4((struct PrintSys *)(*(u32 *)&((struct Obj00030 *)p)->f1B0));
    q = *(u32 *)&((struct Obj00030 *)p)->f1B0;
    if (((struct Obj00030 *)p)->f1AC != 0 && func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00030 *)p)->f1A8))) == 0) {
        func_02045334((struct Descriptor *)((struct Obj00030 *)p)->f1A8);
        ((struct Obj00030 *)p)->f1AC = 0;
    }
    func_020310C4((struct Tcbl *)(((struct Obj00030 *)p)->f1B4));
    func_020310C4((struct Tcbl *)(((struct Obj00030 *)p)->f1B4));
    return 0;
}









u32 func_021B3834(u8 *p, int n)
{
    u32 r = func_02021288(((struct Obj19995 *)p)->f0);
    int i;

    for (i = 0; i < n; i++) {
        func_02021288(*(u16 *)(p + i * 8));
    }
    return r;
}








void func_021B385C(char *p, int idx, int mode, int val, int arg)
{
    if (mode == 1) {
        func_0201EFA4(((struct Obj00037 *)p)->f190, 0, val - 327, 2, 2, 1);
        func_0201EF34(((struct Obj00037 *)p)->f190, 1, func_020212B0((u16)val));
        func_0201F250(((struct Obj00037 *)p)->f190, ((struct Obj00037 *)p)->f198, ((struct Obj00037 *)p)->f19C);
        func_0201F898((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), (u32)(((struct Obj00037 *)p)->f198), idx, ((struct Obj00037 *)p)->f4);
    } else {
        func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), arg, val, idx, ((struct Obj00037 *)p)->f4);
    }
}








/*
 * Spill slots: the image puts the idx*4 offset at sp+4, q at sp+8, n at sp+0xc.
 * A single-def offset local is folded into a compiler temporary, and temps
 * take slots above every spilled local; the second (redundant) assignment in
 * the flag arm keeps off a real local, and declaration order (n, q, ..., off;
 * last declared lowest) gives the image layout.
 */
void func_021B38E0(char *p, int a, int b, int c)
{
    int n;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);
    int idx;
    int k;
    int v;
    char *e;
    int off;

    if (a == 0xff) {
        idx = d_021D946C[c];
    } else {
        idx = b + 6;
    }
    off = idx * 4;
    if (func_02021288(**(u16 **)((char *)d_021DE1A8 + off))) {
        ((struct Obj00037 *)p)->f162 = 1;
        off = idx * 4;
    }
    n = d_021D95DE[idx];
    ((struct Obj00037 *)p)->f180 = func_0201F81C(n + 1, ((struct Obj00037 *)p)->f4);
    for (k = 0; k < n; k++) {
        v = (*(u16 **)((char *)d_021DE1A8 + off))[k];
        func_021B385C(p, k, ((struct Obj00037 *)p)->f162, v, (int)q);
        e = p + k * 8;
        ((struct Obj12843 *)e)->f20 = v;
        ((struct Obj12843 *)e)->f24 = func_0201102C(func_02020FE4((void *)v, 0, ((struct Obj00037 *)p)->f4));
    }
    ((struct Obj00037 *)p)->f160 = k;
    func_021B3834((u8 *)(p + 32), ((struct Obj00037 *)p)->f160);
    func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    func_02045C04(q);
}








void func_021B39C4(Obj *p, int idx)
{
    int i;
    Entry *tbl;
    u32 h;
    int n;

    i = 0;
    h = (u32)func_02045B38(0, 2, 0x36, p->heap);
    tbl = d_021DE164[idx];
    n = d_021D9430[idx];
    p->buf = func_0201F81C(n + 1, p->heap);
    for (; i < n; i++) {
        func_021B385C((char *)p, i, p->mode, tbl[i].id, h);
        p->list[i].id = tbl[i].id;
        p->list[i].val = tbl[i].val;
    }
    p->count = i;
    func_0201F878((struct Slot *)(p->buf + i), p->win, 0xb, -2, p->heap);
    func_02045C04((struct Rec *)h);
}








void func_021B3A64(char *p, int i)
{
    int k = 0;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);

    func_02186670(((struct Obj00037 *)p)->f1C, p + 32, (u16 *)(p + 352), i - 247, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f180 = func_0201F81C(((struct Obj00037 *)p)->f160 + 1, ((struct Obj00037 *)p)->f4);
    for (; k < ((struct Obj00037 *)p)->f160; k++) {
        func_021B385C(p, k, ((struct Obj00037 *)p)->f162, *(u16 *)(p + 32 + k * 8), (int)q);
    }
    func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    func_02045C04(q);
}








/*
 * Unlabelled leaf (tail-call stub), called from func_021B35A4.
 *
 * Addresses are Black-image addresses.
 */
void func_021B3B04(char *w)
{
    func_0201F868(((struct Obj19996 *)w)->f180);
}








int func_021B3B14(char *p, int a)
{
    ((struct Obj00037 *)p)->f188 = func_02045B38(0, 3, 423, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f18C = func_02045B38(0, 2, 53, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f190 = func_0201EC64(((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f198 = func_020457B0(200, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f1B4 = func_0203101C(((struct Obj00037 *)p)->f4, ((struct Obj00037 *)p)->f4, 32, 32);
    ((struct Obj00037 *)p)->f19C = func_02045EC0(((struct Obj00037 *)p)->f188, 29);
    return a;
}








void func_021B3B84(char *p)
{
    func_02031140(((struct Obj03599 *)p)->f1B4);
    func_0201ED04(((struct Obj03599 *)p)->f190);
    func_02045808(((struct Obj03599 *)p)->f19C);
    func_02045808(((struct Obj03599 *)p)->f198);
    func_02045808(((struct Obj03599 *)p)->f1A0);
    func_02045808(((struct Obj03599 *)p)->f194);
    func_02045C04(((struct Obj03599 *)p)->f188);
    func_02045C04(((struct Obj03599 *)p)->f18C);
}








void func_021B3BD8(char *p)
{
    void *q;

    *(volatile u16 *)0x04000050 = 0;
    q = func_020490F4(54, ((struct Obj06037 *)p)->f4);
    func_02049B68(q, 1, 0, 0, 96, ((struct Obj06037 *)p)->f4);
    func_02049658(q, 0, 2, 100, 0, 0, ((struct Obj06037 *)p)->f4);
    func_02049990(q, 2, 2, 0, 100, 0, 0, ((struct Obj06037 *)p)->f4);
    func_02049238(q);
    func_0201F5BC(1, 228, 9, 0, ((struct Obj06037 *)p)->f4);
    func_020414EC(1);
    func_0204047C(2, 1);
}








void func_021B3C58(u8 *w)
{
    func_020414EC(1);
    func_020414EC(2);
    func_0204047C(2, 0);
    func_02193060(1);
}








void func_021B3C78(char *p)
{
    void *q = func_020490F4(54, ((struct Obj02389 *)p)->f4);

    ((struct Obj02389 *)p)->f1D4 = (void *)func_0204AC18(q, 10, 0, 0, 0, 1, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1D8 = (void *)func_0204A6C8(q, 7, 0, 0, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1E4 = (void *)func_0204A6C8(q, 4, 0, 0, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1DC = (void *)func_0204AF28(q, 8, 9, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1E8 = (void *)func_0204AF28(q, 5, 6, ((struct Obj02389 *)p)->f4);
    func_02049238(q);
}








void func_021B3CFC(char *w)
{
    ((struct Obj00037 *)w)->f1EC = (void *)func_0204AC18(((struct Obj00037 *)w)->f1F8, func_02020E60(1, 2), 0, 0x20, 0, 1, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F0 = (void *)func_0204A6C8(((struct Obj00037 *)w)->f1F8, func_02020E60(1, 1), 0, 0, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F4 = (void *)func_0204AF28(((struct Obj00037 *)w)->f1F8, 1, 0, ((struct Obj00037 *)w)->f4);
}







void func_021B3D60(char *w, u32 b)
{
    u32 y;
    u32 x;
    u32 p;
    u32 q;

    if (b <= 0x272) {
        p = (u32)func_02049F78((void *)(((struct Obj03132 *)w)->f1F8), func_02020E60(b, 2), (u32)(&x), ((struct Obj03132 *)w)->f4);
        q = (u32)func_02049E74((void *)(((struct Obj03132 *)w)->f1F8), func_02020E60(b, 1), 0, (u32)(&y), ((struct Obj03132 *)w)->f4);
        func_0204ADEC(((struct Obj03132 *)w)->f1EC, x, 1);
        func_0204A9D0(((struct Obj03132 *)w)->f1F0, (struct Sub0204A9D0 *)y);
        func_020307B0((void *)p);
        func_020307B0((void *)q);
        func_0204B3DC((struct Obj *)((struct Obj03132 *)w)->f1D0, 1);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj03132 *)w)->f1D0, 0);
    }
}







void func_021B3DEC(char *w)
{
    ((struct Obj00357 *)w)->f1C0 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1D8, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1DC, &d_021D96E0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C4 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96E8, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C8 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1CC = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F8, 0, ((struct Obj00357 *)w)->f4);
    func_0204B92C((struct Obj *)((struct Obj00357 *)w)->f1CC, 1);
    ((struct Obj00357 *)w)->f1D0 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1F0, ((struct Obj00357 *)w)->f1EC,
                                        ((struct Obj00357 *)w)->f1F4, &d_021D9700, 0, ((struct Obj00357 *)w)->f4);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1C4, 0);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1C8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1CC, 0);
}







void func_021B3F00(u8 *w)
{
    ((struct Obj00037 *)w)->f1BC = (u32)func_0204B100(5, 1, ((struct Obj00037 *)w)->f4);
    func_0204B22C((struct Bank *)(((struct Obj00037 *)w)->f1BC), 1);
    func_021B3C78((char *)w);
    ((struct Obj00037 *)w)->f1F8 = func_020490F4(0x19, ((struct Obj00037 *)w)->f4);
    func_021B3CFC((char *)w);
    func_021B3DEC((char *)w);
}







void func_021B3F3C(char *w)
{
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1F4));
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1E8));
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1DC));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1F0));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1E4));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1D8));
    func_0204ADA4((u32)(((struct Obj02711 *)w)->f1EC));
    func_0204ADA4((u32)(((struct Obj02711 *)w)->f1D4));
    func_02049238(((struct Obj02711 *)w)->f1F8);
    func_0204B1CC(((struct Obj02711 *)w)->f1BC);
}







void func_021B3FA0(char *w)
{
    WinTmpl **tbl;
    WinTmpl *e;
    int i;
    u32 t;
    u32 bg;

    tbl = d_021DE18C;
    if (((struct Obj00037 *)w)->f163 != 1) {
        tbl = d_021DE170;
    }
    for (i = 0; i < 7; i++) {
        e = tbl[i];
        ((u32 *)(w + 0x164))[i] = func_020450F0((u8)e->f0, e->f4, e->f5, e->f6, e->f7, (u8)e->f8, 1);
    }
    t = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x14);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)((struct Obj00037 *)w)->f164)), 0, 0, (void *)t, (void *)(((struct Obj00037 *)w)->f8), 0x3C4F);
    func_02045808((struct U16Vec *)t);
    ((struct Obj00037 *)w)->f1A8 = ((struct Obj00037 *)w)->f16C;
    ((struct Obj00037 *)w)->f1AC = 0;
    ((struct Obj00037 *)w)->f1B0 = func_0201C440((void *)(((struct Obj00037 *)w)->f4));
    if (((struct Obj00037 *)w)->f163 == 1) {
        bg = ((struct Obj00037 *)w)->f168;
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_020409B4(func_02045730((struct Descriptor *)bg));
    } else {
        bg = ((struct Obj00037 *)w)->f164;
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_020409B4(func_02045730((struct Descriptor *)bg));
        bg = ((struct Obj00037 *)w)->f168;
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_020409B4(func_02045730((struct Descriptor *)bg));
    }
}







void func_021B40A8(u8 *w)
{
    int i;

    func_0201C6EC((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    func_0201C4C0((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    for (i = 0; i < 7; i++) {
        func_020452E8((struct Descriptor *)(*(u32 *)(w + 0x164 + i * 4)));
    }
}







void func_021B40D4(char *w)
{
    u32 t7, t6, s, bg;

    if (((struct Obj00037 *)w)->f163 == 1) {
        t7 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x16);
        t6 = (u32)func_020457B0(10, ((struct Obj00037 *)w)->f4);
        func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), 0, func_0200DABC((struct Blk1AC *)(((struct Obj00037 *)w)->f18)), 4, 1, 1);
    } else {
        t7 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x15);
        t6 = (u32)func_020457B0(10, ((struct Obj00037 *)w)->f4);
        func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), 0, func_0200C274((struct Blk34 *)(((struct Obj00037 *)w)->fC)), 7, 1, 1);
    }
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), (void *)t6, (void *)t7);
    s = (u32)func_02045770((struct Descriptor *)((struct Obj00037 *)w)->f168);
    func_02043B5C((struct CharBuf *)s, 0);
    func_0201C7D0((void *)s, 0, 0, (void *)t6, (void *)(((struct Obj00037 *)w)->f8), 0x3C4F);
    bg = ((struct Obj00037 *)w)->f168;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
    func_02045808((struct U16Vec *)t6);
    func_02045808((struct U16Vec *)t7);
}







/*
 * The spilled second parameter is a u16 (func_021B3370 passes a u16 field
 * to func_02007FB8 in the same slot): as u32 its entry spill
 * `str r1, [sp, #8]` lands after the `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B41AC(char *w, u16 b)
{
    u32 t7, t6, s, bg;

    t7 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj02712 *)w)->f188), 0x17);
    t6 = (u32)func_020457B0(0x14, ((struct Obj02712 *)w)->f4);
    func_0201F73C((void *)(((struct Obj02712 *)w)->f170), 2, 0xE4, 9);
    func_0201EFA4((struct WordSet *)(((struct Obj02712 *)w)->f190), 0, func_02007FB8((u8 *)(((struct Obj02712 *)w)->f10), b, ((struct Obj02712 *)w)->f4), 3, 0, 1);
    func_0201F250((struct WordSet *)(((struct Obj02712 *)w)->f190), (void *)t6, (void *)t7);
    s = (u32)func_02045770((struct Descriptor *)((struct Obj02712 *)w)->f170);
    func_02043B5C((struct CharBuf *)s, 0xF);
    func_0201C7D0((void *)s, 0, 0, (void *)t6, (void *)(((struct Obj02712 *)w)->f8), 0x44F);
    bg = ((struct Obj02712 *)w)->f170;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
    func_02045808((struct U16Vec *)t6);
    func_02045808((struct U16Vec *)t7);
}







void func_021B4264(char *w, u32 b)
{
    u32 win;
    u32 t;
    u32 bg;

    win = (u32)func_02045770((struct Descriptor *)((struct Obj07523 *)w)->f178);
    func_02043B5C((struct CharBuf *)win, 0);
    if (b <= 0x272) {
        t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj07523 *)w)->f18C), b);
        func_0201C7D0((void *)win, 0, 0, (void *)t, (void *)(((struct Obj07523 *)w)->f8), 0x3C40);
        func_02045808((struct U16Vec *)t);
    }
    bg = ((struct Obj07523 *)w)->f178;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
}







void func_021B42D0(char *w, u32 a, u32 b)
{
    u32 t1, t2, t3, s, bg;

    t1 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01502 *)w)->f188), 0x18);
    t2 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01502 *)w)->f188), d_021D945C[((struct Obj01502 *)w)->f163]);
    t3 = (u32)func_020457B0(0x14, ((struct Obj01502 *)w)->f4);
    s = (u32)func_02045770((struct Descriptor *)((struct Obj01502 *)w)->f174);
    func_02043B5C((struct CharBuf *)s, 0xF);
    func_0201F73C((void *)(((struct Obj01502 *)w)->f174), 2, 0xE4, 9);
    func_0201EFA4((struct WordSet *)(((struct Obj01502 *)w)->f190), 0, a, 2, 0, 1);
    func_0201F250((struct WordSet *)(((struct Obj01502 *)w)->f190), (void *)t3, (void *)t1);
    func_0201C7D0((void *)s, 0, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    func_0201EFA4((struct WordSet *)(((struct Obj01502 *)w)->f190), 0, a * b, 7, 1, 1);
    func_0201F250((struct WordSet *)(((struct Obj01502 *)w)->f190), (void *)t3, (void *)t2);
    if (((struct Obj01502 *)w)->f163 == 0) {
        func_0201C7D0((void *)s, 0x23, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    } else {
        func_0201C7D0((void *)s, 0x1D, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    }
    bg = ((struct Obj01502 *)w)->f174;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
    func_02045808((struct U16Vec *)t3);
    func_02045808((struct U16Vec *)t2);
    func_02045808((struct U16Vec *)t1);
}







/*
 * Builds a 0x34-byte list template on the stack (layout as read by
 * func_0201FF30) and creates the list object from it.
 */
void func_021B43EC(char *w)
{
    Tmpl t;

    t.arr = ((struct Obj00037 *)w)->f180;
    t.cb04 = (void *)func_021B468C;
    if (((struct Obj00037 *)w)->f162 == 0) {
        t.cb08 = (void *)func_021B4510;
    } else {
        t.cb08 = (void *)func_021B45A0;
    }
    t.w0c = ((struct Obj00037 *)w)->f16C;
    t.count = func_0201F91C(((struct Obj00037 *)w)->f180);
    t.rows = 7;
    t.f14 = 0;
    t.f15 = 0;
    t.f16 = 0;
    t.f17lo = 8;
    t.f17hi = 0xC;
    t.f18lo = 0;
    t.f18hi = 0xD;
    t.f1Alo = 0;
    t.f1Amid = 0;
    t.f1Apad = 1;
    t.f1Amid2 = 0;
    t.f1Atop = 1;
    t.w1c = w;
    t.h20 = 0xC;
    t.h22 = 0x10;
    t.w24 = 0;
    t.w28 = w + 0x1A8;
    t.w2c = ((struct Obj00037 *)w)->f1B0;
    t.w30 = ((struct Obj00037 *)w)->f8;
    ((struct Obj00037 *)w)->f1A4 = (unsigned int)func_0201FF30((struct Src *)(&t), 0, 0, ((struct Obj00037 *)w)->f4);
}






void func_021B44CC(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g)
{
    if (d <= 8) {
        func_0201C7D0((void *)b, c, d, (void *)e, (void *)f, g);
    } else {
        func_0201C724(a, b, (s16_021B3370)c, (s16_021B3370)d, e, f, (u32)g);
    }
}






/*
 * Twin of func_021B45A0 (its else arm alone). The u8 third parameter is
 * what keeps the reload of its spill slot just before the last call; as u32
 * the reload is hoisted above the hi - lo subtraction. The first parameter
 * is forwarded untouched to func_02020D0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4510(u8 *p, int a, u8 b)
{
    char *w;
    u32 lo;
    int hi;

    w = (char *)func_02020D0C(p);
    if (a != -2) {
        func_0201EFA4((struct WordSet *)(((struct Obj02390 *)w)->f190), 1, *(u32 *)(w + a * 8 + 0x24), 5, 0, 1);
        func_0201F250((struct WordSet *)(((struct Obj02390 *)w)->f190), (void *)(((struct Obj02390 *)w)->f198), (void *)(((struct Obj02390 *)w)->f194));
        lo = func_0201D304((struct StrObj *)(((struct Obj02390 *)w)->f198), ((struct Obj02390 *)w)->f8, 0);
        hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj02390 *)w)->f16C)));
        func_021B44CC((void *)(((struct Obj02390 *)w)->f1B0), (u32)func_02045770((struct Descriptor *)((struct Obj02390 *)w)->f16C), hi - lo, b,
                      ((struct Obj02390 *)w)->f198, ((struct Obj02390 *)w)->f8, 0x31A0);
    }
}






/*
 * The u8 third parameter (a list-cursor callback's on-init flag) is what
 * moves the reload of its spill slot to just before the last call; as int or
 * u32 the reload is hoisted above the hi - lo subtraction.
 */
void func_021B45A0(u32 ctx, int a, u8 b)
{
    char *w;
    u32 lo;
    int hi;

    w = (char *)func_02020D0C((void *)ctx);
    if (a != -2) {
        if (func_02007F68((u8 *)(((struct Obj00810 *)w)->f10), ((Ent_021B3158 *)(w + 0x20))[a].id, 1, ((struct Obj00810 *)w)->f4) != 0) {
            lo = func_0201D304((struct StrObj *)(((struct Obj00810 *)w)->f1A0), ((struct Obj00810 *)w)->f8, 0);
            hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C)));
            func_021B44CC((void *)(((struct Obj00810 *)w)->f1B0), (u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C), hi - lo, b,
                          ((struct Obj00810 *)w)->f1A0, ((struct Obj00810 *)w)->f8, 0x31A0);
        } else {
            func_0201EFA4((struct WordSet *)(((struct Obj00810 *)w)->f190), 1, ((Ent_021B3158 *)(w + 0x20))[a].v, 5, 1, 1);
            func_0201F250((struct WordSet *)(((struct Obj00810 *)w)->f190), (void *)(((struct Obj00810 *)w)->f198), (void *)(((struct Obj00810 *)w)->f194));
            lo = func_0201D304((struct StrObj *)(((struct Obj00810 *)w)->f198), ((struct Obj00810 *)w)->f8, 0);
            hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C)));
            func_021B44CC((void *)(((struct Obj00810 *)w)->f1B0), (u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C), hi - lo, b,
                          ((struct Obj00810 *)w)->f198, ((struct Obj00810 *)w)->f8, 0x31A0);
        }
    }
}






void func_021B468C(u32 a, u32 idx)
{
    u16 v[4];
    char *w;
    char *t;

    w = (char *)func_02020D0C((void *)a);
    func_020202FC((struct Obj *)a, &v[1], &v[0]);
    v[2] = 0xAC;
    v[3] = v[0] * 16 + 0x16;
    func_0204B404((struct Obj *)(((struct Obj03132 *)w)->f1C0), (const struct Vec2 *)(&v[2]), 0);
    if (idx < 0x28) {
        t = w + 0x20;
        func_021B4264(w, *(u16 *)(t + idx * 8));
        func_021B3D60(w, *(u16 *)(t + idx * 8));
    } else {
        func_021B4264(w, 0xFFFF);
        func_021B3D60(w, 0xFFFF);
    }
}






void func_021B46FC(u8 *w)
{
    u16 a;
    u16 b;

    func_0202020C((struct Obj *)(((struct Obj19998 *)w)->f1A4), &a, &b);
}





/*
 * Untraced blob: constant zero return.
 *
 * Addresses are Black-image addresses.
 */
int func_021B4710(void)
{
    return 0;
}





void func_021B4714(u8 *p, u32 sel, u32 c, u32 d)
{
    u32 flag;
    u32 v;
    u32 h;

    if (sel == 9 && d != 0)
        flag = 1;
    else
        flag = 0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01503 *)p)->f17C)), 0xf);
    func_0201F73C((void *)(((struct Obj01503 *)p)->f17C), 0, 0xe4, 9);
    func_0201EF6C((struct WordSet *)(((struct Obj01503 *)p)->f190), 0, c, flag, 0);
    func_0201F14C((struct WordSet *)(((struct Obj01503 *)p)->f190), 1, func_02020FE4((void *)c, 5, ((struct Obj01503 *)p)->f4));
    v = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01503 *)p)->f188), sel);
    func_0201F250((struct WordSet *)(((struct Obj01503 *)p)->f190), (void *)(((struct Obj01503 *)p)->f198), (void *)v);
    func_02045808((struct U16Vec *)v);
    ((struct Obj01503 *)p)->f1B8 = (u32)func_0201CD10(((struct Obj01503 *)p)->f17C, 0, 0, ((struct Obj01503 *)p)->f198,
                                        ((struct Obj01503 *)p)->f8, func_02012FFC(),
                                        ((struct Obj01503 *)p)->f1B4, 0, ((struct Obj01503 *)p)->f4, 0xffff,
                                        (u32)func_021B4710);
    h = ((struct Obj01503 *)p)->f17C;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
}





void func_021B4804(char *w, u32 a)
{
    if (((struct Obj00030 *)w)->f162 == 1) {
        if (((struct Obj00030 *)w)->f163 == 1) {
            func_021B4984(w, 8, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200);
        } else {
            func_021B4984(w, 7, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200);
        }
    } else {
        if (((struct Obj00030 *)w)->f163 == 1) {
            func_021B4918(w, 6, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200, ((struct Obj00030 *)w)->f208);
        } else {
            func_021B4918(w, 5, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200, ((struct Obj00030 *)w)->f208);
        }
    }
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4878(u32 a)
{
func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)a)), 15);
    func_0201F73C((void *)a, 0, 228, 9);
}




void func_021B4894(char *w, u32 b)
{
    u32 t;
    u32 win;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01121 *)w)->f188), b);
    func_0201F250((struct WordSet *)(((struct Obj01121 *)w)->f190), (void *)(((struct Obj01121 *)w)->f198), (void *)t);
    func_02045808((struct U16Vec *)t);
    ((struct Obj01121 *)w)->f1B8 = (u32)func_0201CD10(((struct Obj01121 *)w)->f17C, 0, 0, ((struct Obj01121 *)w)->f198,
                                        ((struct Obj01121 *)w)->f8, func_02012FFC(), ((struct Obj01121 *)w)->f1B4, 0,
                                        ((struct Obj01121 *)w)->f4, 0xFFFF, 0);
    win = ((struct Obj01121 *)w)->f17C;
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}




/*
 * The spilled third parameter is narrow (u16 here; s16/u8 give the same
 * bytes): as u32/int its entry spill `str r2, [sp, #8]` lands after the
 * `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4918(char *w, u32 a, u16 b, u32 c, u16 d)
{
    func_021B4878(((struct Obj01121 *)w)->f17C);
    func_0201EF6C((struct WordSet *)(((struct Obj01121 *)w)->f190), 0, b, 0, 0);
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 1, d, 2, 0, 1);
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 2, d * c, 7, 0, 1);
    func_021B4894((char *)((u32)w), a);
}




void func_021B4984(char *w, u32 a, u32 b, u32 c)
{
    func_021B4878(((struct Obj01121 *)w)->f17C);
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 0, b - 327, 2, 2, 1);
    func_0201EF34((struct WordSet *)(((struct Obj01121 *)w)->f190), 1, func_020212B0(b));
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 2, c, 5, 0, 1);
    func_021B4894((char *)((u32)w), a);
}




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




void func_021B4D14(volatile Work_021B4878 *w)
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
    u16 k = func_02011330((struct Stream *)a);

    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 1;
    v[5] = 1;
    func_0218F9C4((u8 *)x, (u8 *)v, k);
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
