/*
 * function: TOWNMAP_ApplyScroll
 * address:  0x021BB0E4
 * packet:   pkt_ov072_021BB0E4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *   BG_SYS_SetAffine  0x02041FB0  arm
 *   BG_SYS_SetScrollY  0x02041F6C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[2];
    short f4;
    short f6;
    short f8;
    short fA;
    u8 padC[8];
    u32 f14;
    u8 pad18[8];
    int f20;
    int f24;
} W;

extern void BG_SYS_ResetSlot(u32, u32, u32);
extern void BG_SYS_SetAffine(u32, u32, u16);
extern void BG_SYS_SetScrollY(u32, u32, u32);

void TOWNMAP_ApplyScroll(W *p, const int *v)
{
    p->f20 = (v[0] > p->f8) ? p->f8 : ((v[0] < p->f6) ? p->f6 : v[0]);
    p->f24 = (v[1] > p->fA) ? p->fA : ((v[1] < p->f4) ? p->f4 : v[1]);

    BG_SYS_ResetSlot(p->f0, 0, p->f20);
    BG_SYS_ResetSlot(p->f0, 3, p->f24);
    BG_SYS_SetAffine(p->f0, 9, 0x80);
    BG_SYS_SetAffine(p->f0, 12, 0x60);
    BG_SYS_SetScrollY(p->f0, 3, p->f14);
    BG_SYS_SetScrollY(p->f0, 6, p->f14);
    BG_SYS_ResetSlot(p->f1, 0, p->f20);
    BG_SYS_ResetSlot(p->f1, 3, p->f24);
    BG_SYS_SetAffine(p->f1, 9, 0x80);
    BG_SYS_SetAffine(p->f1, 12, 0x60);
    BG_SYS_SetScrollY(p->f1, 3, p->f14);
    BG_SYS_SetScrollY(p->f1, 6, p->f14);
}
