/*
 * function: C_GEAR_TintPalettes
 * address:  0x021F0DB4
 * packet:   pkt_ov029_021F0DB4
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker (evidence class: none image-wide): both calls to PALANM_GetDefaultWork
 * (0x02021728, arm9, Thumb) are inside this function; that address is an
 * unlabelled arm9 leaf (the integrator's) with no outside witness. Verified C for it
 * (EXACT, region arm9, --cc 1.1p1 --thumb, no relocations):
 *
 *   int PALANM_GetDefaultWork(char *p, int i)
 *   {
 *       return *(int *)(p + i * 0x14);
 *   }
 *
 * Its neighbour PALANM_GetTransWork (matched) is the same with +4.
 *
 * symbols:
 *   PALANM_GetDefaultWork  0x02021728  thumb
 *   PALANM_GetTransWork  0x02021730  thumb
 *   PALANM_BlendColors  0x02021F64  thumb
 *   func_02082D44  0x02082D44  arm
 *   d_021F31B6     0x021F31B6  data  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern u16 d_021F31B6[];
extern int PALANM_GetDefaultWork(char *p, int i);
extern int PALANM_GetTransWork(char *p, int i);
extern void PALANM_BlendColors(u16 *src, u16 *dst, int count, int weight, u16 color);
extern void func_02082D44(void *src, void *dst, int n);

void C_GEAR_TintPalettes(char *p, int mode)
{
    char *a, *b;
    int i;

    if (mode == 0) {
        a = (char *)PALANM_GetDefaultWork(*(char **)(p + 0x210), 3);
        b = (char *)PALANM_GetTransWork(*(char **)(p + 0x210), 3);
        for (i = 0; i < 14; i++) {
            if (0xFBEE & (1 << i)) {
                PALANM_BlendColors((u16 *)(a + i * 0x20), (u16 *)(a + i * 0x20), 0x10, 8,
                              d_021F31B6[*(u8 *)(p + 0x459)]);
                func_02082D44(a + i * 0x20, b + i * 0x20, 0x20);
            }
        }
        a = (char *)PALANM_GetDefaultWork(*(char **)(p + 0x210), 1);
        b = (char *)PALANM_GetTransWork(*(char **)(p + 0x210), 1);
        for (i = 0; i < 14; i++) {
            if (0x3E & (1 << i)) {
                PALANM_BlendColors((u16 *)(a + i * 0x20), (u16 *)(a + i * 0x20), 0x10, 8,
                              d_021F31B6[*(u8 *)(p + 0x459)]);
                func_02082D44(a + i * 0x20, b + i * 0x20, 0x20);
            }
        }
    }
}
