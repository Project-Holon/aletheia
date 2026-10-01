/*
 * function: func_021C69B4
 * address:  0x021C69B4
 * packet:   pkt_ov021_021C69B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: DIFF. Logic and layout verified (unused 5th parameter
 * puts pos/flag at sp+0x1c/0x20). Left: the h value passed to func_02047400
 * is held in r5 in the original (moved to r2 at the call) and s->f28 is
 * loaded into r2 in the first guard/loop; compiled computes h straight into r2,
 * which shifts everything after by 2 bytes.
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
extern u32 func_02047400(u32 a, u32 b, u32 c);
extern u32 func_02047564(u32 m, u32 a, u32 b);
extern u32 func_0204767C(u32 m, u32 *list);
extern void func_020477A4(u32 h, u16 i);
extern void func_0207ADC4(void *p);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
void func_021C69B4(Elem *e, S *s, u16 idx, u16 id, u32 unused, V *pos, int flag)
{
    int i;
    u32 m;

    e->f4 = idx;
    e->f6 = id;
    i = 0;
    if (s->f29 == 1) {
        i = s->f0;
        if (s->f4 != 0)
            i = s->f4;
    }
    m = func_02047400(s->f0, id, i);
    if (s->f28 != 0) {
        MIi_CpuClear32(0, e->f48, sizeof(e->f48));
        for (i = 0; i < s->f28; i++)
            e->f48[i] = func_02047564(m, s->f8[i], 0);
    }
    e->f44 = func_0204767C(m, e->f48);
    if (s->f28 != 0) {
        for (i = 0; i < s->f28; i++)
            func_020477A4(e->f44, i);
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
