/*
 * function: func_021BAB40
 * address: 0x021BAB40
 * packet: pkt_ov093_021BAB40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BABEC 0x021BABEC thumb ov093
 *   func_021BAC04 0x021BAC04 thumb ov093
 *   func_021BB7FC 0x021BB7FC thumb ov093
 *   func_021BB9D0 0x021BB9D0 thumb ov093
 */

extern void func_021BABEC(void *, void *);
extern void func_021BAC04(void);
extern void func_021BB7FC(void *);
extern void func_021BB9D0(void *);
void func_021BAB40(char *p)
{
 func_021BABEC(p, (void *)func_021BAC04);
 func_021BB7FC(p);
 func_021BB9D0(*(void **)(p + 0x44));
}
