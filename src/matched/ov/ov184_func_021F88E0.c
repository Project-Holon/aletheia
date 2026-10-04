/*
 * function: func_021F88E0
 * address:  0x021F88E0
 * packet:   pkt_021F88E0
 * region:   ov184
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3BF0  0x021F3BF0  thumb  ov112
 *   func_021FC640  0x021FC640  thumb  ov186
 *   func_021FC148  0x021FC148  thumb  ov186
 *   func_021FB964  0x021FB964  thumb  ov186
 *   func_021FEEC0  0x021FEEC0  thumb  ov186
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_021F3BF0(u8 *p);
extern void func_021FC640(u32 a, u16 b);
extern void func_021FC148(char *p, unsigned i, unsigned heap);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FEEC0(char *p, int mode, u32 value);

void func_021F88E0(char *p, char *q)
{
    if (*(u32 *)p == 0)
        return;
    func_021F3BF0(*(void **)p);
    *(u32 *)p = 0;
    func_021FC640(*(u32 *)(q + 8), *(u16 *)(p + 0x24));
    func_021FC148((char *)(*(u32 *)(q + 0xc)), 0, *(u16 *)(p + 0x24));
    func_021FB964((void *)(*(u32 *)(q + 0xc)), 0, *(u16 *)(p + 0x24));
    func_021FEEC0((char *)(*(u32 *)(q + 4)), 0, 1);
}
