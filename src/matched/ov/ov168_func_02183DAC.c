/*
 * function: func_02183DAC
 * address:  0x02183DAC
 * packet:   pkt_02183DAC
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D3C   0x02183D3C  thumb
 *   func_02183D34   0x02183D34  thumb
 *   func_02183E18   0x02183E18  thumb
 *   func_02184470   0x02184470  thumb
 *   func_0218448C   0x0218448C  thumb
 *   func_0218484C   0x0218484C  thumb
 *   SND_MIC_IsLimitReached   0x02006D94  thumb
 *   GFL_USE_PlaySeDefaultVolume   0x020061E4  thumb
 *
 * Four-state step: x+0xF8 through 0x2184470 on 0, gate two polls on 1,
 *   x+0xF8 through 0x218448C on 2, install 0x2183E18 on 3.
 */


extern unsigned int func_02183D3C(unsigned int *p);
extern void func_02183D34(unsigned int *p, unsigned int v);
typedef unsigned int   u32;
extern void func_02183E18(int a, int *state);
extern void func_02184470(int *p);
extern void func_0218448C(int *p);
extern int func_0218484C(void);
extern u32 SND_MIC_IsLimitReached(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void func_02183DAC(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        func_02184470((int *)(x + 0xF8));
        *state = 1;
        break;
    case 1:
        if (func_0218484C() && SND_MIC_IsLimitReached()) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            *state = 2;
        }
        break;
    case 2:
        func_0218448C((int *)(x + 0xF8));
        *state = 3;
        break;
    case 3:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183E18);
        break;
    }
}
