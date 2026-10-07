/*
 * file:     unit_021D4240_p02.c
 * unit:     yes
 * function: func_021D4630, func_021D4644, func_021D46CC, func_021D48D8, func_021D4A64, func_021D4AD4, func_021D4B30, func_021D4B74, func_021D4BDC, func_021D4BF0
 * address:  0x021D4630
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021D5708 0x021D5708 data a1
 *   data_021D5704 0x021D5704 data a1
 *   data_021D570C 0x021D570C data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   data_021D5870 0x021D5870 data a2
 *   d_021D575C 0x021D575C data a4
 *   d_021D5890 0x021D5890 data a4
 *   d_021D5720 0x021D5720 data a4
 *   d_021D5718 0x021D5718 data a4
 *   d_021D5728 0x021D5728 data a4
 *   func_021D4C50 0x021D4C50 thumb ov122
 *   func_021D4FE4 0x021D4FE4 thumb ov122
 *   func_021D4384 0x021D4384 thumb ov122
 *   func_021D5004 0x021D5004 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 *   func_02051B84 0x02051B84 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D45E8 0x021D45E8 thumb ov122
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02178118 0x02178118 thumb ov014
 */
#include "../../matched/include/Obj00073.h"
#include "../../matched/include/Obj13963.h"
#include "../../matched/include/Obj10431.h"
#include "../../matched/include/Obj02472.h"
#include "../../matched/include/Obj13964.h"
#include "../../matched/include/Obj06457.h"

struct Obj;
struct Actor;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct Rec;
struct Ctx;
struct Comm;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int (*Fn)(int,u32 *);

typedef struct { u8 v[3]; } Triple;

typedef struct { u16 f00, f02, f04; u8 f06, f07; } Request;

typedef signed int     s32;

typedef struct Pair { int a, b; } Pair;

extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern int func_021D4C50(int value, char *p);
extern void func_021D4FE4(char *p);
extern void func_021D4384(int, Pair *, void *, void *, void *, void *);
extern void func_021D5004(char *p);
extern void func_021D4244(void *p, u32 a, int a2);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_0201DD68(void);
extern void func_021D45E8(char *);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020452E8(struct Descriptor *d);
extern unsigned int func_020221A4(void);
extern unsigned int func_02012138(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_02178118(u32 callback, u32 value);
extern void func_02026400(struct Comm *p);
void func_021D4630(int a,int b,u32 *p);
void func_021D4644(u16 *p, const u16 *add, int count);
void func_021D46CC(char *p);
void func_021D48D8(char *p);
void func_021D4A64(char *p);
void func_021D4AD4(char *p);
void func_021D4B30(char *p);
void func_021D4B74(char *p);
void func_021D4BDC(char *p);
void func_021D4BF0(void);
extern const Triple data_021D5708, data_021D5704, data_021D570C;
extern u16 data_021D5870[];
extern const Pair d_021D575C;
extern int d_021D5890[], d_021D5720[], d_021D5718[], d_021D5728[];

void func_021D4630(int a,int b,u32 *p) {if(b==0 && p[1]!=0) {if(((Fn)p[1])(a,p)==0)return;}}

void func_021D4644(u16 *p, const u16 *add, int count)
{
    int i, j;
    for (i = 0; i < count; i++) {
        u16 *q = p + i * 16;
        for (j = 0; j < 16; j++) {
            u16 color = q[j];
            u16 r = color & 31;
            u16 g = (color & 0x3e0) >> 5;
            u16 b = (color & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            q[j] = r + (g << 5) + (b << 10);
        }
    }
}

void func_021D46CC(char *p)
{
    Triple x = data_021D5708;
    Triple y = data_021D5704;
    Triple z = data_021D570C;
    Request req;
    int i, a, b, c, d, e, f, g;
    i = 0;
    a = 0x37c;
    b = 0x378;
    c = 0x380;
    d = 0x390;
    e = 0x390;
    f = 0x390;
    g = 0x390;
    for (; i < 3; i++) {
        char *q;
        req.f00 = x.v[i]; req.f02 = y.v[i]; req.f04 = z.v[i];
        req.f06 = 1; req.f07 = 2;
        q = p + 4 * i;
        *(void **)(q + d) = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, *(u32 *)(p + a), *(u32 *)(p + b), *(u32 *)(p + c), &req, 1, ((struct Obj00073 *)p)->fC);
        func_0204B92C(*(void **)(q + e), 0);
        func_0204B3DC(*(void **)(q + f), 1);
        func_0204B688(*(void **)(q + g), 1);
    }
    req.f00 = 128; req.f02 = 96; req.f04 = 15; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f39C = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f39C, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f39C, 1);
    func_0204B688(((struct Obj00073 *)p)->f39C, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 18; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A0 = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f3A0, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f3A0, 0);
    func_0204B688(((struct Obj00073 *)p)->f3A0, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 25; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A4 = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f3A4, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f3A4, 0);
    func_0204B688(((struct Obj00073 *)p)->f3A4, 1);
}

/*
 * ABI: 02049990 argument 5 is u16: original truncates the value at 021D49B4/49D2.
 */
void func_021D48D8(char *p)
{
    u32 arc;
    void *resource;
    char *palette;
    ((struct Obj00073 *)p)->f54 = func_020457B0(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f58 = func_020457B0(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f50 = func_020457B0(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f3C = (void *)func_020450F0(5, 16, 10, 10, 2, 13, 0);
    ((struct Obj00073 *)p)->f4C = func_0201D7EC(23, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f44 = func_02045B38(0, 2, 23, ((struct Obj00073 *)p)->fC);
    arc = (u32)func_020490F4(29, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 0, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 1, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    resource = func_02049F78((void *)arc, 1, (u32)&palette, ((struct Obj00073 *)p)->fC);
    func_02082D44(((struct Obj13963 *)palette)->fC, p + 0x12c, 0xe0);
    func_02082D44(((struct Obj13963 *)palette)->fC, p + 0x20c, 0xe0);
    func_021D4644((u16 *)(p + 0x20c), data_021D5870, 7);
    func_020307B0(resource);
    ((struct Obj00073 *)p)->f60 = func_02049740((void *)arc, 4, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049990((void *)arc, 9, 4, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049990((void *)arc, 15, 6, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f37C = func_0204A6C8((void *)arc, 5, 0, 1, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f378 = func_0204AC18((void *)arc, 3, 1, 0, 0, 10, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f380 = func_0204AF28((void *)arc, 7, 16, ((struct Obj00073 *)p)->fC);
    func_02049238(arc);
    ((struct Obj00073 *)p)->f5C = func_0201F5DC((void *)5, 11, 0, ((struct Obj00073 *)p)->fC);
    func_02049B40(23, 5, 4, 384, 32, ((struct Obj00073 *)p)->fC);
    func_021D46CC(p);
}

void func_021D4A64(char *p)
{
    Pair pair = d_021D575C;
    func_021D4384(2, &pair, p, d_021D5890, d_021D5720, d_021D5718);
    ((struct Obj10431 *)p)->f40 = func_02051B84((u8 *)d_021D5728, (int)func_021D4630, (int)p, ((struct Obj10431 *)p)->fC);
    ((struct Obj10431 *)p)->f4 = func_021D4C50;
    func_021D5004(p);
    func_021D4244(p, (u32)func_021D4FE4, 0x31b);
}

void func_021D4AD4(char *p)
{
    unsigned ranges;
    func_0201DD68();
    func_021D45E8(p);
    func_02040DA8(5, 1, 0);
    ranges = ((struct Obj02472 *)p)->f5C;
    func_0203FB44(5, (u16)ranges, (u16)(ranges >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04(((struct Obj02472 *)p)->f44);
    func_0201D83C(((struct Obj02472 *)p)->f4C);
    func_02045808(((struct Obj02472 *)p)->f54);
    func_02045808(((struct Obj02472 *)p)->f50);
    func_02045808(((struct Obj02472 *)p)->f58);
    func_020452E8(((struct Obj02472 *)p)->f3C);
}

void func_021D4B30(char *p)
{
    if (func_020221A4()) {
        if (((struct Obj13964 *)p)->f8 == 1) {
            if (!func_02026454((void *)func_02012138(((struct Obj13964 *)p)->f354)))
                func_021D4244(p, 0, 0x341);
        } else {
            func_021D4244(p, 0, 0x345);
        }
    }
}

/*
 * evidence: unlabelled ov014 Thumb setter 0x02178118 is filed separately.
 * extent: unit includes tail-call stub 0x021D4BDC and return stub 0x021D4BF0;
 *   two zero padding bytes at 0x021D4BF2 follow the intended code.
 */
void func_021D4B74(char *p)
{
    ((struct Obj06457 *)p)->f38C = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj06457 *)p)->fC);
    func_02178118(0, 0);
    if (((struct Obj06457 *)p)->f8 == 1 && func_02026454((void *)func_02012138(((struct Obj06457 *)p)->f354)))
        func_02026400((struct Comm *)func_02012138(((struct Obj06457 *)p)->f354));
    func_021D4244(p, (u32)func_021D4B30, 0x35e);
}

void func_021D4BDC(char *p)
{
    func_021D4244(p, (u32)func_021D4B74, 0x36f);
}

void func_021D4BF0(void)
{
}
