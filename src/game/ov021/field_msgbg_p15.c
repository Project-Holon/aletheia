/*
 * file:     field_msgbg_p15.c
 * unit:     yes
 * function: func_0218BD24, func_0218BD28, func_0218BD94
 * address:  0x0218BD24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0218BEE8  0x0218BEE8  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_0218BF84  0x0218BF84  thumb  ov021
 */
#include "../../matched/include/Obj17895.h"
#include "../../matched/include/Obj01114.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    unsigned short heap;
    unsigned char pad[0x1AA];
    unsigned short n;
    unsigned char pad2[0x1A];
    unsigned int count;
    unsigned char *ents;
} S;

void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, unsigned short tag);
void func_0218BEE8(S *p, unsigned char *e, int i, int arg);
extern u32 func_020307B0(void *p);
extern void func_0218BF84(void *p);
u8 func_0218BD24(u8 *p);
void func_0218BD28(S *p, int arg);
void func_0218BD94(u8 *s);
extern unsigned char d_021DD9CC[];


/*
 * Loads the byte at +0xc of the object.
 */
u8 func_0218BD24(u8 *p)
{
    return ((struct Obj17895 *)p)->fC;
}


void func_0218BD28(S *p, int arg)
{
    unsigned short n = p->n;
    unsigned char i;
    if (n != 0) {
        p->count = n;
        p->ents = func_02030734(p->heap, n * 0x18, 1, (const char *)d_021DD9CC, 0x45F);
        for (i = 0; i < p->count; i++)
            func_0218BEE8(p, p->ents + i * 0x18, i, arg);
    }
}


void func_0218BD94(u8 *s)
{
    u32 i;

    if (*(u8 * *)&((struct Obj01114 *)s)->f1CC != 0) {
        for (i = 0; i < ((struct Obj01114 *)s)->f1C8; i++)
            func_0218BF84(*(u8 * *)&((struct Obj01114 *)s)->f1CC + i * 0x18);
        func_020307B0(*(u8 * *)&((struct Obj01114 *)s)->f1CC);
        ((struct Obj01114 *)s)->f1C8 = 0;
        *(u8 * *)&((struct Obj01114 *)s)->f1CC = 0;
    }
}
