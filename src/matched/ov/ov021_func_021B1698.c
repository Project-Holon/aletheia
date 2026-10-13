/*
 * function: SCRCMD_FLDMMDL_StartMmdlAnime
 * address:  0x021B1698
 * packet:   pkt_ov021_021B1698
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   VM_GetU32  0x0201134C  thumb
 *   SCRCMD_FLDMMDL_GetMmdlByScriptId  0x021B1668  thumb  ov021
 *   FLDMMDL_ACMD_ListCreate  0x02197D3C  thumb  ov021
 *   SCRCMD_WORK_AddAnimeTask  0x0215A6DC  thumb  ov010
 */

void *SCRCMD_WORK_GetScriptWork(void *p);
unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
struct Cursor;
unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
u32 SCRCMD_FLDMMDL_GetMmdlByScriptId(u32 a, u32 b);
int FLDMMDL_ACMD_ListCreate(int a, int b);
void SCRCMD_WORK_AddAnimeTask(int *p, int v);

int SCRCMD_FLDMMDL_StartMmdlAnime(int *a, int *b)
{
    int r7;
    int r6;
    int r0;

    SCRCMD_WORK_GetScriptWork((void *)b);
    r7 = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    r6 = VM_GetU32((struct Cursor *)a);
    r0 = SCRCMD_FLDMMDL_GetMmdlByScriptId((u32)b, r7);
    if (r0 == 0) {
        return 0;
    }
    SCRCMD_WORK_AddAnimeTask(b, FLDMMDL_ACMD_ListCreate(r0, a[5] + r6));
    return 0;
}
