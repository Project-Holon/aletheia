/*
 * function: func_021C9468
 * address: 0x021C9468
 * packet: pkt_ov212_021C9468
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
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
 * symbols:
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Query { u8 mode; u8 rule; u8 kind; u8 type1; u8 type2; u8 attr; u8 last; };
struct Search {
  void *save; struct Query *query; u16 state; u16 padA; void *arc;
  u16 index; u16 count; u16 *ids; u8 *reject;
  u16 count1; u16 pad1; u16 *table1; u16 count2; u16 pad2; u8 *table2;
  u16 count3; u16 pad3; u8 *table3; u16 count4; u16 pad4; u16 *table4;
  void *personal; u16 resultCount; u16 pad42; u16 *result;
};
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
extern const char site[];
int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out)
{
  u32 unused1, unused2, outForm;
  u32 mask;
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
    mask = 1023;
    for (; i < end; i++) {
      u32 v = p->ids[i];
      species = v & mask;
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
