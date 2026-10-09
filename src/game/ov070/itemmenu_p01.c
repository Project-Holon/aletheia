/*
 * file:     itemmenu_p01.c
 * unit:     yes
 * function: func_021B6EF8, func_021B7128, func_021B7250, func_021B7504, func_021B7584, func_021B75A4, func_021B761C, func_021B7640, func_021B7688, func_021B76E4, func_021B7700, func_021B77E4, func_021B7804, func_021B7868, func_021B795C, func_021B7A7C, func_021B7B08, func_021B7B80, func_021B7C88, func_021B7CD0, func_021B7D20, func_021B7D9C, func_021B7DD0, func_021B7DF4, func_021B7F38, func_021B7F54, func_021B8080, func_021B809C, func_021B80BC, func_021B80C4, func_021B811C, func_021B8134, func_021B81B0, func_021B81B8, func_021B81F4, func_021B822C, func_021B8280, func_021B832C, func_021B83A0, func_021B83B8, func_021B8600, func_021B8640, func_021B8688
 * address:  0x021B6EF8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_02027324  0x02027324  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_02020FE4  0x02020FE4  thumb
 *   func_021B6EC8  0x021B6EC8  thumb  ov070
 *   d_021BB9C4     0x021BB9C4  data  a4
 *   func_021B690C  0x021B690C  thumb  ov070
 *   func_021B6934  0x021B6934  thumb  ov070
 *   func_021B6A78  0x021B6A78  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6AD8  0x021B6AD8  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B9AAC  0x021B9AAC  thumb  ov070
 *   func_021BA9AC  0x021BA9AC  thumb  ov070
 *   func_02027858  0x02027858  thumb
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_020213E0  0x020213E0  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021BADB8  0x021BADB8  thumb  ov070
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02035C38  0x02035C38  arm
 *   func_02051C88  0x02051C88  arm
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B63F8  0x021B63F8  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B9850  0x021B9850  thumb  ov070
 *   func_020355D8  0x020355D8  arm
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B8EA8  0x021B8EA8  thumb  ov070
 *   func_021B8B7C  0x021B8B7C  thumb  ov070
 *   func_02082BCC  0x02082BCC  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021BB5DC  0x021BB5DC  thumb  ov070
 *   func_021B8B0C  0x021B8B0C  thumb  ov070
 *   func_021B6554  0x021B6554  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_0203633C  0x0203633C  arm
 *   func_021B8CE4  0x021B8CE4  thumb  ov070
 *   func_021B8F90  0x021B8F90  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_021BB1AC  0x021BB1AC  thumb  ov070
 *   func_021BB0F8 0x021BB0F8 thumb ov070
 *   func_02006238  0x02006238  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_02021350  0x02021350  thumb
 *   func_021B6204  0x021B6204  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_021B8DAC  0x021B8DAC  thumb  ov070
 *   func_021B8DCC  0x021B8DCC  thumb  ov070
 *   func_021BB08C  0x021BB08C  thumb  ov070
 *   func_021B8E08  0x021B8E08  thumb  ov070
 *   func_021B619C  0x021B619C  thumb  ov070
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 *   func_021BAFC4  0x021BAFC4  thumb  ov070
 *   func_021BB0BC  0x021BB0BC  thumb  ov070
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_021BB1C4 0x021BB1C4 thumb ov070
 *   func_021BB260 0x021BB260 thumb ov070
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02035BA4  0x02035BA4  arm
 *   d_021BB960     0x021BB960  data  a1
 *   func_02030734  0x02030734  arm
 *   sub_02007CC8   0x02007CC8  thumb
 *   func_02020F14  0x02020F14  thumb
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   MATH_QSort     0x02081BE4  arm
 *   d_021BBBC0     0x021BBBC0  data  ov070  a1
 *   func_021BB5A4  0x021BB5A4  thumb  ov070
 *   func_021BB398  0x021BB398  thumb  ov070
 *   func_0202EB04  0x0202EB04  thumb
 *   func_021B97E8  0x021B97E8  thumb  ov070
 *   func_0202E448  0x0202E448  thumb
 *   func_02012BE0  0x02012BE0  thumb
 *   func_021BB368  0x021BB368  thumb  ov070
 *   func_02012BF8 0x02012BF8 thumb
 *   func_02020F34  0x02020F34  thumb
 *   func_021B8F68  0x021B8F68  thumb  ov070
 *   d_021BB998 0x021BB998 data ov070 a4
 *   d_021BB95C 0x021BB95C data a1
 *   func_021BA9C0 0x021BA9C0 thumb ov070
 *   func_021B624C  0x021B624C  thumb  ov070
 *   func_021B6288  0x021B6288  thumb  ov070
 *   d_021BB984     0x021BB984  data  a4
 *   func_021B97CC  0x021B97CC  thumb  ov070
 *   func_02021D50  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021BB690  0x021BB690  thumb  ov070
 */
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj20665.h"
#include "../../matched/include/Obj20666.h"
#include "../../matched/include/Obj20667.h"
#include "../../matched/include/Obj04328.h"
#include "../../matched/include/Obj20669.h"
#include "../../matched/include/Obj07689.h"
#include "../../matched/include/Obj20670.h"

struct MsgBank;
struct WordSet;
struct Obj;
struct TaskMenu;
struct PrintSys;
struct Ctx;
struct Row;
struct Blk34;
struct Obj_021B7D9C;
struct Rec;
struct Obj_021B7F54;
struct CodeIn;
struct S02021D50;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct RangeEnt {
    u16 lo;
    u16 n;
    void (*fn)(void *);
} RangeEnt;

typedef struct Obj_021B7128 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x51C - 0x014];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x844 - 0x6AC];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    unsigned int f84C;
} Obj_021B7128;

typedef struct Obj_021B7250 Obj_021B7250;

struct Obj_021B7250 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x18 - 0x14];
    void *f018;
    unsigned char pad01C[0x20 - 0x1C];
    unsigned char f020[0x4D8];
    void (*f4F8)(Obj_021B7250 *o);
    unsigned char pad4FC[0x50C - 0x4FC];
    void *f50C;
    unsigned char pad510[0x694 - 0x510];
    void *f694;
    unsigned char pad698[0x6A4 - 0x698];
    void *f6A4;
    unsigned char pad6A8[0x80C - 0x6A8];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    int f81C;
    unsigned char pad820[0x844 - 0x820];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
    void *f850;
    unsigned char pad854[0x85C - 0x854];
    int f85C;
};

typedef signed int     s32;

typedef struct Obj_021B7504 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x844 - 0x780];
    int f844;
} Obj_021B7504;

typedef struct Obj_021B75A4 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj_021B75A4;

typedef struct Obj_021B7640 {
    unsigned char pad000[0x51C];
    void *f51C;
    unsigned char pad520[0x528 - 0x520];
    unsigned int f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj_021B7640;

typedef struct Obj_021B7688 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj_021B7688;

typedef struct Obj_021B7700 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x6A8 - 0x52C];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7700;

typedef struct Obj_021B7804 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7804;

typedef struct Obj_021B7868 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7868;

typedef struct Obj_021B8134 {
    void *f000;
    unsigned char pad004[0x80C - 0x4];
    int f80C;
    unsigned char pad810[0x814 - 0x810];
    int f814;
    int f818;
} Obj_021B8134;

typedef struct Obj_021B80C4 {
    unsigned char pad000[0x81C];
    int f81C;
    unsigned char pad820[0x850 - 0x820];
    void *f850;
} Obj_021B80C4;

typedef struct Obj_021B795C {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x7F4 - 0x6AC];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B795C;

typedef struct Obj_021B8280 Obj_021B8280;

typedef struct Obj_021B7D20 {
    unsigned char pad000[0x18];
    void *gfx;
    unsigned char pad01C[0x544 - 0x1C];
    u16 f544;
    unsigned char pad546[0x810 - 0x546];
    int timerA;
    int timerB;
    unsigned char pad818[0x84C - 0x818];
    int cell;
} Obj_021B7D20;

typedef struct Obj_021B7D9C {
    u8 pad000[0x724];
    u32 winA;
    u32 winB;
    u8 pad72C[0x7F0 - 0x72C];
    int repeat;
    int num;
} Obj_021B7D9C;

typedef struct Obj_021B7A7C Obj_021B7A7C;

typedef struct Obj_021B7B08 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x7F4 - 0x546];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7B08;

typedef struct Obj_021B7B80 {
    void *f000;
    unsigned char pad004[0x51C - 0x004];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x77C - 0x546];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7B80;

typedef struct Obj_021B7C88 Obj_021B7C88;

typedef struct Obj_021B7CD0 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj_021B7CD0;

typedef struct Item {
    u16 id;
    u16 count;
} Item;

typedef struct HitRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} HitRect;

typedef struct HitTbl {
    HitRect r[3];
} HitTbl;

typedef struct Ent {
    Item item;
    u32 key;
} Ent;

typedef struct {
    u8 pad0[0x544];
    u16 f544;
    u8 pad1[0x808 - 0x546];
    int f808;
} Work;

typedef struct Obj_021B7F54 {
    u8 pad000[0x18];
    void *save;
    u8 pad01C[0x544 - 0x1C];
    u16 heap;
    u8 pad546[0x80C - 0x546];
    u32 pocket;
} Obj_021B7F54;

typedef struct Obj_021B822C {
    unsigned char pad00[0x1C];
    int f1C;
} Obj_021B822C;

typedef struct { int v[11]; } T44;

typedef struct { unsigned char v[4]; } T4;

struct Obj_021B8280 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x4F8 - 0x14];
    void (*f4F8)(Obj_021B7250 *o);
    unsigned char pad4FC[0x80C - 0x4FC];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    unsigned char pad81C[0x844 - 0x81C];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
};

typedef struct TabTbl {
    int v[5];
} TabTbl;

extern int func_021BADF0(int p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021BB580(char *p, int v);
extern void func_02027324(u16 id);
extern void func_021B6100(char *p, int k);
extern u32 func_02020FE4(u16 a, u32 sel, u32 id);
extern int  func_021B6EC8(u16 id);
extern int  func_021B690C(u16 id);
extern void func_021B6934(u8 *p);
extern void func_021B6A78(u8 *p);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AD8(int p);
extern void func_021B6138(char *p);
extern void func_021BB3F4(int p, int mode);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021B8AF4(void *o);
extern u8 func_020355C4(void);
extern void func_021B9AAC(char *p);
extern void func_021BA9AC(char *p);
extern void func_02027858(struct TaskMenu *m);
extern int func_021B61B8(unsigned char *p);
extern unsigned short *func_021B616C(char *, int);
extern u32 func_020213E0(u16 v);
extern unsigned int func_0202136C(u16 v);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern void func_021BADAC(void *p);
extern void func_021BADB8(char *p, unsigned v);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_02035C38(void);
extern s32 func_02051C88(struct Ctx *c);
extern s32 func_0202EA40(struct Row *p);
extern u32 func_021B63F8(u8 *p);
extern u32 func_020362DC(void);
extern int func_021B61C8(u8 *p);
extern void func_020061E4(unsigned int se);
extern void func_021B9850(char *p);
extern void func_020355D8(u8 v);
extern void func_021B8C1C(int p, int a, int b);
extern void func_021B8EA8(int p);
extern void func_021B8B7C(int p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void func_0204B878(struct Obj_021B7250 *p, u16 value);
extern void func_021BB5DC(int p, int mode);
extern int func_021B8B0C(void *p);
extern int func_021B6554(void *o);
extern void func_021BA6A4(char *p);
extern unsigned int func_0203633C(void);
extern void func_021B8CE4(int p, int u, int a, int b);
extern void func_021B8F90(void *o);
extern void func_020414EC(u32 i);
extern void func_021BB1AC(char *p);
extern void func_021BB0F8(int p);
extern int func_02006238(void);
extern int func_02035C60(void);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_021BACF0(int p, int mode);
extern u8 func_02021350(u16 id);
extern void func_021B6204(u8 *p, int a, unsigned int b, int c, int d);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_021B8DAC(void);
extern void func_021B8DCC(char *p);
extern void func_021BB08C(char *p);
extern void func_021B8E08(unsigned char *p);
extern int func_021B619C(int a, int b, unsigned int id);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern void func_021BAFC4(u8 *p);
extern void func_021BB0BC(char *p);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void func_021BB1C4(Work *p);
extern void func_021BB260(u8 *p, int val);
extern void func_0204B3DC(struct Obj_021B7D9C *p, u32 v);
extern int func_02035BA4(const void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void *func_02020F14(u32 a);
extern int func_02020F20(int h, int id, u16 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *arc);
extern void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(Ent *, Ent *), void *buf);
extern void func_021BB398(int p, u32 val);
extern void func_0202EB04(struct CodeIn *p);
extern void func_021B97E8(char *p, int mode);
extern u32 func_0202E448(u32 id);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern int func_02012BF8(int p, int a);
extern void *func_02020F34(unsigned int item, unsigned int which, unsigned int heap);
extern int func_021B8F68(char *p, int value);
extern void func_021BA9C0(unsigned char *p, int *tbl, int n);
extern void func_021B624C(void *o, int a, int b);
extern void func_021B6288(struct Obj_021B8280 *o, int a, int b);
extern void func_021B97CC(void *p, int v);
extern void func_02021D50(struct S02021D50 *p);
extern void func_0204A648();
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern int func_021BB690(const char *p);
void func_021B6EF8(u8 *p);
void func_021B7128(Obj_021B7128 *o);
void func_021B7250(Obj_021B7250 *o);
void func_021B7504(Obj_021B7504 *o);
void func_021B7584(int p);
void func_021B75A4(Obj_021B75A4 *o);
void func_021B761C(int p);
void func_021B7640(Obj_021B7640 *o);
void func_021B7688(Obj_021B7688 *o);
void func_021B76E4(int p);
void func_021B7700(Obj_021B7700 *o);
void func_021B77E4(int p);
void func_021B7804(Obj_021B7804 *o);
void func_021B7868(Obj_021B7868 *o);
void func_021B795C(Obj_021B795C *o);
void func_021B7A7C(Obj_021B7A7C *o);
void func_021B7B08(Obj_021B7B08 *o);
void func_021B7B80(Obj_021B7B80 *o);
void func_021B7C88(Obj_021B7C88 *o);
void func_021B7CD0(Obj_021B7CD0 *o);
void func_021B7D20(Obj_021B7D20 *o, int x);
void func_021B7D9C(u8 *p, int v);
void func_021B7DD0(u8 *p);
int func_021B7DF4(Obj_021B7D9C *o);
int func_021B7F38(Ent *a, Ent *b);
void func_021B7F54(Obj_021B7F54 *o);
void func_021B8080(u8 *p);
void func_021B809C(u8 *p);
void func_021B80BC(void *p);
void func_021B80C4(Obj_021B80C4 *o, int flag);
int func_021B811C(u8 *p);
int func_021B8134(Obj_021B8134 *o, int k);
int func_021B81B0(int x);
void func_021B81B8(u8 *p);
void func_021B81F4(u8 *p);
void func_021B822C(Obj_021B822C *o, void *rec, u16 *p, u8 *out);
void func_021B8280(struct Obj_021B8280 *p, unsigned char *q);
void func_021B832C(struct Obj_021B8280 *p);
int func_021B83A0(char *p, int value);
void func_021B83B8(u32 idx, int flag, Obj_021B8280 *o);
void func_021B8600(int u, int p);
void func_021B8640(int p);
void func_021B8688(int p);
extern const RangeEnt d_021BB9C4[8];
extern HitTbl d_021BB960;
extern char d_021BBBC0[];
extern T44 d_021BB998;
extern T4 d_021BB95C;
extern const TabTbl d_021BB984;







/*
 * The switch arms are in the original's layout order (0,1,3,4-5,2,8,9,6,7);
 * the table entry at 0x021BB9C8 is d_021BB9C4[i].fn, one extern through
 * its field (the pool word is the symbol + 4).
 */
void func_021B6EF8(u8 *p)
{
    int flag = 0;
    u32 x;
    int r;

    if (func_021BADF0((int)p) == 0)
        return;
    if (func_020279E8(((struct Obj00002 *)p)->f77C)) {
        x = *(u32 *)(p + 0x828 + func_02027A04(((struct Obj00002 *)p)->f77C) * 4);
        ((struct Obj00002 *)p)->f848 = x;
        switch (x) {
        case 0:
            func_021BB580((char *)p, 0);
            if (*(u32 *)&((struct Obj00002 *)p)->f80C != 4)
                func_02027324(((struct Obj00002 *)p)->f84C);
            if (*(u32 *)&((struct Obj00002 *)p)->f80C == 2) {
                func_021B6100((char *)p, (int)((void *)func_021B7640));
            } else if (func_02020FE4(((struct Obj00002 *)p)->f84C, 0x1D, ((struct Obj00002 *)p)->f544) == 1) {
                ((struct Obj00002 *)p)->f844 = 0xC;
                func_021B6100((char *)p, 0);
            } else if (func_021B6EC8(((struct Obj00002 *)p)->f84C) >= 0) {
                d_021BB9C4[func_021B6EC8(*(u32 *)(p + 0x84C))].fn(p);
            } else {
                r = func_021B690C(((struct Obj00002 *)p)->f84C);
                if (r == 1) {
                    func_021B6100((char *)p, (int)((void *)func_021B6934));
                } else if (r == 2) {
                    func_021B6100((char *)p, (int)((void *)func_021B6A78));
                } else {
                    ((struct Obj00002 *)p)->f844 = 5;
                    func_021B6100((char *)p, 0);
                }
            }
            break;
        case 1:
            func_021BB580((char *)p, 0);
            if (func_02028754(((struct Obj00002 *)p)->fC, 0)) {
                ((struct Obj00002 *)p)->f844 = 0xB;
                func_021B6100((char *)p, 0);
            } else {
                func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x39, (void *)(((struct Obj00002 *)p)->f524));
                func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
                func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
                func_021B6100((char *)p, (int)((void *)func_021B6AD8));
            }
            break;
        case 3:
            func_021B6100((char *)p, (int)((void *)func_021B7804));
            break;
        case 4:
        case 5:
            if (func_021B811C(p) == 1) {
                func_021B8134((Obj_021B8134 *)((struct Obj *)p), *(u32 *)&((struct Obj00002 *)p)->f810);
                func_021B6138((char *)p);
                func_021BB3F4((int)p, 1);
                func_0204B92C(((struct Obj00002 *)p)->f6A8, 1);
                func_021B8AF4(p);
            }
            break;
        case 2:
            func_021BB580((char *)p, 0);
            if ((int)((struct Obj00002 *)p)->f84C >= 0x89 && (int)((struct Obj00002 *)p)->f84C <= 0x94) {
                ((struct Obj00002 *)p)->f844 = 0x13;
                func_021B6100((char *)p, 0);
            }
            break;
        case 8:
            if (func_020355C4() == 1)
                func_021B9AAC((char *)p);
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)p), func_020355C4() == 0);
            func_021BB3F4((int)p, 1);
            func_0204B92C(((struct Obj00002 *)p)->f6A8, 1);
            func_021B8AF4(p);
            break;
        case 9:
            ((struct Obj00002 *)p)->f844 = 1;
            func_021B6100((char *)p, 0);
            break;
        case 6:
            ((struct Obj00002 *)p)->f844 = 2;
            func_021BB580((char *)p, 0);
            func_021B6100((char *)p, 0);
            break;
        case 7:
            break;
        }
        flag = 1;
    }
    if (flag) {
        func_021BA9AC((char *)p);
        func_02027858(((struct Obj00002 *)p)->f77C);
        *(u32 *)&((struct Obj00002 *)p)->f77C = 0;
    }
}








void func_021B7128(Obj_021B7128 *o)
{
    u16 *p;
    int s;

    p = (void *)func_021B616C((char *)((unsigned char *)o), func_021B61B8((unsigned char *)o));
    o->f84C = 0;
    if (p != 0)
        o->f84C = *p;
    s = o->f010;
    if (s == 2) {
        if (func_02020FE4(o->f84C, 3, o->f544) == 0 && func_020213E0(o->f84C) == 1) {
            if (func_0202136C(o->f84C) != 0)
                o->f844 = 0x12;
            else
                o->f844 = 3;
            func_021B6100((char *)o, 0);
            return;
        }
        func_02045CAC(o->f51C, 0x2F, (void *)o->f524);
        func_021B61F4((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB3F4((int)o, 0);
        func_021BB580((char *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7688));
    } else if (s == 5) {
        o->f844 = 1;
        func_021B6100((char *)o, 0);
    } else if (s == 4) {
        func_021B6100((char *)o, (int)((void *)func_021B795C));
    } else {
        func_021B832C((struct Obj_021B8280 *)((struct Obj_021B7128 *)o));
        func_021BADB8((char *)o, o->f84C);
        func_021BADAC(o);
        func_0204B92C((struct Obj *)o->f6A8, 0);
        func_021B6100((char *)o, (int)((void *)func_021B6EF8));
    }
}








void func_021B7250(Obj_021B7250 *o)
{
    unsigned int k;
    int v;

    if (func_0201C6B4(o->f50C) == 0)
        return;
    if (func_02035C38() == 0)
        o->f85C = 0;
    func_02051C88(o->f694);
    func_0202EA40(o->f850);
    if (o->f4F8 != func_021B7250)
        return;
    if (func_021B63F8((u8 *)o) != 0) {
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        return;
    }
    if (o->f85C == 1)
        return;
    if (func_020355C4() == 1) {
        k = func_020362DC();
        if (k == 0)
            return;
        if (func_021B61C8((u8 *)o) != 0) {
            if ((k & 0xC0A) == 0) {
                func_020061E4(0x548);
                func_021B9850((char *)o);
                func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
                return;
            }
        } else {
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
            if (k & 0xCD)
                return;
        }
    }
    if (func_020362DC() & 2) {
        o->f844 = 1;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C((int)o, 4, 0);
        return;
    }
    if (func_020362DC() & 0x400) {
        if (o->f010 == 2)
            return;
        o->f844 = 0;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C((int)o, 3, 0);
        return;
    }
    if (func_020362DC() & 0x800) {
        if (func_021B811C((u8 *)o) != 1)
            return;
        if (o->f80C == 4) {
            func_021B8134((Obj_021B8134 *)((struct Obj *)o), o->f810);
            func_021B6138((char *)o);
        } else {
            func_021B81B8((u8 *)o);
        }
        if (func_020355C4() != 1)
            return;
        func_021B9850((char *)o);
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
        return;
    }
    if ((func_020362DC() & 8) && o->f80C != 2 && o->f80C != 3 && func_021B61C8((u8 *)o) > 1) {
        func_021B8080((u8 *)o);
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        func_021B6100((char *)o, (int)((void *)func_021B8EA8));
        return;
    }
    if (func_020362DC() & 1) {
        if (func_021B61C8((u8 *)o) > 0) {
            func_021B6100((char *)o, (int)((void *)func_021B8B7C));
            return;
        }
    } else if (func_020362DC() & 4) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8((u8 *)o) > 1) {
            func_02082BCC(o->f020, 0, 0x4D8);
            func_02007CC8(o->f018, o->f020, o->f80C, 1);
            func_0204B878(o->f6A4, 2);
            func_021BB5DC((int)o, 0);
            o->f81C = 1;
            func_021B8B0C(o);
        }
        return;
    } else if (func_021B6554(o) != 0) {
        func_021BA6A4((char *)o);
        func_020061E4(0x548);
        func_021B6138((char *)o);
        return;
    }
    if (func_0203633C() & 0x10) {
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_020355D8(0);
        func_021B8CE4((int)o, v, 1, (int)((void *)func_021B8F90));
        return;
    }
    if (func_0203633C() & 0x20) {
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_020355D8(0);
        func_021B8CE4((int)o, v, 0, (int)((void *)func_021B8F90));
    }
}







void func_021B7504(Obj_021B7504 *o)
{
    if (func_020279E8(o->f77C) == 0)
        return;
    if (func_02027A04(o->f77C) == 0) {
        func_021BA9AC((char *)o);
        o->f844 = 6;
        func_021B6100((char *)o, 0);
    } else {
        func_021BA9AC((char *)o);
        func_020414EC(3);
        func_0204B92C((struct Obj *)o->f6A8, 1);
        func_021BB3F4((int)o, 1);
        if (func_020355C4() == 1) {
            func_021B9AAC((char *)o);
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 0);
        } else {
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
        }
        func_021B8AF4(o);
    }
    func_021BB1AC((char *)o);
}






void func_021B7584(int p) { if (func_021BADF0(p)) { func_021BB0F8(p); func_021B6100((void *)p,(int)((void *)func_021B7504)); } }







void func_021B75A4(Obj_021B75A4 *o)
{
    if (func_02006238() == 1)
        return;
    if ((func_020362DC() & 3) == 0 && func_02035C60() == 0)
        return;
    func_02045CAC(o->f51C, 0x3E, (void *)o->f524);
    func_0201EF34(o->f520, 0, func_020212B0(o->f84C));
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BACF0((int)o, 1);
    func_021B6100((char *)o, (int)((void *)func_021B7584));
}






void func_021B761C(int p) { if (func_021BADF0(p)) { func_020061E4(0x55C); func_021B6100((void *)p,(int)((void *)func_021B75A4)); } }






void func_021B7640(Obj_021B7640 *o)
{
    if (func_02021350(o->f84C) == 0xFF)
        func_02045CAC(o->f51C, 0x3C, (void *)o->f528);
    else
        func_02045CAC(o->f51C, 0x3D, (void *)o->f528);
    func_021BACF0((int)o, 1);
    func_021B6100((char *)o, (int)((void *)func_021B761C));
}






void func_021B7688(Obj_021B7688 *o)
{
    if ((func_020362DC() & 3) || func_02035C60() != 0) {
        func_020414EC(3);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        o->f83E = 1;
        func_021BA6A4((char *)o);
        func_0204B92C((struct Obj *)o->f6A8, 1);
        func_021BB3F4((int)o, 1);
        func_021B8AF4(o);
    }
}





void func_021B76E4(int p) { if (func_021BADF0(p)) func_021B6100((void *)p,(int)((void *)func_021B7688)); }






void func_021B7700(Obj_021B7700 *o)
{
    int r;
    int v;

    if (func_020279E8(o->f77C) == 0)
        return;
    r = func_02027A04(o->f77C);
    func_021BB1AC((char *)o);
    func_020414EC(3);
    if (r == 0) {
        func_020061E4(0x647);
        func_021B7D20((Obj_021B7D20 *)o, o->f7F4);
        func_02045CAC(o->f51C, 0x36, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B76E4));
    } else {
        func_0204B92C((struct Obj *)o->f6A8, 1);
        v = 1;
        func_021BB3F4((int)o, 1);
        if (func_020355C4() != 0)
            v = 0;
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), v);
        func_021B8AF4(o);
    }
}





void func_021B77E4(int p) { if (func_021BADF0(p)) { func_021BB0F8(p); func_021B6100((void *)p,(int)((void *)func_021B7700)); } }






void func_021B7804(Obj_021B7804 *o)
{
    o->f7F4 = 1;
    func_021B7D9C((u8 *)o, 1);
    func_02045CAC(o->f51C, 0x35, (void *)o->f524);
    func_021B6204((u8 *)o, 0, o->f84C, 1, 0);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7868));
}






void func_021B7868(Obj_021B7868 *o)
{
    int r;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_021B7DF4((Obj_021B7D9C *)o) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0((u8 *)o);
        func_02045CAC(o->f51C, 0x37, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B77E4));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C((int)o, 4, (int)((void *)func_021B8DCC));
    }
}






void func_021B795C(Obj_021B795C *o)
{
    unsigned int a;
    unsigned int b;

    func_0204B92C((struct Obj *)o->f6A8, 0);
    a = func_02020FE4(o->f84C, 0, (u32)o->f544);
    b = func_02020FE4(o->f84C, 3, (u32)o->f544);
    if (a == 0 || b != 0) {
        func_021BB3F4((int)o, 0);
        func_02045CAC(o->f51C, 0x4D, (void *)o->f524);
        func_021B61F4((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB580((char *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7C88));
        return;
    }
    o->f7F4 = 1;
    func_021BB08C((char *)o);
    func_021BB3F4((int)o, 0);
    if (func_021B616C((char *)o, func_021B61B8((u8 *)o))[1] == 1) {
        func_021B6100((char *)o, (int)((void *)func_021B7B08));
        return;
    }
    func_021B7D9C((u8 *)o, 2);
    func_02045CAC(o->f51C, 0x4E, (void *)o->f524);
    func_021B61F4((u8 *)o, 0, o->f84C);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7A7C));
}






void func_021B7A7C(Obj_021B7A7C *o)
{
    int r;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_021B7DF4((Obj_021B7D9C *)o) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0((u8 *)o);
        func_021B6100((char *)o, (int)((void *)func_021B7B08));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C((int)o, 4, (int)((void *)func_021B8E08));
    }
}






void func_021B7B08(Obj_021B7B08 *o)
{
    int v;

    func_021BB0F8((int)o);
    v = func_021B619C(o->f84C, o->f7F4, o->f544);
    func_02045CAC(o->f51C, 0x4F, (void *)o->f524);
    func_0201EFA4(o->f520, 0, v, 7, 0, 1);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7B80));
}





void func_021B7B80(Obj_021B7B80 *o)
{
    int r;
    int v;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_020279E8(o->f77C) == 0)
        return;
    r = func_02027A04(o->f77C);
    func_021BB1AC((char *)o);
    switch (r) {
    case 0:
        v = func_021B619C(o->f84C, o->f7F4, o->f544);
        func_021B7D20((Obj_021B7D20 *)o, o->f7F4);
        func_0200C278((struct Blk34 *)((unsigned int)func_02012F08(o->f000)), v);
        func_020061E4(0x655);
        func_021BAFC4((u8 *)o);
        func_02045CAC(o->f51C, 0x50, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, v, 7, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B7C88));
        break;
    case 1:
        func_021B80C4((Obj_021B80C4 *)o, func_020355C4() == 0);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
        break;
    }
}





void func_021B7C88(Obj_021B7C88 *o)
{
    if (func_021BADF0((int)o) == 0)
        return;
    if (func_020362DC() & 3) {
        func_021B80C4((Obj_021B80C4 *)o, 1);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
        return;
    }
    if (func_02035C60() != 0) {
        func_021B80C4((Obj_021B80C4 *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
    }
}






void func_021B7CD0(Obj_021B7CD0 *o)
{
    func_020414EC(3);
    o->f818 = 0xFFFF;
    func_021B6138((char *)o);
    o->f83E = 1;
    func_021BA6A4((char *)o);
    func_021BB0BC((char *)o);
    func_0204B92C((struct Obj *)o->f6A8, 1);
    func_021BB3F4((int)o, 1);
    func_021B8AF4(o);
}






void func_021B7D20(Obj_021B7D20 *o, int x)
{
    int v;

    func_021B616C((char *)((unsigned char *)o), func_021B61B8((unsigned char *)o));
    func_02007F1C(o->gfx, o->cell, x, o->f544);
    if (func_02007FB8(o->gfx, o->cell, o->f544) != 0)
        return;
    if (func_021B61C8((unsigned char *)o) + 1 < 7) {
        v = o->timerA - 1;
        if (v <= 0)
            v = 0;
        o->timerA = v;
    } else {
        v = o->timerB - 1;
        if (v < -1)
            v = -1;
        o->timerB = v;
    }
}




void func_021B7D9C(u8 *p, int v) { ((struct Obj00002 *)p)->f7EC=v; func_021BB1C4((Work *)p); func_021BB260(p,((struct Obj00002 *)p)->f7F4); func_0204B3DC(((struct Obj00002 *)p)->f724, 1); func_0204B3DC(((struct Obj00002 *)p)->f728, 1); }




void func_021B7DD0(u8 *p) { func_020414EC(3); func_0204B3DC(((struct Obj00002 *)p)->f724, 0); func_0204B3DC(((struct Obj00002 *)p)->f728, 0); }





/*
 * Quantity selector input: touch buttons (hit table d_021BB960, with
 * auto-repeat accelerating after 120 frames) or the d-pad step the count at
 * +0x7F4 by 1 or 10, wrap it between 1 and the item's count, and redraw on
 * change. Returns whether any input was taken.
 */
int func_021B7DF4(Obj_021B7D9C *o)
{
    HitTbl tbl;
    Item *e;
    int saved;
    int hit;
    int changed;
    int dir;

    changed = 0;
    saved = o->num;
    e = (void *)func_021B616C((char *)((u8 *)o), func_021B61B8((u8 *)o));
    tbl = d_021BB960;
    hit = func_02035BA4(&tbl);
    if (hit != -1) {
        o->repeat++;
        changed = 1;
    } else {
        o->repeat = 0;
    }
    if (o->repeat == 1 || o->repeat > 30) {
        switch (hit) {
        case 0:
            if (o->repeat > 120)
                o->num += 10;
            else
                o->num += 1;
            dir = 0;
            break;
        case 1:
            if (o->repeat > 120)
                o->num -= 10;
            else
                o->num -= 1;
            dir = 1;
            break;
        }
    }
    if (hit == -1) {
        if (func_0203633C() & 0x40) {
            o->num += 1;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x80) {
            o->num -= 1;
            dir = 1;
            changed = 1;
        } else if (func_0203633C() & 0x10) {
            o->num += 10;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x20) {
            o->num -= 10;
            dir = 1;
            changed = 1;
        }
    }
    if (e->count < o->num)
        o->num = 1;
    else if (o->num < 1)
        o->num = e->count;
    if (o->num != saved) {
        func_020061E4(0x548);
        if (dir == 0)
            func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7D9C *)o->winA), 0xB);
        else
            func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7D9C *)o->winB), 0xA);
        func_021BB260((u8 *)o, o->num);
    }
    return changed;
}





int func_021B7F38(Ent *a, Ent *b)
{
    if (a->key == b->key)
        return 0;
    if (a->key > b->key)
        return 1;
    return -1;
}





void func_021B7F54(Obj_021B7F54 *o)
{
    int i;
    Ent *ents;
    Item *items;
    int n;
    int h;
    int rec;
    u32 x;
    Ent *e;

    ents = func_02030734(o->heap, 0x9B0, 0, d_021BBBC0, 0xB35);
    items = func_02030734(o->heap, 0x4D8, 0, d_021BBBC0, 0xB36);
    sub_02007CC8(o->save, items, o->pocket, 1);
    n = func_021B61C8((u8 *)o);
    h = (int)func_02020F14(o->heap);
    for (i = 0; i < n; i++) {
        rec = func_02020F20(h, items[i].id, o->heap);
        e = &ents[i];
        x = func_02021014((struct Rec *)rec, 0xF);
        e->key = (x << 28) + (func_02021014((struct Rec *)rec, 0x11) << 16) + items[i].id;
        e->item = items[i];
        func_020307B0((void *)rec);
    }
    func_02049238((void *)h);
    MATH_QSort(ents, n, 8, func_021B7F38, 0);
    for (i = 0; i < n; i++) {
        items[i] = ents[i].item;
    }
    sub_02007CC8(o->save, items, o->pocket, 0);
    func_020307B0(items);
    func_020307B0(ents);
}




void func_021B8080(u8 *p) { func_020061E4(0x663); func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7F54 *)(((struct Obj20665 *)p)->f72C)), 2); }




void func_021B809C(u8 *p) { func_021B7F54((Obj_021B7F54 *)((struct Obj_021B7F54 *)p)); ((struct Obj20666 *)p)->f818=0xFFFF; func_021B6138((char *)p); }




void func_021B80BC(void *p)
{
    void func_021BB5A4(char *p);
    func_021BB5A4(p);
}





void func_021B80C4(Obj_021B80C4 *o, int flag)
{
    if (o->f81C == 1)
        flag = 1;
    if (flag)
        func_020355D8(0);
    else
        func_020355D8(1);
    if (func_021B61C8((u8 *)o) == 0)
        flag = 0;
    if (flag == 0) {
        func_021BB398((int)o, 0);
    } else {
        func_021BB398((int)o, 1);
        func_0202EB04(o->f850);
    }
    func_021B97E8((char *)o, flag);
}




int func_021B811C(u8 *p) { int v = ((struct Obj20667 *)p)->f10; if (v==0 || v==1 || v==3) return 1; return 0; }





int func_021B8134(Obj_021B8134 *o, int k)
{
    u16 *p;
    int v;

    k += o->f814 + 1;
    if (o->f80C == 4) {
        if (func_021B61C8((u8 *)o) <= k)
            return 0;
        p = (void *)func_021B616C((char *)((u8 *)o), k);
        v = func_0202E448(*p);
        if (v == 0x19)
            return 0;
        if (func_021B83A0((char *)o, *p) == 1)
            func_02012BE0(o->f000, v, 0);
        else
            func_02012BE0(o->f000, v, 1);
        func_020061E4(0x646);
        o->f818 = 0xFFFF;
        return 1;
    }
    return 0;
}




int func_021B81B0(int x)
{
    int func_021BB368(int);
    return func_021BB368(x);
}




void func_021B81B8(u8 *p) { int a; int v; a=func_021B81B0(((struct Obj04328 *)p)->f80C); v=func_02012BF8(*(int *)&((struct Obj04328 *)p)->f0,a); func_02012BE0(((struct Obj04328 *)p)->f0,a,v^1); func_020061E4(0x646); func_021B81F4(p); }




void func_021B81F4(u8 *p) { if (((struct Obj04328 *)p)->f81C!=1) func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7F54 *)(((struct Obj04328 *)p)->f718)), (unsigned int)func_02012BF8(*(int *)&((struct Obj04328 *)p)->f0,func_021B81B0(((struct Obj04328 *)p)->f80C))+6u); }





void func_021B822C(Obj_021B822C *o, void *rec, u16 *p, u8 *out)
{
    if (func_02021014(rec, 6) != 0) {
        if (func_0202136C(*p) == 1)
            *out = 2;
        else if (*p == 0x1C2 && o->f1C == 1)
            *out = 1;
        else
            *out = 0;
    }
    if ((u16)(*p + 0xFD98) <= 1)
        *out = 0;
}




void func_021B8280(struct Obj_021B8280 *p, unsigned char *q)
{
    unsigned short *e = (void *)func_021B616C((char *)((u8 *)p), func_021B61B8((u8 *)p));
    if (e != 0 && *e != 0) {
        void *h = func_02020F34(*e, 0, ((struct Obj00002 *)p)->f544);
        unsigned char v = ((struct Obj00002 *)p)->f80C;
        func_021B822C((Obj_021B822C *)p, h, e, q);
        if (func_021B8F68((char *)p, v) == 0 && q[0] != 2) {
            q[0] = 0xFF;
        }
        if (func_02021014(h, 3) == 0) {
            if (func_020213E0(*e) == 1) {
                q[1] = 6;
            }
            if (v != 2) {
                q[2] = 3;
            }
        }
        if (func_02021014(h, 4) != 0) {
            if (func_021B83A0((char *)p, *e) == 1) {
                q[2] = 5;
            } else {
                q[2] = 4;
            }
        }
        q[3] = 8;
        func_020307B0(h);
    }
}



/*
 * lever: func_021BA9C0 reads the count in r2; passing j keeps it in r2.
 */
void func_021B832C(struct Obj_021B8280 *p)
{
    T44 t = d_021BB998;
    T4 a = d_021BB95C;
    int tmp[4];
    int j;
    int i;
    func_021B8280((struct Obj_021B8280 *)p, (unsigned char *)(&a));
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int c = a.v[i];
        if (c != 0xFF) {
            *(int *)((char *)p + j * 4 + 0x828) = c;
            tmp[j] = t.v[a.v[i]];
            j++;
        }
    }
    func_021BA9C0((unsigned char *)p, tmp, j);
}



int func_021B83A0(char *p, int value)
{
    return func_02012BF8(((struct Obj20669 *)p)->f0, (int)func_0202E448((u16)value));
}




/*
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table d_021BB984, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of func_021B7250's key handling.
 */
void func_021B83B8(u32 idx, int flag, Obj_021B8280 *o)
{
    int tab;
    int count;
    int v;
    int saved;
    int cur;
    TabTbl t;

    tab = -1;
    count = func_021B61C8((unsigned char *)o);
    if (flag != 0)
        return;
    if (idx < 5) {
        t = d_021BB984;
        if (o->f80C != t.v[idx]) {
            tab = t.v[idx];
            func_021B80C4((Obj_021B80C4 *)o, 0);
        }
    } else if (idx == 5) {
        func_021B80C4((Obj_021B80C4 *)o, 0);
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_021B8CE4((int)o, v, 0, (int)((void *)func_021B8F90));
        return;
    } else if (idx == 6) {
        func_021B80C4((Obj_021B80C4 *)o, 0);
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_021B8CE4((int)o, v, 1, (int)((void *)func_021B8F90));
        return;
    } else if (idx == 7) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8((unsigned char *)o) > 1) {
            func_021B8080((u8 *)o);
            func_021B80C4((Obj_021B80C4 *)o, 0);
            o->f818 = 0xFFFF;
            func_021B6138((char *)o);
            func_021B6100((char *)o, (int)((void *)func_021B8EA8));
        }
    } else if (idx == 8) {
        if (func_021B811C((u8 *)o) == 1) {
            func_021B81B8((u8 *)o);
            func_021B80C4((Obj_021B80C4 *)o, 0);
            o->f818 = 0xFFFF;
            func_021B6138((char *)o);
        }
    } else if (idx == 9) {
        if (o->f010 != 2) {
            o->f844 = 0;
            o->f84C = 0;
            func_021B8C1C((int)o, 3, 0);
            func_020355D8(1);
        }
    } else if (idx == 10) {
        o->f844 = 1;
        o->f84C = 0;
        func_021B8C1C((int)o, 4, 0);
        func_020355D8(1);
    } else if (idx >= 11 && idx < 17) {
        if (o->f4F8 != func_021B7250)
            return;
        saved = o->f810;
        cur = func_021B61B8((u8 *)o);
        if (func_021B61C8((unsigned char *)o) == 0)
            return;
        if (o->f810 != idx - 11) {
            o->f810 = idx - 11;
            if (count <= func_021B61B8((u8 *)o)) {
                o->f810 = saved;
                return;
            }
        }
        func_021B624C(o, cur, func_021B61B8((u8 *)o));
        func_021B80C4((Obj_021B80C4 *)o, 0);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        func_021B9850((char *)o);
        func_021B6100((char *)o, (int)((void *)func_021B8B7C));
        return;
    } else if (idx >= 17) {
        if (func_021B811C((u8 *)o) == 1 && func_021B8134((Obj_021B8134 *)o, idx - 17) == 1) {
            func_021B80C4((Obj_021B80C4 *)o, 0);
            func_021B6138((char *)o);
        }
    }
    if (tab != -1) {
        v = o->f80C;
        o->f80C = tab;
        func_020061E4(0x7D9);
        func_021B6288((struct Obj_021B8280 *)o, v, o->f80C);
        func_021B80BC(o);
        func_021B80C4((Obj_021B80C4 *)o, 0);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
    }
}




void func_021B8600(int u, int p)
{
    int s = ((struct Obj07689 *)p)->f840;
    if (s == 1) {
        func_021B97CC((void *)p, 1);
        ((struct Obj07689 *)p)->f840 = 0;
    } else if (s == 2) {
        func_021B97CC((void *)p, 0);
        ((struct Obj07689 *)p)->f840 = 0;
    }
    func_02021D50((struct S02021D50 *)(((struct Obj07689 *)p)->f854));
    func_0204A648();
}




void func_021B8640(int p)
{
    if (func_0201C6B4((const struct PrintSys *)(*(int *)&((struct Obj00002 *)p)->f50C))) {
        func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj00002 *)p)->f544);
        func_020061E4(0x79F);
        func_021B6100((char *)p, (int)func_021B8688);
    }
}




/*
 * blocked:
 */
void func_021B8688(int p)
{
    int a = func_020221A4();
    int b = func_021BB690((const char *)p);
    if (a == 1 && b == 0) {
        func_0204B92C((struct Obj *)((struct Obj20670 *)p)->f6A8, 1);
        func_021B8AF4((void *)p);
    }
}
