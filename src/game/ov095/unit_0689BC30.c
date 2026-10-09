/*
 * file:     unit_0689BC30.c
 * function: func_0689BC30
 * address: 0x0689BC30
 * packet: pkt_ov095_0689BC30
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: BD40 returns Word passed by value to BD50/BD70, reserving the
 *   original two frame words; node declaration before species fixes r4/r5.
 * symbols:
 *   func_0689BD30 0x0689BD30 thumb ov095
 *   func_0689BD40 0x0689BD40 thumb ov095
 *   func_0689BD50 0x0689BD50 thumb ov095
 *   func_0689BD60 0x0689BD60 thumb ov095
 *   func_0689BD70 0x0689BD70 thumb ov095
 *   func_0689BD80 0x0689BD80 thumb ov095
 *   func_0689BD90 0x0689BD90 thumb ov095
 *   func_0689BDA0 0x0689BDA0 thumb ov095
 *   func_0689BDB0 0x0689BDB0 thumb ov095
 *   func_0689BDC0 0x0689BDC0 thumb ov095
 *   func_0689BDD0 0x0689BDD0 thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int v; } Word;
typedef struct { u32 f0; u16 f4; u8 f6, f7; u16 f8; u8 fa, fb; u8 data[0x174]; } Node;
extern int func_0689BD30(u32);
extern Word func_0689BD40(u32, int);
extern int func_0689BD50(Word);
extern Node *func_0689BD60(u32, int, u32);
extern int func_0689BD70(Word);
extern int func_0689BD80(u32, int);
extern int func_0689BD90(u32, u32);
extern void func_0689BDA0(void *, int, int);
extern void func_0689BDB0(void *, u32);
extern void func_0689BDC0(void *, int);
extern void func_0689BDD0(u32, Node *);
void func_0689BC30(u32 a, u32 b, u32 c)
{
    Word value;
    Node *node;
    int species;
    int special;
    if (func_0689BD30(b) != 0)
        return;
    value = func_0689BD40(b, 8);
    species = func_0689BD50(value);
    special = -1;
    switch (species) {
    case 0x23: special = 0x277; break;
    case 0x14: special = 0x276; break;
    case 0x53: special = 0x278; break;
    case 0x1cf: special = 0x279; break;
    case 0x80: special = 0x27a; break;
    case 0xfa: special = 0x27b; break;
    case 0x148: special = 0x27c; break;
    }
    node = func_0689BD60(a, 7, c);
    node->f6 = c;
    if (func_0689BD70(value) != 0)
        node->f4 = func_0689BD80(b, 8);
    else
        node->f4 = func_0689BD80(b, 16);
    if (special != -1) {
        node->f7 = 2 | node->f7;
        node->f8 = special;
        node->fa = func_0689BD90(a, c);
        node->fb = 6;
    }
    func_0689BDA0(node->data, 2, 0x174);
    func_0689BDB0(node->data, c);
    func_0689BDC0(node->data, species);
    func_0689BDD0(a, node);
}
