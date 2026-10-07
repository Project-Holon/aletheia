/*
 * file:     comm_player_p22.c
 * unit:     yes
 * function: func_02169510, func_02169520, func_02169528, func_02169530, func_02169538, func_02169540, func_02169550, func_02169560, func_02169568, func_02169578, func_02169580, func_02169598
 * address:  0x02169510
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02046C9C  0x02046C9C  arm
 *   func_02046C9C 0x02046C9C arm
 *   func_02169A68  0x02169A68  thumb  ov010
 *   func_02169928  0x02169928  thumb  ov010
 */
#include "../../matched/include/Obj17744.h"
#include "../../matched/include/Obj19043.h"
#include "../../matched/include/Obj19045.h"
#include "../../matched/include/Obj19047.h"
#include "../../matched/include/Obj00281.h"
#include "../../matched/include/Obj00306.h"
#include "../../matched/include/Obj19049.h"
#include "../../matched/include/Obj17745.h"

struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct V3 {
    u32 a, b, c;
} V3;

typedef signed short   s16;

extern void sub_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern void func_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern void *func_02169A68(int a0);
extern int func_02169928();
void func_02169510(u8 *src, V3 *dst);
int func_02169520(int a0, int a1);
void func_02169528(unsigned char *a, int *out);
void func_02169530(unsigned char *a, int *out);
void func_02169538(unsigned char *a, int *out);
void func_02169540(unsigned char *a, unsigned int v);
void func_02169550(char *p);
int func_02169560(unsigned char *a);
void func_02169568(char *p);
int func_02169578(unsigned char *a);
int func_02169580(int a0);
u32 func_02169598(u8 *p);


/*
 * Unlabelled leaf (blocker of ov021 func_0218C724).  Copies the 12 bytes
 * at src+4 to dst.
 */
void func_02169510(u8 *src, V3 *dst)
{
    *dst = *(V3 *)(src + 4);
}




int func_02169520(int a0, int a1)
{

a0 = a0 + 0xb0;
((struct Obj17744 *)((char *)a1))->f0 = a0;
    return a0;}


/*
 * Unlabelled leaf accessor: copies the word at +0xD4 to *out.
 *
 * Addresses are Black-image addresses.
 */
void func_02169528(unsigned char *a, int *out)
{
    *out = ((struct Obj19043 *)a)->fD4;
}


/*
 * Unlabelled leaf accessor: copies the word at +0x14 to *out.
 *
 * Addresses are Black-image addresses.
 */
void func_02169530(unsigned char *a, int *out)
{
    *out = ((struct Obj19045 *)a)->f14;
}


/*
 * Unlabelled leaf accessor: copies the word at +0xBC to *out.
 *
 * Addresses are Black-image addresses.
 */
void func_02169538(unsigned char *a, int *out)
{
    *out = ((struct Obj19047 *)a)->fBC;
}


/*
 * Unlabelled leaf: tail call initialising the record at +0x84 in mode 1.
 *
 * Addresses are Black-image addresses.
 */
void func_02169540(unsigned char *a, unsigned int v)
{
    sub_02046C9C(((struct Obj00281 *)a)->f84, 1, v);
}

void func_02169550(char *p) { func_02046C9C(((struct Obj00306 *)p)->f84, 1, 0); }


/*
 * Unlabelled leaf accessor: returns the word at +0x84.
 *
 * Addresses are Black-image addresses.
 */
int func_02169560(unsigned char *a)
{
    return ((struct Obj19049 *)a)->f84;
}

void func_02169568(char *p) { func_02046C9C(((struct Obj00306 *)p)->f88, 2, 0); }


/*
 * Unlabelled leaf: forwarding tail call to func_02169A68.
 *
 * Addresses are Black-image addresses.
 */
int func_02169578(unsigned char *a)
{
    return (int)func_02169A68((int)a);
}


int func_02169580(int a0)
{
    int a1;
    int a2;
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_02169A68(a0);
loc_02169588:
a0 = ((struct Obj00281 *)t4)->f2C;
t4 = t4 + 0x84;
a1 = ((struct Obj00281 *)((char *)t4))->f0;
    a0 = func_02169928(a0, a1, p);
loc_02169594:
    return a0;}



/*
 * Reads the word field at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02169598(u8 *p)
{
    return ((struct Obj17745 *)p)->f2C;
}
