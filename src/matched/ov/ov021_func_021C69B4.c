/*
 * function: func_021C69B4
 * address:  0x021C69B4
 * packet:   pkt_ov021_021C69B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unused 5th parameter puts pos/flag at sp+0x1c/0x20.  func_0204767C takes
 * the count as a third argument (the last f28 load is reused in r2).  The
 * h value starts (i = 0) before the e->f4/f6 stores, so it interferes with
 * idx in r2 and lands in r5, copied to r2 at the call.
 *
 * symbols:
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8[8]; u8 f28; u8 f29; } S;
typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V f8;
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 f20[0x24];
    u32 f44;
    u32 f48[8];
} Elem;
struct G3dOwner;
struct G3dRec;
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
struct G3dSys;
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0207ADC4(void *p);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
void func_021C69B4(Elem *e, S *s, u16 idx, u16 id, u32 unused, V *pos, int flag)
{
    int i;
    u32 m;

    i = 0;
    e->f4 = idx;
    e->f6 = id;
    if (s->f29 == 1) {
        i = s->f0;
        if (s->f4 != 0)
            i = s->f4;
    }
    m = (u32)func_02047400((void *)s->f0, id, (void *)i);
    if (s->f28 != 0) {
        MIi_CpuClear32(0, e->f48, sizeof(e->f48));
        for (i = 0; i < s->f28; i++)
            e->f48[i] = (u32)func_02047564((struct G3dOwner *)m, (const struct G3dOwner *)s->f8[i], 0);
    }
    e->f44 = (u32)func_0204767C(m, e->f48, s->f28);
    if (s->f28 != 0) {
        for (i = 0; i < s->f28; i++)
            func_020477A4((struct G3dSys *)e->f44, (u16)i);
    }
    if (pos != 0)
        e->f8 = *pos;
    if (flag != 0) {
        e->b2 = 1;
        e->f14 = 0x1000;
        e->f18 = 0x1000;
        e->f1C = 0x1000;
        func_0207ADC4(e->f20);
    }
    e->k = 1;
}
