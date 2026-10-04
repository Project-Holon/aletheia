/*
 * function: func_021AC810
 * address:  0x021AC810
 * packet:   pkt_ov021_021AC810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   d_021DE050     0x021DE050  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19872.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V3 { int x, y, z; } V3;
typedef struct Blk { u32 w[9]; } Blk;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct B {
    u32 f0;
    Blk blk;
    u16 f28[4];
    u16 f30;
} B;

struct BbActDesc;
struct BbActSys;
extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern void func_021AC1CC(u32 a, u8 *b);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u16 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern int func_021AC1A0(u32 a);
extern void func_021AC178(u32 a);
extern u32 d_021DE050[];

void func_021AC810(u32 a, B *b)
{
    u8 *p = (u8 *)func_021AC1AC(a);
    Desc s;
    u16 idx;
    u32 h;
    u16 r;

    b->blk = *(Blk *)p;
    func_0216E1A4(((struct Obj19872 *)p)->f4, (int)b->f28);
    func_021AC1CC(a, p + 0x14);
    idx = b->blk.w[8];
    s.slot = *(u16 *)(b->blk.w[0] + idx * 2 + 8);
    s.v12 = 0x2000;
    s.v14 = 0x2000;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.pos = *(V3 *)(p + 0x14);
    s.f1c = 0;
    s.f20 = (u32)b;
    h = *(u32 *)(b->blk.w[0] + 4);
    b->f30 = func_02050340((struct BbActSys *)h, 0, (const struct BbActDesc *)(&s), 1, 0);
    if (b->f30 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)h, b->f30, d_021DE050[idx], 1);
    r = b->f30;
    func_0205082C((void *)h, r, 0);
    func_020507F0((void *)h, r, 1);
    if (func_021AC1A0(a) == 0)
        b->f0 = 1;
    func_021AC178(a);
}
