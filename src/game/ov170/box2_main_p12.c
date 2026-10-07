/*
 * file:     box2_main_p12.c
 * unit:     yes
 * function: func_021DF040, func_021DF0BC, func_021DF0D4, func_021DF110, func_021DF11C, func_021DF128, func_021DF144
 * address:  0x021DF040
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
 *   func_021EC000 0x021EC000 thumb
 *   func_021EB324 0x021EB324 thumb
 *   func_02041EE4 0x02041EE4 arm
 *   func_021ED6E4  0x021ED6E4  thumb  ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 */
#include "../../matched/include/Obj14263.h"

#define WORK(p) (*(char **)((p) + 0x2C))
struct Bank;
struct CharBuf;
struct Descriptor;
struct Rec;
struct Node;
struct Blk37;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    char pad[18];
    unsigned char level:7;
    unsigned char egg:1;
    unsigned char gender:4;
    unsigned char showgender:1;
    unsigned char shiny:1;
    unsigned char mark:2;
} Summary;

extern void func_021EC000(char *p, int i, int v);
extern void func_021EB324(char *w);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBFA8(char *p, int i, int v);
void func_021DF040(char *p);
void func_021DF0BC(unsigned char *p);
void func_021DF0D4(char *p,int base,u32 bits);
void func_021DF110(char *p, int b);
void func_021DF11C(char *p, int b);
void func_021DF128(int p);
void func_021DF144(char *w, Summary *s);


void func_021DF040(char *p)
{
    unsigned i;
    if (*(int *)(WORK(p) + 0x9EA0) != 0)
        func_021EC000(WORK(p), 0xB, 0);
    if (*(int *)(WORK(p) + 0x9EA4) != 0)
        func_021EC000(WORK(p), 0xC, 0);
    for (i = 0x1C; i < 0x2D; i++)
        func_021EC000(WORK(p), i, 0);
    func_021EB324(WORK(p));
    func_021DF128((int)WORK(p));
    func_021EC000(WORK(p), 0x19, 0);
    func_021EC000(WORK(p), 0x1A, 0);
    func_021EC000(WORK(p), 0x1B, 0);
    func_02041EE4(5, 3, 0xC0);
}

/*
 * Reset, clear the state, mark the 0x16 field.
 */
void func_021DF0BC(unsigned char *p)
{
    func_021DF040((char *)p);
    func_021ED6E4((char **)p, 0);
    p[0x16] = 0xff;
}

void func_021DF0D4(char *p,int base,u32 bits) { u16 i,v;for(i=0;i<6;i++){if(bits & (1<<i))v=i*2+1;else v=i*2;func_021EBFA8(*(char * *)&((struct Obj14263 *)p)->f2C,base+i,v);func_021EC000(*(char * *)&((struct Obj14263 *)p)->f2C,base+i,1);} }


void func_021DF110(char *p, int b)
{
    func_021DF0D4(p, 0xd, b);
}


/*
 * Forward with index 19.
 */
void func_021DF11C(char *p, int b)
{
    func_021DF0D4(p, 0x13, b);
}

/*
 * Seat the six 0x13 entries.
 */
void func_021DF128(int p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_021EC000((char *)p, i + 0x13, 0);
}

void func_021DF144(char *w, Summary *s)
{
    if (s->shiny == 0 || s->egg == 1)
        func_021EC000(w, 25, 0);
    else
        func_021EC000(w, 25, 1);
    if (s->mark == 0) {
        func_021EC000(w, 26, 0);
        func_021EC000(w, 27, 0);
    } else if (s->mark == 1) {
        func_021EC000(w, 26, 0);
        func_021EC000(w, 27, 1);
    } else {
        func_021EC000(w, 26, 1);
        func_021EC000(w, 27, 0);
    }
}
