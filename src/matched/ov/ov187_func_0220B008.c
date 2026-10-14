/*
 * function: BR_MAIN_InitSceneManager
 * address:  0x0220B008
 * packet:   pkt_0220B008
 * region:   ov187
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   PROCSYS_Create  0x02031324  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 *f0;
    u8 pad[0xc];
    u16 f10;
    u8 pad2[2];
    u32 f14;
    u32 f18;
};

extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern void *PROCSYS_Create(int a0);

void BR_MAIN_InitSceneManager(struct S *p, u32 a, u32 b, u32 c)
{
    MI_CpuFill8(p, 0, 0x28);
    p->f0 = PROCSYS_Create(c);
    p->f14 = b;
    p->f18 = a;
    p->f10 = c;
}
