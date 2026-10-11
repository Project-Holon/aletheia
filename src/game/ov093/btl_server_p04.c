/*
 * file:     btl_server_p04.c
 * unit:     yes
 * function: func_021BDB88, func_021BDBB8, func_021BDBEC, func_021BDC0C, func_021BDC2C, func_021BDC58, func_021BDC78, func_021BDC98, func_021BDD00, func_021BDD7C, func_021BDE18, func_021BDE48, func_021BDE98, func_021BE3A8, func_021BE400, func_021BE518, func_021BE52C, func_021BE550, func_021BE620, func_021BE66C, func_021BE6A8, func_021BE6EC, func_021BE7E4, func_021BE878, func_021BE8C4, func_021BE8F4, func_021BE924, func_021BE95C, func_021BE994, func_021BE9D0, func_021BEA14, func_021BEA60, func_021BEAB4, func_021BEB14, func_021BEBD8, func_021BEC08, func_021BEC2C, func_021BEC58, func_021BF04C, func_021BF0E4, func_021BF168, func_021BF1B4, func_021BF244, func_021BF27C, func_021BF2B4, func_021BF2EC, func_021BF324, func_021BF3D8, func_021BF4AC, func_021BF6E8, func_021BF78C, func_021BF83C, func_021BF8D4
 * address:  0x021BDB88
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D70FC 0x021D70FC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E28  0x021B8E28  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021C6190  0x021C6190  thumb  ov093
 *   func_021BD0C0  0x021BD0C0  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 *   func_021C5108  0x021C5108  thumb  ov093
 *   func_021D64F0  0x021D64F0  thumb  ov093
 *   func_021BDE08  0x021BDE08  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
 *   func_021D5C08 0x021D5C08 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021C001C 0x021C001C thumb ov093
 *   func_021C62D8 0x021C62D8 thumb ov093
 *   func_021C5604 0x021C5604 thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   func_021C07AC 0x021C07AC thumb ov093
 *   func_021C0450 0x021C0450 thumb ov093
 *   func_021BE338 0x021BE338 thumb ov093
 *   func_021BE348 0x021BE348 thumb ov093
 *   func_021BE358 0x021BE358 thumb ov093
 *   func_021BE368 0x021BE368 thumb ov093
 *   func_021BE378 0x021BE378 thumb ov093
 *   func_021BE388 0x021BE388 thumb ov093
 *   func_021BE398 0x021BE398 thumb ov093
 *   func_021C6458 0x021C6458 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021C024C 0x021C024C thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021BFE60 0x021BFE60 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021BFF60 0x021BFF60 thumb ov093
 *   func_021E0394 0x021E0394 thumb ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021D7394 0x021D7394 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D73D4 0x021D73D4 thumb ov093
 *   func_021C0520 0x021C0520 thumb ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   d_021EFDB8 0x021EFDB8 data a2
 *   func_021D6E74 0x021D6E74 thumb ov093
 *   func_021BCB14 0x021BCB14 thumb ov093
 *   func_021BCB68 0x021BCB68 thumb ov093
 *   func_021D6E40 0x021D6E40 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021BD148 0x021BD148 thumb ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021BEB04 0x021BEB04 thumb ov093
 *   func_021BEBB8  0x021BEBB8  thumb  ov093
 *   func_021BEBC8  0x021BEBC8  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_0201C1BC 0x0201C1BC thumb
 *   func_021BFC08 0x021BFC08 thumb ov093
 *   func_021BEFEC 0x021BEFEC thumb ov093
 *   func_021BEFFC 0x021BEFFC thumb ov093
 *   func_021BF00C 0x021BF00C thumb ov093
 *   func_021BF01C 0x021BF01C thumb ov093
 *   func_021BF02C 0x021BF02C thumb ov093
 *   func_021BF03C 0x021BF03C thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021BD200 0x021BD200 thumb ov093
 *   func_021C65A8 0x021C65A8 thumb ov093
 *   func_021BFBD0 0x021BFBD0 thumb ov093
 *   func_021CC8A0 0x021CC8A0 thumb ov093
 *   func_021C091C 0x021C091C thumb ov093
 *   func_021C2DC4 0x021C2DC4 thumb ov093
 *   func_021C2488 0x021C2488 thumb ov093
 *   func_021C3184 0x021C3184 thumb ov093
 *   func_021C3438 0x021C3438 thumb ov093
 *   func_021C376C 0x021C376C thumb ov093
 *   func_021C3274 0x021C3274 thumb ov093
 *   func_021C3AA8 0x021C3AA8 thumb ov093
 *   func_021C3D08 0x021C3D08 thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021BF0A4  0x021BF0A4  thumb  ov093
 *   func_021BF0B4  0x021BF0B4  thumb  ov093
 *   func_021BF0C4  0x021BF0C4  thumb  ov093
 *   func_021BF0D4  0x021BF0D4  thumb  ov093
 *   func_021BFA00  0x021BFA00  thumb  ov093
 *   func_021C572C  0x021C572C  thumb  ov093
 *   func_021BF138  0x021BF138  thumb  ov093
 *   func_021BF148  0x021BF148  thumb  ov093
 *   func_021BF158  0x021BF158  thumb  ov093
 *   func_021BF204  0x021BF204  thumb  ov093
 *   func_021BF214  0x021BF214  thumb  ov093
 *   func_021BF224  0x021BF224  thumb  ov093
 *   func_021BF234  0x021BF234  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021BF3B8  0x021BF3B8  thumb  ov093
 *   func_021BF3C8  0x021BF3C8  thumb  ov093
 *   func_021D62D8  0x021D62D8  thumb  ov093
 *   func_021CC8B0  0x021CC8B0  thumb  ov093
 *   func_021BF46C  0x021BF46C  thumb  ov093
 *   func_021BF47C  0x021BF47C  thumb  ov093
 *   func_021BF48C  0x021BF48C  thumb  ov093
 *   func_021BF49C  0x021BF49C  thumb  ov093
 *   func_021C6E3C  0x021C6E3C  thumb  ov093
 *   func_021C7C24  0x021C7C24  thumb  ov093
 *   func_021BF5E8 0x021BF5E8 thumb ov093
 *   func_021BF5F8 0x021BF5F8 thumb ov093
 *   func_021BF608 0x021BF608 thumb ov093
 *   func_021BF618 0x021BF618 thumb ov093
 *   func_021BF628 0x021BF628 thumb ov093
 *   func_021BF638 0x021BF638 thumb ov093
 *   func_021BF648 0x021BF648 thumb ov093
 *   func_021BF658 0x021BF658 thumb ov093
 *   func_021BF668 0x021BF668 thumb ov093
 *   func_021BF678 0x021BF678 thumb ov093
 *   func_021BF688 0x021BF688 thumb ov093
 *   func_021BF698 0x021BF698 thumb ov093
 *   func_021BF6A8 0x021BF6A8 thumb ov093
 *   func_021BF6B8 0x021BF6B8 thumb ov093
 *   func_021BF6C8 0x021BF6C8 thumb ov093
 *   func_021BF6D8 0x021BF6D8 thumb ov093
 *   func_021C6668 0x021C6668 thumb ov093
 *   func_021C8828  0x021C8828  thumb  ov093
 *   func_021CC8C0  0x021CC8C0  thumb  ov093
 *   func_021BF894  0x021BF894  thumb  ov093
 *   func_021BF8A4  0x021BF8A4  thumb  ov093
 *   func_021BF8B4  0x021BF8B4  thumb  ov093
 *   func_021BF8C4  0x021BF8C4  thumb  ov093
 *   func_021C6948  0x021C6948  thumb  ov093
 *   func_021BF944  0x021BF944  thumb  ov093
 *   func_021BF954  0x021BF954  thumb  ov093
 *   func_021BF964  0x021BF964  thumb  ov093
 *   func_021BF974  0x021BF974  thumb  ov093
 *   func_021BF984  0x021BF984  thumb  ov093
 *   func_021BF994  0x021BF994  thumb  ov093
 *   func_021BF9A4  0x021BF9A4  thumb  ov093
 *   func_021BFA60  0x021BFA60  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09961.h"
#include "../../matched/include/Obj13311.h"
#include "../../matched/include/Obj21052.h"
#include "../../matched/include/Obj09962.h"
#include "../../matched/include/Obj09964.h"
#include "../../matched/include/Obj09965.h"
#include "../../matched/include/Obj21056.h"
#include "../../matched/include/Obj07752.h"
#include "../../matched/include/Obj13315.h"
#include "../../matched/include/Obj04358.h"
#include "../../matched/include/Obj13316.h"
#include "../../matched/include/Obj13317.h"

#define F(o) (*(u8 **)(p + (o)))
struct Unk021D62A8;
struct UtilWork;
struct Msg;
struct O;
struct Out64B4;
struct Slot;
struct Unk021BD1E0;
struct Unk021BDE48;
struct Unk021BE518;
struct Unk021D82D0;
struct Unk021BD200;
struct UtilSlots;
struct Q;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Fl { u8 f : 1; };

struct Unk021BDE48 { u32 lo : 7; u32 species : 16; u32 hi : 9; };

union Unk021E8B80 {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    u32 w;
} Action;

struct Out_021BDB88 { u8 c0; u8 pad; u16 c2; u8 c4; };

struct Cell { u32 w[5]; };

struct Out_021BE3A8 { u8 pad[16]; u32 flag : 1; u32 rest : 31; };

struct Unk021BE518 { u8 f0; u8 f1[6]; };

struct Lock_021BDB88 { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

typedef struct { u8 *a; u32 b, c; u8 d0, flag; u16 pad; } E;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E_021BCB68;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BCB68 e[4]; } S_021BCB68;

struct State { u16 f0; u8 f2, f3, f4; u8 a:1, b:1, rest:6; };

struct Bits78A { u8 low:4, skip:1, rest:3; };

struct Buf { u32 wpos, rpos; };

struct S { u32 id[6]; u16 a[6], b[6]; u8 c[6]; u16 d[6]; u8 n, max, f44, f45; };

struct Rec { u32 value; u16 kind; u8 data, flag; };

struct O { u32 pos; struct Rec r[120]; };

struct Lock_021BF244 { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };

struct Bf { u8 pad[0x10]; u32 f : 1; };

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern void func_021D70FC(int a, int b, int c);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 func_021B8DDC(u32 x);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021B8E28(u8 *p, u32 n, u8 *out, u8 *cnt_out);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
extern int func_021C6190(u8 *p, u8 *a);
extern int func_021BD0C0(u8 *p, u8 x, u32 y);
extern int func_021D5B68(void *p);
extern void func_021BD1D0(u8 *p, u32 n);
extern void func_021C5108(u8 *p, u8 *a, int z);
extern void func_021D64F0(u8 *a);
extern void func_021BDE08(u8 *p, u32 n);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Unk021E8B80 func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Unk021E8B80 v);
extern int func_021D55A0(struct UtilWork *p, int id);
extern u32 func_021D5C08(struct UtilWork *p);
extern void func_021BD1E0(struct Unk021BD1E0 *p);
extern int func_021D80BC(void *p, int a, int m, u16 move);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int func_021E02DC(u8 *, u16, u32);
extern int func_021C001C(u8 *, u8 *, u16, u16);
extern int func_021C62D8(u8 *p, u8 *a, u32 unused, u32 c, struct O *out);
extern void func_021C5604(u8 *, u8 *, int);
extern void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern int func_021CA7F4(u8 *, u8 *, u16, const u8 *, void *);
extern int func_021C07AC(u8 *, u8 *, u16, u16, int);
extern void func_021C0450(u8 *, u8 *, u16, int);
extern void func_021BE338(void *);
extern void func_021BE348(void *);
extern u32 func_021BE358(void *);
extern void func_021BE368(void *);
extern void func_021BE378(void *, void *);
extern void func_021BE388(void *, u32);
extern void func_021BE398(void *, u16, u32, u32);
extern int func_021C6458(u8 *, u8 *, u32, u32, u8 *);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C8810(u8 *);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern int func_021C024C(u8 *, u8 *, u32);
extern void func_021D6744(u8 *, u8, int, u8, u16, u16);
extern u8 func_021D69AC(u8 *, int);
extern void func_021C0780(u8 *, u8 *, int, u8);
extern void func_021BFE60(u8 *, u8 *);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void func_021BFF60(u8 *, u8 *, int);
extern void func_021E0394(u8 *, int);
extern int func_0201BEB8(void *bag, int item);
extern int func_021EF948(int k);
extern u8 *func_021B9934(char *, int);
extern int func_021D5B7C(void *);
extern void func_021D7394(int kind);
extern int func_021D59B4(u8 *p, int k);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D73D4(int kind);
extern void func_021C0520(u8 *, u8 *, u16, u32);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern u32 func_021D6E74(u8 *p);
extern E *func_021BCB14(u8 *, u16, u8, u32);
extern int func_021BCB68(S_021BCB68 *p, E_021BCB68 *cur);
extern void func_021D6E40(u8 *, u8, u16);
extern void func_021CD64C(void *, u8, ...);
extern int func_021BD148(void *p, u8 x);
extern int func_021C88E4(u8 *p);
extern void func_021C5718(u8 *p, u8 *a, u32 b);
extern u8 func_021BEB04(u8 *p, int selector);
extern u32 func_021BEBB8(int d);
extern u8 *func_021BEBC8(int d, u32 i);
extern void func_021D75A8(int key, u32 val);
extern u8 func_021B8FF4(u8 *);
extern void func_021BA1B4(char **p, int i);
extern u32 func_0201C1BC(u16);
extern int func_021BFC08(u8 *, u8 *, u8 *, u16);
extern void func_021BEFEC(void *);
extern void func_021BEFFC(struct S *);
extern int func_021BF00C(struct S *);
extern int func_021BF01C(struct S *);
extern int func_021BF02C(struct S *);
extern void func_021BF03C(struct O *);
extern u32 func_021CD4FC(u8 *, u32);
extern void func_021BD200(struct Unk021BD200 *p, u8 *q, u8 *a, int t);
extern int func_021C65A8(u8 *, u8 *, u32, u8 *);
extern void func_021BFBD0(u8 *, u32, u8 *, u32);
extern void func_021CC8A0(u32 *p);
extern void func_021C091C(u8 *, u8 *, u8 *, u8 *, u32, u32);
extern void func_021C2DC4(u8 *, u32, u32, u32);
extern void func_021C2488(u8 *, u16, u8 *, u32);
extern void func_021C3184(u8 *, const u16 *, u32, u32);
extern void func_021C3438(u8 *, u16 *, u8 *, u8 *);
extern void func_021C376C(u8 *, u16, int, int);
extern void func_021C3274(u8 *, u32, u32, u32);
extern void func_021C3AA8(u8 *, u16 *, u8 *);
extern void func_021C3D08(u8 *, u16 *, u8 *, u8 *);
extern void func_021C60EC(u8 *p, u8 *a, u32 n);
extern int func_021C4F64(u8 *, u8 *);
extern void func_021BF0A4(int c);
extern int func_021BF0B4(int c);
extern void func_021BF0C4(int c, int x);
extern int func_021BF0D4(int c);
extern int func_021BFA00(u8 *p, u8 *a, u8 *b, void *item);
extern void func_021C572C(u8 *p, u8 *a, u32 v);
extern int func_021BF138(int c);
extern u8 *func_021BF148(int c, int k);
extern void func_021BF158(int c, u8 *x);
extern void func_021BF204(int c);
extern int func_021BF214(int c);
extern void func_021BF224(int c, int x);
extern int func_021BF234(int c);
extern u32 func_021D6D7C(u8 *p);
extern int func_021BF3B8(u8 *q, int k, u32 n);
extern int func_021BF3C8(u8 *q, int k, u32 n);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021CC8B0(u32 *p, u32 i, u32 b);
extern void func_021BF46C(int d);
extern u8 *func_021BF47C(int d);
extern void func_021BF48C(int d, u8 *x);
extern u8 *func_021BF49C(int d);
extern int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
extern void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e);
extern void func_021BF5E8(void *);
extern u8 *func_021BF5F8(void *);
extern void func_021BF608(void *, u8 *);
extern u8 *func_021BF618(void *);
extern void func_021BF628(void *);
extern u8 *func_021BF638(void *);
extern void func_021BF648(void *, u8 *);
extern u8 *func_021BF658(void *);
extern void func_021BF668(void *);
extern u8 *func_021BF678(void *);
extern void func_021BF688(void *, u8 *);
extern u8 *func_021BF698(void *);
extern void func_021BF6A8(void *);
extern u8 *func_021BF6B8(void *);
extern void func_021BF6C8(void *, u8 *);
extern u8 *func_021BF6D8(void *);
extern int func_021C6668(u8 *, u8 *, u8 *, u16);
extern u32 func_021C8828(u8 *p);
extern u32 func_021CC8C0(u32 *p, u32 i);
extern void func_021BF894(int d);
extern u8 *func_021BF8A4(int d);
extern void func_021BF8B4(int d, u8 *x);
extern u8 *func_021BF8C4(int d);
extern int func_021C6948(u8 *p, u8 *a, u8 *b, u32 v);
extern int func_021BF944(int d);
extern u8 *func_021BF954(int d, int k);
extern void func_021BF964(int d);
extern u8 *func_021BF974(int d);
extern void func_021BF984(int d, u8 *x);
extern u8 *func_021BF994(int d);
extern int func_021BF9A4(u8 *p, u8 *a, u8 *b, u16 *c);
extern int func_021BFA60(u8 *p, u8 *a, u8 *b, struct Q *q);
void func_021BDB88(u8 *p, u8 *a);
void func_021BDBB8(u8 *p, u8 *a);
void func_021BDBEC(u8 *p);
void func_021BDC0C(u8 *p);
void func_021BDC2C(u8 *p);
void func_021BDC58(u8 *p);
void func_021BDC78(u8 *p, u8 *a);
void func_021BDC98(u8 *p, u8 *a, u8 v);
int func_021BDD00(u8 *p, u8 *a, int c);
void func_021BDD7C(u8 *p, u8 *a, u32 c);
void func_021BDE18(u8 *p, u8 *a);
u16 func_021BDE48(void *p, struct Unk021BDE48 *m);
void func_021BDE98(u8 *p, u8 *a, Action *act, u32 key);
int func_021BE3A8(u8 *p, u8 *a, u16 *s);
void func_021BE400(u8 *p, u16 key);
void func_021BE518(struct Unk021BE518 *p);
void func_021BE52C(u8 *p, int a, int b, int c);
void func_021BE550(u8 *p, u8 *b, u16 c, void *unused);
void func_021BE620(u8 *p, u8 *a, u8 *c);
void func_021BE66C(u8 *p, u8 *a, u8 *c, int k);
void func_021BE6A8(u8 *p, u8 *a, u8 *c, int k);
int func_021BE6EC(u8 *p, u8 *a, u16 key, u32 x);
int func_021BE7E4(u8 *p, u8 *a, u32 b, u32 c, u8 *q);
int func_021BE878(u8 *p, u8 *a, u32 v);
void func_021BE8C4(u8 *p, u8 *a);
void func_021BE8F4(u8 *p,u8 *a);
void func_021BE924(u8 *p, u8 *a, u32 v);
void func_021BE95C(u8 *p, u8 *a, u32 v);
void func_021BE994(u8 *p,u8 *a,u32 c,u32 d);
void func_021BE9D0(u8 *p, u8 *a, u32 c, u32 d);
void func_021BEA14(u8 *p, u8 *a, u8 *b, u32 c);
void func_021BEA60(u8 *p, u8 *a, u8 *b, u32 c);
int func_021BEAB4(u8 *p, u8 *a, int b, int c, u8 *q);
int func_021BEB14(int a, u8 *b, int c, int d, u8 *e, u8 *g);
void func_021BEBD8(u8 *p,u8 *a,int c,int d);
int func_021BEC08(u8 *p,u8 *a);
void func_021BEC2C(u8 *p,u8 *a,int c);
int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d);
void func_021BF04C(u8 *p, u16 *b, int s, int c);
void func_021BF0E4(int u, u8 *b, int c, u8 *d, int e);
int func_021BF168(u8 *p, u16 *a, u8 *b);
void func_021BF1B4(int u, u16 *b, int s, int c, int e);
void func_021BF244(u8 *p, u32 a, u32 b);
void func_021BF27C(u8 *p, u32 a, u32 b);
void func_021BF2B4(u8 *p, u32 a, u32 b);
void func_021BF2EC(u8 *p, u32 a, u32 b, int k);
int func_021BF324(u8 *p, u8 *a, u8 *b);
void func_021BF3D8(u8 *p, int b, u8 *a, int d, void *arr);
void func_021BF4AC(u8 *p, u8 *b, u8 *a, void *d, void *e);
int func_021BF6E8(u8 *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1);
int func_021BF78C(u8 *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h);
void func_021BF83C(u8 *p, u16 *b, u8 *c, int d);
void func_021BF8D4(u8 *p, u16 *b, u8 *c, int d);
extern const u16 d_021EFDB8[3];














void func_021BDB88(u8 *p, u8 *a)
{
    func_021D74F8(0xc43);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 0x55);
    func_021D7540(0xc46);
}















void func_021BDBB8(u8 *p, u8 *a)
{
    func_021D74F8(0xc55);
    func_021D75EC(2, func_021D5440(a));
    func_021D70FC((int)p, 0x55, 4);
    func_021D7540(0xc58);
}















void func_021BDBEC(u8 *p)
{
    func_021D74F8(3173);
    func_021D70F0(p, 86);
    func_021D7540(3175);
}















void func_021BDC0C(u8 *p)
{
    func_021D74F8(3187);
    func_021D70F0(p, 87);
    func_021D7540(3189);
}















void func_021BDC2C(u8 *p)
{
    u32 old;
    old = func_021CC8D8(p + 0x1d74, 0xc82);
    func_021BDC58(p);
    func_021CC95C((u32 *)(p + 0x1d74), old, 0xc84);
}















void func_021BDC58(u8 *p)
{
    func_021D74F8(3217);
    func_021D70F0(p, 88);
    func_021D7540(3219);
}















void func_021BDC78(u8 *p, u8 *a)
{
    u8 id;
    int value;
    id = func_021D5440(a);
    value = func_021B8DDC(id);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3b, value, id);
}
















void func_021BDC98(u8 *p, u8 *a, u8 v)
{
    u8 buf[2];
    int r;
    u8 *q;
    func_021BDC78(p, a);
    if (func_021BDD00(p, a, 0)) {
        r = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(a));
        func_021B8E28(*(u8 * *)&((struct Obj00003 *)p)->f4, r, &buf[1], &buf[0]);
        q = p + 0x7D9;
        if (q[buf[1]] < 0xFF) q[buf[1]]++;
        func_021BD9D4(p, buf[1], buf[0], v, 1);
    }
}
















int func_021BDD00(u8 *p, u8 *a, int c)
{
    u32 n, i;
    if (c == 0) {
        n = func_021C6190(p, a);
        if (n != 0) {
            ((struct Fl *)(p + 0x78A))->f = 1;
            for (i = 0; i < n; i++) {
                func_021BD0C0(p, p[0x78B + i], func_021D5440(a));
                if (func_021D5B68(a)) break;
            }
            ((struct Fl *)(p + 0x78A))->f = 0;
        }
    }
    if (func_021D5B68(a) == 0) {
        func_021BDD7C(p, a, 0x26C);
        return 1;
    }
    return 0;
}














void func_021BDD7C(u8 *p, u8 *a, u32 c)
{
    u32 n = func_021D5440(a);
    u32 s;
    int r = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, n);
    if (r != 6) func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3C, r, c);
    func_021BD1D0(p, n);
    s = func_021CC8D8(p + 0x1D74, 3327);
    func_021BDE18(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), s, 3329);
    func_021C5108(p, a, 0);
    func_021D64F0(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x20, func_021D5440(a));
    func_021BDE08(p + 0x1AB8, n);
}














void func_021BDE18(u8 *p, u8 *a)
{
    func_021D74F8(3348);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 0x54);
    func_021D7540(3351);
}















u16 func_021BDE48(void *p, struct Unk021BDE48 *m)
{
    u16 r = 0x17;
    if (func_021D62C4(p, 0x17) && m->species != 0xA5) {
        r = func_021E8B80(func_021D6314(p, r));
        if (r != m->species && func_021D55A0(p, r)) return r;
    }
    return 0;
}














static inline void ev18(void *w, u32 x, u32 s, u32 c, u32 b, u32 i2, u32 i1)
{
    func_021CD4B0(w, 0x18, x, s, c, b, i2, i1);
}














void func_021BDE98(u8 *p, u8 *a, Action *act, u32 key)
{
    int k;
    u8 sel;
    u32 prev;
    int chk1, chk2;
    int found;
    u8 flag;
    u8 pr;
    u16 m;
    u16 id;
    u16 id2;
    struct Out_021BDB88 o;

    prev = func_021D5C08((struct UtilWork *)a);
    func_021BD1E0((struct Unk021BD1E0 *)F(0x4a8));
    func_021BE518((struct Unk021BE518 *)F(0x4b0));
    o.c2 = 0;
    o.c4 = 6;
    m = func_021BDE48(a, (struct Unk021BDE48 *)act);
    if (m != 0) {
        func_021D82D0((struct Unk021D82D0 *)act, m, func_021D80BC(*(void **)(p + 4), *(int *)(p + 8), (int)a, m));
    }
    id = act->full.move;
    pr = func_021D5778((struct UtilWork *)a, id);
    id2 = id;
    sel = (u8)act->full.select;
    flag = 0;
    o.c0 = 0;
    chk1 = (u8)func_021D62C4((struct Unk021D62A8 *)a, 0x19);
    chk2 = (u8)func_021D62C4((struct Unk021D62A8 *)a, 0x1a);
    func_021E02DC(a, id, key);
    func_021BE924(p, a, id);
    if (func_021C001C(p, a, id, (u8)((chk1 != 0 || chk2 != 0) ? 1 : flag)) != 0) goto end;
    if (func_021C62D8(p, a, id, sel, (struct O *)(&o.c2)) == 0) {
        func_021C5604(p, a, id);
        func_021C64B4(p, id, a, (struct Out64B4 *)F(0x1ab4));
        func_021CA7F4(p, a, sel, F(0x1ab4), F(0x850));
        func_021C07AC(p, a, id, pr, (int)F(0x850));
        flag = 1;
        func_021C0450(p, a, id, 0x1a);
        goto end;
    }
    found = (u8)((o.c2 != 0) ? 1 : 0);
    if (found) {
        func_021C5604(p, a, id);
        func_021BEBD8(p, a, id, sel);
        func_021E02DC(a, o.c2, key);
        id2 = o.c2;
        sel = o.c4;
    } else {
        id2 = id;
    }
    func_021C64B4(p, id, a, (struct Out64B4 *)F(0x1ab4));
    if (found) {
        func_021C64B4(p, id2, a, (struct Out64B4 *)F(0x1ab0));
        ((u32 *)F(0x1ab0))[4] |= 4;
        ((u16 *)F(0x1ab0))[1] = id;
        if (func_021BE3A8(p, a, (u16 *)F(0x1ab0)) != 0) {
            func_021C07AC(p, a, id, pr, (int)F(0x850));
            flag = 1;
            goto end;
        }
    } else {
        *(struct Cell *)F(0x1ab0) = *(struct Cell *)F(0x1ab4);
    }
    func_021BE338(F(0x850));
    func_021BE348(F(0x854));
    func_021CA7F4(p, a, sel, F(0x1ab0), F(0x850));
    {
        u32 v = (u8)func_021BE358(F(0x850));
        func_021BE368(F(0x850));
        func_021BE378(F(0x850), F(0x854));
        func_021BE388(F(0x854), v);
    }
    if (chk1 == 0 && chk2 == 0 && pr != 4) {
        func_021C07AC(p, a, id, pr, (int)F(0x850));
        flag = 1;
    }
    {
        k = 0x1ab4;
        func_021BE66C(p, a, *(void **)(p + k), 0x22);
        func_021BE620(p, a, *(void **)(p + k - 4));
        if (func_021C6458(p, a, id, id2, p + k + 0x30) != 0) {
            func_021C99A0(p, (const struct Msg *)(p + k + 0x30));
            k += 0x30;
            func_021C8810(p + k);
        } else {
            func_021C5604(p, a, id2);
        }
    }
    *(u16 *)(p + 0x1f74) = id2;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x22) != 0) {
        func_021C5620(p, a, 0x22, 0);
        func_021D5FC0((struct UtilWork *)a, 0xe);
    }
    if (func_021C024C(p, a, id2) == 0
        && func_021BE7E4(p, a, id2, sel, (u8 *)&o) == 0
        && func_021BE6EC(p, a, id2, sel) == 0) {
        func_021BE398(p + 0x1c, id2, *(u32 *)(p + 0x10), func_021D5440(a));
        func_021BE66C(p, a, F(0x1ab0), 0x23);
        if (func_021BEAB4(p, a, id2, *(int *)(p + 0x854), F(0x4ac)) != 0) {
            func_021BE550(p, a, id2, F(0x854));
        } else {
            o.c0 = func_021BEC58(p, a, id2, F(0x854));
        }
    }
end:
    func_021D5FC0((struct UtilWork *)a, 3);
    if (flag != 0 || chk1 != 0 || id2 == 0xa5) {
        func_021D6744(a, sel, o.c0, F(0x1ab0)[6], id2, id);
        ev18(*(void **)(p + 0xc), func_021D5440(a), sel, o.c0, F(0x1ab0)[6], id2, id);
    } else if (func_021D69AC(a, 3) != 0) {
        func_021C0780(p, a, 3, 0);
    }
    if (prev != 0x10 && func_021D5C08((struct UtilWork *)a) != 0x10) func_021BFE60(p, a);
    if (func_021D5BB0((struct UtilWork *)a, 0xb) != 0) {
        func_021CD4B0(*(void **)(p + 0xc), 0x31, func_021D5440(a), 0);
        func_021BFF60(p, a, 0);
    }
    func_021BE994(p, a, id2, o.c0);
    if (o.c2 != 0) func_021E0394(a, o.c2);
    func_021E0394(a, id);
    func_021BE400(p, id2);
}


















int func_021BE3A8(u8 *p, u8 *a, u16 *s)
{
    u16 t = *s;
    int k = 0;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0xF) && (u32)func_0201BEB8((void *)t, (int)0xC)) {
        k = 0xD;
    } else if (func_021EF948(2) && (u32)func_0201BEB8((void *)t, (int)9)) {
        k = 0x14;
    }
    if (k) {
        func_021C0450(p, a, t, k);
        return 1;
    }
    return 0;
}


















void func_021BE400(u8 *p, u16 key)
{
    u32 i;
    u8 *a;
    u8 *b;
    u32 lock;
    for (i = 0; i < (*(u8 **)(p + 0x4b0))[0]; i++) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 1]);
        b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 13]);
        if (func_021D5B7C(a) != 0) {
            lock = func_021CC8D8(p + 0x1d74, 3657);
            func_021BEA60(p, a, b, key);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 3659);
            func_021C64B4(p, key, a, (struct Out64B4 *)(*(struct Out_021BE3A8 * *)&((struct Obj00003 *)p)->f1AB0));
            (*(struct Out_021BE3A8 **)(p + 0x1ab0))->flag = 1;
            func_021CA7F4(p, a, (*(u8 **)(p + 0x4b0))[i + 7], (const u8 *)(*(struct Out_021BE3A8 **)(p + 0x1ab0)), ((struct Obj00003 *)p)->f864);
            func_021D7394(func_021D5440(a));
            func_021E02DC(a, key, func_021D59B4(a, 12));
            func_021BEC58(p, a, key, ((struct Obj00003 *)p)->f864);
            func_021E03D8(a, key);
            func_021D73D4(func_021D5440(a));
        }
    }
}


















void func_021BE518(struct Unk021BE518 *p)
{
    u32 i;
    p->f0 = 0;
    for (i = 0; i < 6; i++) p->f1[i] = 0x1F;
}

















/*
 * evidence: Each byte store may alias p[0], so reread the index.
 */
void func_021BE52C(u8 *p, int a, int b, int c)
{
    if (p[0] < 6) {
        (p + p[0])[1] = a;
        (p + p[0])[13] = b;
        (p + p[0])[7] = c;
        p[0]++;
    }
}

















void func_021BE550(u8 *p, u8 *b, u16 c, void *unused)
{
    u8 *a;
    u32 lock;
    if ((*(u8 **)(p + 0x4ac))[0] != 0) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4ac))[1]);
        lock = func_021CC8D8(p + 0x1d74, 3720);
        func_021BEA14(p, a, b, c);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 3722);
        func_021C64B4(p, c, a, ((struct Obj00003 *)p)->f1AB0);
        func_021CA7F4(p, a, (*(u8 **)(p + 0x4ac))[7], ((struct Obj00003 *)p)->f1AB0, ((struct Obj00003 *)p)->f864);
        if (func_021D62C4((struct Unk021D62A8 *)a, 15) != 0 && (u32)func_0201BEB8((void *)c, (int)12) != 0) {
            func_021C0520(p, a, c, 13);
            return;
        }
        func_021E02DC(a, c, func_021D59B4(a, 12));
        func_021BEC58(p, a, c, ((struct Obj00003 *)p)->f864);
        func_021E03D8(a, c);
    }
}


















void func_021BE620(u8 *p, u8 *a, u8 *c)
{
    func_021D74F8(3755);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj09961 *)c)->f0);
    func_021D7630(0x16, c[6]);
    func_021D70F0(p, 0xA2);
    c[6] = func_021D775C(0x16);
    func_021D7540(3761);
}

















/*
 * evidence: CC8D8 returns its four-byte Lock_021BDB88 in r0; preserve that complete
 * word as u32, as matched twin 021BE924 does. CC95C stores r1 unchanged.
 */
void func_021BE66C(u8 *p, u8 *a, u8 *c, int k)
{
    u32 old;
    old = func_021CC8D8((struct Lock_021BDB88 *)(p + 0x1D74), 3774);
    func_021BE6A8(p, a, c, k);
    func_021CC95C((u32 *)(p + 0x1D74), old, 3778);
}


















void func_021BE6A8(u8 *p, u8 *a, u8 *c, int k)
{
    func_021D74F8(3791);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13311 *)c)->f0);
    func_021D75EC(0x16, c[6]);
    func_021D70F0(p, k);
    func_021D7540(3796);
}

















int func_021BE6EC(u8 *p, u8 *a, u16 key, u32 x)
{
    u32 i;
    u32 n;
    u8 id;
    u8 *chosen;
    u32 best;
    u8 chosen_id;
    E *cur;
    E *found[2];
    u32 v;
    for (i = 0; i < 3; i++) {
        if (key == d_021EFDB8[i]) break;
    }
    if (i == 3) goto fail;
    if (func_021D5BB0((struct UtilWork *)a, 10) != 0) goto fail;
    if (func_021D6E74(a) != 0) goto fail;
    n = 0;
    id = func_021D5440(a);
    for (i = 0; i < 3; i++) {
        if (key != d_021EFDB8[i]) {
            found[n] = func_021BCB14(p, d_021EFDB8[i], id, x);
            if (found[n] != 0) {
                n++;
                if (n >= 2) break;
            }
        }
    }
    if (n == 0) goto fail;
    best = 6;
    chosen = found[0]->a;
    for (i = 0; i < n; i++) {
        cur = found[i];
        v = (u32)func_021BCB68((S_021BCB68 *)p, (E_021BCB68 *)cur);
        if (v < best) {
            best = v;
            chosen = cur->a;
        }
    }
    chosen_id = func_021D5440(chosen);
    func_021D5FC0((struct UtilWork *)a, 10);
    func_021D6E40(chosen, id, key);
    func_021CD64C(((struct Obj21052 *)p)->fC, 91, 0x47a, id, chosen_id, 0xffff0000);
    func_021BD148(p, chosen_id);
    return 1;
fail:
    return 0;
}


















int func_021BE7E4(u8 *p, u8 *a, u32 b, u32 c, u8 *q)
{
    u32 lk = func_021CC8D8(p + 0x1D74, 3894);
    int r = func_021BE878(p, a, c);
    int s;
    *q = 0;
    if (r) {
        s = func_021B8D8C(((struct Obj09962 *)p)->f4, ((struct Obj09962 *)p)->f8, func_021D5440(a));
        if (func_021C88E4(p) == 2) {
            func_021CD4B0(((struct Obj09962 *)p)->fC, 0x30, s, c, b, 0);
            func_021BE8C4(p, a);
            *q = 1;
        } else {
            func_021C5718(p, a, b);
        }
    }
    func_021CC95C((u32 *)(p + 0x1D74), lk, 3913);
    return r;
}


















int func_021BE878(u8 *p, u8 *a, u32 v)
{
    int r;
    func_021D74F8(3931);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0xD, v);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 6);
    r = func_021D775C(0x51);
    func_021D7540(3937);
    return r;
}















void func_021BE8C4(u8 *p, u8 *a)
{
    u32 old;
    old = func_021CC8D8((struct Lock_021BDB88 *)(p + 0x1D74), 3951);
    func_021BE8F4(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), old, 3956);
}















void func_021BE8F4(u8 *p,u8 *a)
{
    func_021D74F8(3968);
    func_021D75EC(3,func_021D5440(a));
    func_021D70F0(p,7);
    func_021D7540(3971);
}
















void func_021BE924(u8 *p, u8 *a, u32 v)
{
    u32 s = func_021CC8D8(p + 0x1D74, 3985);
    func_021BE95C(p, a, v);
    func_021CC95C((u32 *)(p + 0x1D74), s, 3987);
}















void func_021BE95C(u8 *p, u8 *a, u32 v)
{
    func_021D74F8(4000);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, v);
    func_021D70F0(p, 3);
    func_021D7540(4004);
}














/*
 * Interface: getter's matched Lock_021BDB88 return is one full word; original
 * 021CC8DA loads old [r0] into r1; 021CC900 copies r1 to r0 unchanged.
 * This caller
 * saves r0 at 021BE9A8 and restores all bits through r1 at 021BE9BA;
 * 021CC95C is str r1,[r0]; bx lr. Scalar spelling follows matched caller
 * 021BC568 and retains the same word ABI. Struct/union locals used a
 * 12-byte frame and separate 4019 pool; scalar uses original 4-byte frame.
 */
void func_021BE994(u8 *p,u8 *a,u32 c,u32 d)
{
    u32 old;
    old=func_021CC8D8(p+0x1d74, 4017);
    func_021BE9D0(p,a,c,d);
    func_021CC95C((u32 *)(p+0x1d74),old,4019);
}















void func_021BE9D0(u8 *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(4032);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x51, d);
    func_021D70F0(p, 4);
    func_021D7540(4037);
}















void func_021BEA14(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4051);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D70F0(p, 8);
    func_021D7540(4056);
}














void func_021BEA60(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4069);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 9);
    func_021D7540(4075);
}













/*
 * The byte loaded and compared in r1 remains the veneer call's second
 * argument. The veneer at 021BEB04 preserves r0/r1 to its target.
 */
int func_021BEAB4(u8 *p, u8 *a, int b, int c, u8 *q)
{
    u8 buf[2];
    buf[1] = 0x1F;
    buf[0] = 0x1F;
    func_021BEB14((int)p, a, b, c, &buf[1], &buf[0]);
    if (buf[1] != 0x1F) {
        q[7] = (buf[0] != 0x1F) ? func_021BEB04(p + 0x1AB8, buf[0]) : 6;
        q[1] = buf[1];
        q[0] = 1;
        return 1;
    }
    return 0;
}











int func_021BEB14(int a, u8 *b, int c, int d, u8 *e, u8 *g)
{
    u32 n;
    u32 i;
    n = func_021BEBB8(d);
    func_021D74F8(4136);
    func_021D75EC(0x12, c);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(5, n);
    for (i = 0; i < n; i++)
        func_021D75EC(6 + i, func_021D5440(func_021BEBC8(d, i)));
    func_021D7630(2, 0x1f);
    func_021D75A8(4, 0x1f);
    func_021D70F0((void *)a, 0x1a);
    *e = func_021D775C(2);
    *g = func_021D775C(4);
    func_021D7540(4155);
    if (*e != 0x1f)
        return 1;
    return 0;
}











void func_021BEBD8(u8 *p,u8 *a,int c,int d)
{
    int n;
    n=func_021B8D8C(((struct Obj09964 *)p)->f4,((struct Obj09964 *)p)->f8,func_021D5440(a));
    func_021CD4B0(((struct Obj09964 *)p)->fC,0x30,n,d,c,0);
}












int func_021BEC08(u8 *p,u8 *a)
{
    int n;
    n=func_021B8DDC(func_021D5440(a));
    if(n==func_021B8FF4(*(u8 * *)&((struct Obj09965 *)p)->f4)) return 1;
    return 0;
}












void func_021BEC2C(u8 *p,u8 *a,int c)
{
    if(func_021BEC08(p,a)) {
        if(c==150) func_021BA1B4((char **)(*(u8 * *)&((struct Obj09965 *)p)->f4),73);
        else if(c==165) func_021BA1B4((char **)(*(u8 * *)&((struct Obj09965 *)p)->f4),74);
    }
}











/*
 * budget: 2 iteration one; scheduling variant1/2 consumed; no checks/permuter.
 * Single action/filter pipeline, with flags initialized at EC74..EC7E.
 * All exit paths and switch table mappings retain their original results.
 * CC8D8 returns the full pre-mutation 32-bit Lock_021BDB88 (10+9+9+1+1+1+1).
 * ECFA saves all r0 and ED0E/ED14 forwards all r1 to own CC95C's u32
 * store; preserve line inputs 10A8/10AA under original return-use rule.
 * C5718's own one-input body does not erase the original loaded r1/r2.
 * Veneers EFEC/FFC/00C/01C/02C/03C forward respectively to ov095
 * CB3C/CEE4/CD50/CD50/CD50/D050; own matched records fix their widths.
 * Original ED78 branches onto ED7A: duplicated forced=1 arms retain the
 * cross-jumped break. Original EDB0..EDB4 extracts byte bit4, represented
 * by Bits78A. EE44 branches directly to EE6C, skipping C5718 at EE68;
 * only BF02C's true path performs that call before BF27C.
 */
int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d)
{
    u32 lock;
    u32 action = func_0201C1BC(key);
    u8 id = func_021D5440(a);
    int active = 1;
    int execute = 0;
    int forced = 0;
    u32 pos;
    int result;
    struct State *s;
    func_021BEC2C(p, a, key);
    if ((u32)func_0201BEB8((void *)key, (int)1)) {
        switch (func_021BFC08(p, a, d, key)) {
        case 0: break;
        case 1: return execute;
        case 2: return active;
        case 3: return execute;
        case 4: break;
        }
    }
    func_021BEFEC(((struct Obj00003 *)p)->f860);
    pos = func_021CD4FC((u8 *)(*(struct Buf * *)&((struct Obj00003 *)p)->fC), 0x30);
    func_021BD200((struct Unk021BD200 *)(*(struct State * *)&((struct Obj00003 *)p)->f4A8), p, a, (int)d);
    lock = func_021CC8D8(p + 0x1d74, 0x10a8);
    result = func_021C65A8(p, a, key, d);
    func_021CC95C((u32 *)(p + 0x1d74), lock, 0x10aa);
    if (result != 0) {
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a == 0) s->a = 1;
        if (result == 2) {
            func_021BFBD0(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
            return 1;
        }
    }
    switch (action) {
    case 0: case 4: case 6: case 7: case 8:
        execute = 1;
        forced = 1;
        break;
    case 9:
        forced = 1;
        break;
    }
    func_021BEFFC((struct S *)d);
    func_021BF04C(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (int)a, (int)d);
    func_021BF0E4((int)p, a, (int)d, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, execute);
    if (func_021BF00C((struct S *)d)) {
        if (((struct Bits78A *)(p + 0x78a))->skip == 0) func_021C5718(p, a, key);
        active = 0;
    }
    if (active != 0) {
        if (action != 9) func_021BF83C(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, (int)d);
        func_021CC8A0((u32 *)(p + 0x1f88));
        if (forced != 0 || func_021BF168(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a))
            func_021BF3D8(p, *(int *)&((struct Obj00003 *)p)->f1AB0, a, (int)d, p + 0x1f88);
        func_021BF4AC(p, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, a, d, p + 0x1f88);
        if (action != 9) func_021BF8D4(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, (int)d);
        if (func_021BF01C((struct S *)d)) {
            func_021BF27C(p, id, key);
            active = 0;
        } else {
            func_021BF1B4((int)p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (int)a, (int)d, forced);
            if (func_021BF02C((struct S *)d)) {
                func_021C5718(p, a, key);
                func_021BF27C(p, id, key);
                active = 0;
            }
        }
    }
    if (active != 0) {
        if (execute != 0) {
            func_021C091C(p, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, a, d, (u32)(p + 0x1f88), 0);
        } else {
            switch (action) {
            case 2: func_021C2DC4(p, *(u32 *)&((struct Obj00003 *)p)->f1AB0, (u32)a, (u32)d); break;
            case 1: func_021C2488(p, key, a, (u32)d); break;
            case 5: func_021C3184(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (u32)a, (u32)d); break;
            case 9: func_021C3438(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, d); break;
            case 12: func_021C376C(p, key, (int)a, (int)d); break;
            case 3: func_021C3274(p, key, (u32)a, (u32)d); break;
            case 10: func_021C3AA8(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a); break;
            case 11: case 13: func_021C3D08(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, d); break;
            }
        }
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a != 0) {
            if (s->b == 0) func_021BFBD0(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
            func_021BF03C((struct O *)(p + 0x1c));
            if (!func_021D5B68(a) && (u32)func_0201BEB8((void *)key, (int)2)) func_021C60EC(p, a, 12);
            func_021BF244(p, id, key);
        } else {
            func_021BF27C(p, id, key);
            active = 0;
        }
    } else {
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a != 0) func_021BFBD0(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
    }
    func_021BF2B4(p, id, key);
    func_021C4F64(p, a);
    return active;
}









void func_021BF04C(u8 *p, u16 *b, int s, int c)
{
    int x;
    func_021BF0A4(c);
    x = func_021BF0B4(c);
    while (x != 0) {
        if (func_021BFA00(p, (u8 *)s, (u8 *)x, (void *)(*b)) != 0) {
            func_021BF0C4(c, x);
            func_021C572C(p, (u8 *)x, *b);
            p[0x78a] |= 0x10;
        }
        x = func_021BF0D4(c);
    }
}








void func_021BF0E4(int u, u8 *b, int c, u8 *d, int e)
{
    u8 *x;
    if (func_021BF138(c) == 1) {
        x = func_021BF148(c, 0);
        if (x != 0) {
            if (func_021D5440(x) == func_021D5440(b)) {
                if (((struct Obj21056 *)d)->fC != 7) {
                    if (func_021D5BB0((struct UtilWork *)b, 12) != 0 || e != 0)
                        func_021BF158(c, x);
                }
            }
        }
    }
}








int func_021BF168(u8 *p, u16 *a, u8 *b)
{
    int r;
    func_021D74F8(4500);
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x12, *a);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x3d);
    r = func_021D775C(0x51);
    func_021D7540(4506);
    return r;
}








void func_021BF1B4(int u, u16 *b, int s, int c, int e)
{
    int x;
    func_021BF204(c);
    x = func_021BF214(c);
    while (x != 0) {
        if (s != x && func_021D6D7C((u8 *)x) != 0 && e == 0 && (u32)func_0201BEB8((void *)((u16)((void *)*b)), (int)0xd) == 0)
            func_021BF224(c, x);
        x = func_021BF234(c);
    }
}







/*
 * interface: The four-byte Lock_021BF244 getter returns its entire original word in
 * r0 (021CC8DA,021CC900); restore 021CC95C stores that word unchanged.
 * Scalar payload follows matched caller 021BCEFC and preserves every bit.
 */
void func_021BF244(u8 *p, u32 a, u32 b)
{
    int line = 0x11e7;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)(p + 0x1d74), line);
    func_021BF2EC(p, a, b, 0x25);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}







void func_021BF27C(u8 *p, u32 a, u32 b)
{
    int line = 0x11f6;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)(p + 0x1d74), line);
    func_021BF2EC(p, a, b, 0x26);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}







void func_021BF2B4(u8 *p, u32 a, u32 b)
{
    int line = 0x1205;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)(p + 0x1d74), line);
    func_021BF2EC(p, a, b, 0x27);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}







void func_021BF2EC(u8 *p, u32 a, u32 b, int k)
{
    int line = 0x1214;
    func_021D74F8(line);
    func_021D75EC(2, a);
    func_021D75EC(0x12, b);
    func_021D70F0(p, k);
    func_021D7540(line + 4);
}







int func_021BF324(u8 *p, u8 *a, u8 *b)
{
    u8 t;
    if (func_021BF3B8(p + 0x1ab8, *(int *)&((struct Obj07752 *)p)->f4, func_021D5440(a)) != 0) {
        if (func_021D59B4(a, 0x11) == 0x63)
            return 1;
    }
    if (func_021BF3C8(p + 0x1ab8, *(int *)&((struct Obj07752 *)p)->f4, func_021D5440(b)) != 0) {
        if (func_021D59B4(b, 0x11) == 0x63)
            return 1;
    }
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x1c) != 0)
        return 1;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x1d) != 0) {
        t = func_021D62D8((struct UtilSlots *)a, 0x1d);
        if (t == func_021D5440(b))
            return 1;
    }
    return 0;
}





void func_021BF3D8(u8 *p, int b, u8 *a, int d, void *arr)
{
    u8 *x;
    int r;
    int e;
    func_021CC8A0(arr);
    func_021BF46C(d);
    x = func_021BF47C(d);
    while (x != 0) {
        r = func_021C6E3C(p, a, x, (u8 *)b, 1);
        func_021CC8B0(arr, func_021D5440(x), r);
        if (r == 0) {
            func_021BF48C(d, x);
            func_021C7C24((u16 *)(p + 0x1f7c), (int)p, a, x, 0);
            e = func_021B8DDC(func_021D5440(a));
            if (e == func_021B8FF4(*(u8 * *)&((struct Obj13315 *)p)->f4))
                func_021BA1B4((char **)(*(u8 * *)&((struct Obj13315 *)p)->f4), 0x4b);
        }
        x = func_021BF49C(d);
    }
}



void func_021BF4AC(u8 *p, u8 *b, u8 *a, void *d, void *e)
{
    u8 *q;
    func_021BF5E8(d);
    q = func_021BF5F8(d);
    while (q) {
        if (func_021BF324(p, a, q) == 0 && func_021BF6E8(p, b, a, q, e, 43))
            func_021BF608(d, q);
        q = func_021BF618(d);
    }
    func_021BF628(d);
    q = func_021BF638(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 44)) func_021BF648(d, q);
        q = func_021BF658(d);
    }
    if ((u32)func_0201BEB8((void *)(((struct Obj04358 *)b)->f0), (int)3)) {
        func_021BF668(d);
        q = func_021BF678(d);
        while (q) {
            if (func_021D5BB0((struct UtilWork *)q, 7) && func_021C6668(p, a, q, ((struct Obj04358 *)b)->f0) == 0) {
                func_021BF688(d, q);
                func_021CD64C(((struct Obj13316 *)p)->fC, 91, 523, func_021D5440(q), 0xffff0000);
            }
            q = func_021BF698(d);
        }
    }
    func_021BF6A8(d);
    q = func_021BF6B8(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 45)) func_021BF6C8(d, q);
        q = func_021BF6D8(d);
    }
}




int func_021BF6E8(u8 *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1)
{
    u32 s;
    int flag;
    int r;
    s = func_021CC8D8(p + 0x1d74, 4784);
    flag = 0;
    r = func_021BF78C(p, b, s1, c2, d, s0, p + 0x1ae4, &flag);
    if (r != 0) {
        if (func_021C8828(p + 0x1ae4) != 0) {
            func_021C99A0(p, (const struct Msg *)(p + 0x1ae4));
            func_021C8810(p + 0x1ae4);
        } else if (func_021C88E4(p) == 0 && flag == 0) {
            func_021CD64C(((struct Obj13316 *)p)->fC, 0x5b, 0xd2, func_021D5440(d), 0xffff0000);
        }
    }
    func_021CC95C((u32 *)(p + 0x1d74), s, 4810);
    return r;
}





int func_021BF78C(u8 *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h)
{
    u32 t;
    int r;
    t = func_021CC8C0(f, func_021D5440(e));
    func_021C8810(g);
    func_021D74F8(4834);
    func_021D75EC(3, func_021D5440(d));
    func_021D75EC(4, func_021D5440(e));
    func_021D75EC(0x12, ((struct Obj13317 *)b)->f0);
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x4e, ((struct Bf *)b)->f);
    func_021D75EC(0x3f, (u32)g);
    func_021D75EC(0x38, t);
    func_021D7630(0x40, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, c);
    r = func_021D775C(0x40);
    *h = func_021D775C(0x51);
    func_021D7540(4847);
    return r;
}





void func_021BF83C(u8 *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    func_021BF894(d);
    x = func_021BF8A4(d);
    while (x != 0) {
        if (func_021BF324(p, c, x) == 0) {
            if (func_021C6948(p, c, x, *b) != 0) {
                func_021BF8B4(d, x);
                func_021C572C(p, x, *b);
            }
        }
        x = func_021BF8C4(d);
    }
}


void func_021BF8D4(u8 *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    if (func_021BF944(d) == 1 && func_021BF954(d, 0) == c)
        return;
    func_021BF964(d);
    x = func_021BF974(d);
    while (x != 0) {
        if (func_021BF9A4(p, c, x, b) == 0 && func_021BFA60(p, c, x, (struct Q *)b) == 0) {
            func_021BF984(d, x);
            func_021C572C(p, x, *b);
        }
        x = func_021BF994(d);
    }
}
