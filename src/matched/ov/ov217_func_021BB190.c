/*
 * function: func_021BB190
 * address: 0x021BB190
 * packet: pkt_ov217_021BB190
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BB1FE..021BB200 is two zero bytes of alignment padding.
 * symbols:
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BBADC 0x021BBADC thumb ov217
 *   func_021BBAA4 0x021BBAA4 thumb ov217
 *   func_021BC06C 0x021BC06C thumb ov217
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BC2D8 0x021BC2D8 thumb ov217
 *   func_021BC338 0x021BC338 thumb ov217
 *   func_021BC43C 0x021BC43C thumb ov217
 *   func_021BC168 0x021BC168 thumb ov217
 *   func_021BC014 0x021BC014 thumb ov217
 *   func_021BBF60 0x021BBF60 thumb ov217
 *   func_021BC2FC 0x021BC2FC thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021BB98C(void *);
extern void func_021BBADC(u8 *);
extern unsigned func_021BBAA4(unsigned, unsigned);
extern int func_021BC06C(char *);
extern void func_021BB990(void *);
extern void func_021BC2D8(u8 *);
extern void func_021BC338(u8 *);
extern void func_021BC43C(u8 *);
extern unsigned func_021BC168(unsigned);
extern void func_021BC014(u8 *);
extern void func_021BBF60(u8 *);
extern int func_021BC2FC(void *);
extern void func_021BB91C(void *);
void func_021BB190(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBADC(p);
        func_021BBAA4((unsigned)p, p[0x33]);
        func_021BC06C((char *)p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8(p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BBF60(p);
            func_021BB91C(p);
        }
        break;
    }
}
