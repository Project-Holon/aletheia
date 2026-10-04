/*
 * function: func_021BB534
 * address: 0x021BB534
 * packet: pkt_ov217_021BB534
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BB910 retains visibly supplied r1=10 through C0E4C to C0EA4.
 * symbols:
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BBD14 0x021BBD14 thumb ov217
 *   func_021BBD28 0x021BBD28 thumb ov217
 *   func_021BBD18 0x021BBD18 thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BC72C 0x021BC72C thumb ov217
 *   func_021C1038 0x021C1038 thumb ov217
 *   func_021BC4B4 0x021BC4B4 thumb ov217
 *   func_021BBBE4 0x021BBBE4 thumb ov217
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BC2D8 0x021BC2D8 thumb ov217
 *   func_021BC338 0x021BC338 thumb ov217
 *   func_021BC43C 0x021BC43C thumb ov217
 *   func_021BC168 0x021BC168 thumb ov217
 *   func_021BC014 0x021BC014 thumb ov217
 *   func_021BBF60 0x021BBF60 thumb ov217
 *   func_021BC2FC 0x021BC2FC thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021BB98C(void *);
extern void func_021BBD14(void *, unsigned);
extern void func_021BBD28(int, int);
extern void func_021BBD18(int, int);
extern unsigned func_021BC580(unsigned, unsigned);
extern void func_021BC72C(u8 *, unsigned, u8 *);
extern unsigned func_021C1038(unsigned, unsigned);
extern void func_021BC4B4(char *);
extern void func_021BBBE4(u8 *);
extern void func_021BB990(void *);
extern void func_021BC2D8(u8 *);
extern void func_021BC338(u8 *);
extern void func_021BC43C(u8 *);
extern void func_021BC168(unsigned);
extern void func_021BC014(u8 *);
extern void func_021BBF60(u8 *);
extern int func_021BC2FC(void *);
extern void func_021BB91C(void *);
extern void func_021BB910(u8 *, unsigned);
void func_021BB534(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBD14(p, 0);
        func_021BBD28((int)p, 1);
        func_021BBD18((int)p, 0);
        func_021BC580((unsigned)p, 3);
        func_021BC72C(p, 0, (u8 *)1);
        func_021BC72C(p, 1, (u8 *)1);
        func_021BC72C(p, 2, (u8 *)1);
        if (*(unsigned *)(p + 0x15c) == 0) {
            func_021C1038(*(unsigned *)(p + p[0x32] * 4 + 0xb4), 14);
            func_021BC4B4((char *)p);
        }
        func_021BBBE4(p);
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
            func_021BB91C(p);
            func_021BB910(p, 10);
        }
        break;
    }
}
