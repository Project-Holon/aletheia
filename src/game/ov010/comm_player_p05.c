/*
 * file:     comm_player_p05.c
 * unit:     yes
 * function: func_0216932C, func_02169354, func_0216937C, func_021693A0, func_021693B4, func_021693BC, func_021693C4, func_021693CC, func_021693D4, func_0216940C, func_02169444, func_02169470, func_021694D4, func_021694F8, func_021694FC, func_02169500, func_02169510, func_02169520, func_02169528, func_02169530, func_02169538, func_02169540, func_02169550, func_02169560, func_02169568, func_02169578, func_02169580, func_02169598
 * address:  0x0216932C
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
 *   func_02169308  0x02169308  thumb  ov010
 *   func_0216968C  0x0216968C  thumb  ov010
 *   func_02169710  0x02169710  thumb  ov010
 *   func_0216990C 0x0216990C thumb ov010
 *   func_020490F4 0x020490F4 arm
 *   func_02049238  0x02049238  arm
 *   func_02169998  0x02169998  thumb  ov010
 *   func_02169880  0x02169880  thumb  ov010
 *   func_0204944C  0x0204944C  arm
 *   func_0216959C  0x0216959C  thumb  ov010
 *   sub_02046C9C  0x02046C9C  arm
 *   func_02046C9C 0x02046C9C arm
 *   func_02169A68  0x02169A68  thumb  ov010
 *   func_02169928  0x02169928  thumb  ov010
 */
#include "../../matched/include/Obj04162.h"
#include "../../matched/include/Obj03541.h"
#include "../../matched/include/Obj00306.h"
#include "../../matched/include/Obj19036.h"
#include "../../matched/include/Obj12053.h"
#include "../../matched/include/Obj19037.h"
#include "../../matched/include/Obj19038.h"
#include "../../matched/include/Obj19039.h"
#include "../../matched/include/Obj19040.h"
#include "../../matched/include/Obj05901.h"
#include "../../matched/include/Obj12385.h"
#include "../../matched/include/Obj17742.h"
#include "../../matched/include/Obj17743.h"
#include "../../matched/include/Obj17744.h"
#include "../../matched/include/Obj19043.h"
#include "../../matched/include/Obj19045.h"
#include "../../matched/include/Obj19047.h"
#include "../../matched/include/Obj00281.h"
#include "../../matched/include/Obj19049.h"
#include "../../matched/include/Obj17745.h"

struct ArcFile;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct V3 {
    u32 a, b, c;
} V3;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
u32 f0;
u32 f4;
u32 f8;
u32 fc;
u16 f10;
u16 pad;
} Entry;

typedef struct {
u8 pad0[0x9c];
Entry *table;
u32 f_a0;
u16 count;
} Obj;

typedef struct E
{
  int key;
  int a;
  int b;
  int c;
} E;

typedef struct S12 { u32 a, b, c; } S12;

extern int func_02169308();
extern int func_0216968C(u8 *p);
extern int func_02169710();
extern void func_0216990C(u8 *);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *arc);
extern int func_02169998(int a0, int a1);
extern void func_02169880(u8 *p);
extern void func_0204944C(struct ArcFile *h, u32 b, u32 c, u32 d, void *out);
extern void func_0216959C(u8 *p);
extern void sub_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern void func_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern void *func_02169A68(int a0);
extern int func_02169928();
int func_0216932C(int a0);
int func_02169354(int a0, int a1);
void func_0216937C(u8 *p,int a,int b);
void func_021693A0(int a0);
void func_021693B4(char *p, int v);
void func_021693BC(char *p);
void func_021693C4(char *p, int v);
void func_021693CC(char *p);
void func_021693D4(u8 *base, u8 *src, u32 idx);
void func_0216940C(Obj *o, u32 i);
u32 *func_02169444(u8 *base, u32 idx);
void func_02169470(u8 *p, u32 b);
void func_021694D4(u8 *p, int a1);
void func_021694F8(u8 *p, u16 v);
u16 func_021694FC(u8 *p);
void func_02169500(u8 *p, u8 *q);
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







int func_0216932C(int a0)
{
    int a1;
    int v0;
    int t4;
    int t5;
t5 = a0 + 0;
a0 = 1;
((struct Obj04162 *)t5)->f2 = a0;
t4 = (int)&v0;
loc_02169336:
a0 = t5 + 0;
    a0 = func_02169308(a0);
loc_0216933C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02169520(a0, a1);
loc_02169344:
    a0 = v0;
a0 = ((struct Obj04162 *)((char *)a0))->f0;
    if (a0 != 0) goto loc_02169336;
loc_0216934C:
a0 = 0;
((struct Obj04162 *)t5)->f2 = a0;
    return a0;
}







int func_02169354(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = func_0216968C((u8 *)a0);
loc_02169360:
    if (a0 != 1) goto loc_02169378;
loc_02169364:
a0 = t5 + 0;
a0 = a0 + 0x98;
a0 = ((struct Obj03541 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_02169376;
loc_0216936E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02169710(a0, a1);
loc_02169376:
t4 = 1;
loc_02169378:
a0 = t4 + 0;
    return a0;}






void func_0216937C(u8 *p,int a,int b) { func_0216990C(p); func_021693A0((int)p); ((struct Obj19036 *)(*(u8 * *)&((struct Obj00306 *)p)->f2C))->f4=0; ((struct Obj00306 *)p)->f10=func_020490F4(a,b); }







void func_021693A0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12053 *)t4)->f10;
    if (a0 == 0) goto loc_021693B2;
loc_021693AA:
    func_02049238((void *)a0);
loc_021693AE:
a0 = 0;
((struct Obj12053 *)t4)->f10 = a0;
loc_021693B2:
    return;}







/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218CEE4.
 */
void func_021693B4(char *p, int v)
{
    ((struct Obj19037 *)p)->f94 = v;
}







/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218D05C.
 */
void func_021693BC(char *p)
{
    ((struct Obj19038 *)p)->f94 = 0;
}







void func_021693C4(char *p, int v)
{
    ((struct Obj19039 *)p)->f98 = v;
}







void func_021693CC(char *p)
{
    ((struct Obj19040 *)p)->f98 = 0;
}







/*
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Stores a 0x14-byte
 * record (word, 12 bytes, halfword) into entry idx of the table at +0x9C.
 */
void func_021693D4(u8 *base, u8 *src, u32 idx)
{
    *(u32 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14) = ((struct Obj12385 *)src)->f0;
    *(V3 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14 + 4) = *(V3 *)(src + 4);
    *(u16 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14 + 0x10) = ((struct Obj12385 *)src)->f10;
}







/*
 * Reset the 0x14-byte entry `i` of the table at +0x9c.
 *
 * Addresses are Black-image addresses.
 */
void func_0216940C(Obj *o, u32 i)
{
Entry *e;
if (i == 0xffffffff)
return;
if (i >= o->count)
return;
o->table[i].f0 = 0xffffffff;
e = &o->table[i];
e->f4 = 0;
e->f8 = 0;
e->fc = 0;
*(u16 *)((u8 *)&o->table[i] + 0x10) = 0;
}





/*
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Returns the 0x14-byte
 * entry idx of the table at +0x9C, or 0 if idx is out of range or the
 * entry is unused (first word -1).
 */
u32 *func_02169444(u8 *base, u32 idx)
{
    u32 *e;

    if (idx >= ((struct Obj05901 *)base)->fA4)
        return 0;
    e = (u32 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14);
    if (e[0] == -1)
        return 0;
    return e;
}



inline static int Find(const u16 *pv, const E *tbl)
{
  unsigned i;
  i = 0;
  while (tbl[i].key != (-1))
  {
    if ((*pv) == tbl[i].key)
      break;
    i++;
  }

  return i;
}



/*
 * lever: initialized table-read temporary in the once-only budget-300 permuter
 * gives table r1 and sentinel r0; validation agrees with all five relocations.
 */
void func_02169470(u8 *p, u32 b)
{
  u16 v;
  const E *tbl;
  int i;
  E *tmp;
  func_02169998((int)(*((void **) (p + 0x2c))), b);
  func_02169550((char *)p);
  func_02169568((char *)p);
  func_02169880(p);
  *((u32 *) (p + 0x14)) = b;
  func_0204944C((struct ArcFile *)*((u32 *) (p + 0x10)), b, 0, 2, &v);
  tmp = *((E **) (p + 0x28));
  tbl = *((E **) (p + 0x28));
  i = Find(&v, tmp);
  tbl = tbl;
  *((int *) (p + 0x18)) = i;
  *((u16 *) (p + 0xb0)) = 1;
}




void func_021694D4(u8 *p, int a1)
{
    func_02169998((int)(*((void **)(p + 0x2c))), a1);
    func_02169550((char *)p);
    func_02169568((char *)p);
    func_0216959C(p);
    func_0216990C(p);
}






/*
 * Stores the halfword at p.
 *
 * Addresses are Black-image addresses.
 */
void func_021694F8(u8 *p, u16 v)
{
    ((struct Obj17742 *)p)->f0 = v;
}






/*
 * Reads the halfword at p.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021694FC(u8 *p)
{
    return ((struct Obj17743 *)p)->f0;
}






/*
 * Copies a 12-byte record from q into p + 0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_02169500(u8 *p, u8 *q)
{
    *(S12 *)(p + 0x4) = *(S12 *)q;
}



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
