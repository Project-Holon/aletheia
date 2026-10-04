/*
 * function: func_021BBDEC
 * address:  0x021BBDEC
 * packet:   pkt_ov091_021BBDEC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02027FEC  0x02027FEC  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    short b;
    int flag;
} S;

typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void func_02045808(struct U16Vec *vec);

int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5)
{
    S s;
    int r;
    s.a = (int)func_02045EC0((struct MsgBank *)(*(int *)(p + 0x134)), id);
    s.b = 0x39e3;
    if (a5 == 0) {
        s.flag = 0;
    } else {
        s.flag = 1;
    }
    r = func_02027FEC(*(int *)(p + 0x254), (u32)(&s), r3, a4, 10, *(u16 *)p);
    func_02045808((struct U16Vec *)s.a);
    return r;
}
