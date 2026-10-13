/*
 * function: SCRCMD_CreateMmdlIcaProc
 * address:  0x021D1A04
 * packet:   pkt_ov021_021D1A04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   SCRCMD_MMDL_ICA_CreateProc  0x021D182C  thumb  ov021
 *   SCRIPT_WORK_SetReturnParam  0x02159104  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u8 *SCRCMD_MMDL_ICA_CreateProc(u32 a, u32 b, u32 *c, u32 d);
extern void SCRIPT_WORK_SetReturnParam(u8 *p, u32 v);

int SCRCMD_CreateMmdlIcaProc(u32 a, u32 b)
{
    u32 buf[3];
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    u32 *q = (u32 *)SCRIPT_WORK_ResetFieldParam((int)s);
    u32 t = FIELDMAP_GetHeapId((u8 *)q[1]);
    u32 k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u8 *r;

    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((struct Obj00020 *)q[1]), (struct VecFx32 *)buf);
    r = SCRCMD_MMDL_ICA_CreateProc(q[1], k, buf, t);
    SCRIPT_WORK_SetReturnParam(s, (u32)r);
    return 0;
}
