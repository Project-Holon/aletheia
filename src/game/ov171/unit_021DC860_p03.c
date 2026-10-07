/*
 * file:     unit_021DC860_p03.c
 * unit:     yes
 * function: func_021DE114, func_021DE144, func_021DE1F8, func_021DE218, func_021DE238, func_021DE258, func_021DE290, func_021DE2D4, func_021DE34C
 * address:  0x021DE114
 * region:   ov171
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DEB88 0x021DEB88 data a4
 *   func_021DC924 0x021DC924 thumb ov171
 *   func_0204A48C 0x0204A48C arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B100 0x0204B100 arm
 *   func_021DE064 0x021DE064 thumb ov171
 *   d_021DEBA4 0x021DEBA4 data a4
 *   func_0204B3B4  0x0204B3B4  arm
 */
#include "../../matched/include/Obj01756.h"
#include "../../matched/include/Obj08251.h"
#include "../../matched/include/Obj24058.h"

struct Obj;
struct Bank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Cfg {u8 pad_00[8];u8 unk_08,unk_09,unk_0a,unk_0b;u32 unk_0c;u16 unk_10,unk_12,unk_14,unk_16,unk_18,unk_1a;};

typedef signed int     s32;

extern void *func_021DC924(void);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern u32 func_020275E4(void);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(u8 *);
extern void func_0204A8D4(u32 v);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021DE064(int *, int, int);
extern void func_0204B3B4(struct Obj *p);
void func_021DE114(u8 *p);
void func_021DE144(char *p);
void func_021DE1F8(char *p, int i);
void func_021DE218(char *p,int i);
void func_021DE238(char *p,int i);
void func_021DE258(char *p);
struct Obj *func_021DE290(char *p, const char *q);
void func_021DE2D4(char *p);
void func_021DE34C(char *p, int i);
extern const struct Cfg d_021DEB88;
extern const char d_021DEBA4[];

void func_021DE114(u8 *p)
{
    struct Cfg cfg=d_021DEB88;
    func_0204A48C(&cfg,(u32)func_021DC924(),140);
}

void func_021DE144(char *p)
{
    unsigned i;
    u8 *s;
    int a;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbb4 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbe8 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xc1c + i * 4) = -1;
    s = func_020490F4(func_020275E4(), 0x808c);
    ((struct Obj01756 *)p)->fBE4 = func_0204A6C8(s, func_02027618(), 0, 0, 0x8c);
    *(int *)&((struct Obj01756 *)p)->fC18 = func_0204ABF0(s, func_02027614(), 0, 0x180, 0x8c);
    a = func_0202761C(2);
    ((struct Obj01756 *)p)->fC4C = func_0204AF28(s, a, func_02027620(2), 0x8c);
    func_02049238(s);
}


void func_021DE1F8(char *p, int i)
{
    if (*(u32 *)(p + 0xbb4 + i * 4) != 0xffffffffu) {
        func_0204A8D4(*(u32 *)(p + 0xbb4 + i * 4));
        *(u32 *)(p + 0xbb4 + i * 4) = 0xffffffffu;
    }
}

void func_021DE218(char *p,int i)
{
    if(*(u32 *)((u32)p+0xbe8+(u32)i*4)!=(u32)-1) {
        func_0204ADA4(*(u32 *)((u32)p+0xbe8+(u32)i*4));
        *(u32 *)((u32)p+0xbe8+(u32)i*4)=(u32)-1;
    }
}

void func_021DE238(char *p,int i)
{
    if(*(u32 *)((u32)p+0xc1c+(u32)i*4)!=(u32)-1) {
        func_0204AFD8(*(u32 *)((u32)p+0xc1c+(u32)i*4));
        *(u32 *)((u32)p+0xc1c+(u32)i*4)=(u32)-1;
    }
}

void func_021DE258(char *p)
{
    unsigned i;
    for(i=0;i<13;i++)func_021DE1F8(p,i);
    for(i=0;i<13;i++)func_021DE218(p,i);
    for(i=0;i<13;i++)func_021DE238(p,i);
}

/*
 * trailing: two zero alignment bytes at 0x021DE2D2.
 */
struct Obj *func_021DE290(char *p, const char *q)
{
    return func_0204B294((void *)((struct Obj24058 *)p)->fB70, *(int *)(p + 0xbb4 + ((struct Obj08251 *)q)->f8 * 4),
        *(int *)(p + 0xbe8 + ((struct Obj08251 *)q)->fC * 4), *(int *)(p + 0xc1c + ((struct Obj08251 *)q)->f10 * 4),
        q, ((struct Obj08251 *)q)->f16, 0x8c);
}

/*
 * lever: group the integer table offset before adding its symbol base.
 */
void func_021DE2D4(char *p)
{
    unsigned i;
    *(int *)&((struct Obj01756 *)p)->fB70 = (int)func_0204B100(31, 0, 0x8c);
    for (i = 0; i < 16; ++i)
        *(int *)(p + 0xb74 + i * 4) = 0;
    for (i = 12; i <= 15; ++i)
        *(int *)(p + 0xb74 + i * 4) = (int)func_021DE290(p, d_021DEBA4 + (i * 24 - 0x120));
    if (((struct Obj01756 *)p)->fC5F == 1) {
        func_021DE064((int *)p, 12, 0);
        func_021DE064((int *)p, 13, 0);
    }
}


void func_021DE34C(char *p, int i)
{
    if (*(int *)(p + 0xb74 + i * 4) != 0) {
        func_0204B3B4((struct Obj *)(*(int *)(p + 0xb74 + i * 4)));
        *(int *)(p + 0xb74 + i * 4) = 0;
    }
}
