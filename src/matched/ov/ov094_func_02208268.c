/*
 * function: BTLV_GAUGE_DrawGender
 * address:  0x02208268
 * packet:   pkt_ov094_02208268
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_GetActorImageProxy  0x0204B7C8  arm  arm9
 *   MIi_CpuCopy16  0x02082A60  arm  arm9
 */

typedef unsigned char u8;
typedef struct { int w[9]; } Struct36;
typedef struct { void *f0; char p4[0x44 - 4]; int f44; char p48[0x6d - 0x48]; u8 f6d; } E;
typedef struct { char p0[0x14]; char *f14; } O;
struct Struct36;
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void MIi_CpuCopy16(const void *, void *, int);

void BTLV_GAUGE_DrawGender(O *o, E *e)
{
    Struct36 buf;
    int off1;
    int off2;
    enum { VRAM_BASE = 0x06400000 } vram;

    off1 = e->f6d * 64 + 0x380;
    off2 = e->f6d * 64 + 0x3a0;
    if (e->f6d == 2) {
        off1 = 0x660;
        off2 = 0x660;
    }
    CLACT_GetActorImageProxy(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        vram = VRAM_BASE;
        MIi_CpuCopy16(o->f14 + off1, (void *)(vram + 0x440 + buf.w[1]), 0x20);
        MIi_CpuCopy16(o->f14 + off2, (void *)(vram + 0x540 + buf.w[1]), 0x20);
    } else {
        vram = VRAM_BASE;
        MIi_CpuCopy16(o->f14 + off1, (void *)(vram + 0x420 + buf.w[1]), 0x20);
        MIi_CpuCopy16(o->f14 + off2, (void *)(vram + 0x520 + buf.w[1]), 0x20);
    }
}
