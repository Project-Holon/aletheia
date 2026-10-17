/*
 * file:     zukan_search_engine.c
 * unit:     yes
 * function: ZUKAN_SEARCH_ENGINE_Create, ZUKAN_SEARCH_ENGINE_ReleaseWork, ZUKAN_SEARCH_ENGINE_Filter, ZUKAN_SEARCH_ENGINE_LoadSpeciesIds, ZUKAN_SEARCH_ENGINE_LoadFormIds, ZUKAN_SEARCH_ENGINE_LoadTables, ZUKAN_SEARCH_ENGINE_FinalTest
 * address:  0x021C9428
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
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
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   g_021C99A8     0x021C99A8  data
 *   g_021C9968     0x021C9968  data
 *   POKE_PERSONAL_LoadFormTable  0x0201AF80  thumb
 */
#include "zukan_shared_types.h"

struct Query { u8 mode; u8 rule; u8 kind; u8 type1; u8 type2; u8 attr; u8 last; };

struct Search {
  void *save; struct Query *query; u16 state; u16 padA; void *arc;
  u16 index; u16 count; u16 *ids; u8 *reject;
  u16 count1; u16 pad1; u16 *table1; u16 count2; u16 pad2; u8 *table2;
  u16 count3; u16 pad3; u8 *table3; u16 count4; u16 pad4; u16 *table4;
  void *personal; u16 resultCount; u16 pad42; u16 *result;
};

extern u32 GFL_HEAP_Free(void *p);

extern void *GFL_HEAP_Alloc(unsigned,unsigned,int,const char *,u16);

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

extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

void ZUKAN_SEARCH_ENGINE_Create(struct Search *p, struct Query *b, int heap);

void ZUKAN_SEARCH_ENGINE_ReleaseWork(int a0);

int ZUKAN_SEARCH_ENGINE_Filter(struct Search *p, u16 heap, u16 *outCount, u16 **out);

u32 ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(u32 mode,int heap,u16 **out);

unsigned int ZUKAN_SEARCH_ENGINE_LoadFormIds(int a0, int a1, int a2, int a3, u16 **out);

void ZUKAN_SEARCH_ENGINE_LoadTables(u32 a0, u32 a1, u16 *a2, u32 *a3, u16 *a4, u32 *a5, u16 *a6, u32 *a7, u16 *a8, u32 *a9);

u8 ZUKAN_SEARCH_ENGINE_FinalTest(const u8 *t, const u16 *u, u32 s, u32 f);

extern const char site[];

extern const char g_021C99A8[];

extern int g_021C9968[];

void ZUKAN_SEARCH_ENGINE_Create(struct Search *p, struct Query *b, int heap)
{
    struct Search *q = GFL_HEAP_Alloc(heap, 0x48, 1, (const char *)0x021C99A8, 0x1ce);

    q->save = p;
    q->query = b;
    q->state = 0;
    q->arc = 0;
    q->index = 0;
    q->personal = 0;
    q->resultCount = 0;
    q->result = 0;
}

/*
 * Bottom-up unblocker for the last unresolved site of
 * src/pending/ZKNSEARCH_MAIN_UpdateSearchEngine.c.  Thumb tail-call veneer into the ARM9
 * GFL_HEAP_Free (the image is `ldr r3,[pc,#0]; bx r3; .word 0x020307B0`);
 * disasm emits it as an unlabelled `.word` run, so no listing class attests
 * it.  Addresses are Black-image addresses.
 */
void ZUKAN_SEARCH_ENGINE_ReleaseWork(int a0)
{
    GFL_HEAP_Free((void *)a0);
}

/*
 * note 2026-10-05 (P24L1): rewritten from the listing, bytes equal (772/772). Only relocation
 *   without a witness is finalTest 0x021C9918; the leaf is filed as src/matched/ov/ZUKAN_SEARCH_ENGINE_FinalTest.c
 *   (EXACT c99 and c), so a manifest refresh should resolve it and promote this file to EXACT.
 *   Levers that closed it from 483 B off: (1) calls with each reject written as
 *   p->reject[i] = 1; continue; at every failing test (raises the use count of i, so i keeps r5
 *   and form takes the spill slot; the tail merges back to one store), (2) u16 of = outForm read
 *   once and used for both the 649 test and the compare, (3) u16 count, (4) u8 fr = finalTest(..)
 *   local before the compare to the query byte (cmp operand order), (5) u16 n = p->count read
 *   before i = p->index (load order at the top of case 3), (6) mask = 1023 as a local gives the
 *   ldr 999; adds 0x18 pair. Older draft docs/notes/pkt_ov212_021C9468.c.txt is superseded.
 */
int ZUKAN_SEARCH_ENGINE_Filter(struct Search *p, u16 heap, u16 *outCount, u16 **out)
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

u32 ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(u32 mode,int heap,u16 **out)
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

unsigned int ZUKAN_SEARCH_ENGINE_LoadFormIds(int a0, int a1, int a2, int a3, u16 **out)
{
    u16 *buf;
    unsigned int n;

    if (a1 == 0 && a2 == 0) {
        u16 i;
        buf = GFL_HEAP_Alloc(a3, 0x512, 0, g_021C99A8, 0x3B1);
        for (i = 0; i < 0x289;) {
            buf[i] = i + 1;
            i++;
        }
        n = 0x289;
    } else {
        unsigned int tmp;
        buf = (u16 *)ARC_UTIL_LoadHandleMemberWithSize((void *)a0, g_021C9968[a2], 0, a3, &tmp);
        n = (tmp >> 1) & 0xFFFF;
    }
    *out = buf;
    return n;
}

/*
 * Addresses are Black-image addresses.
 */
void ZUKAN_SEARCH_ENGINE_LoadTables(u32 a0, u32 a1, u16 *a2, u32 *a3,
                   u16 *a4, u32 *a5, u16 *a6, u32 *a7, u16 *a8, u32 *a9)
{
    u32 buf;

    *a3 = (u32)POKE_PERSONAL_LoadFormTable(a1, 0);
    *a2 = 0x28A;
    *a5 = (u32)ARC_UTIL_LoadHandleMemberWithSize((void *)a0, 1, 0, a1, &buf);
    *a4 = buf;
    *a7 = (u32)ARC_UTIL_LoadHandleMemberWithSize((void *)a0, 2, 0, a1, &buf);
    *a6 = buf;
    *a9 = (u32)ARC_UTIL_LoadHandleMemberWithSize((void *)a0, 0, 0, a1, &buf);
    *a8 = buf >> 1;
}

u8 ZUKAN_SEARCH_ENGINE_FinalTest(const u8 *t, const u16 *u, u32 s, u32 f)
{
    u16 n;
    n = 0;
    if (f != 0) {
        do {
            s = u[s];
            if (s == 0) break;
            n++;
        } while (n != f);
    }
    return t[s];
}
