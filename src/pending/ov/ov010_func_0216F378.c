/*
 * function: func_0216F378
 * address: 0x0216F378
 * packet: pkt_ov010_0216F378
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * Blocker: descriptor 021C892C is data in ov111; no outside witness without
 * hint. Pooled request ID is 110, so no proven ov111 loading path yet.
 * symbols:
 *   func_02031324 0x02031324 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_02031348 0x02031348 arm
 *   d_021C892C 0x021C892C data a4
 *   ov110_id 0x0000006E data a1
 * Interface: veneers preserve arguments and result as shown by their full
 * forwarding targets 02031354 and 020314F4.
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02031324(u16);
extern void *func_02012EBC(void *);
extern void func_02031348(void *,u32,const void *,void *);
extern const u32 d_021C892C[];
extern char ov110_id[];
int func_0216F378(char *p) { if (*(void **)(p+8)==0) *(void **)(p+8)=func_02031324(*(u32 *)p); *(void **)(p+12)=func_02012EBC(*(void **)(*(char **)(p+24)+4)); func_02031348(*(void **)(p+8),(u32)ov110_id,d_021C892C,*(void **)(p+24)); return 6; }
