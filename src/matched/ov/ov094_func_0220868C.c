/*
 * function: func_0220868C
 * address:  0x0220868C
 * packet:   pkt_ov094_0220868C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorImageProxy  0x0204B7C8  arm  arm9
 */

typedef unsigned char u8;
typedef struct { int w[9]; } Struct36;
typedef struct { char p0[0xc]; void *fc; char p10[0x78 - 0x10]; int f78; } E;
typedef struct { char p0[0x14]; char *f14; } O;
struct Struct36;
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void func_02082A60(const void *, void *, int);

void func_0220868C(O *o, E *e, int c)
{
    u8 cnt[6];
    Struct36 buf;
    int n;
    int i;
    enum { VRAM_BASE = 0x06400000 } vram;

    n = e->f78 - c;
    for (i = 0; i < 6; i++)
        cnt[i] = 8;
    for (i = 5; i >= 0; i--) {
        if (n >= 8) {
            cnt[i] = 0;
            n -= 8;
        } else {
            cnt[i] = 8 - n;
            break;
        }
    }
    CLACT_GetActorImageProxy(e->fc, (struct Struct36 *)(&buf));

    i = 0;
    vram = VRAM_BASE;
    for (; i < 6; i++)
        func_02082A60(o->f14 + (cnt[i] * 32 + 0x6a0), (void *)(vram + i * 32 + buf.w[1]), 0x20);
}
