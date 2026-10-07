/*
 * file:     box2_main_p11.c
 * unit:     yes
 * function: func_021DEDD8, func_021DEF58, func_021DEF60, func_021DEF98, func_021DEFEC, func_021DEFF8
 * address:  0x021DEDD8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E88 0x02017E88 thumb
 *   func_02030734 0x02030734 arm
 *   func_020185A0 0x020185A0 thumb
 *   func_02017F08 0x02017F08 thumb
 *   func_02017EB4 0x02017EB4 thumb
 *   func_0201B268 0x0201B268 thumb
 *   func_0201B28C 0x0201B28C thumb
 *   d_021F1400 0x021F1400 data a1
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_021ECCCC  0x021ECCCC  thumb  ov170
 *   func_021ED028  0x021ED028  thumb  ov170
 *   func_021EB2A4  0x021EB2A4  thumb  ov170
 *   func_021DF11C  0x021DF11C  thumb  ov170
 *   func_021DF144  0x021DF144  thumb  ov170
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_021DF040 0x021DF040 thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj18457.h"
#include "../../matched/include/Obj18458.h"

struct Sav;
typedef struct {
    void *mon;
    unsigned short species;
    unsigned short form;
    unsigned pid;
    unsigned char cC;
    unsigned char cD;
    unsigned char cE;
    unsigned char cF;
    unsigned short item;
    unsigned char level : 7;
    unsigned char egg : 1;
    unsigned char gender : 4;
    unsigned char showgender : 1;
    unsigned char shiny : 1;
    unsigned char mark : 2;
    unsigned short moves[4];
} Summary;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern unsigned func_02017E88(void *p, unsigned id, unsigned v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern unsigned char func_020185A0(void *mon);
extern unsigned char func_02017F08(void *mon);
extern u32 func_02017EB4(void *p);
extern u32 func_0201B268(void *mon);
extern u32 func_0201B28C(void *mon);
extern u32 func_020307B0(void *p);
extern void func_021ECCCC(char *p, void **mon, int index);
extern void func_021ED028(char *p, unsigned char *q);
extern void func_021EB2A4(u8 *p, int a);
extern void func_021DF11C(char *, int);
extern void func_021DF144(int, int);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void func_021DF040(char *p);
Summary *func_021DEDD8(void *mon);
void func_021DEF58(void *s);
void func_021DEF60(char *p, int a);
int func_021DEF98(char *p, int a, unsigned b);
void func_021DEFEC(char *p, int b);
void func_021DEFF8(char *p, unsigned b);
extern const char d_021F1400[];


/*
 * Allocates the 0x1C-byte summary of a Pokemon (species, form, PID,
 * markings, level, flags, four moves); NULL for an empty slot.
 */
Summary *func_021DEDD8(void *mon)
{
    Summary *s;
    unsigned i;

    if (func_02017E88(mon, 0xA9, 0) != 0) {
        s = func_02030734(0x4C, 0x1C, 0, d_021F1400, 0xCD2);
        s->mon = mon;
        s->species = func_02017E88(mon, 5, 0);
        s->form = func_02017E88(mon, 6, 0);
        s->pid = func_02017E88(mon, 0, 0);
        s->cC = func_02017E88(mon, 0xAE, 0);
        s->cD = func_02017E88(mon, 0xAF, 0);
        s->cE = func_02017E88(mon, 0xA, 0);
        s->cF = func_020185A0(mon);
        s->item = func_02017E88(mon, 0xB, 0);
        s->level = func_02017E88(mon, 0x9E, 0);
        s->egg = (unsigned char)func_02017E88(mon, 0x4C, 0);
        if (s->egg == 0)
            s->gender = func_02017F08(mon);
        else
            s->gender = 0;
        if (func_02017EB4(mon) == 1)
            s->shiny = 1;
        else
            s->shiny = 0;
        if (func_0201B268(mon) == 1)
            s->mark = 1;
        else if (func_0201B28C(mon) == 1)
            s->mark = 2;
        else
            s->mark = 0;
        if (s->species != 0x1D && s->species != 0x20 && s->egg == 0)
            s->showgender = 1;
        else
            s->showgender = 0;
        for (i = 0; i < 4; i++)
            s->moves[i] = func_02017E88(mon, 0x36 + i, 0);
    } else {
        s = 0;
    }
    return s;
}


void func_021DEF58(void *s)
{
    func_020307B0(s);
}

/*
 * Six-step handover: stage 0xb, rebuild, refresh, push the 0x10
 *   tag word, re-tag, then release handle 3.
 */
void func_021DEF60(char *p, int a)
{
    func_021ECCCC(p, (void **)a, 0xb);
    func_021ED028((char *)(*(int *)&((struct Obj00000 *)p)->f2C), (unsigned char *)a);
    func_021EB2A4((u8 *)p, a);
    func_021DF11C(p, ((struct Obj18457 *)a)->f10);
    func_021DF144(*(int *)&((struct Obj00000 *)p)->f2C, a);
    func_02041EE4(5, 3, 0);
}

int func_021DEF98(char *p, int a, unsigned b)
{
    void *mon;
    int state;
    void *s;
    mon = (void *)func_021DD2D0((void ***)p, a, b);
    if (mon) {
        state = func_02017DBC(mon);
        s = func_021DEDD8(mon);
        if (s) {
            func_021DEF60(p, (int)s);
            func_021DEF58(s);
            func_02017DE4(mon, state);
        } else {
            func_021DF040(p);
            func_02017DE4(mon, state);
            return 0;
        }
    } else {
        func_021DF040(p);
        return 0;
    }
    return 1;
}


/*
 * Forward with the byte field at +0x14.
 */
void func_021DEFEC(char *p, int b)
{
    func_021DEF98(p, ((struct Obj18458 *)p)->f14, b);
}

/*
 * extent: final two bytes are zero alignment padding.
 */
void func_021DEFF8(char *p, unsigned b)
{
    void *mon;
    void *s;
    int state;
    mon = (void *)func_021DD2D0((void ***)p, ((struct Obj00000 *)p)->f14, b);
    state = func_02017DBC(mon);
    s = func_021DEDD8(mon);
    func_021ECCCC(p, s, 11);
    func_021ED028(((struct Obj00000 *)p)->f2C, s);
    func_021EB2A4((u8 *)p, (int)s);
    func_021DEF58(s);
    func_02017DE4(mon, state);
}
