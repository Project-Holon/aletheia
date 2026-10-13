/*
 * function: VCT_MAIN_HangUp
 * address:  0x021AF13C
 * packet:   pkt_ov013_021AF13C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gVctWork     0x021B3C80  data  ov013
 *   DWC_RAP_CleanupVchat  0x02156400  thumb  ov009
 *   VCT_SESSION_SendGroupCommand  0x021B20B0  arm  ov013
 */

typedef unsigned char u8;

typedef struct Work {
    u8 pad0[0x19AC];
    int f19AC;
    u8 pad19B0[0x1A1C - 0x19B0];
    int f1A1C;
} Work;

extern Work *gVctWork;
extern void DWC_RAP_CleanupVchat(void);
extern int VCT_SESSION_SendGroupCommand(int a, int b);

void VCT_MAIN_HangUp(void)
{
    if (gVctWork->f1A1C == 0 || gVctWork->f19AC == 0) {
        DWC_RAP_CleanupVchat();
        return;
    }
    if (gVctWork->f19AC == 1) {
        if (VCT_SESSION_SendGroupCommand(gVctWork->f1A1C, 2)) {
            DWC_RAP_CleanupVchat();
            return;
        }
    }
    if (VCT_SESSION_SendGroupCommand(gVctWork->f1A1C, 1)) {
        DWC_RAP_CleanupVchat();
    }
}
