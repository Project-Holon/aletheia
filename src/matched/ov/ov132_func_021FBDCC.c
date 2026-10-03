/*
 * function: func_021FBDCC
 * address: 0x021FBDCC
 * packet: pkt_ov132_021FBDCC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 021F6B18's own source reads r0 only; this caller additionally
 * supplies r1 as a narrowed halfword, retained as an unused second input.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F6B18 0x021F6B18 thumb ov112
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
struct Object; struct Entry;
extern struct Object *func_021F9DAC(void *);
extern struct Entry *func_021F6B18(struct Object *,unsigned short);
extern void func_021F9DB8(void *,struct Entry *,unsigned char);
int func_021FBDCC(int unused,char *p) { char *obj; unsigned int a,b; struct Entry *entry;obj=*(char **)p;a=func_0201134C(*(struct Cursor **)(p+4));b=func_0201134C(*(struct Cursor **)(p+4));entry=func_021F6B18(func_021F9DAC(*(void **)(obj+0x34)),b);func_021F9DB8(*(void **)(obj+0x34),entry,a);return 0; }
