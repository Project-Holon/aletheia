/*
 * function: func_021FBFA8
 * address: 0x021FBFA8
 * packet: pkt_ov132_021FBFA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Own 021F9EDC source takes u16; original caller passes the
 * full word b+0x33 without truncation, so the extern parameter is widened.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DC0 0x021F9DC0 thumb ov132
 *   func_021F9EDC 0x021F9EDC thumb ov132
 *   func_021F9DCC 0x021F9DCC thumb ov132
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern char *func_021F9DC0(void *);
extern char *func_021F9EDC(char *,unsigned int);
extern void func_021F9DCC(void *,char *,unsigned char);
int func_021FBFA8(int unused,char *p) { char *obj; unsigned int a,b; char *entry;obj=*(char **)p;a=func_0201134C(*(struct Cursor **)(p+4));b=func_0201134C(*(struct Cursor **)(p+4));entry=func_021F9EDC(func_021F9DC0(*(void **)(obj+0x34)),b+0x33);func_021F9DCC(*(void **)(obj+0x34),entry,a);return 0; }
