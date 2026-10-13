/*
 * function: GFL_USE_ResetSound
 * address:  0x02005B74
 * packet:   pkt_02005B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02074A54
 * symbols:
 *   _SndState      0x020AA260  data
 *   GFL_USE_SetSndStackHeap  0x020057DC  thumb
 *   GFL_USE_InitSndStack  0x02005888  thumb
 *   GFL_USE_CancelChangeDefaultFade  0x02005F5C  thumb
 *   GFL_USE_InitSeSlots  0x02006118  thumb
 *   NNS_SndArcGetGroupInfo  0x02074518  arm
 *    */

extern char _SndState[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020754C4(u32 a);
extern void GFL_USE_SetSndStackHeap(u32 **a);
extern void *NNS_SndArcGetGroupInfo(int index);
extern void func_02074A54(int a, int b);
extern void GFL_USE_InitSeSlots(void);
extern void GFL_USE_InitSndStack(u16 a);
extern void GFL_USE_CancelChangeDefaultFade(void);
void GFL_USE_ResetSound(int a0)
{
    func_020754C4(*(int *)(_SndState + 0x10));
    GFL_USE_SetSndStackHeap((u32 **)(_SndState + 0x10));
    if (a0 != 0) {
        NNS_SndArcGetGroupInfo(0);
        func_02074A54(0, *(int *)(_SndState + 0x10));
        *(int *)(_SndState + 0x18) = 0;
    }
    GFL_USE_InitSeSlots();
    GFL_USE_InitSndStack(0);
    GFL_USE_CancelChangeDefaultFade();
    *(short *)(_SndState + 0) = 0;
    *(int *)(_SndState + 8) = 0;
    *(int *)(_SndState + 0x14) = 0;
    *(int *)(_SndState + 4) = 0;
}
