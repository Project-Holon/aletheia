/*
 * function: func_021BE934
 * address:  0x021BE934
 * packet:   pkt_021BE934
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   d_021C3AC8     0x021C3AC8  data  a1
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021BEB6C  0x021BEB6C  thumb  ov217
 *
 * blocker: codegen only, 11 bytes. All 8 relocations resolve (d_021C3AC8 as
 *   one symbol, the four field pool words are addends +0..+3). The sole
 *   difference is register allocation: the original keeps the switch value
 *   (`ldr r1, [r0, #0x34]`) and the dispatch index in r1/r2, this source
 *   puts it in r0/r1 because mwccarm is free to overwrite the dead argument
 *   register r0. Tried: named local, direct p->f34 struct member, repeated
 *   `*(int *)(p + 0x34)` expression, and struct-typed parameter; all give
 *   r0. Byte-identical otherwise (table and bodies line up).
 */

typedef unsigned char u8;

typedef struct E {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 pad[0x20];
} E;

extern E d_021C3AC8[];
extern void func_020413B0(int, int, int, int, int, int);
extern int func_020409B4(int);
extern void func_021BEB6C(void);

int func_021BE934(char *p)
{
    switch (*(int *)(p + 0x34)) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(int *)(p + 0x34)].a,
                      d_021C3AC8[*(int *)(p + 0x34)].b,
                      d_021C3AC8[*(int *)(p + 0x34)].c,
                      d_021C3AC8[*(int *)(p + 0x34)].d, 0xa);
        break;
    case 1:
        func_020413B0(2, 0xd, 4, 0x13, 4, 0xa);
        func_020413B0(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        func_021BEB6C();
        break;
    }
    return func_020409B4(2);
}
