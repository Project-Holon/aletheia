/*
 * file:     time_icon_p04.c
 * unit:     yes
 * function: func_0202EECC, func_0202EF60, func_0202EF98, func_0202F038
 * address:  0x0202EECC
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
 *   func_020056EC   0x020056EC  thumb
 *   func_0204384C   0x0204384C  arm
 *   func_02045730   0x02045730  arm
 *   func_02045758   0x02045758  arm
 *   func_02045738   0x02045738  arm
 *   func_02045760   0x02045760  arm
 *   func_02045740   0x02045740  arm
 *   func_02045778   0x02045778  arm
 *   func_020450F0   0x020450F0  arm
 *   func_02045374   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *   func_02030734  0x02030734  arm
 *   g_020A7814     0x020A7814  data
 *   g_0202F099      0x0202F099  data
 *   func_02030DA8   0x02030DA8  arm
 *   func_020437AC   0x020437AC  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_02045334   0x02045334  arm
 *   func_020452E8   0x020452E8  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_02031194   0x02031194  arm
 */
#include "../../matched/include/Obj03003.h"
#include "../../matched/include/Obj03004.h"
#include "../../matched/include/Obj01809.h"

struct Descriptor;
struct Bmp;
struct Cfg;
struct CharBuf;
struct Node;
struct Obj020437AC;
struct TcblNode;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 unk10;
    u8  pad[0xa];
};

extern u32 func_020056EC(u32 range);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045778(struct Descriptor *p);
extern u32  func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32  func_02030DA8(u32 a, u32 b, u32 c, u32 d);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02030EAC(struct Node *n);
extern void func_02031194(struct TcblNode *n);
void func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4);
struct Obj *func_0202EF60(u32 heap);
void func_0202EF98(u8 *p, u32 a1, u32 a2, u8 a3, u8 a4);
void func_0202F038(u8 *p);
extern const char g_020A7814[];
extern u8 g_0202F099[];



/*
 * Fills in a freshly allocated record: the id, then a surface from the
 * caller's six size queries (width and height are each the sum of two of
 * them minus two, truncated to a byte).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EECC.c \
 *       --func func_0202EECC --addr 0x0202EECC --cc 1.1p1 --thumb
 */
void func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    ((struct Obj03003 *)p)->f10 = a4;
    ((struct Obj03003 *)p)->f13 = 0;
    ((struct Obj03003 *)p)->f12 = a2;
    ((struct Obj03003 *)p)->f14 = a3;
    ((struct Obj03003 *)p)->f15 = func_020056EC(8);
    ((struct Obj03003 *)p)->fC = (u32)func_0204384C(0xC6, 0, 1, ((struct Obj03003 *)p)->f10);

    v0 = func_02045730((struct Descriptor *)((u32)a1));
    v6 = func_02045758(a1);
    v7 = func_02045738(a1);
    v3 = func_02045760(a1);
    v2 = func_02045740(a1);
    v4 = func_02045778(a1);

    func_02045374((struct Cfg *)(((struct Obj03003 *)p)->f8 = func_020450F0(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1)));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj03003 *)p)->f8)));
}



struct Obj *func_0202EF60(u32 heap)
{
    struct Obj *obj = func_02030734(heap, 0x1c, 0, g_020A7814, 0xa6);

    obj->unk10 = (u16)heap;
    obj->unk0C = (u32)func_0204384C(0xc6, 0, 1, obj->unk10);
    obj->unk08 = 0;
    obj->unk00 = 0;
    obj->unk04 = 0;
    return obj;
}



/*
 * func_0202EECC's twin with the record unzeroed: the surface is built the
 * same way, then the caller's handle is attached through func_02030DA8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EF98.c \
 *       --func func_0202EF98 --addr 0x0202EF98 --cc 1.1p1 --thumb
 */
void func_0202EF98(u8 *p, u32 a1, u32 a2, u8 a3, u8 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    ((struct Obj03004 *)p)->f13 = 0;
    ((struct Obj03004 *)p)->f12 = a3;
    ((struct Obj03004 *)p)->f14 = a4;
    ((struct Obj03004 *)p)->f15 = func_020056EC(8);

    v0 = func_02045730((struct Descriptor *)a2);
    v6 = func_02045758((struct Descriptor *)a2);
    v7 = func_02045738((struct Descriptor *)a2);
    v3 = func_02045760((struct Descriptor *)a2);
    v2 = func_02045740((struct Descriptor *)a2);
    v4 = func_02045778((struct Descriptor *)a2);

    func_02045374((struct Cfg *)(((struct Obj03004 *)p)->f8 = func_020450F0(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1)));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj03004 *)p)->f8)));

    ((struct Obj03004 *)p)->f4 = 0;
    ((struct Obj03004 *)p)->f0 = func_02030DA8(a1, (u32)g_0202F099, (u32)p, 0);
    ((struct Obj03004 *)p)->f18 = 1;
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F038.c \
 *       --func func_0202F038 --addr 0x0202F038 --cc 1.1p1 --thumb
 */
void func_0202F038(u8 *p)
{
    if (((struct Obj01809 *)p)->f0 == 0 && ((struct Obj01809 *)p)->f4 == 0) {
        func_020437AC((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));
        func_020307B0(p);
        return;
    }

    ((struct Obj01809 *)p)->f18 = 0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01809 *)p)->f8)), ((struct Obj01809 *)p)->f12);
    func_02045334((struct Descriptor *)((struct Obj01809 *)p)->f8);
    func_020452E8((struct Descriptor *)(((struct Obj01809 *)p)->f8));
    func_020437AC((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));

    if (((struct Obj01809 *)p)->f0 != 0) {
        func_02030EAC((struct Node *)(((struct Obj01809 *)p)->f0));
        func_020307B0(p);
        return;
    }

    if (((struct Obj01809 *)p)->f4 != 0)
        func_02031194((struct TcblNode *)(((struct Obj01809 *)p)->f4));
}
