/*
 * file:     ctvt_draw_p02.c
 * unit:     yes
 * function: func_021BBA6C, func_021BBA88, func_021BBA94, func_021BBE5C, func_021BBF2C, func_021BC5E8, func_021BC7FC, func_021BCB88, func_021BCC40, func_021BCE2C, func_021BCEF8, func_021BD038, func_021BD0A4
 * address:  0x021BBA6C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_021C7234    0x021C7234  data  ov172
 *   func_020307B0  0x020307B0  arm
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE010  0x021BE010  thumb  ov172
 *   func_021BE018  0x021BE018  thumb  ov172
 *   func_021BE024  0x021BE024  thumb  ov172
 *   func_021BE004  0x021BE004  thumb  ov172
 *   func_021BE0EC  0x021BE0EC  thumb  ov172
 *   func_021BD134  0x021BD134  thumb  ov172
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B878  0x0204B878  arm
 *   d_021C7234     0x021C7234  data
 *   func_02028148  0x02028148  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021BE02C  0x021BE02C  thumb  ov172
 *   func_021BE030  0x021BE030  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_021BE054  0x021BE054  thumb  ov172
 *   func_021BE0D0  0x021BE0D0  thumb  ov172
 *   func_021BE0F0  0x021BE0F0  thumb  ov172
 *   func_021BE318  0x021BE318  thumb  ov172
 *   func_021BE34C  0x021BE34C  thumb  ov172
 *   func_021BDFDC  0x021BDFDC  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021B7B64  0x021B7B64  thumb  ov172
 *   func_021B80DC  0x021B80DC  thumb  ov172
 *   func_021B80EC  0x021B80EC  thumb  ov172
 *   func_021B8B7C  0x021B8B7C  thumb  ov172
 *   func_021B8C14  0x021B8C14  thumb  ov172
 *   func_021B8C20  0x021B8C20  thumb  ov172
 *   func_021BD0C4  0x021BD0C4  thumb  ov172
 *   func_02035D20  0x02035D20  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B404  0x0204B404  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0202824C  0x0202824C  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02035C08  0x02035C08  arm
 *   func_020362DC  0x020362DC  arm
 *   d_021C7040     0x021C7040  data
 *   func_021B8108  0x021B8108  thumb  ov172
 *   func_0203CF10  0x0203CF10  arm
 *   func_0203CF3C  0x0203CF3C  arm
 *   func_02177B80  0x02177B80  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_021B85D0  0x021B85D0  thumb  ov172
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0202E930  0x0202E930  thumb
 *   func_02045994  0x02045994  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202E938  0x0202E938  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_021BE04C  0x021BE04C  thumb  ov172
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02027FEC  0x02027FEC  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D50  0x02009D50  thumb
 */
#include "../../matched/include/Obj03316.h"
#include "../../matched/include/Obj08261.h"
#include "../../matched/include/Obj00330.h"
#include "../../matched/include/Obj01950.h"
#include "../../matched/include/Obj01951.h"
#include "../../matched/include/Obj01166.h"
#include "../../matched/include/Obj02882.h"
#include "../../matched/include/Obj24102.h"
#include "../../matched/include/Obj01560.h"
#include "../../matched/include/Obj24103.h"
#include "../../matched/include/Obj00543.h"
#include "../../matched/include/Obj01266.h"

#define MK(c, p, a1, a2, a3, sp) func_0204B294((void *)func_021BE024(c), func_021BE018(c, a1), func_021BE018(c, a2), func_021BE018(c, a3), &d, sp, v)
#define W(o) (*(u32_021BBF2C *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define OBJ (*(struct Obj **)(p + 0x400))
struct Obj;
struct Descriptor;
struct Cfg;
struct PrintSys;
struct Actor;
struct Vec2;
struct Sub0200852CObj;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Strbuf;
struct BigObj;
struct Sub020097BCObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32_021BBA6C;

typedef signed int     s32;

typedef unsigned int   u32_021BBA88;

typedef unsigned int   u32_021BBA94;

typedef signed short   s16;

struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

typedef unsigned int   u32_021BBE5C;

typedef unsigned int   u32_021BBF2C;

typedef unsigned long u32_021BC5E8;

struct SpritePos {
    s16 x;
    s16 y;
};

typedef unsigned long u32_021BC7FC;

struct Info {
    u8 pad0[2];
    u8 b2_0 : 1;
    u8 b2_1 : 5;
    u8 b2_6 : 2;
    u8 pad3[8];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32_021BC7FC w4dummy;
};

struct Rec {
    u8 pad0[4];
    u32_021BC7FC f4;
    u8 pad8[3];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32_021BC7FC fC_0 : 17;
    u32_021BC7FC fC_17 : 10;
    u32_021BC7FC fC_27 : 5;
    u8 pad10[0x10];
    u8 f20;
    u8 f21_0 : 1;
    u8 f21_1 : 1;
    u8 f21_2 : 6;
};

struct Bits2 {
    u8 b0 : 1;
    u8 b1 : 5;
    u8 b6 : 2;
};

struct Slot {
    u32_021BC7FC active;
    u32_021BC7FC unseen;
    u32_021BC7FC f8;
    u8 padC[8];
    u8 *buf;
    u8 kind;
    u8 mac[6];
    u8 pad1f;
    u8 row;
    u8 pad21[3];
};

struct List {
    u8 pad[0x1e4];
    struct Slot slots[15];
};

typedef unsigned long u32_021BCB88;

typedef unsigned long u32_021BCC40;

struct FlagsA {
    u8 pad[0x21];
    u8 on : 1;
    u8 rest : 7;
};

struct FlagsB {
    u8 pad[2];
    u8 low : 6;
    u8 b6 : 1;
    u8 b7 : 1;
};

typedef unsigned long u32_021BCE2C;

typedef unsigned long u32_021BCEF8;

struct Prompt {
    u32_021BCEF8 str;
    u16 color;
    u16 pad;
    u32_021BCEF8 flags;
};

typedef unsigned long u32_021BD038;

typedef unsigned long u32_021BD0A4;

extern void *func_02030734(u32_021BBA6C heapId, u32_021BBA6C size, int clear, const char *site, u16 tag);
extern u32_021BBA88 func_020307B0(void *p);
extern u16 func_021BE00C(u16 *p);
extern u32_021BBA94  func_021BE010(void *c);
extern u32_021BBA94  func_021BE018(void *c, int i);
extern u32_021BBA94  func_021BE024(void *c);
extern u32_021BBA94 func_021BE004(void *p);
extern u32_021BBA94 func_021BE0EC(void *c);
extern void func_021BD134(void *ctx, char *st, u32_021BBA94 msgId);
extern u32_021BBA94 func_02049658(void *a, u32_021BBA94 b, u32_021BBA94 c, u32_021BBA94 d, u32_021BBA94 e, u32_021BBA94 f, u16 g);
extern void func_020498F4(void *a, u32_021BBA94 b, u32_021BBA94 c, u32_021BBA94 d, u32_021BBA94 e, u32_021BBA94 f, u16 g);
extern void func_020409B4(u32_021BBA94 a);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32_021BBA94 v);
extern void func_0204B3DC(struct Obj *o, unsigned int k);
extern u32_021BBA94 func_020450F0(u32_021BBA94 layer, u32_021BBA94 a, u32_021BBA94 b, u32_021BBA94 tiles, u8 c, u8 d, u8 slot);
extern void func_02041EE4(u32_021BBA94 index, u32_021BBA94 a, u32_021BBA94 b);
extern void func_0204B878(struct Obj *, u16);
extern void func_02028148(u8 *p);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32_021BBE5C func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_020414EC(u32_021BBE5C i);
extern u32_021BBF2C func_021BE02C(void *c);
extern void func_021BE030(void *c, u32_021BBF2C v);
extern u32_021BBF2C func_021BE044(void *c);
extern u8 func_021BE054(void *c);
extern u32_021BBF2C func_021BE0D0(void *c);
extern void func_021BE0F0(u8 *c);
extern void func_021BE318(char *a0, void *a1);
extern void func_021BE34C(void *c);
extern u32_021BBF2C func_021BDFDC(void *c);
extern u32_021BBF2C func_021BDFE4(void *c);
extern void func_021B7578(int x, char *p);
extern int func_021B7590(int x, char *p);
extern void func_021B7B64(int x, char *p);
extern void func_021B80DC(int unused, char *p, u32_021BBF2C v);
extern void func_021B80EC(int unused, char *p, const u8 *src);
extern u8 *func_021B8B7C(void *c, u8 *x);
extern void func_021B8C14(void *c, u8 *x);
extern u32_021BBF2C func_021B8C20(void *c, u8 *x);
extern void func_021BD0C4(void *c, char *p, int msg);
extern void func_0202208C(void *p1, u32_021BBF2C p2, u32_021BBF2C p3, u32_021BBF2C p4, u32_021BBF2C p5, u32_021BBF2C p6, u32_021BBF2C p7);
extern u32_021BBF2C func_020221A4(void);
extern int func_02035C60(void);
extern u32_021BBF2C func_0204B98C(struct Actor *a);
extern u32_021BBF2C func_02028230(u8 *p);
extern void func_02028178(u8 *p);
extern void func_02006210(void);
extern void func_020061E4(u32_021BBF2C id);
extern void func_0200616C(void *arg, int i);
extern void func_0201F7A8(void *desc, u32_021BBF2C kind);
extern u32_021BBF2C func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *w);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32_021BBF2C a);
extern u32_021BC5E8 func_02035D20(u32_021BC5E8 *outA, u32_021BC5E8 *outB);
extern u32_021BC5E8 func_02035CB8(u32_021BC5E8 *outA, u32_021BC5E8 *outB);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021BC5E8 which);
extern u32_021BC5E8 func_0202824C(void **p);
extern void func_0202822C(char *p, int v);
extern int func_02035C08(const void *p);
extern u32_021BC5E8 func_020362DC(void);
extern int func_021B8108(void *unused, void *p);
extern u32_021BC7FC func_0203CF10(u32_021BC7FC a);
extern void *func_0203CF3C(u32_021BC7FC a);
extern u8 func_02177B80(int i);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32_021BC7FC func_02008530(const struct Sub0200852CObj *obj);
extern void func_02087C6C(void *p);
extern int func_021B85D0(unsigned char *p, unsigned char *q);
extern u32_021BC7FC func_02013D5C(u32_021BC7FC id);
extern u32_021BC7FC func_02013D9C(u32_021BC7FC id);
extern void func_02082D44(const void *src, void *dst, u32_021BC7FC n);
extern u32_021BCC40 func_021BE034(void *p);
extern u32_021BCC40 func_021BE03C(void *p);
extern struct WordSet *func_0201EC64(u32_021BCC40 heap);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct U16Vec *func_020457B0(u32_021BCC40 capacity, u32_021BCC40 heapId);
extern u16 *func_0202E930(void *p);
extern void func_02045994(struct Strbuf *o, const u16 *src, unsigned int len);
extern void func_0201C724(void *owner, u32_021BCC40 a, u32_021BCC40 b, u32_021BCC40 c, u32_021BCC40 d, u32_021BCC40 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32_021BCC40 index);
extern u16 func_0202E938(void *p);
extern void func_0201EFA4(struct WordSet *p, u32_021BCC40 i, u32_021BCC40 a, u32_021BCC40 b, u32_021BCC40 c, u32_021BCC40 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32_021BCC40 func_0201ED04(struct WordSet *p);
extern u32_021BCEF8 func_021BE04C(void *p);
extern u32_021BCEF8 func_02027FEC(u32_021BCEF8 a0, u32_021BCEF8 a1, u32_021BCEF8 a2, u32_021BCEF8 a3, u8 a4, u16 a5);
extern u32_021BD0A4 func_0201283C(const struct BigObj *p);
extern int func_02009D50(struct Sub020097BCObj *obj, const void *unused, u32_021BD0A4 id, u32_021BD0A4 kind, u32_021BD0A4 *out);
void *func_021BBA6C(int unused, void *p);
void func_021BBA88(int unused, int v);
void func_021BBA94(void *a0, u8 *p);
void func_021BBE5C(void *a0, char *a1);
int func_021BBF2C(void *a0, char *p);
void func_021BC5E8(void *ctx, u8 *list);
void func_021BC7FC(void *ctx, u8 *list);
void func_021BCB88(void *ctx, char *list);
void func_021BCC40(void *ctx, char *list, char *row, int idx);
void func_021BCE2C(void *ctx, char *list, char *cur, u8 idx);
void func_021BCEF8(void *ctx, u8 *st);
void func_021BD038(void *ctx, char *st);
int func_021BD0A4(void *ctx, u32_021BD0A4 unused, u32_021BD0A4 a, u32_021BD0A4 b, u32_021BD0A4 c);
extern u32_021BBA6C g_021C7234[];
extern u8 d_021C7234[];
extern const u8 d_021C7040[];


void *func_021BBA6C(int unused, void *p)
{
    return func_02030734((u32_021BBA6C)p, 0x408, 1, (const char *)g_021C7234, 0xd8);
}


/*
 * Tail call to func_020307B0, second argument forwarded.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBA88(int unused, int v)
{
    func_020307B0((void *)v);
}


/*
 * Scene setup: fifteen rows of three sprite objects (stride 0x1c), the objects at +0x400 and
 * +0x404, fifteen 0x24-byte entries with text buffers, fifteen windows, then state clears.
 * note 2026-10-05 (wD7 lane03): EXACT. Closing levers: the d.z choice as an if/else (the ternary
 * gave the inverted branch layout and changed the whole colouring), the missing `d.a = 0x10` in
 * the third object of each row (logic error in the draft), row computed after the descriptor
 * stores, and separate pointer locals for loop 2 and loop 3 (spill slots 0x10 and 0xc).
 */
void func_021BBA94(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u32_021BBA94 o;
    u8 i;
    u8 j;
    u8 k;
    u8 z;
    u8 *row;
    u8 *ent;
    u8 *slot;
    u32_021BBA94 owner;
    int o1, o2, o3, o4, o5, o6, o7;

    v = func_021BE00C(a0);
    owner = func_021BE010(a0);
    o = func_021BE004(a0);
    if (*(u32_021BBA94 *)(o + 4) != 2 && *(u32_021BBA94 *)(o + 4) != 3 && func_021BE0EC(a0) == 0) {
        func_02049658((void *)owner, 0xb, 4, 0, 0xa << 10, 0, v);
        func_020498F4((void *)owner, 0x12, 4, 0, 0, 0, v);
        func_020409B4(4);
    }
    d.b = 3;
    for (i = 0; i < 15; i++) {
        d.x = 0x80;
        d.y = i * 32 + 0x10;
        d.z = 8;
        d.a = 0x20;
        row = p + i * 0x1c;
        *(u32_021BBA94 *)(row + 0x48) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        func_0204B3DC((struct Obj *)*(u32_021BBA94 *)(row + 0x48), 0);
        func_0204B92C((struct Obj *)*(u32_021BBA94 *)(row + 0x48), 1);
        d.x = 0x12;
        d.z = 9;
        d.a = 0x10;
        *(u32_021BBA94 *)(row + 0x4c) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        func_0204B3DC((struct Obj *)*(u32_021BBA94 *)(row + 0x4c), 0);
        d.x = 0xc8;
        d.z = 0x12;
        d.a = 0x10;
        *(u32_021BBA94 *)(row + 0x50) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        func_0204B3DC((struct Obj *)*(u32_021BBA94 *)(row + 0x50), 0);
    }
    d.x = 0xe0;
    d.y = 0xa8;
    if (func_021BE0EC(a0) == 0)
        d.z = 1;
    else
        d.z = 0xf;
    j = 0;
    d.a = j;
    d.b = j;
    *(u32_021BBA94 *)(p + 0x400) = (u32_021BBA94)MK(a0, p, 6, 2, 10, 1);
    func_0204B3DC((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 1);
    func_0204B92C((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 1);
    d.x = 0xf8;
    d.y = 0x18;
    d.z = 0xc;
    *(u32_021BBA94 *)(p + 0x404) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
    func_0204B3DC((struct Obj *)*(u32_021BBA94 *)(p + 0x404), 0);
    o1 = 0x14A;
    o1 += 0x9a;
    o2 = 0x14A;
    o2 += 0x9e;
    o3 = 0x14A;
    o3 += 0xa2;
    o4 = 0x14A;
    o4 += 0xaa;
    o5 = 0x14A;
    o5 += 0xba;
    o6 = 0x14A;
    o6 += 0xae;
    o7 = 0x14A;
    o7 += 0xb9;
    for (j = 0; j < 15; j++) {
        ent = p + j * 0x24;
        *(u32_021BBA94 *)(ent + o1) = 0;
        *(u32_021BBA94 *)(ent + o2) = 0;
        *(u32_021BBA94 *)(ent + o3) = 0;
        *(u32_021BBA94 *)(ent + o4) = 0;
        *(u8 *)(ent + o5) = 0xff;
        *(u32_021BBA94 *)(ent + o6) = (u32_021BBA94)func_02030734(v, 0x64, 1, (const char *)d_021C7234, 0xff + 0x4b);
        *(u8 *)(ent + o7) = 0;
    }
    for (k = 0; k < 15; k++) {
        slot = p + k * 0x1c;
        *(u32_021BBA94 *)(slot + 0x40) = 0;
        *(u32_021BBA94 *)(slot + 0x44) = 0;
        *(u8 *)(slot + 0x58) = 0xff;
        *(u32_021BBA94 *)(slot + 0x54) = func_020450F0(6, 3, (u8)(k * 4 + 1), 0x19, 2, 0xa, 1);
    }
    *(u32_021BBA94 *)(p + 0x2c) = func_020450F0(4, 1, 0x15, 0x15, 2, 0xa, 1);
    *(u32_021BBA94 *)(p + 0x30) = func_020450F0(4, 2, 9, 0x1c, 2, 0xa, 1);
    z = 0;
    *(u32_021BBA94 *)(p + 0x38) = z;
    *(u16 *)(p + 0x36) = z;
    for (z = 0; z < 3; z++) {
        p[z] = 0xff;
    }
    p[3] = 0xff;
    *(u16 *)(p + 4) = 0;
    *(u16 *)(p + 6) = 0;
    p[0x14] = 0;
    p[0x15] = 0xff;
    *(u32_021BBA94 *)(p + 0x18) = 0xff;
    *(u32_021BBA94 *)(p + 0xc) = 0;
    *(u32_021BBA94 *)(p + 0x10) = 0;
    *(u32_021BBA94 *)(p + 0x20) = 0;
    *(u32_021BBA94 *)(p + 0x24) = 0;
    *(u32_021BBA94 *)(p + 0x28) = 0;
    *(u32_021BBA94 *)(p + 0x1c) = 0;
    *(u32_021BBA94 *)(p + 8) = 0;
    *(u16 *)(p + 0x34) = 0;
    func_02041EE4(6, 3, 0);
    if ((u32_021BBA94)(*(u32_021BBA94 *)(o + 4) - 2) <= 1 && func_021BE0EC(a0) == 0) {
        func_0204B878((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 0xf);
        func_021BD134(a0, (char *)p, 0x18);
        *(u32_021BBA94 *)(p + 0x38) = 1;
        *(u32_021BBA94 *)(p + 0x18) = 3;
    }
}


void func_021BBE5C(void *a0, char *a1)
{
    u32_021BBE5C p;
    u8 i, j;

    if (((struct Obj03316 *)a1)->f1C != 0) {
        func_02028148((u8 *)(*(u32_021BBE5C *)&((struct Obj03316 *)a1)->f1C));
        *(u32_021BBE5C *)&((struct Obj03316 *)a1)->f1C = 0;
    }

    p = ((struct Obj03316 *)a1)->f2C;
    func_020456F8((struct Descriptor *)p);
    func_020409B4(func_02045730((struct Descriptor *)p));
    func_020452E8((struct Descriptor *)(((struct Obj03316 *)a1)->f2C));

    p = ((struct Obj03316 *)a1)->f30;
    func_020456F8((struct Descriptor *)p);
    func_020409B4(func_02045730((struct Descriptor *)p));
    func_020452E8((struct Descriptor *)(((struct Obj03316 *)a1)->f30));

    func_0204B3B4((struct Obj *)(((struct Obj03316 *)a1)->f404));
    func_0204B3B4((struct Obj *)(((struct Obj03316 *)a1)->f400));

    for (i = 0; i < 0xf; i++) {
        char *q = a1 + i * 0x1c;

        func_020452E8((struct Descriptor *)(((struct Obj08261 *)q)->f54));
        func_0204B3B4((struct Obj *)(((struct Obj08261 *)q)->f50));
        func_0204B3B4((struct Obj *)(((struct Obj08261 *)q)->f4C));
        func_0204B3B4((struct Obj *)(((struct Obj08261 *)q)->f48));
    }

    for (j = 0; j < 0xf; j++)
        func_020307B0((void *)(*(u32_021BBE5C *)(a1 + j * 0x24 + 0x1f8)));

    func_020414EC(6);
    func_020409B4(6);
    func_02041EE4(6, 3, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02041EE4(4, 3, 0);
}


/*
 * 2026-10-04 (D3-06): byte-identical (1724 bytes); 4 of 106 relocations wait on
 *   unlabelled ov172 Thumb leaves filed EXACT this wave as src/matched/ov/
 *   ov172_func_021B8B7C.c, ov172_func_021B8C14.c, ov172_func_021B8C20.c,
 *   ov172_func_021BE0F0.c. After the integrator manifest gives them shard
 *   witnesses, this file should verify EXACT and move to src/matched/ov.
 *   Keys: cnt is block-local in the fC==1 block (sets its stack slot);
 *   case 6 jumps into case 10 by tail merge (code written twice).
 */
int func_021BBF2C(void *a0, char *p)
{
    u32_021BBF2C t;
    u16 v;
    u32_021BBF2C *st;
    u32_021BBF2C t2;
    u8 i, j;
    char *r;
    char *q;
    u8 *ip;
    u32_021BBF2C w;
    struct Descriptor *d;

    v = func_021BE00C(a0);
    st = (u32_021BBF2C *)func_021BE004(a0);
    switch (W(8)) {
    case 0:
        if (func_021BE02C(a0) == 1)
            func_0202208C((void *)0, 1, 1, 0, 6, 1, v);
        else
            func_0202208C((void *)4, 1, 1, 0, 6, 1, v);
        W(8) = 1;
        break;
    case 1:
        if (func_020221A4() == 1) {
            u32_021BBF2C *s = (u32_021BBF2C *)func_021BE004(a0);
            if (func_021BE0EC(a0) == 1)
                W(8) = 11;
            else if (s[1] == 2 || s[1] == 3)
                W(8) = 8;
            else
                W(8) = 5;
        }
        break;
    case 2:
        func_0202208C((void *)4, 0, 0, 0, 6, 1, v);
        func_021BE030(a0, 0);
        W(8) = 4;
        break;
    case 3:
        if (func_021B7590((int)a0, (char *)func_021BDFDC(a0)) == 1) {
            func_0202208C((void *)0, 0, 0, 0, 6, 1, v);
            func_021BE030(a0, 0);
            W(8) = 4;
        }
        break;
    case 4:
        if (func_020221A4() == 1) {
            if (W(0x18) == 0 || W(0x18) == 5)
                return 4;
            return 1;
        }
        break;
    case 5:
        func_021BC5E8(a0, (u8 *)p);
        func_021BD038(a0, p);
        break;
    case 6:
        if (W(0x18) == 0 || W(0x18) == 5) {
            if (func_0204B98C((struct Actor *)OBJ) == 0) {
                func_021B7578((int)a0, (char *)func_021BDFDC(a0));
                W(0x18) = 0;
                W(8) = 3;
            }
            break;
        }
        if (func_02028230((void *)W(0x1c)) != 1)
            break;
        if (W(0x18) == 2) {
            t = func_021BDFE4(a0);
            func_021B80DC((int)a0, (char *)t, 4);
            func_021B80EC((int)a0, (char *)t, (const u8 *)(p + 0x1fd + B(3) * 0x24));
            func_021BD134(a0, p, 0x18);
            W(0x38) = 1;
            W(8) = 7;
            H(0x34) = 0;
            H(0x36) = 0;
            func_02028148((void *)W(0x1c));
            W(0x1c) = 0;
        } else {
            t2 = func_021BDFE4(a0);
            W(8) = 9;
            func_021BD134(a0, p, 0x14);
            W(0x38) = 1;
            H(0x36) = 0;
            func_021B80DC((int)a0, (char *)t2, 3);
            func_02028148((void *)W(0x1c));
            W(0x1c) = 0;
            ip = func_021B8B7C(a0, (u8 *)t2);
            for (i = 0; i < 3; i++) {
                if (B(i) == 0xff) {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = 0xff;
                } else {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = *(u8 *)(p + B(i) * 0x24 + j + 0x1fd);
                }
            }
            ip[0x21] |= 2;
            func_021B8C14(a0, (u8 *)t2);
        }
        func_0204B878(OBJ, 0xf);
        break;
    case 7:
    case 8:
    case 9:
        func_021BDFE4(a0);
        if (func_021BE054(a0) >= 2) {
            if (W(0x28) == 0) {
                t = func_021BDFDC(a0);
                func_02006210();
                func_020061E4(0x73e);
                func_021B7B64((int)a0, (char *)t);
            }
            W(8) = 2;
        }
        if (W(8) == 9) {
            H(0x36)++;
            if (H(0x36) >= 0x78) {
                H(0x36) = 0;
                func_0200616C((void *)0x73d, 2);
            }
        }
        if (W(8) == 9) {
            if (func_021B8C20(a0, (u8 *)func_021BDFE4(a0)) == 1) {
                func_021B80DC((int)a0, (char *)func_021BDFE4(a0), 2);
                func_021BD134(a0, p, 0x27);
                W(8) = 10;
            }
        } else if (W(8) == 7 || W(8) == 8) {
            H(0x34)++;
            if (H(0x34) >= 0x4b0) {
                func_021B80DC((int)a0, (char *)func_021BDFE4(a0), 2);
                func_021BD134(a0, p, 0x28);
                W(8) = 10;
            }
        }
        break;
    case 10:
        if (func_02035C60() == 1) {
            if (((u32_021BBF2C *)func_021BE004(a0))[1] == 2) {
                func_021B7578((int)a0, (char *)func_021BDFDC(a0));
                W(0x18) = 0;
                W(8) = 3;
            } else {
                for (i = 0; i < 3; i++)
                    B(i) = 0xff;
                W(8) = 5;
                B(3) = 0xff;
                func_0201F7A8((void *)W(0x30), 1);
                d = (struct Descriptor *)W(0x30);
                func_020456F8(d);
                func_020409B4(func_02045730(d));
                func_021BE34C(a0);
                func_0204B878(OBJ, 1);
                W(0x18) = 4;
            }
        }
        break;
    case 11:
        func_020452E8((struct Descriptor *)W(0x2c));
        W(0x2c) = func_020450F0(4, 2, 5, 0x1c, 0xe, 0xa, 1);
        func_021BD0C4(a0, p, 0x29);
        W(8) = 12;
        break;
    case 12:
        if (func_021BE054(a0) >= 2 && W(0x28) == 0) {
            func_02006210();
            W(0x28) = 1;
            func_020061E4(0x73e);
        }
        if (func_02035C60() == 1 || func_021BE0D0(a0) == 1) {
            func_020061E4(0x54c);
            func_0201F7A8((void *)W(0x2c), 1);
            d = (struct Descriptor *)W(0x2c);
            func_020456F8(d);
            func_020409B4(func_02045730(d));
            func_020452E8((struct Descriptor *)W(0x2c));
            W(0x2c) = func_020450F0(4, 1, 0x15, 0x15, 2, 0xa, 1);
            func_021BE0F0(a0);
            if (st[1] == 2 || st[1] == 3) {
                func_0204B878(OBJ, 0xf);
                if (func_021BE054(a0) < 2)
                    func_021BD134(a0, p, 0x18);
                W(0x38) = 1;
                W(0x18) = 3;
                W(8) = 8;
            } else {
                W(8) = 5;
                W(0x18) = 4;
                func_0204B878(OBJ, 1);
                v = func_021BE00C(a0);
                w = func_021BE010(a0);
                func_02049658((void *)w, 0xb, 4, 0, 0x2800, 0, v);
                func_020498F4((void *)w, 0x12, 4, 0, 0, 0, v);
                func_020409B4(4);
            }
        }
        break;
    }
    if (st[1] != 3 && func_021BE0EC(a0) == 0) {
        func_021BC7FC(a0, (u8 *)p);
        for (i = 0; i < 15; i++) {
            r = p + i * 0x1c;
            if (*(u32_021BBF2C *)(r + 0x44) == 1) {
                struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
                if (func_0201C6C4(ps, func_02045770(*(struct Descriptor **)(r + 0x54))) == 0) {
                    d = *(struct Descriptor **)(r + 0x54);
                    func_02045334(d);
                    func_02045374((struct Cfg *)d);
                    func_02041B6C(func_02045730(d));
                    *(u32_021BBF2C *)(r + 0x44) = 0;
                }
            }
        }
        if (W(0xc) == 1) {
            u8 cnt = 0;
            for (i = 0; i < 15; i++)
                func_021BCE2C(a0, p, p + 0x40 + i * 0x1c, i);
            func_02041EE4(6, 3, H(4));
            for (i = 0; i < 3; i++) {
                if (B(i) != 0xff)
                    cnt++;
            }
            for (j = 0; j < 15; j++) {
                r = p + j * 0x24;
                if (*(u32_021BBF2C *)(r + 0x1e4) == 1) {
                    q = p + 0x40 + *(u8 *)(r + 0x204) * 0x1c;
                    if (*(u32_021BBF2C *)(r + 0x1ec) == 1 && *(u8 *)(r + 0x203) < 4 && (B(3) == 0xff || B(3) == j))
                        func_0204B878(*(struct Obj **)(q + 0xc), 0xa);
                    else if (cnt == 3 || B(3) != 0xff || *(u8 *)(r + 0x203) == 4)
                        func_0204B878(*(struct Obj **)(q + 0xc), 0xb);
                    else
                        func_0204B878(*(struct Obj **)(q + 0xc), 9);
                    if (*(u32_021BBF2C *)(r + 0x1f4) == 1) {
                        *(u32_021BBF2C *)(r + 0x1f4) = 0;
                        func_0204B878(*(struct Obj **)(q + 8), 0x22);
                    }
                }
            }
            W(0xc) = 0;
        }
    }
    if (W(0x20) == 1) {
        struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
        if (func_0201C6C4(ps, func_02045770((struct Descriptor *)W(0x2c))) == 0) {
            func_02045334((struct Descriptor *)W(0x2c));
            func_02045374((struct Cfg *)W(0x2c));
            func_020409B4(4);
            W(0x20) = 0;
        }
    }
    if (W(0x24) == 1) {
        struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
        if (func_0201C6C4(ps, func_02045770((struct Descriptor *)W(0x30))) == 0) {
            func_02045334((struct Descriptor *)W(0x30));
            func_02045374((struct Cfg *)W(0x30));
            func_020409B4(4);
            W(0x24) = 0;
            if (W(0x38) == 1) {
                W(0x38) = 0;
                func_021BE318(a0, (void *)W(0x30));
            }
        }
    }
    if (W(0x1c) != 0)
        func_02028178((void *)W(0x1c));
    return 2;
}


void func_021BC5E8(void *ctx, u8 *list)
{
    u32_021BC5E8 tx;
    u32_021BC5E8 ty;
    u32_021BC5E8 dx;
    u32_021BC5E8 dy;
    struct SpritePos pos;
    int trg;
    int cont;
    s16 row;
    u8 id;
    u8 *e;
    int done;
    u8 i;
    int s;
    u32_021BC5E8 range;

    trg = func_02035D20(&tx, &ty);
    cont = func_02035CB8(&dx, &dy);
    func_021BDFE4(ctx);
    if (trg == 1) {
        if (tx > 8 && tx < 0xe0) {
            row = (ty + ((struct Obj00330 *)list)->f4) >> 5;
            if (row >= 0 && row < 15) {
                id = *(list + row * 0x1c + 0x58);
                e = list + 0x1e4 + id * 0x24;
                done = 0;
                if (((struct Obj01950 *)e)->f0 == 1 && e[0x1f] < 4) {
                    if (e[0x18] == 0x20) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            list[3] = id;
                            done = 1;
                            ((struct Obj01950 *)e)->f8 = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            func_020061E4(0x73b);
                        } else {
                            list[3] = 0xff;
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            func_020061E4(0x73c);
                        }
                    } else if (list[3] == 0xff) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            for (i = 0; i < 3; i++) {
                                if (list[i] == 0xff) {
                                    list[i] = id;
                                    break;
                                }
                            }
                            if (i < 3) {
                                done = 1;
                                ((struct Obj01950 *)e)->f8 = 1;
                                ((struct Obj01950 *)e)->f10 = 1;
                                ((struct Obj00330 *)list)->fC = 1;
                                func_020061E4(0x73b);
                            }
                        } else {
                            for (i = 0; i < 3; i++) {
                                if (id == list[i]) {
                                    list[i] = 0xff;
                                    break;
                                }
                            }
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            func_020061E4(0x73c);
                        }
                    }
                }
                if (done == 1)
                    func_021BCEF8(ctx, list);
            }
        } else if (tx >= 0xec && tx <= 0x104 && ty >= ((struct Obj00330 *)list)->f6 + 0xc
                   && ty <= ((struct Obj00330 *)list)->f6 + 0x24 && list[0x14] > 5) {
            ((struct Obj00330 *)list)->f10 = 1;
            func_0204B878((struct Obj *)(((struct Obj00330 *)list)->f404), 0xd);
            func_020061E4(0x66c);
        }
    }
    if (cont == 1 && ((struct Obj00330 *)list)->f10 == 1 && list[0x14] > 5) {
        if (dx >= 0xec && dx <= 0x104 && dy >= 0xc && dy <= 0x9c) {
            range = (list[0x14] - 5) * 32;
            s = dy - 0x18;
            if (s < 0)
                s = 0;
            else if (s > 0x78)
                s = 0x78;
            ((struct Obj00330 *)list)->f6 = s;
            pos.x = 0xf8;
            pos.y = ((struct Obj00330 *)list)->f6 + 0x18;
            func_0204B404((struct Obj *)(((struct Obj00330 *)list)->f404), (const struct Vec2 *)(&pos), 1);
            ((struct Obj00330 *)list)->f4 = ((struct Obj00330 *)list)->f6 * range / 0x78;
            ((struct Obj00330 *)list)->fC = 1;
        }
    } else {
        ((struct Obj00330 *)list)->f10 = 0;
        func_0204B878((struct Obj *)(((struct Obj00330 *)list)->f404), 0xc);
    }
    if (((struct Obj00330 *)list)->f1C != 0 && func_0202824C((void **)(((struct Obj00330 *)list)->f1C)) == 1) {
        func_0202822C((char *)(((struct Obj00330 *)list)->f1C), 1);
        ((struct Obj00330 *)list)->f8 = 6;
        func_020061E4(0x54c);
        if (((struct Obj00330 *)list)->f18 == 1)
            func_0200616C((void *)0x73d, 2);
    }
    if (!func_02035C08(d_021C7040) || (func_020362DC() & 2)) {
        ((struct Obj00330 *)list)->f8 = 6;
        ((struct Obj00330 *)list)->f18 = 5;
        func_0204B878((struct Obj *)(((struct Obj00330 *)list)->f400), 9);
        func_020061E4(0x551);
    }
}


/*
 * Peer list refresh: marks every active slot as unseen, scans the 16 wireless
 * peers, matches each peer MAC against the 15 slots (kind 0x20 or 3), adds new
 * peers to a free slot and to the first free row, then drops slots that were
 * not seen, compacts the rows, and refreshes the list.
 *
 * pass 2 2026-10-06 P2L03: EXACT. kind is a u8 local (func_02177B80 returns u8) and
 * found = 1 is a plain literal after the unseen store. With a u32 kind the found
 * spill store was scheduled above the unseen store (10 bytes) and the found = match
 * stand-in was needed (2 bytes); the narrow kind closes it.
 */
void func_021BC7FC(void *ctx, u8 *list)
{
    int changed;
    int refresh;
    int found;
    int diff;
    struct Rec *p;
    u8 kind;
    u32_021BC7FC a;
    u32_021BC7FC c;
    int match;
    u8 slot;
    int j;
    int i;
    u8 k;
    u8 m;
    u8 r;
    u8 *e;
    u8 *row;
    u8 *mac;
    u32_021BC7FC mode;
    int ok;
    u32_021BC7FC b;
    u8 buf[8];
    u8 q;

    changed = 0;
    refresh = 0;
    if (!func_021B8108(ctx, (void *)func_021BDFE4(ctx)))
        return;
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32_021BC7FC *)(e + 0x1e4) == 1)
            *(u32_021BC7FC *)(e + 0x1e8) = 1;
    }
    mode = *(u32_021BC7FC *)(list + 8);
    if (mode != 7 && mode != 9 && mode != 10 && (int)mode >= 5) {
        for (j = 0; j < 16; j++) {
            found = 0;
            diff = 0;
            p = (struct Rec *)func_0203CF10(j);
            if (p == 0)
                continue;
            slot = 0xff;
            mac = func_0203CF3C(j);
            kind = func_02177B80(j);
            if (kind == 3 && ((struct Bits2 *)((u8 *)p + 2))->b1 != 2)
                continue;
            ok = 0;
            if (kind == 0x20) {
                a = (u32_021BC7FC)func_020084F4(p);
                b = func_02008550((const struct Sub0200852CObj *)p);
                c = func_02008530((const struct Sub0200852CObj *)p);
                func_02087C6C(buf);
                if (p->f21_1 == 0 || func_021B85D0((u8 *)p, buf) == 1)
                    ok = func_021BD0A4(ctx, (u32_021BC7FC)list, a, c, b);
            } else if (func_02013D5C((u16)p->fC_17) == 0 && func_02013D9C((u16)p->fC_17) == 0) {
                ok = func_021BD0A4(ctx, (u32_021BC7FC)list, (u32_021BC7FC)((u8 *)p + 0x1a), p->f4, p->bB_7);
            }
            if (ok == 0)
                continue;
            for (k = 0; k < 15; k++) {
                e = list + k * 0x24;
                if (*(u32_021BC7FC *)(e + 0x1e4) == 1) {
                    match = 1;
                    for (m = 0; m < 6; m++) {
                        if (mac[m] != e[m + 0x1fd]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match == 1) {
                        ((struct List *)list)->slots[k].unseen = 0;
                        found = 1;
                        if (kind != ((struct List *)list)->slots[k].kind) {
                            found = 0;
                            diff = 1;
                            slot = k;
                            for (m = 0; m < 3; m++) {
                                if (k == list[m]) {
                                    list[m] = 0xff;
                                    refresh = 1;
                                }
                            }
                            if (list[3] == k) {
                                list[3] = 0xff;
                                refresh = 1;
                            }
                        }
                        if (kind == 0x20 && (*(u8 **)(e + 0x1f8))[0x20] != p->f20) {
                            found = 0;
                            diff = 1;
                            slot = k;
                        }
                        break;
                    }
                } else if (slot == 0xff) {
                    slot = k;
                }
            }
            if (found != 0 || slot == 0xff)
                continue;
            e = list + slot * 0x24;
            *(u32_021BC7FC *)(e + 0x1e4) = 1;
            *(u32_021BC7FC *)(e + 0x1e8) = 0;
            *(u32_021BC7FC *)(e + 0x1ec) = 0;
            for (m = 0; m < 6; m++)
                e[m + 0x1fd] = mac[m];
            if (kind == 0x20) {
                ((struct List *)list)->slots[slot].kind = 0x20;
                func_02082D44(p, ((struct List *)list)->slots[slot].buf, 0x34);
            } else {
                ((struct List *)list)->slots[slot].kind = 3;
                func_02082D44(p, ((struct List *)list)->slots[slot].buf, 0x64);
            }
            if (diff == 0) {
                for (r = 0; r < 15; r++) {
                    row = list + r * 0x1c;
                    if (row[0x58] == 0xff) {
                        row[0x58] = slot;
                        e[0x204] = r;
                        *(u32_021BC7FC *)(row + 0x40) = 1;
                        break;
                    }
                }
            } else {
                *(u32_021BC7FC *)(list + e[0x204] * 0x1c + 0x40) = 1;
            }
            changed = 1;
        }
    }
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32_021BC7FC *)(e + 0x1e4) == 1 && *(u32_021BC7FC *)(e + 0x1e8) == 1) {
            q = e[0x204];
            for (; q < 14; q++) {
                row = list + q * 0x1c;
                if (row[0x74] == 0xff)
                    break;
                row[0x58] = row[0x74];
                list[row[0x58] * 0x24 + 0x204] = q;
                *(u32_021BC7FC *)(row + 0x40) = 1;
            }
            row = list + q * 0x1c;
            row[0x58] = 0xff;
            *(u32_021BC7FC *)(row + 0x40) = 1;
            e[0x204] = 0xff;
            *(u32_021BC7FC *)(e + 0x1e4) = 0;
            for (m = 0; m < 3; m++) {
                if (i == list[m]) {
                    list[m] = 0xff;
                    refresh = 1;
                }
            }
            if (list[3] == i) {
                list[3] = 0xff;
                refresh = 1;
            }
            i--;
            changed = 1;
        }
    }
    if (changed == 1) {
        func_021BCB88(ctx, (char *)list);
        refresh = 1;
        *(u32_021BC7FC *)(list + 0xc) = 1;
    }
    if (refresh == 1 && *(u32_021BC7FC *)(list + 8) == 5)
        func_021BCEF8(ctx, list);
}


void func_021BCB88(void *ctx, char *list)
{
    struct SpritePos pos;
    u8 n = 0;
    u8 i;
    u32_021BCB88 range;

    for (i = 0; i < 15; i++)
        func_021BCC40(ctx, list, list + 0x40 + i * 0x1c, i);
    for (i = 0; i < 15; i++) {
        if (*(u8 *)(list + i * 0x1c + 0x58) != 0xff)
            n++;
    }
    if (((struct Obj01951 *)list)->f14 == n)
        return;
    if (n > 5) {
        range = (n - 5) * 32;
        func_0204B3DC((struct Obj *)((struct Obj01951 *)list)->f404, 1);
        if (((struct Obj01951 *)list)->f4 > range)
            ((struct Obj01951 *)list)->f4 = range;
        ((struct Obj01951 *)list)->f6 = ((struct Obj01951 *)list)->f4 * 0x78 / range;
        if (((struct Obj01951 *)list)->f10 == 0) {
            pos.x = 0xf8;
            pos.y = ((struct Obj01951 *)list)->f6 + 0x18;
            func_0204B404((struct Obj *)(((struct Obj01951 *)list)->f404), (const struct Vec2 *)(&pos), 1);
        }
    } else {
        func_0204B3DC((struct Obj *)((struct Obj01951 *)list)->f404, 0);
        ((struct Obj01951 *)list)->f4 = 0;
        ((struct Obj01951 *)list)->fC = 1;
    }
    ((struct Obj01951 *)list)->f14 = n;
}


static inline u8 func_021BCC40_show(u32_021BCC40 win)
{
    func_020456F8((struct Descriptor *)win);
    return func_02045730((struct Descriptor *)win);
}


void func_021BCC40(void *ctx, char *list, char *row, int idx)
{
    u32_021BCC40 buf2;
    u32_021BCC40 fmt2;
    u32_021BCC40 msgs;
    u32_021BCC40 sys;
    u32_021BCC40 str;
    u32_021BCC40 buf;
    u8 *p;
    u32_021BCC40 heap;
    u32_021BCC40 fmt;
    u32_021BCC40 font;
    char *e;
    u32_021BCC40 ws;

    if (((struct Obj02882 *)row)->f0 != 1)
        return;
    if (((struct Obj02882 *)row)->f18 != 0xff) {
        heap = func_021BE00C(ctx);
        font = func_021BE034(ctx);
        msgs = func_021BE03C(ctx);
        sys = func_021BE044(ctx);
        e = list + 0x1e4 + ((struct Obj02882 *)row)->f18 * 0x24;
        ws = (u32_021BCC40)func_0201EC64(heap);
        func_02043B5C((struct CharBuf *)((u32_021BCC40)func_02045770((struct Descriptor *)((struct Obj02882 *)row)->f14)), 0);
        str = (u32_021BCC40)func_020457B0(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            func_02045994((struct Strbuf *)str, func_0202E930(((struct Obj01166 *)e)->f14), 8);
        else
            func_02045994((struct Strbuf *)str, (const u16 *)(*(char * *)&((struct Obj01166 *)e)->f14 + 0x1a), 8);
        func_0201C724((void *)sys, (u32_021BCC40)func_02045770((struct Descriptor *)((struct Obj02882 *)row)->f14), 6, 0, str, font, 0x3c40);
        func_02045808((struct U16Vec *)str);
        fmt = (u32_021BCC40)func_02045EC0((struct MsgBank *)msgs, 0xe);
        buf = (u32_021BCC40)func_020457B0(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            func_0201EFA4((struct WordSet *)ws, 0, func_0202E938(((struct Obj01166 *)e)->f14), 5, 2, 1);
        else
            func_0201EFA4((struct WordSet *)ws, 0, ((struct Obj24102 *)(*(char * *)&((struct Obj01166 *)e)->f14))->f18, 5, 2, 1);
        func_0201F250((struct WordSet *)ws, (void *)buf, (void *)fmt);
        func_02045808((struct U16Vec *)fmt);
        func_0201C724((void *)sys, (u32_021BCC40)func_02045770((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x50, 0, buf, font, 0x3c40);
        func_02045808((struct U16Vec *)buf);
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            p = *(u8 * *)&((struct Obj01166 *)e)->f14;
            ((struct Obj01166 *)e)->f1F = p[0x20];
            fmt2 = (u32_021BCC40)func_02045EC0((struct MsgBank *)msgs, 0x10);
            buf2 = (u32_021BCC40)func_020457B0(0x20, heap);
            p += 0x20;
            func_0201EFA4((struct WordSet *)ws, 0, *p, 1, 0, 1);
            func_0201F250((struct WordSet *)ws, (void *)buf2, (void *)fmt2);
            func_02045808((struct U16Vec *)fmt2);
            func_0201C724((void *)sys, (u32_021BCC40)func_02045770((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x90, 0, buf2, font, 0x3c40);
            func_02045808((struct U16Vec *)buf2);
        } else {
            ((struct Obj01166 *)e)->f1F = 0;
        }
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            if ((*(struct FlagsA * *)&((struct Obj01166 *)e)->f14)->on == 1)
                ((struct Obj01166 *)e)->fC = 1;
            else
                ((struct Obj01166 *)e)->fC = 0;
        } else if ((*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b7 == 1 && (*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b6 == 0) {
            ((struct Obj01166 *)e)->fC = 1;
        } else {
            ((struct Obj01166 *)e)->fC = 0;
        }
        func_0201ED04((struct WordSet *)ws);
        ((struct Obj02882 *)row)->f4 = 1;
    } else {
        func_02041B6C(func_021BCC40_show(((struct Obj02882 *)row)->f14));
    }
    ((struct Obj02882 *)row)->f0 = 0;
}


/*
 * Places the three cursor sprites (+0x8, +0xc, +0x10) on list row idx relative to the scroll offset at +4: hidden when no row is selected (+0x18 == 0xff) or the row is off screen; the third sprite shows only when the selected entry's flag at +0x1f0 is set, animated from the row's cell at +0x50.
 */
void func_021BCE2C(void *ctx, char *list, char *cur, u8 idx)
{
    struct SpritePos pos;
    s16 y;

    if (((struct Obj01560 *)cur)->f18 == 0xff) {
        func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
        func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
        func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        return;
    }
    y = idx * 32 - ((struct Obj24103 *)list)->f4;
    if (y >= -32 && y <= 0xa0) {
        pos.x = 0x80;
        pos.y = y + 0x10;
        func_0204B404((struct Obj *)(((struct Obj01560 *)cur)->f8), (const struct Vec2 *)(&pos), 1);
        func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->f8, 1);
        pos.x = 0x12;
        func_0204B404((struct Obj *)(((struct Obj01560 *)cur)->fC), (const struct Vec2 *)(&pos), 1);
        func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->fC, 1);
        pos.x = 0xc8;
        func_0204B404((struct Obj *)(((struct Obj01560 *)cur)->f10), (const struct Vec2 *)(&pos), 1);
        if (*(u32_021BCE2C *)(list + ((struct Obj01560 *)cur)->f18 * 0x24 + 0x1f0) == 1) {
            func_0204B878((struct Obj *)(*(u32_021BCE2C *)(list + idx * 0x1c + 0x50)), 0x12);
            func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->f10, 1);
        } else {
            func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        }
        return;
    }
    func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
}


static inline u8 func_021BCEF8_show(u32_021BCEF8 win)
{
    func_020456F8((struct Descriptor *)win);
    return func_02045730((struct Descriptor *)win);
}


/*
 * Keeps the button prompt (+0x1c, kind at +0x18) in step with the selection: a fourth selected slot shows prompt 0x13 (kind 2), any selected slot shows prompt 0x12 (kind 1), none removes the prompt (kind 0) and reprints message 0x11 when the mode byte at +0x14 is set.
 */
void func_021BCEF8(void *ctx, u8 *st)
{
    u8 n = 0;
    u8 i;
    u16 heap = func_021BE00C(ctx);
    u32_021BCEF8 msgs = func_021BE03C(ctx);
    u32_021BCEF8 sys = func_021BE04C(ctx);

    for (i = 0; i < 3; i++) {
        if (st[i] != 0xff)
            n++;
    }
    if (st[3] != 0xff) {
        if (((struct Obj00543 *)st)->f18 != 2) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            func_0201F7A8((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                func_02028148((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32_021BCEF8)func_02045EC0((struct MsgBank *)msgs, 0x13);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = func_02027FEC(sys, (u32_021BCEF8)(&p), 0, 0x15, 0x15, heap);
            func_02045808((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 2;
        }
    } else if (n != 0) {
        if (((struct Obj00543 *)st)->f18 != 1) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            func_0201F7A8((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                func_02028148((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32_021BCEF8)func_02045EC0((struct MsgBank *)msgs, 0x12);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = func_02027FEC(sys, (u32_021BCEF8)(&p), 0, 0x15, 0x15, heap);
            func_02045808((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 1;
        }
    } else if (((struct Obj00543 *)st)->f18 != 0) {
        if (((struct Obj00543 *)st)->f1C != 0) {
            func_02028148((u8 *)(((struct Obj00543 *)st)->f1C));
            ((struct Obj00543 *)st)->f1C = 0;
        }
        if (st[0x14] != 0)
            func_021BD0C4(ctx, (char *)st, 0x11);
        ((struct Obj00543 *)st)->f18 = 0;
    }
}


static inline u8 func_021BD038_show(u32_021BD038 win)
{
    func_020456F8((struct Descriptor *)win);
    return func_02045730((struct Descriptor *)win);
}


void func_021BD038(void *ctx, char *st)
{
    if (((struct Obj01266 *)st)->f14 == ((struct Obj01266 *)st)->f15)
        return;
    if (((struct Obj01266 *)st)->f14 == 0) {
        func_021BD134(ctx, st, 0x1c);
        ((struct Obj01266 *)st)->f38 = 1;
        func_02041B6C(func_021BD038_show(((struct Obj01266 *)st)->f2C));
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f2C), 1);
    } else if (((struct Obj01266 *)st)->f15 == 0 && ((struct Obj01266 *)st)->f14 != 0) {
        func_021BD0C4(ctx, st, 0x11);
        func_021BE34C(ctx);
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f30), 1);
        func_020409B4(func_021BD038_show(((struct Obj01266 *)st)->f30));
    }
    ((struct Obj01266 *)st)->f15 = ((struct Obj01266 *)st)->f14;
}


int func_021BD0A4(void *ctx, u32_021BD0A4 unused, u32_021BD0A4 a, u32_021BD0A4 b, u32_021BD0A4 c)
{
    return func_02009D50((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(*((u32_021BD0A4 *)func_021BE004(ctx)))), (const void *)a, b, c, 0);
}
