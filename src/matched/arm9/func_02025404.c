/*
 * function: func_02025404
 * address:  0x02025404
 * packet:   pkt_020251FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204AC18  0x0204AC18  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


typedef signed int     s32;
struct ActorTool;
extern int func_02025360(struct ActorTool *p, int len, u32 bank);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

s32 func_02025404(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 v = func_02025360((struct ActorTool *)a0, a4, a3);

    return func_0204AC18((void *)a1, a2, a3, (v & 0x7ff) << 5, 0, (u16)a4, (u16)a5);
}
