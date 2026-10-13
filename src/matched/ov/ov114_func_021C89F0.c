/*
 * function: DPW_TR_CancelAsync
 * address:  0x021C89F0
 * packet:   pkt_ov114_021C89F0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A dispatch tracker: the global 0x021D3D2C holds an even step id; each even
 * case runs the shared handler DWCi_EncSessionCancel and advances the id by one.
 * DWCi_EncSessionCancel is resolved by the sdk class; the global by sole-ref.
 *
 * symbols:
 *   DWCi_EncSessionCancel  0x021CA188  arm  ov114
 *   g_021D3D2C     0x021D3D2C  data ov114 a4
 */

typedef unsigned int u32;

extern void DWCi_EncSessionCancel(void);
extern u32  g_021D3D2C;

void DPW_TR_CancelAsync(void)
{
    switch (g_021D3D2C) {
    case 2:  DWCi_EncSessionCancel(); g_021D3D2C = 3;  break;
    case 4:  DWCi_EncSessionCancel(); g_021D3D2C = 5;  break;
    case 6:  DWCi_EncSessionCancel(); g_021D3D2C = 7;  break;
    case 8:  DWCi_EncSessionCancel(); g_021D3D2C = 9;  break;
    case 10: DWCi_EncSessionCancel(); g_021D3D2C = 11; break;
    case 12: DWCi_EncSessionCancel(); g_021D3D2C = 13; break;
    case 14: DWCi_EncSessionCancel(); g_021D3D2C = 15; break;
    case 16: DWCi_EncSessionCancel(); g_021D3D2C = 17; break;
    case 18: DWCi_EncSessionCancel(); g_021D3D2C = 19; break;
    case 20: DWCi_EncSessionCancel(); g_021D3D2C = 21; break;
    case 22: DWCi_EncSessionCancel(); g_021D3D2C = 23; break;
    }
}
