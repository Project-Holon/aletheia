/*
 * function: func_02026FB8
 * address:  0x02026FB8
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f00;
    u32 f04 : 17;
    u32 f04hi : 15;
    u32 f08 : 17;
    u32 f08b : 5;
    u32 f08hi : 10;
    u32 f0clo : 16;
    u32 f0c : 10;
    u32 f0chi : 6;
    u8  pad10[0x5c - 0x10];
    u16 f5c;
    u8  f5e;
} Obj;

extern void *g_02146940;

extern void *func_02012EBC(void *a);
extern void *func_02012FCC(void *a);
extern void *func_0200C0F0(void *a);
extern u32   func_0200864C(void *a);
extern u32   func_02008650(void *a);
extern u32   func_0200C1C4(void *a);
extern u32   func_0200C1DC(void *a);

void func_02026FB8(Obj *o)
{
    void *a;
    void *b;

    a = func_02012EBC(*(void **)g_02146940);
    b = func_02012FCC(*(void **)g_02146940);
    a = func_0200C0F0(a);
    o->f0c = func_0200864C(b);
    o->f0chi = func_02008650(b);
    o->f08 = func_0200C1C4(a);
    o->f04 = func_0200C1DC(a);
    o->f08b = o->f08b + 1;
    o->f5c = 0;
    o->f5e = 1;
}
