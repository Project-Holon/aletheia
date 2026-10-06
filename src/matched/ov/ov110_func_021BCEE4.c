/*
 * function: func_021BCEE4
 * address: 0x021BCEE4
 * packet: pkt_ov110_021BCEE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCF16.
 * symbols:
 *   func_021BCDE0 0x021BCDE0 thumb ov110
 *   func_021BCE24 0x021BCE24 thumb ov110
 *   func_021BCE54 0x021BCE54 thumb ov110
 *   func_021BCEA0 0x021BCEA0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BCDE0(u8 *p);
extern void func_021BCE24(void *);
extern void func_021BCE54(char *);
extern void func_021BCEA0(char *);
void func_021BCEE4(char *p,u32 mode) { switch(mode) { case 0: func_021BCDE0((u8 *)p); break; case 1: func_021BCE24(p); break; case 2: func_021BCE54(p); break; case 3: func_021BCEA0(p); break; } }
