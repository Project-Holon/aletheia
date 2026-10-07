/*
 * file:     unit_021B6100_p04.c
 * unit:     yes
 * function: func_021B71B8, func_021B71C4, func_021B7378, func_021B7438, func_021B7448, func_021B7460
 * address:  0x021B71B8
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F868 0x0201F868 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201BD28 0x0201BD28 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_021B6C84 0x021B6C84 thumb ov173
 *   func_021B6BF8 0x021B6BF8 thumb ov173
 *   func_0201C1F4 0x0201C1F4 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   func_021B79E0 0x021B79E0 thumb ov173
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   d_021B8350 0x021B8350 data a4
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_021B74F8 0x021B74F8 thumb ov173
 */
#include "../../matched/include/Obj00544.h"
#include "../../matched/include/Obj24172.h"
#include "../../matched/include/Obj24173.h"
#include "../../matched/include/Obj10669.h"
#include "../../matched/include/Obj14314.h"
#include "../../matched/include/Obj24174.h"
#include "../../matched/include/Obj03858.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Rec;
struct U16Vec;
struct WordSet;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u32 func_0201F868(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_0201BD28(u16,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B6C84(char *,u32,u32,u32,u8);
extern u32 func_021B6BF8(char *,int,u32,u16,int,u8);
extern u32 func_0201C1F4(u16);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021B79E0(u8 *p, u16 id);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02017E1C(void *, unsigned int, unsigned int);
extern void func_0201F73C(void *, int, int, int);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_020409B4(u32);
extern int func_021B74F8(u32);
void func_021B71B8(char *p);
void func_021B71C4(char *p,int move);
void func_021B7378(char *p, u32 kind);
u16 func_021B7438(char **p);
unsigned short func_021B7448(int *p);
void func_021B7460(char *p, u32 kind);
extern const u32 d_021B8350[][11];

void func_021B71B8(char *p)
{
    func_0201F868(*(void **)(p + 0x58));
}

static inline void flush(void *win)
{
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(func_02045730(win));
}

static inline void clear(void *win)
{
    func_020456F8(win);
    func_02041B6C(func_02045730(win));
}

/*
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * abi: 6BF8 font extern widened to u32: the original forwards the full p+0x60 word without narrowing.
 */
void func_021B71C4(char *p,int move)
{
    u32 value;
    void *bank;
    int zero;
    zero=0;
    func_02043B5C(func_02045770(*(void **)(p+0x1c)),0);
    func_02043B5C(func_02045770(*(void **)(p+0x14)),0);
    func_02043B5C(func_02045770(*(void **)(p+0x18)),0);
    func_0204B3DC(*(void **)(p+0x110),0);
    if(move!=zero-2) {
        value=func_0201BD28(move,3);
        if(value<=1) func_02045CAC(*(void **)(p+0x44),0x21,*(void **)(p+0x4c));
        else func_021B6C84(p,0x1d,value,3,0);
        func_021B6BF8(p,4,*(u32 *)(p+0x60),0x440,1,0);
        value=func_0201BD28(move,4);
        if(value==0 || func_0201C1F4(move)!=0) func_02045CAC(*(void **)(p+0x44),0x21,*(void **)(p+0x4c));
        else func_021B6C84(p,0x1e,value,3,0);
        func_021B6BF8(p,5,*(u32 *)(p+0x60),0x440,1,0);
        bank=func_02045B38(0,2,0xca,79);
        func_02045CAC(bank,move,*(void **)(p+0x4c));
        func_021B6BF8(p,6,*(u32 *)(p+0x60),0x440,0,0);
        func_02045C04(bank);
        func_021B79E0((u8 *)p,move);
        func_0204B3DC(*(void **)(p+0x110),1);
        flush(*(void **)(p+0xc));
        flush(*(void **)(p+0x10));
    } else {
        clear(*(void **)(p+0xc));
        clear(*(void **)(p+0x10));
    }
    flush(*(void **)(p+0x1c));
    flush(*(void **)(p+0x14));
    flush(*(void **)(p+0x18));
}

void func_021B7378(char *p, u32 kind)
{
    void *str;
    switch (kind) {
    case 0: func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 1: func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 2: func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 3:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 4:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 5:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7448((int *)p)); break;
    case 6:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 7: func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 8:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 9: func_0201F02C(((struct Obj00544 *)p)->f48, 2, (void *)(((struct Obj24172 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f4)); break;
    case 10: func_0201EF34(((struct Obj00544 *)p)->f48, 0, func_021B7448((int *)p)); break;
    }
    str = func_02045EC0(((struct Obj00544 *)p)->f44, d_021B8350[((struct Obj24173 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f19][kind]);
    func_0201F250(((struct Obj00544 *)p)->f48, ((struct Obj00544 *)p)->f4C, str);
    func_02045808(str);
}


u16 func_021B7438(char **p)
{
    char *q = *p;

    return *(u16 *)(*(char * *)&((struct Obj10669 *)q)->f10 + (((struct Obj10669 *)q)->f16 + ((struct Obj10669 *)q)->f14) * 2);
}


unsigned short func_021B7448(int *p)
{
    int *q = *(int * *)&((struct Obj24174 *)p)->f0;

    return func_02017E1C((void *)((struct Obj14314 *)q)->f0, ((struct Obj14314 *)q)->f1B + 0x36, 0);
}

void func_021B7460(char *p, u32 kind)
{
    u32 zero;
    int speed;
    void *q;
    func_02043B5C(func_02045770(((struct Obj03858 *)p)->f20), 15);
    zero = 0;
    func_0201F73C(((struct Obj03858 *)p)->f20, 0, 1, 13);
    func_021B7378(p, kind);
    speed = func_02012FFC();
    ((struct Obj03858 *)p)->f6C = func_0201CD10(*(u32 *)&((struct Obj03858 *)p)->f20, 0, 0, ((struct Obj03858 *)p)->f4C, ((struct Obj03858 *)p)->f60, speed, ((struct Obj03858 *)p)->f64, zero, 0x4f, 0xffff, (u32)func_021B74F8);
    q = ((struct Obj03858 *)p)->f20;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}
