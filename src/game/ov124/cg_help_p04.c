/*
 * file:     cg_help_p04.c
 * unit:     yes
 * function: func_021D4940, func_021D49C8, func_021D4B14, func_021D4B84
 * address:  0x021D4940
 * region:   ov124
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02030734 0x02030734 arm
 *   func_02041090 0x02041090 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B908 0x0204B908 arm
 *   d_021D4CF4 0x021D4CF4 data a4
 *   d_021D4CA4 0x021D4CA4 data a4
 *   d_021D4D4C 0x021D4D4C data a1
 *   d_021D4C04 0x021D4C04 data a4
 *   d_021D4BE0 0x021D4BE0 data a2
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_0203630C 0x0203630C arm
 *   func_0200854C 0x0200854C thumb
 *   func_021D4240 0x021D4240 thumb ov124
 *   func_021D4280 0x021D4280 thumb ov124
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../matched/include/Obj00068.h"
#include "../../matched/include/Obj00122.h"
#include "../../matched/include/Obj22993.h"
#include "../../matched/include/Obj00991.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct Obj;
struct Vec2;
struct Obj0203159C;
struct Sub0200852CObj;
struct S020315D4;
typedef short s16;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct { s16 x, y; } Vec;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_02061CA4(void *, u32, u32, int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B908(int a0, int a1);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_0200846C(int a0);
extern unsigned int func_0203630C(void);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_021D4240(char *);
extern void func_021D4280(char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
void func_021D4940(char *p,int n);
void func_021D49C8(char *p, u32 n);
int func_021D4B14(void *a,int b,void *c);
int func_021D4B84(struct S020315D4 *task,int b,int keep,char *p);
extern const u32 d_021D4CF4[], d_021D4CA4[], d_021D4C04[];
extern const char d_021D4D4C[];
extern const Vec d_021D4BE0;

void func_021D4940(char *p,int n)
{
    void *q;
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f24),1);
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f20),0);
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    func_0201C724(((struct Obj00068 *)p)->f30,(u32)func_02045770(((struct Obj00068 *)p)->f24),40,8,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    func_02045808(q);
    n += 12;
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    func_0201C724(((struct Obj00068 *)p)->f30,(u32)func_02045770(((struct Obj00068 *)p)->f20),0,0,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    func_02045808(q);
    ((struct Obj00068 *)p)->f1C = 1;
}

/*
 * lever: the two-halfword delta is a struct assignment; field stores differ by 13 bytes.
 */
void func_021D49C8(char *p, u32 n)
{
    u16 *q;
    u8 i, j;
    Vec delta;
    func_0204B878(((struct Obj00122 *)p)->f5C, d_021D4CF4[n]);
    func_0204B3DC(((struct Obj00122 *)p)->f5C, 1);
    if (n <= 7) {
        func_02061CA4((void *)31, 320, (u32)(*(char * *)&((struct Obj22993 *)(*(char * *)&((struct Obj00122 *)p)->f48))->fC + d_021D4CA4[n] * 32), 32);
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2ac);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i * 4 + j] = j + d_021D4C04[n] + i * 32 + 0xa000;
            }
        }
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    } else {
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2bb);
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    }
    func_020409B4(4);
    delta = d_021D4BE0;
    func_0204B404(((struct Obj00122 *)p)->f5C, (const struct Vec2 *)(&delta), 1);
    if (n == 10) {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 0);
        func_0204B908((int)(((struct Obj00122 *)p)->f5C), 1);
    } else if (n == 11) {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 0);
        func_0204B908((int)(((struct Obj00122 *)p)->f5C), 0);
    } else {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 1);
    }
}

int func_021D4B14(void *a,int b,void *c)
{
    char *p;
    void **q;
    func_0203064C(1,0x8a,0x60000);
    p = func_0203159C(a,0x60,0x8a);
    q = c;
    if (!q) {
        q = func_02030734(0x8a,8,1,d_021D4D4C,0x2f3);
        *q = func_0200846C(0x8a);
        if (func_0203630C() & 0x100) func_0200854C(*q,1);
        else func_0200854C(*q,0);
    }
    ((struct Obj00068 *)p)->f4 = q;
    ((struct Obj00068 *)p)->f0 = 0x8a;
    func_021D4240(p);
    return 1;
}

int func_021D4B84(struct S020315D4 *task,int b,int keep,char *p) {func_021D4280(p);if(keep==0){func_020307B0(**(void ** *)&((struct Obj00991 *)p)->f4);func_020307B0(((struct Obj00991 *)p)->f4);}func_020315D4(task);func_020306F0(0x8a);return 1;}
