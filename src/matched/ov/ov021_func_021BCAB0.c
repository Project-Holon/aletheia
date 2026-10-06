/*
 * function: func_021BCAB0
 * address:  0x021BCAB0
 * packet:   pkt_ov021_021BCAB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD118  0x021BD118  thumb  ov021
 *   func_02013E4C  0x02013E4C  thumb
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_021BCB48  0x021BCB48  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb
 *   func_0215841C  0x0215841C  thumb
 *   func_021583EC  0x021583EC  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_020458F8  0x020458F8  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern u16 func_021BD118(u8 *p);
extern unsigned int func_02013E4C(unsigned int id);
extern int func_021BC5BC(u8 *a);
extern int func_021BCB48(int *p, int b);
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *a);
extern int func_02158344(int a);
extern int func_0215841C(int a);
extern int func_021583EC(int a, int b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);

void func_021BCAB0(int *p)
{
    int r6, r7;
    unsigned int r4;

    r6 = func_021BD118((u8 *)((int)p));
    r4 = func_02013E4C((unsigned int)r6);
    if (r4 >= 0x75) {
        r4 = 0;
    }
    if (r4 == 0) {
        func_021BC5BC((u8 *)p);
        return;
    }
    if (func_021BCB48((int *)((int)p), r6) != 0) {
        func_02158344((int)func_02012138((const struct Ctx *)p[0]));
        r7 = func_021583EC(p[1], func_0215841C(p[1]));
        r6 = (int)func_02045EC0((struct MsgBank *)p[5], 3);
        func_02045CAC((struct MsgBank *)p[5], r4, (void *)p[7]);
        func_0201F02C((struct WordSet *)p[2], 0, (void *)r7);
        func_0201F158((struct WordSet *)p[2], 1, r4);
        func_0201F250((struct WordSet *)p[2], (void *)p[7], (void *)r6);
        func_02045808((struct U16Vec *)r6);
    } else {
        func_02045CAC((struct MsgBank *)p[5], r4, (void *)p[7]);
    }
    *((unsigned char *)p + 0x20) = func_020458F8((struct U16Vec *)p[7]);
}
