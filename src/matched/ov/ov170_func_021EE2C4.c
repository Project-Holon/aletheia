/*
 * function: func_021EE2C4
 * address: 0x021EE2C4
 * packet: pkt_ov170_021EE2C4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021EE3CC 0x021EE3CC thumb ov170
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_021EE408 0x021EE408 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   d_021F02F0 0x021F02F0 data a4
 */
typedef struct { unsigned a, b; } Pair;
extern const Pair d_021F02F0[];
typedef unsigned char  u8;
struct Struct_02025D1C;
extern u8 func_020355C4(void);
extern void func_021EE3CC(char **);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Struct_02025CD0;
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_02025D1C(struct Struct_02025D1C *obj);
extern void func_021EE408(char **, int);
extern void func_021ED55C(char **, int);
void func_021EE2C4(char **p)
{
    int f;
    int i;
    f = func_020355C4() == 1 ? 0 : 1;
    switch (*(unsigned *)(p[0] + 0x24)) {
    case 0: i = 0; break;
    case 1: i = 2; break;
    case 2: i = 3; break;
    case 3: i = 7; break;
    case 4: i = 13; break;
    case 5: i = 15; break;
    }
    func_021EE3CC(p);
    *(void **)(p[11] + 0x70) = func_02025CD0(d_021F02F0[i].a, d_021F02F0[i].b, (u32)p, f, ((unsigned *)p)[9], 0x4c);
    func_02025D1C(*(void **)(p[11] + 0x70));
    func_021EE408(p, ((int *)p)[9]);
    func_021ED55C(p, f);
    *(int *)(p[11] + 0xa168) = ((int *)p)[9];
}
