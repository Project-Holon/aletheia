/*
 * function: FIELD_SOUND_SYSTEM_PopBgm
 * address:  0x020293D8
 * packet:   pkt_0202939C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct T {
    u32 pad00;
    u32 f04;
    u32 f08;
    u8  pad0c[0x14];
    int f20;
    u32 f24;
};

extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
struct S;
extern void func_02028BDC(struct S *s, u32 mask);

void FIELD_SOUND_SYSTEM_PopBgm(struct T *p)
{
    u32 n;

    if (p->f20 <= 0) {
        return;
    }
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    n = p->f20 - 1;
    p->f20 = n;
    p->f08 = *(u32 *)((char *)p + 0x24 + n * 4);
    if (n == 0) {
        func_02028BDC((struct S *)p, 1);
    }
}
