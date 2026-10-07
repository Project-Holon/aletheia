/*
 * file:     br_codein_p24.c
 * unit:     yes
 * function: func_021E111C, func_021E11D0, func_021E1244, func_021E1374, func_021E138C, func_021E13D8, func_021E13FC, func_021E16E4, func_021E1708, func_021E1850, func_021E1910
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
 *   func_021E1BA8 0x021E1BA8 thumb ov183
 *   func_02051C88 0x02051C88 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_021E0CE8 0x021E0CE8 thumb ov183
 *   func_021E1C14 0x021E1C14 thumb ov183
 *   func_021E1C44 0x021E1C44 thumb ov183
 *   func_021E0D00 0x021E0D00 thumb ov183
 *   func_021E1C00 0x021E1C00 thumb ov183
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 *   d_021E3858 0x021E3858 data a4
 *   func_021E0D90 0x021E0D90 thumb ov183
 *   func_020457B0 0x020457B0 arm
 *   func_02045AA8 0x02045AA8 arm
 *   func_0201F35C 0x0201F35C thumb
 *   _ull_mul 0x0209C054 arm
 *   d_021E3880 0x021E3880 data a2
 *   func_021E19EC 0x021E19EC thumb ov183
 *   func_02051B84 0x02051B84 arm
 */
#include "../../matched/include/Obj03882.h"
#include "../../matched/include/Obj01768.h"
#include "../../matched/include/Obj00143.h"
#include "../../matched/include/Obj00417.h"
#include "../../matched/include/Obj00478.h"
#include "../../matched/include/Obj00732.h"
#include "../../matched/include/Obj03331.h"

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
struct Pair;
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

typedef struct {u32_021E13FC x,y;} Pair;

typedef unsigned long u32_021E1708;

typedef unsigned long long u64;

typedef struct {int tag,value,mode,handle; char rest[12];} Record;

typedef unsigned long u32_021E1910;

typedef struct {short a,b,c,d;} Row_021E1910;

typedef struct {Row_021E1910 row[12];} Table_021E1910;

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
extern void func_021E1BA8(char *);
extern s32_021E13D8 func_02051C88(struct Ctx *c);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021E13FC which);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021E0E40(int,int);
extern void func_021E0CE8(char *p, int index, int a2);
extern int func_021E1C14(char *,int);
extern int func_021E1C44(const char *p, int a);
extern void func_021E0D00(char *,int);
extern void func_021E1C00(char *);
extern void func_021E0D90(char *);
extern struct U16Vec *func_020457B0(u32_021E1708 capacity, u32_021E1708 heapId);
extern void func_02045AA8(struct U16Vec *dst, struct U16Vec *src);
extern void func_0201F35C(void *, int, u32_021E1708, u32_021E1708, u32_021E1708);
extern void func_021E19EC(u32_021E1910 idx, int arg, char *p);
extern void *func_02051B84(u8 *,int,int,int);
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
extern const int d_021E3850[];
extern const Table_021E1244 d_021E3868;
extern const int d_021E3998[],d_021E397C[];
extern const Table_021E1910 d_021E3880;

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
    Pair scale;
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
                    func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                    ++((struct Obj00417 *)record)->f19;
                }
                if(i>=((struct Obj00478 *)p)->f250&&i<((struct Obj00478 *)p)->f254){
                    factor=*(int *)((u32_021E13FC)d_021E397C+((struct Obj00417 *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
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
                func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                ++((struct Obj00417 *)record)->f19;
            }
        }
        for(i=((struct Obj00478 *)p)->f250;i<((struct Obj00478 *)p)->f254;i++){
            record=(char *)((u32_021E13FC)p+i*28);
            if(((struct Obj00417 *)record)->f19!=6){
                factor=*(int *)((u32_021E13FC)d_021E397C+((struct Obj00417 *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                func_0204B5AC(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
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
