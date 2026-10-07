/*
 * file:     zukan_detail_graphic_p18.c
 * unit:     yes
 * function: func_021BE920, func_021BE9C8, func_021BE9CC, func_021BEA00, func_021BEA04, func_021BEA90
 * address:  0x021BE920
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4        0x020490F4  arm
 *   func_02049BDC        0x02049BDC  arm
 *   func_02049238        0x02049238  arm
 *   func_0204384C        0x0204384C  arm
 *   func_02043814        0x02043814  arm
 *   func_020437AC        0x020437AC  arm
 *   func_02045EC0        0x02045EC0  arm
 *   func_0201C724        0x0201C724  thumb
 *   func_02045808        0x02045808  arm
 *   data_021C84F4        0x021C84F4  data
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020437D4  0x020437D4  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02034AC4 0x02034AC4 arm
 *   ov067_id 0x00000043 data
 *   ov206_id 0x000000CE data
 *   func_021BC32C 0x021BC32C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BEF9C 0x021BEF9C thumb ov208
 *   func_021BC448 0x021BC448 thumb
 *   func_021BC518 0x021BC518 thumb
 *   func_021BC508 0x021BC508 thumb
 *   func_021BF63C 0x021BF63C thumb ov208
 *   func_021BF61C 0x021BF61C thumb ov208
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_021BF41C 0x021BF41C thumb ov208
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_021BC464 0x021BC464 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   func_021BC34C 0x021BC34C thumb ov208
 *   func_02034A5C 0x02034A5C arm
 */
#include "../../matched/include/Obj03362.h"

struct Bmp;
struct Obj020437AC;
struct MsgBank;
struct U16Vec;
struct PrintSys;
struct Ov208Buf;
struct Rec;
struct Node;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Ov208Icon {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    int fc;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

struct Ov208PalTbl {
    u32 v[5];
};

typedef unsigned char  u8;

struct Ov208Scene {
    int task;
    int f4; int f8;
    void *fc;
    void *f10;
    int f14; int f18;
    char pad[0x94 - 0x1c];
    int f94; int f98;
    char pad2[0x10c - 0x9c];
    int f10c;
};

typedef signed int     s32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *h);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02041B6C(u32 layer);
extern int func_02034AC4(s32 handle);
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern int func_020056A0(void (*fn)(void *), void *arg, int n);
extern void func_021BEF9C(void *p);
extern void *func_021BC448(u32 heap);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void func_021BF63C(int,char *,unsigned);
extern void func_021BF61C(int,char *,unsigned);
extern void func_021BA2CC(char *);
extern void func_021BF41C(int,char *,unsigned);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021BC464(void *);
extern void func_02030EAC(struct Node *);
extern void func_021BC34C(char *);
extern void func_02034A5C(int);
void ov208_func_021BE920(struct Ov208Icon *p);
void func_021BE9C8(void);
void ov208_func_021BE9CC(struct Ov208Icon *p);
void ov208_func_021BEA00(u16 *p, u16 v);
int func_021BEA04(void *owner, int unused, u16 *heap);
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap);
extern const struct Ov208PalTbl data_021C84F4;
extern const char ov067_id[];
extern const char ov206_id[];


void ov208_func_021BE920(struct Ov208Icon *p)
{
    struct Ov208PalTbl pal;
    void *h;
    u32 s;

    if (p->fc < 0 || p->fc >= 5)
        return;
    h = func_020490F4(0x9f, p->heap);
    pal = data_021C84F4;
    func_02049BDC(h, 4, 4, pal.v[p->fc] << 5, 0x1a0, 0x20, p->heap);
    func_02049238(h);
    h = func_0204384C(0x9f, 0xe, 0, p->heap);
    func_02043814(h, (const struct Bmp *)p->f18);
    func_020437AC(h);
    s = (u32)func_02045EC0((struct MsgBank *)p->f24, p->fc + 0xb2);
    func_0201C724((void *)p->f2c, p->f18, 0x18, 5, s, p->f4, 0x3dc0);
    func_02045808((struct U16Vec *)s);
    p->f30 = 1;
    ov208_func_021BE9CC(p);
}

void func_021BE9C8(void)
{
}


void ov208_func_021BE9CC(struct Ov208Icon *p)
{
    if (p->f30 != 0 && func_0201C6C4((struct PrintSys *)p->f2c, (void *)p->f18) == 0) {
        func_02040B1C(5, func_020437D4((const struct Bmp *)p->f18), p->f20, p->f1c);
        func_02041B6C(5);
        p->f30 = 0;
    }
}


void ov208_func_021BEA00(u16 *p, u16 v)
{
    *p = v;
}

/*
 * 2026-10-04 (D2-16): callback func_021BEF9C filed EXACT as src/matched/ov/ov208_func_021BEF9C.c (empty void function, bx lr). Still MATCH only
 * because no shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only func_021BEF9C (task callback, no witness yet) blocks EXACT; bytes match.
 */
int func_021BEA04(void *owner, int unused, u16 *heap)
{
    struct Ov208Scene *s;
    func_02034AC4((u32)ov067_id);
    func_02034AC4((u32)ov206_id);
    s = func_021BC32C(owner, 0x120, *heap);
    func_02082BCC(s, 0, 0x120);
    s->task = func_020056A0(func_021BEF9C, s, 1);
    s->f94 = 6;
    s->f98 = 6;
    s->f10c = 0;
    s->fc = func_021BC448(*heap);
    s->f10 = func_021BC448(*heap);
    func_021BC518(s->fc);
    func_021BC518(s->f10);
    func_021BC508(0, s->fc);
    func_021BC508(1, s->f10);
    s->f14 = 0;
    s->f18 = 1;
    return 1;
}

/*
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    func_021BF63C(owner,q,heap);func_021BF61C(owner,q,heap);
    func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f8);func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f4);
    func_021BF41C(owner,q,heap);
    func_0201D83C(((struct Obj03362 *)q)->f110);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f11C);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f118);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f114);
    func_021BC464(((struct Obj03362 *)q)->f10);func_021BC464(((struct Obj03362 *)q)->fC);
    func_02030EAC(*(struct Node * *)&((struct Obj03362 *)q)->f0);func_021BC34C(first);
    func_02034A5C((int)ov206_id);func_02034A5C((int)ov067_id);return 1;
}
