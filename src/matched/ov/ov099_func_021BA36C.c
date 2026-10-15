/*
 * function: WIFICLUBACTOR_AnimateBounce
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
 * an arm9 leaf is the integrator's).  Same blocker as ov099_func_021BA2D4.c.
 *
 * blocker: arm9 leaf GF_STANDARD_Get_F5FC 0x0203F5FC (arm, 64 bytes), verified EXACT
 * with `one --arm` (no --region), C:
 *
 *   typedef unsigned long u32;
 *   typedef signed short s16;
 *   extern const s16 FX_SinCosTable_[];   (0x020A1B38 data a2)
 *   int GF_STANDARD_Get_F5FC(u32 a)
 *   {
 *       int t;
 *       if (a >= 360) {
 *           return 0;
 *       }
 *       t = (int)(a * 65535) / 360;
 *       return FX_SinCosTable_[(t >> 4) * 2];
 *   }
 *
 * symbols:
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   GF_STANDARD_Get_F5FC  0x0203F5FC  arm
 *   WF2DMAP_OBJDRAW_SetActorPos  0x021C5814  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActorPos2  0x021C5898  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetFrameZero  0x021C5864  thumb  ov127
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

extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern int GF_STANDARD_Get_F5FC(u32 x);
extern void WF2DMAP_OBJDRAW_SetActorPos(void *p, P2 v);
extern void WF2DMAP_OBJDRAW_SetActorPos2(void *p, P2 v);
extern void WF2DMAP_OBJDRAW_SetFrameZero(u8 *p, int b);

void WIFICLUBACTOR_AnimateBounce(void *w, S *s)
{
    P2 pos;
    P2 q;
    int t;

    pos.x = WF2DMAP_OBJ_GetSlot(s->f0, 0);
    pos.y = WF2DMAP_OBJ_GetSlot(s->f0, 1);
    q = pos;
    t = (s16)(s->f8 - 16);
    if (t > 0) {
        pos.y = pos.y - (s16)((s32)(((long long)GF_STANDARD_Get_F5FC((u16)(180 * (s16)(t % 6) / 6)) * 16384 + 0x800) >> 12) >> 12);
    }
    WF2DMAP_OBJDRAW_SetActorPos(s->f4, pos);
    WF2DMAP_OBJDRAW_SetActorPos2(s->f4, q);
    WF2DMAP_OBJDRAW_SetFrameZero(s->f4, 1);
}
