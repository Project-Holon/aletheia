/*
 * function: BTL_SICK_ProcTurnEnd
 * address:  0x0689B7FC
 * packet:   pkt_ov095_0689B7FC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Only the six real cases are written (8, 0x12, 0x14, 0x15, 0x17, 0x23), in
 * that source order; adding empty `case 0x13:`/`case 0x16:` arms pulls 8 into
 * one big table and swaps the a/t registers.
 *
 * symbols:
 *   func_0689B89C  0x0689B89C  thumb  ov095
 *   func_0689B8AC  0x0689B8AC  thumb  ov095
 *   func_0689B8BC  0x0689B8BC  thumb  ov095
 *   BTL_SICK_TickPerishSong  0x0689B974  thumb  ov095
 *   BTL_SICK_ApplyLeechSeed  0x0689B9F4  thumb  ov095
 *   BTL_SICK_RecoverHpIngrain  0x0689BB7C  thumb  ov095
 *   BTL_SICK_ApplyBindDamage  0x0689BC30  thumb  ov095
 *   BTL_SICK_RecoverHpAquaRing  0x0689BDE0  thumb  ov095
 *   BTL_SICK_EndEncoreWhenPpEmpty  0x0689BEAC  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0689B89C(u32 a);
extern int func_0689B8AC(u32 a, u32 b);
extern void func_0689B8BC(u32 a, u32 b, u32 c, int d);
extern void BTL_SICK_TickPerishSong(void *a, void *b, int c);
extern void BTL_SICK_ApplyLeechSeed(void *a, void *b, int c);
extern void BTL_SICK_RecoverHpIngrain(void *a, void *b, int c);
extern void BTL_SICK_ApplyBindDamage(u32 a, u32 b, u32 c);
extern void BTL_SICK_RecoverHpAquaRing(void *a, void *b, int c);
extern void BTL_SICK_EndEncoreWhenPpEmpty(void *a, void *b, int c);

void BTL_SICK_ProcTurnEnd(void *a, void *b, u32 c, int t)
{
    int r;

    if (func_0689B89C((u32)b) != 0)
        return;
    r = func_0689B8AC((u32)b, t);
    if (r != 0)
        func_0689B8BC((u32)a, (u32)b, t, r);
    switch (t) {
    case 0x14:
        BTL_SICK_TickPerishSong(a, b, c);
        break;
    case 0x12:
        BTL_SICK_ApplyLeechSeed((void *)a, (void *)b, c);
        break;
    case 0x15:
        BTL_SICK_RecoverHpIngrain((void *)a, (void *)b, c);
        break;
    case 8:
        BTL_SICK_ApplyBindDamage((u32)a, (u32)b, c);
        break;
    case 0x23:
        BTL_SICK_RecoverHpAquaRing((void *)a, (void *)b, c);
        break;
    case 0x17:
        BTL_SICK_EndEncoreWhenPpEmpty((void *)a, (void *)b, c);
        break;
    }
}
