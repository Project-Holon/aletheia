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
 *   func_021C8010  0x021C8010  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D5B68  0x021D5B68  thumb
 *   func_021D6314  0x021D6314  thumb
 *   func_021D7B74  0x021D7B74  thumb
 *   func_021E8B80  0x021E8B80  thumb
 *   func_021E8C24  0x021E8C24  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int v; } Word;
typedef struct { u32 f0; u16 f4; u8 f6, f7; u16 f8; u8 fa, fb; u8 data[0x174]; } Node;
extern int func_021D5B68(u32);
extern Word func_021D6314(u32, int);
extern int func_021E8B80(Word);
extern Node *func_021C88A4(u32, int, u32);
extern int func_021E8C24(Word);
extern int func_021D7B74(u32, int);
extern int func_021C8010(u32, u32);
extern void func_021C8838(void *, int, int);
extern void func_021C8860();
extern void func_021C88C8(u32, Node *);
void func_0689BC30(u32 a, u32 b, u32 c)
{
    Word value;
    Node *node;
    int species;
    int special;
    if (func_021D5B68(b) != 0)
        return;
    value = func_021D6314(b, 8);
    species = func_021E8B80(value);
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
    node = func_021C88A4(a, 7, c);
    node->f6 = c;
    if (func_021E8C24(value) != 0)
        node->f4 = func_021D7B74(b, 8);
    else
        node->f4 = func_021D7B74(b, 16);
    if (special != -1) {
        node->f7 = 2 | node->f7;
        node->f8 = special;
        node->fa = func_021C8010(a, c);
        node->fb = 6;
    }
    func_021C8838(node->data, 2, 0x174);
    func_021C8860(node->data, c);
    func_021C8860(node->data, species);
    func_021C88C8(a, node);
}
