/*
 * function: func_021C6874
 * address:  0x021C6874
 * packet:   pkt_ov021_021C6874
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  label -- func_02022040 (arm9 Thumb, 0x02022040) is an unlabelled
 *           arm9 leaf inside func_02022004's listed extent (02022004..0202208C);
 *           this call is its only witness, so the site stays wildcarded. Every
 *           concrete byte matches. The leaf verifies EXACT on its own
 *           (match.py one --thumb, no --region) as:
 *
 *             void func_02022040(u16 *pal, int n, u8 *tbl)
 *             {
 *                 int i;
 *                 int c;
 *                 u8 v;
 *
 *                 for (i = 0; i < n; i++) {
 *                     c = *pal;
 *                     v = tbl[(((c & 0x1f) * 76) + (((c >> 5) & 0x1f) * 151)
 *                              + (((c >> 10) & 0x1f) * 29)) >> 8];
 *                     *pal++ = (v << 10) | (v << 5) | v;
 *                 }
 *             }
 *
 *           Needs a function_starts seed at 0x02022040 (arm9, Thumb) and the
 *           leaf filed by the arm9 owner; then this file should go EXACT.
 * symbols:
 *   func_02046E24   0x02046E24  arm
 *   func_02046F50   0x02046F50  arm
 *   func_02046F48   0x02046F48  arm
 *   func_0206E964   0x0206E964  arm
 *   func_02022040   0x02022040  thumb
 *   func_021C6854   0x021C6854  thumb  ov021
 *   MIi_CpuClear32  0x02082A7C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8[8];
    u8 f28;
    u8 f29;
} S;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
    u8 pad32[6];
    u32 f38;
} Pal;

extern u32 func_02046E24(u32 a, u32 b);
extern int func_02046F50(u32 a, int b);
extern u32 func_02046F48(u32 a);
extern Pal *func_0206E964(u32 h);
extern void func_02022040(void *pal, int n, int t);
extern void func_021C6854(S *s);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);

void func_021C6874(S *s, int unused, D *d, int mode, int flag)
{
    u32 h;
    Pal *p;
    int i;

    if (d->f0 != 0)
        s->f0 = func_02046E24(d->f0, d->fC);
    if (d->f4 != 0)
        s->f4 = func_02046E24(d->f4, d->fE);
    if (flag != 0) {
        h = 0;
        if (s->f0 != 0)
            h = s->f0;
        if (s->f4 != 0)
            h = s->f4;
        if (func_02046F50(h, 2)) {
            p = func_0206E964(func_02046F48(h));
            func_02022040((u8 *)p + p->f38, (u32)(p->f30 << 3) / sizeof(u16), flag);
        }
    }
    if (s->f0 != 0 || s->f4 != 0) {
        if (mode == 1)
            func_021C6854(s);
        else
            s->f29 = 2;
    }
    if (d->f20 != 0) {
        s->f28 = d->f20;
        MIi_CpuClear32(0, s->f8, sizeof(s->f8));
        for (i = 0; i < s->f28; i++)
            s->f8[i] = func_02046E24(d->f8, d->f10[i]);
    }
}
