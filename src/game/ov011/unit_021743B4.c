/*
 * file:     unit_021743B4.c
 * unit:     yes
 * function: func_021743B4, func_021743E4, func_0217440C, func_0217443C, func_0217446C, func_0217449C, func_021744D0, func_02174514, func_0217456C, func_021745B0, func_021745F8, func_02174630, func_02174660, func_02174690, func_021746AC, func_021746EC, func_02174734, func_02174798, func_021747A8, func_021747E0, func_021747F4, func_0217482C, func_02174854, func_02174898, func_021748CC, func_02174908, func_02174954, func_02174978, func_02174AE0, func_02174B2C, func_02174B7C, func_02174BC4, func_02174C38, func_02174CCC, func_02174D5C, func_02174DF4, func_02174E14, func_02174E3C, func_02174EAC, func_02174F54, func_02175004, func_02175060, func_02175144, func_02175184, func_021751A8, func_021751D4, func_02175274, func_021752DC, func_02175368, func_0217537C, func_0217538C, func_021753B8, func_021753D0, func_0217544C, func_0217545C, func_0217546C, func_021754B4, func_021754E8, func_02175508, func_02175514, func_0217553C, func_02175548, func_02175598, func_02175628, func_02175648, func_021756A4, func_021756B0, func_021756D0, func_021756F0, func_02175710, func_0217574C, func_0217576C, func_021757A8, func_021757C4, func_02175894, func_021758B4, func_021758C8, func_02175914, func_02175920, func_0217592C, func_02175938, func_02175954, func_021759B0, func_021759C0, func_021759F8, func_02175A24, func_02175A34, func_02175AE8, func_02175B14, func_02175B34, func_02175B4C, func_02175B8C, func_02175BAC, func_02175BBC, func_02175BCC, func_02175BE4
 * address:  0x021743B4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021780FC 0x021780FC thumb ov014
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012F20  0x02012F20  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_0202E7E0  0x0202E7E0  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0202E7C4  0x0202E7C4  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020266AC 0x020266AC thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_021583EC  0x021583EC  thumb ov010
 *   func_021861F4  0x021861F4  thumb ov020
 *   func_02012800  0x02012800  thumb
 *   func_0203D578  0x0203D578  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_02161FF0  0x02161FF0  thumb ov010
 *   func_02162008  0x02162008  thumb ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02173758  0x02173758  thumb  ov011
 *   func_02173828  0x02173828  thumb  ov011
 *   func_02174374  0x02174374  thumb  ov011
 *   func_02173984  0x02173984  thumb  ov011
 *   func_02012E40  0x02012E40  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BE84  0x0200BE84  thumb
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_021737A8  0x021737A8  thumb ov011
 *   func_021738E4  0x021738E4  thumb ov011
 *   func_02173AE0  0x02173AE0  thumb ov011
 *   func_02173B44  0x02173B44  thumb ov011
 *   func_020127C4 0x020127C4 thumb
 *   func_02162024 0x02162024 thumb ov010
 *   func_02162038 0x02162038 thumb ov010
 *   func_0216202C 0x0216202C thumb ov010
 *   func_02162040 0x02162040 thumb ov010
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0216749C  0x0216749C  thumb ov010
 *   func_021673C4  0x021673C4  thumb ov010
 *   func_021673A8  0x021673A8  thumb ov010
 *   func_02039338  0x02039338  arm
 *   func_02173CB0 0x02173CB0 thumb ov011
 *   func_02012944  0x02012944  thumb
 *   func_02008468  0x02008468  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008494  0x02008494  thumb
 *   func_020127AC  0x020127AC  thumb
 *   func_02012BA4  0x02012BA4  thumb
 *   func_020266D4  0x020266D4  thumb
 *   func_020264B4  0x020264B4  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013E90  0x02013E90  thumb
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_02167810  0x02167810  thumb  ov010
 *   func_02167658  0x02167658  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *   d_02176AA0  0x02176AA0  data ov011 a2
 *   func_02012B58 0x02012B58 thumb
 *   func_0216786C  0x0216786C  thumb ov010
 *   func_02012FB0  0x02012FB0  thumb
 *   sub_02082BCC  0x02082BCC  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020120D8  0x020120D8  thumb
 *   func_02008550  0x02008550  thumb
 *   tbl_02176A90   0x02176A90  data  ov011  a2
 *   tbl_02176A98   0x02176A98  data  ov011  a2
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200BF70  0x0200BF70  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_0200BF94  0x0200BF94  thumb
 *   func_0200BF54  0x0200BF54  thumb
 *   d_02176B08 0x02176B08 data ov011 a2
 *   tbl_02176AD0 0x02176AD0 data ov011 a2
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02161FEC  0x02161FEC  thumb  ov010
 *   func_02175EE8 0x02175EE8 thumb ov011
 *   func_02175D34  0x02175D34  thumb  ov011
 *   func_02176158  0x02176158  thumb  ov011
 *   func_02176194  0x02176194  thumb  ov011
 *   func_0203F4FC 0x0203F4FC arm
 *   func_02173DA0  0x02173DA0  thumb  ov011
 *   func_02173EEC  0x02173EEC  thumb  ov011
 *   func_021741E8  0x021741E8  thumb  ov011
 *   func_02173F74  0x02173F74  thumb  ov011
 *   func_021742EC  0x021742EC  thumb  ov011
 *   func_021742A8  0x021742A8  thumb  ov011
 *   func_02173FF4 0x02173FF4 thumb ov011
 *   func_02175DA8 0x02175DA8 thumb ov011
 */
#include "../../matched/include/Obj12421.h"
#include "../../matched/include/Obj09346.h"
#include "../../matched/include/Obj00269.h"
#include "../../matched/include/Obj09347.h"
#include "../../matched/include/Obj07329.h"
#include "../../matched/include/Obj04951.h"
#include "../../matched/include/Obj09349.h"
#include "../../matched/include/Obj01838.h"
#include "../../matched/include/Obj05913.h"
#include "../../matched/include/Obj02670.h"
#include "../../matched/include/Obj07330.h"
#include "../../matched/include/Obj12425.h"
#include "../../matched/include/Obj19182.h"
#include "../../matched/include/Obj03548.h"
#include "../../matched/include/Obj00566.h"
#include "../../matched/include/Obj07331.h"
#include "../../matched/include/Obj07332.h"
#include "../../matched/include/Obj19190.h"
#include "../../matched/include/Obj19191.h"
#include "../../matched/include/Obj00567.h"
#include "../../matched/include/Obj12430.h"
#include "../../matched/include/Obj12431.h"
#include "../../matched/include/Obj19193.h"
#include "../../matched/include/Obj09352.h"

struct Entry;
struct Link;
struct BigObj;
struct Rec44;
struct Sub02014444Obj;
struct Sub24;
struct SaveBlock;
struct Big;
struct Entry32;
struct Sub0200852CObj;
struct Ent;
struct Work;
struct Src;
struct Report;
struct Rec1B0;
struct Ctx;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct { u8 low : 4; u8 flags : 2; u8 high : 2; } F93F;

typedef struct F_021743B4 {
    unsigned char f0 : 1;
    unsigned char f1 : 7;
} F_021743B4;

typedef struct { unsigned char a : 1; unsigned char b : 1; unsigned char c : 1; } F8;

typedef struct { int d[21]; } B54;

typedef struct { u8 pad[0x8f8]; u8 f0 : 1; u8 f1 : 1; u8 f2 : 1; u8 f3 : 5; } F_02174854;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits;

typedef struct Blk {
    u8 pad[0x50];
    u32 a : 6;
    u32 b : 4;
    u32 c : 4;
    u32 d : 4;
    u32 e : 6;
} Blk;

typedef struct {
    u16 low : 9;
    u16 state : 6;
    u16 high : 1;
} F86_02174E14;

typedef struct Ent_021748CC {
    int w[7];
} Ent_021748CC;

typedef struct F86_02174E3C {
    u16 x : 3;
    u16 rest : 13;
} F86_02174E3C;

typedef struct Q {
    u8 lo : 6;
    u8 hi : 2;
} Q;

typedef struct Ent_02174F54 {
    u32 f0;
    int f4;
    u8 pad8[0xc];
    u16 f14;
    u16 a : 3;
    u16 rest : 13;
    u8 pad18[3];
    u8 lo : 6;
    u8 mid : 1;
    u8 hi : 1;
} Ent_02174F54;

typedef struct Cp {
    int w[5];
} Cp;

typedef struct Fl_02174F54 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Fl_02174F54;

typedef struct Entry {
    u32 f0;
    u8 pad4[0xe];
    u8 f12;
    u8 pad13;
    u16 f14;
    u16 a : 3;
    u16 b : 6;
    u16 f18;
    u8 pad1a;
    u8 pad1b : 7;
    u8 hi : 1;
} Entry;

typedef struct Ent_021743B4 {
    u16 a;
    u16 b;
    u16 c;
} Ent_021743B4;

typedef struct C12 {
    int w[3];
} C12;

typedef struct Hd {
    u8 pad[0x14];
    u16 f14;
    u16 lo : 3;
    u16 x : 6;
    u16 mid : 6;
    u16 top : 1;
} Hd;

typedef struct F86 {
    u16 lo : 9;
    u16 x : 6;
    u16 hi : 1;
} F86;

typedef struct { u8 low : 4; u8 flag : 1; u8 high : 3; } Flags_0217545C;

typedef struct { u8 low : 4; u8 flag : 1; u8 high : 3; } Flags_021754B4;

typedef unsigned long long u64;

typedef struct Out {
    u32 f00;
    u64 f04;
    u8  f0c[2];
    u8  f0e;
} Out;

typedef struct Flags_021756F0 {
    u8 lo : 6;
    u8 f  : 1;
    u8 hi : 1;
} Flags_021756F0;

typedef struct Lo3 {
    u16 v  : 3;
    u16 hi : 13;
} Lo3;

typedef struct Flags_02175710 {
    u8 a  : 1;
    u8 f  : 1;
    u8 hi : 6;
} Flags_02175710;

typedef struct {
    u8 pad0[0xA8];
    u16 hA8;
    u16 hAA;
    u8 padAC[0xD8 - 0xAC];
    u8 bD8;
    u8 padD9[0xE3 - 0xD9];
    u8 bE3;
    u8 padE4[0x19C - 0xE4];
    u8 b19C;
    u8 pad19D[0x1A5 - 0x19D];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 f4 : 1;
    u8 f5 : 3;
} Work;

typedef struct {
    u32 w0;
    u32 w4;
} Ctx;

typedef struct Flags_021758C8 {
    u8 a  : 1;
    u8 f  : 1;
    u8 hi : 6;
} Flags_021758C8;

typedef struct Rec {
    u32 lo : 15;
    u32 a  : 7;
    u32 b  : 10;
    u8  pad04[0x28];
    u8  f2c;
    u8  pad2d[7];
} Rec;

typedef struct {
    u8 pad0[0x190];
    u32 stamp;
    u8 pad194[9];
    u8 active;
    u8 pending;
} State;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags_02175A24;

typedef struct Fl_02175184 {
    u8 lo : 2;
    u8 x  : 1;
    u8 y  : 1;
    u8 hi : 4;
} Fl_02175184;

typedef struct { u8 a:2; u8 bit:1; u8 rest:5; } Flags_02175B8C;

typedef struct { u8 a : 3; u8 b : 1; u8 c : 4; } Fb;

u32 func_02026478(void *obj);
int func_021736D8(void);
struct Entry *func_020399A8(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_0203D1E8(u32 unused, void *arg);
void func_021780FC(u8 value);
u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0203D1A4(struct Link *p);
int func_02012F20(int a);
void *func_02012B38(const struct BigObj *p);
u8 func_02014484(struct Sub02014444Obj *o);
int func_0202E7E0(int a);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0202E7C4(int a, int b, int c);
void func_02082D44(const void *s, void *d, int n);
void func_020266AC(u32 a, u32 b, u32 c);
u8 *func_020127D0(u8 *o, u32 idx);
int func_021583EC(void *a0, int a1);
void func_021861F4(u16 *p, int x);
void func_02012800(u8 *obj, void *dst);
int func_0203D578(int a, int b);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_02161FF0(u8 *p, int v);
void func_02162008(u8 *p, u16 v);
void *func_020127A4(struct SaveBlock *p);
u16 func_02012AC8(const struct Rec44 *p);
unsigned int func_02013D9C(unsigned int id);
extern u32 func_0203D378(void);
extern int func_0203D1B4(void);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern int func_02173758(int a, int b, ...);
extern int func_02173828(char *p);
extern int func_02174374(int *a);
extern int func_02173984(char *p, int b);
extern u8 func_02012E40(const u8 *o);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_0200BE84(void *, u8 *);
u32 func_0203D1C0(u32 index);
int func_021737A8(void);
int func_021738E4(void *a, int b);
int func_02173AE0(int a, int b, int c, int d);
int func_02173B44(void *p, int i, int v);
unsigned char *func_020127C4(void *p);
int func_02162024(char *p, int index, void *out);
void func_02162038(char *p, int index);
int func_0216202C(char *p, void *out, u8 *index);
void func_02162040(char *p);
void *func_0200E0B0(void *p);
unsigned short func_0216749C(struct Entry32 *list, struct Entry32 *out, u32 cap, int page, u8 *n);
u8 func_021673C4(u8 *p);
u8 func_021673A8(u8 *p);
u16 func_02039338(void);
int func_02173CB0(int *a, int b);
u8 *func_02012944(void *p);
int func_02008468(void);
void *func_020127B8(void *p);
unsigned int func_02008530(const struct Sub0200852CObj *obj);
void func_02008494(void *src, void *dst);
void *func_020127AC(struct SaveBlock *p, unsigned int idx);
void func_02012BA4(struct BigObj *p, int i, u8 v);
void func_020266D4(u32 a, u32 b);
void func_020264B4(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag);
extern u32 func_02013D5C(u32 id);
extern u32 func_02013E90(u32 a, u32 b);
extern int func_021677E4(void *p, int i);
extern u16 func_02167810(struct Work *w, int i);
extern void func_02167658(int, int);
extern void func_021675D0(struct Work *w, int idx, int a2, struct Src *src);
extern u8 func_02012B58(const struct BigObj *p);
int func_0216786C(struct Work *w, struct Report *out);
u8 func_02012FB0(int a);
extern void sub_02082BCC(void *p, int c, unsigned int n);
extern void MI_CpuFill8(void *, u8, u32);
int func_020120D8(char *a);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_0200FB24(void);
extern u32 func_0200BF70(struct Rec1B0 *p);
extern int func_02012B70(const struct BigObj *p);
extern int func_02012FCC(int p0);
extern unsigned long long func_0200BFA4(u8 *p, void *q, u32 mode);
extern unsigned long long func_0200BF94(struct Rec1B0 *p);
extern void func_0200BF54(struct Rec1B0 *p, u8 *dest, u32 n);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02012B8C(struct BigObj *p, u32 v);
extern void func_02161FEC(char *p, u16 v);
extern void func_02175EE8(u8 *);
extern void func_02175D34(Ctx *c, Work *w, int a);
extern void func_02176158(int a, u8 *p);
extern void func_02176194(Ctx *c, Work *w);
extern u32 func_0203F4FC(void);
extern int func_02173DA0(int a, int b, int c);
extern int func_02173EEC(char *a, char *b);
extern int func_021741E8(char *a, char *b);
extern int func_02173F74(int a, u8 *b);
extern u32 func_021742EC(u32 a);
extern int func_021742A8(int a);
extern int func_02173FF4(int a, int b, int c);
extern int func_02175DA8(u8 *p);
int func_021743B4(char *p);
void func_021743E4(int a, int b, void *c, signed char *p);
u32 func_0217440C(void);
void func_0217443C(int a, int b, void *c, signed char *p);
u32 func_0217446C(void);
void func_0217449C(int a, int b, u8 *c, u8 *p);
int func_021744D0(int a, int b, int c, ...);
void func_02174514(int a, int b, int *c, char *d);
int func_0217456C(int a, int b, int c, ...);
void func_021745B0(int a, int b, void *c, char *d);
int func_021745F8(u32 a, u32 b);
void func_02174630(int a, int b, u8 *c, u8 *p);
int func_02174660(int a, ...);
void func_02174690(int n, int b, int c, u8 *p);
int func_021746AC(char *a, int b);
void func_021746EC(int a, int b, void *c, char *d);
int func_02174734(char *p, int b, void *c);
void func_02174798(int a, int b, int c, u8 *p);
int func_021747A8(void *a, int b);
void func_021747E0(int a, int b, int c, u8 *p);
int func_021747F4(int a, int b);
void func_0217482C(int a, int b, const u8 *c, u8 *p);
int func_02174854(unsigned char *p, int b, int c);
void func_02174898(int a, int b, B54 *c, u8 *p);
int func_021748CC(char *p, int a);
void func_02174908(int a, int b, int c, unsigned char *d);
u32 func_02174954(u32 p);
void func_02174978(u8 *s);
void func_02174AE0(unsigned char *p);
void func_02174B2C(unsigned char *p);
void func_02174B7C(unsigned char *p);
void func_02174BC4(unsigned char *p);
void func_02174C38(unsigned char *p);
void func_02174CCC(unsigned char *p);
void func_02174D5C(int *p, const u8 *q);
void func_02174DF4(u8 *p);
void func_02174E14(u8 *p, int a);
void func_02174E3C(u8 *p);
void func_02174EAC(u8 *p, int idx, u8 *q);
void func_02174F54(u8 *p, int idx, const Ent_02174F54 *src, int arg);
void func_02175004(u8 *p);
void func_02175060(u8 *p, int idx);
int func_02175144(u16 v, u8 *out);
int func_02175184(u8 *a, u8 *b);
int func_021751A8(u8 *p, int index);
void func_021751D4(u8 *p, u16 a, int b, Ent_02174F54 *c);
void func_02175274(u8 *p, int arg);
int func_021752DC(u8 *p);
void func_02175368(char *p);
unsigned char *func_0217537C(unsigned char *p);
void func_0217538C(u8 *p, int a);
void func_021753B8(u8 *p);
int func_021753D0(u8 *p, int i, u8 v);
void func_0217544C(u8 *p);
void func_0217545C(u8 *p);
void func_0217546C(u8 *p);
int func_021754B4(u8 *p, int *out);
void func_021754E8(u8 *p, int a, int b, int c);
void func_02175508(int a, int b, int c);
int func_02175514(u8 *p);
void func_0217553C(u8 *p);
void func_02175548(u32 a, u16 *p1, u8 *p2, u8 *p3);
u16 func_02175598(u8 *o, u32 id);
int func_02175628(void);
void func_02175648(void *sv, Out *o);
u8 func_021756A4(char *p);
int func_021756B0(int value);
int func_021756D0(u32 x);
void func_021756F0(u8 *o, u32 v);
void func_02175710(u8 *o, u32 v);
void func_0217574C(u8 *o, u32 v);
void func_0217576C(u8 *p);
void func_021757A8(u8 *p);
void func_021757C4(Ctx *c, Work *w);
int func_02175894(u8 *p);
int func_021758B4(u8 *p);
int func_021758C8(u8 *o);
void func_02175914(int a, int b);
void func_02175920(int a);
void func_0217592C(int a);
void func_02175938(u8 *p, const u16 *src, int index);
int func_02175954(void *unused, u8 *o, Rec *src);
void func_021759B0(u8 *p);
void func_021759C0(State *p, u8 index);
void func_021759F8(u8 *p, int n);
int func_02175A24(u8 *p);
void func_02175A34(void *a, u8 *b);
void func_02175AE8(int ctx, u8 *p);
int func_02175B14(u8 *p);
u8 *func_02175B34(u8 *p);
void func_02175B4C(u8 *a, u8 *b);
int func_02175B8C(u8 *p);
void func_02175BAC(u8 *p);
int func_02175BBC(u8 *p);
u8 *func_02175BCC(u8 *p);
int func_02175BE4(void *a);
void func_02175C04(u8 *o, u32 bit);
extern Ent_021743B4 d_02176AA0[8];
extern u16 tbl_02176A90[];
extern u16 tbl_02176A98[];
extern const u16 d_02176B08[];
extern u16 tbl_02176AD0[];




int func_021743B4(char *p)
{
    func_02026478((void *)(((int *)p)[1]));
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0x21d, 4, (u32)(p + 0x354));
}




void func_021743E4(int a, int b, void *c, signed char *p)
{
    p[0x93d]++;
    if (p[0x93c] == 0) {
        func_0203D1E8((u32)func_020399A8(), 0);
        func_021780FC(1);
    }
}




u32 func_0217440C(void)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), 0, 0x21e, 0, 0, 0, 0, 0);
}




void func_0217443C(int a, int b, void *c, signed char *p)
{
    p[0x93d]--;
    if (p[0x93d] == 0 && p[0x93c] == 0) {
        func_0203D1E8((u32)func_020399A8(), (void *)1);
        func_021780FC(0);
    }
}




u32 func_0217446C(void)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), 0, 0x21f, 0, 0, 0, 0, 0);
}




/*
 * extent: existing follower ov011_func_021744D0.c stays separate.
 */
void func_0217449C(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
        ((F93F *)(p + 0x93f))->flags |= *c;
    }
}





/*
 * Handed as 0x021744D2; the function starts at the push {r0-r3} at 0x021744D0.
 */
int func_021744D0(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), b, 0x220, 1, (u32)(&c), 0, 0, 0);
}





/*
 * 2026-10-05 (D8 lane19): re-verified, MATCH; only unresolved relocations are arm9 leaves 0x0202E7E0 and 0x0202E7C4 (no witness outside range). Needs labels seeded. Source is byte-correct; no C change possible.
 *
 * Blocked: MATCH*, two unlabelled arm9 leaves have no witness outside the range (Ilias's):
 *   0x0202E7E0 thumb `int f(int *p) { return *p; }` (ldr r0,[r0]; bx lr)
 *   0x0202E7C4 thumb leaf, ldm/stm struct copy of 0x18 bytes (words at 0202E7C4..0202E7DC)
 * Everything else in the file compiles byte-correct (88 of 90 B listed, tail is pad).
 */
void func_02174514(int a, int b, int *c, char *d)
{
    int p;
    int q;
    int t;

    p = func_02026478((void *)(((int *)d)[1]));
    q = func_02012F20(p);
    if ((unsigned char)d[0x8fb] & (1 << a)) {
        if (func_02014484(func_02012B38((const struct BigObj *)p)) == 1) {
            t = func_0202E7E0(q);
            if (t == 0 || t == 3) {
                func_0202E7C4(q, *c, (int)func_02012950((struct Sub24 *)p, a));
            }
        }
    }
}





/*
 * Handed as 0x0217456E; the function starts at the push {r0-r3} at 0x0217456C.
 */
int func_0217456C(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), b, 0x221, 4, (u32)(&c), 0, 0, 0);
}





void func_021745B0(int a, int b, void *c, char *d)
{
    func_02026478((void *)(((int *)d)[1]));
    if (((unsigned char)d[0x8fb] & (1 << a)) && ((F_021743B4 *)(d + 0x8f8))->f0 == 0) {
        func_02082D44(c, d + 0x8e4, 0x14);
        ((F_021743B4 *)(d + 0x8f8))->f0 = 1;
    }
}




int func_021745F8(u32 a, u32 b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), a, 0x222, 0x14, b, 0, 0, 0);
}




/*
 * extent: existing follower ov011_func_02174660.c stays separate.
 */
void func_02174630(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((u32)func_020399A8())) && (p[0x8fb] & (1 << a))) {
        func_020266AC(((u32 *)p)[1], a, *c);
    }
}





/*
 * Handed as 0x02174662; the function starts at the push {r0-r3} at 0x02174660.
 */
int func_02174660(int a, ...)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x223, 1, (u32)(&a));
}



void func_02174690(int n, int b, int c, u8 *p) { p[0x908] |= (u8)(1 << n); }




int func_021746AC(char *a, int b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    r = func_0203D3F8((u32)func_020399A8(), b, 0x224, 0, 0, 0, 0, 0);
    if (r == 1) {
        a[0x90c] = 0;
    }
    return r;
}




void func_021746EC(int a, int b, void *c, char *d)
{
    int h;
    int s;

    h = func_02026478((void *)(((struct Obj12421 *)d)->f4));
    s = (int)func_020127D0((u8 *)h, 0);
    func_021861F4(c, func_021583EC((void *)h, a));
    func_02082D44(c, (void *)s, 0x1E8);
    func_02012800((u8 *)h, c);
    d[0x90C] = 1;
}




int func_02174734(char *p, int b, void *c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x225) == 1) {
        return 0;
    }
    func_02082D44(c, p + 0x460, 0x1E8);
    return func_0203D4D0((int)func_020399A8(), b & 0xFF, 0x225, 0x1E8, (u32)c, 0, 0, 1);
}



void func_02174798(int a, int b, int c, u8 *p)
{
    func_02161FF0(p + 0x35c, c);
}



int func_021747A8(void *a, int b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), b, 0x226, 8, (u32)a, 0, 0, 0);
}



void func_021747E0(int a, int b, int c, u8 *p)
{
    func_02162008(p + 0x35c, (u16)a);
}



int func_021747F4(int a, int b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), b, 0x227, 8, a, 0, 0, 0);
}



/*
 * Hidden function (round 5): copies the four bytes at c to the 4-byte record
 * number a at offset 0x8d4 of p. The const source lets both byte pairs load
 * before their stores.
 */
void func_0217482C(int a, int b, const u8 *c, u8 *p)
{
    u8 *q = p + a * 4;
    q[0x8d4] = c[0];
    q[0x8d5] = c[1];
    q[0x8d6] = c[2];
    q[0x8d7] = c[3];
}



int func_02174854(unsigned char *p, int b, int c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    ((F8 *)(p + 0x8F8))->b = 0;
    return func_0203D3F8((u32)func_020399A8(), b, 0x228, 4, c, 0, 0, 0);
}



void func_02174898(int a, int b, B54 *c, u8 *p)
{
    *(B54 *)(p + 0x82c) = *c;
    ((F_02174854 *)p)->f1 = 1;
    ((F_02174854 *)p)->f2 = 0;
}




int func_021748CC(char *p, int a)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), a, 0x229, 0x54, (u32)(p + 0x880), 0, 0, 0);
}





void func_02174908(int a, int b, int c, unsigned char *d)
{
    int h;

    h = func_02026478((void *)(((struct Obj09346 *)d)->f4));
    if (a != func_0203D1A4((struct Link *)func_020399A8()) && ((unsigned)(((struct Obj09346 *)d)->f86 << 29) >> 29) == a) {
        if (func_02013D9C(func_02012AC8(func_020127A4((struct SaveBlock *)h))) != 0) {
            d[0x8F8] |= 4;
        }
    }
}




/*
 * lever: caller consumes the live r0 result of legacy void forwarders.
 */
u32 func_02174954(u32 p)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0x22a, 4, p);
}





/*
 * Addresses are Black-image addresses.
 */
void func_02174978(u8 *s)
{
    int h;
    int n;
    void *w;

    h = func_02026478((void *)(((struct Obj00269 *)s)->f4));
    if (func_0203D378() == 1) {
        n = func_0203D1B4();
        if (n > s[0x902]) {
            s[0x902] = n;
            s[0x903] = 1;
            func_02012B4C((struct BigObj *)h, s[0x902]);
        }
    }
    if (s[0x903] == 1 && func_02173758((int)s, s[0x902]) == 1) {
        s[0x903] = 0;
    }
    func_02174AE0(s);
    func_0217546C(s);
    if (s[0x8fe] == 1) {
        func_02174E3C(s);
        func_02173828((char *)s);
    }
    func_02174B2C(s);
    func_02174B7C(s);
    func_02174BC4(s);
    if (s[0x93e] == 1 && func_021743B4((char *)s) == 1) {
        s[0x93e] = 0;
    }
    func_021757C4((Ctx *)s, (Work *)(s + 0x1ac));
    if (s[0x907] == 1 && func_02174374((int *)s) == 1) {
        s[0x907] = 0;
    }
    func_02174C38(s);
    func_02174CCC(s);
    func_02174DF4(s);
    if (func_021752DC(s) == 1) {
        s[0x900] = 1;
    }
    if (s[0x900] == 1 && ((Bits *)(s + 0x904))->b1 == 0 && func_02173984((char *)s, (int)(s + 0x70)) == 1) {
        s[0x900] = 0;
    }
    if (func_02012E40((const u8 *)h) == 0 && ((Bits *)(s + 0x8f8))->b0 == 1) {
        w = func_0200BE48(func_02012EBC((struct Big *)h));
        if (func_021756D0(((struct Obj00269 *)s)->f8F4) == 0) {
            ((struct Obj00269 *)s)->f8F4 = 0x11;
        }
        func_0200BE84(w, s + 0x8e4);
        ((Bits *)(s + 0x8f8))->b0 = 0;
    }
}





void func_02174AE0(unsigned char *p)
{
    int r;

    r = func_02014484((struct Sub02014444Obj *)func_02012B38((const struct BigObj *)func_02026478((void *)(((struct Obj09347 *)p)->f4))));
    switch (r) {
    case 0:
        if (((unsigned)(((struct Obj09347 *)p)->f86 << 17) >> 26) == 2) {
            func_02174E14(p, 0);
        }
        break;
    case 1:
        if (((unsigned)(((struct Obj09347 *)p)->f86 << 17) >> 26) == 0) {
            func_02174E14(p, 2);
        }
        break;
    }
}





void func_02174B2C(unsigned char *p)
{
    int i;

    if (p[0x8FF] != 0) {
        p[0x8FF]--;
        return;
    }
    for (i = 0; i < p[0x902]; i++) {
        if ((int)func_0203D1C0((unsigned char)i) == 1 && !(p[0x8FB] & (1 << i))) {
            func_021737A8();
            p[0x8FF] = 30;
            return;
        }
    }
}





void func_02174B7C(unsigned char *p)
{
    int i;

    if (func_0203D378() != 0) {
        for (i = 0; i < p[0x902]; i++) {
            if ((int)func_0203D1C0((unsigned char)i) == 0 && (p[0x8FB] & (1 << i))) {
                func_021738E4(p, i);
            }
        }
    }
}





void func_02174BC4(unsigned char *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p[i + 0x945] != 0) {
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
                if (func_02173AE0((int)p, i, 2, p[i + 0x945]) == 1) {
                    p[i + 0x945] = 0;
                }
            } else {
                p[i + 0x945] = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (p[i + 0x948] != 0) {
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
                if (func_02173B44(p, i, p[i + 0x948]) == 1) {
                    p[i + 0x948] = 0;
                }
            } else {
                p[i + 0x948] = 0;
            }
        }
    }
}




/*
 * func_02026478 returns the argument consumed by func_020127C4.
 */
void func_02174C38(unsigned char *p)
{
    int b1[2];
    int b2[2];
    unsigned char i;
    int h;
    h = func_02026478((void *)(((struct Obj07329 *)p)->f4));
    if (p[0x908] != 0) {
        if (func_02174734((char *)p, p[0x908], (void *)func_020127C4((void *)h)) == 1) {
            p[0x908] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (func_02162024((char *)(p + 0x35C), i, b1) == 1) {
            if (func_021747A8(b1, i) == 1) {
                func_02162038((char *)(p + 0x35C), i);
            }
        }
    }
    if (func_0216202C((char *)(p + 0x35C), b2, &i) == 1) {
        if (func_021747F4((int)b2, i) == 1) {
            func_02162040((char *)(p + 0x35C));
        }
    }
}





/*
 * The guard's ldrb lands in r1 because func_02026478's result is live in r0:
 * it is func_020127C4's argument (the r0 at that call is never re-set).
 */
void func_02174CCC(unsigned char *p)
{
    unsigned char i;
    unsigned char *e;
    unsigned char *q;
    int h;

    h = func_02026478((void *)(((struct Obj04951 *)p)->f4));
    if (p[0x908] != 0) {
        if (func_02174734((char *)p, p[0x908], (void *)func_020127C4((void *)h)) == 1) {
            p[0x908] = 0;
        }
    }
    e = p + 0x8D4;
    for (i = 0; i < 3; i++) {
        q = p + i * 4;
        if (q[0x8D5] == 1) {
            func_02174D5C((int *)p, e + i * 4);
            if (func_021748CC((char *)p, i) == 1) {
                q[0x8D5] = 0;
            }
        }
    }
    if (p[0x8E1] == 1) {
        if (func_02174954((u32)(p + 0x8E0)) == 1) {
            p[0x8E1] = 0;
        }
    }
}





void func_02174D5C(int *p, const u8 *q)
{
    Blk *b;
    void *x;
    int t;
    u8 buf[4];

    b = (Blk *)((u8 *)p + 0x880);
    x = func_0200E0B0(func_02012EBC((struct Big *)func_02026478((void *)p[1])));
    func_0216749C(x, (struct Entry32 *)b, 0x14, q[0], buf);
    b->a = buf[0];
    b->b = func_021673C4(x);
    b->c = func_021673A8(x);
    t = func_02039338();
    b->d = t;
    b->e = q[0];
}




void func_02174DF4(u8 *p)
{
    if (p[0x924] != 0) {
        if (func_02173CB0((int *)p, p[0x924]) == 1) {
            p[0x924] = 0;
        }
    }
}




void func_02174E14(u8 *p, int a)
{
    ((F86_02174E14 *)(p + 0x86))->state = (u16)a;
    p[0x900] = 1;
}





void func_02174E3C(u8 *p)
{
    int v;

    v = func_02026478((void *)(((struct Obj09349 *)p)->f4));
    func_02082D44(func_02012944((void *)v), p + 0x160, func_02008468());
    func_02082D44(func_020127B8((void *)v), p + 0x180, 0x10);
    func_021752DC(p);
    if (((F86_02174E3C *)(p + 0x86))->x == 0x80) {
        func_02175710(p, func_02039338());
    }
    *(Ent_021748CC *)(p + 0x190) = *(Ent_021748CC *)(p + 0x70);
}



/*
 * (ldr r3,=target; movs r2,#0x20; bx r3), no witness outside the range.
 * Verified C for the leaf: void func_02008494(u8 *a, int b) style thunk;
 * needs Ilias's arm9 leaf filed to promote this to EXACT.
 */
void func_02174EAC(u8 *p, int idx, u8 *q)
{
    int x;
    int ctx;
    int a;
    int flag;

    ctx = func_02026478((void *)(((struct Obj00269 *)p)->f4));
    flag = 0;
    a = (int)func_02012950((struct Sub24 *)ctx, idx);
    if (p[0x8FB] & (1 << idx)) {
        x = func_02008530((const struct Sub0200852CObj *)a);
        if (x == func_02008530((const struct Sub0200852CObj *)q)) {
            goto skip;
        }
    }
    flag = 1;
skip:
    func_02008494(q, (void *)a);
    func_02082D44(q + 0x20, func_020127AC((struct SaveBlock *)ctx, idx), 0x10);
    func_02012BA4((struct BigObj *)ctx, idx, ((Q *)(q + 0x4A))->hi);
    func_02174F54(p, idx, (const Ent_02174F54 *)(q + 0x30), 1);
    p[0x8FB] |= (u8)(1 << idx);
    if (flag == 1 && idx != func_02039338()) {
        func_020266D4(((struct Obj00269 *)p)->f4, idx);
    }
}




void func_02174F54(u8 *p, int idx, const Ent_02174F54 *src, int arg)
{
    Ent_02174F54 *e;
    u32 saved;

    e = (Ent_02174F54 *)(p + 0x8C) + idx;
    saved = e->f0;
    func_02082D44(src, e, 0x1C);
    e->f0 = saved;
    e->hi = (u8)src->f0;
    if (src->f0 == 1) {
        e->f0 = 1;
    }
    func_020264B4((void *)(((struct Obj00269 *)p)->f4), idx, e->f14, (u8)e->a, e->lo, arg);
    if (idx != func_02039338()) {
        *((Cp *)(p + 0xE0) + idx) = *(Cp *)e;
        func_021751D4(p, ((struct Obj00269 *)p)->f84, ((struct Obj00269 *)p)->f74, e);
    }
    p[0x927] |= (u8)(1 << idx);
}





void func_02175004(u8 *p)
{
    u8 i;

    if (func_02012E40((const u8 *)func_02026478((void *)(((struct Obj01838 *)p)->f4))) == 1) {
        return;
    }
    if (((Fl_02174F54 *)(p + 0x904))->b1 == 1) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (p[0x927] & (1 << i)) {
            func_02175060(p, i);
            p[0x927] ^= (u8)(1 << i);
        }
    }
}





static inline int func_02175060_check(Entry *e, Entry *me)
{
    if (e->hi == 1) {
        return 1;
    }
    if (e->f12 != 0 && e->f12 != 1) {
        return 1;
    }
    if (func_02013D5C(e->f14) == 1 && func_02013D5C(me->f14) == 1) {
        return 0;
    }
    if (e->a == me->a) {
        if (func_02013D9C(e->f14) == 1 && func_02013D9C(me->f14) == 1) {
            if (e->b == me->b) {
                return 0;
            }
            return 1;
        }
        if (func_02013E90(me->f14, e->f14) == 1) {
            return 0;
        }
        return 1;
    }
    return 1;
}





void func_02175060(u8 *p, int idx)
{
    Entry *e;
    int r;

    e = (Entry *)(p + 0x8c) + idx;
    if (idx != func_02039338()) {
        Entry *me = (Entry *)(p + 0x70);
        e->f0 = func_02175060_check(e, me);
    }
    if (func_021677E4((void *)(((struct Obj05913 *)p)->f8), idx) == 1) {
        r = func_02175598((u8 *)e, func_021583EC((void *)func_02026478((void *)(((struct Obj05913 *)p)->f4)), idx));
        if (r != func_02167810((struct Work *)(((struct Obj05913 *)p)->f8), idx)) {
            func_02167658(((struct Obj05913 *)p)->f8, idx);
            if (e->f18 != 0) {
                func_021675D0((struct Work *)(((struct Obj05913 *)p)->f8), idx, r, (struct Src *)e);
            }
        }
    }
}





int func_02175144(u16 v, u8 *out)
{
    int i;
    u8 k;

    ((struct Obj02670 *)out)->f0 = v;
    for (i = 0; i < 8; i++) {
        if (v == d_02176AA0[i].a) {
            k = 0;
        } else if (v == d_02176AA0[i].b) {
            k = 1;
        } else {
            continue;
        }
        out[2] = k;
        out[3] = i;
        return 1;
    }
    out[3] = 0xff;
    return 0;
}




int func_02175184(u8 *a, u8 *b)
{
    if (((struct Obj02670 *)a)->f0 == ((struct Obj02670 *)b)->f0) return 0;
    if (a[2] != b[2] && a[3] == b[3]) return 1;
    return 2;
}




int func_021751A8(u8 *p, int index)
{
    int value;
    if (index >= p[0x902]) return 0;
    value = index - func_02012B58((const struct BigObj *)func_02026478((void *)(((struct Obj07330 *)p)->f4)));
    if (value < 0) value += p[0x902];
    return value;
}





void func_021751D4(u8 *p, u16 a, int b, Ent_02174F54 *c)
{
    u8 x[4];
    u8 y[4];
    int r;
    int w;
    int k;
    int n;

    func_02175144(a, x);
    func_02175144(c->f14, y);
    r = func_02175184(x, y);
    switch (r) {
    case 1:
        break;
    case 2:
        break;
    case 0:
        if (func_02013D5C(a) != 0) {
            w = c->f4 % 0x400000;
            k = func_021751A8(p, c->a);
            n = p[0x902];
            if (k == n - 1 && w > 0x200000 && b < 0x200000) {
                c->f4 = w - 0x400000;
            } else if (k == 0 && w < 0x200000 && b > (n << 22) - 0x200000) {
                c->f4 = w + (n << 22);
            } else {
                c->f4 = w + (k << 22);
            }
        }
        break;
    }
}





void func_02175274(u8 *p, int arg)
{
    u8 *arr;
    u8 *h;
    int n;
    int i;
    u8 *e;

    n = func_02012B58((const struct BigObj *)func_02026478((void *)(((struct Obj12425 *)p)->f4)));
    h = p + 0x70;
    i = 0;
    arr = p + 0x8C;
    for (; i < 3; i++) {
        if ((p[0x8FB] & (1 << i)) && i != n) {
            e = arr + i * 0x1C;
            *(C12 *)(e + 4) = *(C12 *)(p + 0xE4 + i * 0x14);
            func_021751D4(p, ((struct Obj19182 *)h)->f14, arg, (struct Ent_02174F54 *)e);
        }
    }
}





int func_021752DC(u8 *p)
{
    int ctx;
    int v;
    int r;
    int k;
    Hd *h;

    ctx = func_02026478((void *)(((struct Obj09349 *)p)->f4));
    v = func_02012AC8(func_020127A4((struct SaveBlock *)ctx));
    h = (Hd *)(p + 0x70);
    r = func_0216786C((struct Work *)(((struct Obj09349 *)p)->f8), (struct Report *)h);
    if (h->f14 != v) {
        h->f14 = v;
        r = 1;
    }
    if (h->x != func_02012FB0(ctx)) {
        h->x = func_02012FB0(ctx);
        r = 1;
    }
    k = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    if (h->top != k) {
        h->top = k;
        r = 1;
    }
    return r;
}





/*
 * Unlabelled Thumb leaf, seeded so that ov018 func_0217FE38 has a witness:
 * clears the four bytes at +0x15C through sub_02082BCC (fill, n bytes).
 *
 * Addresses are Black-image addresses.
 */
void func_02175368(char *p)
{
    sub_02082BCC(p + 0x15C, 0, 4);
}




/*
 * Unlabelled Thumb leaf, the follower of func_02175368 (same +0x15C field):
 * returns the field's address when its first byte is 1, else null.
 * Labelled so that func_02175368's extent ends at its own pool.
 *
 * Addresses are Black-image addresses.
 */
unsigned char *func_0217537C(unsigned char *p)
{
    if (p[0x15C] == 1) {
        return p + 0x15C;
    }
    return 0;
}




/*
 * extent: two zero alignment bytes at 0x021753B6 precede the owned 021753B8 function.
 */
void func_0217538C(u8 *p, int a)
{
    MI_CpuFill8(p + 0x154, 0, 8);
    p[0x154] = a;
    p[0x155] = 4;
    p[0x158] = 0;
    func_021753B8(p);
}




void func_021753B8(u8 *p)
{
    p[0x944]++;
    p[0x159] = p[0x944];
}





int func_021753D0(u8 *p, int i, u8 v)
{
    if (!(p[0x8FB] & (1 << i))) {
        (p + i)[0x945] = v;
        return 0;
    }
    if (((F86 *)(p + 0x86))->x == 0) {
        if (p[0x154] == 4 && p[0x158] == 0 && func_020120D8((char *)((struct Obj03548 *)p)->f0) == 0) {
            p[0x154] = i;
            p[0x156] = 1;
            p[0x158] = v;
            p[0x159] = v;
            func_0217544C(p);
            return 1;
        }
        (p + i)[0x945] = v;
    } else {
        (p + i)[0x945] = v;
    }
    return 0;
}




void func_0217544C(u8 *p) { p[0x8F8] |= 0x10; }




/*
 * lever: bitfield clear emits bics; byte mask emits ands with 0xEF.
 */
void func_0217545C(u8 *p) { ((Flags_0217545C *)(p + 0x8F8))->flag = 0; }





void func_0217546C(u8 *p)
{
    u8 buf[4];
    u8 *q;
    int i;

    if (func_021754B4(p, (int *)buf) == 1 && func_020120D8((char *)((struct Obj00566 *)p)->f0) == 1) {
        q = p + 0x945;
        i = p[0x154];
        if (q[i] == 0) {
            q[i] = p[0x158];
        }
        func_0217538C(p, 4);
        func_0217545C(p);
    }
}




int func_021754B4(u8 *p, int *out)
{
    int value;
    if (p == 0 || ((struct Obj07331 *)p)->f8 == 0) return 0;
    value = p[0x154];
    if (value != 4 && ((Flags_021754B4 *)(p + 0x8F8))->flag == 1) {
        *out = value;
        return 1;
    }
    return 0;
}




void func_021754E8(u8 *p, int a, int b, int c)
{
    if (p[0x154] == a && p[0x158] == c) {
        p[0x155] = a;
        p[0x157] = b;
    }
}





void func_02175508(int a, int b, int c)
{
    func_021754E8((u8 *)a, b, 3, c);
}





/*
 * note:     unlabelled leaf (push {r3,r4}, no lr); callers func_0218123C and
 *           func_02181584 in ov018. Its follower 0x0217553C is also an
 *           unlabelled leaf.
 */
int func_02175514(u8 *p)
{
    int r;

    if (p[0x155] != 4) {
        r = p[0x157];
        if (r != 0) {
            p[0x157] = 0;
            return r;
        }
    }
    return 0;
}





/*
 * Unlabelled leaf (no lr save): clears the byte at +0x157.
 */
void func_0217553C(u8 *p)
{
    p[0x157] = 0;
}





void func_02175548(u32 a, u16 *p1, u8 *p2, u8 *p3)
{
    u32 x;
    u32 i;
    int r;

    x = func_02008530((const struct Sub0200852CObj *)a);
    r = func_02008550((const struct Sub0200852CObj *)a);
    i = ((x >> 16) + (u16)x) & 3;
    if (r == 0) {
        *p1 = tbl_02176A90[i];
        *p2 = 3;
        *p3 = 0;
    } else {
        *p1 = tbl_02176A98[i];
        *p2 = 4;
        *p3 = 1;
    }
}





u16 func_02175598(u8 *o, u32 id)
{
    struct { u8 x; u8 y; u16 c; } s;
    u16 h;

    h = ((struct Obj07332 *)o)->f18;
    if (h == 0) {
        if (o[0x12] == 1) {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 2 : 5;
        } else {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 1 : 4;
        }
    } else if (h == 0xFFFF) {
        func_02175548(id, &s.c, &s.y, &s.x);
    } else {
        s.c = h;
        if (func_021756B0(s.c) == 0) {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 10 : 14;
        }
    }
    if ((s.c >= 0xdf && s.c < 0x1000) || s.c >= 0x1236) {
        s.c = 10;
    }
    return s.c;
}




/*
 * extent: two zero alignment bytes at 0x02175646 precede existing 02175648 code.
 */
int func_02175628(void)
{
    if (func_0200FB24() != 0) return 0;
    if (func_0203D1B4() > 1) return 1;
    return 0;
}





void func_02175648(void *sv, Out *o)
{
    void *q;

    q = func_0200BE48(func_02012EBC(sv));
    MI_CpuFill8(o, 0, 0x10);
    o->f00 = func_0200BF70(q);
    if (func_02012B70(sv) == 1) {
        o->f04 = func_0200BFA4(q, (void *)func_02012FCC((int)sv), 2);
    } else {
        o->f04 = func_0200BF94(q);
    }
    func_0200BF54(q, o->f0c, 2);
    o->f0e = 1;
}





u8 func_021756A4(char *p)
{
    return p[0x35a];
}




/*
 * A ternary loop condition keeps the unrotated entry branch.
 */
int func_021756B0(int value)
{
    unsigned int i;
    for (i = 0; (i < 162) ? 1 : 0; i++) if (value == d_02176B08[i]) return 1;
    return 0;
}




/*
 * The 32-byte follower at 021756F0 already has its own matched shard.
 * A ternary loop condition preserves the branch to the bottom test.
 */
int func_021756D0(u32 x)
{
    u32 i;
    for (i = 0; (i < 0x1c) ? 1 : 0; i++) {
        if (x == tbl_02176AD0[i]) {
            return 1;
        }
    }
    return 0;
}





/*
 * Unlabelled leaf: sets bit 6 of the byte at +0x93f from the low bit of v.
 */
void func_021756F0(u8 *o, u32 v)
{
    ((Flags_021756F0 *)(o + 0x93f))->f = (u8)v;
}





/*
 * func_0217574C is an unlabelled leaf (bit 1 of the byte at +0x904).
 */
void func_02175710(u8 *o, u32 v)
{
    void *p;

    p = func_020120F4(((struct Obj00269 *)o)->f0);
    ((Lo3 *)(o + 0x86))->v = v;
    func_02012B8C(p, v);
    func_02161FEC((char *)(o + 0x35c), (u8)v);
}





void func_0217574C(u8 *o, u32 v)
{
    ((Flags_02175710 *)(o + 0x904))->f = (u8)v;
}




void func_0217576C(u8 *p)
{
    int i;
    MI_CpuFill8(p, 0, 0x1A8);
    p[0xA4] = 4;
    func_02175EE8(p + 0x90);
    p[0xD8] = 4;
    for (i = 0; i < 3; i++) p[0xE0 + i] = 4;
    func_021757A8(p);
}




/*
 * extent: two zero alignment bytes at 0x021757C2 precede existing 021757C4 code.
 */
void func_021757A8(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) p[i * 0x28 + 0x10] = 0;
}





void func_021757C4(Ctx *c, Work *w)
{
    int x;

    if (func_0203D378() == 1 && func_02175B14((u8 *)w) == 1) {
        if (w->bD8 == 4) {
            if (w->hA8 != 0) {
                if (w->b19C == 0 && func_02175894((u8 *)w) > w->hA8) {
                    w->b19C = 1;
                }
            } else if (w->f1 == 1 && func_02175894((u8 *)w) > w->hAA) {
                x = func_02026478((void *)c->w4);
                if (w->bE3 == 0) {
                    func_02175D34(c, w, func_02012B58((const struct BigObj *)x));
                }
            }
        } else if (w->f1 == 1 && func_02175894((u8 *)w) > w->hAA) {
            w->f4 = 1;
        }
    }
    func_02176158((int)c, (u8 *)w);
    func_02176194(c, w);
    func_02175A34(c, (u8 *)w);
    func_02175AE8((int)c, (u8 *)w);
}




int func_02175894(u8 *p)
{
    u32 now = func_0203F4FC();
    u32 stamp = ((struct Obj19190 *)p)->f190;
    if (now < stamp) now += 86400;
    return now - stamp;
}




int func_021758B4(u8 *p)
{
    int limit = ((struct Obj19191 *)p)->fAA;
    int n = limit - func_02175894(p);
    if (n < 0) n = 0;
    return n;
}





int func_021758C8(u8 *o)
{
    int h;
    int v;

    if (func_02175B14(o) == 1 && o[0xd8] == 4) {
        h = ((struct Obj00567 *)o)->fA8;
        if (h != 0 || ((Flags_021758C8 *)(o + 0x1a5))->f == 0) {
            v = h - func_02175894(o);
        } else {
            v = func_021758B4(o);
        }
        if (v < 0) {
            return 0;
        }
        return v;
    }
    return 0;
}





/*
 * Three one-byte flag setters at fixed offsets.
 */
void func_02175914(int a, int b)
{
    *(unsigned char *)(a + b + 0x194) = 1;
}





void func_02175920(int a)
{
    ((struct Obj12430 *)a)->f19A = 1;
}





void func_0217592C(int a)
{
    ((struct Obj12431 *)a)->f19B = 1;
}




void func_02175938(u8 *p, const u16 *src, int index)
{
    u16 *dst = (u16 *)(p + index * 40);
    unsigned n;
    if (*((u8 *)dst + 16) != 1) {
        n = 20;
        do { *dst++ = *src++; } while (--n);
    }
}





int func_02175954(void *unused, u8 *o, Rec *src)
{
    Rec *dst;
    int r;

    dst = (Rec *)(o + 0x78);
    r = 0;
    if (src->a > 0x14 || src->b > 0xb4) {
        return 0;
    }
    if (o[0x1a1] == 0 && src->f2c != 4) {
        r = 1;
        o[0x1a1] = r;
    }
    if (dst->f2c != 4) {
        return r;
    }
    *dst = *src;
    return r;
}




void func_021759B0(u8 *p)
{
    u8 *q = func_02175B34(p);
    if (q != 0) ((struct Obj19193 *)q)->f30 = 0;
}




static inline void SetBits(State *p, u8 bit)
{
    p->active |= bit;
    p->pending |= bit;
}




/*
 * lever: u8 mask conversion through SetBits inline preserves the original
 * field load before the truncation finishes; open-coded byte locals differ.
 */
void func_021759C0(State *p, u8 index)
{
    if (p->active == 0) p->stamp = func_0203F4FC();
    SetBits(p, 1 << index);
}




/*
 * extent: follower 0x02175A24 already filed separately.
 */
void func_021759F8(u8 *p, int n)
{
    p[0x1A5] |= 2;
    ((struct Obj09352 *)p)->fAA = n;
    if (func_0203D378() == 0) ((struct Obj09352 *)p)->f190 = func_0203F4FC();
}





/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C4D0): bit 1 of the
 * flag byte at +0x1A5.
 */
int func_02175A24(u8 *p)
{
    return ((Flags_02175A24 *)(p + 0x1A5))->b1;
}





void func_02175A34(void *a, u8 *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (b[0x194 + i] == 1 && func_02173DA0((int)a, (int)b, i) == 1) {
            b[0x194 + i] = 0;
        }
    }
    if (b[0x19a] == 1 && func_02173EEC(a, (char *)b) == 1) {
        b[0x19a] = 0;
    }
    if (b[0x19b] == 1 && func_021741E8(a, (char *)b) == 1) {
        b[0x19b] = 0;
    }
    if (b[0x19c] == 1 && func_02173F74((int)a, b) == 1) {
        b[0x19c] = 2;
    }
    if (b[0x19f] != 0 && func_021742EC(b[0x19f]) == 1) {
        b[0x19f] = 0;
    }
    if (b[0x1a0] != 0 && func_021742A8(b[0x1a0]) == 1) {
        b[0x1a0] = 0;
    }
}




/*
 * prototype: func_02173FF4 trailing input omitted: full matched body neither
 * reads nor forwards d; original caller supplies no r3 value.
 */
void func_02175AE8(int ctx, u8 *p)
{
    u8 mask = p[0x19E];
    if (mask != 0) {
        if (func_02173FF4(ctx, func_021758B4(p), mask) == 1) p[0x19E] = 0;
    }
}




int func_02175B14(u8 *p)
{
    if (p[0xA4] == 4 || p[0x1A1] == 0) return 0;
    return 1;
}




/*
 * extent: two zero alignment bytes follow the compiled return.
 */
u8 *func_02175B34(u8 *p)
{
    if (func_02175B14(p) == 0) p = 0;
    else p += 0x78;
    return p;
}





void func_02175B4C(u8 *a, u8 *b)
{
    if (func_02175B14(b) == 1) {
        ((Fl_02175184 *)(b + 0x1a5))->x = 1;
        ((Fl_02175184 *)(b + 0x1a5))->y = 0;
        a[0x8a] |= 0x20;
        a[0x900] = 1;
    }
}




int func_02175B8C(u8 *p)
{
    if (func_02175B14(p) == 1) return ((Flags_02175B8C *)(p + 0x1A5))->bit;
    return 0;
}




/*
 * extent: follower 0x02175BBC already filed separately.
 */
void func_02175BAC(u8 *p)
{
    p[0x1A5] |= 8;
}





/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov018 func_0217BDE0: bit 3 of the byte
 * at +0x1A5.
 */
int func_02175BBC(u8 *p)
{
    return ((Fb *)(p + 0x1A5))->b;
}




u8 *func_02175BCC(u8 *p)
{
    if (func_02175DA8(p) == 0) p = 0;
    else p += 0xAC;
    return p;
}





/*
 * func_02175C04 is an unlabelled leaf (sets one bit in a byte at +0x19f or +0x1a0).
 */
int func_02175BE4(void *a)
{
    if (func_02175B8C(a) == 1 || func_02175BCC(a) != 0) {
        return 1;
    }
    return 0;
}





void func_02175C04(u8 *o, u32 bit)
{
    if (o[0xe0] == 4) {
        o[0x19f] |= (u8)(1 << bit);
    } else {
        o[0x1a0] |= (u8)(1 << bit);
    }
}
