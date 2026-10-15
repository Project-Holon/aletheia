/*
 * function: BR_CODEIN_ProfileHandleInput
 * address: 0x021E19EC
 * packet: pkt_ov183_021E19EC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 wave P5 lane T5 (pengy share): earlier DIFF, two residues (merged far-branch stubs, idx-12 CSE).
 * 2026-10-05 wave P5 lane T5b: EXACT with the ov129 021D958C forms: idx is u32 (unsigned % and / by plain 5),
 *   `if (*(int *)(p + 0x22C) != 1) return;` then `if (arg == 0) {`, non-const Record pointer. One compile.
 *   Callbacks: BR_CODEIN_ProfileCreateButtons passes this as BUTTON_MAN_Create's callback (idx, arg, obj).
 * symbols:
 *   BR_CODEIN_ProfileGetActorIndex 0x021E0E40 thumb ov183
 *   BR_CODEIN_ProfileBuildAnimName 0x021E1708 thumb ov183
 *   BR_CODEIN_ProfileApplyRecords 0x021E1850 thumb ov183
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int tag,value,mode,handle; char rest[12];} Record;
struct Obj;
extern int BR_CODEIN_ProfileGetActorIndex(int,int);
extern void BR_CODEIN_ProfileBuildAnimName(char *);
extern void BR_CODEIN_ProfileApplyRecords(char *);
extern void CLACT_SetActorAnimSeq(struct Obj *, u16);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void BR_UTIL_StartEffect(int,int,int *);
void BR_CODEIN_ProfileHandleInput(u32 idx, int arg, char *p)
{
    Record *rec = (Record *)p;
    u32 i, j, v;
    int old, val;
    if (*(int *)(p + 0x22C) != 1) return;
    if (arg == 0) {
    if (idx <= 11) {
        if (rec[idx].mode == 1) {
            *(int *)(p + 0x318) = 2;
            *(int *)(p + 0x31C) = idx;
        } else {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = rec[idx].value;
        }
        GFL_USE_PlaySeDefaultVolume(0x703);
        return;
    }
    if (idx == 0x16) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 0;
        *(u16 *)(p + 0x1BA) = 2;
        GFL_USE_PlaySeDefaultVolume(0x703);
        TOUCHPANEL_GetPointTrg(&x, &y);
        args[0] = x;
        args[1] = y;
        BR_UTIL_StartEffect(*(int *)(p + 0x348), 1, args);
    } else if (idx == 0x17) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 3;
        *(u16 *)(p + 0x1BA) = 2;
        GFL_USE_PlaySeDefaultVolume(0x703);
        TOUCHPANEL_GetPointTrg(&x, &y);
        args[0] = x;
        args[1] = y;
        BR_UTIL_StartEffect(*(int *)(p + 0x348), 1, args);
    } else {
        *(u16 *)(p + 0x1B8) = (idx - 12) % 5;
        *(u16 *)(p + 0x1BA) = (idx - 12) / 5;
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    if (idx >= 12 && idx <= 21) {
        u32 x, y;
        int args[2];
        if (*(int *)(p + 0x240) != 0) {
        TOUCHPANEL_GetPointTrg(&x, &y);
        args[0] = x;
        args[1] = y;
        BR_UTIL_StartEffect(*(int *)(p + 0x348), 1, args);
        i = *(int *)(p + 0x188);
        v = idx - 11;
        CLACT_SetActorAnimSeq((struct Obj *)rec[i].handle, (u16)BR_CODEIN_ProfileGetActorIndex(rec[i].tag = v, rec[i].mode));
        old = rec[i].value;
        j = i + 1;
        if (j == *(u32 *)(p + 0x23C)) {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = 0;
            *(int *)(p + 0x320) = 0;
        } else {
            val = rec[j].value;
            if (old != val) {
                *(int *)(p + 0x318) = 1;
                *(int *)(p + 0x31C) = val;
                *(int *)(p + 0x320) = 0;
            } else {
                *(int *)(p + 0x318) = 2;
                *(int *)(p + 0x31C) = j;
            }
        }
        }
    } else if (idx == 0x16) {
        BR_CODEIN_ProfileApplyRecords(p);
    } else {
        BR_CODEIN_ProfileBuildAnimName(p);
    }
    }
}
