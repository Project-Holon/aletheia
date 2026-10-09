/*
 * file:     field_effect_p03.c
 * unit:     yes
 * function: func_021A8E78, func_021A8E80, func_021A8EEC, func_021A8FFC, func_021A9080, func_021A90A4, func_021A90E0, func_021A9154, func_021A926C, func_021A9294, func_021A92A4, func_021A9350, func_021A94B0, func_021A9508, func_021A954C, func_021A957C, func_021A9604, func_021A96B8, func_021A9780, func_021A9810, func_021A9828, func_021A996C, func_021A99A8, func_021A99E4, func_021A9A5C, func_021A9B00, func_021A9B68, func_021A9BE8
 * address:  0x021A8E78
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
 *   func_021A8B84  0x021A8B84  thumb  ov021
 *   d_021D8C4C     0x021D8C4C  data  ov021  a1
 *   d_021D8B26     0x021D8B26  data  ov021  a1
 *   d_021D8B27     0x021D8B27  data  ov021  a1
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02035C08  0x02035C08  arm
 *   d_021D8C2C     0x021D8C2C  data  ov021  a1
 *   func_0204B404  0x0204B404  arm
 *   func_0204B878  0x0204B878  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B324  0x0204B324  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_02045334  0x02045334  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02049238  0x02049238  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200D418  0x0200D418  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02018598  0x02018598  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_021A9DC8  0x021A9DC8  thumb  ov021
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02010FB0  0x02010FB0  thumb
 *   func_021A9C58  0x021A9C58  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02005728  0x02005728  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_021A9CAC  0x021A9CAC  thumb
 *   func_021A9D30  0x021A9D30  thumb
 *   data_021D8DE8  0x021D8DE8  data
 *   func_0200D454  0x0200D454  thumb
 *   func_02019C90  0x02019C90  thumb
 *   _u32_div_f  0x0209C2B0  arm
 */
struct W_021A8E78;
struct Obj_021A8E78;
struct Vec2;
struct Actor;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Big;
struct BigObj;
struct Blk38;
struct Sub0200852CObj;
struct Spec;
struct Unit_021A8E78;
struct Slot14_021A94B0;
struct GdsEnt;
struct Mon;
struct Entry8_021A8E78;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021A8E78;

typedef signed char    s8;

struct W_021A8E78 {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20;
    u8 f21;
};

typedef struct Item_021A8E78 {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item_021A8E78;

typedef struct Obj_021A8E78 {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[0x24 - 0x20];
    int f24;
    int f28;
    int f2C;
    u8 pad30[0x34 - 0x30];
    Item_021A8E78 items[7];
    int fF8;
    u8 padFC[0x124 - 0xFC];
    u32 f124;
} Obj_021A8E78;

struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    void *f18;
};

struct W_021A8FFC {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[4];
    u32 f2C;
    u32 f30;
    struct Slot slots[7];
    u32 cur;
    u8 padFC[0x28];
    void *f124;
};

struct Buf32 {
    u8 b[32];
};

typedef short s16_021A9080;

typedef struct {
    s16_021A9080 x;
    s16_021A9080 y;
} P;

typedef struct {
    char pad0[0x124];
    int f124;
    int pad128[3];
    int f134;
} S_021A9080;

typedef struct {
    int pad0;
    int f0;
    int pad8[5];
} E;

typedef struct {
    int pad0[3];
    int fc;
    int pad10[3];
    char pad1c[2];
    u8 b1e;
    u8 b1f;
    int pad20[2];
    int f28;
    int pad2c;
    int f30;
    int pad34;
    E e[7];
    char padfc[0x128 - 0xfc];
    int f128;
} S_021A90A4;

struct W {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[4];
    u32 f2C;
    u32 f30;
    struct Slot slots[7];
    struct Slot *cur;
    u8 padFC[0x28];
    void *f124;
};

typedef struct Item_021A90E0 {
    int f00;
    int f04;
    int f08;
    u32 f0C;
    u32 f10;
    u8 f14;
    u8 f15;
    u8 pad16[2];
    u32 f18;
} Item_021A90E0;

typedef struct Src {
    int f00;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 f08;
    u8 f09;
    u8 pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
} Src;

typedef struct Obj_021A90E0 {
    u16 f00;
    u16 f02;
    void *f04;
    u8 pad08[0x104 - 0x08];
    u32 f104;
    u8 pad108[0x11C - 0x108];
    u32 f11C;
    u8 pad120[0x12C - 0x120];
    u32 f12C;
} Obj_021A90E0;

typedef struct Hdr {
    u16 f00;
    u16 f02;
    u16 f04;
    u8 f06;
    u8 f07;
    u16 f08;
    u16 f0A;
    u32 f0C;
    u32 f10;
    u16 f14;
    u16 f16;
} Hdr;

typedef signed int     s32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
} S_021A926C;

typedef struct {
    int f0;
    int f4;
} S_021A9294;

struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

struct Sel_021A8E78 {
    void *f00;
    void *f04;
    int f08;
    int f0C;
    u8 pad10[5];
    u8 f15;
    u16 f16;
    u16 f18;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 pad1F;
    u32 f20;
    void *f24;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 9;
    u32 b15 : 1;
};

struct Obj {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[0xE];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 4;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
};

typedef signed short   s16;

struct Slot14_021A94B0 { u8 pad00[4]; u8 f04; u8 pad05[0xF]; };

struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

struct Unit_021A8E78 {
    void *f00;
    void *f04;
};

struct Sel_021A94B0 {
    u8 pad00[8];
    int f08;
};

struct Out {
    u16 f00;
    u16 f02;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
};

typedef unsigned long long u64;

struct Unit_021A96B8 {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x11];
    u8 f1D;
    u8 pad1E[2];
    u32 f20;
    void *f24;
    u32 b0 : 9;
    u32 b9 : 1;
    u32 b10 : 1;
};

struct Slot14_021A9604 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 f07; };

struct Unit_021A9780 {
    u8 pad00[0x20];
    u32 f20;
};

struct Sel {
    void *f00;
    void *f04;
    int f08;
    int f0C;
    u8 pad10[5];
    u8 f15;
    u16 f16;
    u16 f18;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 pad1F;
    u32 f20;
    void *f24;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 b11 : 1;
    u32 b12 : 1;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 b15 : 1;
};

struct Unit_021A9828 {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[4];
    u8 f1E;
    u8 pad1F[9];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 2;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 6;
    u32 b15 : 1;
};

struct Entry8_021A8E78 { u32 a, b; };

struct Entry8_021A99E4 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 pad07; };

struct Unit {
    void *f00;
    u8 pad04[4];
    int f08;
    u8 pad0C[4];
    u32 f10;
    u8 f14;
};

struct Unit_021A9A5C {
    void *f00;
    u8 pad04[4];
    int f08;
    u8 pad0C[4];
    u32 f10;
    u8 f14;
};

struct Slot14 { u16 f00; u8 pad02[2]; u8 f04; u8 f05; u8 pad06[0xE]; };

struct Unit_021A9BE8 {
    u8 pad00[0x14];
    u8 f14;
    u8 pad15[0x13];
    u32 b0 : 14;
    u32 b14 : 1;
};

extern int func_021A8B84(int idx);
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020061E4(u32 se);
extern void func_0204B3DC(struct Obj_021A8E78 *, unsigned int);
extern void func_020355D8(u8 v);
extern int func_02035C08(const void *p);
extern void func_0204B404(struct Obj_021A8E78 *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj_021A8E78 *p, u16 value);
extern u32 func_02188C54(u8 *p);
extern u32 func_021904AC(u8 *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj_021A90E0 *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_0204B92C(struct Obj_021A90E0 *p, u32 v);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj_021A90E0 *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_02045334(struct Descriptor *a);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *o, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049658(void *o, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u32 e);
extern void func_02049238(void *o);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u8 a);
extern u32 func_020307B0(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02012934(const struct BigObj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0200D418(void *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u8 func_02018598(void *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u32 func_0200D58C(struct Blk38 *p);
extern u32 func_0201AA50(void *p);
extern u32 func_021A9DC8(void);
extern u32 func_0201AB08(void *p);
extern u32 func_0209C2B0(u32 a, u32 b);
extern u32 func_02010FB0(u32 v);
extern void func_021A9C58(struct Unit_021A8E78 *u, struct Spec *specs, struct Slot14_021A94B0 *s);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern u32 func_0200D4B8(const struct GdsEnt *e, u32 i);
extern u32 func_02005728(u32 v);
extern void *func_0219390C(void *a, u32 b);
extern u8 *func_02193C00(int a);
extern u32 func_020056EC(u32 v);
extern void *func_0201ADE4(unsigned int a, int b, unsigned int c);
extern u32 func_021A9D30(struct Unit_021A96B8 *u, void *src, struct Slot14_021A9604 *s);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void func_021A9CAC(void *mon, void *src, int a, int b);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern void func_020185C4(void *p);
extern void func_0201AE14(void *p);
extern u8 func_0200D454(struct Blk38 *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
int func_021A8E78(u32 a, u32 b);
u32 func_021A8E80(struct W_021A8E78 *w, u32 dir);
void func_021A8EEC(Obj_021A8E78 *p);
void func_021A8FFC(struct W_021A8FFC *w);
void func_021A9080(S_021A9080 *s, s16_021A9080 x, s16_021A9080 y);
void func_021A90A4(S_021A90A4 *s, int m);
void func_021A90E0(struct W *w);
void func_021A9154(Obj_021A90E0 *p, Item_021A90E0 *it, const Src *s);
void func_021A926C(int a, S_021A926C *s);
void func_021A9294(int a, S_021A9294 *s);
void func_021A92A4(u32 a, u32 b);
void func_021A9350(struct Sel_021A8E78 *s, void *a, int b, int c, u16 d);
u32 func_021A94B0(struct Obj *o, u32 unused, u32 n);
int func_021A9508(u8 *u, void *arg, struct Slot14_021A94B0 *slots);
int func_021A954C(void *a0, void *u, u16 id, void *slots);
void *func_021A957C(void *a0, struct Unit_021A8E78 *u, u32 want);
u32 func_021A9604(int obj, struct Sel_021A94B0 *sel, struct Out *out);
void func_021A96B8(void *mon, const struct Unit_021A96B8 *u, struct Slot14_021A9604 *s);
void func_021A9780(void *mon, const struct Unit_021A9780 *u, void *src);
u16 func_021A9810(int a);
void func_021A9828(struct Sel *s, u16 d);
int func_021A996C(struct Unit_021A9828 *u, u8 n);
const struct Entry8_021A8E78 *func_021A99A8(void *p);
int func_021A99E4(void *a0, struct Unit *u, u16 id, struct Spec *spec);
u8 func_021A9A5C(u8 *a0, struct Unit_021A9A5C *u, u16 id, struct Spec *spec);
void func_021A9B00(struct Spec *spec, struct Slot14 *s);
u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type);
void func_021A9BE8(const struct Unit_021A9BE8 *u, const struct Spec *specs, struct Slot14 *s);
extern u8 d_021D8C4C[][8][4];
extern u8 d_021D8B26[];
extern u8 d_021D8B27[];
extern struct Buf32 d_021D8C2C;
extern const struct Entry8_021A8E78 data_021D8DE8[];









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A8E78(u32 a, u32 b)
{
return (a + (b << 1));
}









/*
 * Addresses are Black-image addresses.
 */
u32 func_021A8E80(struct W_021A8E78 *w, u32 dir)
{
    u32 idx = func_021A8E78(w->f1E, w->f1F);
    u32 r = d_021D8C4C[func_021A8B84(w->f21) - 4][idx][dir];

    if (idx != r) {
        if (r == 0xFF) {
            w->f1F = 2;
            return 1;
        }
        if (r == 0xFE) {
            w->f1F = 1;
            return 1;
        }
        if (r != 6) {
            w->f1E = d_021D8B26[r * 2];
        }
        w->f1F = d_021D8B27[r * 2];
        return 1;
    }
    return 0;
}








void func_021A8EEC(Obj_021A8E78 *p)
{
    u32 trg;
    u32 rep;

    trg = func_020362DC();
    rep = func_0203633C();
    if (p->f2C == 0 && (trg | rep) != 0) {
        if ((trg & 2) || (trg & 0x400)) {
            func_021A90A4((void *)p, 1);
            return;
        }
        func_020061E4(0x548);
        p->f2C = 1;
        p->fF8 = 0;
        p->f24 = 1;
        func_0204B3DC((struct Obj_021A8E78 *)p->f124, 1);
        return;
    }
    if (rep & 0x40) {
        if (func_021A8E80((struct W_021A8E78 *)p, 0) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x80) {
        if (func_021A8E80((struct W_021A8E78 *)p, 1) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x20) {
        if (func_021A8E80((struct W_021A8E78 *)p, 2) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x10) {
        if (func_021A8E80((struct W_021A8E78 *)p, 3) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if ((trg & 2) || (trg & 0x400)) {
        func_021A90A4((void *)p, 1);
    } else if (trg & 1) {
        if (p->items[func_021A8E78(p->f1E, p->f1F)].f08 != 7) {
            func_021A90A4((void *)p, 0);
            func_020355D8(0);
        }
    }
}







void func_021A8FFC(struct W_021A8FFC *w)
{
    struct Buf32 buf = d_021D8C2C;
    int r = func_02035C08(&buf);
    u32 z;

    if (r != -1 && w->slots[r].f08 != 7) {
        w->f1E = r % 2;
        w->f1F = r / 2;
        z = 0;
        w->f2C = z;
        func_0204B3DC(w->f124, 0);
        if (r == 6) {
            func_021A90A4((void *)w, 1);
            return;
        }
        w->f24 = 1;
        func_021A90A4((void *)w, z);
        func_020355D8(1);
    }
}







void func_021A9080(S_021A9080 *s, s16_021A9080 x, s16_021A9080 y)
{
    P v;
    v.x = x;
    v.y = y;
    func_0204B404((struct Obj_021A8E78 *)s->f124, (const struct Vec2 *)(&v), 0);
    s->f134 = 0;
}







void func_021A90A4(S_021A90A4 *s, int m)
{
    if (m == 1) {
        s->f28 = 1;
        s->fc = 4;
        func_0204B878((struct Obj_021A8E78 *)s->f128, 8);
    } else {
        s->f28 = 0;
        s->fc = 5;
        s->f30 = s->e[func_021A8E78(s->b1e, s->b1f)].f0;
    }
}







void func_021A90E0(struct W *w)
{
    struct Slot *old;

    if (w->f24 == 1) {
        old = w->cur;
        w->cur = &w->slots[w->f1E + w->f1F * 2];
        func_0204B878(w->f124, 0);
        func_021A9080((void *)w, w->cur->f14, w->cur->f15);
        if (w->cur->f18 != 0 && w->f2C == 1) {
            func_0204B878(w->cur->f18, 1);
        }
        if (old != 0 && old->f18 != 0) {
            func_0204B878(old->f18, 0);
        }
        w->f24 = 0;
    }
}







void func_021A9154(Obj_021A90E0 *p, Item_021A90E0 *it, const Src *s)
{
    Hdr h;
    u32 k;

    k = func_021904AC((u8 *)func_02188C54(p->f04));
    it->f00 = 1;
    it->f08 = s->f00;
    it->f14 = s->f04;
    it->f15 = s->f05;
    it->f04 = func_020450F0(6, s->f06, s->f07, 8, 2, 0xD, 1);
    func_02045374((struct Cfg *)it->f04);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)it->f04)), 0);
    func_0201C724((void *)p->f12C, (int)func_02045770((struct Descriptor *)it->f04), 2, 1, s->f0C, k, 0x440);
    if (s->f10 != 0) {
        it->f0C = func_0204A6C8((void *)s->f10, s->f14, 0, 1, p->f00);
        it->f10 = func_0204AF28((void *)s->f10, s->f18, s->f1C, p->f00);
        h.f00 = s->f08;
        h.f02 = s->f09;
        h.f04 = 0;
        h.f06 = 0;
        h.f07 = 0;
        h.f08 = 0;
        h.f0A = 0;
        h.f0C = 0x1000;
        h.f10 = 0x1000;
        h.f14 = 0;
        h.f16 = 2;
        it->f18 = (u32)func_0204B324(p->f11C, it->f0C, p->f104, it->f10, (u32)(&h), 0, p->f00);
        func_0204B954((struct Actor *)it->f18, 0x1000);
        func_0204B92C((struct Obj_021A90E0 *)it->f18, 1);
        func_0204B878((void *)((struct Obj_021A90E0 *)it->f18), 0);
        if (it->f08 == 7)
            func_0204B3DC((void *)((struct Obj_021A90E0 *)it->f18), 0);
        else
            func_0204B3DC((void *)((struct Obj_021A90E0 *)it->f18), 1);
    } else {
        it->f18 = 0;
    }
}







void func_021A926C(int a, S_021A926C *s)
{
    if (s->f0 == 1) {
        func_020452E8((struct Descriptor *)s->f4);
        if (s->f18 != 0) {
            func_0204B3B4((struct Obj_021A90E0 *)s->f18);
            func_0204AFD8(s->f10);
            func_0204A8D4(s->fc);
        }
    }
}







void func_021A9294(int a, S_021A9294 *s)
{
    if (s->f0 == 1) {
        func_02045334((struct Descriptor *)s->f4);
    }
}







void func_021A92A4(u32 a, u32 b)
{
    struct Scr *ptr;
    void *h;
    int i;
    u16 *d;
    void *o;

    o = func_020490F4(func_020275E4(), a);
    func_02049B68(o, func_02027624(), 4, 0x60, 0x20, a);
    func_02049658(o, func_02027628(), b, 0x80, 0, 0, a);
    h = func_02049EF4(o, func_0202762C(), 0, (void **)&ptr, a);
    func_02049238(o);
    d = ptr->data;
    for (i = 0; i < 0x300; i++) {
        d[i] = (d[i] + 0x80) | 0x3000;
    }
    func_020410D0((u8)b, 0, 0x15, 0x20, (u32)3, (u32)ptr->data, (u32)0, (u32)0x15, (u32)0x20, (u32)0x18);
    func_02041B6C(b);
    func_020307B0(h);
}







void func_021A9350(struct Sel_021A8E78 *s, void *a, int b, int c, u16 d)
{
    void *t;
    void *party;
    void *mon;

    t = func_02012EBC(a);
    party = func_02012934(a);
    func_02082BCC(s, 0, 0x2C);
    s->f08 = b;
    s->f0C = c;
    s->f00 = a;
    s->f04 = func_0200D418(t);
    if (b == 5 || b == 6)
        s->b1 = 1;
    s->f24 = func_02012944(a);
    s->f20 = func_02008530(s->f24);
    mon = func_0201AB28(party, 0);
    s->f1A = func_02017E1C(mon, 0x4C, 0);
    if (s->f1A == 0) {
        s->f16 = func_02017E1C(mon, 5, 0);
        s->f18 = func_02017E1C(mon, 6, 0);
        s->f1B = func_02017E1C(mon, 10, 0);
        s->f1C = func_02017E1C(mon, 0x6E, 0);
        s->f1D = func_02018598(mon);
        func_021A9828((void *)s, d);
    }
    s->b0 = func_020142E8((void *)func_0201296C(a), 0x960);
    if (func_0200D58C(func_0200D418(t)) == 0)
        s->b2 = 1;
    if (s->f0C == 2) {
        s->b3 = 1;
        s->f0C = 0;
    }
    if (s->f0C == 1)
        s->b3 = 1;
    s->b4 = 0;
    s->b5 = 0;
    if (s->f08 == 1 && (int)func_0201AA50(party) >= 2 && func_021A9DC8() < 0x28)
        s->b5 = 1;
    if (s->b15 || s->b2)
        s->f1E = func_02017E1C(func_0201AB28(party, func_0201AB08(party)), 0x9E, 0);
    s->f15 = s->b5 + 1;
}






u32 func_021A94B0(struct Obj *o, u32 unused, u32 n)
{
    u32 v = n;

    if (o->b1) {
        if (o->b8) {
            v = v * 2;
        }
        if (v > 100) {
            v = 100;
        }
        return v;
    }
    if (o->b6) {
        v = v * 2;
    } else if (o->b7) {
        v = v >> 1;
    }
    if (o->f18 == 0xE0 || o->f18 == 0x140) {
        v = func_0209C2B0(n * 2, 3);
    }
    if (v > 100) {
        v = 100;
    }
    return func_02010FB0(v);
}






int func_021A9508(u8 *u, void *arg, struct Slot14_021A94B0 *slots)
{
    int n = 0;
    int i;

    for (i = 0; i < u[0x15]; i++) {
        struct Slot14_021A94B0 *s = &slots[n];
        func_021A9C58((struct Unit_021A8E78 *)u, arg, s);
        if (func_021A996C((void *)((struct Unit_021A8E78 *)u), s->f04) == 0)
            n++;
    }
    return n;
}






int func_021A954C(void *a0, void *u, u16 id, void *slots)
{
    struct Spec specs[12];

    MIi_CpuClear32(0, specs, sizeof(specs));
    func_021A9A5C(a0, u, id, specs);
    return func_021A9508(u, specs, slots);
}






void *func_021A957C(void *a0, struct Unit_021A8E78 *u, u32 want)
{
    void *buf[2];
    u8 n = 0;
    u8 i;
    void *m;

    for (i = 0; i < 2; i++) {
        if (func_0200D488(u->f04, i) == 0)
            continue;
        m = func_0200D4AC(u->f04, i);
        if (func_0200D4B8(m, 1) != want)
            continue;
        if (func_021A996C((void *)u, func_0200D4B8(m, 6)) != 0)
            continue;
        buf[n++] = m;
    }
    if (n == 0 || func_02005728(1000) < 500)
        return 0;
    return buf[func_02005728(n)];
}






u32 func_021A9604(int obj, struct Sel_021A94B0 *sel, struct Out *out)
{
    u32 k;
    u32 sum;
    u32 r;
    int i;
    u8 *q;
    int p;

    switch (sel->f08) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    case 3:
        k = 2;
        break;
    case 0xFF:
        return 0;
    }
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)func_0219390C((void *)obj, i);
        if (p) {
            sum += func_02193C00(p)[k + 0x14];
        }
    }
    r = func_020056EC(sum);
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)func_0219390C((void *)obj, i);
        if (p) {
            q = func_02193C00(p);
            sum += q[k + 0x14];
            if (r < sum) {
                func_02082BCC(out, 0, 0x14);
                out->f00 = ((u16 *)(q + 8))[k];
                out->f04 = (q + k)[0x10];
                return 1;
            }
        }
    }
    return 0;
}






void func_021A96B8(void *mon, const struct Unit_021A96B8 *u, struct Slot14_021A9604 *s)
{
    void *pd = func_0201ADE4(s->f00, s->f05, 4);
    u32 pid = func_021A9D30((struct Unit_021A96B8 *)u, pd, s);

    func_02017588(mon, s->f00, s->f04, u->f20, 0xFFFFFFFF, pid);
    func_02017E40(mon, 0x6F, s->f05);
    if (s->f07)
        func_02018A00(mon, s->f00, s->f05);
    if (s->f02 <= 0x272) {
        if (s->f02 != 0)
            func_02017E40(mon, 6, s->f02);
        else
            func_021A9CAC(mon, pd, u->b9, u->f08 == 1);
    }
    func_02017E40(mon, 0x9A, func_02008550(u->f24));
    func_02017E40(mon, 0x8E, (u32)func_020084F4(u->f24));
    if (u->b10)
        func_02017E40(mon, 0x70, u->f1D);
    func_020185C4(mon);
    func_0201AE14(pd);
}






/*
 * Addresses are Black-image addresses.
 *
 * Lever: `const struct Unit_021A8E78 *u` settles the argument scheduling before the
 * func_02017588 call (as in ov021_func_021A96B8.c).
 */
/*
 * Addresses are Black-image addresses.
 *
 * Lever: `const struct Unit *u` settles the argument scheduling before the
 * func_02017588 call (as in ov021_func_021A96B8.c).
 */
void func_021A9780(void *mon, const struct Unit_021A9780 *u, void *src)
{
    u16 species = func_0200D4B8(src, 4);
    u8 level = func_0200D4B8(src, 6);
    u32 pow = func_0200D4B8(src, 2);

    func_02017588(mon, species, level, u->f20, pow, func_0200D4B8(src, 3));
    func_02017E40(mon, 0x70, func_0200D4B8(src, 10));
    func_02017E40(mon, 0x9D, func_0200D4B8(src, 7));
    func_02017E40(mon, 0xA0, func_0200D4B8(src, 5));
    func_020185C4(mon);
}






u16 func_021A9810(int a)
{
    u16 *p = (u16 *)func_021A99A8((void *)a);
    if (p == 0) {
        return 0xffff;
    }
    return *p;
}





void func_021A9828(struct Sel *s, u16 d)
{
    switch (s->f1B) {
    case 0x23:
    case 0x47:
    case 0x63:
        s->b6 = 1;
        return;
    case 0x01:
    case 0x49:
    case 0x5F:
        s->b7 = 1;
        return;
    case 0x08:
        if (d == 3 || d == 12)
            s->b7 = 1;
        return;
    case 0x51:
        if (d == 1 || d == 4 || d == 5)
            s->b7 = 1;
        return;
    case 0x15:
    case 0x3C:
        if (s->b1)
            s->b8 = 1;
        return;
    case 0x0E:
        s->b9 = 1;
        return;
    }
    if (s->f1B == 0x38 && func_021A9DC8() < 0x43) {
        s->b11 = 1;
        return;
    }
    if (func_021A9DC8() < 0x32)
        return;
    switch (s->f1B) {
    case 0x2A:
        s->b12 = 1;
        return;
    case 0x09:
        s->b13 = 1;
        return;
    case 0x2E:
    case 0x37:
    case 0x48:
        s->b14 = 1;
        return;
    case 0x16:
    case 0x33:
        s->b15 = 1;
        return;
    case 0x1C:
        s->b10 = 1;
        return;
    }
}





int func_021A996C(struct Unit_021A9828 *u, u8 n)
{
    if (u->b3)
        return 0;
    if (u->b15 && u->f1E >= n + 5)
        return 1;
    if (!u->b1 && u->b2 && n < u->f1E)
        return 1;
    return 0;
}




const struct Entry8_021A8E78 *func_021A99A8(void *p)
{
    void *q = func_02012EBC(p);
    u32 k;

    if (func_020142E8((void *)func_0201296C(p), 0x960) == 0)
        return 0;
    k = func_0200D454(func_0200D418(q));
    if (k >= 0x11)
        k = 0;
    return &data_021D8DE8[k];
}



int func_021A99E4(void *a0, struct Unit *u, u16 id, struct Spec *spec)
{
    const struct Entry8_021A99E4 *e = (void *)func_021A99A8(u->f00);

    if (e == 0 || e->f00 != id)
        return 0;
    if (u->f08 != 0)
        return 0;
    if (func_02005728(1000) > 400)
        return 0;
    spec->id = e->f02;
    spec->lo = e->f05;
    spec->hi = e->f06;
    spec->lvl = e->f04;
    u->f10 = 3;
    u->f14 = 1;
    return 1;
}




/*
 * Addresses are Black-image addresses.
 *
 * Shape: n is a u8 (the return needs no truncation) and each case assigns
 * mode, then n, then src; that order keeps every case its own block with a
 * branch to the join and gives n r6, src r4.
 */
u8 func_021A9A5C(u8 *a0, struct Unit_021A9A5C *u, u16 id, struct Spec *spec)
{
    u8 n = 0;
    u32 mode = 0;
    u8 *src;

    if (func_021A99E4(a0, (void *)u, id, spec) != 0)
        return u->f14;
    if (u->f08 >= 7)
        u->f08 = 0;
    switch (u->f08) {
    case 0:
        n = 12;
        src = a0 + 0x08;
        break;
    case 1:
        n = 12;
        src = a0 + 0x38;
        break;
    case 2:
        n = 12;
        src = a0 + 0x68;
        break;
    case 3:
        mode = 1;
        n = 5;
        src = a0 + 0x98;
        break;
    case 4:
        mode = 1;
        n = 5;
        src = a0 + 0xAC;
        break;
    case 5:
        mode = 2;
        n = 5;
        src = a0 + 0xC0;
        break;
    case 6:
        mode = 2;
        n = 5;
        src = a0 + 0xD4;
        break;
    }
    u->f10 = mode;
    u->f14 = n;
    MI_CpuCopy8(src, spec, n * 4);
    return n;
}




void func_021A9B00(struct Spec *spec, struct Slot14 *s)
{
    s16 range = spec->hi - spec->lo;
    u8 cap;
    int lvl;
    u16 id;

    MI_CpuFill8(s, 0, 0x14);
    if (range < 0)
        range = 0;
    s->f04 = spec->lo + func_021A9DC8() % (u32)(range + 1);
    id = spec->id;
    s->f00 = id;
    cap = func_02019C90(id, 0, 0x20);
    lvl = spec->lvl;
    if (lvl == 0x1F)
        s->f05 = func_02005728(cap);
    else if (lvl >= cap)
        s->f05 = 0;
    else
        s->f05 = lvl;
}




u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type)
{
    u8 buf[12];
    int i;
    int n;
    u8 t1, t2;

    n = 0;
    for (i = 0; i < u[0x14]; i++) {
        if (specs[i].lvl != 0x1F) {
            t1 = func_02019C90(specs[i].id, specs[i].lvl, 6);
            t2 = func_02019C90(specs[i].id, specs[i].lvl, 7);
            if (t1 == type || t2 == type) {
                buf[n] = i;
                n++;
            }
        }
    }
    if (n == 0)
        return 0xFF;
    return buf[func_021A9DC8() % n];
}




/*
 * Lever: `const` on both the unit and the spec-table pointers keeps the
 * per-iteration reload of u->f14 and the image colouring; declaration order
 * i, max, base, varied.
 */
void func_021A9BE8(const struct Unit_021A9BE8 *u, const struct Spec *specs, struct Slot14 *s)
{
    int i;
    u8 max;
    u8 base;
    int varied;

    max = s->f04;
    base = max;
    varied = 0;
    if (u->b14 == 0)
        return;
    for (i = 0; i < u->f14; i++) {
        if (varied == 0 && specs[i].lo != specs[i].hi)
            varied = 1;
        if (s->f00 == specs[i].id && max < specs[i].hi)
            max = specs[i].hi;
    }
    if (base + 5 <= max && varied == 1)
        s->f04 += 5;
    else
        s->f04 = max;
}
