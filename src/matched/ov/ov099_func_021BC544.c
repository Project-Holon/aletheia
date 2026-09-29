/*
 * unit:     yes
 * function: func_021BC544
 * function: func_021BC5C0
 * function: func_021BC5D4
 * function: func_021BC5E8
 * address:  0x021BC544
 * packet:   pkt_ov099_021BC544
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C37DC     0x021C37DC  data  a4
 *   func_0203D378  0x0203D378  arm
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *
 * Unit of the lead function plus three unlabelled tail-call stubs
 * (0x021BC5C0/5D4/5E8) that store 0x4b/0x4c/0x4d at +0x132c and tail-call it.
 * The ov099 hint on the 12-byte table is contested, so the data token is bare.
 * The 0x242 offset is an enum-typed local (keeps r4 live, 0x1CC = o - 0x76).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef struct { u32 a, b, c; } Tri;
typedef enum { K242 = 0x242 } Off;

extern const Tri d_021C37DC;
extern int func_0203D378(void);
extern void func_021BA874(char *p, int id);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);
extern int func_020399A8(void);
extern void func_02039C68(u32 h, u32 a, u32 b);

int func_021BC544(char *p, int v);

int func_021BC544(char *p, int v)
{
    Tri t = d_021C37DC;
    Off o;

    if (func_0203D378() == 0) {
        o = K242;
        func_021BA874(p, *(u16 *)(p + o) - 1);
        func_021BAAB8(p, ((u32 *)&t)[*(u16 *)(p + 0x132c) - 0x4b], 0);
        *(u32 *)(p + (o - 0x76)) = 0x4f;
    } else {
        func_021BAAB8(p, 0x4c, 0);
        func_021BC090(p);
        func_02039C68(func_020399A8(), 0x1b, 0xa);
        *(u32 *)(p + 0x1CC) = 0x49;
    }
    return v;
}

int func_021BC5C0(char *p, int v)
{
    *(u16 *)(p + 0x132c) = 0x4b;
    return func_021BC544(p, v);
}

int func_021BC5D4(char *p, int v)
{
    *(u16 *)(p + 0x132c) = 0x4c;
    return func_021BC544(p, v);
}

int func_021BC5E8(char *p, int v)
{
    *(u16 *)(p + 0x132c) = 0x4d;
    return func_021BC544(p, v);
}
