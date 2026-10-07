/*
 * file:     guru2_main_p23.c
 * unit:     yes
 * function: func_021E14BC, func_021E14CC, func_021E14E4, func_021E1540, func_021E1584, func_021E15DC, func_021E1604, func_021E161C, func_021E1634, func_021E168C, func_021E1694, func_021E16AC, func_021E16C0, func_021E16C4, func_021E16D8, func_021E170C, func_021E172C, func_021E1758, func_021E1768, func_021E1784, func_021E17EC, func_021E180C, func_021E1814, func_021E1830, func_021E18CC, func_021E1910, func_021E1954, func_021E1974, func_021E1988, func_021E19A4
 * address:  0x021E14BC
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021DFF20 0x021DFF20 thumb ov137
 *   func_020307B0 0x020307B0 arm
 *   d_021E2018 0x021E2018 data a4
 *   d_021E22B8 0x021E22B8 data a1
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E0634 0x021E0634 thumb ov137
 *   func_021E0980 0x021E0980 thumb ov137
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02039338 0x02039338 arm
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_021DCE00 0x021DCE00 thumb ov137
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02184180 0x02184180 thumb ov022
 *   func_0202F190 0x0202F190 thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   d_021E1F04 0x021E1F04 data a4
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 */
#include "../../matched/include/Obj23799.h"
#include "../../matched/include/Obj14251.h"
#include "../../matched/include/Obj23800.h"
#include "../../matched/include/Obj02209.h"
#include "../../matched/include/Obj10636.h"
#include "../../matched/include/Obj14254.h"
#include "../../matched/include/Obj23802.h"
#include "../../matched/include/Obj01753.h"
#include "../../matched/include/Obj23803.h"
#include "../../matched/include/Obj23806.h"
#include "../../matched/include/Obj06543.h"
#include "../../matched/include/Obj23807.h"
#include "../../matched/include/Obj03304.h"
#include "../../matched/include/Obj23808.h"
#include "../../matched/include/Obj14255.h"
#include "../../matched/include/Obj23809.h"
#include "../../matched/include/Obj23810.h"
#include "../../matched/include/Obj02497.h"
#include "../../matched/include/Obj06536.h"
#include "../../matched/include/Obj23811.h"
#include "../../matched/include/Obj23812.h"

struct Node;
struct ArcFile;
struct RecDC;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

typedef struct
{
  int active;
  int a;
  int b;
  int key;
  char rest[0xa4];
} Record_021E14E4;

typedef struct
{
  char pad[0x140];
  Record_021E14E4 records[1];
} Block;

typedef struct { int a, b; } Pair;

typedef struct { int a, b, c, d, e; } Record_021E1694;

struct Range { u16 lo, hi; };

struct Entry { unsigned count; struct Range *ranges; };

extern void func_02030EAC(struct Node *n);
extern void func_021DFF20(u8 *p, int a);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(void *, void (*)(void *, int *), void *, int);
extern void func_021E0634(u8 *p, int a);
extern void func_021E0980(char *, int);
extern u32 func_020493D4(struct ArcFile *, u32);
extern void func_0204932C(struct ArcFile *, u32, void *);
extern void func_02082BCC(void *, int, unsigned);
extern u16 func_02039338(void);
extern void *func_021DEB10(char *p);
extern int func_021841A4(unsigned char *);
extern int func_021DCE00(char *p, int i);
extern void *func_0201AB28(void *, unsigned);
extern char *func_02184180(unsigned char *p, int i);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern u32 func_0201AA18(void *p);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
extern void func_02005DE4(void *);
extern int func_02005E64(void);
extern void func_02005D90(unsigned int,unsigned short);
extern int func_02005F38(void);
extern int func_02005E9C(void);
void func_021E14BC(u8 *p);
void func_021E14CC(char *p, char *q);
void func_021E14E4(const char *p);
void func_021E1540(void *task, int *p);
void func_021E1584(char *p, int flag);
void func_021E15DC(int *p, int v);
void func_021E1604(char *p, int v);
int func_021E161C(char *p);
void *func_021E1634(char *p, u32 member, int flag);
void func_021E168C(int *p,int a);
void func_021E1694(char *p, const Record_021E1694 *q);
char *func_021E16AC(char *p);
char *func_021E16C0(char *p);
int func_021E16C4(char *p, int mask);
int func_021E16D8(const char *p);
int func_021E170C(char *p);
void func_021E172C(char *p,unsigned short *q);
void func_021E1758(char *p, int a1);
int func_021E1768(char *p, int i);
void func_021E1784(char *p, int i);
int func_021E17EC(char *p);
void func_021E180C(int *p,int a,int b);
void func_021E1814(unsigned char *p,u16 *q);
int func_021E1830(char *p, int angle, int index);
int func_021E18CC(void *p);
int func_021E1910(char *p);
int func_021E1954(char *p);
int func_021E1974(char *p);
void func_021E1988(unsigned int n);
int func_021E19A4(void);
extern const Pair d_021E2018;
extern const char d_021E22B8[];
extern struct Entry d_021E1F04[];


/*
 * Addresses are Black-image addresses.
 */
void func_021E14BC(u8 *p)
{
    func_02030EAC(((struct Obj23799 *)p)->fD90);
}


void func_021E14CC(char *p, char *q)
{
    char *r = p + 0xC90 + ((struct Obj23800 *)q)->fC * 0x10;

    ((struct Obj14251 *)r)->f0 = 1;
    *(char * *)&((struct Obj14251 *)r)->fC = q;
}

void func_021E14E4(const char *p)
{
  int mask = *((int *) (p + 28));
  const Block *base;
  int i;
  int count;
  i = 0;
  base = (const Block *) (p + 0x1a0);
  count = *((int *) (p + 48));
  for (; i < count; i++)
  {
    if ((base->records[i].active != 0) && (mask & (1 << base->records[i].key)))
      func_021E14CC((char *) p, (char *) (&base->records[i]));
  }
}

void func_021E1540(void *task, int *p)
{
    int done = 0;
    if (p[1] == 1) {
        p[2]--;
        if (p[2] <= 0) {
            p[2] = 0;
            done = 1;
        }
    } else {
        p[2]++;
        if (p[2] >= 8) {
            p[2] = 8;
            done = 1;
        }
    }
    func_021DFF20((void *)p[0], p[2]);
    if (done == 1) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}

void func_021E1584(char *p, int flag)
{
    Pair values = d_021E2018;
    int *q = func_02030734(0x8072, 12, 0, d_021E22B8, 5992);
    q[0] = (int)p;
    q[1] = flag;
    q[2] = ((int *)&values)[flag];
    func_02030DA8(((struct Obj02209 *)p)->fD98, func_021E1540, q, 0);
}


void func_021E15DC(int *p, int v)
{
    *p += v;
    while (*p < 0) *p += 0x168000;
    *p %= 0x168000;
}

void func_021E1604(char *p, int v)
{
    func_021E0634((u8 *)(p + 0xe0), v);
    func_021E0980(p, v);
}


int func_021E161C(char *p)
{
    int n = ((struct Obj10636 *)p)->f8 + 1;

    ((struct Obj10636 *)p)->f8 = n;
    if (n < 0x258)
        return 0;
    ((struct Obj10636 *)p)->f8 = 0x258;
    return 1;
}

/*
 * extent: following 021E168C is already matched separately.
 */
void *func_021E1634(char *p, u32 member, int flag)
{
    u32 size = func_020493D4(*(struct ArcFile * *)&((struct Obj14254 *)p)->fD58, member);
    void *result;
    if (flag == 1)
        result = func_02030734(114, size, 0, d_021E22B8, 6090);
    else
        result = func_02030734(0x8072, size, 0, d_021E22B8, 6092);
    func_0204932C(*(struct ArcFile * *)&((struct Obj14254 *)p)->fD58, member, result);
    return result;
}

void func_021E168C(int *p,int a) { if(a!=0) p[13]=a; }

void func_021E1694(char *p, const Record_021E1694 *q)
{
    ((struct Obj23802 *)p)->f3C = 1;
    *(Record_021E1694 *)(p + 0x58) = *q;
}

char *func_021E16AC(char *p)
{
    func_02082BCC(p + 0xb8, 0, 32);
    return p + 0xb8;
}


char *func_021E16C0(char *p)
{
    return p + 0xb8;
}


int func_021E16C4(char *p, int mask)
{
    return (((struct Obj23803 *)(*(char * *)&((struct Obj01753 *)p)->fDC))->f40 & mask) != 0;
}

/*
 * Lever: initialise count before bound, then carry bound through a plain copy bound_ after x is loaded.
 * Direct bound use left a four-byte zero/subtraction scheduling swap; bounded permuter found the copy spelling.
 * trailing: Two zero alignment bytes.
 */
int func_021E16D8(const char *p)
{
  unsigned int count;
  int bound;
  unsigned int x;
  int bound_;
  count = 0;
  bound = (*((int *) ((*((char **) (p + 0xd8))) + 8))) - 1;
  x = *((unsigned short *) ((*((char **) (p + 0xdc))) + 0x42));
  bound_ = bound;
  while (x)
  {
    count += x & 1;
    x >>= 1;
  }

  return ((int) count) >= bound_;
}


/*
 * extent: 30-byte body followed by two bytes of zero alignment padding.
 * lever: Initialize count before loading x; declare count before x.
 * Existing result-before-input and declaration-order idioms cover this.
 */
int func_021E170C(char *p) { int count; unsigned int x; count=0;x=((struct Obj23806 *)(*(char * *)&((struct Obj01753 *)p)->fDC))->f42;while(x) { count+=x&1; x>>=1; }return count; }

/*
 * extent: 42-byte body followed by two bytes of zero alignment padding.
 * volatile: The raw halfword at q+0 is re-read at 021E1732/021E1734.
 */
void func_021E172C(char *p,unsigned short *q) { unsigned int index;unsigned short value; index=*(volatile unsigned short *)&((struct Obj06543 *)q)->f0;value=*(volatile unsigned short *)&((struct Obj06543 *)q)->f0;*(unsigned short *)(p+index*4+0x7c)=value;*(unsigned short *)(p+index*4+0x7e)=q[1];if(q[1]==func_02039338())((struct Obj23807 *)p)->f2C=q[0]; }

void func_021E1758(char *p, int a1) { ((struct Obj01753 *)p)->f30=func_021841A4(func_021DEB10(p)); }


/*
 * The `&` operand order names the temporary: `field & (1 << i)` (field into
 * r2, mask into r0) reproduces the original; `(1 << i) & field` rotates them.
 */
int func_021E1768(char *p, int i)
{
    if (i != 0 && (((struct Obj23808 *)(*(char * *)&((struct Obj03304 *)p)->fDC))->f42 & (1 << i)) == 0)
        return 0;
    return 1;
}

void func_021E1784(char *p, int i)
{
    void *party;
    void *other;
    int slot;
    void *a;
    void *b;
    void *q;
    party = ((struct Obj14255 *)p)->f24;
    other = (void *)func_021DCE00(*(char * *)&((struct Obj14255 *)p)->fDC, i);
    slot = *(int *)(p + 0x44 + i * 4);
    a = func_0201AB28(party, (*(int **)(p + 0xd8))[1]);
    b = func_0201AB28(other, slot);
    q = func_021DEB10(p);
    func_0202F190(b, (int)6, (u32)func_02184180(q, (u8)func_02039338()), (int)30002, (int)114);
    func_02019CE0(b, a);
}

int func_021E17EC(char *p)
{
    int count = 0;
    unsigned bits = ((struct Obj23809 *)(*(char * *)&((struct Obj03304 *)p)->fDC))->f46;
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}

void func_021E180C(int *p,int a,int b) { (p+a)[17]=b; }

void func_021E1814(unsigned char *p,u16 *q)
{
    u16 *d=(u16 *)(p+108);
    unsigned n=8;
    do { *d++=*q++; } while(--n);
    ((struct Obj23810 *)p)->f40=1;
}

int func_021E1830(char *p, int angle, int index)
{
    int tmp;
    unsigned a;
    unsigned count;
    unsigned b;
    struct Range *r;
    struct Entry *e;
    func_021E15DC(&angle, -((struct Obj02497 *)p)->f11C);
    func_021E15DC(&angle, -((struct Obj02497 *)p)->f124);
    tmp = angle;
    func_021E15DC(&tmp, -0x4000);
    a = tmp / 0x1000;
    tmp = angle;
    func_021E15DC(&tmp, 0x5000);
    b = tmp / 0x1000;
    e = &d_021E1F04[index];
    count = e->count;
    r = e->ranges;
    while (count) {
        if ((a >= r->lo && a <= r->hi) || (b >= r->lo && b <= r->hi))
            return 1;
        r++;
        count--;
    }
    return 0;
}

int func_021E18CC(void *p)
{
    int n;
    int i;
    void *m;
    n = func_0201AA18(p);
    for (i = 0; i < n; i++) {
        m = func_0201AB28(p, i);
        if (func_02017E1C(m, 0x4c, 0) != 0 && func_02017E1C(m, 3, 0) != 0)
            return 1;
    }
    return 0;
}

int func_021E1910(char *p)
{
    int i;
    if (func_021E18CC(((struct Obj03304 *)p)->f24) == 1)
        return 1;
    for (i = 0; i < 5; i++) {
        if (func_021E1768(p, i) != 0 && func_021E18CC((void *)func_021DCE00(*(char * *)&((struct Obj03304 *)p)->fDC, i)) == 1)
            return 1;
    }
    return 0;
}


int func_021E1954(char *p) { int count; unsigned int x; count=0;x=((struct Obj23811 *)(*(char * *)&((struct Obj06536 *)p)->fDC))->f4A;while(x) { count+=x&1; x>>=1; }return count; }


int func_021E1974(char *p)
{
    return ((struct Obj23812 *)(*(char * *)&((struct Obj06536 *)p)->fDC))->f48 != 0;
}

void func_021E1988(unsigned int n) { func_02005DE4((void *)1);func_02005E64();func_02005D90(n,65535); }

/*
 * prototype: Legacy 02005E9C source lists four inputs, but its complete
 * body starts with 02005FBC(void) and reads no entry inputs; omitted them.
 */
int func_021E19A4(void) { if(func_02005F38()==0) { func_02005E9C();func_02005DE4(0);return 0; }return 1; }
