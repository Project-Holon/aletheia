/*
 * function: func_021EEC78
 * address:  0x021EEC78
 * packet:   pkt_ov093_021EEC78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   d_021F63D8     0x021F63D8  data  ov093  a4
 *   d_021F3990     0x021F3990  data  ov093  a2
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 t[8];
    u8 pad[0x20];
    u32 f50;
    u32 f54;
} G;

typedef struct {
    u8 pad[0x10];
    u16 f10;
    u8 pad2[6];
    u16 f18;
    u16 f1a;
} H;

extern G d_021F6398;
extern H d_021F63D8;
extern const u16 d_021F3990[];
struct MsgBank;
struct U16Vec;
struct WordSet;
extern int func_021BA1A8(char **p, int m);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

void func_021EEC78(u32 a, u32 b, u32 c, u32 d)
{
    int i;

    d_021F6398.f00 = a;
    d_021F6398.f04 = c;
    d_021F63D8.f10 = d;
    d_021F6398.f54 = b;
    d_021F63D8.f18 = func_021BA1A8((char **)a, 0x200);
    d_021F63D8.f1a = 0;
    d_021F6398.f08 = (u32)func_0201EC64(d);
    d_021F6398.f0c = (u32)func_020457B0(0x200 >> 1, d);
    for (i = 0; i < 8; i++) {
        d_021F6398.t[i] = (u32)func_02045B38(0, 2, d_021F3990[i], d);
    }
}
