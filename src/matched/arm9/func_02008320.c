/*
 * function: CONFIG_Init
 * address:  0x02008320
 * packet:   pkt_02008320
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 */

typedef unsigned short u16;

/* one u16 of packed flags: the seven low fields are written one at a time. */
struct Flags02008320 {
    u16 a : 4;
    u16 b : 2;
    u16 c : 1;
    u16 d : 1;
    u16 e : 1;
    u16 f : 1;
    u16 g : 1;
    u16 h : 5;
};

extern void MI_CpuFill8(void *p, int c, u16 n);

void CONFIG_Init(struct Flags02008320 *p)
{
    MI_CpuFill8(p, 0, 4);
    p->a = 1;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 1;
    p->g = 0;
}
