/*
 * function: func_021BA36C
 * address:  0x021BA36C
 * packet:   pkt_ov099_021BA36C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Parked at MATCH: every byte is right, the single wildcard is the
 * blx to the unlabelled arm9 leaf 0x0203F5FC (no witness outside the range;
 * an arm9 leaf is Ilias's).  Same blocker as ov099_func_021BA2D4.c.
 *
 * blocker: arm9 leaf func_0203F5FC 0x0203F5FC (arm, 64 bytes), verified EXACT
 * with `one --arm` (no --region), C:
 *
 *   typedef unsigned long u32;
 *   typedef signed short s16;
 *   extern const s16 d_020A1B38[];   (0x020A1B38 data a2)
 *   int func_0203F5FC(u32 a)
 *   {
 *       int t;
 *       if (a >= 360) {
 *           return 0;
 *       }
 *       t = (int)(a * 65535) / 360;
 *       return d_020A1B38[(t >> 4) * 2];
 *   }
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_0203F5FC  0x0203F5FC  arm
 *   func_021C5814  0x021C5814  thumb  ov127
 *   func_021C5898  0x021C5898  thumb  ov127
 *   func_021C5864  0x021C5864  thumb  ov127
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
    s16 f8;
} S;

extern int func_021C49A4(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern int func_0203F5FC(u32 x);
extern void func_021C5814(void *p, P2 v);
extern void func_021C5898(void *p, P2 v);
extern void func_021C5864(u8 *p, int b);

void func_021BA36C(void *w, S *s)
{
    P2 pos;
    P2 q;
    int t;

    pos.x = func_021C49A4(s->f0, 0);
    pos.y = func_021C49A4(s->f0, 1);
    q = pos;
    t = (s16)(s->f8 - 16);
    if (t > 0) {
        pos.y = pos.y - (s16)((s32)(((long long)func_0203F5FC((u16)(180 * (s16)(t % 6) / 6)) * 16384 + 0x800) >> 12) >> 12);
    }
    func_021C5814(s->f4, pos);
    func_021C5898(s->f4, q);
    func_021C5864(s->f4, 1);
}
