/*
 * function: func_021CE9E4
 * address:  0x021CE9E4
 * packet:   pkt_ov021_021CE9E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0, f4, f8, fc, f10, f14, f18;
} S;

struct MsgBank;
struct P;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_02190F7C(struct P *p);
extern void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);

void func_021CE9E4(S *p, u32 m)
{
    u32 n;

    if (m == 8 && *(u16 *)((u8 *)p + 0x57a) == 8)
        return;
    *(u16 *)((u8 *)p + 0x57a) = m;
    n = (u32)func_02045EC0((struct MsgBank *)p->f8, m);
    func_0201F250((struct WordSet *)p->f4, (void *)p->f18, (void *)n);
    func_02045808((struct U16Vec *)n);
    func_02190F7C((struct P *)p->f14);
    func_02190EB8((struct P *)p->f14, 0, 0, p->f18);
}
