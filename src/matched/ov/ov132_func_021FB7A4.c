/*
 * function: func_021FB7A4
 * address: 0x021FB7A4
 * packet: pkt_ov132_021FB7A4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Original caller narrows both 021F9140 arguments to bytes,
 * overriding its own source's wider parameters; 021F9AD8 index is byte too.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9140 0x021F9140 thumb ov132
 *   func_021F9AD8 0x021F9AD8 thumb ov132
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern void func_021F9140(unsigned char *,unsigned char,unsigned char);
extern void func_021F9AD8(char *,int,unsigned char);
int func_021FB7A4(int unused,char *p) { char *obj; unsigned int index,n; obj=*(char **)p;index=func_0201134C(*(struct Cursor **)(p+4));n=func_0201134C(*(struct Cursor **)(p+4));func_021F9140(*(unsigned char **)(obj+0x34),n,index);func_021F9AD8(*(char **)(obj+0x34),1,index);return 0; }
