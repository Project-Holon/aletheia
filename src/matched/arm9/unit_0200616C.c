/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x0200616C
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_PlaySeInSlot, GFL_USE_PlaySe, GFL_USE_PlaySeDefaultVolume, GFL_USE_PlaySeWithVolume,
 *           GFL_USE_StopSeSlot, GFL_USE_StopAllSe
 *
 * symbols:
 *   sub_0200616C_Table  0x020AA294  data
 *   GFL_USE_IsSeqStartAllowed        0x02005CE0  thumb
 *   GFL_USE_GetSeSlot        0x02006148  thumb
 *   GFL_USE_SetSeSlotVolume        0x020062BC  thumb
 *   func_020755A8       0x020755A8  arm
 *   func_02072E7C       0x02072E7C  arm
 *   func_02075560       0x02075560  arm
 *
 * Registering and tearing down the five entries of the table at 0x020AA294,
 * and three forwarders over GFL_USE_PlaySe.  GFL_USE_PlaySeDefaultVolume and GFL_USE_PlaySeWithVolume
 * both tail call it through the same pool word, the first supplying a -1 for
 * the second argument and the second passing both of its own straight
 * through, which is four bytes of code and one relocation each.
 */

typedef unsigned int u32;

struct Sub0200616CEntry {
    void *unk00;
    u32   unk04;
};

extern struct Sub0200616CEntry sub_0200616C_Table[];

extern int  GFL_USE_IsSeqStartAllowed(void *arg);
extern int  GFL_USE_GetSeSlot(u32 a);
extern void GFL_USE_SetSeSlotVolume(int i, u32 b);
extern u32 func_020755A8(u32 a, int b, int c, int d, u32 e);
extern void func_02072E7C(void **r0, int fadeFrame);
extern u32 func_02075560(u32 a, u32 b);

void GFL_USE_PlaySe(u32 a, u32 b);
void GFL_USE_StopSeSlot(int i);

void GFL_USE_PlaySeInSlot(void *arg, int i)
{
    if (GFL_USE_IsSeqStartAllowed(arg) == 0) {
        return;
    }
    sub_0200616C_Table[i].unk00 = 0;
    if (func_020755A8((u32)(&sub_0200616C_Table[i].unk04), i + 1, -1, -1, (u32)arg) == 1) {
        sub_0200616C_Table[i].unk00 = arg;
    }
}

void GFL_USE_PlaySe(u32 a, u32 b)
{
    int i;

    if (GFL_USE_IsSeqStartAllowed((void *)a) == 0) {
        return;
    }
    i = GFL_USE_GetSeSlot(a);
    sub_0200616C_Table[i].unk00 = 0;
    if (func_02075560((u32)(&sub_0200616C_Table[i].unk04), a) != 1) {
        return;
    }
    sub_0200616C_Table[i].unk00 = (void *)a;
    if (b < 0x80) {
        GFL_USE_SetSeSlotVolume(i, b);
    }
}

void GFL_USE_PlaySeDefaultVolume(u32 a)
{
    GFL_USE_PlaySe(a, -1);
}

void GFL_USE_PlaySeWithVolume(u32 a, u32 b)
{
    GFL_USE_PlaySe(a, b);
}

void GFL_USE_StopSeSlot(int i)
{
    func_02072E7C((void **)(&sub_0200616C_Table[i].unk04), 0);
}

void GFL_USE_StopAllSe(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        GFL_USE_StopSeSlot(i);
    }
}
