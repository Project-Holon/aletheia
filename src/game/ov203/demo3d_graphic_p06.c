/*
 * file:     demo3d_graphic_p06.c
 * unit:     yes
 * function: func_021BE7A8, func_021BE7BC, func_021BE7D8, func_021BE7F0, func_021BE85C, func_021BE874, func_021BE8F4, func_021BE920, func_021BE938, func_021BE948, func_021BE990
 * address:  0x021BE7A8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE79C  0x021BE79C  thumb  ov203
 *   d_021C185C  0x021C185C  data
 *   d_021C186C 0x021C186C data a4
 *   func_02030734 0x02030734 arm
 *   d_021C3CF0 0x021C3CF0 data a1
 *   d_021C0348 0x021C0348 data a4
 *   func_020307B0 0x020307B0 arm
 *   d_021C1868 0x021C1868 data a4
 *   d_021C1860  0x021C1860  data
 */
#include "../../matched/include/Obj14588.h"
#include "../../matched/include/Obj25319.h"
#include "../../matched/include/Obj14590.h"
#include "../../matched/include/Obj08376.h"
#include "../../matched/include/Obj08377.h"
#include "../../matched/include/Obj25320.h"
#include "../../matched/include/Obj10863.h"

struct Owner;
struct TcblNode;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Config {unsigned words[11];} Config;

typedef struct Entry { int x; unsigned short id, pad; int flag; } Entry;

typedef struct Pair { const unsigned short *ids; unsigned count; } Pair;

typedef struct Group { const Pair *pairs; unsigned count; } Group;

typedef struct Selector { const Group *groups; unsigned short count, selector; } Selector;

typedef struct Row { const Selector *selectors; unsigned words[4]; } Row;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} bf_021BE920;

typedef struct Flags { unsigned short doubled:1; unsigned short rest:15; } Flags;

extern u32 func_021BE79C(u32 id);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
u32 func_021BE7A8(u32 id);
void func_021BE7BC(u32 a, u32 b, u32 c);
u8 func_021BE7D8(unsigned x);
void *func_021BE7F0(unsigned heap);
void func_021BE85C(char *a);
void func_021BE874(char *ctx, const char *config, u8 type);
void * func_021BE8F4(char *p,u8 *q);
u32 func_021BE920(u32 a);
int func_021BE938(void *a);
void func_021BE948(void *ctx, int mode, unsigned char *width, unsigned char *height);
u32 func_021BE990(u32 id);
extern u8 d_021C185C[];
extern char d_021C186C[];
extern const char d_021C3CF0[];
extern unsigned d_021C0348[];
extern const Row d_021C1868[];
extern u8 d_021C1860[];


u32 func_021BE7A8(u32 id)
{
    return *(u32 *)(d_021C185C + func_021BE79C(id) * 0x14);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BE7BC(u32 a, u32 b, u32 c)
{
    u16 *t = (u16 *)func_021BE7A8(a);

    func_02011510(b, 0xa0, *t, c);
}

u8 func_021BE7D8(unsigned x) { return *(u32 *)(d_021C186C+func_021BE79C(x)*20); }

void *func_021BE7F0(unsigned heap)
{
    char *ctx;
    Entry *entries;
    char *extra;
    int i;
    ctx = func_02030734(heap, 16, 1, d_021C3CF0, 0xab);
    entries = func_02030734(heap, 72, 1, d_021C3CF0, 0xac);
    extra = func_02030734(heap, 16, 1, d_021C3CF0, 0xad);
    for (i = 0; i < 6; i++) {
        entries[i].x = 160;
        entries[i].flag = 0;
    }
    ((struct Obj25319 *)extra)->f8 = d_021C0348;
    *(Entry * *)&((struct Obj14588 *)ctx)->f0 = entries;
    *(char * *)&((struct Obj14588 *)ctx)->f8 = extra;
    return ctx;
}


void func_021BE85C(char *a)
{
    func_020307B0((void *)((struct Obj14590 *)a)->f8);
    func_020307B0((void *)((struct Obj14590 *)a)->f0);
    func_020307B0(a);
}

void func_021BE874(char *ctx, const char *config, u8 type)
{
    Entry *entries = *(Entry * *)&((struct Obj08376 *)ctx)->f0;
    char *extra = *(char * *)&((struct Obj08376 *)ctx)->f8;
    unsigned choice = 0;
    const Group *group;
    int i;
    const Pair *pair;
    group = func_021BE8F4((char *)(&d_021C1868[*(unsigned *)config].selectors[type]), (u8 *)config);
    if (group->count > 1) choice = *(const unsigned char *)&((struct Obj08377 *)config)->f9;
    if (choice >= group->count) choice = 0;
    pair = &group->pairs[choice];
    ((struct Obj08376 *)ctx)->f4 = pair->count;
    for (i = 0; i < 6; i++) {
        if (i < pair->count) entries[i].id = pair->ids[i];
        else entries[i].id = 0;
    }
    ((struct Obj08376 *)ctx)->fC = 1;
    ((struct Obj25320 *)extra)->fC = pair->count - 1;
}


void * func_021BE8F4(char *p,u8 *q) { int x=0;switch(((struct Obj10863 *)p)->f6){case 1:x=q[10];break;case 2:x=q[8];break;case 3:x=q[13];break;}if(x>=((struct Obj10863 *)p)->f4)x=0;return (void *)(((struct Obj10863 *)p)->f0+x*8); }


/*
 * The width-1 bitfield must sit at bit 0 (`b0:1`), not bit 15: the original
 * extracts with the equal shift pair `lsls #0x1f / lsrs #0x1f`, so it is the
 * low bit of the halfword at +6 that is shifted by 0x1000.
 * Addresses are Black-image addresses.
 */
u32 func_021BE920(u32 a)
{
    bf_021BE920 *p = (bf_021BE920 *)(func_021BE7A8(a) + 6);

    return 0x1000 >> p->b0;
}


int func_021BE938(void *a)
{
    unsigned int v = *(unsigned short *)(func_021BE7A8((u32)a) + 6);
    return (v << 30) >> 31;
}

void func_021BE948(void *ctx, int mode, unsigned char *width, unsigned char *height)
{
    unsigned char *record = (unsigned char *)func_021BE7A8((u32)ctx);
    if (mode == 0) {
        *width = record[0x4e];
        *height = record[0x4f] * (((Flags *)(record + 6))->doubled + 1);
    } else {
        *width = record[0x50];
        *height = record[0x51] * (((Flags *)(record + 6))->doubled + 1);
    }
}


/*
 * closed: dropping the contested ov203 token lets the function's own region
 * pick the object; the +0010 ABS32 resolves as sole-ref/data and the file is
 * EXACT.  See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 * Addresses are Black-image addresses.
 */
u32 func_021BE990(u32 id)
{
    return *(u32 *)(d_021C1860 + func_021BE79C(id) * 0x14);
}
