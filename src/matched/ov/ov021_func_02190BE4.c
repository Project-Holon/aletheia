/*
 * function: func_02190BE4
 * address:  0x02190BE4
 * packet:   pkt_ov021_02190BE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D3F38     0x021D3F38  data   ov021  a4
 *   d_021D3E68     0x021D3E68  data   ov021  a4
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_02190B08  0x02190B08  thumb  ov021
 *   func_02190860  0x02190860  thumb  ov021
 *   func_02020D10  0x02020D10  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blk32 { u32 w[8]; } Blk32;
typedef struct Blk16 { u32 w[4]; } Blk16;

extern Blk32 d_021D3F38;
extern Blk16 d_021D3E68;

struct Pair;
struct Rec;
extern int func_021904B0(u32 a, u32 b);
extern u32 func_02190A28(const struct Pair *arr, int n, u32 c, u16 d);
extern u32 func_02045C04(struct Rec *rec);
extern int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f);
extern u32 *func_02190860(u16 *a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
extern void func_02020D10(u8 *p, u32 v);

u32 *func_02190BE4(u16 *a, u32 b)
{
    Blk32 A = d_021D3F38;
    Blk16 B = d_021D3E68;
    u32 r7;
    u32 r18;
    u32 *res;

    r7 = func_021904B0((u32)a, 0xe9);
    r18 = func_02190A28((const struct Pair *)(&B), 2, r7, a[0]);
    func_02045C04((struct Rec *)r7);
    func_02190B08((u32)(&A), 2, 0x18, 0xa, 7, 4);
    res = func_02190860(a, &A, r18, 0, (u16)b, a[3], 0, 0, 0);
    func_02020D10((u8 *)res[4], 0);
    return res;
}
