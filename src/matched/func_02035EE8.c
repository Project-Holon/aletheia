/*
 * function: func_02035EE8
 * address:  0x02035EE8
 * packet:   pkt_02035EE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_020A799C    0x020A799C  data
 *   func_02030734 0x02030734  arm
 *   func_02082BCC 0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8  pad[0x40];
    u32 f40;
    u32 f44;
} T;

extern u8 g_020A799C[];
extern void *func_02030734(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02082BCC(void *dst, u32 val, u32 size);

T *func_02035EE8(u32 a)
{
    T *p = (T *)func_02030734(a, 0x4c, 0, (u32)g_020A799C, 0x44);

    func_02082BCC(p, 0, 0x4c);
    p->f40 = 8;
    p->f44 = 0xf;
    return p;
}
