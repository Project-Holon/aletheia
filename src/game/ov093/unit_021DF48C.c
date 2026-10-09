/*
 * file:     unit_021DF48C.c
 * unit:     yes
 * function: func_021DF48C, func_021DF498, func_021DF4A4, func_021DF4B0, func_021DF4BC, func_021DF4C8, func_021DF4D4, func_021DF4E0, func_021DF510, func_021DF51C, func_021DF548, func_021DF588, func_021DF594, func_021DF5F4, func_021DF634, func_021DF640, func_021DF6AC, func_021DF6EC, func_021DF6F8, func_021DF704, func_021DF710, func_021DF71C, func_021DF728, func_021DF734
 * address:  0x021DF48C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F1464     0x021F1464  data   ov093  a4
 *   d_021F151C     0x021F151C  data   a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F1514     0x021F1514  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   d_021F167C     0x021F167C  data   ov093  a4
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021E8A58  0x021E8A58  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   d_021F168C     0x021F168C  data   ov093  a4
 *   d_021F169C     0x021F169C  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 *   d_021F14F4     0x021F14F4  data   ov093  a4
 *   d_021F13FC     0x021F13FC  data   ov093  a4
 *   d_021F13AC     0x021F13AC  data   ov093  a4
 *   d_021F137C     0x021F137C  data   ov093  a4
 */
struct QF;
struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Word { unsigned int v; } Word;

typedef struct Rec_021DF48C {
    int f00;
    int f04;
    Word f08;
    unsigned char pad0c[3];
    unsigned char id;
} Rec_021DF48C;

typedef struct Rec_021DF588 {
    int f00;
    int f04;
    Word f08;
    u8 f0c;
    u8 pad0d[2];
    u8 id;
} Rec_021DF588;

typedef struct Rec {
    int f00;
    int f04;
    Word f08;
    u8 f0c;
    u8 pad0d[2];
    u8 id;
    u8 pad10[4];
    u8 f14[8];
    u32 f1c;
} Rec;

extern int func_021D775C(int);
extern int func_021DCFF8(int a, int b);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern Word func_021D7D18(int x);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern Word func_021E8A58(void);
extern u16 func_021D70A8(struct QQ *p);
void func_021DF93C(int, int, int, int);
void func_021DF48C(void *a, int b, int c);
int *func_021DF498(int *p);
void func_021DF4A4(void *a, int b, int c);
int *func_021DF4B0(int *p);
void func_021DF4BC(void *a, int b, int c);
int *func_021DF4C8(int *p);
void func_021DF4D4(int a, int b, int c);
void func_021DF4E0(void *a, int b, int c, int d);
int *func_021DF510(int *p);
void func_021DF51C(int a, int b, int c);
void func_021DF548(void *self, void *q, int id);
int *func_021DF588(int *p);
void func_021DF594(void *self, void *q, int id);
void func_021DF5F4(void *self, void *q, int id);
int *func_021DF634(int *p);
void func_021DF640(void *self, void *q, int id);
void func_021DF6AC(void *self, void *q, int id);
int *func_021DF6EC(int *p);
void func_021DF6F8(int a, int b, int c);
int *func_021DF704(int *p);
void func_021DF710(int a, int b, int c);
int *func_021DF71C(int *p);
void func_021DF728(int a, int b, int c);
int *func_021DF734(int *p);
extern int d_021F1464[];
extern int d_021F151C[];
extern int d_021F1514[];
extern int d_021F167C[];
extern int d_021F168C[];
extern int d_021F169C[];
extern int d_021F14F4[];
extern int d_021F13FC[];
extern int d_021F13AC[];
extern int d_021F137C[];









void func_021DF48C(void *a, int b, int c)
{
    func_021DF4E0(a, b, c, 3);
}










int *func_021DF498(int *p)
{
    *p = 1;
    return d_021F1464;
}










void func_021DF4A4(void *a, int b, int c)
{
    func_021DF4E0(a, b, c, 4);
}









int *func_021DF4B0(int *p)
{
    *p = 1;
    return d_021F151C;
}









void func_021DF4BC(void *a, int b, int c)
{
    func_021DF4E0(a, b, c, 1);
}








int *func_021DF4C8(int *p)
{
    *p = 1;
    return d_021F1514;
}








void func_021DF4D4(int a, int b, int c)
{
    func_021DF4E0((void *)a, b, c, 2);
}








void func_021DF4E0(void *a, int b, int c, int d)
{
    if (c == func_021D775C(3) && d == func_021D775C(0x39))
        func_021D76BC(0x24, func_021DCFF8((int)a, 2));
}







int *func_021DF510(int *p)
{
    *p = 2;
    return d_021F167C;
}







void func_021DF51C(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D5444(func_021C7CF4((int *)b, c)) == 0x19)
        func_021D7704(0x35, 2 << 12);
}








void func_021DF548(void *self, void *q, int id)
{
    Rec_021DF48C *r;
    unsigned char tag;

    if (id != func_021D775C(2))
        return;
    tag = func_021D775C(3);
    r = (Rec_021DF48C *)func_021C88A4(q, 12, tag);
    r->id = id;
    r->f04 = 1;
    r->f08 = func_021D7D18(1);
    func_021C88C8(q, r);
}






int *func_021DF588(int *p)
{
    *p = 2;
    return d_021F168C;
}






void func_021DF594(void *self, void *q, int id)
{
    Rec_021DF588 *r;

    if (id != func_021D775C(2))
        return;
    r = (Rec_021DF588 *)func_021C88A4(q, 12, id);
    r->f04 = 5;
    r->f08 = func_021E8A58();
    r->f0c = 0;
    r->id = id;
    func_021C8838((u8 *)r + 0x14, 2, 0xf0);
    func_021C8860((struct S *)((u8 *)r + 0x14), id);
    func_021C8860((struct S *)((u8 *)r + 0x14), func_021D70A8(self));
    func_021C88C8(q, r);
}







/*
 * When id matches the value for key 2, allocate a 12-byte record (tag from
 * key 3), fill it and post it to the queue.
 *
 * func_021E8A58 returns a one-word struct by value; that is what reserves
 * the empty frame word (push r3 / sub sp, #4). An int return drops it.
 */
void func_021DF5F4(void *self, void *q, int id)
{
    Rec_021DF588 *r;
    unsigned char tag;

    if (id != func_021D775C(2))
        return;
    tag = func_021D775C(3);
    r = (Rec_021DF588 *)func_021C88A4(q, 12, tag);
    r->id = id;
    r->f04 = 5;
    r->f08 = func_021E8A58();
    func_021C88C8(q, r);
}





int *func_021DF634(int *p)
{
    *p = 2;
    return d_021F169C;
}





void func_021DF640(void *self, void *q, int id)
{
    Rec *r;

    if (id != func_021D775C(2))
        return;
    r = (Rec *)func_021C88A4(q, 12, id);
    r->f04 = 4;
    r->f08 = func_021D7D18(4);
    r->f0c = 0;
    r->id = id;
    r->f1c = func_021D70A8(self);
    func_021C8838(r->f14, 2, 0x102);
    func_021C8860((struct S *)r->f14, id);
    func_021C8860((struct S *)r->f14, func_021D70A8(self));
    func_021C88C8(q, r);
}






/*
 * Twin of func_021DF548 with kind 4.
 */
void func_021DF6AC(void *self, void *q, int id)
{
    Rec *r;
    unsigned char tag;

    if (id != func_021D775C(2))
        return;
    tag = func_021D775C(3);
    r = (Rec *)func_021C88A4(q, 12, tag);
    r->id = id;
    r->f04 = 4;
    r->f08 = func_021D7D18(4);
    func_021C88C8(q, r);
}




int *func_021DF6EC(int *p)
{
    *p = 1;
    return d_021F14F4;
}




void func_021DF6F8(int a, int b, int c)
{
    func_021DF93C(a, b, c, 6);
}



int *func_021DF704(int *p)
{
    *p = 1;
    return d_021F13FC;
}



void func_021DF710(int a, int b, int c)
{
    func_021DF93C(a, b, c, 4);
}


int *func_021DF71C(int *p)
{
    *p = 1;
    return d_021F13AC;
}


void func_021DF728(int a, int b, int c)
{
    func_021DF93C(a, b, c, 5);
}


/*
 * sdk:      DWCi_ScSetUseSSL (libdwcsc.TWL.HYB.a(dwc_sc.o))
 */
int *func_021DF734(int *p)
{
    *p = 1;
    return d_021F137C;
}
