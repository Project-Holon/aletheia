/*
 * file:     gsync_state_p06.c
 * unit:     yes
 * function: func_021D5A60, func_021D5A7C, func_021D5AB0, func_021D5AC0, func_021D5B10, func_021D5B70, func_021D5BA0, func_021D5BA8
 * address:  0x021D5A60
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_021D97CC  0x021D97CC  thumb
 *   func_0200F7DC 0x0200F7DC thumb
 *   d_021DAC20 0x021DAC20 data a4
 *   func_02030734 0x02030734 arm
 *   func_02034714 0x02034714 arm
 *   d_021DAA40 0x021DAA40 data ov123 a1
 *   d_021DAA54 0x021DAA54 data ov123 a1
 *   g_021DAC20 0x021DAC20 data ov123 a4
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_020307B0 0x020307B0 arm
 *   func_021C5B80 0x021C5B80 arm ov114
 */
#include "../../matched/include/Obj13973.h"
#include "../../matched/include/Obj04497.h"
#include "../../matched/include/Obj22941.h"
#include "../../matched/include/Obj13974.h"
#include "../../matched/include/Obj22942.h"
#include "../../matched/include/Obj22943.h"
#include "../../matched/include/Obj10437.h"

struct Descriptor;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
extern void func_021D97CC(int, void *);
extern void func_0200F7DC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02156DE0(int a, int b);
extern u32 func_020307B0(void *p);
extern int func_021C5B80(void);
void func_021D5A60(char *p);
void func_021D5A7C(char *p);
void func_021D5AB0(u8 *p, int x);
void func_021D5AC0(void *unused, u32 mode);
char *func_021D5B10(int heap,int size);
void func_021D5B70(char *p);
int func_021D5BA0(char *p);
int func_021D5BA8(char *p);
extern u8 *d_021DAC20;
extern char d_021DAA40[], d_021DAA54[];
extern char *g_021DAC20;


void func_021D5A60(char *p)
{
    func_0201F7A8(((struct Obj13973 *)p)->f48, 2);
    func_020456F8(((struct Obj13973 *)p)->f48);
    func_02041B6C(6);
}

void func_021D5A7C(char *p){if(((struct Obj04497 *)p)->f7C){func_0202F038(((struct Obj04497 *)p)->f7C);((struct Obj04497 *)p)->f7C=0;}((struct Obj04497 *)p)->f7C=func_0202EE8C(((struct Obj04497 *)p)->f84,((struct Obj04497 *)p)->f44,15,16,((struct Obj04497 *)p)->fB0);}


/*
 * Addresses are Black-image addresses.
 */
void func_021D5AB0(u8 *p, int x)
{
    func_021D97CC(x, ((struct Obj22941 *)p)->f2C);
}


static inline u32 func_021D5AC0_next(u32 mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
        break;
    case 3:
        return mode;
    case 6:
        *(u32 *)(d_021DAC20 + 0xC8) = 1;
        break;
    case 8:
        func_0200F7DC();
        break;
    }
    return mode;
}


/*
 * 2026-10-05 (wD9r lane99): EXACT. The switch is a static inline helper that returns the mode; case 3
 *   returns from inside the switch, the other cases break to the final `return mode;`. The inline return
 *   copy into the result keeps case 3's own `b end` block until after jump-table threading (the stub at
 *   +0x26). No redundant statement and no cast: only the return-versus-break shape of case 3.
 *   Earlier lanes (D2 to D9r) tried every in-function form of case 3; all merged it with the end label.
 */
void func_021D5AC0(void *unused, u32 mode)
{
    u32 next = func_021D5AC0_next(mode);
    *(u32 *)(d_021DAC20 + 0xB0) = 1;
    *(u32 *)(d_021DAC20 + 0xB4) = next;
}

char *func_021D5B10(int heap,int size)
{
    char *p;
    p=func_02030734(heap,0xd4,1,d_021DAA40,0x88);
    if (g_021DAC20) func_02034714(d_021DAA54,0,d_021DAA54);
    g_021DAC20=p;
    ((struct Obj13974 *)p)->fB8=func_02030734(heap,size+0x40,0,d_021DAA40,0x8c);
    ((struct Obj13974 *)p)->fBC=size;
    return p;
}

void func_021D5B70(char *p){if(g_021DAC20){func_02156DE0(0,0);func_020307B0(((struct Obj22942 *)p)->fB8);func_020307B0(p);g_021DAC20=0;}}

int func_021D5BA0(char *p){return ((struct Obj22943 *)p)->fB8;}

int func_021D5BA8(char *p){if(!((struct Obj10437 *)p)->fC4){if(func_021C5B80())((struct Obj10437 *)p)->fC4=1;}return ((struct Obj10437 *)p)->fB0==0;}
