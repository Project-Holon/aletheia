/*
 * file:     unit_021B7518_p01.c
 * unit:     yes
 * function: func_021B7518, func_021B75A8, func_021B7758, func_021B7968
 * address:  0x021B7518
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   d_021EFD54     0x021EFD54  data   a4
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4294 0x021D4294 thumb ov093
 *   func_021D4348 0x021D4348 thumb ov093
 *   func_021D4360 0x021D4360 thumb ov093
 *   func_021D4378 0x021D4378 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021D43B8 0x021D43B8 thumb ov093
 *   func_021D440C 0x021D440C thumb ov093
 *   func_021D4AF4 0x021D4AF4 thumb ov093
 *   func_021D4B18 0x021D4B18 thumb ov093
 *   func_021D4438 0x021D4438 thumb ov093
 *   func_021D44CC 0x021D44CC thumb ov093
 *   func_021D4D24 0x021D4D24 thumb ov093
 *   func_021D4D64 0x021D4D64 thumb ov093
 *   func_021D4680 0x021D4680 thumb ov093
 *   func_021D4784 0x021D4784 thumb ov093
 *   func_021D4D5C 0x021D4D5C thumb ov093
 *   func_021D47A4 0x021D47A4 thumb ov093
 *   func_021D4800 0x021D4800 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021BA128 0x021BA128 thumb ov093
 *   func_021BA648 0x021BA648 thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_0201A918 0x0201A918 thumb
 *   func_021D4808 0x021D4808 thumb ov093
 *   func_021D4898 0x021D4898 thumb ov093
 *   func_021D48CC 0x021D48CC thumb ov093
 *   func_021D4908 0x021D4908 thumb ov093
 *   func_021D49B0 0x021D49B0 thumb ov093
 *   func_021D49CC 0x021D49CC thumb ov093
 *   func_021D49E0 0x021D49E0 thumb ov093
 *   func_021D4A04 0x021D4A04 thumb ov093
 *   func_021B9E38 0x021B9E38 thumb ov093
 *   func_021B9EF0 0x021B9EF0 thumb ov093
 *   func_021BA670 0x021BA670 thumb ov093
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045808 0x02045808 arm
 *   func_020084D4 0x020084D4 thumb
 */
#include "../../matched/include/Obj02130.h"
#include "../../matched/include/Obj00966.h"
#include "../../matched/include/Obj20944.h"
#include "../../matched/include/Obj20945.h"
#include "../../matched/include/Obj20946.h"
#include "../../matched/include/Obj20947.h"
#include "../../matched/include/Obj00764.h"
#include "../../matched/include/Obj20948.h"

struct S;
struct A;
struct B;
struct MsgBank;
struct Rec;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[6]; } Copy;

typedef struct { u8 a:1; u8 b:1; u8 c:1; } Bits;

typedef struct { u8 a:4; u8 b:4; } Nibbles;

typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;

typedef enum { START, END = 15 } Index;

extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern int func_021D4270(void);
extern int func_021D4294(u16 v);
extern int func_021D4348(void);
extern int func_021D4360(void);
extern u8 func_021D4378(void);
extern int func_021BA1A8(char **p, int m);
extern u32 func_021D43B8(u32 a);
extern int func_021D440C(void *);
extern void func_021D4AF4(int a);
extern int func_021D4B18(int a);
extern u8 func_021D4438(u32 a);
extern int func_021D44CC(void);
extern void *func_021D4D24(u32,u16);
extern void func_021D4D64(u32 *p, const void *src, u32 a);
extern u32 func_021D4680(u32 *a);
extern int func_021D4784(u32 a);
extern void func_021D4D5C(void *);
extern void *func_021D47A4(u8);
extern void func_021D4800(void);
extern void func_021B93E0(char *p, u32 a, u32 b);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern void func_021BA128(struct S *p, int i, void *x);
extern void func_021BA648(char *p, u8 k, void *dst);
extern void func_021B9460(char *a, char *b, u8 c);
extern int func_0201A918(void);
extern int func_021D4808(u32 a);
extern int func_021D4898(void);
extern void *func_021D48CC(u8);
extern u32 func_021D4908(void *);
extern int func_021D49B0(void);
extern void *func_021D49CC(void);
extern void func_021D49E0(void);
extern void func_021D4A04(void);
extern void func_021B9E38(char *p, int a, int b);
extern void func_021B9EF0(struct A *p, const struct B *src);
extern void func_021BA670(char *p, u8 k, void *dst);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
int func_021B7518(int *sp, u8 *p);
int func_021B75A8(u8 *p,u32 *state);
int func_021B7758(u8 *p,u32 *state);
int func_021B7968(u8 *p,u32 *state);

extern int (*d_021EFD54[7])(u8 *, u8 *);


int func_021B7518(int *sp, u8 *p)
{
    if (*sp == 0) {
        p[0x46b] = 2;
        p[0x428] = 0;
        p[0x429] = 1;
        p[0x42a] = 0;
        p[0x42b] = 1;
        p[0x42c] = 0;
        p[0x42d] = 1;
        p[0x46c] = *(u8 *)(((struct Obj02130 *)p)->f0 + 0x21);
        p[0x46d] = func_021B8BEC(p, p[0x46c], 0);
        *sp = *sp + 1;
        return 0;
    }
    if ((u32)*sp < 7) {
        if (d_021EFD54[*sp](p, p + 0x460)) {
            ((struct Obj02130 *)p)->f460 = 0;
            *sp = *sp + 1;
        }
        return 0;
    }
    return 1;
}

int func_021B75A8(u8 *p,u32 *state)
{
    u8 *q;
    if (func_021D4270()) {
        ((Bits *)(p + 0x473))->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_021D4294(p[0x46c])) ++*state;
        break;
    case 1:
        if (func_021D4348()) {
            p[0x46a] = 0;
            p[0x46e] = func_021D4360();
            (*(u8 **)p)[0x91] = func_021D4378();
            if (func_021D4360()) *state = 2;
            else *state = 3;
        }
        break;
    case 2:
        *(Copy *)(p + 0x408) = *(Copy *)(p + 0x3f0);
        ((struct Obj00966 *)p)->f420 = ((struct Obj20944 *)(*(u8 * *)&((struct Obj00966 *)p)->f0))->f86;
        ((struct Obj00966 *)p)->f422 = ((struct Obj20945 *)(*(u8 * *)&((struct Obj00966 *)p)->f0))->f74;
        ((struct Obj00966 *)p)->f424 = ((struct Obj20946 *)(*(u8 * *)&((struct Obj00966 *)p)->f0))->f76;
        if (func_021BA1A8((char **)p,0x1000)) {
            p[0x426] = ((struct Obj00966 *)p)->f43C;
            ((Nibbles *)(p + 0x427))->a = ((Bits *)(p + 0x473))->c;
        } else {
            p[0x426] = 2;
            ((Nibbles *)(p + 0x427))->a = 1;
        }
        if (func_021D43B8((u32)(p + 0x408))) ++*state;
        break;
    case 3:
        if (func_021D440C(p + 0x408)) {
            q = *(u8 * *)&((struct Obj00966 *)p)->f0;
            ((struct Obj20947 *)q)->f86 = ((struct Obj00966 *)p)->f420;
            *(Copy *)(q + 0x9c) = *(Copy *)(p + 0x408);
            *(Copy *)(p + 0x3f0) = *(Copy *)(p + 0x408);
            ((Bits *)(p + 0x473))->c = ((Nibbles *)(p + 0x427))->a;
            ((struct Obj00966 *)p)->f43C = p[0x426];
            ((struct Obj00966 *)p)->f440 = ((struct Obj00966 *)p)->f422;
            ((struct Obj00966 *)p)->f442 = ((struct Obj00966 *)p)->f424;
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * lever: k starts at 1 and is conditionally assigned 3; ternary reverses the short branch.
 */
int func_021B7758(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    u8 *desc;
    int k;
    q = *(u8 * *)&((struct Obj00764 *)p)->f0;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4AF4((u8)2);
        ++*state;
        break;
    case 1:
        if (func_021D4B18((u8)2)) ++*state;
        break;
    case 2:
        if (func_021D4438((u32)(((struct Obj20948 *)q)->f24))) ++*state;
        break;
    case 3:
        if (func_021D44CC()) {
            if (!p[0x471]) *state = 10;
            else {
                if (p[0x46e]) {
                    ((struct Obj00764 *)p)->f2C4 = func_021D4D24(func_0201A918(), (((struct Obj00764 *)p)->f468 & 0x7fff) | 0x8000);
                }
                p[0x470] = 0;
                ++*state;
            }
        }
        break;
    case 4:
        k = 1;
        if (p[0x470]) k = 3;
        p[0x472] = k;
        if (p[0x46e]) func_021D4D64(((struct Obj00764 *)p)->f2C4, *(void **)(q + p[0x472] * 4 + 0x24),p[0x472]);
        func_021D4AF4((u8)(p[0x470] + 6));
        ++*state;
        break;
    case 5:
        if (func_021D4B18((u8)(p[0x470] + 6))) ++*state;
        break;
    case 6:
        if (!p[0x46e] || func_021D4680(((struct Obj00764 *)p)->f2C4)) ++*state;
        break;
    case 7:
        if (func_021D4784(p[0x472])) {
            ++p[0x470];
            if (p[0x470] >= p[0x471]) {
                if (p[0x46e]) {
                    func_021D4D5C(((struct Obj00764 *)p)->f2C4);
                    ((struct Obj00764 *)p)->f2C4 = 0;
                }
                *state = 10;
            } else *state = 4;
        }
        break;
    case 10:
        func_021B93E0((char *)(p + 0xc8),(u32)p,(int)0);
        desc = p + 0xc8;
        for (i = 0; i < 4; ++i) {
            if (func_021B8B9C(p,i)) {
                func_021BA128((struct S *)p,(u8)i,func_021D47A4(i));
                func_021BA648((char *)p,i,func_021D47A4(i));
                func_021B9460((char *)desc,(char *)p,i);
            }
        }
        ++*state;
        break;
    case 11:
        func_021B93E0((char *)(p + 0x1b0),(u32)p,(int)1);
        for (i = 0; i < 4; ++i) {
            if (func_021B8B9C(p,i)) func_021B9460((char *)(p + 0x1b0),(char *)p,i);
        }
        ++*state;
        break;
    case 12:
        func_021D4800();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}

int func_021B7968(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    u32 offset;
    void *bank;
    void *s;
    void *s2;
    u16 *src;
    u16 *dst;
    u16 buf[16];
    int k;
    q = *(u8 **)p;
    if (func_021D4270()) {
        ((Bits *)(p + 0x473))->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4AF4((u8)4);
        ++*state;
        break;
    case 1:
        if (func_021D4B18((u8)4)) ++*state;
        break;
    case 2:
        if (func_021D4808((u32)(*(void **)(p + 0xc0)))) ++*state;
        break;
    case 3:
        if (func_021D4898()) {
            for (i = 0; i < p[0x46b]; ++i) {
                s = func_021D48CC(i);
                if (s) {
                    offset = i * 0x28;
                    func_021B9E38((char *)(p + 0x20 + offset),*(u16 *)(p + 0x468),(int)s);
                    if (i != p[0x46c] && ((Bits *)(q + 0xc1))->c) {
                        void *str;
                        int j;
                        bank = func_02045B38(0,2,0x51,*(u16 *)(p + 0x468));
                        str = func_02045EC0(bank,15);
                        func_02045C04(bank);
                        src = func_02045A90(str);
                        for (j = START; j < END && (u32)j < func_020458F8(str); ++j) buf[j] = src[j];
                        dst = buf;
                        dst[j] = func_02045A98();
                        func_02045808(str);
                        func_020084D4((u32)(*(void **)(p + offset + 0x20)),dst);
                        func_02045808(*(void **)(p + offset + 0x24));
                        bank = func_02045B38(0,2,0x51,*(u16 *)(p + 0x468));
                        s2 = func_02045EC0(bank,15);
                        func_02045C04(bank);
                        *(void **)(p + offset + 0x24) = s2;
                    }
                    func_021BA670((char *)p,i,*(void **)(p + offset + 0x20));
                }
            }
            ++*state;
        }
        break;
    case 4:
        if (!p[0x471]) *state = 10;
        else { p[0x470] = 0; ++*state; }
        break;
    case 5:
        func_021D4AF4((u8)(p[0x470] + 8));
        ++*state;
        break;
    case 6:
        if (func_021D4B18((u8)(p[0x470] + 8))) ++*state;
        break;
    case 7:
        k = 1;
        if (p[0x470]) k = 3;
        p[0x472] = k;
        if (p[0x46e] && !func_021D4908(*(void **)(q + p[0x472] * 4 + 0x48))) break;
        ++*state;
    case 8:
        if (func_021D49B0()) {
            func_021B9EF0((struct A *)(p + 0x20 + p[0x472] * 0x28),func_021D49CC());
            func_021D49E0();
            ++p[0x470];
            if (p[0x470] >= p[0x471]) *state = 10;
            else *state = 5;
        }
        break;
    case 10:
        func_021D4A04();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}
