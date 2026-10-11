/*
 * file:     unit_021B7518.c
 * unit:     yes
 * function: func_021B7518, func_021B75A8, func_021B7758, func_021B7968, func_021B7BB0, func_021B7CB4, func_021B7E18, func_021B8070, func_021B81DC, func_021B835C, func_021B83F4, func_021B8434, func_021B84D8, func_021B8548, func_021B8564, func_021B8588, func_021B8590, func_021B85A0, func_021B85A8, func_021B85DC, func_021B85EC, func_021B8630, func_021B8640, func_021B8670, func_021B86A0, func_021B86B8, func_021B86C0, func_021B86C8, func_021B86DC, func_021B86E4, func_021B8714, func_021B871C, func_021B8724, func_021B873C, func_021B8748, func_021B8750, func_021B8778, func_021B87E8
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
 *   func_021D4500 0x021D4500 thumb ov093
 *   func_021D450C 0x021D450C thumb ov093
 *   func_021D45FC 0x021D45FC thumb ov093
 *   func_021D4648 0x021D4648 thumb ov093
 *   func_021D4674 0x021D4674 thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021BA698 0x021BA698 thumb ov093
 *   func_02012EBC 0x02012EBC thumb
 *   func_02007B44 0x02007B44 thumb
 *   func_02007B20 0x02007B20 thumb
 *   func_02007B00 0x02007B00 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAACC 0x021BAACC thumb ov093
 *   func_021BAB10 0x021BAB10 thumb ov093
 *   func_021CD960 0x021CD960 thumb ov093
 *   func_021B6994 0x021B6994 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021BAB40  0x021BAB40  thumb  ov093
 *   func_021BAB9C  0x021BAB9C  thumb  ov093
 *   func_021CD97C  0x021CD97C  thumb  ov093
 *   func_021CDD94  0x021CDD94  thumb  ov093
 *   func_021E908C  0x021E908C  thumb  ov093
 *   func_021BABDC  0x021BABDC  thumb  ov093
 *   func_021CD914 0x021CD914 thumb ov093
 *   func_020083C8 0x020083C8 thumb
 *   func_02013080 0x02013080 thumb
 *   ov231_id       0x000000E7  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021809D8  0x021809D8  thumb  ov231
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200CF28  0x0200CF28  thumb
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_021B8834  0x021B8834  thumb  ov093
 *   func_021B88EC  0x021B88EC  thumb  ov093
 *   func_021B8C50  0x021B8C50  thumb  ov093
 */
#include "../../matched/include/Obj02130.h"
#include "../../matched/include/Obj00966.h"
#include "../../matched/include/Obj20944.h"
#include "../../matched/include/Obj20945.h"
#include "../../matched/include/Obj20946.h"
#include "../../matched/include/Obj20947.h"
#include "../../matched/include/Obj00764.h"
#include "../../matched/include/Obj20948.h"
#include "../../matched/include/Obj07743.h"
#include "../../matched/include/Obj20949.h"
#include "../../matched/include/Obj01232.h"
#include "../../matched/include/Obj05182.h"
#include "../../matched/include/Obj01233.h"
#include "../../matched/include/Obj05183.h"
#include "../../matched/include/Obj01134.h"
#include "../../matched/include/Obj05184.h"
#include "../../matched/include/Obj03685.h"
#include "../../matched/include/Obj13269.h"
#include "../../matched/include/Obj05185.h"
#include "../../matched/include/Obj20950.h"
#include "../../matched/include/Obj18120.h"
#include "../../matched/include/Obj18122.h"
#include "../../matched/include/Obj20952.h"
#include "../../matched/include/Obj12104.h"
#include "../../matched/include/Obj18127.h"
#include "../../matched/include/Obj18129.h"
#include "../../matched/include/Obj20957.h"
#include "../../matched/include/Obj20958.h"
#include "../../matched/include/Obj20959.h"
#include "../../matched/include/Obj20961.h"
#include "../../matched/include/Obj18131.h"
#include "../../matched/include/Obj01889.h"
#include "../../matched/include/Obj20962.h"

struct S;
struct A;
struct B;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Sub02007AC8Entry;
struct Big;
struct Copy24;
struct QB;
struct QA;
struct Scene;
struct QF;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[6]; } Copy;

typedef struct { u8 a:1; u8 b:1; u8 c:1; } Bits;

typedef struct { u8 a:4; u8 b:4; } Nibbles;

typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;

typedef enum { START, END = 15 } Index;

typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B_021B7E18;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
} B_021B835C;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Flags { unsigned char low:2, bit:1, high:5; };


struct Unk021B8CB0 { u32 f0; u32 mode; };

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
extern void func_021D4500(void);
extern u32 func_021D450C(u32 *);
extern int func_021D45FC(void);
extern u32 func_021D4648(u32 a);
extern void func_021D4674(void);
extern int func_021B9F70(u8 *p, int i);
extern void func_021BA698(u8 *p, int k);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02007B20(u32 heap);
extern u32 func_02007B00(void);
extern void func_02082D44(const void *,void *,u32);
extern u8 func_021B6818(int *);
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAACC(char *p, int a, int b, int c, u8 d);
extern void func_021BAB10(int, u8, int);
extern void func_021CD960(u8 *p, u32 v);
extern int func_021B6994(struct S **pp, u32 b);
extern u8 func_021B9010(u8 *, u8);
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern void func_021CD95C(struct QA *p, u32 v);
extern void func_021BAB40(char *p);
extern int func_021BAB9C(int a);
extern int func_021CD97C(int);
extern void func_021CDD94(char *p, int *o);
extern void func_021E908C(char *p);
extern void func_021BABDC(int, u8 *);
extern void func_021CD914(u8 *p);
extern unsigned int func_020083C8(void *);
extern signed char func_02013080(u32 idx);
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern int func_021809D8(void);
extern u16 func_021D5444(struct QF *p);
extern int func_0200CED4(void *,unsigned int);
u16 func_0200CF28(struct Blk37 *p);
extern void *func_021D5844(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u8 func_021B8834(void *p, u32 k, u8 v, u8 *out);
extern u8 func_021B88EC(void *p, u32 k, u32 v, u8 *out);
extern u8 func_021B8C50(char **p, u32 v, int k);
int func_021B7518(int *sp, u8 *p);
int func_021B75A8(u8 *p,u32 *state);
int func_021B7758(u8 *p,u32 *state);
int func_021B7968(u8 *p,u32 *state);
int func_021B7BB0(u8 *p,u32 *state);
int func_021B7CB4(u8 *p);
int func_021B7E18(u8 *p);
int func_021B8070(u8 *p);
int func_021B81DC(u8 *p);
int func_021B835C(u8 *p, int *q);
int func_021B83F4(int a);
int func_021B8434(u8 *p);
int func_021B84D8(u8 *p);
void func_021B8548(unsigned char *p);
int func_021B8564(unsigned char *p);
u32 func_021B8588(void **p);
unsigned int func_021B8590(unsigned char *p);
u8 func_021B85A0(u8 **p);
int func_021B85A8(unsigned char *p);
int func_021B85DC(unsigned char *p);
int func_021B85EC(u32 **p);
u32 func_021B8630(u32 **p);
unsigned int func_021B8640(unsigned int **p);
unsigned int func_021B8670(unsigned int **p);
int func_021B86A0(unsigned int **p, unsigned int i);
void *func_021B86B8(void ***p);
u8 func_021B86C0(u8 **p);
int func_021B86C8(unsigned char **p);
u16 func_021B86DC(void **p);
int func_021B86E4(unsigned int **p);
char *func_021B8714(char **p);
int func_021B871C(char *p);
int func_021B8724(char *p,void *m);
u32 func_021B873C(char **p);
u32 func_021B8748(void **p);
void func_021B8750(char *p,unsigned char k,void *m);
u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
u8 func_021B87E8(void *p, u32 k, u32 v, u8 *out);
extern u8 ov231_id[];




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




int func_021B7BB0(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    void *src;
    q = *(u8 * *)&((struct Obj07743 *)p)->f0;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4500();
        func_021D4AF4(3);
        ++*state;
        break;
    case 1:
        if (func_021D4B18(3)) ++*state;
        break;
    case 2:
        if (func_021D450C((u32 *)func_02007B44(func_02012EBC(((struct Obj20949 *)q)->f58)))) ++*state;
        break;
    case 3:
        if (func_021D45FC()) {
            for (i = 0; i < 4; ++i) {
                if (func_021B8B9C(p,i) && !func_021B9F70(p,(u8)i)) {
                    src = (void *)func_021D4648((u8)i);
                    if (src) {
                        *(void **)(p + i * 4 + 0x3e0) = func_02007B20(((struct Obj07743 *)p)->f468);
                        func_02082D44(src, *(void **)(p + i * 4 + 0x3e0),func_02007B00());
                    }
                }
                func_021BA698(p,(u8)i);
            }
            func_021D4674();
            ++*state;
        }
        break;
    default:
        return 1;
    }
    return 0;
}




int func_021B7CB4(u8 *p)
{
    u8 *q;
    u8 idx;
    int t;
    u32 i, flag;
    q = *(u8 * *)&((struct Obj01232 *)p)->f0;
    idx = p[0x46c];
    t = (int)func_021B6818((int *)q);
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        ((struct Obj01232 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01232 *)p)->f468);
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05182 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01232 *)p)->f468);
        func_021BAA94((char *)(((struct Obj01232 *)p)->f8), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, 1);
        flag = 1;
        if (idx != 0) flag = 0;
        func_021BAACC((char *)(((struct Obj01232 *)p)->f8), q[0x20], ((struct Obj05182 *)q)->f1C, (u8)flag, 1);
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05182 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01232 *)p)->f468);
        ((struct Obj01232 *)p)->fC = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01232 *)p)->f468);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10((int)(((struct Obj01232 *)p)->fC), i, 1);
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(((struct Obj01232 *)p)->fC));
    }
    return 1;
}




/*
 * note 2026-10-05 (wave P3 R5): twin shape of ov093 021B8070 / 021B7CB4 (same callees). The
 *   0x46e flag is a local `k = 0x46e` (p[0x46e], p[k-3], p[k-6], p+(k-0x7e)), spilled to [sp,#0x38]
 *   like the original. f9010 result is a u8 (no truncation before f_BAACC). 69 bytes differ,
 *   all pure instruction ORDER inside the argument setup of the first f9C8 / f6F0 calls and the
 *   else-branch f6F0 call (str [sp] vs lsls r2; adds r1,r4,#0 early vs late). Same 600 bytes of
 *   content. Tried without effect: const u8 *q, const callee prototype params, u32 k,
 *   scheduling off, peephole off (identical 69 B), opt_lifetimes off (123 B), opt_propagation off (574 B).
 *   2026-10-05 (wave P3 R5b): the k = 0x46e local is not needed: plain literals (p[0x46e], p + 0x3f0,
 *   *(u16 *)(p + 0x468), p[0x46b]) give the same 69 bytes, so the file now uses literals. The compiler
 *   itself spills the 0x46e pool word to [sp,#0x38] (no free callee-saved register: p r4, q r6, mode r7,
 *   zero r5, idx spilled). Twin 021B8070 has idx in r4 and a base r6 = 0x46c, so its schedule differs
 *   and cannot be read across. New tries, all worse or equal: u16 local h assigned per site before each
 *   call (143 B); static inline u16 accessor for the heap read (69 B, no change); u32 idx (477 B), u32 mode
 *   (562 B), u32 x (268 B); static inline wrappers for func_021BA9C8 (69 B) and func_021CD6F0 (452 B);
 *   opt_common_subs off (460 B), opt_dead_assignments off (99 B). Residue unchanged: stack-store vs
 *   register-argument order in the first func_021BA9C8 call and the two func_021CD6F0 calls (+0x5C, +0x86..+0xA0,
 *   +0x1C0..+0x1D8). Needs a different IR order for the arguments; no human form found.
 *   final push 2026-10-05 G7L10: still 69 B (same residue, argument-setup order of f9C8 #1/#else and f6F0 idx calls; the
 *   idx==2 arm calls already match). 38 compiles, no change or worse: local struct views for p (f8, fC, f468, f10[]) and q
 *   (f1C/f20/f22) (69/477); named slots pointer (254); idx u16 (410), mode u16 (561); f6F0 prototype widths (idx u8, mode int,
 *   idx int, flag/9th int, arg3 u8) and const params (69 each); f9C8 heap int, const b/c (69); f6818(u8 *) (69); BAACC with an
 *   int 4th parameter as in its definition (202); result into a local before the slot store (452/463); zero locals (69);
 *   0x1b0 as a 27-record index (69); volatile t probe (101); u32 t, u32 f6818 result (69); decl orders (69); swapped arms (479);
 *   p[0x10] as add-order variants (69/477); mode via if/else (544); x int (268); early i = 0 (95); all-const q and callees (69).
 *   scheduling off leaves the 69 B unchanged and opt_lifetimes off keeps the same order residue (plus r4/r5 swap), so the order
 *   comes from IR emission, not the scheduler. Twins 021B8070/021B7CB4/021B81DC differ (idx in a register, no spilled k), and no
 *   other ov093 function contains subs #0x7e, so no asm twin exists. No human form found.
 *   pass 2 2026-10-06 P2L49: EXACT. t is a u8 local and func_021B6818 is declared returning u8 (it returns
 *   only 0 or 1, so the callee code is the same). mwcc keeps the reload of a spilled narrow local below the
 *   outgoing stack stores (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md); with
 *   int t it hoisted the reload and the argument setup order differed (69 B).
 */
int func_021B7E18(u8 *p)
{
    u8 *q;
    u8 idx;
    u8 mode;
    u8 t;
    u32 i;
    u8 x;
    q = *(u8 **)p;
    idx = p[0x46c];
    t = func_021B6818((int *)q);
    mode = (q[0x22] == 0) ? 2 : 1;
    if (func_021D4270()) {
        ((B_021B7E18 *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        *(int *)(p + 8) = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, *(u16 *)(p + 0x468));
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, (u8)mode, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
        func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, mode);
        if (q[0x22] == 2) {
            x = func_021B9010(p, idx);
            *(int *)(p + 0x14) = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), 1, (u8)mode, 1, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
            func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(*(int *)(p + 0x14))), 1, mode);
            *(int *)(p + 0x1c) = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), 3, (u8)mode, 1, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
            func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(*(int *)(p + 0x1c))), 3, mode);
            func_021BAACC((char *)(*(int *)(p + 8)), q[0x20], *(int *)(q + 0x1c), (u8)x, mode);
        } else {
            for (i = 0; i < p[0x46b]; i++) {
                if (i != idx)
                    func_021BAACC((char *)(*(int *)(p + 8)), q[0x20], *(int *)(q + 0x1c), (u8)i, mode);
            }
        }
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, (u8)mode, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
        *(int *)(p + 0xc) = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, *(u16 *)(p + 0x468));
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(*(int *)(p + 0xc), i, func_021B6994((struct S **)p, (u8)i));
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(*(int *)(p + 0xc)));
    }
    return 1;
}





int func_021B8070(u8 *p)
{
    u8 *q;
    u8 idx;
    int t;
    u32 i, flag;
    q = *(u8 * *)&((struct Obj01233 *)p)->f0;
    idx = p[0x46c];
    t = (int)func_021B6818((int *)((unsigned int *)q));
    if (func_021D4270()) {
        ((B_021B7E18 *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        ((struct Obj01233 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01233 *)p)->f468);
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05183 *)q)->f1C, idx, (u8)3, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01233 *)p)->f468);
        func_021BAA94((char *)(((struct Obj01233 *)p)->f8), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, 3);
        flag = 0;
        if (idx == 0) flag = 1;
        func_021BAACC((char *)(((struct Obj01233 *)p)->f8), q[0x20], ((struct Obj05183 *)q)->f1C, (u8)flag, 3);
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05183 *)q)->f1C, idx, (u8)3, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01233 *)p)->f468);
        ((struct Obj01233 *)p)->fC = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01233 *)p)->f468);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(((struct Obj01233 *)p)->fC, i, func_021B6994((struct S **)p, (u8)i));
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(((struct Obj01233 *)p)->fC));
    }
    return 1;
}





int func_021B81DC(u8 *p)
{
    u8 idx;
    u8 *q;
    int t;
    u32 i;
    idx = p[0x46c];
    q = *(u8 * *)&((struct Obj01134 *)p)->f0;
    t = (int)func_021B6818((int *)((unsigned int *)q));
    if (func_021D4270()) {
        ((B_021B7E18 *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        ((struct Obj01134 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01134 *)p)->f468);
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05184 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01134 *)p)->f468);
        func_021BAA94((char *)(((struct Obj01134 *)p)->f8), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, 1);
        for (i = 0; i < p[0x46b]; i++) {
            if (i != idx)
                func_021BAACC((char *)(((struct Obj01134 *)p)->f8), q[0x20], ((struct Obj05184 *)q)->f1C, (u8)i, 1);
        }
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05184 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01134 *)p)->f468);
        ((struct Obj01134 *)p)->fC = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01134 *)p)->f468);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(((struct Obj01134 *)p)->fC, i, func_021B6994((struct S **)p, (u8)i));
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(((struct Obj01134 *)p)->fC));
    }
    return 1;
}






int func_021B835C(u8 *p, int *q)
{
    int r, t;
    if (func_021D4270()) {
        ((B_021B835C *)p)->a = 1;
        return 1;
    }
    if (*q == 0) {
        r = func_021B6818((int *)((unsigned int *)(*(int * *)&((struct Obj03685 *)p)->f0)));
        t = (int)func_021E8F20(p, (void *)(*(int *)(p + p[0x46c] * 4 + 0x10)), (u32)(p + 0xc8), r, 0x13);
        ((struct Obj03685 *)p)->f4 = t;
        func_021CD95C((struct QA *)(*(int *)(p + p[0x46c] * 4 + 0x10)), t);
        if (p[0x46e]) {
            ((struct Obj03685 *)p)->f464 = (u32)func_021B8434;
            func_021BAB40((char *)(((struct Obj03685 *)p)->f8));
        } else {
            ((struct Obj03685 *)p)->f464 = (u32)func_021B84D8;
        }
        *q = *q + 1;
    } else {
        return 1;
    }
    return 0;
}






int func_021B83F4(int a)
{
    int i, found = 0;
    char *p = (char *)a;
    func_021BAB9C(((struct Obj13269 *)p)->f8);
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 &&
            func_021CD97C(*(int *)(p + i * 4 + 0x10)) != 0) {
            func_021CDD94((char *)(*(int *)(p + i * 4 + 0x10)), (int *)((int)(p + 0x448)));
            found = 1;
        }
    }
    func_021E908C((char *)(((struct Obj13269 *)p)->f4));
    return found;
}






int func_021B8434(u8 *p)
{
    int r, i;
    if (((B_021B835C *)p)->a == 0) {
        if (func_021D4270()) {
            ((B_021B835C *)p)->a = 1;
            func_021B8548(p);
        }
    } else if (((B_021B835C *)p)->b != 0) {
        return 1;
    }
    r = func_021BAB9C(((struct Obj05185 *)p)->f8);
    if (r) {
        func_021BABDC(((struct Obj05185 *)p)->f8, p + 0x448);
    }
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 && p[i + 0xc4] == 0) {
            p[i + 0xc4] = func_021CD97C(*(int *)(p + i * 4 + 0x10));
        }
    }
    if (func_021B8564(p)) {
        func_021CDD94((char *)(*(int *)(p + p[0x46c] * 4 + 0x10)), (int *)(p + 0x448));
        r = 1;
    }
    func_021E908C((char *)(((struct Obj05185 *)p)->f4));
    return r;
}






int func_021B84D8(u8 *p)
{
    int r, i;
    if (((B_021B835C *)p)->a == 0) {
        if (func_021D4270()) {
            ((B_021B835C *)p)->a = 1;
            func_021B8548(p);
        }
    } else if (((B_021B835C *)p)->b != 0) {
        return 1;
    }
    r = 0;
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 &&
            func_021CD97C(*(int *)(p + i * 4 + 0x10)) != 0) {
            func_021CDD94((char *)(*(int *)(p + i * 4 + 0x10)), (int *)(p + 0x448));
            r = 1;
        }
    }
    func_021E908C((char *)(((struct Obj20950 *)p)->f4));
    return r;
}





void func_021B8548(unsigned char *p) { unsigned int i; for(i=0;i<4;i++) { void *q; q=*(void **)(p+0x10+i*4); if (q) func_021CD914(q); } }





int func_021B8564(unsigned char *p) { unsigned int i; for (i=0;i<4;i++) { if (*(void **)(p+0x10+i*4) != 0 && p[0xc4+i] == 0) return 0; } return 1; }






/*
 * double deref: *(u32*)(*p + 0x4)
 */
u32 func_021B8588(void **p)
{
    return ((struct Obj18120 *)((u8 *)*p))->f4;
}





unsigned int func_021B8590(unsigned char *p) { return ((struct Flags *)(p+0x473))->bit; }






/* 021B85A0  ldr r0,[r0]; adds r0,#0x80; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x80; ldrb r0, [r0]; bx lr.
 */
u8 func_021B85A0(u8 **p) { return ((struct Obj18122 *)(*p))->f80; }





/*
 * note 2026-10-05: the arm9 witness src/matched/arm9/func_020083C8.c exists (EXACT); the only wildcard is that bl, so this lifts to EXACT after the integrator regenerates the manifest/labels.
 */
int func_021B85A8(unsigned char *p) { if (func_021B86B8((void ***)p)==(void *)1 && func_021B8588((void **)p)==0 && func_021B86C0((unsigned char **)p)==0 && func_020083C8(*(void **)(*(unsigned char **)p+0x5c))==0) return 1; return 0; }





int func_021B85DC(unsigned char *p) { return func_02013080(((struct Obj20952 *)p)->f43C); }






int func_021B85EC(u32 **p)
{
    int r;
    if (**p <= 1) {
        func_02034AC4((int)ov231_id);
        r = func_021809D8();
        func_02034A5C((int)ov231_id);
        if (r == 0) {
            return 0;
        }
        if (func_021BA1A8((char **)p, 0x200) == 0) {
            return 1;
        }
    }
    return 0;
}






/* 021B8630  first round: `if (*q > 1) return 0;` came back bls.  The image
 * takes the guard, so the guarded read is the fall-through arm. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldr r1, [r0]; ldr r0, [r1]; cmp r0, #1; bhi loc_021B863C; ldr r0, [r1, #0x70]; bx lr; movs r0, #0; bx lr.
 */
u32 func_021B8630(u32 **p)
{
    u32 *q = *p;
    if (*q <= 1)
        return ((struct Obj12104 *)q)->f70;
    return 0;
}





unsigned int func_021B8640(unsigned int **p) { switch ((*p)[1]) { case 0:return 1; case 1:return 3; case 2:return 5; case 3:return 5; default:return 5; } }





unsigned int func_021B8670(unsigned int **p) { switch ((*p)[1]) { case 0:return 1; case 1:return 2; case 2:return 3; case 3:return 1; default:return 1; } }





int func_021B86A0(unsigned int **p, unsigned int i) { if (i < func_021B8670(p)*2) return 1; return 0; }





void *func_021B86B8(void ***p)
{
    return **p;
}






/* 021B86C0  ldr r0,[r0]; adds r0,#0x20; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x20; ldrb r0, [r0]; bx lr.
 */
u8 func_021B86C0(u8 **p) { return ((struct Obj18127 *)(*p))->f20; }





/*
 * The SDK symbol list names 0x021B86CA CTRDGi_IsTaskBusy(pt), the busy-flag test (pt->busy != 0).
 * That address lies inside this function (adds #0x22 after the ldr): it is not a separate entry.
 * The final two zero bytes are alignment padding before the next function.
 */
int func_021B86C8(unsigned char **p) { if ((*p)[0x22]) return 1; return 0; }





/*
 * double deref u16
 */
u16 func_021B86DC(void **p)
{
    return ((struct Obj18129 *)((u8 *)*p))->f1A;
}


int func_021B86E4(unsigned int **p) { switch(**p) { case 0:return 0; case 1:return 1; case 2:return 2; case 3:return 2; default:return 1; } }


char *func_021B8714(char **p)
{
    return *p + 8;
}



int func_021B871C(char *p)
{
    return ((struct Obj20957 *)p)->fC0;
}


int func_021B8724(char *p,void *m) { unsigned int s=func_021D5444(m); return func_0200CED4(((struct Obj20959 *)(*(char * *)&((struct Obj20958 *)p)->f0))->f68,s); }


u32 func_021B873C(char **p)
{
    return func_0200CF28((struct Blk37 *)(((struct Obj20961 *)(*p))->f68));
}



/*
 * double deref: *(u32*)(*p + 0x58)
 */
u32 func_021B8748(void **p)
{
    return ((struct Obj18131 *)((u8 *)*p))->f58;
}


void func_021B8750(char *p,unsigned char k,void *m) { if((unsigned int)func_021B86B8((void ***)p)<=1 && k!=0) func_0200CFA0(((struct Obj20962 *)(*(char * *)&((struct Obj01889 *)p)->f0))->f68,func_021D5844(m)); }



u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out)
{
    u8 hi = k >> 8;
    u8 lo = k;

    if (hi == 0) {
        *out = lo;
        return *out != 6;
    }
    if (lo != 6) {
        switch ((*p)->mode) {
        case 0:
        default:
            return func_021B87E8(p, hi, lo, out);
        case 1:
            return func_021B8834(p, hi, lo, out);
        case 2:
            return func_021B88EC(p, hi, lo, out);
        case 3:
            return func_021B87E8(p, hi, lo, out);
        }
    }
    *out = 6;
    return 0;
}



u8 func_021B87E8(void *p, u32 k, u32 v, u8 *out)
{
    switch (k) {
    case 0:
    case 4:
    case 7:
    default:
        return 0;
    case 1:
    case 2:
    case 6:
        *out = func_021B8C50(p, v, 0);
        break;
    case 3:
        *out = v;
        break;
    case 5:
    case 8:
        out[0] = 0;
        out[1] = 1;
        return 2;
    }
    return 1;
}
