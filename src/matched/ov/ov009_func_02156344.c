/*
 * function: DWC_RAP_StartVchat
 * address:  0x02156344
 * packet:   pkt_ov009_02156344
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker: byte-correct; two code witnesses remain unresolved. Existing
 *   unit src/matched/ov/ov009_func_021562EC.c contains 0215631C and02156330,
 *   but its function: header lists only021562EC, so its shard cannot attest
 *   0215631C. Owner correction: one comma-separated function: value listing
 *   DWC_RAP_GetMyAidIfConnected, DWC_RAP_OnVchatStopped, DWC_RAP_EnableLocalVchat, then verify that unit shard.
 *   021AF18C (ov013) is an unlabelled setter; no leaf filed while the existing
 *   unit metadata blocker remains. No ARM9 blocker.
 *   The old note had the switch mapping wrong: 0,1,5,default -> 4; 2 -> 1;
 *   3 -> 2; 4 -> 3, and case 5 needs its own arm (the table's lone `b`).
 *
 * 2026-10-04 (wave D2 lane 04): unit header of ov009_func_021562EC.c corrected to list
 * DWC_RAP_GetMyAidIfConnected, DWC_RAP_OnVchatStopped, DWC_RAP_EnableLocalVchat (shard needs regen by the integrator).
 * The remaining blocker is 0x021AF18C in ov013 (pengy's overlay, not touched).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Only open reloc is THM_CALL VCT_MAIN_SetExitCallback (ov013, pengy's overlay,
 * unlabelled Thumb setter `ldr r1,=A; ldr r2,[r1]; ldr r1,=B; str r0,[r2,r1]; bx lr`, mis-listed as ARM by show). Not filed here.
 *
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: THM_CALL VCT_MAIN_SetExitCallback (ov013,
 *   pengy's overlay, no witness). Not a same-overlay leaf, so no witness filed.
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   DWC_RAP_OnVchatStopped  0x0215631C  thumb  ov009
 *   VCT_MAIN_Start  0x021AEF6C  thumb  ov013
 *   VCT_MAIN_SetExitCallback  0x021AF18C  thumb  ov013
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void DWC_RAP_OnVchatStopped(void);
extern void VCT_MAIN_Start(void *, int, int);
extern void VCT_MAIN_SetExitCallback(void (*cb)(void));

void DWC_RAP_StartVchat(void *a)
{
    u32 v;
    *(u16 *)(g_021A8264 + 0x794) = 1;
    *(u32 *)(g_021A8264 + 0x790) = 1;
    *(u16 *)(g_021A8264 + 0x796) = 1;
    if (*(u32 *)(g_021A8264 + 0x76c) == 0) {
        v = 1;
        switch (*(u32 *)(g_021A8264 + 0x77c)) {
        case 2:
            v = 1;
            break;
        case 3:
            v = 2;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 4;
            break;
        default:
            v = 4;
            break;
        }
        VCT_MAIN_Start(a, v, 1);
        VCT_MAIN_SetExitCallback(DWC_RAP_OnVchatStopped);
        *(u32 *)(g_021A8264 + 0x76c) = 1;
    }
}
