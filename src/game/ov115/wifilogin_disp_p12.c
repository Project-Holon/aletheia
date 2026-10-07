/*
 * file:     wifilogin_disp_p12.c
 * unit:     yes
 * function: func_021D580C, func_021D584C, func_021D58B4, func_021D5900, func_021D592C, func_021D5938, func_021D5984, func_021D5A88, func_021D5A9C, func_021D5B50, func_021D5B5C, func_021D5C24, func_021D5C30, func_021D5C70, func_021D5C94, func_021D5CCC, func_021D5D3C, func_021D5D5C, func_021D5E34, func_021D5E48, func_021D5E6C
 * address:  0x021D580C
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A600 0x0204A600 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02040618 0x02040618 arm
 *   func_0204A648 0x0204A648 arm
 *   func_0207D63C 0x0207D63C arm
 *   sub_02030734 0x02030734 arm
 *   sub_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   sub_0203101C 0x0203101C arm
 *   sub_0201C440 0x0201C440 thumb
 *   sub_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   sub_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 *   func_0201F5DC 0x0201F5DC thumb
 *   sub_02049B40 0x02049B40 arm
 *   d_021D6628 0x021D6628 data a4
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02028470 0x02028470 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020056BC 0x020056BC thumb
 *   func_0202EE30 0x0202EE30 thumb
 *   func_02028484 0x02028484 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02027778 0x02027778 thumb
 *   func_0207D658 0x0207D658 arm
 *   func_02027CFC 0x02027CFC thumb
 *   func_021D5FE8 0x021D5FE8 thumb ov115
 *   func_02027858 0x02027858 thumb
 *   func_02027974 0x02027974 thumb
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02034714 0x02034714 arm
 *   d_021D663C 0x021D663C data a1
 */
#include "../../matched/include/Obj03765.h"
#include "../../matched/include/Obj02170.h"
#include "../../matched/include/Obj22599.h"
#include "../../matched/include/Obj10333.h"
#include "../../matched/include/Obj22600.h"
#include "../../matched/include/Obj22601.h"
#include "../../matched/include/Obj00531.h"
#include "../../matched/include/Obj13852.h"
#include "../../matched/include/Obj00724.h"
#include "../../matched/include/Obj22602.h"
#include "../../matched/include/Obj04466.h"
#include "../../matched/include/Obj08042.h"
#include "../../matched/include/Obj04467.h"
#include "../../matched/include/Obj04468.h"
#include "../../matched/include/Obj08043.h"
#include "../../matched/include/Obj01535.h"
#include "../../matched/include/Obj05321.h"
#include "../../matched/include/Obj13853.h"
#include "../../matched/include/Obj08044.h"
#include "../../matched/include/Obj10334.h"

struct Bank;
struct Node;
struct Obj;
struct Tcbl;
struct U16Vec;
struct GfFont;
struct MsgBank;
struct WordSet;
struct R;
struct PrintSys;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct CharBuf;
struct Cfg;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef short s16;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef int s32;

typedef struct Blk {u8 first,pad[3]; u32 flags;} Blk;

typedef struct {
    u32 heap;
    u8 count, pad[3];
    const void *items;
    u32 param;
    u8 x, y, a, b;
} Template;

enum Kind { K0,K1 };

extern void func_0204A600(void);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A648(void);
extern void func_0207D63C(void *, int, int, int, int);
extern void *sub_02030734(u32,u32,int,const char *,u16);
extern void sub_02045088(u16);
extern void func_0201DD60(void);
extern struct Tcbl *sub_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 sub_0201C440(void *);
extern struct U16Vec *sub_020457B0(u32,u32);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32);
extern struct R *func_02027F60(u16,u16,u32,u32,u16);
extern u32 func_021D5FA0(u32);
extern u32 func_021D5FC4(u32);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void sub_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_0201DD68(void);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern u32 func_020307B0(void *p);
extern void func_02045CAC(struct MsgBank *, u32, void *);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_0201DD78(u32, u32, u32);
extern void func_02028470(u8 *p, u32 v);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_02041B6C(u32);
extern unsigned int func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern int func_02028484(Blk *,void *);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_0207D658(u32, int, int);
extern void func_02027CFC(u8 *, int);
extern void *func_021D5FE8(u8 *, int, int);
extern void func_02027858(struct TaskMenu *);
extern void func_02027974(struct Obj *);
extern u32 func_0201FEBC(u8 *);
extern u32 func_020279E8(struct TaskMenu *m);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021D580C(u8 *p);
void func_021D584C(u8 *p);
void func_021D58B4(void *unused, u8 *p);
void func_021D5900(void *task,u8 *p);
void func_021D592C(u8 *p);
void func_021D5938(u8 *p);
u8 *func_021D5984(u32 heap, u32 bank, u32 mode);
void func_021D5A88(u8 *p);
void func_021D5A9C(u8 *p);
void func_021D5B50(void *p, int b);
void func_021D5B5C(char *p, struct MsgBank *a, int b);
void func_021D5C24(void *p, int b);
void func_021D5C30(u8 *p, unsigned int a, int b);
int func_021D5C70(u8 *p);
void func_021D5C94(u8 *p);
void func_021D5CCC(u8 *p, u32 n);
void func_021D5D3C(u8 *p);
void *func_021D5D5C(u8 *p, int mode, int flag, int selected);
void func_021D5E34(u8 *p);
void func_021D5E48(u8 *p);
int func_021D5E6C(u8 *p);
extern const char d_021D6628[];
extern const char d_021D663C[];

void func_021D580C(u8 *p) {
    ++((struct Obj03765 *)p)->f9C8;
    if (((struct Obj03765 *)p)->f9C8 >= 192) ((struct Obj03765 *)p)->f9C8 = 0;
    if (((struct Obj03765 *)p)->fB4A) {
        ++((struct Obj03765 *)p)->fB4A;
        if (((struct Obj03765 *)p)->fB4A >= 257) ((struct Obj03765 *)p)->fB4A = 1;
    }
    func_0204A600();
}

void func_021D584C(u8 *p) {
    int i;
    for (i = 0; i < 5; ++i) {
        if (*(u32 *)(p + i * 4 + 0x99c)) {
            func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4 + 0x99c)));
            *(u32 *)(p + i * 4 + 0x99c) = 0;
        }
    }
    func_0204ADA4(((struct Obj02170 *)p)->f98C);
    func_0204A8D4(((struct Obj02170 *)p)->f990);
    func_0204AFD8(((struct Obj02170 *)p)->f994);
    if (((struct Obj02170 *)p)->f988) func_02030EAC((struct Node *)(((struct Obj02170 *)p)->f988));
    func_02030EAC((struct Node *)(((struct Obj02170 *)p)->f984));
    func_0204B1CC((struct Bank *)(((struct Obj02170 *)p)->f980));
    func_0204A5AC();
}

/*
 * lever: bind the hardware scanline before adding the signed counter;
 *        the nested expression moves the first four loads/adds.
 * volatile: hardware reads at 021D58BE, 021D58CC and writes 021D58E2, 021D58EA.
 */
void func_021D58B4(void *unused, u8 *p) {
    int i;
    i = *(volatile u16 *)0x04000006;
    i = (i + (((struct Obj22599 *)p)->f9C8 + 1)) % 192;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x04000014 = *(s16 *)(p + 0x9ca + i * 2) & 511;
        *(volatile u32 *)0x04001018 = *(s16 *)(p + 0x9ca + i * 2) & 511;
    }
}

void func_021D5900(void *task,u8 *p) { if(((struct Obj10333 *)p)->fB4A>0) { func_02040618(7,0,((struct Obj10333 *)p)->fB4A-1); func_02040618(2,0,((struct Obj10333 *)p)->fB4A-1); } func_0204A648(); }


void func_021D592C(u8 *p) { ((struct Obj22600 *)p)->f9C4 = 1; }

void func_021D5938(u8 *p) {
    switch (((struct Obj22601 *)p)->f8) {
    case 1:
        func_0207D63C((void *)0x04000050, 4, 3, 6, 16);
        func_0207D63C((void *)0x04001050, 8, 21, 6, 16);
        break;
    case 0:
        func_0207D63C((void *)0x04000050, 1, 8, 8, 16);
        break;
    }
}


/*
 * ABI: DD60 and its forwarding chain ignore the live r0 from45088;
 *   45B38 explicitly truncates its third argument to16 at this call.
 */
u8 *func_021D5984(u32 heap, u32 bank, u32 mode)
{
    u8 *p;
    u32 sel;
    p = sub_02030734(heap, 132, 1, d_021D6628, 135);
    ((struct Obj00531 *)p)->f4C = heap;
    ((struct Obj00531 *)p)->f50 = mode;
    sub_02045088(((struct Obj00531 *)p)->f4C);
    func_0201DD60();
    *(struct Tcbl * *)&((struct Obj00531 *)p)->f44 = sub_0203101C(((struct Obj00531 *)p)->f4C, ((struct Obj00531 *)p)->f4C, 1, 0);
    ((struct Obj00531 *)p)->f48 = sub_0201C440((void *)((struct Obj00531 *)p)->f4C);
    *(struct U16Vec * *)&((struct Obj00531 *)p)->f28 = sub_020457B0(400, ((struct Obj00531 *)p)->f4C);
    *(struct GfFont * *)&((struct Obj00531 *)p)->f24 = func_0201D7EC(23, 0, 0, 0, ((struct Obj00531 *)p)->f4C);
    *(struct MsgBank * *)&((struct Obj00531 *)p)->f1C = sub_02045B38(0, 2, (u16)bank, ((struct Obj00531 *)p)->f4C);
    *(struct WordSet * *)&((struct Obj00531 *)p)->f20 = func_0201EC64(((struct Obj00531 *)p)->f4C);
    *(struct R * *)&((struct Obj00531 *)p)->f70 = func_02027F60(5, 9, *(u32 *)&((struct Obj00531 *)p)->f24, ((struct Obj00531 *)p)->f48, ((struct Obj00531 *)p)->f4C);
    ((struct Obj00531 *)p)->f0 = func_0201F5DC((void *)func_021D5FA0(((struct Obj00531 *)p)->f50), 12, 0, ((struct Obj00531 *)p)->f4C);
    ((struct Obj00531 *)p)->f4 = func_0201F5DC((void *)func_021D5FC4(((struct Obj00531 *)p)->f50), 12, 0, ((struct Obj00531 *)p)->f4C);
    sel = 0;
    if (((struct Obj00531 *)p)->f50 == 0) sel = 4;
    sub_02049B40(23, 5, sel, 352, 32, ((struct Obj00531 *)p)->f4C);
    return p;
}

/*
 * trailing: two-byte alignment padding, no follower.
 */
void func_021D5A88(u8 *p) { func_020310C4(((struct Obj13852 *)p)->f44); func_0201C4E4(*(struct PrintSys * *)&((struct Obj13852 *)p)->f48); }

void func_021D5A9C(u8 *p) {
    u32 n;
    if (((struct Obj00724 *)p)->f80) { func_0202F038(((struct Obj00724 *)p)->f80); ((struct Obj00724 *)p)->f80=0; }
    if (((struct Obj00724 *)p)->f38) { func_0201CE48(((struct Obj00724 *)p)->f38); ((struct Obj00724 *)p)->f38=0; }
    func_021D5D3C(p);
    n=((struct Obj00724 *)p)->f0;
    func_0203FB44(func_021D5FA0(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    n=((struct Obj00724 *)p)->f4;
    func_0203FB44(func_021D5FC4(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    func_0201DD68();
    func_0201ED04(((struct Obj00724 *)p)->f20);
    func_02045C04(((struct Obj00724 *)p)->f1C);
    func_0201D83C(((struct Obj00724 *)p)->f24);
    func_02045808(((struct Obj00724 *)p)->f28);
    func_02027FD8(((struct Obj00724 *)p)->f70);
    func_02031140(((struct Obj00724 *)p)->f44);
    func_0201C6EC(((struct Obj00724 *)p)->f48);
    func_0201C4C0(((struct Obj00724 *)p)->f48);
    if (((struct Obj00724 *)p)->f2C) { func_020452E8(((struct Obj00724 *)p)->f2C); ((struct Obj00724 *)p)->f2C=0; }
    if (((struct Obj00724 *)p)->f30) { func_020452E8(((struct Obj00724 *)p)->f30); ((struct Obj00724 *)p)->f30=0; }
    func_020450C8();
    func_020307B0(p);
}

void func_021D5B50(void *p, int b) { func_021D5B5C(p, (struct MsgBank *)(((struct Obj22602 *)p)->f1C), b); }

/*
 * note 2026-10-05 (wD9r lane A6): first read of the field at +0x50 is an int read, later reads u32; the same-type form gets CSE'd and loads r1 for +0x2c. Row set after the first call.
 */
void func_021D5B5C(char *p, struct MsgBank *a, int b)
{
    int row;
    int kind;
    u32 w;
    func_02045CAC(a, b, *(void **)(p + 0x28));
    row = 1;
    if (*(int *)(p + 0x50) != 0) row = 19;
    if (*(u32 *)(p + 0x2c) == 0) {
        *(u32 *)(p + 0x2c) = func_020450F0(func_021D5FA0(*(u32 *)(p + 0x50)), 1, row, 30, 4, 11, 1);
    }
    w = *(u32 *)(p + 0x2c);
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)w), 15);
    func_0201DD78(1, 2, 15);
    kind = 2;
    if (*(u32 *)(p + 0x50) == 0) kind = 6;
    func_02028470((u8 *)(p + 0x3c), (int)kind);
    if (*(u32 *)(p + 0x38) != 0) func_0201CE48(*(struct Rec3 **)(p + 0x38));
    *(u32 *)(p + 0x38) = func_0201CCE4(w, 0, 0, *(u32 *)(p + 0x28), *(u32 *)(p + 0x24), func_02012FFC(), *(u32 *)(p + 0x44), 2, *(u16 *)(p + 0x4c), 15);
    func_0201F73C((void *)w, 1, (u16)(*(u32 *)p), 12);
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(func_021D5FA0(*(u32 *)(p + 0x50)));
}

void func_021D5C24(void *p, int b) { func_021D5C30(p, ((struct Obj04466 *)p)->f1C, b); }

void func_021D5C30(u8 *p, unsigned int a, int b) {
    func_021D5B5C((char *)p, (struct MsgBank *)a, b);
    if (((struct Obj04466 *)p)->f80) {
        func_0202F038(((struct Obj04466 *)p)->f80);
        ((struct Obj04466 *)p)->f80 = 0;
    }
    ((struct Obj04466 *)p)->f80 = func_0202EE30((void *)func_020056BC(), ((struct Obj04466 *)p)->f2C, 15, 16, ((struct Obj04466 *)p)->f4C);
}

int func_021D5C70(u8 *p) { int result=1; if(((struct Obj08042 *)p)->f38) { result=func_02028484((Blk *)(p+60),((struct Obj08042 *)p)->f38); if(result) { func_0201CE48(((struct Obj08042 *)p)->f38); ((struct Obj08042 *)p)->f38=0; } } return result; }

void func_021D5C94(u8 *p) { if(*(u8 * *)&((struct Obj04467 *)p)->f80) { func_0202F038(*(u8 * *)&((struct Obj04467 *)p)->f80); *(u8 * *)&((struct Obj04467 *)p)->f80=0; } if(((struct Obj04467 *)p)->f2C) { func_0201F7A8(((struct Obj04467 *)p)->f2C,2); func_020456F8(((struct Obj04467 *)p)->f2C); func_02041B6C(func_021D5FA0(((struct Obj04467 *)p)->f50)); } }

void func_021D5CCC(u8 *p, u32 n) {
    void *w;
    if (((struct Obj04468 *)p)->f34==0) ((struct Obj04468 *)p)->f34=(void *)func_020450F0(1,4,7,24,2,11,1);
    w=((struct Obj04468 *)p)->f34;
    func_02043B5C(func_02045770(w),0);
    func_02045CAC(((struct Obj04468 *)p)->f1C,n,((struct Obj04468 *)p)->f28);
    func_0201C7D0(func_02045770(w),0,0,((struct Obj04468 *)p)->f28,((struct Obj04468 *)p)->f24,0x3cc0);
    func_02045334(w);
    func_02045374(w);
    func_02041B6C(1);
}

void func_021D5D3C(u8 *p) { if(((struct Obj08043 *)p)->f34) { func_020456F8(((struct Obj08043 *)p)->f34); func_020452E8(((struct Obj08043 *)p)->f34); ((struct Obj08043 *)p)->f34=0; func_02041B6C(1); } }

/*
 * evidence: 5FE8 forwards the pointer returned by matched 0201FDA0;
 * this caller consumes that return. All six observed ov115 caller sites
 * (45F8,4630,46F4,47AE,488E,4926) set mode to literal0/1, so meaningful
 * Template fields are initialized on reachable case0. Complete original
 * contexts/reference search: B10/5D5C-interface-proof.txt; body unchanged.
 */
void *func_021D5D5C(u8 *p, int mode, int flag, int selected)
{
    u8 *q = p + 0x54;
    Template t;
    ((struct Obj01535 *)q)->f0 = ((struct Obj05321 *)p)->f50;
    switch (((struct Obj01535 *)q)->f0) {
    case 0:
        t.heap = ((struct Obj05321 *)p)->f4C;
        t.count = 2;
        t.items = q + 4;
        switch (mode) {
        case 0: t.x = 32; t.y = 13; t.param = 1; break;
        case 1: t.x = 32; t.y = 24; t.param = 1; break;
        }
        t.a = 13;
        t.b = 3;
        ((struct Obj01535 *)q)->f4 = func_020457B0(100, ((struct Obj05321 *)p)->f4C);
        func_02045CAC(((struct Obj05321 *)p)->f1C, 28, ((struct Obj01535 *)q)->f4);
        ((struct Obj01535 *)q)->f8 = 0x39e0;
        ((struct Obj01535 *)q)->f10 = func_020457B0(100, ((struct Obj05321 *)p)->f4C);
        func_02045CAC(((struct Obj05321 *)p)->f1C, 29, ((struct Obj01535 *)q)->f10);
        ((struct Obj01535 *)q)->f14 = 0x39e0;
        ((struct Obj01535 *)q)->f20 = func_02027778((struct TaskMenuTmpl *)(&t), ((struct Obj01535 *)q)->f1C);
        func_02045808(((struct Obj01535 *)q)->f4);
        func_02045808(((struct Obj01535 *)q)->f10);
        if (flag != 0) func_0207D658(0x04001050, 17, -8);
        func_02027CFC(*(u8 * *)&((struct Obj01535 *)q)->f20, selected);
        break;
    case 1:
        ((struct Obj01535 *)q)->f24 = func_021D5FE8(p, mode, selected);
        ((struct Obj01535 *)q)->f28 = -1;
        break;
    }
    return q;
}

void func_021D5E34(u8 *p) { switch(((struct Obj13853 *)p)->f0) { case K0: func_02027858(*(struct TaskMenu * *)&((struct Obj13853 *)p)->f20); break; case K1: break; } }

void func_021D5E48(u8 *p) { switch(((struct Obj08044 *)p)->f0) { case 0: func_02027974(*(struct Obj * *)&((struct Obj08044 *)p)->f20); break; case 1: ((struct Obj08044 *)p)->f28=func_0201FEBC(*(u8 * *)&((struct Obj08044 *)p)->f24); break; } }

int func_021D5E6C(u8 *p) { switch(((struct Obj10334 *)p)->f0) { case 0: return func_020279E8(((struct Obj10334 *)p)->f20); case 1: if(((struct Obj10334 *)p)->f28!=-1) return 1; else return 0; default: func_02034714(d_021D663C,0,d_021D663C); return 0; } }
