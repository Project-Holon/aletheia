/*
 * file:     namein_graphic_p17.c
 * unit:     yes
 * function: func_021F3EF0, func_021F3FBC
 * address:  0x021F3EF0
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F164 0x0201F164 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045874 0x02045874 arm
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0204581C 0x0204581C arm
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_021F46B4 0x021F46B4 thumb ov194
 *   func_02082BCC  0x02082BCC  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020276A4  0x020276A4  thumb
 *   func_020276A8  0x020276A8  thumb
 *   func_020276AC  0x020276AC  thumb
 *   func_020276B0  0x020276B0  thumb
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_021F51E4  0x021F51E4  thumb ov194
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_021F5569     0x021F5569  data ov194
 */
#include "../../matched/include/Obj03900.h"
#include "../../matched/include/Obj04591.h"

struct U16Vec;
struct WordSet;
struct CharBuf;
struct Rec3;
struct Descriptor;
struct Bmp;
struct Grid;
struct MsgBank;
struct Obj;
struct Param;
struct Sys;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { u16 w; u16 h; u32 pad; } Dim8;

extern struct WordSet *func_0201EC64(u32 heap);
extern int func_0216C0E4(int *);
extern void func_0216C0D4(int *,int);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204581C(struct U16Vec *vec);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
/* The caller consumes R0 returned by the legacy void forwarding wrapper. */
extern int func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021F46B4(unsigned char *p, int *state);
extern void func_02082BCC(void *p, int v, u32 n);
extern u32  func_020275E4(void);
extern u32  func_020276A4(void);
extern u32  func_020276A8(void);
extern u32  func_020276AC(u32 a);
extern u32  func_020276B0(u32 a);
extern int func_0201BC3C(void);
extern u32  func_0201BABC(u32 a, u32 b, u32 c, u32 d);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32  func_0201BB5C(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *h);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_021F51E4(u8 *dst, unsigned arc, u32 member, u32 index, u16 width, u16 height, int pos, int mode, u16 heap);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(u32 a, void *b, s16 c, u32 d, void *e, u32 f, u32 g);
void func_021F3EF0(char *p,char *q,int *w,u32 heap);
void func_021F3FBC(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap);
extern const u8 d_021F5569[];

void func_021F3EF0(char *p,char *q,int *w,u32 heap)
{
    void *set=func_0201EC64(heap);
    if(func_0216C0E4(w)) func_0201EEF4(set,0,(void *)w[2]);
    else {
        int text=(int)func_02045874((struct U16Vec *)w[8],heap);
        func_0216C0D4(w,text);
        func_0201EE0C(set,0,(void *)text,0,0,0);
        func_02045808((struct U16Vec *)text);
    }
    func_0201F164(set,1,w[4],w[5]);
    if(((struct Obj04591 *)p)->f0) func_0201CE48((struct Rec3 *)(((struct Obj04591 *)p)->f0));
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj03900 *)q)->f14)),((struct Obj03900 *)q)->f20);
    func_0204581C(((struct Obj03900 *)q)->f1C);
    func_0201F250(set,((struct Obj03900 *)q)->f1C,(void *)w[3]);
    ((struct Obj04591 *)p)->f0=func_0201CCE4(((struct Obj03900 *)q)->f14,0,0,*(u32 *)&((struct Obj03900 *)q)->f1C,((struct Obj03900 *)q)->f4,func_02012FFC(),((struct Obj04591 *)p)->f4,2,heap,((struct Obj03900 *)q)->f20);
    ((struct Obj04591 *)p)->fE=0;
    *(void (**)(void))(p+8)=(void (*)(void))func_021F46B4;
    ((struct Obj04591 *)p)->fC=60;
    func_0201ED04(set);
}


void func_021F3FBC(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap)
{
    u32 flagA = 0;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u8 v2c;
    void *h;
    u32 w24 = 0x22;
    u32 h20 = 0x14;
    u32 v1c;
    u32 flagB = 0;

    func_02082BCC(o, 0, 0x3c);
    v2c = 0;
    switch (mode) {
    case 0:
    case 1:
        v40 = func_020275E4();
        v3c = func_020276A4();
        v38 = func_020276A8();
        v34 = func_020276AC(2);
        v30 = func_020276B0(2);
        v1c = a2;
        break;
    case 2:
        v40 = 0x20;
        v3c = flagB;
        v2c = d_021F5569[a2];
        v38 = a2 + 0x31;
        v34 = 0x41;
        v30 = 0x42;
        v1c = (a2 >= 8) ? 1 : flagB;
        break;
    case 3:
        flagA = 1;
        v1c = (a3 & 0xFF00) >> 8;
        if (v1c == 2) {
            flagA = 0;
        }
        v40 = 7;
        v3c = func_0201BC3C();
        v38 = func_0201BABC(a2, (u8)a3, v1c, 0);
        v34 = func_0201BC40();
        v30 = func_0201BCB4();
        w24 = 0x1e;
        h20 = 0x14;
        flagB = 1;
        break;
    case 4:
    case 5:
        v40 = 0x76;
        v3c = 9;
        v38 = 8;
        v34 = 7;
        v30 = 6;
        v2c = 1;
        break;
    }
    h = func_020490F4(v40, heap);
    if (flagB != 0) {
        *(void **)(o + 8) = (void *)func_0204ACEC(h, v3c, 0, 0x40, heap);
    } else {
        *(void **)(o + 8) = (void *)func_0204AC18(h, v3c, 0, 0x40, v2c, 1, heap);
    }
    *(void **)(o + 0x10) = (void *)func_0204AF28(h, v34, v30, heap);
    flagB = 0;
    *(void **)(o + 0xC) = (void *)func_0204A6C8(h, v38, 0, 0, heap);
    func_02049238(h);
    {
        Dim8 dim;
        func_02082BCC(&dim, 0, 8);
        dim.w = w24;
        dim.h = h20;
        *(void **)o = func_0204B294((void *)s0, (u32)(*(void **)(o + 0xC)), (u32)(*(void **)(o + 8)), (u32)(*(void **)(o + 0x10)), &dim, flagB, heap);
    }
    func_0204B92C(*(void **)o, 1);
    switch (mode) {
    case 0:
        if (a2 == 0) {
            func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
        } else {
            func_021F51E4(*(void **)o, 0x31, 9, 3, 4, 4, 0, 0, heap);
        }
        break;
    case 1:
        func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
    case 2:
        func_0204B6F4(*(void **)o, 0, 1);
        break;
    case 3:
        func_0204B878(*(void **)o, 1);
        func_0204B6F4(*(void **)o, func_0201BB5C(a2, (u8)a3, (a3 & 0xFF00) >> 8, flagB), flagB);
        break;
    case 5:
        func_0204B878(*(void **)o, 5);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    case 4:
        func_0204B878(*(void **)o, 2);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    }
    if (flagA != 0) {
        void *h2;
        u32 r;
        u32 idx;
        u8 st[0x18];
        h2 = func_020490F4(0x17, heap);
        *(void **)(o + 0x30) = func_02043678(2, 2, 0x20, heap);
        *(void **)(o + 0x24) = (void *)func_0204ACEC(h2, 5, 0, 0xA0, heap);
        func_02049238(h2);
        func_02082BCC(st, 0, 0x18);
        *(void **)(st + 0) = *(void **)(o + 0x30);
        *(u16 *)(st + 4) = 0x2e;
        *(u16 *)(st + 6) = 0x14;
        *(void **)(st + 8) = *(void **)(o + 0x24);
        *(u8 *)(st + 0x10) = 0;
        *(u16 *)(st + 0x12) = 0;
        *(u32 *)(st + 0x14) = 0;
        *(u8 *)(st + 0x11) = 0;
        *(u32 *)(st + 0xC) = 0;
        *(void **)(o + 0x2C) = func_020255A0((struct Sys *)s4, (const struct Param *)st);
        if (v1c == 1) {
            idx = 0x11;
            r = 0xC80;
        } else {
            idx = 0x10;
            r = 0x14C0;
        }
        *(void **)(o + 0x28) = func_02045EC0(s3, idx);
        func_02043B5C(*(void **)(o + 0x30), 0);
        func_0201C724(s2, *(void **)(o + 0x30), 0, 0, *(void **)(o + 0x28), s1, r);
        *(u32 *)(o + 0x38) = s2;
        *(u32 *)(o + 0x34) = 1;
    }
}
