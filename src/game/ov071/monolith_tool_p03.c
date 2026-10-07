/*
 * file:     monolith_tool_p03.c
 * unit:     yes
 * function: func_021B6624, func_021B6644, func_021B677C, func_021B6790, func_021B6808, func_021B6844, func_021B68B4, func_021B68E0, func_021B6960
 * address:  0x021B6624
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02021660  0x02021660  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020216B4  0x020216B4  thumb
 *   func_020498F4  0x020498F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02027634  0x02027634  thumb
 *   func_02049238  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BA7D4     0x021BA7D4  data  a4
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_02025318  0x02025318  thumb
 *   func_02025538  0x02025538  thumb
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02025588 0x02025588 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02025358 0x02025358 thumb
 *   func_02025470  0x02025470  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020254BC  0x020254BC  thumb
 *   func_02025518 0x02025518 thumb
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../../matched/include/Obj02419.h"
#include "../../matched/include/Obj09885.h"

struct PalAnmSlot;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct WordSet;
struct Rec;
struct PrintSys;
struct S02031140;
struct Bank;
struct Cfg;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

struct S6844 {
    int w0, w4;
    u8 b8, b9, ba, bb;
    int wc;
    u16 h10, h12, h14, h16;
    int w18;
};

struct W6844 {
    int w0;
    u8 *unk_04;
    int pad_08[3];
    void *unk_14;
    int pad_18[5];
    void *unk_2c;
};

typedef signed int     s32;

typedef enum { SLOT_FIRST, SLOT_COUNT = 2 } Slot;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32);
extern void func_02021660(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern void func_02027634(void *arc, int id, u32 heap, int base, u32 pal);
extern void func_02049238(void *a);
extern void func_020409B4(u32 a);
extern void func_0203FB44(u32, u32, u32);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_02025588(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02025358(void *);
extern void func_02025518(u32, u32, u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
void func_021B6624(void);
void func_021B6644(void *a, void *b);
void func_021B677C(u32 *p);
void func_021B6790(int *p);
void func_021B6808(void **p);
void func_021B6844(struct W6844 *p);
void func_021B68B4(void **p);
void func_021B68E0(int *p);
void func_021B6960(u32 *p);
extern struct S6844 d_020A1448;
extern char d_021BA7D4;

void func_021B6624(void)
{
    func_02040588(3, 0);
    func_02040588(7, 0);
    func_020403F4(3);
    func_020403F4(7);
}


void func_021B6644(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    func_02021660(((struct Obj02419 *)r5)->f0, (void *)(*(u32 *)&((struct Obj02419 *)r5)->f30), 0x10, 0x61, 0, 0x1c0, 0, 0);
    func_02021660(((struct Obj02419 *)r5)->f0, (void *)(*(u32 *)&((struct Obj02419 *)r5)->f30), 0x11, 0x61, 1, 0x1c0, 0, 0);
    func_02049658(((struct Obj02419 *)r5)->f30, 0xf, 3, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj02419 *)r5)->f30, 0xa, 3, 0, 0, 1, 0x61);
    func_02049658(((struct Obj02419 *)r5)->f30, 0xe, 7, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj02419 *)r5)->f30, 4, 7, 0, 0, 1, 0x61);
    func_020215EC(((struct Obj02419 *)r5)->f0, 0x17, 5, 0x61, 0, 0, 0xd0, 0);
    func_020215EC(((struct Obj02419 *)r5)->f0, 0x17, 5, 0x61, 1, 0, 0xd0, 0);
    h = func_020490F4(0x53, 0x61);
    ((struct Obj09885 *)d)->f138 = (void *)func_0203FA08(7, 0x80, 1);
    func_02049658(h, 0x1c, 7, (u32)(((struct Obj09885 *)d)->f138), 0x80, 0, 0x61);
    func_02027634(h, 7, 0x61, (int)(((struct Obj09885 *)d)->f138), 0xc);
    func_020216B4(((struct Obj02419 *)r5)->f0, h, 0x1b, 0x61, 1, 0x20, 0xc0);
    func_02049238(h);
    func_020409B4(7);
    func_020409B4(3);
    func_020409B4(7);
}

void func_021B677C(u32 *p)
{
    func_0203FB44(7, p[0x138 / 4], 0x80);
}

void func_021B6790(int *p)
{
    void func_0201DD78(u32 r, u32 g, u32 b);
    struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
    struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
    u32 func_0201C440(void *p);
    struct WordSet *func_0201EC64(u32 heap);
    struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

    func_0201DD78(0xf, 2, 0);
    p[6] = (int)func_0203101C(0x61, 0x61, 4, 0x20);
    p[3] = (int)func_0201D7EC(0x17, 0, 0, 0, 0x61);
    p[2] = func_0201C440((void *)0x61);
    p[4] = (int)func_0201EC64(0x61);
    p[7] = (int)func_02045B38(0, 2, 0x43, 0x61);
    p[8] = (int)func_02045B38(0, 2, 0xa0, 0x61);
    p[9] = (int)func_02045B38(0, 2, 0xa1, 0x61);
    p[10] = (int)func_02045B38(0, 2, 0x45, 0x61);
}

void func_021B6808(void **p)
{
    func_02045C04(p[7]);
    func_02045C04(p[8]);
    func_02045C04(p[9]);
    func_02045C04(p[10]);
    func_0201ED04(p[4]);
    func_0201C6EC(p[2]);
    func_0201C4C0(p[2]);
    func_0201D83C(p[3]);
    func_02031140(p[6]);
}

void func_021B6844(struct W6844 *p)
{
    struct S6844 s;
    void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
    struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
    void func_0204B270(struct Bank *bank);
    u8 *func_02025318(u32 a0, u8 a1, u8 a2);
    void *func_02025538(unsigned int a0, void *a1);

    s = d_020A1448;
    s.b8 = 4;
    s.b9 = 0x7c;
    s.ba = 4;
    s.bb = 0x7c;
    s.h10 = 0x60;
    s.h14 = 0x40;
    func_0204A48C((const struct Cfg *)(&s), (u32)(&d_021BA7D4), 0x61);
    p->unk_14 = func_0204B100(0x60, 0, 0x61);
    func_0204B270(p->unk_14);
    p->unk_04 = func_02025318(0x61, 0x10, 0x10);
    p->unk_2c = func_02025538(0x61, p->unk_14);
}

/*
 * split: TU confirms one image-wide witness, inside this caller; no cuts.
 * ARM9 stub: 02025358 ldr r3,[pc,#0]; bx r3; pool 020307B0.
 */
void func_021B68B4(void **p)
{
    func_020434DC(0x10, 0);
    func_02043598(0x10, 0);
    func_02025588(p[11]);
    func_0204B1CC(p[5]);
    func_0204A5AC();
    func_02025358(p[1]);
}

void func_021B68E0(int *p)
{
    void *func_020490F4(u32 id, u32 heap);
    u32 func_02025470(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
    s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
    s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
    u32 func_020254BC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
    void func_02049238(void *);
    void *tmp;
    int i;
    int flag;
    int *e;

    tmp = func_020490F4(0x17, 0x61);
    for (i = 0; i < 2; i++) {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        e = p + i * 4;
        e[16] = func_02025470(p[0], p[1], p[12], 3, flag, 3, 0x61);
        e[17] = func_0204A6C8((void *)p[12], 0, 1, flag, 0x61);
        e[18] = func_0204AF28((void *)p[12], 1, 2, 0x61);
        e[19] = func_020254BC(p[0], p[1], (u32)tmp, 5, flag, 1, 0x61);
    }
    func_02049238(tmp);
}

/*
 * extent: two-byte alignment padding at 0x021B699A.
 * Enum counter preserves the first iteration's cmp/branch.
 */
void func_021B6960(u32 *p)
{
    Slot i;
    int flag;
    u32 *e;
    i = SLOT_FIRST;
    do {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        e = p + i * 4;
        func_02025518(p[1], e[16], flag);
        func_0204A8D4(e[17]);
        func_0204AFD8(e[18]);
        func_02025518(p[1], e[19], flag);
        i++;
    } while (i < SLOT_COUNT);
}
