/*
 * file:     gds_rap_p01.c
 * unit:     yes
 * function: func_021D6660, func_021D6770, func_021D67C8, func_021D6814, func_021D683C, func_021D68EC, func_021D6968, func_021D698C, func_021D69B4, func_021D69DC, func_021D6A08, func_021D6A34
 * address:  0x021D6660
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8600 0x021D8600 arm ov125
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_021D8598 0x021D8598 arm ov125
 *   func_02034714 0x02034714 arm
 *   ov114_id 0x00000072 data
 *   d_021D8D00 0x021D8D00 data a4
 *   d_021D8D0C 0x021D8D0C data a4
 *   d_021D8D28 0x021D8D28 data a4
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_021D85B4 0x021D85B4 arm ov125
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021D730C 0x021D730C thumb ov125
 *   func_021D7700 0x021D7700 thumb ov125
 *   func_021D7154 0x021D7154 thumb ov125
 *   func_021D71CC 0x021D71CC thumb ov125
 *   func_0200B910 0x0200B910 thumb
 *   d_021D8C80 0x021D8C80 data a2
 *   func_021D85C0 0x021D85C0 arm ov125
 *   func_021D6B40 0x021D6B40 thumb ov125
 *   func_021D6FB0 0x021D6FB0 thumb ov125
 */
#include "../../matched/include/Obj03805.h"
#include "../../matched/include/Obj14003.h"
#include "../../matched/include/Obj02838.h"
#include "../../matched/include/Obj06472.h"
#include "../../matched/include/Obj22996.h"
#include "../../matched/include/Obj03806.h"
#include "../../matched/include/Obj14004.h"
#include "../../matched/include/Obj14005.h"
#include "../../matched/include/Obj14006.h"
#include "../../matched/include/Obj01060.h"

struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct ObjC4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[7]; } Blk;

typedef signed int     s32;

typedef struct { int words[32]; } Block128;

typedef struct { int words[108]; } Block432;

typedef int (*Callback)(void *, void *);

extern int func_02034AC4(s32 handle);
extern void func_02082BCC(void *, int, u32);
extern int func_021D8600(int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021D8598(void *, const char *, int);
extern void func_02034714(const char *, u32, const char *);
extern void func_021B99B8(u8 *p);
extern void func_021B9838(u8 *p);
extern void func_021D85B4(void);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern int func_021D730C(char *);
extern char *func_021D7700(void);
extern void func_0200B784(u16, int *, int *);
extern int func_021D7154(int, int, int *, int *);
extern void func_021D71CC(const void *src, void *dst, u32 n);
extern struct ObjC4 *func_0200B910(void);
extern void func_02082D44(void *, const void *, unsigned int);
extern unsigned func_021D85C0(void);
extern int func_021D6B40(u8 *p, int *done);
extern int func_021D6FB0(char *);
int func_021D6660(char *p, char *a);
void func_021D6770(char *p);
int func_021D67C8(char *p, const Block128 *a, const Block432 *b);
int func_021D6814(char *p,int v);
int func_021D683C(char *p, void *dst);
int func_021D68EC(char *p, int id, unsigned int index, int mode, u8 other);
int func_021D6968(char *p);
int func_021D698C(char *p);
int func_021D69B4(char *p);
int func_021D69DC(char *p,int a,int b);
int func_021D6A08(char *p,int a,int b);
int func_021D6A34(char *p);
extern char ov114_id[];
extern const char d_021D8D00[];
extern const char d_021D8D0C[];
extern char d_021D8D28[];
extern const u16 d_021D8C80[][2];


int func_021D6660(char *p, char *a)
{
    func_02034AC4((int)ov114_id);
    func_02082BCC(p, 0, 0x5A4);
    *(u32 *)(p + 0x13C) = *(u16 *)(a + 4);
    *(u32 *)p = *(u32 *)(a + 8);
    *(u32 *)(p + 0x494) = *(u32 *)(a + 0xC);
    *(Blk *)(p + 0x148) = *(Blk *)(a + 0x10);
    *(int *)(p + 0x144) = -1;
    *(u32 *)(p + 0x3D8) = 0x55F4;
    *(u32 *)(p + 0x3DC) = 0x55F4;
    *(void **)(p + 0x3AC) = func_02030734(*(u16 *)(a + 4), func_021D8600(-1), 0, d_021D8D00, 0x84);
    func_02082BCC(*(void **)(p + 0x3AC), 0, func_021D8600(-1));
    *(int *)(p + 0x3E4) = (int)func_02045B38(0, 2, 0xE8, *(u16 *)(a + 4));
    *(int *)(p + 0x3E8) = (int)func_0201EC64(*(u16 *)(a + 4));
    *(int *)(p + 0x3EC) = (int)func_020457B0(0x100, *(u16 *)(a + 4));
    *(u32 *)(p + 4) = *(u32 *)a;
    p[8] = 0x15;
    p[9] = 2;
    if (func_021D8598(p + 4, d_021D8D0C, 0x3071) != 1)
        func_02034714(d_021D8D28, 0, d_021D8D28);
    *(u32 *)(p + 0x3B4) = 1;
    *(u32 *)(p + 0x3B0) = 1;
    return 1;
}

void func_021D6770(char *p)
{
    if (((struct Obj03805 *)p)->f404) {
        func_021B99B8(((struct Obj03805 *)p)->f404);
        func_021B9838(((struct Obj03805 *)p)->f404);
    }
    func_021D85B4();
    ((struct Obj03805 *)p)->f3B4 = 0;
    func_02045808(((struct Obj03805 *)p)->f3EC);
    func_0201ED04(((struct Obj03805 *)p)->f3E8);
    func_02045C04(((struct Obj03805 *)p)->f3E4);
    func_020307B0(((struct Obj03805 *)p)->f3AC);
    func_02034A5C((int)ov114_id);
}

int func_021D67C8(char *p, const Block128 *a, const Block432 *b)
{
    if (!func_021D730C(p)) return 0;
    *(Block128 *)(p + 0x174) = *a;
    *(Block432 *)(p + 0x1f4) = *b;
    p[0x401] = 0x3c;
    ((struct Obj14003 *)p)->f3D8 = 0x5208;
    return 1;
}

int func_021D6814(char *p,int v) {if(!func_021D730C(p))return 0;*(u16 *)&((struct Obj02838 *)p)->f3A4=v;((struct Obj02838 *)p)->f3D8=0x5209;return 1;}

int func_021D683C(char *p, void *dst)
{
    char *r;
    char *out;
    char *base;
    int outer, inner;
    int n, m;
    int i;
    r = func_021D7700();
    if (!func_021D730C(p)) return 0;
    func_0200B784(((struct Obj22996 *)r)->fA6, &n, &m);
    base = r + 0xd00;
    out = p + 0x498;
    for (i = 0; i < 12; i++) {
        if (!func_021D7154((int)p, i, &outer, &inner)) break;
        func_021D71CC(base + outer * 676 + inner * 112 + 50, out + i * 22, 11);
    }
    ((struct Obj06472 *)p)->f5A0 = 0;
    p[0x403] = 0;
    *(char * *)&((struct Obj06472 *)p)->f174 = r;
    func_02082D44(dst, func_0200B910(), 128);
    p[0x401] = 60;
    ((struct Obj06472 *)p)->f3D8 = 0x55f0;
    return 1;
}

int func_021D68EC(char *p, int id, unsigned int index, int mode, u8 other)
{
    if (!func_021D730C(p)) return 0;
    if (index >= 20) func_02034714(d_021D8D28, 0, d_021D8D28);
    func_02082BCC(p + 0x174, 0, 16);
    ((struct Obj03806 *)p)->f174 = id;
    ((struct Obj03806 *)p)->f176 = d_021D8C80[index][0];
    ((struct Obj03806 *)p)->f178 = d_021D8C80[index][1];
    ((struct Obj03806 *)p)->f17A = mode;
    ((struct Obj03806 *)p)->f17B = other;
    ((struct Obj03806 *)p)->f17C = 100;
    ((struct Obj03806 *)p)->f3E0 = 0;
    ((struct Obj03806 *)p)->f3D8 = 0x55f1;
    return 1;
}

int func_021D6968(char *p) {if(!func_021D730C(p))return 0;((struct Obj14004 *)p)->f3E0=1;((struct Obj14004 *)p)->f3D8=0x55f1;return 1;}

int func_021D698C(char *p) {if(!func_021D730C(p))return 0;((struct Obj14005 *)p)->f3E0=2;((struct Obj14005 *)p)->f3D8=0x55f1;return 1;}

int func_021D69B4(char *p) {if(!func_021D730C(p))return 0;((struct Obj14006 *)p)->f3E0=3;((struct Obj14006 *)p)->f3D8=0x55f1;return 1;}

int func_021D69DC(char *p,int a,int b) {if(!func_021D730C(p))return 0;((struct Obj02838 *)p)->f3A4=a;((struct Obj02838 *)p)->f3A8=b;((struct Obj02838 *)p)->f3D8=0x55f2;return 1;}

int func_021D6A08(char *p,int a,int b) {if(!func_021D730C(p))return 0;((struct Obj02838 *)p)->f3A4=a;((struct Obj02838 *)p)->f3A8=b;((struct Obj02838 *)p)->f3D8=0x55f3;return 1;}

int func_021D6A34(char *p)
{
    int result;
    if (((struct Obj01060 *)p)->f3B4 == 1) {
        if (((struct Obj01060 *)p)->f3D8 != 0x55f4) {
            if (((struct Obj01060 *)p)->f401 != 0) {
                (((struct Obj01060 *)p)->f401)--;
            } else {
                switch (func_021D85C0()) {
                case 1: case 7: case 8: case 9:
                    if (func_021D6B40((u8 *)p, &result) == 1) {
                        ((struct Obj01060 *)p)->f3D8 = 0x55f4;
                        ((struct Obj01060 *)p)->f402 = 0;
                        if (result == 1) {
                            ((struct Obj01060 *)p)->f168 = 2;
                            ((struct Obj01060 *)p)->f16C = 0x55f0;
                            ((struct Obj01060 *)p)->f170 = ((struct Obj01060 *)p)->f493;
                            ((struct Obj01060 *)p)->f164 = 1;
                            if (*(Callback *)&((struct Obj01060 *)p)->f154 != 0)
                                (*(Callback *)(p + 0x154))(((struct Obj01060 *)p)->f148, p + 0x164);
                        }
                    }
                    break;
                case 0: case 2: case 3: case 4: case 5: case 6:
                default: break;
                }
            }
        }
        func_021D6FB0(p);
        if (*(Callback *)&((struct Obj01060 *)p)->f3FC != 0) {
            if ((*(Callback *)(p + 0x3fc))(p, p + 0x3f0) == 1) {
                *(Callback *)&((struct Obj01060 *)p)->f3FC = 0;
                if (*(Callback *)&((struct Obj01060 *)p)->f3F0 != 0) {
                    (*(Callback *)(p + 0x3f0))(((struct Obj01060 *)p)->f148, p + 0x164);
                    *(Callback *)&((struct Obj01060 *)p)->f3F0 = 0;
                }
                func_02082BCC(p + 0x3f0, 0, 16);
                ((struct Obj01060 *)p)->f3DC = 0x55f4;
            }
        }
    }
    return 1;
}
