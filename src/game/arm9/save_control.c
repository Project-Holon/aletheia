/*
 * file:     save_control.c
 * unit:     yes
 * function: func_02006F20, func_02007084, func_020070A4, func_020070C8, func_02007150, func_02007168, func_020071A8, func_020071C0, func_020071CC, func_020071D8, func_020071E4, func_020071E8, func_020071EC, func_020071F0, func_02007210, func_02007214, func_02007218, func_0200721C, func_02007220, func_02007230, func_0200723C, func_02007248, func_0200725C, func_020072A4, func_020072CC, sub_02007324, sub_0200734C, func_02007374, func_020073B0, func_020073D8, func_02007400, func_02007428, func_02007464, func_020074CC, func_020074D8, func_0200752C, sub_020075B0, sub_02007610, sub_02007664, sub_02007698, sub_020076A4, sub_020076B4, func_020076D0, func_02007774, func_020077B8, func_0200780C, func_0200781C, func_02007838, sub_0200785C, sub_02007898, sub_020078C4, sub_0200791C, sub_02007984, sub_020079A0, sub_020079BC, sub_02007A18, sub_02007A68, sub_02007A80, sub_02007A9C, sub_02007AA4, sub_02007AC8, sub_02007AD0, sub_02007AEC, sub_02007AF4, sub_02007B00, sub_02007B08, sub_02007B20, sub_02007B44, sub_02007B50, sub_02007B54, sub_02007B5C, sub_02007B64, sub_02007B68, sub_02007BD0, sub_02007C20, sub_02007C34, sub_02007C70, sub_02007CB0, sub_02007CB8, sub_02007CC8, sub_02007D00, sub_02007D6C, sub_02007D94, sub_02007DF8, sub_02007E3C, sub_02007E50, sub_02007ECC, sub_02007EF8, sub_02007F1C, sub_02007F68, sub_02007F7C, sub_02007FA0, sub_02007FB8, sub_02007FD0, sub_02007FF4, sub_02008038, sub_02008058, sub_020080A0, sub_020080FC, sub_0200816C, sub_020081DC, sub_0200823C, sub_02008254, sub_02008270, sub_02008284, sub_02008288, sub_02008298, sub_0200829C, sub_020082B0, sub_020082B4, sub_020082B8, sub_020082D4
 * address:  0x02006F20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4   0x02034AC4  arm
 *   func_02034A5C   0x02034A5C  arm
 *   func_02030734   0x02030734  arm
 *   func_0203192C   0x0203192C  arm
 *   func_02031AE0   0x02031AE0  arm
 *   func_020319C0   0x020319C0  arm
 *   func_02034714   0x02034714  arm
 *   func_021DFC20   0x021DFC20  thumb  ov228
 *   func_021DFE90   0x021DFE90  thumb  ov228
 *   func_021DFE98   0x021DFE98  thumb  ov228
 *   func_021DFDB8   0x021DFDB8  thumb  ov228
 *   sub_02008754    0x02008754  thumb
 *   sub_02008784    0x02008784  thumb
 *   sub_0200725C    0x0200725C  thumb
 *   sub_020072A4    0x020072A4  thumb
 *   sub_0200A5F8    0x0200A5F8  thumb
 *   sub_0200A7EC    0x0200A7EC  thumb
 *   ov228_id        0x000000E4  data
 *   sub_02006F20_File  0x020A7054  data
 *   sub_02006F20_Ptr   0x02146168  data
 *   g_0209D938      0x0209D938  data
 *   sub_02006F20_Msg   0x020A7064  data
 *   sub_02007084_Ptr    0x02146168  data
 *   sub_020070A4_File   0x020A7064  data
 *   func_020307B0       0x020307B0  arm
 *   func_0203195C       0x0203195C  arm
 *   func_0200A5F8  0x0200A5F8  thumb
 *   func_0200A7EC  0x0200A7EC  thumb
 *   func_02008784  0x02008784  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_020087C0  0x020087C0  thumb
 *   func_02007428  0x02007428  thumb
 *   func_02031BB4  0x02031BB4  arm
 *   func_02008754  0x02008754  thumb
 *   func_02031E68 0x02031E68 arm
 *   func_020319A4  0x020319A4  arm
 *   func_02031994  0x02031994  arm
 *   func_020319F0    0x020319F0  arm
 *   veneer_020319E4  0x020319E4  arm
 *   func_020334E8  0x020334E8  arm
 *   func_0200725C_Table  0x0209D950  data
 *   func_020087D4        0x020087D4  thumb
 *   func_02031DC0        0x02031DC0  arm
 *   sub_020072A4_File   0x020A7064  data
 *   func_020072CC_Table  0x0209D950  data
 *   func_02031948        0x02031948  arm
 *   sub_02007324_Table  0x0209D950  data
 *   sub_0200734C_File   0x020A7064  data
 *   g_020A7064     0x020A7064  data
 *   func_020087A8  0x020087A8  thumb
 *   func_02031C10  0x02031C10  arm
 *   func_02031C30  0x02031C30  arm
 *   sub_020073D8_File  0x020A7064  data
 *   func_02033478  0x02033478  arm
 *   sub_0200752C_File  0x020A7068  data
 *   sub_020071CC       0x020071CC  thumb
 *   sub_02007AF4       0x02007AF4  thumb
 *   sub_02017E88       0x02017E88  thumb
 *   sub_020181A0       0x020181A0  thumb
 *   func_02045B38      0x02045B38  arm
 *   func_02045C04      0x02045C04  arm
 *   func_02045F5C      0x02045F5C  arm
 *   sub_020075B0_File  0x020A7068  data
 *   sub_020074CC       0x020074CC  thumb
 *   sub_02017550  0x02017550  thumb
 *   sub_020077B8_File  0x020A7068  data
 *   sub_0200785C_File  0x020A7068  data
 *   func_02045924      0x02045924  arm
 *   func_02045A38      0x02045A38  arm
 *   sub_020079BC_File  0x020A7068  data
 *   sub_02007AA4_File  0x020A706C  data
 *   sub_02007B20_File  0x020A707C  data
 *   func_02082A7C      0x02082A7C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   sub_02007B50   0x02007B50  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02020FE4  0x02020FE4  thumb
 *   func_02021288  0x02021288  thumb
 *   func_0202130C  0x0202130C  thumb
 *   sub_02008254_File  0x020A708C  data
 */
#include "../../matched/include/Obj00370.h"
#include "../../matched/include/Obj11223.h"
#include "../../matched/include/Obj08731.h"
#include "../../matched/include/Obj15568.h"
#include "../../matched/include/Obj15569.h"
#include "../../matched/include/Obj16869.h"

struct State;
struct SaveCtrl;
struct SaveCtrl;
struct Big;
struct Job;
struct Obj02031DC0;
struct Obj;
struct MsgBank;
struct Rec;
struct SaveCtrl;
struct MsgData;
struct Su0Entry;
struct Sub02007454Header;
struct Sav;
struct Strbuf;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int u32;

struct SaveCtrl
{
  u8 unk00;
  u8 unk01;
  u8 unk02;
  u8 unk03;
  u8 unk04;
  u8 unk05;
  u8 pad06[6];
  u32 unk0C;
  void *unk10;
  void *unk14[9];
};

typedef unsigned short u16;

typedef enum { SLOT_0, SLOT_1, SLOT_2, SLOT_3, SLOT_4, SLOT_5, SLOT_6, SLOT_7, SLOT_8, SLOT_MAX } Slot;



typedef enum { BIT_0, BIT_MAX = 9 } Bit;

struct Sub02007168 {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
};



struct Ctrl020071D8 {
    unsigned char pad[16];
    void *unk10;
};



struct Sub02007248 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
};

struct Desc {
    u8 data[0x18];
};











struct Su4Entry {
    u32 data[0x22];
};

struct Su4Name {
    u8 data[0x28];
};

struct Sub02007454Header {
    u32 unk00;
    struct Su4Name unk04[0x18];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};



struct Su0Header {
    u32 unk00;
    u8  pad04[0x3C4 - 4];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};



struct Su0Entry {
    u8 data[0x88];
};











struct Sub0200785CHeader {
    u32 unk00;
    struct Su4Name unk04[0x18];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};



struct Sub020079BCHeader {
    u32 unk00;
    struct Su4Name unk04[0x18];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};



typedef signed char   s8;

struct PerapVoice {
    u32 unk00;
    u8  data[1000];
};

struct Item {
    u16 id;
    u16 qty;
};

typedef signed short   s16;

struct MyItemSave {
    s16 unk00[5];
    s16 unk0A[5];
    u16 unk14;
    u16 unk16;
    s16 unk18[4];
    s16 unk20[4];
    u16 unk28;
    u16 unk2A;
};

extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203192C(void *a, void *b);
extern int func_02031AE0(struct State *o, u32 a1);
extern void *func_020319C0(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_021DFC20(u32 heap);
extern u8 func_021DFE90(u8 *p);
extern int func_021DFE98(u8 *p);
extern void func_021DFDB8(void *p);
extern u8 sub_02008754(void *sys);
extern int sub_02008784(void *sys, u32 index);
extern u32 sub_0200725C(struct SaveCtrl *ctrl, u32 id, u8 heap);
extern void sub_020072A4(struct SaveCtrl *ctrl, u32 id);
extern void *sub_0200A5F8(void *sys);
extern void sub_0200A7EC(struct Big *p, u8 value);
extern u32 func_020307B0(void *p);
extern void func_0203195C(u8 *p);
extern void *func_0200A5F8(void *self);
extern void func_0200A7EC(struct Big *h, u8 v);
extern int func_02008784(void *sys, u32 index);
extern u32  func_0200725C(struct SaveCtrl *self, u32 a, u8 heap);
extern void func_020072A4(struct SaveCtrl *self, u32 a);
extern void func_020087C0(void *sys, u32 index);
extern void func_02007428(void);
extern int func_02031BB4(u32 a0);
extern u8 func_02008754(void *sys);
extern int func_02031E68(const char *ptr);
extern u32 func_020319A4(u8 *p, u32 id);
extern u32 func_02031994(u8 *p, u32 *out);
extern int func_020319F0(struct Job *job, u32 heap);
extern void *veneer_020319E4(void *p);
extern int func_020334E8(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u32 *func_020087D4(void *sys, u32 index);
extern int func_02031DC0(struct Obj02031DC0 *a0, u32 a1, u32 a2);
extern void *func_02031948(void *desc, u32 heap, void *buf, u32 size,
                           u32 c);
extern void func_020087A8(void *sys, u32 index);
extern void  func_02031C10(u8 *a, u8 *b, u32 c);
extern int func_02031C30(struct Obj *a, struct Obj *b);
void func_02007400(char *a0, u32 a1, u32 a2);
extern void func_02033478(int a0, int a1, int a2);
extern void *sub_020071CC(struct SaveCtrl *ctrl, u32 id);
extern struct Su0Entry *sub_02007AF4(void **save, u32 box);
extern u32 sub_02017E88(void *p, u32 id, u32 v);
extern void sub_020181A0(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
void sub_02007464(struct Sub02007454Header *h);
struct Sub02007454Header *sub_020074CC(void **save);
int sub_0200752C(void **save, u32 box, const struct Su4Entry *src);
void sub_02007454(struct Sub02007454Header *h);
extern void sub_02017550(struct Sav *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045A38(struct U16Vec *src, unsigned short *dest,
                          u32 n);
extern void func_02082A7C(u32 value, void *dest, u32 size);
void sub_02007B08(void *p);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
void sub_02007B54(struct PerapVoice *p);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern u32 func_02021288(u32 a);
extern u32 func_0202130C(u32 id);
struct Item *sub_02007D94(struct Item *arr, u32 n, u16 id, u16 qty, u16 max);
struct Item *sub_02007DF8(u8 *base, u16 id, u16 qty, u16 d);
struct Item *sub_02007ECC(struct Item *arr, u32 n, u16 id, u16 qty);
struct Item *sub_02007EF8(u8 *base, u16 id, u16 qty, u16 d);
u32 sub_02007F7C(const struct Item *arr, u32 n);
void sub_02007FD0(struct Item *a, struct Item *b);
void sub_02007FF4(struct Item *arr, u32 n);
void sub_02008038(struct Item *arr, u32 n);
void sub_02008058(struct Item *arr, u32 n);
void sub_020080A0(struct Item *arr, u32 n);
void sub_020080FC(struct Item *arr, u32 n);
struct SaveCtrl *func_02006F20(int heap);
void sub_02007084(void);
struct SaveCtrl *sub_020070A4(void);
int func_020070C8(char *self);
int func_02007150(int a0);
int func_020071A8(int a0);
u32 func_020071C0(char *p);
void func_02007374(char *a0, u32 a1);
int func_020073B0(char *a0, u32 a1);
void sub_02007428(void);
void sub_02007454(struct Sub02007454Header *h);
void sub_02007664(void *save, u32 box, u32 slot);
u32 sub_02007698(void *save);
u8 sub_020076A4(void *save);
u8 sub_020076B4(void *save);
int sub_020076D0(void *save, int *pbox, int *pslot);
int sub_02007774(void *save);
int sub_020077B8(void *save, u32 box);
void sub_0200780C(void *save, u32 box);
u8 sub_0200781C(void *save, u32 box);
void sub_02007838(void *save, u32 box, u8 v);
void sub_0200785C(void *save, u32 box, void *dest);
void sub_02007898(void *save, u32 box, const void *src);
int sub_020078C4(void *save, u32 box);
int sub_0200791C(void *save, u32 box);
int sub_02007984(void *save);
int sub_020079A0(void *save);
int sub_020079BC(void **save, u32 box, u32 slot, int field, int arg);
struct Su0Entry *sub_02007A18(void **save, u32 box, u32 slot);
void sub_02007A68(void *save, u32 bits);
int sub_02007A80(void *save, u32 bits);
u32 sub_02007A9C(void);
u32 *sub_02007AA4(u32 heap, u32 value);
void sub_02007AC8(void *p);
u32 sub_02007CB0(void);
void sub_02007CB8(void *p);
void sub_02007CC8(u8 *base, void *buf, u32 id, int save);
u32 sub_02007D00(u8 *base, u32 id, void **pp, u32 *pn);
u32 sub_02007D6C(u8 *base, u32 a, void **pp, u32 *pn, u16 d);
void *sub_02008254(u32 heap);
extern u8 ov228_id[];
extern const char sub_02006F20_File[];
extern const char sub_02006F20_Msg[];
extern struct SaveCtrl *sub_02006F20_Ptr;
extern u8 g_0209D938[];
extern struct SaveCtrl *sub_02007084_Ptr;
extern const char sub_020070A4_File[];
extern struct Desc func_0200725C_Table[];
extern const char sub_020072A4_File[];
extern struct Desc func_020072CC_Table[];
extern struct Desc sub_02007324_Table[];
extern const char sub_0200734C_File[];
extern char  g_020A7064[];
extern const char sub_020073D8_File[];
extern const char sub_0200752C_File[];
extern const char sub_020075B0_File[];
extern const char sub_020077B8_File[];
extern const char sub_0200785C_File[];
extern const char sub_020079BC_File[];
extern const char sub_02007AA4_File[];
extern const char sub_02007B20_File[];
extern const char sub_02008254_File[];



/*
 * The constructor of "save_control.c" (the file name string at 0x020A7054 is
 * the one this passes to the debug allocator at 0x02030734, line 0x58).  It
 * loads the overlay that owns the save code, reads three mode bytes out of
 * it, allocates the 0x38 byte control block into the global at 0x02146168,
 * and then walks the nine save streams at +0x14 deciding which to open.
 *
 * 0x000000E4 is the overlay id, an absolute linker symbol and not the plain
 * integer 228: written as a literal it compiles `movs r0, #0xe4` with no
 * pool word, where the original has `ldr r0, [pc, #0x148]` over a pool word
 * 0x000000E4.  See
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * Both dispatches are dense PC-relative halfword tables over five cases, so
 * every low case label exists in the source even where the arm is empty;
 * see docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * WAVE 16 (docs/notes/func_02006F20.c.txt had it at 118 out and
 * MATCH-capped).  The cap went with the ov228 leaves matched this wave
 * (src/matched/func_021DFDB8.c, func_021DFE90.c, func_021DFE98.c; plus the
 * labelled func_021DFC20), carried by the ov228 hints above; func_021DFE90
 * takes the overlay work pointer (its body reads r0).  The bytes closed in
 * three steps: a fresh body with the switch value `r` tested as
 * (u32)(r - 1) <= 1 before sub_02008754 (167 out, size exact); an ENUM loop
 * counter over the nine slots, which keeps the image's unfolded `cmp r4, #9`
 * guard (10 out); and the loop written in its own shape, `i = 0; if (i <
 * MAX) { flags = &c->unk0C; do { ... i++; } while (i < MAX); }`, which puts
 * the flags pointer after the guard where the image computes it.  A `for`
 * with flags assigned inside the body instead keeps a second top test.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006F20.c \
 *       --func func_02006F20 --addr 0x02006F20 --cc 1.1p1 --thumb
 */
struct SaveCtrl *func_02006F20(int heap)
{
    struct SaveCtrl *c;
    void *ov;
    u8 mode;
    int sub;
    int r;
    int s;
    Slot i;
    u32 *flags;

    func_02034AC4((int)ov228_id);
    ov = func_021DFC20(heap);
    mode = func_021DFE90(ov);
    sub = func_021DFE98(ov);
    func_021DFDB8(ov);
    func_02034A5C((int)ov228_id);
    c = (struct SaveCtrl *)func_02030734(heap, 0x38, 1, sub_02006F20_File, 0x58);
    sub_02006F20_Ptr = c;
    c->unk00 = 1;
    c->unk02 = 1;
    c->unk01 = 0;
    c->unk04 = mode;
    c->unk05 = sub;
    c->unk10 = (void *)func_0203192C(g_0209D938, (void *)heap);
    r = func_02031AE0(c->unk10, 1);
    if ((u32)(r - 1) <= 1 && sub_02008754(c) == 1)
        r = 0;
    c->unk0C = 0;
    if (sub == 1)
        c->unk0C |= 0x800;
    switch (r) {
    case 1:
        c->unk02 = 0;
    case 2:
        c->unk00 = 0;
        c->unk01 = 1;
        if (r == 2)
            c->unk0C |= 1;
        i = 0;
        if (i < SLOT_MAX) {
            flags = &c->unk0C;
            do {
                if (sub_02008784(c, i) == 1) {
                    s = sub_0200725C((struct SaveCtrl *)c, i, 1);
                    sub_020072A4((struct SaveCtrl *)c, i);
                    switch (s) {
                    case 1:
                    case 2:
                        if (i == 6)
                            sub_0200A7EC(sub_0200A5F8(c), 1);
                        break;
                    case 0:
                    case 3:
                    case 4:
                        *flags |= 1 << (i + 2);
                        if (i == 6)
                            sub_0200A7EC(sub_0200A5F8(c), 0);
                        break;
                    }
                } else if (i == 6) {
                    sub_0200A7EC(sub_0200A5F8(c), 0);
                }
                i++;
            } while (i < SLOT_MAX);
        }
        break;
    case 3:
        c->unk0C |= 2;
    case 0:
    case 4:
        func_020319C0(c->unk10);
        break;
    default:
        func_02034714(sub_02006F20_Msg, 0, sub_02006F20_Msg);
        break;
    }
    return c;
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * alias: this is "save_control.c".  The constructor of the object these two
 * reach, sub_02006F20 at the head of the same original file, passes
 * 0x020A7054 to the debug allocator, and the bytes at 0x020A7054 spell
 * "save_control.c".  That function is a near miss and is not in this tree;
 * see the header of src/matched/unit_020071E4.c for the census.
 *
 * The teardown and the checked getter for the one global the file keeps: a
 * pointer at 0x02146168 to the 0x38 byte control block.  sub_020070A4 loads
 * that pointer twice out of one pool word, once for the assertion and once
 * for the result, which is what a global read either side of a call looks
 * like.
 *
 * The range stops at 0x020070C8 for an evidence reason.  sub_020070C8, 134
 * bytes, is the per-frame step of the same object and it calls
 * sub_020087C0, whose only branch anywhere in the 3.9 MB image is the `bl`
 * at 0x02007140 inside it: `label` has one witness and it is in the bytes
 * under test, `literal` sees no pool word naming the address at all, and no
 * cut can move the caller out of the range that contains it.  It closes the
 * day anything else in the image calls 0x020087C0.
 *
 * 0x020A7064 is the empty string, not a file name.  "save_control.c" ends
 * with its NUL at 0x020A7062 and the next twelve bytes are NUL up to
 * "box_savedata.c" at 0x020A706C, so the assertion helper at 0x02034714 is
 * being passed an empty message here and at six further sites in the same
 * original file.  The address is carried by the `literal` class: the pool
 * word at 0x02007080, inside sub_02006F20 and so outside this range, holds
 * it too.
 */
void sub_02007084(void)
{
    if (sub_02007084_Ptr != 0) {
        func_0203195C(sub_02007084_Ptr->unk10);
        func_020307B0(sub_02007084_Ptr);
        sub_02007084_Ptr = 0;
    }
}



struct SaveCtrl *sub_020070A4(void)
{
    if (sub_02007084_Ptr == 0) {
        func_02034714(sub_020070A4_File, 0, sub_020070A4_File);
    }
    return sub_02007084_Ptr;
}



/*
 * save_control.c.  EXACT* (the 136-byte extent includes the 2-byte pad).
 * Two levers closed the 35-byte near miss of docs/notes/pkt_020070C8.c.txt:
 * the bit loop's counter is an enum, which keeps the `cmp r4, #9; bge`
 * entry guard (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md),
 * and the early exit is `goto end` onto the one `return t`, so the branch
 * lands on the shared `adds r0, r7, #0` instead of straight on the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020070C8.c  *       --func func_020070C8 --addr 0x020070C8 --thumb --cc 1.1p1
 */
int func_020070C8(char *self)
{
    int t = func_02031AE0(*(struct State * *)&((struct Obj00370 *)self)->f10, 1);
    void *h;
    Bit i;

    if (t != 1 && t != 2) {
        goto end;
    }
    {
        ((struct Obj00370 *)self)->f1 = 1;
        h = func_0200A5F8(self);
        func_0200A7EC(h, 0);
        if (func_02008784(self, 6) == 1) {
            int r = func_0200725C((struct SaveCtrl *)self, 6, 1);

            func_020072A4((struct SaveCtrl *)self, 6);
            if (r != 1 && r != 2)
                goto bits;
            func_0200A7EC(h, 1);
        }
bits:
        if (*(int *)&((struct Obj00370 *)self)->fC != 0) {
            for (i = 0; i < 9; i++) {
                if (*(int *)&((struct Obj00370 *)self)->fC & (1 << (i + 2)))
                    func_020087C0(self, i);
            }
        }
    }
end:
    return t;
}


int func_02007150(int a0){ int t0, t1, t2; t0 = func_02008754((void *)a0); ((struct Obj11223 *)((char *)((a0 + 0))))->f3 = (unsigned char)t0; t1 = func_02008774((int)((a0 + 0) + 0)); t2 = func_02031B8C((int)((struct Obj11223 *)((char *)((a0 + 0))))->f10); return t2; }


/*
 * Two byte flags at +4 and +5 are one `||` (the first arms the early return,
 * the second skips it), while the pair at the end is a genuine `&&` - so
 * only the first guard shares its exit.  The early arm returns the zero it
 * just stored into both flags, which is why the `movs r0, #0` is not
 * duplicated into a third register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007168.c \
 *       --func func_02007168 --addr 0x02007168 --cc 1.1p1 --thumb
 */
u32 func_02007168(struct Sub02007168 *p)
{
    u32 r;

    if (p->unk04 == 1 || p->unk05 == 1) {
        func_02007428();
        p->unk04 = 0;
        p->unk05 = 0;
        return 0;
    }
    r = func_02031BB4(p->unk10);
    if (r == 2 && func_02008754(p) == 0) {
        p->unk00 = 0;
        p->unk01 = 1;
    }
    return r;
}



int func_020071A8(int a0){ int t0, t1; t0 = func_02031C04((int)((struct Obj08731 *)((char *)((a0 + 0))))->f10); if ((unsigned int)(((struct Obj08731 *)((char *)((a0 + 0))))->f3) == (unsigned int)(1)) { t1 = func_02008764((int)((a0 + 0) + 0)); } else {  return ((struct Obj08731 *)((char *)((a0 + 0))))->f3; } }



/*
 * Thumb tail-call stub: loads p->field_0x10 and tail-calls func_02031E68.
 * Witness leaf for ov034 func_021F09BC.
 */
u32 func_020071C0(char *p)
{
    return func_02031E68(*(void **)(p + 0x10));
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One function, twelve bytes, and it is the block lookup every save accessor
 * in this region goes through: src/matched/unit_02007454.c, unit_02007664.c,
 * unit_02007774.c, unit_020079BC.c and unit_02007AC8.c all reach their data
 * through it.  It is a tail call, so it has no prologue and no label of its
 * own beyond the one disasm.py's cross-reference pass gave it; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * It is a file of its own for an evidence reason rather than a structural
 * one.  The twelve bytes on either side of it, 0x020071C0 and 0x020071D8,
 * are the same shape with the same object and tail-call the ARM addresses
 * 0x02031E68 and 0x02031994.  Neither of those two carries a `func_` label:
 * they open `ldr r0, [r0, #0x144]` and `ldr r2, [r0, #0x30]` with no
 * register-saving prologue, so disasm.py's sweep never fires on them, and
 * the only word in the whole image that names either is the pool word of the
 * caller under test.  `literal` therefore discards its own witness and
 * neither address can be attested, so both functions are left out and this
 * one is cut free between them.  0x020319A4, by contrast, is a labelled ARM
 * function reached by `bl` from 0x02032B10 and 0x02032C5C, which is the
 * `label` class with two witnesses outside any range here.
 */
void *sub_020071CC(struct SaveCtrl *ctrl, u32 id)
{
    return (void *)func_020319A4(ctrl->unk10, id);
}


/*
 * Unlabelled Thumb tail-call thunk: func_02031994(ctrl->unk10); sibling of sub_020071CC.
 */
void *func_020071D8(struct Ctrl020071D8 *ctrl, int *out)
{
    return (void *)func_02031994(ctrl->unk10, (u32 *)out);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02007210, sub_02007214, sub_02007218, sub_0200721C,
 *           sub_02007220, sub_02007230, sub_0200723C
 *
 * Eleven accessors on the save_control block, and eight of the eleven carry
 * no label at all: they are two and three instruction bodies ending in
 * `bx lr` or in a pool word and a `bx`, so the generated listing prints them
 * as a run of `.word`s between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  The run was
 * read out of the bytes and the section map that `tu` prints is what checks
 * the boundaries.
 *
 * sub_0200723C tail-calls through 0x020319E4, which is a linker veneer and
 * not a function: the twelve bytes there are `ldr ip, [pc, #0]; bx ip` and a
 * pointer word.  The extern is therefore declared at the veneer's address
 * and marked `arm`, which is also the name disasm.py gives it in the
 * listing; see
 * docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md.
 *
 * The range is cut where it is for evidence rather than for structure.  Two
 * twelve byte functions of exactly the same shape sit just below it, at
 * 0x020071C0 and 0x020071D8, and tail-call 0x02031E68 and 0x02031994; both
 * of those are ARM bodies with no register-saving prologue, so disasm.py
 * never labelled them, and each is named by exactly one word in the image,
 * the pool word of its own caller.  `literal` discards a witness inside the
 * compared range and `label` has no label to read, so neither can be
 * attested at any cut and both functions are left out.  The range stops
 * before 0x02007248 for the same reason: that function's only external
 * reference is the ARM 0x020334E8 and its only `blx` anywhere in the image
 * is the one inside it, so the witness is the call itself.
 *
 * The one near miss above this range is sub_02006F20, the constructor, 336
 * bytes at 0x02006F20.  It calls four addresses in overlay space, 0x021DFC20,
 * 0x021DFE90, 0x021DFE98 and 0x021DFDB8, and none of them is attestable: the
 * cross-region index knows the branches, but `attest_overlay_label` also
 * demands that some overlay's own listing carry a `func_` label at the
 * address, and no overlay labels any of the four.  0x021DFDB8 is the case
 * docs/MATCHING.md already records, inside seven overlays and labelled by
 * none of them.  Nothing about the C is in question and no cut helps, since
 * the targets are outside the region entirely.
 */
u8 sub_020071E4(const struct SaveCtrl *ctrl)
{
    return ctrl->unk00;
}

u32 sub_020071E8(const struct SaveCtrl *ctrl)
{
    return ctrl->unk0C;
}

u8 sub_020071EC(const struct SaveCtrl *ctrl)
{
    return ctrl->unk01;
}

int sub_020071F0(struct SaveCtrl *ctrl)
{
    if (sub_020071E4(ctrl) == 1 && sub_020071EC(ctrl) == 1) {
        return 1;
    }
    return 0;
}

u8 sub_02007210(const struct SaveCtrl *ctrl)
{
    return ctrl->unk04;
}

void sub_02007214(struct SaveCtrl *ctrl, u8 v)
{
    ctrl->unk04 = v;
}

u8 sub_02007218(const struct SaveCtrl *ctrl)
{
    return ctrl->unk05;
}

void sub_0200721C(struct SaveCtrl *ctrl, u8 v)
{
    ctrl->unk05 = v;
}

void *sub_02007220(struct SaveCtrl *ctrl)
{
    ctrl->unk00 = 1;
    ctrl->unk02 = 1;
    return func_020319C0(ctrl->unk10);
}

void *sub_02007230(struct SaveCtrl *ctrl)
{
    return (void *)func_020319F0(ctrl->unk10, 1);
}

void *sub_0200723C(struct SaveCtrl *ctrl)
{
    return veneer_020319E4(ctrl->unk10);
}


/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * A five-argument forwarder: the fifth parameter is copied out of the
 * caller's frame into this function's own outgoing slot, so the small
 * `push {r3, lr}` + `sub sp, #4` pair is the callee's stack argument home
 * area, not saved state (see
 * docs/idioms/a-defaulting-wrapper-spends-one-zero-on-r3-and-the-stack-word.md
 * for the sibling shape).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007248.c \
 *       --func func_02007248 --addr 0x02007248 --cc 1.1p1 --thumb
 */
int func_02007248(struct Sub02007248 *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    return func_020334E8((u8 *)p->unk10, a1, a2, a3, a4);
}



/*
 * One of nine save-stream slots the save_control block tracks at +0x14.
 * The slot is opened through the backup-system stream constructor, the open
 * is checked by func_02008784, and on success the record is committed by
 * func_02031DC0.
 *
 * Two findings closed this function and its sibling (the other of the pair
 * is noted in each file):
 *
 * 1. func_02031DC0's second and third arguments are (heap, buf), NOT
 *    (buf, heap).  The image names the order directly: heap is loaded into
 *    r1 from its stack home and the func_020087D4 result is dereferenced
 *    into r2.  Every statement reordering, temporary and pointer/type
 *    variation leaves a flat 5-byte residue at exactly those two loads --
 *    tools/permuter.py could not move it at all in 74 (0x0200725C) and 90
 *    (0x020072CC) mutations -- because the residue is in the DECLARATION,
 *    not the body.  Compare src/matched/func_02031DC0.c, whose own
 *    parameters are (Obj *, u32 a1, u32 a2) with a1 passed straight to
 *    func_02031FE0/func_02032688; this file fixes which of the two is heap.
 *
 * 2. The heap parameter is u8, not u32.  With u32 the constant set-up sinks
 *    past the incoming spill (`str r2, [sp]` moves four halfwords later),
 *    which is the residue docs/notes recorded for both functions and which
 *    src/matched/unit_020072A4.c's header describes as unexplained.  It is
 *    a heap id, a small byte value, and narrowing the PARAMETER is what
 *    closes it: a u32 parameter with a u8 local copy, or a u8 in the callee
 *    prototype alone, both stay DIFF.  The matched callers
 *    (src/matched/unit_0200B4E0.c, unit_0200B5CC.c) spell the argument u32;
 *    that is a caller-side widening and does not contradict this, but the
 *    conflict is recorded here rather than silently resolved.
 */
u32 func_0200725C(struct SaveCtrl *ctrl, u32 id, u8 heap)
{
    ctrl->unk14[id] = (void *)func_0203192C(&func_0200725C_Table[id], (void *)heap);
    if (func_02008784(ctrl, id) == 0) {
        return 0;
    }
    func_02031DC0(ctrl->unk14[id], heap, *func_020087D4(ctrl, id));
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The close of one of the nine save streams the save_control block tracks at
 * +0x14.  The slot is asserted non-null and then cleared, and the assertion
 * message is the empty string at 0x020A7064, the same one six other
 * functions of this original file pass.  sub_0200734C in
 * src/matched/unit_02007324.c is the same function again on the same slot
 * array with its own pool word, which is what says these are two entry
 * points and not one.
 *
 * Two near misses bracket this range and neither is an evidence problem.
 *
 * 0x0200725C, 72 bytes, and 0x020072CC, 88 bytes, are the matching opens.
 * Both reproduce every instruction, every register and the whole of their
 * control flow, and both are wrong only in where the incoming third argument
 * is spilled.  The original stores it to its stack home as the first thing
 * the body does and then loads it back at each use (`str r2, [sp]` then
 * `ldr r1, [sp]` in 0x0200725C, `str r2, [sp, #4]` then two `ldr r1,
 * [sp, #4]` in 0x020072CC); this compiler keeps the value in r2 for the
 * first use and sinks the store past the constant set-up, which is 10 bytes
 * in the first function and 7 in the second, all of them in the four
 * halfwords around the spill.  Thirty source shapes were tried against each,
 * crossing the parameter types, pointer temporaries for the slot and the
 * descriptor, statement splitting, the prototype arity of func_0203192C and
 * func_02031948, a struct-by-value parameter and an address-taken one; every
 * one of them lands on the same two counts except the shapes that change the
 * function outright.  A `volatile` local closes 0x0200725C and makes
 * 0x020072CC worse, so it is a coincidence and not the answer, and it is not
 * a claim the bytes support.  All nine front ends at -O4,p agree with each
 * other here, so it is not a version question either.
 */
void sub_020072A4(struct SaveCtrl *ctrl, u32 id)
{
    if (ctrl->unk14[id] == 0) {
        func_02034714(sub_020072A4_File, 0, sub_020072A4_File);
    }
    func_0203195C(ctrl->unk14[id]);
    ctrl->unk14[id] = 0;
}


u32 func_020072CC(struct SaveCtrl *ctrl, u32 id, u8 heap, void *buf, u32 size)
{
    ctrl->unk14[id] = func_02031948(&func_020072CC_Table[id], heap, buf, size, 1);
    if (func_02008784(ctrl, id) == 0) {
        return 0;
    }
    return (u32)func_02031DC0(ctrl->unk14[id], heap, *func_020087D4(ctrl, id));
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The open-for-write that does not register the stream afterwards, and a
 * second copy of the close.  sub_02007324 passes zero where sub_020072CC
 * passes one as the fifth argument of func_02031948, and stores the result
 * with a plain `str r0, [r1, #0x14]` rather than through the `+0x14` base
 * register the other accessors build, because the slot is written once and
 * never read back in this function.
 *
 * 0x0209D950 is the table of 0x18 byte stream descriptors, indexed by the
 * stream id and passed by address.  Three pool words in this original file
 * name it, at 0x020072A0, 0x02007320 and 0x02007348, and the first two are
 * outside this range, which is what carries it under the `literal` class.
 * func_02031948 is likewise reached from exactly two places in the image,
 * 0x020072EE and 0x0200733C, so the cut at 0x02007324 is what leaves the one
 * inside this range a witness.
 */
void sub_02007324(struct SaveCtrl *ctrl, u32 id, u32 heap, u32 a,
                  u32 b)
{
    ctrl->unk14[id] = func_02031948(&sub_02007324_Table[id], heap, (void *)a, b, 0);
}

void sub_0200734C(struct SaveCtrl *ctrl, u32 id)
{
    if (ctrl->unk14[id] == 0) {
        func_02034714(sub_0200734C_File, 0, sub_0200734C_File);
    }
    func_0203195C(ctrl->unk14[id]);
    ctrl->unk14[id] = 0;
}



/*
 * Release slot `a1` of the 0x14-stride handle table: the zero test on the
 * slot is a debug/guard call that passes the same pointer as argument 1 and
 * argument 3 (the compiler loads the pool word once and copies it twice, so
 * the source really did name it twice).  The object pointer at +0x10 is the
 * first argument of the final call and the table entry the second; the third
 * is the raw pointer func_020087D4 returns, not its target.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007374.c \
 *       --func func_02007374 --addr 0x02007374 --cc 1.1p1 --thumb
 */
void func_02007374(char *a0, u32 a1)
{
    u32 *slot = (u32 *)(a0 + 0x14);

    if (slot[a1] == 0) {
        func_02034714(g_020A7064, 0, g_020A7064);
    }
    func_020087A8(a0, a1);
    func_02031C10((u8 *)((struct Obj15568 *)a0)->f10, (u8 *)slot[a1], (u32)func_020087D4(a0, a1));
}



/*
 * The shortest member of the 0x14-stride handle-table family: guard, then
 * one call taking the object's +0x10 word and the table entry.  Same
 * double-named guard pointer as func_02007374 and func_02007400.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020073B0.c \
 *       --func func_020073B0 --addr 0x020073B0 --cc 1.1p1 --thumb
 */
int func_020073B0(char *a0, u32 a1)
{
    u32 *slot = (u32 *)(a0 + 0x14);

    if (slot[a1] == 0) {
        func_02034714(g_020A7064, 0, g_020A7064);
    }
    return func_02031C30((struct Obj *)((struct Obj15569 *)a0)->f10, (struct Obj *)slot[a1]);
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One checked forwarder on the stream slot array: the slot is asserted
 * non-null with the empty string at 0x020A7064 and then handed to the ARM
 * func_020319A4 with the caller's value.
 *
 * The function immediately after it, sub_02007400 at 0x02007400, is the same
 * twenty instructions against func_020319F0 and is left out.  Its callee is
 * named twice in the whole image: by the `blx` at 0x0200741E inside it, and
 * by the pool word at 0x02007238 in sub_02007230.  A pool word only counts
 * under the `literal` class, which requires the word to sit at an address
 * disasm.py classified as a literal pool, and 0x02007238 is inside an
 * unlabelled tail-call function rather than a pool, so it is not admitted.
 * The `label` class therefore has the one `blx`, which is inside whatever
 * range holds sub_02007400, and no cut can move it out.  The direction that
 * does work is the other one: src/matched/unit_020071E4.c holds the pool
 * word and takes that same `blx` as its outside witness, which is why the
 * accessor run stops at 0x02007248 and this range starts at 0x020073D8.
 *
 * The two functions immediately below this range, 0x02007374 and 0x020073B0,
 * are left out for the plainer version of the same reason.  Each is the only
 * thing in the image that names its callee: 0x02031C10 is reached only from
 * the `blx` at 0x020073A6 inside sub_02007374, and 0x02031C30 only from
 * 0x020073CE inside sub_020073B0.  The witness is in both cases the call
 * itself, so shrinking the range to the one function keeps it inside, and
 * the target is ARM library code that cannot be made `local`.  The same
 * argument leaves out 0x02007248, whose callee 0x020334E8 is named once, by
 * the `blx` at 0x02007252 inside it, and 0x02007150, 0x02007168 and
 * 0x020071A8, whose callees 0x02031B8C, 0x02031BB4 and 0x02031C04 are each
 * named once in the same way.  All six close the day something else in the
 * image calls those addresses.
 */
void *sub_020073D8(struct SaveCtrl *ctrl, u32 id, u32 v)
{
    if (ctrl->unk14[id] == 0) {
        func_02034714(sub_020073D8_File, 0, sub_020073D8_File);
    }
    return (void *)func_020319A4(ctrl->unk14[id], v);
}


/*
 * Close sibling of func_020073B0 with a value instead of the object word:
 * the table entry is read into r0 *after* the local is moved to r6, so the
 * argument order at the call is (slot, a2), not (a2, slot).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007400.c \
 *       --func func_02007400 --addr 0x02007400 --cc 1.1p1 --thumb
 */
void func_02007400(char *a0, u32 a1, u32 a2)
{
    u32 *slot = (u32 *)(a0 + 0x14);

    if (slot[a1] == 0) {
        func_02034714(g_020A7064, 0, g_020A7064);
    }
    func_020319F0((struct Job *)slot[a1], a2);
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The last function of "save_control.c": two four byte writes of zero, to
 * 0x0007F800 and 0x0007FC00, through the ARM func_02033478.  Those two
 * constants are plain integer pool words with no relocation on them at all,
 * so they are written as the constants they are rather than declared in the
 * `symbols:` block, and the zero is one stack word whose address is passed
 * to both calls.
 *
 * func_02033478 is named three times in the whole image: by the two `blx`
 * sites inside this function and by one `blx` at 0x021DFF42 in ov228.  That
 * overlay branch is the only thing that carries it, because both in-region
 * sites are inside any range that contains this function and the honesty
 * rule discards them; the cross-region index is what makes it a `label`.
 * Without it this function would be in the same position as 0x02007374 and
 * 0x020073B0 and would not be matchable at all.
 *
 * The only caller of this function anywhere is the `bl` at 0x02007178 inside
 * sub_02007168, which is itself left out (its callee 0x02031BB4 is named
 * once, by the `blx` inside it), so nothing here depends on that direction.
 */
void sub_02007428(void)
{
    u32 zero = 0;

    func_02033478(0x7F800, (int)(&zero), 4);
    func_02033478(0x7FC00, (int)(&zero), 4);
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_020074D8, sub_0200752C
 *
 * alias: this is where "box_savedata.c" starts.  The header of
 * src/matched/unit_020079BC.c records the file name, recovered from the
 * string at 0x020A706C that sub_02007AA4 passes to the debug allocator, and
 * says the file's boundaries are bracketed rather than located.  The front
 * one is located now: 0x02007454 is the first function of it.  What fixes it
 * is the pair 0x02007454 and 0x0200745C, the twelve bytes immediately after
 * the last function of "save_control.c".  0x0200745C returns 0x3E0, which is
 * sizeof of the 0x3DE byte box header rounded up to its four byte alignment,
 * and 0x02007464, the very next function, is the constructor that clears
 * exactly that header.  Every block file in this region opens with that
 * pair; see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  The
 * function before them, sub_02007428, passes no file name at all, but the
 * one before that passes 0x020A7064, the empty string "save_control.c" uses,
 * and the first function of this file that names anything names 0x020A7068,
 * which is the empty string every assert in unit_020079BC.c, unit_02007774.c
 * and the rest of "box_savedata.c" passes.  So the seam is between 0x02007454
 * and 0x02007428 and the two halves use different assertion strings across
 * it.
 *
 * The struct is the one unit_020079BC.c already declares: a current box index
 * at +0, twenty-four 0x28 byte names at +4, twenty-four bytes at +0x3C4, a
 * flag at +0x3DC and the box count at +0x3DD.  Four details are worth
 * naming, and three of them are worth three bytes each.
 *
 *  - sub_02007464 seeds the twenty-four bytes at +0x3C4 with a counter that
 *    wraps at sixteen, and the reset is `adds r4, r1, #0` off a register
 *    holding zero rather than a `movs`, which is the same "derive the
 *    constant from a register that already has one" the rest of this region
 *    shows.  The counter is not a `u8`: a byte variable would carry a
 *    `lsls #24` / `lsrs #24` pair at the increment and there is none, so it
 *    is an unsigned `int` stored through a `u8` array.  Which of the two
 *    zeroes the copy in r1 is taken from is decided by which is written
 *    first, so the counter has to be cleared in the `for` initialiser
 *    alongside the index (`for (i = 0, c = 0; ...)`); clearing it in the
 *    statement before the loop swaps r3 and r4 throughout.
 *  - sub_0200752C copies a whole 0x88 byte entry with an inline `ldm`/`stm`
 *    loop of seventeen iterations, which is
 *    docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: the entry has
 *    to be declared four-aligned (`u32 data[0x22]`), because a byte-aligned
 *    declaration turns the same assignment into a 0x88 iteration
 *    `ldrb`/`strb` loop.
 *  - sub_020074D8 walks the boxes from the current one and stops when it
 *    comes back to it, so the loop is a `do`/`while` with no guard, and the
 *    box count it reads on the way round is still live after the loop: the
 *    `cmp r1, #0x18` that follows compares the last value read inside it,
 *    not a fresh load, and the extra box it then opens is that value.  Its
 *    declaration order is load bearing for the same reason as the counter
 *    above: with the header pointer declared first it lands in r4 and the
 *    box index in r5, and the original has them the other way round.
 *  - the very next statement, the one that bumps the box count by eight,
 *    re-reads the field even though the value is sitting in r1.  Only the
 *    compound form does that; see
 *    docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md.
 */
void sub_02007454(struct Sub02007454Header *h)
{
    sub_02007464(h);
}

u32 sub_0200745C(void)
{
    return sizeof(struct Sub02007454Header);
}



void sub_02007464(struct Sub02007454Header *h)
{
    void *msg;
    u32 i;
    u32 c;

    for (i = 0, c = 0; i < 0x18; i++) {
        h->unk3C4[i] = c;
        c++;
        if (c >= 0x10) {
            c = 0;
        }
    }
    h->unk3DC = 0;
    msg = func_02045B38(0, 2, 9, 1);
    if (msg != 0) {
        for (i = 0; i < 0x18; i++) {
            func_02045F5C(msg, i + 6, (u16 *)(&h->unk04[i]), 0x14);
        }
        func_02045C04(msg);
    }
    h->unk00 = 0;
    h->unk3DD = 8;
}

struct Sub02007454Header *sub_020074CC(void **save)
{
    return sub_020071CC(*save, 0);
}

int sub_020074D8(void **save, const struct Su4Entry *src)
{
    u32 box;
    struct Sub02007454Header *h;
    u8 n;

    h = sub_020074CC(save);
    box = h->unk00;

    do {
        if (sub_0200752C(save, box, src) != 0) {
            return 1;
        }
        box++;
        n = h->unk3DD;
        if (box >= n) {
            box = 0;
        }
    } while (box != h->unk00);
    if (n != 0x18) {
        h->unk3DD += 8;
        sub_0200752C(save, n, src);
        return 1;
    }
    return 0;
}

int sub_0200752C(void **save, u32 box, const struct Su4Entry *src)
{
    struct Sub02007454Header *h = sub_020074CC(save);
    u32 slot;

    if (box == -1) {
        box = h->unk00;
    } else if (box >= h->unk3DD) {
        func_02034714(sub_0200752C_File, 0, sub_0200752C_File);
    }
    for (slot = 0; slot < 30; slot++) {
        struct Su4Entry *base = (struct Su4Entry *)sub_02007AF4(save, box);

        if (sub_02017E88(&base[slot], 5, 0) == 0) {
            base[slot] = *src;
            sub_020181A0(&base[slot]);
            return 1;
        }
    }
    return 0;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Writing one box entry and swapping two of them.  Both reach the entry
 * array through sub_02007AF4 the way every function of this file does, and
 * both copy a whole 0x88 byte entry with the inline eight byte ldm/stm loop
 * of docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: 0x11
 * iterations of two words.  The entry struct is therefore declared as an
 * array of u32 and not of u8, because a one aligned struct would have given
 * a 0x88 iteration ldrb/strb loop instead.
 *
 * sub_020075B0 bounds the box index against the header byte at 0x3DD rather
 * than against the constant 0x18 the rest of the file uses, and that byte is
 * past every Thumb immediate, so it arrives as a pool word and a register
 * offset ldrb.  The failure arm passes 0x020A7068 twice to func_02034714,
 * the same empty string and the same three argument assert shape as
 * sub_020077B8 in unit_02007774.c.
 *
 * sub_02007610 is the three assignment swap through a 0x88 byte stack
 * temporary, and its fifth argument arrives on the stack: `ldr r1, [sp,
 * #0xa0]` is 0x88 of locals plus the six saved registers, not a local.
 */
int sub_020075B0(void *save, u32 box, u32 slot,
                 const struct Su4Entry *src)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < h->unk3DD && slot < 30) {
        struct Su4Entry *base = (struct Su4Entry *)sub_02007AF4(save, box);

        base[slot] = *src;
        sub_020181A0(&base[slot]);
        return 1;
    }
    func_02034714(sub_020075B0_File, 0, sub_020075B0_File);
    return 0;
}

void sub_02007610(void *save, u32 box1, u32 slot1, u32 box2, u32 slot2)
{
    struct Su4Entry tmp;
    struct Su4Entry *p1 = (struct Su4Entry *)sub_02007AF4(save, box1);
    struct Su4Entry *p2 = (struct Su4Entry *)sub_02007AF4(save, box2);

    tmp = p1[slot1];
    p1[slot1] = p2[slot2];
    p2[slot2] = tmp;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * The box accessors: sub_020074CC turns the caller's save handle into the
 * 0x3DE byte box header, and sub_02007AF4 turns a box index into that box's
 * array of thirty 0x88 byte entries.
 *
 * Two encodings to note.  The header's `unk3DD` sits past every Thumb
 * immediate, so it arrives as a pool word and a register offset `ldrb`
 * rather than as an offset in the instruction, and sub_020076B4 loads that
 * same pool word twice, once for the read-modify-write and once for the
 * value it returns.  And the entry index is scaled by 0x88, which is not a
 * power of two, so it is a real `muls` with the constant materialised by
 * `movs r1, #0x88`: that is what indexing an array of a non power of two
 * sized struct looks like, and it is what says the element is 0x88 bytes
 * rather than that there is a multiply in the source.
 */
void sub_02007664(void *save, u32 box, u32 slot)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (slot < 30 && box < 0x18) {
        sub_02017550((struct Sav *)(&sub_02007AF4(save, box)[slot]));
    }
}


u32 sub_02007698(void *save)
{
    return ((struct Su0Header *)sub_020074CC(save))->unk00;
}


u8 sub_020076A4(void *save)
{
    return ((struct Su0Header *)sub_020074CC(save))->unk3DD;
}


u8 sub_020076B4(void *save)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);

    if (h->unk3DD != 0x18) {
        h->unk3DD += 8;
    }
    return h->unk3DD;
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * The one function between unit_02007664.c and unit_02007774.c: given a box
 * and a slot by reference, find the next occupied slot at or after it,
 * wrapping round the boxes, and write the answer back through the two
 * pointers.  sub_02017E88 asked with the field id 0xA9 is the "is this entry
 * empty" test, the same call unit_02007774.c counts with.
 *
 * Three things the shape says.  The box and slot are read out of the two
 * pointers once, before the outer loop, and are carried in registers: the
 * back edge at 0x0200774A lands on the sub_02007AF4 call and not on the
 * loads, so a source that re-read `*pbox` each time round would be a
 * different function.  The wrap comparison is signed (`blt`), so the index
 * is an int even though the bound is the unsigned byte at 0x3DD.  And that
 * byte is loaded once for the whole tail: the compiler keeps it live across
 * the loop exit and uses the same register for the `cmp #0x18` and for the
 * value written back through the pointer, so only the increment reloads it.
 *
 * The four parameters and the header pointer are all spilled to the stack at
 * sp+0..sp+0xC.  That is register pressure with r4..r7 carrying the box, the
 * slot, the entry base and the constant 0x88, not five pointers in the
 * source.
 */
int sub_020076D0(void *save, int *pbox, int *pslot)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);
    int box;
    int slot;

    if (*pbox == -1) {
        *pbox = h->unk00;
    }
    box = *pbox;
    slot = *pslot;
    while (1) {
        struct Su0Entry *base = (struct Su0Entry *)sub_02007AF4(save, box);

        while (slot < 30) {
            if (sub_02017E88(&base[slot], 0xA9, 0) == 0) {
                *pbox = box;
                *pslot = slot;
                return 1;
            }
            slot++;
        }
        box++;
        if (box >= h->unk3DD) {
            box = 0;
        }
        if (box == *pbox) {
            break;
        }
        slot = 0;
    }
    if (h->unk3DD != 0x18) {
        *pbox = h->unk3DD;
        *pslot = 0;
        h->unk3DD += 8;
        return 1;
    }
    return 0;
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02007838
 *
 * Counting the occupied entries of every box and of one box, the box
 * cursor's setter, and the getter and setter for the per-box byte at
 * 0x3C4.  sub_02017E88 is the "is this entry empty" test, asked with the
 * field id 0xA9 throughout.
 *
 * sub_02007774 spills its outer loop counter to the stack even though it is
 * an ordinary `int`: r4 through r7 are already carrying the inner counter,
 * the running total, the entry base and the constant 0x88, and the save
 * handle is on the stack too.  The spill is register pressure and not a
 * pointer in the source.
 *
 * The failure path of sub_020077B8 passes the same pointer as the first and
 * the third argument of func_02034714, which is the shape of an assertion
 * helper taking a file name twice.  The address is declared in the
 * `symbols:` block rather than written as `__FILE__`; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md.
 */
int sub_02007774(void *save)
{
    int box;
    int slot;
    int n = 0;

    for (box = 0; box < 0x18; box++) {
        struct Su0Entry *base = (struct Su0Entry *)sub_02007AF4(save, box);

        for (slot = 0; slot < 30; slot++) {
            if (sub_02017E88(&base[slot], 0xA9, 0) == 0) {
                n++;
            }
        }
    }
    return n;
}



int sub_020077B8(void *save, u32 box)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);
    struct Su0Entry *base;
    int slot;
    int n;

    if (box == -1) {
        box = h->unk00;
    }
    if (box >= 0x18) {
        func_02034714(sub_020077B8_File, 0, sub_020077B8_File);
    }
    n = 0;
    base = (struct Su0Entry *)sub_02007AF4(save, box);
    for (slot = 0; slot < 30; slot++) {
        if (sub_02017E88(&base[slot], 0xA9, 0) == 0) {
            n++;
        }
    }
    return n;
}



void sub_0200780C(void *save, u32 box)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);

    if (box < 0x18) {
        h->unk00 = box;
    }
}



u8 sub_0200781C(void *save, u32 box)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);

    if (box < 0x18) {
        return h->unk3C4[box];
    }
    return 0;
}



void sub_02007838(void *save, u32 box, u8 v)
{
    struct Su0Header *h = (struct Su0Header *)sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        h->unk3C4[box] = v;
    }
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02007984, sub_020079A0
 *
 * The box name getter and setter, two per box counts, and the whole-storage
 * totals that sum each of them over all 24 boxes.
 *
 * The range has to be exactly these six functions.  sub_020078C4 is called
 * from one place in the image and sub_0200791C from one place, and those two
 * places are sub_02007984 and sub_020079A0 respectively, so a file that
 * stopped before the summing loops would leave both counts with no witness
 * outside the compared range and cap at MATCH.  Inside one range they are
 * `local` and cost no image evidence at all.  It cuts the other way too: the
 * file cannot start any later than 0x0200785C, because that is where the
 * 0x28 byte name array's first user is.
 *
 * The header's layout falls out of the two shapes.  The name accessors do
 * `adds r2, r1, #4` and then multiply the box index by 0x28, so the names
 * are an array of 24 0x28 byte entries starting at offset 4 and ending at
 * 4 + 24 * 0x28 = 0x3C4, which is exactly where the per box byte the rest of
 * the file reads begins.
 *
 * Two of the six needed their locals reordering before they matched, and the
 * evidence is only ever which register a value lands in.  sub_0200791C
 * declares its slot counter before the entry base, the reverse of
 * sub_020078C4 immediately above it, and that one line is the whole
 * difference between r4/r5 and r5/r4 throughout its loop.  The two summing
 * loops initialise the box index before the running total, which is why
 * they are written `for (box = 0, n = 0; ...)` rather than initialising the
 * total at its declaration: the order of the two `movs rN, #0` follows the
 * order of the initialisers, and nothing else in either function does.
 */
void sub_0200785C(void *save, u32 box, void *dest)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        func_02045924(dest, (const u16 *)(&h->unk04[box]));
        return;
    }
    func_02034714(sub_0200785C_File, 0, sub_0200785C_File);
}


void sub_02007898(void *save, u32 box, const void *src)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        func_02045A38((struct U16Vec *)src, (unsigned short *)&h->unk04[box], 0x14);
    }
}


int sub_020078C4(void *save, u32 box)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);
    struct Su0Entry *base;
    int slot;
    int n;

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        n = 0;
        base = (struct Su0Entry *)sub_02007AF4(save, box);
        for (slot = 0; slot < 30; slot++) {
            if (sub_02017E88(&base[slot], 0xA9, 0) != 0) {
                n++;
            }
        }
        return n;
    }
    func_02034714(sub_0200785C_File, 0, sub_0200785C_File);
    return 0;
}


int sub_0200791C(void *save, u32 box)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);
    int slot;
    struct Su0Entry *base;
    int n;

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        n = 0;
        base = (struct Su0Entry *)sub_02007AF4(save, box);
        for (slot = 0; slot < 30; slot++) {
            if (sub_02017E88(&base[slot], 0xA9, 0) != 0 &&
                sub_02017E88(&base[slot], 0x4C, 0) == 0) {
                n++;
            }
        }
        return n;
    }
    func_02034714(sub_0200785C_File, 0, sub_0200785C_File);
    return 0;
}


int sub_02007984(void *save)
{
    int n;
    u32 box;

    for (box = 0, n = 0; box < 0x18; box++) {
        n += sub_020078C4(save, box);
    }
    return n;
}


int sub_020079A0(void *save)
{
    int n;
    u32 box;

    for (box = 0, n = 0; box < 0x18; box++) {
        n += sub_0200791C(save, box);
    }
    return n;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02007A9C, sub_02007AA4
 *
 * The checked entry accessor in its two forms, the flag byte at 0x3DC, the
 * size of one box page, and the four byte allocation the box code hangs its
 * per-save state on.
 *
 * alias: the file identity is in the image.  sub_02007AA4 passes 0x020A706C
 * to the debug allocator at 0x02030734, and the bytes at 0x020A706C spell
 * "box_savedata.c".  That is this code.  sub_02007B20, further down the same
 * run, passes 0x020A707C instead, and those bytes spell "perapvoice.c", so a
 * translation unit boundary falls between the two and the run
 * 0x02007664..0x02007B54 is at least two original files rather than one.
 * Neither name is used as a source file name in this tree yet, because the
 * boundary is bracketed (somewhere in 0x02007AC8..0x02007B20) rather than
 * located.
 *
 * The range used to stop at 0x02007AA4 for an evidence reason, and the
 * `string` class now carries it.  0x020A706C is named by exactly one pool
 * word in the image and it is this function's own, so `literal` has no
 * witness; the ten NUL bytes between "save_control.c"'s terminator at
 * 0x020A7062 and 0x020A706C used to be more padding than the class allowed.
 * They are not dead bytes: 0x020A7068 is an empty string, and it is the one
 * the five assert calls above pass.  The rule now walks the whole NUL run up
 * to twelve bytes and demands that 0x020A706C be the only address in it at
 * which a string begins, which it is: the empty string at 0x020A7068 is not
 * one.  See "The string class" in docs/MATCHING.md.
 *
 * sub_02007A9C carries no label because it saves nothing: `movs r0, #0xFF`,
 * `lsls r0, r0, #4`, `bx lr`.  0xFF0 is 30 entries of 0x88 bytes, which is
 * one box, and it never reaches a literal pool because a byte shifted left
 * costs two halfwords against a pool word plus its `ldr`.
 */
int sub_020079BC(void **save, u32 box, u32 slot, int field, int arg)
{
    struct Sub020079BCHeader *h = (struct Sub020079BCHeader *)sub_020074CC(save);

    if (box >= 0x18 && box != -1) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (slot >= 30) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (box == -1) {
        box = h->unk00;
    }
    return sub_02017E88(&sub_02007AF4(save, box)[slot], field, arg);
}


struct Su0Entry *sub_02007A18(void **save, u32 box, u32 slot)
{
    struct Sub020079BCHeader *h = (struct Sub020079BCHeader *)sub_020074CC(save);

    if (box >= 0x18 && box != -1) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (slot >= 30) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (box == -1) {
        box = h->unk00;
    }
    return &sub_02007AF4(save, box)[slot];
}


void sub_02007A68(void *save, u32 bits)
{
    struct Sub020079BCHeader *h = (struct Sub020079BCHeader *)sub_020074CC(save);

    h->unk3DC |= (u8)bits;
}


int sub_02007A80(void *save, u32 bits)
{
    struct Sub020079BCHeader *h = (struct Sub020079BCHeader *)sub_020074CC(save);

    if (h->unk3DC & bits) {
        return 1;
    }
    return 0;
}


u32 sub_02007A9C(void)
{
    return 0xFF0;
}


u32 *sub_02007AA4(u32 heap, u32 value)
{
    u32 *p = func_02030734(heap, 4, 0, sub_02007AA4_File, 0x3B9);

    *p = value;
    return p;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02007B00, sub_02007B08, sub_02007B20, sub_02007B44,
 *           sub_02007B50
 *
 * The two block lookups everything above goes through, the page clear, and
 * a constructor.  sub_02007B20 passes 0x020A707C to the debug allocator at
 * 0x02030734 with the line number 0x57, and the bytes at 0x020A707C spell
 * "perapvoice.c", so the second half of this range is that file.  The
 * string is named by one pool word in the whole image and it is this
 * function's own, so the `literal` class discards its only witness; the
 * `string` class closes it, because "box_savedata.c" ends with its NUL at
 * 0x020A707A and one byte of padding puts the next string at 0x020A707C by
 * construction.
 *
 * Three of the nine carry no label, all because they save nothing.
 * sub_02007AEC and sub_02007B00 return the two object sizes, 0xFF0 and
 * 0x3EC, each as `movs` plus `lsls` rather than a pool word; 0x3EC is what
 * sub_02007B08 clears and what sub_02007B20 allocates, which is how the
 * three tie together.  sub_02007AF4 is a tail call through a pool word, and
 * it is the function every accessor above reaches the entry array with.
 */
void sub_02007AC8(void *p)
{
    func_020307B0(p);
}


void sub_02007AD0(struct Su0Entry *base)
{
    u32 i;

    for (i = 0; i < 30; i++) {
        sub_02017550((struct Sav *)&base[i]);
    }
}

u32 sub_02007AEC(void)
{
    return 0xFF0;
}

struct Su0Entry *sub_02007AF4(void **save, u32 box)
{
    return sub_020071CC(*save, box + 1);
}

u32 sub_02007B00(void)
{
    return 0x3EC;
}

void sub_02007B08(void *p)
{
    func_02082A7C(0, p, 0x3EC);
    ((struct Obj16869 *)p)->f0 = 0;
}

void *sub_02007B20(u32 heap)
{
    void *p = func_02030734(heap, 0x3EC, 1, sub_02007B20_File, 0x57);

    sub_02007B08(p);
    return p;
}

struct Su0Entry *sub_02007B44(void *sys)
{
    return sub_020071CC(sys, 0x24);
}

void *sub_02007B50(void **p)
{
    return *p;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02007BD0, sub_02007C20, sub_02007C34, sub_02007C70
 *
 * The rest of "perapvoice.c", which src/matched/unit_02007AC8.c opens.  That
 * file names the object: its constructor allocates 0x3EC bytes and its clear
 * routine zeroes 0x3EC, and the same 0x3EC is what sub_02007C20 copies here.
 * The object is one `u32` flag followed by 1000 bytes, and sub_02007B50 in
 * the neighbouring file reads the flag that sub_02007B54 and sub_02007B5C
 * write.
 *
 * Four of the eight carry no label, because none of them saves lr.
 * sub_02007B5C is the `= 1` twin of sub_02007B54, sub_02007B64 returns the
 * address of the payload, sub_02007B68 and sub_02007BD0 are the codec pair,
 * and sub_02007C20 is a tail call into MI_CpuCopy8.
 *
 * What the range teaches:
 *
 *  - the payload is 1000 bytes holding two signed four bit samples each.
 *    sub_02007B68 expands them to 8000 bytes, four copies of each sample in
 *    the high nibble of a byte, and zero fills to 0x1FF4; sub_02007BD0 is the
 *    exact inverse, 0x1F40 bytes in and 1000 out.  The bias of eight in both
 *    directions is what makes the four bit field signed.
 *  - the `lsls #28` / `asrs #24` pair at the end of each expansion is
 *    `(s8)(v << 4)` and not `v << 4`: the truncation is materialised because
 *    the value is assigned to an `s8` local before the inner store loop, and
 *    writing the shift straight into the store gives `lsls #4` alone.
 *  - sub_02007BD0 packs the two nibbles into one byte with a plain store
 *    followed by an `|=`, which is why the byte is stored, reloaded with
 *    `ldrb` and stored again.  Neither half is masked on the way in, so the
 *    source is two `u8` statements and not a bitfield.
 *  - sub_02007B68 reloads `src[i]` for the second nibble rather than keeping
 *    it: source and destination are both `s8 *`, so the stores in between may
 *    alias and the compiler has to re-read.
 */
void sub_02007B54(struct PerapVoice *p)
{
    p->unk00 = 0;
}

void sub_02007B5C(struct PerapVoice *p)
{
    p->unk00 = 1;
}

u8 *sub_02007B64(struct PerapVoice *p)
{
    return p->data;
}

void sub_02007B68(s8 *dest, const s8 *src)
{
    int i;
    int j;
    int o;

    o = 0;
    for (i = 0; i < 1000; i++) {
        s8 a = (s8)((s8)((u8)(src[i] & 0xF) - 8) << 4);

        for (j = 0; j < 4; j++) {
            dest[o + j] = a;
        }
        {
            s8 b = (s8)((s8)((u8)(src[i] >> 4) - 8) << 4);

            for (j = 4; j < 8; j++) {
                dest[o + j] = b;
            }
        }
        o += 8;
    }
    for (i = 1000 * 8; i < 0x1FF4; i++) {
        dest[i] = 0;
    }
}

void sub_02007BD0(struct PerapVoice *p, const s8 *src)
{
    int i;
    int j;

    p->unk00 = 1;
    j = 0;
    for (i = 0; i < 0x1F40; i += 8) {
        u8 lo = (u8)((s8)(src[i] / 16) + 8);

        p->data[j] = lo;
        {
            u8 hi = (u8)((s8)(src[i + 4] / 16) + 8);

            p->data[j] |= (u8)(hi << 4);
        }
        j++;
    }
}

void sub_02007C20(struct PerapVoice *dest, const struct PerapVoice *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PerapVoice));
}

void sub_02007C34(struct PerapVoice *p, void *a)
{
    int i;
    int n = func_0201AA18(a);

    for (i = 0; i < n; i++) {
        if (func_02017E1C(func_0201AB28(a, i), 5, 0) == 0x1B9) {
            return;
        }
    }
    sub_02007B54(p);
}

u32 sub_02007C70(struct PerapVoice *p)
{
    if ((u32)sub_02007B50((void **)p) == 1) {
        u8 v = (u8)(p->data[0x64] ^ p->data[0x1F4] ^ p->data[0x2BC]);

        if (v < 100) {
            return 1;
        }
        if (v >= 150 && v < 256) {
            return 2;
        }
    }
    return 0;
}


#define NULL ((void *)0)


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02007D6C, sub_02007D94, sub_02007DF8, sub_02007E3C,
 *           sub_02007E50, sub_02007ECC, sub_02007EF8, sub_02007F1C,
 *           sub_02007F68, sub_02007F7C, sub_02007FA0, sub_02007FB8,
 *           sub_02007FD0, sub_02007FF4, sub_02008038, sub_02008058,
 *           sub_020080A0, sub_020080FC, sub_0200816C, sub_020081DC,
 *           sub_0200823C
 *
 * The item bag: a 0x9C0 byte block holding five arrays of `{u16 id; u16
 * qty;}` entries, and the add, take, count and sort routines over them.  The
 * file boundary at the low end is the block file opening idiom: sub_02007CB0
 * returns 0x9C0 and sub_02007CB8 fills exactly 0x9C0 bytes with zero, and the
 * function before it belongs to "perapvoice.c".
 *
 * The five arrays are named by the two switches, sub_02007D00 and the
 * unlabelled sub_020081DC, which agree entry for entry:
 *
 *   id 0   offset 0x000   0x136 entries
 *   id 4   offset 0x4D8   0x053 entries
 *   id 2   offset 0x624   0x06D entries
 *   id 1   offset 0x7D8   0x030 entries
 *   id 3   offset 0x898   0x040 entries
 *
 * and 0x898 + 0x40 * 4 is 0x998, which is the whole block bar 0x28 trailing
 * bytes.  The case bodies of both switches are emitted in the order 4, 0, 3,
 * 1, 2, and per docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * that order is the order the source wrote the case labels in, so it is kept
 * here.  Neither switch has a `default:` that sets the count, and
 * sub_020081DC reads an uninitialised count on an unknown id: the dispatch
 * chain branches past the merged tail rather than into it, which is the
 * reading in docs/idioms/switch-arms-tail-merge.md.
 *
 * Eleven of the twenty-five functions carry no label, all of them because
 * they save no lr.  sub_020081DC is the largest of them, 96 bytes of switch
 * plus table plus pool sitting between two literal pools in the listing.
 *
 * What the range teaches:
 *
 *  - sub_02007DF8, sub_02007E50 and sub_02007F1C pass the address of a local
 *    pointer to sub_02007D6C after having already used that pointer for
 *    something else, and the compiler gives both uses the same stack slot.
 *    Writing them as two variables produces two slots and moves every offset
 *    in the frame, so the source really does reuse the one variable.
 *  - the loop bound in sub_02008058 and its two siblings is assigned after
 *    the induction variable, not before: `for (i = 0, lim = n - 1; ...)`.
 *    Written the other way round the compiler has no zero in hand at the
 *    point it needs one and materialises it from a literal pool, which costs
 *    four bytes of pool the original does not have.
 *  - sub_020080FC compares two calls to func_0202130C.  The first result is
 *    spilled across the second call and the comparison comes out `cmp r1, r0`
 *    with the spilled operand first, which is the same tell
 *    docs/idioms/cmp-operand-order-names-the-temporary.md records; here the
 *    spill is forced by the second call rather than by a named local, so the
 *    two calls can be written inline inside the `||`.
 *  - sub_02007ECC returns `&arr[i]` from a second `return` statement rather
 *    than through a merged local.  sub_02007D94, ten functions earlier, does
 *    use the merged form, and the difference is visible: the merged form
 *    reaches the shared epilogue with an extra `adds r0, rN, #0`.
 */
u32 sub_02007CB0(void)
{
    return 0x9C0;
}


void sub_02007CB8(void *p)
{
    MI_CpuFill8(p, 0, 0x9C0);
}


void sub_02007CC8(u8 *base, void *buf, u32 id, int save)
{
    void *p;
    u32 n;

    sub_02007D00(base, id, &p, &n);
    if (save) {
        MI_CpuCopy8(p, buf, n * 4);
    } else {
        MI_CpuCopy8(buf, p, n * 4);
    }
}


u32 sub_02007D00(u8 *base, u32 id, void **pp, u32 *pn)
{
    switch (id) {
    case 4:
        *pp = base + 0x4D8;
        *pn = 0x53;
        break;
    case 0:
        *pp = base;
        *pn = 0x136;
        break;
    case 3:
        *pp = base + 0x898;
        *pn = 0x40;
        break;
    case 1:
        *pp = base + 0x7D8;
        *pn = 0x30;
        break;
    case 2:
        *pp = base + 0x624;
        *pn = 0x6D;
        break;
    default:
        *pp = NULL;
        break;
    }
    return id;
}


u32 sub_02007D6C(u8 *base, u32 a, void **pp, u32 *pn, u16 d)
{
    u32 id = func_02020FE4((void *)a, 5, d);

    sub_02007D00(base, id, pp, pn);
    return id;
}


struct Item *sub_02007D94(struct Item *arr, u32 n, u16 id, u16 qty, u16 max)
{
    u32 i;
    u32 free = -1;

    for (i = 0; i < n; i++) {
        if (id == arr[i].id) {
            struct Item *e = &arr[i];

            if (qty + e->qty > max) {
                e = NULL;
            }
            return e;
        }
        if (free == -1 && arr[i].id == 0 && arr[i].qty == 0) {
            free = i;
        }
    }
    if (free == -1) {
        return NULL;
    }
    return &arr[free];
}

struct Item *sub_02007DF8(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    if (sub_02007D6C(base, id, &p, &n, d) == 2) {
        return sub_02007D94(p, n, id, qty, 1);
    }
    return sub_02007D94(p, n, id, qty, 999);
}

u32 sub_02007E3C(u8 *base, u16 id, u16 qty, u16 d)
{
    if (sub_02007DF8(base, id, qty, d) != NULL) {
        return 1;
    }
    return 0;
}

u32 sub_02007E50(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;
    void *q;
    u32 m;
    u16 old;
    u32 kind;

    p = sub_02007DF8(base, id, qty, d);
    if (p == NULL) {
        return 0;
    }
    old = ((struct Item *)p)->qty;
    ((struct Item *)p)->id = id;
    ((struct Item *)p)->qty = (u16)(((struct Item *)p)->qty + qty);
    kind = sub_02007D6C(base, id, &p, &n, d);
    if (kind == 3) {
        sub_020080A0(p, n);
    } else if (kind == 2) {
        sub_020080FC(p, n);
    } else if (old == 0) {
        sub_02007D00(base, kind, &q, &m);
        m = sub_02007F7C(q, m);
        sub_02007FF4(q, m);
    }
    return 1;
}

struct Item *sub_02007ECC(struct Item *arr, u32 n, u16 id, u16 qty)
{
    u32 i;

    for (i = 0; i < n; i++) {
        if (id == arr[i].id) {
            if (arr[i].qty < qty) {
                return NULL;
            }
            return &arr[i];
        }
    }
    return NULL;
}

struct Item *sub_02007EF8(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    sub_02007D6C(base, id, &p, &n, d);
    return sub_02007ECC(p, n, id, qty);
}

u32 sub_02007F1C(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    p = sub_02007EF8(base, id, qty, d);
    if (p == NULL) {
        return 0;
    }
    ((struct Item *)p)->qty = (u16)(((struct Item *)p)->qty - qty);
    if (((struct Item *)p)->qty == 0) {
        ((struct Item *)p)->id = 0;
    }
    sub_02007D6C(base, id, &p, &n, d);
    sub_02008058(p, n);
    return 1;
}

u32 sub_02007F68(u8 *base, u16 id, u16 qty, u16 d)
{
    if (sub_02007EF8(base, id, qty, d) != NULL) {
        return 1;
    }
    return 0;
}

u32 sub_02007F7C(const struct Item *arr, u32 n)
{
    u32 c = 0;
    u32 i;

    if (arr != NULL) {
        for (i = 0; i < n; i++) {
            if (arr[i].id != 0) {
                c++;
            }
        }
    }
    return c;
}

u32 sub_02007FA0(u8 *base, u32 id)
{
    void *p;
    u32 n;

    sub_02007D00(base, id, &p, &n);
    return sub_02007F7C(p, n);
}

u32 sub_02007FB8(u8 *base, u16 id, u16 d)
{
    struct Item *e = sub_02007EF8(base, id, 1, d);

    if (e == NULL) {
        return 0;
    }
    return e->qty;
}

void sub_02007FD0(struct Item *a, struct Item *b)
{
    struct Item t;

    t = *a;
    *a = *b;
    *b = t;
}

void sub_02007FF4(struct Item *arr, u32 n)
{
    struct Item t;
    int i;

    t.id = 0;
    if (n <= 1) {
        return;
    }
    for (i = (int)n - 1; i >= 0; i--) {
        if (t.id == 0) {
            MI_CpuCopy8(&arr[i], &t, sizeof(struct Item));
        } else {
            MI_CpuCopy8(&arr[i], &arr[i + 1], sizeof(struct Item));
        }
    }
    MI_CpuCopy8(&t, arr, sizeof(struct Item));
}

void sub_02008038(struct Item *arr, u32 n)
{
    u32 i;

    for (i = 0; i < n; i++) {
        if (arr[i].id == 0) {
            arr[i].qty = 0;
        }
    }
}

void sub_02008058(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    sub_02008038(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0) {
                sub_02007FD0(&arr[i], &arr[j]);
            }
        }
    }
}

void sub_020080A0(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    sub_02008038(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0 ||
                (arr[j].qty != 0 && arr[i].id > arr[j].id)) {
                sub_02007FD0(&arr[i], &arr[j]);
            }
        }
    }
}

void sub_020080FC(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    sub_02008038(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0 ||
                (arr[j].qty != 0 &&
                 func_0202130C(arr[i].id) > func_0202130C(arr[j].id))) {
                sub_02007FD0(&arr[i], &arr[j]);
            }
        }
    }
}

void sub_0200816C(u8 *base)
{
    void *p;
    u32 n;

    sub_02007D00(base, 4, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 0, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 3, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 1, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 2, &p, &n);
    sub_02008058(p, n);
}

struct Item *sub_020081DC(u8 *base, u32 id, u32 index)
{
    u32 n;

    switch (id) {
    case 4:
        base += 0x4D8;
        n = 0x53;
        break;
    case 0:
        n = 0x136;
        break;
    case 3:
        base += 0x898;
        n = 0x40;
        break;
    case 1:
        base += 0x7D8;
        n = 0x30;
        break;
    case 2:
        base += 0x624;
        n = 0x6D;
        break;
    }
    if (index >= n) {
        return NULL;
    }
    return (struct Item *)(base + index * 4);
}

u32 sub_0200823C(u32 a)
{
    if (func_02021288(a) == 1) {
        return 1;
    }
    return 999;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02008298, sub_0200829C, sub_020082B0, sub_020082B4,
 *           sub_020082B8, sub_020082D4
 *
 * "myitem_savedata.c".  sub_02008254 passes 0x020A708C to the debug allocator
 * at 0x02030734 with the line number 0x342, and the bytes at 0x020A708C spell
 * "myitem_savedata.c", so this range is the head of that file.  The string is
 * named by one pool word in the whole image and it is this function's own, so
 * the `literal` class discards its only witness; the `string` class closes it,
 * because "perapvoice.c" ends with its NUL at 0x020A7088 and three bytes of
 * padding put the next string at 0x020A708C by construction.
 *
 * The object the constructor allocates is 0x2C bytes, and the nine accessors
 * after it account for every byte of it bar the two at +0x16: two parallel
 * five element `s16` arrays at +0 and +0xA, a `u16` at +0x14, two parallel
 * four element `s16` arrays at +0x18 and +0x20, and two `u16`s at +0x28 and
 * +0x2A.  Nine of the ten functions carry no label, because only the
 * constructor saves lr.
 *
 * Every one of the four array reads is an `ldrsh` with a register offset,
 * which per docs/idioms/ldrsh-register-offset-is-signedness.md is the only
 * evidence that those elements are signed; the writers use plain `strh` and
 * say nothing.
 *
 * The near miss this range stops short of is 0x020082DC, the six byte tail
 * call that ends the packet:
 *
 *     020082DC  ldr r0, =0x0209DD64
 *     020082DE  ldr r3, =0x020362A4      NHTTP_CleanupAsync
 *     020082E0  bx  r3
 *
 * Both of its pool words are unattestable and the reason is the evidence
 * rather than the C.  0x020362A4 does carry a `func_020362A4` label, but
 * nothing anywhere in the image branches to it, so the `label` class has no
 * call site to point at; the only word in the 3.9 MB image holding the value
 * is the pool word at 0x020082E8, which is inside the range under test, so
 * `literal` discards its only witness.  0x0209DD64 is the same census exactly:
 * one witness image wide, the pool word at 0x020082E4, and it is data with no
 * label it could ever acquire.  Neither is a veneer and neither is a string.
 * Shrinking the range cannot help, because for both sites the sole witness is
 * the pool word of the very function that needs it.  It closes the day
 * anything else in the image names either address.
 */
void *sub_02008254(u32 heap)
{
    return func_02030734(heap, sizeof(struct MyItemSave), 1,
                         sub_02008254_File, 0x342);
}


void sub_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b)
{
    *a = p->unk0A[i];
    *b = p->unk00[i];
}

u16 sub_02008284(const struct MyItemSave *p)
{
    return p->unk14;
}

void sub_02008288(struct MyItemSave *p, int i, s16 a, s16 b)
{
    p->unk0A[i] = a;
    p->unk00[i] = b;
}

void sub_02008298(struct MyItemSave *p, u16 v)
{
    p->unk14 = v;
}

void sub_0200829C(const struct MyItemSave *p, int i, s16 *a, s16 *b)
{
    *a = p->unk20[i];
    *b = p->unk18[i];
}

u16 sub_020082B0(const struct MyItemSave *p)
{
    return p->unk28;
}

u16 sub_020082B4(const struct MyItemSave *p)
{
    return p->unk2A;
}

void sub_020082B8(struct MyItemSave *p, const s16 *a, const s16 *b)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        p->unk20[i] = a[i];
        p->unk18[i] = b[i];
    }
}

void sub_020082D4(struct MyItemSave *p, u16 a, u16 b)
{
    p->unk28 = a;
    p->unk2A = b;
}
