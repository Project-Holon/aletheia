/*
 * function: SCRCMD_POKEMON_FLD_RegisterTableValueNumber
 * address:  0x021B721C
 * packet:   pkt_ov021_021B721C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same ARC_UTIL_LoadMemberWithSize lookup as SCRCMD_POKEMON_FLD_AddTableValueToPoints; the table is const so its
 * byte load is scheduled ahead of the `str r0,[sp]` that passes &cnt.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_0201EFA4  0x0201EFA4  thumb
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   func_020307B0  0x020307B0  arm
 *   sScrcmdTableFileIds     0x021D99D0  data   ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent { u32 k; u32 v; };

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct WordSet;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_020307B0(void *p);
extern const u8 sScrcmdTableFileIds[];

int SCRCMD_POKEMON_FLD_RegisterTableValueNumber(u32 a, u32 b)
{
    void *s;
    u32 v;
    u32 k;
    u32 idx;
    u32 p1;
    u32 p2;
    u32 t;
    struct Ent *arr;
    u32 cnt;
    u32 i;

    s = SCRCMD_WORK_GetScriptWork((void *)b);
    v = FIELDMAP_GetHeapId((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)s))[1]));
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    idx = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    p1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    p2 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    t = (u32)SCRIPT_WORK_GetWordSet(s);
    arr = (struct Ent *)ARC_UTIL_LoadMemberWithSize(0xd0, sScrcmdTableFileIds[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            func_0201EFA4((struct WordSet *)t, p1, arr[i].v, p2, 0, 1);
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}
