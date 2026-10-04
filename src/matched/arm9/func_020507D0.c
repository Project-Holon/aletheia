/*
 * function: func_020507D0
 * address:  0x020507D0
 * packet:   pkt_020507D0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */

typedef struct { int f0; char pad[0x24]; } E28_020507D0;
typedef struct { int pad0; int f4; char pad[0x10]; E28_020507D0 *f18; } Mgr_020507D0;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0204F704(u8 *a0, int i);

int func_020507D0(Mgr_020507D0 *p, int i)
{
    return func_0204F704((u8 *)p->f4, p->f18[i].f0);
}
