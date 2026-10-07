/*
 * file:     pokemontrade_3d_p01.c
 * unit:     yes
 * function: func_021DEA24, func_021DEB34, func_021DEBA0, func_021DEBD4, func_021DEC4C, func_021DECA0, func_021DED58, func_021DED74, func_021DEDBC, func_021DEE00, func_021DEEA8, func_021DEEFC, func_021DEF1C, func_021DF0B8, func_021DF168, func_021DF1C8, func_021DF210, func_021DF338, func_021DF37C, func_021DF3E4, func_021DF404, func_021DF43C, func_021DF490, func_021DF4CC, func_021DF510, func_021DF548, func_021DF59C, func_021DF5D8, func_021DF614, func_021DF6B4, func_021DF6EC, func_021DF708, func_021DF78C, func_021DF7AC, func_021DF7D0, func_021DF7F0, func_021DF868, func_021DF8A0, func_021DF8E0, func_021DF904, func_021DF918, func_021DF978, func_021DF9E8, func_021DFA60, func_021DFA98, func_021DFAD0, func_021DFB4C, func_021DFB84, func_021DFBB4, func_021DFBF0, func_021DFC28, func_021DFC68, func_021DFD0C, func_021DFD24, func_021DFD30, func_021DFD3C
 * address:  0x021DEA24
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE9E8 0x021DE9E8 thumb ov119
 *   func_02035C08 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE754 0x021DE754 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 *   func_021DD140 0x021DD140 thumb ov119
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_02035C60 0x02035C60 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_0207D658 0x0207D658 arm
 *   func_02040588 0x02040588 arm
 *   func_021E69C0 0x021E69C0 thumb ov119
 *   func_020221A4 0x020221A4 thumb
 *   func_021E4000 0x021E4000 thumb ov119
 *   func_021E64B8 0x021E64B8 thumb ov119
 *   func_021DD588 0x021DD588 thumb ov119
 *   func_021E4570 0x021E4570 thumb ov119
 *   func_021DD9DC 0x021DD9DC thumb ov119
 *   func_021E4888 0x021E4888 thumb ov119
 *   func_021DD528 0x021DD528 thumb ov119
 *   func_02041570 0x02041570 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021E24E8 0x021E24E8 thumb ov119
 *   func_021E6B90 0x021E6B90 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DE8C0 0x021DE8C0 thumb ov119
 *   func_02039C68 0x02039C68 arm
 *   func_0215642C 0x0215642C thumb ov009
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_02156ED0  0x02156ED0  thumb  ov009
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B99F0 0x021B99F0 thumb ov114
 *   func_021B99F4 0x021B99F4 thumb ov114
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_02008F88 0x02008F88 thumb
 *   func_02019B58 0x02019B58 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_02156E24 0x02156E24 thumb ov009
 *   func_0200853C 0x0200853C thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_020173EC 0x020173EC thumb
 *   func_020435F4 0x020435F4 arm
 *   func_02022230 0x02022230 thumb
 *   func_021D89CC 0x021D89CC thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021DD90C 0x021DD90C thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   d_021E76D4 0x021E76D4 data a4
 *   func_021E131C 0x021E131C thumb ov119
 *   d_021E76EC 0x021E76EC data a4
 *   func_021E26AC 0x021E26AC thumb ov119
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_02035C38 0x02035C38 arm
 *   func_021DD34C  0x021DD34C  thumb  ov119
 *   func_021DD4F4  0x021DD4F4  thumb  ov119
 *   func_021E62D4  0x021E62D4  thumb  ov119
 *   func_021E6718  0x021E6718  thumb  ov119
 *   func_021E6790  0x021E6790  thumb  ov119
 *   func_021E67A8  0x021E67A8  thumb  ov119
 *   func_02035D20 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021E67C4 0x021E67C4 thumb ov119
 *   func_021E68B4  0x021E68B4  thumb  ov119
 *   func_021E67E0 0x021E67E0 thumb ov119
 *   func_02006254 0x02006254 thumb
 *   func_021E5868  0x021E5868  thumb  ov119
 *   func_021E57FC  0x021E57FC  thumb  ov119
 *   func_021E6308 0x021E6308 thumb ov119
 *   func_021E293C 0x021E293C thumb ov119
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_021E6F0C 0x021E6F0C thumb ov119
 *   func_021E272C 0x021E272C thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   func_021E36A8 0x021E36A8 thumb ov119
 *   func_02041300 0x02041300 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   g_021E7844      0x021E7844  data  ov119
 *   d_021E7794 0x021E7794 data a4
 *   func_02015C30   0x02015C30  thumb
 *   sub_02030734   0x02030734  arm
 *   d_021E80F4     0x021E80F4  data  ov119
 *   _s32_div_f      0x0209C0A4  arm
 *   tbl_020A1B38    0x020A1B38  data
 *   func_02015C48   0x02015C48  thumb
 *   _s32_to_float    0x0209BDBC  arm
 *   __fdiv           0x0209CE10  arm
 *   __fmul           0x0209C77C  arm
 *   _fmul            0x0209C77C  arm
 *   _f2s             0x0209C494  arm
 *   func_02015E04  0x02015E04  thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005DF8  0x02005DF8  thumb
 */
#include "../../matched/include/Obj00251.h"
#include "../../matched/include/Obj10363.h"
#include "../../matched/include/Obj05337.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj02171.h"
#include "../../matched/include/Obj13900.h"
#include "../../matched/include/Obj01927.h"
#include "../../matched/include/Obj02827.h"
#include "../../matched/include/Obj22746.h"
#include "../../matched/include/Obj13901.h"
#include "../../matched/include/Obj13902.h"
#include "../../matched/include/Obj22747.h"
#include "../../matched/include/Obj10364.h"
#include "../../matched/include/Obj10365.h"
#include "../../matched/include/Obj10366.h"
#include "../../matched/include/Obj04479.h"
#include "../../matched/include/Obj13904.h"
#include "../../matched/include/Obj10368.h"
#include "../../matched/include/Obj13906.h"
#include "../../matched/include/Obj10369.h"
#include "../../matched/include/Obj00826.h"
#include "../../matched/include/Obj13907.h"
#include "../../matched/include/Obj22748.h"
#include "../../matched/include/Obj00906.h"

struct MsgBank;
struct Obj;
struct Entry;
struct Link;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
struct Sub0200852CObj;
struct TaskMenu;
struct S119DD4F4;
typedef unsigned char u8;

typedef unsigned int u32_021DEA24;

typedef struct S_021DEA24 S_021DEA24;

typedef unsigned int u32_021DEB34;

typedef unsigned int   u32_021DEBA0;

typedef unsigned short u16;

typedef unsigned u32_021DEBD4;

typedef unsigned int   u32_021DEC4C;

typedef unsigned int   u32_021DECA0;

typedef unsigned int   u32_021DED74;

typedef unsigned int   u32_021DEDBC;

typedef unsigned int   u32_021DEE00;

typedef unsigned int   u32_021DEEA8;

typedef unsigned int u32_021DEF1C;

typedef unsigned int   u32_021DF0B8;

typedef unsigned int   u32_021DF168;

typedef unsigned int   u32_021DF1C8;

typedef unsigned int   u32_021DF210;

typedef unsigned int   u32_021DF338;

typedef unsigned int   u32_021DF37C;

typedef unsigned int   u32_021DF404;

typedef unsigned int   u32_021DF43C;

typedef struct { int a, b; } Pair_021DF490;

typedef unsigned int   u32_021DF4CC;

typedef unsigned int   u32_021DF510;

typedef unsigned int   u32_021DF548;

typedef struct { int a, b; } Pair_021DF59C;

typedef unsigned int   u32_021DF5D8;

typedef unsigned int   u32_021DF708;

typedef unsigned int   u32_021DF7F0;

typedef unsigned int   u32_021DF8A0;

typedef unsigned int   u32_021DF918;

typedef unsigned int   u32_021DF978;

typedef struct { u8 low:4;u8 high:4; } Flags;

typedef unsigned int   u32_021DF9E8;

typedef unsigned int u32_021DFA60;

typedef struct {
    u32_021DFA60 a;
    u32_021DFA60 b;
} Pair_021DFA60;

typedef struct {
    Pair_021DFA60 t[25];
} Table;

typedef struct { int id; int key; } Ent_021DFA98;

typedef struct { Ent_021DFA98 e[22]; } Tbl;

typedef unsigned int   u32_021DFA98;

typedef unsigned int u32_021DFAD0;

typedef struct { int fn; int id; } Ent_021DFAD0;

typedef struct { Ent_021DFAD0 e[2]; } T2;

typedef struct { Ent_021DFAD0 e[6]; } T6;

typedef unsigned int u32_021DFB4C;

typedef unsigned int u32_021DFB84;

typedef unsigned int u32_021DFBB4;

typedef unsigned int u32_021DFBF0;

typedef signed short s16_021DFBF0;

typedef signed int s32_021DFBF0;

typedef struct {
    u32_021DFBF0 f00;
    s32_021DFBF0 f04;
    s32_021DFBF0 f08;
    u32_021DFBF0 f0c;
    u32_021DFBF0 f10;
    u16 f14;
    u16 f16;
} S_021DFBF0;

typedef unsigned int u32_021DFC28;

typedef struct {
    u32_021DFC28 f00;
    u32_021DFC28 f04;
    u32_021DFC28 f08;
    u32_021DFC28 f0c;
    u32_021DFC28 f10;
    u32_021DFC28 f14;
    u32_021DFC28 f18;
    u32_021DFC28 f1c;
    u32_021DFC28 f20;
    u32_021DFC28 f24;
    u32_021DFC28 f28;
    u32_021DFC28 f2c;
    u32_021DFC28 f30;
    u32_021DFC28 f34;
} P;

typedef unsigned int u32_021DFC68;

typedef int s32_021DFC68;

typedef unsigned int u32_021DFD0C;

typedef short s16_021DFD24;

typedef signed char s8;

typedef unsigned int u32_021DFD24;

typedef int s32_021DFD24;

typedef short s16_021DFD30;

typedef unsigned int u32_021DFD30;

typedef int s32_021DFD30;

typedef unsigned int   u32_021DFD3C;

extern void func_021B63D0(struct S_021DEA24 *p);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern int func_021B6448(u8 *),func_021B6470(u8 *);
extern void func_02045CAC(struct MsgBank *,unsigned,void *);
extern void func_021E1024(void *);
extern void func_021DD09C(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DE9E8(void *);
extern int func_02035C08(const void *);
extern u32_021DEA24 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void func_020061E4(u32_021DEA24 a);
extern void func_021E68F4(int,int);
extern int func_021DE754(char *,int),func_021DE208(char *);
extern int func_021DD140(char *p);
extern int func_021E12AC(char *p);
extern int func_02035C60(void);
extern void func_021E1098(char *p);
extern int func_021D8980(char *p);
extern void func_0207D658(u32_021DEBD4,int,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_021E69C0(char *p);
extern u32_021DEC4C func_020221A4(void);
extern void func_021E4000(char *p);
extern void func_021E64B8(void *);
extern void func_021DD588(char *p);
extern void func_021E4570(char *p);
extern void func_021DD9DC(unsigned char *);
extern void func_021E4888(char *p);
extern void func_021DD528(char *,int);
extern void func_02041570(int channel, u16 val);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021E24E8(char *p, int a1);
extern void func_021E6B90(char *p);
extern void func_0202208C(void *p1, u32_021DECA0 p2, u32_021DECA0 p3, u32_021DECA0 p4, u32_021DECA0 p5, u32_021DECA0 p6, u32_021DECA0 p7);
extern int func_021D8A24(void *);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32_021DEDBC b, u32_021DEDBC c, u32_021DEDBC d);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_021DE8C0(char *p);
extern void func_02039C68(struct Link *,unsigned,unsigned);
extern void func_0215642C(int);
extern void func_021B9774(u8 *p);
extern void func_021B9838(u8 *p);
extern void func_02156ED0(void);
extern int func_021B99DC(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern int func_021B99F0(u8 *p);
extern u32_021DEF1C func_021B99F4(u32_021DEF1C p, u32_021DEF1C i);
extern void func_021B99B8(u8 *);
extern int func_021D89EC(const u8 *p);
extern u32_021DEF1C func_02017E1C(void *,u32_021DEF1C,u32_021DEF1C);
extern void func_02017E40(void *,u32_021DEF1C,u32_021DEF1C);
extern u32_021DEF1C func_0202136C(u16);
extern void *func_02008F08(int);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern void func_02019B58(void *);
extern struct MsgBank *func_02045B38(u32_021DEF1C resident, u32_021DEF1C arcId, u32_021DEF1C fileId, u32_021DEF1C heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32_021DEF1C index);
extern u32_021DEF1C func_02045C04(struct Rec *rec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02045808(struct U16Vec *vec);
extern u32_021DEF1C func_020307B0(void *p);
extern void func_02156DC4(int a0, int a1);
extern void func_02156E24(int,int,int);
extern u32_021DF0B8 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *func_021B9800(int,int,int);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *,int,int);
extern int func_021B98F8(u8 *);
extern int func_021B9748(u8 *);
extern u32_021DF0B8 func_020173EC(void);
extern void func_020435F4(u32_021DF168 planes);
extern void func_02022230(u32_021DF168 which);
extern void func_021D89CC(char *p);
extern void func_021D9434(void *);
extern unsigned int func_0203D1A4(struct Link *p);
extern int func_021DD24C(char *p);
extern void func_021DD294(char *p, int a, int b);
extern void func_021DD90C(u8 *p, int i, int msg, int force);
extern void func_021DAEF0(char *p);
extern void func_021DBBD0(char *p);
extern void func_021E1030(char *p);
extern u32_021DF43C func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E131C(char *p, int *ids, int count, int x, int y);
extern void func_021E26AC(void *);
extern int func_021D8AF4(int,char *);
extern int func_021D8B0C(int,int);
extern int func_021D8AA8(void *);
extern int func_02035C38(void);
extern int func_021DD34C(char *p, int a, int b);
extern void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
extern void func_021E62D4(void *p, int a, int b);
extern void func_021E6718(char *p, int i);
extern void func_021E6790(void *p, int i, int a);
extern void func_021E67A8(void *p, int i);
extern u32_021DF7F0 func_02035D20(u32_021DF7F0 *outA, u32_021DF7F0 *outB);
extern void func_021E67C4(void *,int);
extern void func_021E68B4(int p, int n);
extern void func_021E67E0(void *, int, int);
extern int func_02006254(u32_021DF8A0 a);
extern void func_021E5868(char *p);
extern void func_021E57FC(int p);
extern void func_021E6308(void *,int,int);
extern void func_021E293C(char *p, int i);
extern void func_021E36D8(void *,int);
extern void func_021E6F0C(char *p, int side, void *mon);
extern void func_021E272C(char *p, int i, void *mon);
extern void func_02041B6C(u32_021DF918 bit);
extern void func_021E36A8(void *,int,int,void *,int,int);
extern void func_02041300(int,int,unsigned char,int,int,int,int);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern u32_021DF9E8 func_0203D3F8(u32_021DF9E8 entry, u32_021DF9E8 sendID, u32_021DF9E8 c, u32_021DF9E8 d, u32_021DF9E8 e, u32_021DF9E8 f, u32_021DF9E8 g, u32_021DF9E8 h);
extern void func_02015C30(void *p, u32_021DFB4C *out);
extern void *sub_02030734(u32_021DFB84 heapId, u32_021DFB84 size, int clear, const char *site, u16 tag);
extern s32_021DFBF0 _s32_div_f(s32_021DFBF0, s32_021DFBF0);
extern void func_02015C48(void *p, u32_021DFC28 *src);
extern float _s32_to_float(s32_021DFC68);
extern float __fdiv(float, float);
extern float __fmul(float, float);
extern s32_021DFC68 _f2s(float);
extern void func_02015E04(void *p);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32_021DFD3C a);
void func_021DEA24(char *p);
void func_021DEB34(void *p);
void func_021DEBA0(char *p);
void func_021DEBD4(void *p);
void func_021DEC4C(void *p);
void func_021DECA0(char *p);
void func_021DED58(void *p);
void func_021DED74(void *p);
void func_021DEDBC(void *p);
void func_021DEE00(unsigned char *p);
void func_021DEEA8(void *p);
void func_021DEEFC(void **p);
void func_021DEF1C(u8 *p);
void func_021DF0B8(char *p);
void func_021DF168(void *p);
void func_021DF1C8(void *p);
void func_021DF210(char *p);
void func_021DF338(void *p);
void func_021DF37C(u8 *p);
void func_021DF3E4(void *p);
void func_021DF404(char *p);
void func_021DF43C(void *p);
void func_021DF490(void *p);
void func_021DF4CC(char *p);
void func_021DF510(char *p);
void func_021DF548(void *p);
void func_021DF59C(void *p);
void func_021DF5D8(char *p);
int func_021DF614(char *p,int a,int b);
int func_021DF6B4(char *p, int a, int b);
void func_021DF6EC(void *p);
void func_021DF708(void *p);
void func_021DF78C(void *p);
void func_021DF7AC(void *p, int a);
void func_021DF7D0(void *p);
void func_021DF7F0(void *p);
void func_021DF868(void *p);
void func_021DF8A0(void *p, int a, int b);
void func_021DF8E0(void *p);
void func_021DF904(void *p);
void func_021DF918(void *p,int i,void *v);
void func_021DF978(void *p);
int func_021DF9E8(char *p,void *src,int kind);
void func_021DFA60(u32_021DFA60 key);
void func_021DFA98(int key);
void func_021DFAD0(int a0, u8 *a1);
void func_021DFB4C(void *p, void *a1, void *a2);
void *func_021DFB84(void *a0, void *a1, void *a2, u32_021DFB84 heapId);
void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
int func_021DFBF0(int a0, int a1, S_021DFBF0 *a2, int a3);
void func_021DFC28(P *p, int a1);
void func_021DFC68(void *p, int a1);
void func_021DFD0C(char *p);
void func_021DFD24(u32_021DFD24 *p);
void func_021DFD30(u8 *p, u32_021DFD30 v);
void func_021DFD3C(void *p);
extern const char d_021E80C4[];
extern const Pair_021DF490 d_021E76D4;
extern const Pair_021DF59C d_021E76EC;
extern const Table g_021E7844;
extern const Tbl d_021E7794;
extern s16_021DFBF0 tbl_020A1B38[];

static inline int poll(void) { int v=func_020362DC(); if(v)func_020355D8(0); return v; }

/*
 * prototype: 02035C08 returns the r0 consumed by original after its forwarding call; matched 021D98AC documents full ARM9 forwarding proof.
 */
void func_021DEA24(char *p)
{
    int idx,sentinel;
    func_021B63D0(*(S_021DEA24 * *)&((struct Obj00251 *)p)->f9C0);
    if(func_021B6448(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==1) {
        func_02045CAC(*(struct MsgBank * *)&((struct Obj00251 *)p)->f720,148,((struct Obj00251 *)p)->f738);
        func_021E1024(p);
        func_021B6548((unsigned char *)(*(int *)&((struct Obj00251 *)p)->f9C0),1,0);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DE9E8);
        return;
    }
    sentinel=-1;
    if(func_021B6470(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==sentinel) {
        idx=func_02035C08(d_021E80C4);
        if(idx!=sentinel) {
            func_020355D8(1);
            func_020061E4(0x548);
            func_021E68F4((int)p,sentinel);
            if(func_021DE754(p,idx)) return;
        }
        if(func_020355C4() && poll()) {
            ((struct Obj00251 *)p)->f10A0%=6;
            if(((struct Obj00251 *)p)->f10A0<0) ((struct Obj00251 *)p)->f10A0=0;
            func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
            func_020061E4(0x548);
            return;
        }
        if(poll()==1) {
            if(func_021DE754(p,((struct Obj00251 *)p)->f10A0)) return;
        }
        if(func_021DE208(p)) {
            func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
            func_020061E4(0x548);
        }
    }
}

void func_021DEB34(void *p)
{
    int v;
    if(func_021DD140(p) && func_021E12AC(p)) {
        v=func_020362DC();
        if(v) func_020355D8(0);
        if(v==0) {
            v=func_02035C60();
            if(v) func_020355D8(1);
            if(v==0) return;
        }
        if(func_020355C4()) func_021E68F4((int)p,-1);
        else func_021E68F4((int)p,0);
        func_021E1098(p);
        func_021D8980(p);
        func_021D8E84(p,(int)func_021DEA24);
    }
}


void func_021DEBA0(char *p)
{
    func_02045CAC(((struct Obj10363 *)p)->f720, 0x91, ((struct Obj10363 *)p)->f738);
    func_021E1024(p);
    *(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DEB34);
}

static inline void inside(int wnd,int effect) {u32_021DEBD4 tmp=(*(volatile u16 *)0x04001048 & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x04001048=(u16)tmp;}

static inline void outside(int wnd,int effect) {u32_021DEBD4 tmp=(*(volatile u16 *)0x0400104a & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x0400104a=(u16)tmp;}

/*
 * volatile: hardware WININ 0x04001048, WINOUT 0x0400104A and DISPCNT 0x04001000 read-modify-written at 0x021DEBE8/0x021DEBF8, 0x021DEC0C/0x021DEC18, 0x021DEC1A/0x021DEC22.
 */
void func_021DEBD4(void *p) {
 func_0207D658(0x04001050,27,-8);
 inside(31,1);
 *(volatile u16 *)0x04001040=0x80ff;
 *(volatile u16 *)0x04001044=0xa9;
 outside(31,0);
 *(volatile u32_021DEBD4 *)0x04001000=(*(volatile u32_021DEBD4 *)0x04001000 & ~0xe000)|0x2000;
 func_02040588(3,1);func_02040588(5,1);func_02040588(4,1);
}

void func_021DEC4C(void *p) {
 if(func_021E69C0(p)) {
  if(func_020355C4()) {func_021E68F4((int)p,-1);((struct Obj05337 *)p)->f10A0=0;}
  else {func_021E68F4((int)p,0);((struct Obj05337 *)p)->f10A0=0;}
  if(func_020221A4()) {func_021DEBD4(p);func_021D8E84(p,(int)func_021DEBA0);}
 }
}

void func_021DECA0(char *p) {
 func_021E4000(p);func_021DF7D0(p);func_021DF8E0(p);func_021E64B8(p);func_021DD588(p);func_021E4570(p);func_021DD9DC((unsigned char *)p);func_021E4888(p);
 func_021DD528(p,1);func_02041570(6,0);func_0204B3DC((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,0);
 func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,1);func_021B6548((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,0);func_021E24E8(p,6);
 ((struct Obj00001 *)p)->f108C=0;((struct Obj00001 *)p)->f1084=1;func_021E6B90(p);
 func_0202208C(0,1,1,0,6,1,((struct Obj00001 *)p)->f5F4);func_021D8E84(p,(int)func_021DEC4C);
}


void func_021DED58(void *p)
{
    if (func_020221A4() != 0) {
        func_021D8E84(p, (int)func_021DECA0);
    }
}

void func_021DED74(void *p) {
 if(!func_021D8A24(p) || ((struct Obj00001 *)p)->f1060) {
  func_0202208C(0,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
  func_021D8E84(p,(int)func_021DED58);
 }
}

void func_021DEDBC(void *p) {
 unsigned h=(unsigned)func_020399A8();
 u8 b;
 if(func_021D8A24(p)) {
  b=1;
  if(func_0203D3A8((void *)h,0xc0a,1,(u32_021DEDBC)(&b))) {func_021D8E84(p,(int)func_021DED74);return;}
 } else {func_021D8E84(p,(int)func_021DED74);}
}

void func_021DEE00(unsigned char *p) {
 int v;
 if(func_02039CB4((struct Link *)func_020399A8(),21,8)) {
  if(p[0x11e6]==0 && p[0x11e7]==0) {func_021D8E84(p,(int)func_021DEDBC);return;}
  if(p[0x11e6]==0xf0) v=0x9e;
  else if(p[0x11e6]==0xf1) v=0x9f;
  else if(p[0x11e6]==0xf2) v=0xa0;
  else if(p[0x11e6]==0xff) v=0xa1;
  else if((p[0x11e7]&0xf0)==0xf0) v=0xa1;
  else if(p[0x11e7]) v=0x8f;
  else v=0x90;
  func_02045CAC((struct MsgBank *)(((struct Obj02171 *)p)->f720),v,(void *)(((struct Obj02171 *)p)->f738));
  func_021E1024(p);p[0x11f1]=120;((struct Obj02171 *)p)->fF2C=0;
  func_021D8E84(p,(int)func_021DE8C0);
 }
}

void func_021DEEA8(void *p) {
 void *h=func_020399A8();
 ((struct Obj13900 *)p)->f109A=0;
 if(func_0203D3A8((void *)h,0xc11,1,(u32_021DEEA8)((char *)p+0x11e6))) {
  func_02039C68((struct Link *)func_020399A8(),21,8);
  if(((struct Obj13900 *)p)->f118C==2) func_0215642C(0);
  func_021D8E84(p,(int)func_021DEE00);
 }
}


void func_021DEEFC(void **p)
{
    if (*p != 0) {
        func_021B9774(*p);
        func_021B9838(*p);
        *p = 0;
        func_02156ED0();
    }
}

/*
 * lever: Nested success tests share the normal callback after the inner
 * guards. The bank allocation reads p+0x5f4 directly; the name allocation
 * reads the saved heap pointer, reproducing the original two load forms.
 * interface: 02019B58 receives the visibly loaded record pointer: its
 * empty 020185F0 call preserves r0 for 02019B64, which reads that input.
 */
void func_021DEF1C(u8 *p)
{
    int status, result, i, off1, off2;
    u8 n=0, error;
    u8 *data;
    const u16 *heap;
    void *mon, *bank, *text, *name;
    u32_021DEF1C value;
    status=func_021B99DC(*(u8 * *)&((struct Obj01927 *)p)->f0);
    result=func_021B9790(*(u8 * *)&((struct Obj01927 *)p)->f0);
    if(result==0) {
    if(status==200) {
        data=func_021B97F4(*(u8 * *)&((struct Obj01927 *)p)->f0);
        p[0x11e6]=func_021B99F0(data);
        if(p[0x11e6]==1) {
            off1=0x109a;
            if(*(u16 *)(p+off1)==0) {
                i=n;
                heap=(const u16 *)(p+0x5f4);
                off2=off1;
                off2-=0xb6;
                off1-=0xb6;
                do {
                    if(func_021D89EC(*(void **)(p+i*4+off1))) {
                        mon=*(void **)(p+i*4+off2);
                        if(func_021B99F4((u32_021DEF1C)data,n)) {
                            value=func_02017E1C(mon,6,0);
                            bank=func_02045B38(0,2,81,((struct Obj01927 *)p)->f5F4);
                            text=func_02045EC0(bank,15);
                            func_02045C04(bank);
                            if(func_0202136C(value)) {
                                name=func_02008F08(*heap);
                                func_02017E1C(mon,167,(u32_021DEF1C)name);
                                func_02008F88(name,func_02045A90(text));
                                func_02017E40(mon,167,(u32_021DEF1C)name);
                                func_020307B0(name);
                            }
                            func_02019B58(mon);
                            func_02017E40(mon,142,(u32_021DEF1C)func_02045A90(text));
                            func_02045808(text);
                        }
                        n++;
                    }
                    i++;
                } while(i<3);
                ((struct Obj01927 *)p)->f109A=1;
                func_021D8E84(p,(int)func_021DF0B8);
                goto cleanup;
            }
        }
        func_021D8E84(p,(int)func_021DEEA8);
    } else goto failed;
    } else goto failed;
    goto cleanup;
failed:
    {
        if(result==15 || status==200) return;
        switch(status) {
        case 400: error=240; break;
        case 401: error=241; break;
        case 408: error=242; break;
        default: error=255; break;
        }
        p[0x11e6]=error;
        func_021B9774(*(u8 * *)&((struct Obj01927 *)p)->f0);
    }
    func_021D8E84(p,(int)func_021DEEA8);
cleanup:
    if(*(u8 * *)&((struct Obj01927 *)p)->f0) {
        func_021B99B8(*(u8 * *)&((struct Obj01927 *)p)->f0);
        func_021B9838(*(u8 * *)&((struct Obj01927 *)p)->f0);
        *(u8 * *)&((struct Obj01927 *)p)->f0=0;
        func_02156ED0();
        func_02156DC4(0,0);
    }
}

void func_021DF0B8(char *p) {
 int n=0;
 int i;
 func_02156E24(13,0x10000,((struct Obj02827 *)p)->f5F4);
 *(u8 * *)&((struct Obj02827 *)p)->f0=func_021B9800(((struct Obj02827 *)p)->f5F4,func_0200853C(((struct Obj02827 *)p)->f830),((struct Obj22746 *)(*(char * *)&((struct Obj02827 *)p)->f8))->f24);
 func_02156DC4((int)func_021DEEFC,(int)p);
 for(i=0;i<3;i++) if(func_021D89EC(*(void **)(p+0xfe4+i*4))) n++;
 func_021B98A0(*(u8 * *)&((struct Obj02827 *)p)->f0,((struct Obj02827 *)p)->f5F4,func_020173EC()*n,2);
 for(i=0;i<3;i++) if(func_021D89EC(*(void **)(p+i*4+0xfe4))) func_021B98D8(*(u8 * *)&((struct Obj02827 *)p)->f0,*(int *)(p+i*4+0xfe4),func_020173EC());
 func_021B98F8(*(u8 * *)&((struct Obj02827 *)p)->f0);func_021B9748(*(u8 * *)&((struct Obj02827 *)p)->f0);func_021D8E84(p,(int)func_021DEF1C);
}

/*
 * volatile: field p+0x11fa re-read at 0x021DF18E after store at 0x021DF18C.
 */
void func_021DF168(void *p) {
 if(func_020221A4()) {
  func_021E4888(p);func_020435F4(4);func_02022230(4);
  ++*(volatile unsigned char *)&((struct Obj13901 *)p)->f11FA;
  if(*(volatile unsigned char *)&((struct Obj13901 *)p)->f11FA>=3) {func_021D89CC(p);func_021D8E84(p,(int)func_021D9434);return;}
  func_02039C68((struct Link *)func_020399A8(),31,8);func_021D8E84(p,(int)func_021DF0B8);
 }
}

void func_021DF1C8(void *p) {
 func_0202208C((void *)4,0,0,0,6,1,((struct Obj13902 *)p)->f5F4);
 if(((struct Obj13902 *)p)->f118C==2) func_0215642C(1);
 func_021D8E84(p,(int)func_021DF168);
}

void func_021DF210(char *p)
{
    unsigned a, b;
    volatile int v; /* memory-resident on purpose: the original keeps v in [sp] and reads it uninitialised on the fall-through path; a plain local takes r7 */
    a = func_0203D1A4((struct Link *)func_020399A8());
    b = 1 - a;
    if (!func_021D8A24(p)) {
        a = 0;
        b = 1;
    }
    if (func_021D8A24(p)) {
        if (!func_02039CB4((struct Link *)func_020399A8(), 0x1A, 8)) {
            func_021DD24C(p);
            return;
        }
    }
    func_021DD294(p, 0, 0);
    ((struct Obj00001 *)p)->f11EA = 0;
    ((struct Obj00001 *)p)->f11E8 = 3;
    ((struct Obj00001 *)p)->f11E9 = 3;
    if (*(unsigned char *)(p + a + 0x11E0) == 10 && *(unsigned char *)(p + b + 0x11E0) == 10) {
        func_021DD90C((u8 *)p, 0, 1, 1);
        func_021DD90C((u8 *)p, 1, 1, 1);
        if (((struct Obj00001 *)p)->f118C == 3) {
            func_021D8E84(p, (int)func_021DF1C8);
        } else {
            func_021D8E84(p, (int)func_021DEDBC);
        }
        return;
    }
    if (*(unsigned char *)(p + a + 0x11E0) == 4 && *(unsigned char *)(p + b + 0x11E0) == 4) {
        ((struct Obj22747 *)(*(char * *)&((struct Obj00001 *)p)->f8))->f8 = 3;
        func_021D8E84(p, (int)func_021D9434);
        return;
    }
    if (*(unsigned char *)(p + b + 0x11E0) == 4) {
        v = 0x61;
    } else if (*(unsigned char *)(p + a + 0x11E0) == 4) {
        v = 0x66;
    }
    func_02045CAC(((struct Obj00001 *)p)->f720, v, ((struct Obj00001 *)p)->f738);
    func_021E1024(p);
    ((struct Obj00001 *)p)->f11E0 = 0;
    ((struct Obj00001 *)p)->f11E1 = 0;
    ((struct Obj00001 *)p)->f11E8 = 0;
    ((struct Obj00001 *)p)->f11E9 = 0;
    func_021D8E84(p, (int)func_021DAEF0);
}

void func_021DF338(void *p) {
 unsigned h=(unsigned)func_020399A8();
 u8 b;
 if(func_021D8A24(p)) {
  b=1;
  if(func_0203D3A8((void *)h,0xc0f,1,(u32_021DF338)(&b))) {func_021D8E84(p,(int)func_021DF210);return;}
 } else {func_021D8E84(p,(int)func_021DF210);}
}

void func_021DF37C(u8 *p) {
 unsigned h=(unsigned)func_020399A8();
 u8 b;
 if(func_021E12AC((char *)p)) {
  if(func_021D8A24(p)) {
   b=10;
   if(func_0203D3A8((void *)h,0xc00,1,(u32_021DF37C)(&b))) {
    func_02039C68((struct Link *)func_020399A8(),26,8);
    func_021D8E84(p,(int)func_021DF338);return;
   }
  } else {p[0x11e0]=10;p[0x11e1]=10;func_021D8E84(p,(int)func_021DF338);}
 }
}

void func_021DF3E4(void *p)
{
    func_020399A8();
    if (func_021E12AC(p)) {
        func_021D8E84(p, (int)func_021DBBD0);
    }
}

void func_021DF404(char *p)
{
    func_02045CAC(((struct Obj10364 *)p)->f720, 0x88, ((struct Obj10364 *)p)->f738);
    func_021E1024(p);
    func_021E1030(p);
    ((struct Obj10364 *)p)->f11F1 = 0x78;
    func_021D8E84(p, (int)func_021DF37C);
}

void func_021DF43C(void *p)
{
    int v;
    if (!func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) return;
    v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    *(int *)&((struct Obj00001 *)p)->f64C=0;
    if (v==0) {func_021D8E84(p,(int)func_021DF404);return;}
    func_021E1098(p);
    func_021D8E84(p,(int)func_021DF3E4);
}

void func_021DF490(void *p)
{
    Pair_021DF490 t;
    if (func_021E12AC(p)) {
        t = d_021E76D4;
        func_021E131C(p, (int *)&t, 2, 0x20, 0xc);
        func_021D8E84(p, (int)func_021DF43C);
    }
}

void func_021DF4CC(char *p)
{
    func_0203D1A4((struct Link *)((unsigned)func_020399A8()));
    if (func_021E12AC(p) && func_021DD140(p)) {
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),0x89,(void *)(*(int *)&((struct Obj00001 *)p)->f738));
        func_021E1024(p);
        func_021D8E84(p,(int)func_021DF490);
    }
}

void func_021DF510(char *p)
{
    func_02045CAC(((struct Obj10365 *)p)->f720, 0x88, ((struct Obj10365 *)p)->f738);
    func_021E1024(p);
    func_021E1030(p);
    ((struct Obj10365 *)p)->f11F1 = 0x78;
    func_021D8E84(p, (int)func_021DF4CC);
}

void func_021DF548(void *p)
{
    int v;
    if (!func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) return;
    v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    *(int *)&((struct Obj00001 *)p)->f64C=0;
    if (v==0) {func_021D8E84(p,(int)func_021DF510);return;}
    func_021E1098(p);
    func_021D8E84(p,(int)func_021DBBD0);
}

void func_021DF59C(void *p)
{
    Pair_021DF59C t;
    if (func_021E12AC(p)) {
        t = d_021E76EC;
        func_021E131C(p, (int *)&t, 2, 0x20, 0xc);
        func_021D8E84(p, (int)func_021DF548);
    }
}

void func_021DF5D8(char *p)
{
    func_02045CAC(((struct Obj10366 *)p)->f720, 0x87, ((struct Obj10366 *)p)->f738);
    func_021E1024(p);
    func_021B6548(((struct Obj10366 *)p)->f9C0, 1, 0);
    func_021D8E84(p, (int)func_021DF59C);
    func_021E26AC(p);
}

int func_021DF614(char *p,int a,int b)
{
    int x,y,i;
    x=func_021D8AF4(a,p);
    y=func_021D8B0C(a,b);
    if(((struct Obj04479 *)p)->fF7C==y && ((struct Obj04479 *)p)->fF80==x) return 1;
    if(func_021D8AA8(p)) {
        for(i=0;i<3;i++) {
            if(*(int *)(p+i*4+0xfa4)==-1) continue;
            if(y==*(int *)(p+i*4+0xfa4) && x==*(int *)(p+i*4+0xfbc)) return 1;
        }
    } else {
        if(((struct Obj04479 *)p)->fF84==y && ((struct Obj04479 *)p)->fF88==x && ((struct Obj04479 *)p)->fF7C==-1 && ((struct Obj04479 *)p)->fF80==-1) return 1;
    }
    return 0;
}

int func_021DF6B4(char *p, int a, int b)
{
    int x = func_021D8AF4(a, p);
    int y = func_021D8B0C(a, b);
    if (((struct Obj13904 *)p)->fF94 == y && ((struct Obj13904 *)p)->fF98 == x) {
        return 1;
    }
    return 0;
}

void func_021DF6EC(void *p)
{
    if (func_02035C38() == 0) {
        func_021D8E84(p, (int)func_021DBBD0);
    }
}


void func_021DF708(void *p)
{
    int v = func_021DD34C(p, ((struct Obj00001 *)p)->fF98,
                          ((struct Obj00001 *)p)->fF94);

    if (func_021D8A24(p) == 0 ||
        func_0203D3A8(func_020399A8(), 0xc0b, 4, (u32_021DF708)(&v)) != 0) {
        ((struct Obj00001 *)p)->fF84 = -1;
        ((struct Obj00001 *)p)->fF88 = -1;
        ((struct Obj00001 *)p)->fF7C = -1;
        ((struct Obj00001 *)p)->fF80 = -1;
        ((struct Obj00001 *)p)->fF94 = -1;
        ((struct Obj00001 *)p)->fF98 = -1;
        if (v != -1) {
            func_021DD4F4(p, 0, v);
            func_021E62D4(p, 0, v);
        }
        func_021D8E84(p, 0x021DF6ED);
    }
}


/*
 * Init the four sub-objects when the object is in the first state.
 */
void func_021DF78C(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        func_021E6718(p, i);
}


void func_021DF7AC(void *p, int a)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        func_021E6790(p, i, a);
}


void func_021DF7D0(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        func_021E67A8(p, i);
}

void func_021DF7F0(void *p)
{
    unsigned x,y;
    unsigned char slot;
    if (!func_021D8AA8(p)) return;
    if (!func_02035D20(&x,&y)) return;
    if(x<8 || x>=104 || y<144 || y>=168) return;
    slot=(x-8)/24U;
    if(slot>=4) slot=3;
    func_021E67C4(p,slot);
    func_021DF8A0(p,slot,0);
    if(func_021D8A24(p)) func_0203D3A8(func_020399A8(),0xc0d,1,(u32_021DF7F0)(&slot));
}


/*
 * Count the two arm timers down and re-arm the ones that expired.
 */
void func_021DF868(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 2; i++) {
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            continue;
        ((unsigned char *)p)[0x11e4 + i]--;
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            func_021E68B4((int)p, i);
    }
}

void func_021DF8A0(void *p, int a, int b)
{
    if (func_021D8AA8(p)) {
        func_021E67E0(p,a,b);
        ((unsigned char *)p+b)[0x11e4]=60;
        if (!func_02006254(0x54a)) func_020061E4(0x54a);
    }
}


/*
 * Reset the two sub-objects and the decoder when in the first state.
 */
void func_021DF8E0(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 2; i++)
        func_021E68B4((int)p, i);
    func_021E5868(p);
}


/*
 * Tear the object down when it is in the first state.
 */
void func_021DF904(void *p)
{
    if (func_021D8AA8(p))
        func_021E57FC((int)p);
}

void func_021DF918(void *p,int i,void *v)
{
    int one;
    func_021E6308(p,i,0);
    if (((unsigned char *)p+i)[0x11e2]) {
        func_021E293C(p,i);
        func_021E36D8(p,i);
    }
    func_021E6F0C(p,i,v);
    func_021E272C(p,i,v);
    one=1;
    func_02041B6C(1);
    func_021E36A8(p,i,one-i,v,one-i,one);
}

void func_021DF978(void *p)
{
    int i;
    for(i=0;i<2;i++) {
        if (((unsigned char *)p+i)[0x11e2]==0) continue;
        ((unsigned char *)p+i)[0x11e2]--;
        func_021E6308(p,i,0);
        if (((unsigned char *)p+i)[0x11e2]==0) {
            func_021E293C(p,i);
            func_02041300(1,0,(unsigned char)(i<<4),0,16,24,16);
            func_02041B6C(1);
            func_021E36D8(p,i);
            func_021E6308(p,i,1);
        }
    }
}

int func_021DF9E8(char *p,void *src,int kind)
{
    unsigned id;
    int one;
    id=(unsigned)func_020399A8();
    if(((Flags *)(p+0x11fb))->low) return 0;
    MI_CpuCopy8(src,((struct Obj00001 *)p)->f106C,func_020173EC());
    one=1;
    if(!(int)func_0203D3F8(id,255,(u16)kind,func_020173EC(),(u32_021DF9E8)(((struct Obj00001 *)p)->f106C),(int)0,(int)0,(int)one)) return 0;
    ((Flags *)(p+0x11fb))->low=one;
    return one;
}


void func_021DFA60(u32_021DFA60 key)
{
    Table local;
    unsigned int i;

    local = g_021E7844;
    for (i = 0; i < 25; i++)
        if (key == local.t[i].b)
            func_020061E4(local.t[i].a);
}

void func_021DFA98(int key)
{
    Tbl t = d_021E7794;
    unsigned i;
    for (i = 0; i < 22; i++) {
        if (key == t.e[i].key) {
            func_020061E4(t.e[i].id);
        }
    }
}


/*
 * Recursive MATCH unblocker: the non-SDK callee of ov119 func_021DFC28
 * (+0038) and a dependency of the func_021D7130 tree.  Copies two constant
 * eight-byte-record tables from 0x021E7754 (two records) and 0x021E7764 (six
 * records) to the stack, gates on two bytes of the second argument, then
 * calls func_020061E4 on each record whose id matches arg0.  Both table
 * addresses are literal pool words, so they carry no relocation; the byte at
 * +0x11ED picks the six-record table (the `== 0` arm is the fall-through, the
 * unsigned counter is what makes the loop `blo`, not `blt`).
 *
 * Addresses are Black-image addresses.
 */
void func_021DFAD0(int a0, u8 *a1)
{
    T2 t1 = *(T2 *)0x021E7754;
    T6 t2 = *(T6 *)0x021E7764;
    unsigned int i;

    if (a1[0x11EF] != 0)
        return;
    if (a1[0x11ED] == 0) {
        for (i = 0; i < 2; i++)
            if (a0 == t1.e[i].id)
                func_020061E4(t1.e[i].fn);
    } else {
        for (i = 0; i < 6; i++)
            if (a0 == t2.e[i].id)
                func_020061E4(t2.e[i].fn);
    }
}


void func_021DFB4C(void *p, void *a1, void *a2)
{
    u8 buf[12];

    func_02015C30((void *)(((struct Obj10368 *)p)->f0), (u32_021DFB4C *)buf);
    ((struct Obj10368 *)p)->f8 = 0;
    ((struct Obj10368 *)p)->f4 = (u32_021DFB4C)a1;
    MI_CpuCopy8(a2, (char *)p + 0x28, 0xC);
    MI_CpuCopy8(buf, (char *)p + 0x1C, 0xC);
}


/*
 * Addresses are Black-image addresses.
 */
void *func_021DFB84(void *a0, void *a1, void *a2, u32_021DFB84 heapId)
{
    void *r = sub_02030734(heapId, 0x38, 1, (const char *)0x021E80F4, 0xD2);

    ((struct Obj13906 *)r)->f0 = a0;
    func_021DFB4C(r, a1, a2);
    ((struct Obj13906 *)r)->fC = 0;
    return r;
}


/*
 * Recursive MATCH unblocker: the alloc + store callee named by the parked
 * ov118 func_021D6CC4 (+0014 / +001E... it is the same pokemontrade_mcss.c
 * helper family as ov119 0x021DFB84) and by all three ov119 0x021DFBxx
 * entries.  func_021DFB84 is the four-argument form (line 0xD2) and this is
 * the five-argument form (a3 stored at +0x34, line 0xE7); the heap id is the
 * fifth parameter and reaches the debug allocator through its own stack home
 * (`ldrh r0,[sp,#0x20]`, a u16), which is what forces the 8-byte frame.
 *
 * Addresses are Black-image addresses.
 */
void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId)
{
    void *r = sub_02030734(heapId, 0x38, 1, (const char *)0x021E80F4, 0xE7);

    ((struct Obj10369 *)r)->f0 = a0;
    func_021DFB4C(r, a1, a2);
    ((struct Obj10369 *)r)->fC = 0;
    ((struct Obj10369 *)r)->f34 = (u32_021DFBB4)a3;
    return r;
}


/*
 * Recursive MATCH unblocker: callee of the parked ov119 func_021DFC68
 * (+0044) and part of the func_021D7130 tree.  Interpolates between a0 and a1
 * at record stride (the difference divided by f04, scaled by f08), then, when
 * the record's f16 is set and a3 is nonzero, re-derives the position from the
 * sine table tbl_020A1B38 with the phase f14>>4.  The divide's destination
 * only reproduces when the quotient is bound to its own local first
 * (`int q = ...; int r = q * a2->f08 + a0;`).
 *
 * Addresses are Black-image addresses.
 */
int func_021DFBF0(int a0, int a1, S_021DFBF0 *a2, int a3)
{
    int q = (a1 - a0) / a2->f04;
    int r = q * a2->f08 + a0;

    if (a2->f16 != 0 && a3 != 0)
        r = a1 + tbl_020A1B38[2 * (a2->f14 >> 4)] * 8;
    return r;
}


/*
 * Recursive MATCH unblocker: callee of the parked ov119 func_021DFC68
 * (+0060) and of func_021D7130's tree.  Reads the descriptor at p->f34 +
 * 0xc*p->f08 and hands three offset-adjusted words to func_02015C48, then
 * forwards p->f08 and its own second argument to func_021DFAD0.
 *
 * Addresses are Black-image addresses.
 */
void func_021DFC28(P *p, int a1)
{
    u32_021DFC28 vec[3];
    int idx = p->f08;
    u32_021DFC28 *e = (u32_021DFC28 *)(p->f34 + idx * 0xc);

    vec[0] = e[0] + p->f1c;
    vec[1] = e[1] + p->f20;
    vec[2] = e[2] + p->f24;
    func_02015C48((void *)p->f00, vec);
    func_021DFAD0(p->f08, (u8 *)a1);
}


/*
 * 2026-10-02 lane R1: the register shift (r2/r3 instead of r1/r2) was the incoming r1 kept
 * live: the function takes a second argument and forwards it to func_021DFC28 (p, a1), whose
 * matched definition reads r1. Callers in ov118 pass two arguments.
 *
 * Addresses are Black-image addresses.
 */
void func_021DFC68(void *p, int a1)
{
    u32_021DFC68 vec[6];
    s32_021DFC68 k, next, m;

    if (p == 0)
        return;
    k = *(s32_021DFC68 *)&((struct Obj00826 *)p)->f8;
    next = k + 1;
    m = ((struct Obj00826 *)p)->f4;
    *(s32_021DFC68 *)&((struct Obj00826 *)p)->f8 = next;
    if (m < next)
        return;
    if (m != next) {
        if (((struct Obj00826 *)p)->f34 != 0) {
            func_021DFC28(p, a1);
            return;
        }
        func_02015C30((void *)(((struct Obj00826 *)p)->f0), &vec[0]);
        vec[3] = func_021DFBF0(((struct Obj00826 *)p)->f1C, ((struct Obj00826 *)p)->f28, p, 0);
        if (((struct Obj00826 *)p)->f16 != 0) {
            float q = 374.0f * __fdiv(_s32_to_float((s32_021DFC68)(vec[0] - vec[3])), 4096.0f);
            ((struct Obj00826 *)p)->f14 -= (u16)_f2s(q);
        }
        vec[4] = func_021DFBF0(((struct Obj00826 *)p)->f20, ((struct Obj00826 *)p)->f2C, p, 1);
        vec[5] = func_021DFBF0(((struct Obj00826 *)p)->f24, ((struct Obj00826 *)p)->f30, p, 0);
        func_02015C48((void *)(((struct Obj00826 *)p)->f0), &vec[3]);
        return;
    }
    func_02015C48((void *)(((struct Obj00826 *)p)->f0), (u32_021DFC68 *)((char *)p + 0x28));
}


void func_021DFD0C(char *p)
{
    func_02015E04((void *)(((struct Obj13907 *)p)->f844));
    ((struct Obj13907 *)p)->f854 = 1;
}

void func_021DFD24(u32_021DFD24 *p) { if (p) { func_020307B0((void *)((u32_021DFD24)p)); } }


void func_021DFD30(u8 *p, u32_021DFD30 v) { ((struct Obj22748 *)p)->fF2C = v; }


/*
 * Decrement the +0x11f8 guard byte (both its condition and the store use
 * that same pool word) and pulse the 0x3c delay. Non-SDK dep of
 * func_021DFDA0's case-5/6 arms.
 *
 * Addresses are Black-image addresses.
 */
void func_021DFD3C(void *p)
{
    u8 *b = p;

    if (((struct Obj00906 *)b)->f11F8 != 0) {
        func_02005E9C();
        ((struct Obj00906 *)b)->f11F8 -= 1;
        func_02005DE4(0);
        func_02005DF8(0x3c);
    }
}
