/*
 * function: func_02184ECC
 * address:  0x02184ECC
 * packet:   pkt_ov023_02184ECC
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02185F74  0x02185F74  thumb  ov023
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w;
    u8 f;
} Ent;

typedef struct {
    char pad0[0x104];
    u32 win[7];
    char pad120[0xc];
    Ent ent[7];
    u32 f164;
    u32 f168;
    u32 f16c;
    u32 f170;
} W;

extern void func_02045088(u16 heapId);
extern u32  func_020450F0(u32 a, u32 b, u8 c, u32 d, u32 e, u32 f, u32 g);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(u32 a, u32 b);
extern u32  func_0203101C(u32 a, u32 b, u32 c, u32 d);
extern u32  func_0201C440(u16 heap);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern u32  func_02045730(u32 a);
extern void func_020409B4(u32 a);
extern void func_02185F74(u32 *a, int b, W *p);

void func_02184ECC(W *p)
{
    int i;
    u32 w;

    func_02045088(0x28);
    p->win[6] = func_020450F0(0, 2, 1, 0x1b, 4, 0xd, 1);
    func_02043B5C((u32)func_02045770((struct Descriptor *)p->win[6]), 0xf);
    p->ent[6].w = p->win[6];
    p->ent[6].f = 0;
    p->win[5] = func_020450F0(1, 1, 2, 0x1e, 0xf, 0, 1);
    func_02043B5C((u32)func_02045770((struct Descriptor *)p->win[5]), 2);
    p->f170 = func_0203101C(0x28, 0x28, 0x20, 0x20);
    p->f164 = func_0201C440(0x28);
    p->f168 = func_0201C440(0x28);
    for (i = 0; i < 5; i++) {
        p->win[i] = func_020450F0(4, 5, i * 4 + 3, 0xa, 2, 0xd, 1);
        func_02043B5C((u32)func_02045770((struct Descriptor *)p->win[i]), 0);
        p->ent[i].w = p->win[i];
        p->ent[i].f = 0;
        w = p->win[i];
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
    }
    func_02185F74(p->win, 0x44f, p);
}
