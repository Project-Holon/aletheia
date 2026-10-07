/*
 * file:     worldtrade_adapter_p05.c
 * unit:     yes
 * function: func_021FC2C0, func_021FC360, func_021FC3D0, func_021FC3E0, func_021FC4E4, func_021FC528, func_021FC568, func_021FC5A0, func_021FC610
 * address:  0x021FC2C0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02200BAC 0x02200BAC thumb ov135
 *   tbl_0220351C 0x0220351C data a4
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0200ADB4 0x0200ADB4 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021FC810 0x021FC810 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj03298.h"
#include "../../matched/include/Obj18568.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj10585.h"
#include "../../matched/include/Obj14170.h"
#include "../../matched/include/Obj23406.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj18569.h"

struct Obj;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;

typedef struct {u32 x,y,w,h;} WinDef;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[12];
    u32 side;
    u8 padD54[0x3C];
    u32 item[14];
} Menu;

typedef signed int s32;

typedef signed short s16;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_02200B34(u8 *p);
extern void func_02082BCC(void *, int, int);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B84C(void *, int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_02200BAC(u8 *p, u32 k);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *);
extern void *func_0200ADB4(void *);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_020061E4(unsigned);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void func_021FC2C0(void *p);
void func_021FC360(char *p);
void func_021FC3D0(u8 *p);
void func_021FC3E0(Menu *p);
void func_021FC4E4(char *p);
void func_021FC528(char *p);
void func_021FC568(char *p);
int func_021FC598(char *p);
int func_021FC5A0(char *p);
int func_021FC610(u8 *p, int a1);
extern const WinDef tbl_0220351C[];

void func_021FC2C0(void *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 6, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(2, 1, 0xe, 0, 0x48);
    func_0201F5BC(2, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0x10, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x16, 1, 0, 0x600, 1, 0x48);
    func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    func_02200B34(p);
    func_02049238(h);
}

void func_021FC360(char *p)
{
    ObjPos pos;
    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = 0xd0;
    pos.y = 0x3a;
    ((struct Obj03298 *)p)->fD08 = func_0204B294(((struct Obj03298 *)p)->fBC0, (unsigned int)((struct Obj03298 *)p)->fBC4, (unsigned int)((struct Obj03298 *)p)->fBC8, (unsigned int)((struct Obj03298 *)p)->fBCC, &pos, 0, 0x48);
    func_0204B92C(((struct Obj03298 *)p)->fD08, 1);
    func_0204B878(((struct Obj03298 *)p)->fD08, 0x24);
    func_0204B84C(((struct Obj03298 *)p)->fD08, 1);
    func_0204B3DC(((struct Obj03298 *)p)->fD08, 1);
    func_0203D34C(0, 0x48);
}


/*
 * Tail call into func_0204B3B4 with the pointer held at +0xd08.
 */
void func_021FC3D0(u8 *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18568 *)p)->fD08));
}

void func_021FC3E0(Menu *p)
{
    int i;
    u32 w;
    p->frame=func_020450F0(2,(u8)2,(u8)21,(u8)27,2,13,(u16)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->frame)),0);
    w=p->frame;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    p->side=func_020450F0(2,(u8)21,(u8)15,(u8)10,4,13,(u16)1);
    w=p->side;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    for(i=0;i<14;i++) {
        p->item[i]=func_020450F0(3,(u8)tbl_0220351C[i].x,(u8)tbl_0220351C[i].y,(u8)tbl_0220351C[i].w,tbl_0220351C[i].h,13,(u16)1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->item[i])),0);
        w=p->item[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    func_02200BAC((u8 *)p,2);
}

/*
 * tail: 021FC526..021FC528 is two zero alignment bytes.
 */
void func_021FC4E4(char *p)
{
    int i;
    func_02202940((struct Obj *)(p + 0xfa0));
    func_020452E8(((struct Obj00287 *)p)->fDE0);
    func_020452E8(((struct Obj00287 *)p)->fD40);
    func_020452E8(((struct Obj00287 *)p)->fD50);
    for (i = 0; i < 14; i++) {
        func_020452E8(*(void **)(p + i * 4 + 0xd90));
    }
}

void func_021FC528(char *p)
{
    int i;
    ((struct Obj10585 *)p)->fB88 = func_020457B0(0xb4, 0x48);
    ((struct Obj10585 *)p)->fB8C = func_02045EC0(((struct Obj10585 *)p)->fB6C, 0x2d);
    for (i = 0; i < 10; i++) {
        *(void **)(p + i * 4 + 0xb90) = func_020457B0(0x14, 0x48);
    }
}

void func_021FC568(char *p) {int i;for(i=0;i<10;i++) func_02045808(*(struct U16Vec **)((unsigned)p+i*4+0xb90));func_02045808(*(struct U16Vec * *)&((struct Obj14170 *)p)->fB88);func_02045808(*(struct U16Vec * *)&((struct Obj14170 *)p)->fB8C);}

int func_021FC598(char *p) {((struct Obj23406 *)p)->f28=1;return 2;}

int func_021FC5A0(char *p)
{
    void *q;
    q = func_0200ADB4(**(void ** *)&((struct Obj00018 *)p)->f0);
    if ((func_020362DC() & 1) || func_02035C60()) {
        func_021FC810((u8 *)p, 5, 1, 0, 0xf0f, q);
        func_021F4E98((u8 *)p, 3, 7);
        func_020061E4(0x54c);
    } else if (func_020362DC() & 2) {
        *(int *)&((struct Obj00018 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        func_020061E4(0x551);
    }
    return 2;
}


int func_021FC610(u8 *p, int a1)
{
    func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj18569 *)p)->f28 = 0;
    return 3;
}
