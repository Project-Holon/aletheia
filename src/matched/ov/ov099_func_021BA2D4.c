/*
 * function: WIFICLUBACTOR_AnimateWalkBob
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
 * blocker: arm9 leaf GF_STANDARD_SinFromDegrees 0x0203F5FC (arm, 64 bytes), verified EXACT
 * with `one --arm` (no --region), C:
 *
 *   typedef unsigned long u32;
 *   typedef signed short s16;
 *   extern const s16 FX_SinCosTable_[];   (0x020A1B38 data a2)
 *   int GF_STANDARD_SinFromDegrees(u32 a)
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
 *   WF2DMAP_OBJDRAW_StepActorAnim  0x021C57E8  thumb  ov127
 *   WF2DMAP_OBJDRAW_GetActorDrawEnable  0x021C5834  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActorDrawEnable  0x021C5840  thumb  ov127
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   GF_STANDARD_SinFromDegrees  0x0203F5FC  arm
 *   _ll_mul        0x0209C054  arm
 *   WF2DMAP_OBJDRAW_SetActorPos  0x021C5814  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetSubActorPos  0x021C5898  thumb  ov127
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

extern void WF2DMAP_OBJDRAW_StepActorAnim(char *p);
extern int WF2DMAP_OBJDRAW_GetActorDrawEnable(char *p);
extern void WF2DMAP_OBJDRAW_SetActorDrawEnable(char *p, int a);
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern int GF_STANDARD_SinFromDegrees(u32 x);
extern void WF2DMAP_OBJDRAW_SetActorPos(void *p, P2 v);
extern void WF2DMAP_OBJDRAW_SetSubActorPos(void *p, P2 v);

void WIFICLUBACTOR_AnimateWalkBob(void *w, S *s)
{
    P2 pos;
    P2 q;

    WF2DMAP_OBJDRAW_StepActorAnim(s->f4);
    if (WF2DMAP_OBJDRAW_GetActorDrawEnable(s->f4) == 0) {
        WF2DMAP_OBJDRAW_SetActorDrawEnable(s->f4, 1);
    }
    pos.x = WF2DMAP_OBJ_GetSlot(s->f0, 0);
    pos.y = WF2DMAP_OBJ_GetSlot(s->f0, 1);
    q = pos;
    pos.y = pos.y + (s16)((s32)(((long long)GF_STANDARD_SinFromDegrees(s->f8) * -786432 + 0x800) >> 12) >> 12);
    WF2DMAP_OBJDRAW_SetActorPos(s->f4, pos);
    WF2DMAP_OBJDRAW_SetSubActorPos(s->f4, q);
}
