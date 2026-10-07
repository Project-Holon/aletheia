/*
 * file:     zukan_p03.c
 * unit:     yes
 * function: func_021C9288, func_021C92EC, func_021C9348, func_021C9380, func_021C93A8, func_021C93C4, func_021C93E4, func_021C940C, func_021C9428, func_021C9460, func_021C9468, func_021C976C, func_021C983C, func_021C98A8
 * address:  0x021C9288
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_0200CA8C 0x0200CA8C thumb
 *   func_0200CA78 0x0200CA78 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   open 0x020490F4 arm
 *   close 0x02049238 arm
 *   initial 0x021C983C thumb ov212
 *   tables 0x021C98A8 thumb ov212
 *   alloc 0x02030734 arm
 *   release 0x020307B0 arm
 *   known 0x0200D064 thumb
 *   properties 0x0200CC40 thumb
 *   seen 0x0200CED4 thumb
 *   personalFree 0x0201AE14 thumb
 *   personal 0x0201ADE4 thumb
 *   value 0x0201AE1C thumb
 *   finalTest 0x021C9918 thumb ov212
 *   site 0x021C99A8 data ov212 a1
 *   load 0x0204A298 arm
 *   names 0x0201AF80 thumb
 *   func_0204A39C  0x0204A39C  arm
 *   g_021C99A8     0x021C99A8  data
 *   g_021C9968     0x021C9968  data
 *   func_0201AF80  0x0201AF80  thumb
 */
#include "../../matched/include/Obj08418.h"
#include "../../matched/include/Obj03938.h"

struct Blk37;
struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

struct Query { u8 mode; u8 rule; u8 kind; u8 type1; u8 type2; u8 attr; u8 last; };

struct Search {
  void *save; struct Query *query; u16 state; u16 padA; void *arc;
  u16 index; u16 count; u16 *ids; u8 *reject;
  u16 count1; u16 pad1; u16 *table1; u16 count2; u16 pad2; u8 *table2;
  u16 count3; u16 pad3; u8 *table3; u16 count4; u16 pad4; u16 *table4;
  void *personal; u16 resultCount; u16 pad42; u16 *result;
};

extern unsigned func_0200CA70(struct Blk37 *);
extern unsigned func_0200CED4(struct Blk37 *,u16);
extern unsigned func_0200D064(struct Blk37 *,u16);
extern u16 func_0200CA8C(struct Blk37 *p);
extern void func_0200CA78(struct Blk37 *p, u32 v);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_02041EE4(u32,u32,u32);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
extern void *open(u32, u16);
extern void close(void *);
extern u32 initial(void *, int, int, u32, u16 **);
extern void tables(void *, u32, u16 *, u16 **, u16 *, u8 **, u16 *, u8 **, u16 *, u16 **);
extern void *alloc(u32, u32, int, const char *, u16);
extern void release(void *);
extern u32 known(void *, u16);
extern void properties(void *, u16, u32 *, u32 *, u32 *, u16);
extern u32 seen(void *, u16);
extern void personalFree(void *);
extern void *personal(u32, int, u32);
extern u32 value(const void *, u32);
extern u8 finalTest(const u8 *, const u16 *, u32, u32);
extern void *load(int,int,int,int,u32 *);
extern u16 *names(int,u16 *);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
u16 func_021C9288(struct Blk37 *save,u16 **out,unsigned heap);
void func_021C92EC(void *p,u16 *ids,unsigned count);
int func_021C9348(struct Blk37 *p);
void func_021C9380(struct Blk37 *p, u8 *out);
void func_021C93A8(u32 heap);
void func_021C93C4(u32 heap);
void func_021C93E4(u32 a, u32 b, u32 *counter);
struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);
void func_021C9428(int p, int b, int c);
void func_021C9460(int a0);
int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out);
u32 func_021C976C(u32 mode,int heap,u16 **out);
unsigned int func_021C983C(int a0, int a1, int a2, int a3, u16 **out);
void func_021C98A8(u32 a0, u32 a1, u16 *a2, u32 *a3, u16 *a4, u32 *a5, u16 *a6, u32 *a7, u16 *a8, u32 *a9);
extern const char site[];
extern const char g_021C99A8[];
extern int g_021C9968[];

/*
 * lever: branch-local calls retain the original boolean polarity and hoist
 * the shared output-address setup; initializing selected follows the call.
 */
u16 func_021C9288(struct Blk37 *save,u16 **out,unsigned heap)
{
    u16 *list;
    unsigned count,i;
    u16 selected;
    if(func_0200CA70(save)==1)count=func_021C976C(0,heap,&list);
    else count=func_021C976C(1,heap,&list);
    selected=0;
    for(i=0;i<count;i++){
        if(func_0200CED4(save,list[i])==1||func_0200D064(save,list[i])==1)selected=i+1;
    }
    *out=list;
    return selected;
}

void func_021C92EC(void *p,u16 *ids,unsigned count)
{
    unsigned current;
    u16 chosen,i;
    chosen=0xFFFF;current=func_0200CA8C(p);
    for(i=0;i<count;i++) {
        if(func_0200D064(p,ids[i])==1) {
            if(current==ids[i]) return;
            if(chosen==0xFFFF) chosen=ids[i];
        }
    }
    if(chosen!=0xFFFF) func_0200CA78(p,chosen);
}

int func_021C9348(struct Blk37 *p) {
    if (func_0200CA70(p) == 1) return 1;
    if (func_0200CED4(p,494) == 1 || func_0200D064(p,494) == 1) return 1;
    return 0;
}

void func_021C9380(struct Blk37 *p, u8 *out) {
    if(func_0200CA70(p)==1) out[0]=0; else out[0]=1;
    out[1]=0; out[2]=255; out[3]=255; out[4]=255; out[5]=255; out[6]=255;
}

void func_021C93A8(u32 heap) { func_0202208C(0,1,1,0,6,1,heap); }

void func_021C93C4(u32 heap) { func_0202208C(0,0,0,0,6,1,heap); }

void func_021C93E4(u32 a, u32 b, u32 *counter) {
    ++*counter;
    if(*counter==4) { func_02041EE4(a,1,1); func_02041EE4(b,1,1); *counter=0; }
}

struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap) {
    return func_0204B294((void *)bank,*(const u32 *)&((struct Obj08418 *)t)->f8,*(const u32 *)&((struct Obj08418 *)t)->fC,*(const u32 *)&((struct Obj08418 *)t)->f10,t,*(const u16 *)&((struct Obj08418 *)t)->f16,heap);
}


void func_021C9428(int p, int b, int c)
{
    unsigned char *q = func_02030734(c, 0x48, 1, (const char *)0x021C99A8, 0x1ce);

    ((struct Obj03938 *)q)->f0 = p;
    ((struct Obj03938 *)q)->f4 = b;
    ((struct Obj03938 *)q)->f8 = 0;
    ((struct Obj03938 *)q)->fC = 0;
    ((struct Obj03938 *)q)->f10 = 0;
    ((struct Obj03938 *)q)->f3C = 0;
    ((struct Obj03938 *)q)->f40 = 0;
    ((struct Obj03938 *)q)->f44 = 0;
}


/*
 * Bottom-up unblocker for the last unresolved site of
 * src/pending/func_021BD3AC.c.  Thumb tail-call veneer into the ARM9
 * func_020307B0 (the image is `ldr r3,[pc,#0]; bx r3; .word 0x020307B0`);
 * disasm emits it as an unlabelled `.word` run, so no listing class attests
 * it.  Addresses are Black-image addresses.
 */
void func_021C9460(int a0)
{
    func_020307B0((void *)a0);
}

/*
 * note 2026-10-05 (P24L1): rewritten from the listing, bytes equal (772/772). Only relocation
 *   without a witness is finalTest 0x021C9918; the leaf is filed as src/matched/ov/ov212_func_021C9918.c
 *   (EXACT c99 and c), so a manifest refresh should resolve it and promote this file to EXACT.
 *   Levers that closed it from 483 B off: (1) calls with each reject written as
 *   p->reject[i] = 1; continue; at every failing test (raises the use count of i, so i keeps r5
 *   and form takes the spill slot; the tail merges back to one store), (2) u16 of = outForm read
 *   once and used for both the 649 test and the compare, (3) u16 count, (4) u8 fr = finalTest(..)
 *   local before the compare to the query byte (cmp operand order), (5) u16 n = p->count read
 *   before i = p->index (load order at the top of case 3), (6) mask = 1023 as a local gives the
 *   ldr 999; adds 0x18 pair. Older draft docs/notes/pkt_ov212_021C9468.c.txt is superseded.
 */
int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out)
{
  u32 unused1, unused2, outForm;
  u16 end, i, j, used, species, form;
  u16 count;
  u16 *result;
  u8 type1, type2, id;
  u16 of, n;
  switch (p->state) {
  case 0:
    p->arc = open(98, heap);
    p->state = 1;
    break;
  case 1:
    p->count = initial(p->arc, p->query->mode, p->query->rule, heap, &p->ids);
    p->reject = alloc(heap, p->count, 1, site, 551);
    p->state = 2;
    break;
  case 2:
    tables(p->arc, heap, &p->count1, &p->table1, &p->count2, &p->table2, &p->count3, (u8 **)&p->table3, &p->count4, &p->table4);
    p->state = 3;
    break;
  case 3:
    n = p->count;
    i = p->index;
    if (i >= n) { p->state = 4; break; }
    end = i + 7;
    if (end > n) end = n;
    p->index = end;
    for (; i < end; i++) {
      u32 v = p->ids[i];
      species = v & 1023;
      form = (v & 0xFC00) >> 10;
      if (!known(p->save, species)) { p->reject[i] = 1; continue; }
      properties(p->save, species, &unused1, &unused2, &outForm, heap);
      of = outForm;
      if (p->count == 649) form = of;
      if (form != of) { p->reject[i] = 1; continue; }
      if ((p->query->rule >= 2 && p->query->rule <= 5) || p->query->type1 != 255 || p->query->type2 != 255) {
        if (!seen(p->save, species)) { p->reject[i] = 1; continue; }
      }
      if (p->query->mode == 1 && p->table1[species] == 999) { p->reject[i] = 1; continue; }
      if (p->query->kind != 255 && p->query->kind != p->table2[species]) { p->reject[i] = 1; continue; }
      if (p->personal) personalFree(p->personal);
      p->personal = personal(species, form, heap);
      type1 = value(p->personal, 6);
      type2 = value(p->personal, 7);
      if (p->query->type1 != 255 && p->query->type2 != 255) {
        if ((type1 == p->query->type1 && type2 == p->query->type2) || (type1 == p->query->type2 && type2 == p->query->type1)) {
        } else { p->reject[i] = 1; continue; }
      } else if (p->query->type1 != 255 && p->query->type2 == 255) {
        if (type1 != p->query->type1 && type2 != p->query->type1) { p->reject[i] = 1; continue; }
      } else if (p->query->type1 == 255 && p->query->type2 != 255) {
        if (type1 != p->query->type2 && type2 != p->query->type2) { p->reject[i] = 1; continue; }
      }
      if (p->query->attr != 255) {
        id = value(p->personal, 33);
        if (id != p->query->attr) { p->reject[i] = 1; continue; }
      }
      if (p->query->last != 255) {
        u8 fr = finalTest(p->table3, p->table4, species, form);
        if (fr != p->query->last) { p->reject[i] = 1; continue; }
      }
    }
    break;
  case 4:
    if (p->personal) personalFree(p->personal);
    count = 0;
    for (j = 0; j < p->count; j++)
      if (p->reject[j] == 0) count++;
    if (count) {
      used = 0;
      result = alloc(heap, count * 2, 0, site, 742);
      for (j = 0; j < p->count; j++)
        if (p->reject[j] == 0) { result[used] = p->ids[j] & 1023; used++; }
    } else result = 0;
    release(p->ids);
    release(p->reject);
    release(p->table1);
    release(p->table2);
    release(p->table3);
    release(p->table4);
    p->resultCount = count;
    p->result = result;
    close(p->arc);
    p->state = 5;
    break;
  case 5:
  default:
    *out = p->result;
    *outCount = p->resultCount;
    return 1;
  }
  return 0;
}

u32 func_021C976C(u32 mode,int heap,u16 **out)
{
    u16 *result;
    u16 *map;
    u16 *ids;
    u16 count;
    u32 bytes;
    u16 used;
    u16 i;
    u16 n;
    if (mode == 0) {
        used = 0;
        result = alloc(heap,1298,0,site,825);
        do {
            result[used] = used + 1;
            used = used + 1;
        } while (used < 649);
        *out = result;
        return 649;
    }
    map = names(heap,&count);
    used = 0;
    ids = load(98,4,0,heap,&bytes);
    n = (u16)(bytes / 2);
    result = alloc(heap,count * 2,0,site,862);
    for (i = 0; i < n; i++) {
        u16 id;
        id = ids[i];
        if (map[id] != 999) {
            result[used] = id;
            used++;
        }
    }
    release(ids);
    release(map);
    *out = result;
    return count;
}


unsigned int func_021C983C(int a0, int a1, int a2, int a3, u16 **out)
{
    u16 *buf;
    unsigned int n;

    if (a1 == 0 && a2 == 0) {
        u16 i;
        buf = func_02030734(a3, 0x512, 0, g_021C99A8, 0x3B1);
        for (i = 0; i < 0x289;) {
            buf[i] = i + 1;
            i++;
        }
        n = 0x289;
    } else {
        unsigned int tmp;
        buf = (u16 *)func_0204A39C((void *)a0, g_021C9968[a2], 0, a3, &tmp);
        n = (tmp >> 1) & 0xFFFF;
    }
    *out = buf;
    return n;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C98A8(u32 a0, u32 a1, u16 *a2, u32 *a3,
                   u16 *a4, u32 *a5, u16 *a6, u32 *a7, u16 *a8, u32 *a9)
{
    u32 buf;

    *a3 = (u32)func_0201AF80(a1, 0);
    *a2 = 0x28A;
    *a5 = (u32)func_0204A39C((void *)a0, 1, 0, a1, &buf);
    *a4 = buf;
    *a7 = (u32)func_0204A39C((void *)a0, 2, 0, a1, &buf);
    *a6 = buf;
    *a9 = (u32)func_0204A39C((void *)a0, 0, 0, a1, &buf);
    *a8 = buf >> 1;
}
