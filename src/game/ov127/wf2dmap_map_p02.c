/*
 * file:     wf2dmap_map_p02.c
 * unit:     yes
 * function: func_021C4954, func_021C4980, func_021C4994, func_021C499C, func_021C49A4, func_021C4A00, func_021C4A54, func_021C4A8C
 * address:  0x021C4954
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C6014 0x021C6014 data a4
 *   d_021C6010  0x021C6010  data  a1
 */
#include "../../matched/include/Obj14029.h"
#include "../../matched/include/Obj23040.h"
#include "../../matched/include/Obj00535.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

struct pair { s16 a,b; };

struct delta { signed char a,b; };

char *func_021C4954(unsigned *p, unsigned id);
char *func_021C4980(char **p, int i);
char *func_021C4994(unsigned *p,unsigned id);
char *func_021C499C(char **p,int i);
int func_021C49A4(u8 *p, unsigned int i);
void func_021C4A00(void *p, int i, int v);
struct pair func_021C4A54(struct pair p,int i);
unsigned char func_021C4A8C(int i);
extern struct delta d_021C6014;
extern unsigned char d_021C6010[];

char *func_021C4954(unsigned *p, unsigned id)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0]; char *e;
 do { e=base+i*24; if (((struct Obj14029 *)e)->f0==1 && id==((struct Obj14029 *)e)->fC) return e; i++; } while(i<p[1]); }
 return 0;
}


char *func_021C4980(char **p, int i)
{
    char *base = *p;
    char *e = base + i * 0x18;

    if (((struct Obj23040 *)e)->f0 != 1)
        return 0;
    return e;
}

char *func_021C4994(unsigned *p,unsigned id) { return func_021C4954(p,id); }

char *func_021C499C(char **p,int i) { return func_021C4980(p,i); }

/*
 * extent: two zero alignment bytes at 0x021C49FE follow the return.
 */
int func_021C49A4(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: return *(s16 *)&((struct Obj00535 *)p)->f4;
    case 1: return *(s16 *)&((struct Obj00535 *)p)->f6;
    case 2: return *(s16 *)&((struct Obj00535 *)p)->f8;
    case 3: return *(s16 *)&((struct Obj00535 *)p)->fA;
    case 4: return ((struct Obj00535 *)p)->fC;
    case 5: return p[21];
    case 6: return p[20];
    case 7: return ((struct Obj00535 *)p)->fE;
    case 8: return ((struct Obj00535 *)p)->f10;
    case 9: return ((struct Obj00535 *)p)->f12;
    case 10: return ((struct Obj00535 *)p)->f16;
    default: return (int)p;
    }
}


void func_021C4A00(void *p, int i, int v)
{
    switch (i)
    {
    case 0:
        ((struct Obj00535 *)p)->f4 = (u16)v;
        break;
    case 1:
        ((struct Obj00535 *)p)->f6 = (u16)v;
        break;
    case 2:
        ((struct Obj00535 *)p)->f8 = (u16)v;
        break;
    case 3:
        ((struct Obj00535 *)p)->fA = (u16)v;
        break;
    case 4:
        ((struct Obj00535 *)p)->fC = (u16)v;
        break;
    case 5:
        ((struct Obj00535 *)p)->f15 = (u8)v;
        break;
    case 6:
        ((struct Obj00535 *)p)->f14 = (u8)v;
        break;
    case 7:
        ((struct Obj00535 *)p)->fE = (u16)v;
        break;
    case 8:
        ((struct Obj00535 *)p)->f10 = (u16)v;
        break;
    case 9:
        ((struct Obj00535 *)p)->f12 = (u16)v;
        break;
    case 10:
        ((struct Obj00535 *)p)->f16 = (u16)v;
        break;
    default:
        break;
    }
}

struct pair func_021C4A54(struct pair p,int i)
{
 struct pair *v=&p;
 v->a += *(signed char *)((unsigned)&d_021C6014.a+i*2);
 v->b += *(signed char *)((unsigned)&d_021C6014.b+i*2);
 return p;
}


/*
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r1,[pc,#4]; ldrb r0,[r1,r0]; bx lr; nop; .word 0x021C6010
 * Byte i of the table d_021C6010.
 */
unsigned char func_021C4A8C(int i)
{
    return d_021C6010[i];
}
