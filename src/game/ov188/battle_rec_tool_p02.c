/*
 * file:     battle_rec_tool_p02.c
 * unit:     yes
 * function: func_021EEEA8, func_021EEED8, func_021EEF2C, func_021EEFA4
 * address:  0x021EEEA8
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EEFE4  0x021EEFE4  thumb  ov188
 *   func_021EF090  0x021EF090  thumb  ov188
 *   func_021EF1D8  0x021EF1D8  thumb  ov188
 *   func_021EF2D4  0x021EF2D4  thumb  ov188
 *   g_0214616C     0x0214616C  data
 *   func_02082BCC   0x02082BCC  arm
 *   func_0201AA14   0x0201AA14  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_021EE920   0x021EE920  thumb
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   func_0201A954 0x0201A954 thumb
 *   func_021EEBF0 0x021EEBF0 thumb ov188
 *   func_02017E40 0x02017E40 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021EF360 0x021EF360 data a4
 */
#include "../../matched/include/G_BattleRec.h"
#include "../../matched/include/Obj10803.h"
#include "../../matched/include/Obj14491.h"

struct Mon;
struct Party;
struct PartyMon;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021EEFE4(void *p, char *b, u32 c);
extern void func_021EF090(u8 *a, u8 *b);
extern int func_021EF1D8(char *p, char *a1);
extern int func_021EF2D4(u8 *a, const u8 *b);
extern void func_02082BCC(int, int, int);
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021EE920(struct Mon *p, char *q);
extern u32 func_020173EC(void);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void func_021EEBF0(char *p, struct Mon *q);
extern void func_02017E40(void *,u32,u32);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
void func_021EEEA8(void *p, u32 c);
void func_021EEED8(int a, char *p);
void func_021EEF2C(u8 *a,void *b,u32 c);
void func_021EEFA4(int *a, char *p);
extern struct BattleRec *g_0214616C;
extern char d_021EF360[];


void func_021EEEA8(void *p, u32 c)
{
    char *q = ((char *)g_0214616C) + 0xc4;

    func_021EEFE4(p, q, c);
    func_021EF090(p, (u8 *)q);
    func_021EF1D8(p, q);
    func_021EF2D4(p, (const u8 *)q);
}


/*
 * Clear a 0x2A4-byte record, copy the pair of counts out of a and release
 *   each of the 0x70-byte subrecords through 0x21EE920.
 */
void func_021EEED8(int a, char *p)
{
    int i;
    func_02082BCC((int)p, 0, 0x2A4);
    if (func_0201AA18((void *)a) == 0)
        return;
    ((struct Obj10803 *)p)->f0 = func_0201AA14((void *)a);
    ((struct Obj10803 *)p)->f2 = func_0201AA18((void *)a);
    for (i = 0; i < ((struct Obj10803 *)p)->f2; i++)
        func_021EE920((struct Mon *)((int)func_0201AB28((void *)a, i)), p + 4 + i * 0x70);
}

void func_021EEF2C(u8 *a,void *b,u32 c)
{
    int i;
    u8 *p;
    p=func_02030734((u16)((c & 0x7FFF)|0x8000),func_020173EC(),1,d_021EF360,173);
    func_0201A954(b,((struct Obj14491 *)a)->f0);
    for(i=0;i<((struct Obj14491 *)a)->f2;i++) {
        func_021EEBF0((char *)(a+4+i*112),(struct Mon *)p);
        func_02017E40(p,159,0);
        func_0201A98C(b,(const struct PartyMon *)p);
    }
    func_020307B0(p);
}


void func_021EEFA4(int *a, char *p)
{
    char *base;
    unsigned int i;
    func_02082BCC((int)(p + 0xC38), 0, 0xA90);
    base = p + 0xC38;
    for (i = 0; i < 4; i++) {
        int v = a[9 + i];
        if (v != 0)
            func_021EEED8(v, base + i * 0x2A4);
    }
}
