/*
 * function: BTL_POKEPARAM_ReloadAndResetEffects
 * address:  0x021D6580
 * packet:   pkt_ov093_021D6580
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   BTL_POKEPARAM_ResetMoveHistory  0x021D5364  thumb  ov093
 *   BTL_POKEPARAM_ClearSubstitute  0x021D6D70  thumb  ov093
 *   BTL_POKEPARAM_ClearSickConts  0x021D63B8  thumb  ov093
 *   BTL_POKEPARAM_InitStatStages  0x021D53C0  thumb  ov093
 *   BTL_POKEPARAM_ReloadFromMon  0x021D4EFC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct {
    void *w;
    u8 pad4[0x12];
    u16 f16;
    u8 pad18[3];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;
extern void MI_CpuFill8(void *dst, u8 v, u32 n);
struct S;
struct UtilWork;
extern void BTL_POKEPARAM_ResetMoveHistory(struct UtilWork *p);
extern void BTL_POKEPARAM_ClearSubstitute(unsigned char *p);
extern void BTL_POKEPARAM_ClearSickConts(u8 *p, int all);
extern void BTL_POKEPARAM_ReloadFromMon(struct S *a, void *mon, u32 c, u32 d);
extern void BTL_POKEPARAM_InitStatStages(unsigned char *p);

void BTL_POKEPARAM_ReloadAndResetEffects(Obj *p)
{
    BTL_POKEPARAM_ReloadFromMon((struct S *)p, p->w, 0, 1);
    MI_CpuFill8((u8 *)p + 0x155, 0, 2);
    MI_CpuFill8((u8 *)p + 0x153, 0, 2);
    BTL_POKEPARAM_ClearSubstitute((unsigned char *)p);
    BTL_POKEPARAM_ResetMoveHistory((struct UtilWork *)p);
    BTL_POKEPARAM_ClearSickConts((u8 *)p, 0);
    BTL_POKEPARAM_InitStatStages((unsigned char *)((char *)p + 0xfc));
}
