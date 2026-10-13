/*
 * function: func_021BA2D4
 * address:  0x021BA2D4
 * packet:   pkt_ov099_021BA2D4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Parked at MATCH: every byte is right, the single wildcard is the
 * blx to the unlabelled arm9 leaf 0x0203F5FC (no witness outside the range;
 * an arm9 leaf is the integrator's).  All ov127 leaves it needs are filed and EXACT.
 *
 * blocker: arm9 leaf func_0203F5FC 0x0203F5FC (arm, 64 bytes), verified EXACT
 * with `one --arm` (no --region), C:
 *
 *   typedef unsigned long u32;
 *   typedef signed short s16;
 *   extern const s16 FX_SinCosTable_[];   (0x020A1B38 data a2)
 *   int func_0203F5FC(u32 a)
 *   {
 *       int t;
 *       if (a >= 360) {
 *           return 0;
 *       }
 *       t = (int)(a * 65535) / 360;
 *       return FX_SinCosTable_[(t >> 4) * 2];
 *   }
 *
 * Lever here: the FX multiply constant -786432 (0xFFF40000) is a
 * (long long) multiply, its high word is materialised as `asrs r3,r2,#20`.
 *
 * symbols:
 *   func_021C57E8  0x021C57E8  thumb  ov127
 *   func_021C5834  0x021C5834  thumb  ov127
 *   func_021C5840  0x021C5840  thumb  ov127
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_0203F5FC  0x0203F5FC  arm
 *   _ll_mul        0x0209C054  arm
 *   func_021C5814  0x021C5814  thumb  ov127
 *   func_021C5898  0x021C5898  thumb  ov127
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    s16 x;
    s16 y;
} P2;

typedef struct {
    void *f0;
    void *f4;
    u16 f8;
} S;

extern void func_021C57E8(char *p);
extern int func_021C5834(char *p);
extern void func_021C5840(char *p, int a);
extern int func_021C49A4(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern int func_0203F5FC(u32 x);
extern void func_021C5814(void *p, P2 v);
extern void func_021C5898(void *p, P2 v);

void func_021BA2D4(void *w, S *s)
{
    P2 pos;
    P2 q;

    func_021C57E8(s->f4);
    if (func_021C5834(s->f4) == 0) {
        func_021C5840(s->f4, 1);
    }
    pos.x = func_021C49A4(s->f0, 0);
    pos.y = func_021C49A4(s->f0, 1);
    q = pos;
    pos.y = pos.y + (s16)((s32)(((long long)func_0203F5FC(s->f8) * -786432 + 0x800) >> 12) >> 12);
    func_021C5814(s->f4, pos);
    func_021C5898(s->f4, q);
}
