/*
 * function: func_021C51D4
 * address: 0x021C51D4
 * packet: pkt_ov208_021C51D4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   NNS_G2dRestartMCAnimation 0x02064CBC arm
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Anm { u8 pad0[8]; u8 f8; u8 pad9[3]; u32 fc; };
struct Ov208Slot { void *obj; struct Ov208Anm *anm; };
extern void *MCSS_GetAnimCtrl(void *p);
struct Obj;
extern void NNS_G2dRestartMCAnimation(struct Obj *x);
extern void MCSS_ResetAnmStopFlag(void *p);
void func_021C51D4(struct Ov208Slot *s)
{
    if (s->obj != 0 && s->anm != 0) {
        void *r = MCSS_GetAnimCtrl(s->obj);
        s->anm->f8 = 0;
        s->anm->fc = 0;
        NNS_G2dRestartMCAnimation(r);
        MCSS_ResetAnmStopFlag(s->obj);
    }
}
