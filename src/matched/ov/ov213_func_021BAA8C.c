/*
 * function: func_021BAA8C
 * address: 0x021BAA8C
 * packet: pkt_ov213_021BAA8C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * Separate u8 pointer at +10 preserves the hoisted base; declare the index before the count.
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 func_0201AA18(void *);
int func_021BAA8C(char *p) { void *q; u8 *flags; int i,n; q=*(void **)p; n=0; flags=(u8 *)p+10; for(i=0;i<(int)func_0201AA18(q);i++) if(flags[i]<=1) n++; return n; }
