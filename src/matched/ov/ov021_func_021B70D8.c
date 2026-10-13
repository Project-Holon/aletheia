/*
 * function: SCRCMD_POKEMON_FLD_LookupTableValue
 * address:  0x021B70D8
 * packet:   pkt_ov021_021B70D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   func_020307B0  0x020307B0  arm
 *   sScrcmdTableFileIds     0x021D99D0  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef struct Ent {
    u32 k;
    u32 v;
} Ent;

extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_020307B0(void *p);
extern u8 sScrcmdTableFileIds[];

int SCRCMD_POKEMON_FLD_LookupTableValue(u32 a, u32 b)
{
    u32 i;
    u32 v;
    u32 k;
    u32 idx;
    u16 *out;
    Ent *arr;
    u32 cnt;

    v = FIELDMAP_GetHeapId((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))[1]));
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    idx = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    arr = (Ent *)ARC_UTIL_LoadMemberWithSize(0xd0, sScrcmdTableFileIds[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    i = 0;
    *out = 0;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            *out = arr[i].v;
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}
