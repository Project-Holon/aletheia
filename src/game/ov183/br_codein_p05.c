/*
 * file:     br_codein_p05.c
 * unit:     yes
 * function: func_021E111C, func_021E11D0, func_021E1244, func_021E1374, func_021E138C, func_021E13D8, func_021E13FC, func_021E16E4, func_021E1708, func_021E1850, func_021E1910, func_021E19EC, func_021E1BA8, func_021E1C00, func_021E1C14, func_021E1C44, func_021E1C80, func_021E1D10, func_021E1D48, func_021E1DA8, func_021E1DF0, func_021E1E3C, func_021E2028, func_021E20A4, func_021E20F8, func_021E214C, func_021E2194
 * address:  0x021E111C
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FC214 0x021FC214 thumb ov186
 *   d_021E3850 0x021E3850 data a4
 *   func_02045EC0 0x02045EC0 arm
 *   func_02043678 0x02043678 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_020255A0 0x020255A0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0202597C 0x0202597C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 *   d_021E3868 0x021E3868 data a4
 *   func_021E0840 0x021E0840 thumb ov183
 *   func_021E0E4C 0x021E0E4C thumb ov183
 *   func_021E0954 0x021E0954 thumb ov183
 *   func_021E0E90 0x021E0E90 thumb ov183
 *   func_021E0A88 0x021E0A88 thumb ov183
 *   func_021E0C04 0x021E0C04 thumb ov183
 *   func_021E1008 0x021E1008 thumb ov183
 *   func_021E10A0 0x021E10A0 thumb ov183
 *   func_021E10F4 0x021E10F4 thumb ov183
 *   func_02051C88 0x02051C88 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_021E0CE8 0x021E0CE8 thumb ov183
 *   func_021E0D00 0x021E0D00 thumb ov183
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 *   d_021E3858 0x021E3858 data a4
 *   func_021E0D90 0x021E0D90 thumb ov183
 *   func_020457B0 0x020457B0 arm
 *   func_02045AA8 0x02045AA8 arm
 *   func_0201F35C 0x0201F35C thumb
 *   _ull_mul 0x0209C054 arm
 *   d_021E3880 0x021E3880 data a2
 *   func_02051B84 0x02051B84 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   d_021E38E0 0x021E38E0 data a4
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B570 0x0200B570 thumb
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF67C 0x021FF67C thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   d_021E39B4 0x021E39B4 data a4
 *   func_02034714 0x02034714 arm
 *   func_021E23C8 0x021E23C8 thumb ov183
 *   func_021E24AC 0x021E24AC thumb ov183
 *   func_021E24C4 0x021E24C4 thumb ov183
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021E21E0 0x021E21E0 thumb ov183
 */
#include "../../matched/include/Obj03882.h"
#include "../../matched/include/Obj01768.h"
#include "../../matched/include/Obj00143.h"
#include "../../matched/include/Obj00417.h"
#include "../../matched/include/Obj00478.h"
#include "../../matched/include/Obj00732.h"
#include "../../matched/include/Obj03331.h"
#include "../../matched/include/Obj24628.h"
#include "../../matched/include/Obj02232.h"
#include "../../matched/include/Obj05482.h"
#include "../../matched/include/Obj10753.h"
#include "../../matched/include/Obj24629.h"
#include "../../matched/include/Obj04579.h"
#include "../../matched/include/Obj24630.h"
#include "../../matched/include/Obj24631.h"
#include "../../matched/include/Obj24632.h"
#include "../../matched/include/Obj14441.h"
#include "../../matched/include/Obj10756.h"
#include "../../matched/include/Obj24637.h"
#include "../../matched/include/Obj01275.h"
#include "../../matched/include/Obj24638.h"
#include "../../matched/include/Obj24639.h"
#include "../../matched/include/Obj24640.h"
#include "../../matched/include/Obj24641.h"
#include "../../matched/include/Obj24642.h"
#include "../../matched/include/Obj24643.h"
#include "../../matched/include/Obj24644.h"
#include "../../matched/include/Obj24645.h"
#include "../../matched/include/Obj24646.h"
#include "../../matched/include/Obj24647.h"
#include "../../matched/include/Obj01567.h"
#include "../../matched/include/Obj04580.h"
#include "../../matched/include/Obj10757.h"
#include "../../matched/include/Obj24648.h"
#include "../../matched/include/Obj06612.h"
#include "../../matched/include/Obj14442.h"
#include "../../matched/include/Obj24649.h"
#include "../../matched/include/Obj24650.h"
#include "../../matched/include/Obj10760.h"
#include "../../matched/include/Obj24651.h"
#include "../../matched/include/Obj24652.h"
#include "../../matched/include/Obj24653.h"

struct Grid;
struct Sys;
struct Bmp;
struct MsgBank;
struct Obj;
struct Obj020437AC;
struct U16Vec;
struct Param;
struct Ctx;
struct Actor;
struct PtS;
struct Vec2;
struct Pair_021E111C;
struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
struct Big;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {void *handle; short x,y; unsigned data,zero; u8 a,b; u16 c; unsigned d;} Descriptor;

typedef struct {char f000[0x300]; struct Sys *f300; struct Grid *f304[1];} Object;

typedef enum {INDEX_0,INDEX_1} Index;

typedef signed short   s16_021E111C;

typedef unsigned int   u32_021E111C;

typedef unsigned long u32_021E1244;

typedef struct 
{
  int v[3];
} Row_021E1244;

typedef struct 
{
  Row_021E1244 row[2];
} Table_021E1244;

typedef struct 
{
  char pad[0x328];
  int count;
} State;

typedef signed char s8;

typedef signed short s16_021E1374;

typedef unsigned int u32_021E1374;

typedef signed int s32_021E1374;

typedef int s32_021E13D8;

typedef short s16_021E13FC;

typedef unsigned long u32_021E13FC;

typedef struct {s16_021E13FC a,b,x,y;} Coords;

typedef struct {u32_021E13FC x,y;} Pair_021E111C;

typedef unsigned long u32_021E1708;

typedef unsigned long long u64;

typedef struct {int tag,value,mode,handle; char rest[12];} Record;

typedef unsigned long u32_021E1910;

typedef struct {short a,b,c,d;} Row_021E1910;

typedef struct {Row_021E1910 row[12];} Table_021E1910;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

typedef struct {int a,b;} Pair_021E1C80;

typedef struct {u32 a,b;} Pair;

extern int func_021FC214(char *);
extern void *func_02045EC0(struct MsgBank *bank, u32_021E111C index);
extern struct Bmp *func_02043678(u32_021E111C width, u32_021E111C height, u32_021E111C depth, u16 heap);
extern void func_0201C7A4(void *x, s16_021E111C y, s16_021E111C z, void *s, void *w);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_020257D0(struct Obj *o);
extern void func_0202597C(u8 *g, u32_021E111C a);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_021E0840(char *);
extern void func_021E0E4C(char *);
extern void func_021E0954(char *);
extern void func_021E0E90(char *,int);
extern void func_021E0A88(char *);
extern void func_021E0C04(char *);
extern void func_021E1008(char *);
extern void func_021E10A0(char *);
extern void func_021E10F4(char *);
extern s32_021E13D8 func_02051C88(struct Ctx *c);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021E13FC which);
extern void func_0204B5AC(struct Obj *dst, struct Pair_021E111C *src);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021E0E40(int,int);
extern void func_021E0CE8(char *p, int index, int a2);
extern void func_021E0D00(char *,int);
extern void func_021E0D90(char *);
extern struct U16Vec *func_020457B0(u32_021E1708 capacity, u32_021E1708 heapId);
extern void func_02045AA8(struct U16Vec *dst, struct U16Vec *src);
extern void func_0201F35C(void *, int, u32_021E1708, u32_021E1708, u32_021E1708);
extern void *func_02051B84(u8 *,int,int,int);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020061E4(u32);
extern void func_021FD860(int,int,int *);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void * func_02082BCC(void *,int,int);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern u32 func_0201C440(void *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD714(void *p);
extern void func_020315D4(struct S020315D4 *);
extern u8 func_02012E40(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(int);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *p);
extern int *func_021FD73C(int *p, int v);
extern int func_021FD744(int *a);
extern void func_021F9BA0(unsigned *ctx);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0200B570(void *a, u16 heap, u32 *dp, u32 id);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern u32 func_021FF67C(u8 *p, unsigned long long *out);
extern int func_021FC214(char *),func_021FC21C(char *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021FD19C(char *p, void *q, void *text);
extern int func_02035C60(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021E23C8(char *,char *);
extern void func_021E24AC(char *,char *);
extern void func_021E24C4(char *,char *);
extern int func_021FC830(u8 *p);
extern void func_021E21E0(int task, int *state, char *p);
void func_021E111C(const Object *object,Index index,int x,int y);
void func_021E11D0(char *p,int state);
void func_021E1244(State *p);
void func_021E1374(char *p, int v);
int func_021E138C(char *p);
int func_021E13D4(void);
s32_021E13D8 func_021E13D8(char *p);
int func_021E13FC(char *p);
int func_021E16E4(char *p);
void func_021E1708(char *p);
void func_021E1850(const Record *records);
void func_021E1910(char *p);
void func_021E19EC(u32 idx, int arg, char *p);
void func_021E1BA8(char *p);
void func_021E1C00(char *p);
int func_021E1C14(char *p,int a);
int func_021E1C44(const char *p, int a);
int func_021E1C80(struct Obj0203159C *obj,int unused,char *arg);
int func_021E1D10(struct S020315D4 *a,int b,char *q,char *p);
int func_021E1D48(int a,int b,int c,char *p);
void func_021E1DA8(int a,int *state,char *p);
void func_021E1DF0(int *a,int *state,char *p);
void func_021E1E3C(int *task,int *state,char *p);
int func_021E2028(struct Obj0203159C *obj,int unused,char *arg);
int func_021E20A4(int obj,int b,char *arg,char *p);
int func_021E20F8(int a,int b,int c,char *p);
void func_021E214C(int *task,int *state,char *p);
void func_021E2194(int *task,int *state,char *p);
extern const int d_021E3850[];
extern const Table_021E1244 d_021E3868;
extern const int d_021E3998[],d_021E397C[];
extern const Table_021E1910 d_021E3880;
extern const Pair_021E1C80 d_021E38E0;
extern char d_021E39B4[];





/*
 * lever: form slot=&out[index] before the constructor call and store/reload through slot. The direct out[index] spelling sank the output base and left 15 bytes different.
 */
void func_021E111C(const Object *object,Index index,int x,int y)
{
    char *p=(char *)object;
    int source,handle,obj;
    u8 xx,yy;
    struct Grid **slots;
    Descriptor desc;
    source=func_021FC214(*(char * *)&((struct Obj03882 *)p)->f344);
    source=(int)func_02045EC0((struct MsgBank *)source,d_021E3850[index]);
    handle=(int)func_02043678(10,2,32,((struct Obj03882 *)p)->f34C);
    func_0201C7A4((void *)handle,1,0,(void *)source,(void *)(((struct Obj03882 *)p)->f310));
    xx=((u8 *)(p+0x29a))[(index+22)*4];
    yy=((u8 *)(p+0x298))[(index+22)*4];
    desc.handle=(void *)handle;
    desc.x=xx+x;
    desc.y=yy+y;
    desc.data=((struct Obj03882 *)p)->f264;
    desc.zero=0;
    desc.a=0;
    desc.b=0;
    desc.c=1;
    desc.d=1;
    {
        struct Grid **out=(struct Grid **)(char *)object->f304;
        struct Grid **slot;
        struct Grid *grid;
        slot=&out[index];
        grid=func_020255A0(object->f300,(const struct Param *)(&desc));
        *slot=grid;
        func_020257D0((struct Obj *)((int)grid));
        func_0202597C((u8 *)((int)*slot),1);
    }
    func_020437AC((struct Obj020437AC *)handle);
    func_02045808((struct U16Vec *)source);
}





/*
 * Extent remainder: zero alignment halfword at 021E1242.
 */
void func_021E11D0(char *p,int state)
{
    ((struct Obj01768 *)p)->f244=((struct Obj01768 *)p)->f240;
    ((struct Obj01768 *)p)->f240=state;
    ((struct Obj01768 *)p)->f248=0;
    ((struct Obj01768 *)p)->f24C=0;
    ((struct Obj01768 *)p)->f250=0;
    ((struct Obj01768 *)p)->f254=0;
    if (state) {
        ((struct Obj01768 *)p)->f248=*(u16 *)(p+(state-1)*4+0x21c);
        ((struct Obj01768 *)p)->f24C=*(u16 *)(p+(state-1)*4+0x21e);
    }
    if (((struct Obj01768 *)p)->f244) {
        ((struct Obj01768 *)p)->f250=*(u16 *)(p+(((struct Obj01768 *)p)->f244-1)*4+0x21c);
        ((struct Obj01768 *)p)->f254=*(u16 *)(p+(((struct Obj01768 *)p)->f244-1)*4+0x21e);
    }
}





/*
 * 2026-10-05 (wave P7 lane V7, pengy share): EXACT in c99 and c. The older DIFF28 draft (see docs/notes) closed with two
 * changes. (1) The row index is a block-local initialised BEFORE the table copy (int row = 0, then the const Table copy):
 * the zero then lives across the copy and the copy takes r5/r3 as in the original. (2) The count row pointer of the last
 * loop is a named State pointer local declared before j (cnt = p + group * 4), which gives j r3
 * and the row pointer r2. Original reads: p[0x2FC] = 1; halfword offsets; a stray store at 0x21A reading row[i - 1] after the
 * copy loop (reproduced as in the listing, probably an off-by-one in the original); no hidden callee arguments.
 */
void func_021E1244(State *p)
{
  int i;
  int sum;
  int prefix;
  int group;
  int k;
  State *cnt;
  int j;
  u16 truncated;
  char *tmp;
  *((int *) (((char *) p) + 0x2FC)) = 1;
  *((u16 *) (((char *) p) + 0x21C)) = 0;
  sum = *((int *) (((char *) p) + 0x328));
  truncated = sum;
  *((u16 *) (((char *) p) + 0x21E)) = truncated;
  *((u16 *) (((char *) p) + 0x220)) = truncated;
  sum += *((int *) (((char *) p) + 0x32C));
  tmp = ((char *) p) + 0x222;
  truncated = sum;
  *((u16 *) tmp) = truncated;
  *((u16 *) (((char *) p) + 0x224)) = truncated;
  sum = (*((int *) (((char *) p) + 0x330))) + ((int) sum);
  *((u16 *) (((char *) p) + 0x226)) = sum;
  func_021E11D0((char *) p, 1);
  for (i = 0; i < 3; i++)
    *((int *) (((char *) p) + 0x23C)) += *((int *) ((((u32_021E1244) p) + (i * 4)) + 0x328));

  {
    int row = 0;
    const Table_021E1244 table = d_021E3868;
    if ((*((int *) (((char *) p) + 0x328))) != 4)
      row = 1;
    for (i = 0; i < 3; i++)
      *((u16 *) ((((u32_021E1244) p) + (i * 2)) + 0x214)) = table.row[row].v[i];

    *((u16 *) ((((u32_021E1244) p) + (i * 2)) + 0x214)) = table.row[row].v[i - 1];
    prefix = 0;
    for (group = 0; group < 2; group++)
    {
      prefix += *((int *) ((((u32_021E1244) p) + (group * 4)) + 0x328));
      *((int *) ((((u32_021E1244) p) + (group * 28)) + 0x150)) = prefix - 1;
    }

    group = 0;
    j = 0;
    do
    {
      cnt = (State *) (((u32_021E1244) p) + (group * 4));
      for (k = 0; k < cnt->count; k++)
      {
        *((int *) ((((u32_021E1244) p) + (j * 28)) + 4)) = group + 1;
        j++;
      }

      group++;
    }
    while (j < (*((int *) (((char *) p) + 0x23C))));
  }
}






void func_021E1374(char *p, int v)
{
    ((struct Obj00143 *)p)->f22C = v;
    ((struct Obj00143 *)p)->f230 = 0;
    ((struct Obj00143 *)p)->f234 = 0;
    ((struct Obj00143 *)p)->f238 = 0;
}





/*
 * Follower: 021E13D4 return-one stub, after 021E13D2 alignment.
 */
int func_021E138C(char *p)
{
    func_021E0840(p);
    func_021E0E4C(p);
    func_021E0954(p);
    func_021E0E90(p,0);
    func_021E0A88(p);
    func_021E0C04(p);
    func_021E1008(p);
    func_021E10A0(p);
    func_021E10F4(p);
    func_021E1374(p,1);
    return 0;
}





int func_021E13D4(void)
{
    return 1;
}





s32_021E13D8 func_021E13D8(char *p)
{
    if (*(s32_021E13D8 *)(p + 0x234) == 0) {
        (*(s32_021E13D8 *)(p + 0x234))++;
    } else {
        func_021E1BA8(p);
        func_02051C88(*(void **)(p + 0x294));
    }
    return 0;
}





int func_021E13FC(char *p) {
    int i,factor,selected;
    char *record;
    Pair_021E111C scale;
    Coords coords;
    switch(((struct Obj00478 *)p)->f234){
    case 0:
        func_021E0CE8(p,0,0);
        for(i=0;i<((struct Obj00478 *)p)->f23C;i++){
            record=(char *)((u32_021E13FC)p+i*28);
            if(((struct Obj00417 *)record)->f18!=0){
                func_0204B454(((struct Obj00417 *)record)->fC,(struct PtS *)&coords.x,1);
                coords.x+=((struct Obj00417 *)record)->f14;
                coords.y+=((struct Obj00417 *)record)->f16;
                func_0204B404(((struct Obj00417 *)record)->fC,(const struct Vec2 *)(&coords.x),1);
                --((struct Obj00417 *)record)->f18;
                if(i>=((struct Obj00478 *)p)->f248&&i<((struct Obj00478 *)p)->f24C){
                    factor=*(int *)((u32_021E13FC)d_021E3998+((struct Obj00417 *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair_021E111C *)(&scale));
                    ++((struct Obj00417 *)record)->f19;
                }
                if(i>=((struct Obj00478 *)p)->f250&&i<((struct Obj00478 *)p)->f254){
                    factor=*(int *)((u32_021E13FC)d_021E397C+((struct Obj00417 *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair_021E111C *)(&scale));
                    ++((struct Obj00417 *)record)->f19;
                }
            }
        }
        for(i=0;i<2;i++){
            record=(char *)((u32_021E13FC)p+i*28);
            if(((struct Obj00417 *)record)->f168!=0){
                func_0204B454(((struct Obj00417 *)record)->f15C,(struct PtS *)&coords.a,1);
                coords.a+=((struct Obj00417 *)record)->f164;
                coords.b+=((struct Obj00417 *)record)->f166;
                func_0204B404(((struct Obj00417 *)record)->f15C,(const struct Vec2 *)(&coords.a),1);
                --((struct Obj00417 *)record)->f168;
            }
        }
        if(((struct Obj00478 *)p)->f18==0){
            for(i=((struct Obj00478 *)p)->f248;i<((struct Obj00478 *)p)->f24C;i++){
                record=(char *)((u32_021E13FC)p+i*28);
                func_0204B878(((struct Obj00417 *)record)->fC,func_021E0E40(((struct Obj00417 *)record)->f0,((struct Obj00417 *)record)->f8));
            }
            for(i=((struct Obj00478 *)p)->f250;i<((struct Obj00478 *)p)->f254;i++){
                record=(char *)((u32_021E13FC)p+i*28);
                func_0204B878(((struct Obj00417 *)record)->fC,func_021E0E40(((struct Obj00417 *)record)->f0,((struct Obj00417 *)record)->f8));
            }
            ++((struct Obj00478 *)p)->f234;
        }
        ++((struct Obj00478 *)p)->f238;
        break;
    case 1:
        for(i=((struct Obj00478 *)p)->f248;i<((struct Obj00478 *)p)->f24C;i++){
            record=(char *)((u32_021E13FC)p+i*28);
            if(((struct Obj00417 *)record)->f19!=6){
                factor=*(int *)((u32_021E13FC)d_021E3998+((struct Obj00417 *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair_021E111C *)(&scale));
                ++((struct Obj00417 *)record)->f19;
            }
        }
        for(i=((struct Obj00478 *)p)->f250;i<((struct Obj00478 *)p)->f254;i++){
            record=(char *)((u32_021E13FC)p+i*28);
            if(((struct Obj00417 *)record)->f19!=6){
                factor=*(int *)((u32_021E13FC)d_021E397C+((struct Obj00417 *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair_021E111C *)(&scale));
                ++((struct Obj00417 *)record)->f19;
            }
        }
        if(++((struct Obj00478 *)p)->f238==6)++((struct Obj00478 *)p)->f234;
        break;
    default:
        func_021E1008(p);
        if(((struct Obj00478 *)p)->f320==0)selected=func_021E1C14(p,((struct Obj00478 *)p)->f31C);
        else selected=func_021E1C44(p,((struct Obj00478 *)p)->f31C);
        func_021E0D00(p,selected);
        if(((struct Obj00478 *)p)->f240!=0)func_021E0CE8(p,0,1);
        func_021E1C00(p);
        func_021E1374(p,1);
        break;
    }
    return 0;
}





extern int (*const d_021E3858[])(char *);





int func_021E16E4(char *p){ int r=d_021E3858[*(int *)(p+0x22c)](p); func_021E0D90(p); return r; }





/*
 * Matching: named digit load and byte-field address, with group before used in declaration order, preserve the original loop registers.
 */
void func_021E1708(char *p)
{
  u32_021E1708 group = 0;
  u32_021E1708 i;
  int used = 0;
  int digit;
  void *text;
  char *record;
  u64 *acc;
  u64 product;
  u32_021E1708 tmp;
  char *tmp1;
  text = func_020457B0(100, *((u16 *) (p + 0x34C)));
  tmp1 = p + 0x210;
  *((int *) (p + 0x1F8)) = 1;
  *((u8 *) tmp1) = 0;
  *((int *) (p + 0x354)) = 0;
  *((int *) (p + 0x358)) = 0;
  *((int *) (p + 0x35C)) = 0;
  *((u32_021E1708 *) (p + 0x360)) = 0;
  *((u32_021E1708 *) (p + 0x364)) = 0;
  i = 0;
  if (((int) i) < (*((int *) (p + 0x23C))))
  {
    acc = (u64 *) (p + 0x360);
    do
    {
      record = (char *) (((u32_021E1708) p) + (i * 28));
      if ((*((int *) record)) == 0)
      {
        *((int *) record) = 1;
        func_0204B878(*((void **) (record + 12)), func_021E0E40(1, *((int *) (record + 8))));
      }
      tmp = *((u32_021E1708 *) record);
      digit = tmp - 1;
      func_0201F35C(text, digit, 1, 1, 1);
      func_02045AA8(*((void **) (p + 0x33C)), text);
      *((int *) ((((u32_021E1708) p) + (group * 4)) + 0x354)) *= 10;
      *((int *) ((((u32_021E1708) p) + (group * 4)) + 0x354)) += digit;
      used++;
      if (((int) used) >= (*((int *) ((((u32_021E1708) p) + (group * 4)) + 0x328))))
      {
        group++;
        used = 0;
      }
      product = (*acc) * 10;
      *acc = product + ((u32_021E1708) digit);
      i++;
    }
    while (((int) i) < (*((int *) (p + 0x23C))));
  }
  func_02045808(text);
  func_021E1374(p, 3);
  *((int *) (p + 0x350)) = 2;
}





void func_021E1850(const Record *records)
{
    char *p=(char *)records;
    int i,old,value,offset;
    ((struct Obj00732 *)p)->f1DC=1;
    p[0x1f4]=0;
    if (((struct Obj00732 *)p)->f240==0) {
        i=((struct Obj00732 *)p)->f23C-1;
        ((struct Obj00732 *)p)->f188=i;
        value=records[i].value;
        ((struct Obj00732 *)p)->f318=1;
        ((struct Obj00732 *)p)->f31C=value;
        ((struct Obj00732 *)p)->f320=1;
    } else {
        i=((struct Obj00732 *)p)->f188;
        func_0204B878((struct Obj *)records[i].handle,func_021E0E40(((Record *)records)[i].tag=0,records[i].mode));
        old=records[i].value;
        if (i>0) {
            func_0204B878((struct Obj *)records[i-1].handle,func_021E0E40(records[i-1].tag,records[i-1].mode));
            value=records[i-1].value;
            if (old!=value) {
                ((struct Obj00732 *)p)->f318=1;
                ((struct Obj00732 *)p)->f31C=value;
                ((struct Obj00732 *)p)->f320=1;
            } else {
                ((struct Obj00732 *)p)->f318=2;
                ((struct Obj00732 *)p)->f31C=i-1;
            }
        } else ((struct Obj00732 *)p)->f350=1;
    }
}





void func_021E1910(char *p) {
    int i;
    Table_021E1910 table;
    for(i=0;i<12;i++)*(char **)(p+i*28+16)=(p+0x298)+i*4;
    table=d_021E3880;
    for(;i<24;i++){
        *(u8 *)(p+i*4+0x298)=table.row[i-12].b-table.row[i-12].d;
        *(u8 *)(p+i*4+0x29A)=table.row[i-12].a-table.row[i-12].c;
        *(u8 *)(p+i*4+0x299)=table.row[i-12].b+table.row[i-12].d;
        *(u8 *)(p+i*4+0x29B)=table.row[i-12].a+table.row[i-12].c;
    }
    ((struct Obj03331 *)p)->f2F8=255;
    ((struct Obj03331 *)p)->f294=func_02051B84((u8 *)(p+0x298),(int)func_021E19EC,(int)p,((struct Obj03331 *)p)->f34C);
}





/*
 * 2026-10-05 wave P5 lane T5 (pengy share): earlier DIFF, two residues (merged far-branch stubs, idx-12 CSE).
 * 2026-10-05 wave P5 lane T5b: EXACT with the ov129 021D958C forms: idx is u32 (unsigned % and / by plain 5),
 *   `if (*(int *)(p + 0x22C) != 1) return;` then `if (arg == 0) {`, non-const Record pointer. One compile.
 *   Callbacks: func_021E1910 passes this as func_02051B84's callback (idx, arg, obj).
 */
void func_021E19EC(u32 idx, int arg, char *p)
{
    Record *rec = (Record *)p;
    u32 i, j, v;
    int old, val;
    if (*(int *)(p + 0x22C) != 1) return;
    if (arg == 0) {
    if (idx <= 11) {
        if (rec[idx].mode == 1) {
            *(int *)(p + 0x318) = 2;
            *(int *)(p + 0x31C) = idx;
        } else {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = rec[idx].value;
        }
        func_020061E4(0x703);
        return;
    }
    if (idx == 0x16) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 0;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
    } else if (idx == 0x17) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 3;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
    } else {
        *(u16 *)(p + 0x1B8) = (idx - 12) % 5;
        *(u16 *)(p + 0x1BA) = (idx - 12) / 5;
        func_020061E4(0x703);
    }
    if (idx >= 12 && idx <= 21) {
        u32 x, y;
        int args[2];
        if (*(int *)(p + 0x240) != 0) {
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
        i = *(int *)(p + 0x188);
        v = idx - 11;
        func_0204B878((struct Obj *)rec[i].handle, (u16)func_021E0E40(rec[i].tag = v, rec[i].mode));
        old = rec[i].value;
        j = i + 1;
        if (j == *(u32 *)(p + 0x23C)) {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = 0;
            *(int *)(p + 0x320) = 0;
        } else {
            val = rec[j].value;
            if (old != val) {
                *(int *)(p + 0x318) = 1;
                *(int *)(p + 0x31C) = val;
                *(int *)(p + 0x320) = 0;
            } else {
                *(int *)(p + 0x318) = 2;
                *(int *)(p + 0x31C) = j;
            }
        }
        }
    } else if (idx == 0x16) {
        func_021E1850((const Record *)p);
    } else {
        func_021E1708(p);
    }
    }
}





/*
 * Extent remainder: zero alignment halfword at 021E1BFE.
 */
void func_021E1BA8(char *p)
{
    switch (((struct Obj00478 *)p)->f318) {
    case 0: break;
    case 1:
        func_021E11D0(p,((struct Obj00478 *)p)->f31C);
        func_021E0E4C(p);
        func_021E0E90(p,1);
        func_021E1374(p,2);
        ((struct Obj00478 *)p)->f318=255;
        break;
    case 2:
        func_021E0D00(p,((struct Obj00478 *)p)->f31C);
        func_021E1C00(p);
        break;
    case 255: break;
    }
}






void func_021E1C00(char *p)
{
    ((struct Obj00478 *)p)->f318 = 0;
    ((struct Obj00478 *)p)->f31C = 0;
    ((struct Obj00478 *)p)->f320 = 0;
}






/*
 * extent: final two bytes are alignment padding.
 */
int func_021E1C14(char *p,int a){int i,n; n=((struct Obj24628 *)p)->f23C;for(i=0;i<n;i++){if(a==*(int *)(p+i*28+4))return i;}return 0;}





/*
 * checks: 1 n/a no calls; 2 matched 1C14 confirms signed index/raw28 stride; 3 enum index DIFF7, unsigned-long count and long index each DIFF4; 4 count/address reuse DIFF4, permuter expands the read-only count field at guard and return; 5 refreshed directory and neighbours; no stack object.
 * matching: re-reading count at guard and return instead of a cached scalar lets the dying offset use r4. No stores or calls can change count during this function.
 * extent: 58 code bytes, alignment padding at021E1C7E..021E1C80; next function starts1C80.
 * retry: 5 one runs, once-only permuter budget300 found expand(n x2) after9 candidates; emitted DIFF4 baseline agrees; winner validated by run6.
 */
int func_021E1C44(const char *p, int a)
{
  int i;
  int found;
  unsigned n;
  n = *((const unsigned *) (p + 0x23c));
  found = 0;
  for (i = 0; i < ((int) (*((const unsigned *) (p + 0x23c)))); i++)
  {
    if (a == (*((const int *) ((p + (i * 28)) + 4))))
      found = 1;
    else
      if (found == 1)
      return i - 1;
  }

  return (*((const unsigned *) (p + 0x23c))) - 1;
}




int func_021E1C80(struct Obj0203159C *obj,int unused,char *arg)
{
    char *p;
    int i;
    Pair_021E1C80 pair;
    p=func_0203159C(obj,32,func_021F9B9C((struct Obj24810 *)(((struct Obj05482 *)arg)->fC)));
    func_02082BCC(p,0,32);
    *(char * *)&((struct Obj02232 *)p)->f18=arg;
    ((struct Obj02232 *)p)->f8=func_021F9B9C((struct Obj24810 *)(((struct Obj05482 *)arg)->fC));
    ((struct Obj02232 *)p)->f4=(int)func_021FD6D8((int)p,(int)func_021E1DA8,((struct Obj02232 *)p)->f8);
    ((struct Obj02232 *)p)->f0=func_0201C440((void *)(((struct Obj02232 *)p)->f8));
    ((struct Obj02232 *)p)->fC=(int)func_021FD12C(((struct Obj05482 *)arg)->f8,(void *)(((struct Obj02232 *)p)->f0),((struct Obj02232 *)p)->f8);
    func_021FD170((char *)(((struct Obj02232 *)p)->fC),(char *)(((struct Obj05482 *)arg)->f8),(void *)111);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x10)=(int)func_021FD760(((struct Obj05482 *)arg)->f4,(char *)(((struct Obj05482 *)arg)->f8),i,((struct Obj02232 *)p)->f8);
    pair=d_021E38E0;
    func_021FD860(((struct Obj02232 *)p)->f10, 4, (int *)&pair);
    return 1;
}




int func_021E1D10(struct S020315D4 *a,int b,char *q,char *p){int i;for(i=0;i<2;i++)func_021FD820(*(char **)(p+i*4+16));func_021FD15C(((struct Obj10753 *)p)->fC,((struct Obj24629 *)q)->f8);func_0201C4C0(((struct Obj10753 *)p)->f0);func_021FD714((void *)(((struct Obj10753 *)p)->f4));func_020315D4(a);return 1;}




int func_021E1D48(int a,int b,int c,char *p)
{
    int i;
    if (!func_02012E40((const u8 *)(((struct Obj24630 *)(*(char * *)&((struct Obj04579 *)p)->f18))->f14)) && func_021FF88C((char *)(((struct Obj24631 *)(*(char * *)&((struct Obj04579 *)p)->f18))->f10))==2) {
        func_021F9C6C(((struct Obj24632 *)(*(char * *)&((struct Obj04579 *)p)->f18))->fC);
        return 1;
    }
    func_021FD71C((u8 *)(((struct Obj04579 *)p)->f4));
    if (func_021FD72C((int *)(((struct Obj04579 *)p)->f4))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x10)));
    func_0201C4E4((struct PrintSys *)(((struct Obj04579 *)p)->f0));
    func_021FD1BC((void *)(((struct Obj04579 *)p)->fC));
    return 0;
}



void func_021E1DA8(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj14441 *)p)->f18,2,3,0); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj14441 *)p)->f18))) *state=2; break;
    case 2: func_021FD73C((int *)a,(int)func_021E1E3C); break;
    }
}



void func_021E1DF0(int *a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj10756 *)p)->f18,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj10756 *)p)->f18))) *state=2; break;
    case 2: func_021F9BA0((unsigned int *)(((struct Obj24637 *)(*(char * *)&((struct Obj10756 *)p)->f18))->fC)); func_021FD744(a); break;
    }
}



/*
 * lever: keep the copied u64 and quotient distinct; use the emitted _ull_mod runtime symbol.
 */
void func_021E1E3C(int *task,int *state,char *p) {
    u32 out;
    u64 total;
    u32 msg,x,y; Pair pair;
    void *str,*expanded,*ws,*bank;
    u64 copy,quotient;
    int result;
    switch(*state) {
    case 0:
        func_0200B570(func_02012EBC(((struct Obj24638 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f14),89,&out,0);
        if(out==1)*state=1;else func_021FD73C((int *)task,(int)func_021E1DF0);break;
    case 1:
        ((struct Obj01275 *)p)->f1C=0;func_021FF54C(((struct Obj24639 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10,2,0);*state=2;break;
    case 2:
        ++((struct Obj01275 *)p)->f1C;
        if(func_021FF648(((struct Obj24640 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10)) {
            total=0;
            if(((struct Obj01275 *)p)->f1C>=96) {
                result=func_021FF72C(((struct Obj24641 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10,(int *)(&msg));
                if(result==0) {
                    if(func_021FF67C(((struct Obj24642 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10,&total)) {
                        bank=(void *)func_021FC214(*(char * *)&((struct Obj24643 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8);
                        ws=(void *)func_021FC21C(*(char * *)&((struct Obj24644 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8);
                        str=func_02045EC0(bank,334);expanded=func_020457B0(128,0x8059);
                        copy=total;quotient=copy/100000;
                        func_0201EFA4(ws,2,(u32)(copy%100000),5,2,1);
                        func_0201EFA4(ws,1,(u32)(quotient%100000),5,2,1);
                        func_0201EFA4(ws,0,(u32)(quotient/100000),2,2,1);
                        func_0201F250(ws,expanded,str);
                        func_021FD19C((char *)(((struct Obj01275 *)p)->fC),(void *)(((struct Obj24645 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8),expanded);
                        func_02045808(expanded);func_02045808(str);
                    }
                } else if(result==3) {
                    func_021F9C6C((int)(((struct Obj24646 *)(*(char * *)&((struct Obj01275 *)p)->f18))->fC));func_021FD744(task);break;
                } else func_021FD170((char *)(((struct Obj01275 *)p)->fC),(char *)(((struct Obj24647 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8),(void *)msg);
                func_021FD860(((struct Obj01275 *)p)->f10, 0, (int *)0);*state=4;
            }
        }break;
    case 3:func_021FD73C((int *)task,(int)func_021E1DF0);break;
    case 4:
        if(func_02035C60()) {
            func_02035D20(&x,&y);pair.a=x;pair.b=y;func_021FD860(((struct Obj01275 *)p)->f14, 1, (int *)&pair);
            func_020061E4(0x703);*state=3;
        }break;
    }
}


int func_021E2028(struct Obj0203159C *obj,int unused,char *arg)
{
    char *p;
    int i;
    if (*(int *)&((struct Obj01567 *)arg)->f0>=4) func_02034714(d_021E39B4,0,d_021E39B4);
    p=func_0203159C(obj,40,func_021F9B9C((struct Obj24810 *)(((struct Obj01567 *)arg)->f10)));
    func_02082BCC(p,0,40);
    *(char * *)&((struct Obj04580 *)p)->f20=arg;
    ((struct Obj04580 *)p)->f1C=func_021F9B9C((struct Obj24810 *)(((struct Obj01567 *)arg)->f10));
    ((struct Obj04580 *)p)->f8=(int)func_021FD6D8((int)p,(int)func_021E214C,((struct Obj04580 *)p)->f1C);
    ((struct Obj04580 *)p)->f0=func_0201C440((void *)(((struct Obj04580 *)p)->f1C));
    func_021E23C8(p,arg);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x14)=(int)func_021FD760(((struct Obj01567 *)arg)->f8,(char *)(*(int *)&((struct Obj01567 *)arg)->fC),i,((struct Obj04580 *)p)->f1C);
    return 1;
}


/*
 * Extent remainder: zero alignment halfword at 021E20F6.
 */
int func_021E20A4(int obj,int b,char *arg,char *p)
{
    int i;
    for (i=0;i<2;i++) func_021FD820((char *)(*(int *)(p+i*4+0x14)));
    if (((struct Obj24648 *)(*(char * *)&((struct Obj10757 *)p)->f20))->f1C) func_021E24AC(p,arg);
    else { func_021E24AC(p,arg); func_021E24C4(p,arg); }
    func_0201C4C0((struct PrintSys *)(((struct Obj10757 *)p)->f0));
    func_021FD714((void *)(((struct Obj10757 *)p)->f8));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}


int func_021E20F8(int a,int b,int c,char *p)
{
    int i;
    func_021FD71C((u8 *)(((struct Obj06612 *)p)->f8));
    if (func_021FD72C((int *)(((struct Obj06612 *)p)->f8))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x14)));
    func_0201C4E4((struct PrintSys *)(((struct Obj06612 *)p)->f0));
    if (((struct Obj06612 *)p)->f4) func_021FD1BC((void *)(((struct Obj06612 *)p)->f4));
    for (i=0;i<2;i++) if (*(int *)(p+i*4+0xc)) func_021FC830((u8 *)(*(int *)(p+i*4+0xc)));
    return 0;
}


void func_021E214C(int *task,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(((struct Obj24649 *)(*(char * *)&((struct Obj14442 *)p)->f20))->f4,2,3,0); *state=1; break;
    case 1: if (func_021FE7B0(*(int * *)&((struct Obj24650 *)(*(char * *)&((struct Obj14442 *)p)->f20))->f4)) *state=2; break;
    case 2: func_021FD73C(task,(int)func_021E21E0); break;
    }
}


void func_021E2194(int *task,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(((struct Obj24651 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f4,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0(*(int * *)&((struct Obj24652 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f4)) *state=2; break;
    case 2: func_021F9BA0((unsigned int *)(((struct Obj24653 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f10)); func_021FD744(task); break;
    }
}
