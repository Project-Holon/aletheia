/*
 * function: WF2DMAP_SCENE_HandleButton
 * address: 0x021D958C
 * packet: pkt_ov129_021D958C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave P5 lane T3, pengy share, user-approved for this function only): first draft, no twin found.
 * Args (n, touch, p): touch screen button handler, Record layout of ov129 021D8FA0 (state, value, flag, handle).
 * 2026-10-05 (wave P5 lane T3b): EXACT. The residue was the const on the Record pointer: with a non-const
 * `Record *r = (Record *)p;` the plain store `r[idx].state = n - 11;` gets `adds r1,r4,r7` before the store (the
 * store can alias the later field loads, so the address is built first). The pos_of() accessor and roff() were not
 * needed: plain `m = n - 12;` is also EXACT. Also EXACT: the sibling ov183 021E19EC form
 * `WF2DMAP_SCENE_GetCellAnim(r[idx].state = n - 11, r[idx].flag)`. Earlier tries: unsigned n (blo/bhi); early `if (x != 1) return;`;
 * `if (touch == 0)` shape.
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WF2DMAP_SCENE_SetCursorPos 0x021D9E98 thumb ov129
 *   WF2DMAP_SCENE_ClearSelection 0x021D93D4 thumb ov129
 *   WF2DMAP_SCENE_CheckGridNumber 0x021D9320 thumb ov129
 *   WF2DMAP_SCENE_BuildNumberList 0x021D9348 thumb ov129
 *   WF2DMAP_SCENE_ResetState 0x021D8AF4 thumb ov129
 *   WF2DMAP_SCENE_SetCursorVisible 0x021D9E48 thumb ov129
 *   WF2DMAP_SCENE_SetCursorPosBySlot 0x021D9EE8 thumb ov129
 *   WF2DMAP_SCENE_SetButtonCursor 0x021D9564 thumb ov129
 *   WF2DMAP_SCENE_GetCellAnim 0x021DA158 thumb ov129
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
struct Obj;
typedef struct { int state, value, flag; struct Obj *handle; char tail[12]; } Record;
typedef unsigned char  u8;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void WF2DMAP_SCENE_SetCursorPos(char *p, int i);
extern void WF2DMAP_SCENE_ClearSelection(char *p);
extern int WF2DMAP_SCENE_CheckGridNumber(u8 *p);
extern void WF2DMAP_SCENE_BuildNumberList(char *p);
extern void WF2DMAP_SCENE_ResetState(char *p, int v);
extern void WF2DMAP_SCENE_SetCursorVisible(char *p, int i, int a);
extern void WF2DMAP_SCENE_SetCursorPosBySlot(char *p, int i, int j);
extern void WF2DMAP_SCENE_SetButtonCursor(u8 *p, int n);
extern int WF2DMAP_SCENE_GetCellAnim(int x, int flag);

void WF2DMAP_SCENE_HandleButton(u32 n, int touch, char *p)
{
    Record *r = (Record *)p;
    int idx, v, k;
    int m;
    if (*(int *)(p + 0x22C) != 1) return;
    if (*(int *)(p + 0x2FC) != 1) *(int *)(p + 0x2FC) = 1;
    if (touch == 0) {
        {
            if (n <= 11) {
                if (r[n].flag == 1) {
                    *(int *)(p + 0x31C) = 2;
                    *(int *)(p + 0x320) = n;
                } else {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = r[n].value;
                }
                GFL_USE_PlaySeDefaultVolume(1352);
            } else if (n == 22) {
                *(s16 *)(p + 0x1B8) = 0;
                *(s16 *)(p + 0x1BA) = 2;
                GFL_USE_PlaySeDefaultVolume(1363);
                WF2DMAP_SCENE_ClearSelection(p);
            } else if (n == 23) {
                *(s16 *)(p + 0x1B8) = 3;
                *(s16 *)(p + 0x1BA) = 2;
                if (WF2DMAP_SCENE_CheckGridNumber((u8 *)p)) {
                    WF2DMAP_SCENE_BuildNumberList(p);
                    GFL_USE_PlaySeDefaultVolume(1357);
                } else {
                    WF2DMAP_SCENE_ResetState(p, 4);
                }
            } else if (n >= 12 && n <= 21) {
                if (*(int *)(p + 0x240) == 0) return;
                GFL_USE_PlaySeDefaultVolume(1356);
                idx = *(int *)(p + 0x188);
                r[idx].state = n - 11;
                CLACT_SetActorAnimSeq(r[idx].handle, WF2DMAP_SCENE_GetCellAnim(r[idx].state, r[idx].flag));
                WF2DMAP_SCENE_SetCursorVisible(p, 1, 1);
                m = n - 12;
                WF2DMAP_SCENE_SetCursorPos(p, m);
                WF2DMAP_SCENE_SetCursorVisible(p, 1, 0);
                WF2DMAP_SCENE_SetCursorVisible(p, 2, 1);
                WF2DMAP_SCENE_SetCursorPosBySlot(p, m, 2);
                CLACT_SetActorAnimSeq(*(struct Obj **)(p + 0x1CC), 3);
                v = r[idx].value;
                if (idx + 1 == *(int *)(p + 0x23C)) {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = 0;
                    *(int *)(p + 0x324) = 0;
                } else {
                    k = r[idx + 1].value;
                    if (v != k) {
                        *(int *)(p + 0x31C) = 1;
                        *(int *)(p + 0x320) = k;
                        *(int *)(p + 0x324) = 0;
                    } else {
                        *(int *)(p + 0x31C) = 2;
                        *(int *)(p + 0x320) = idx + 1;
                    }
                }
                WF2DMAP_SCENE_SetButtonCursor((u8 *)p, n);
            } else {
                *(s16 *)(p + 0x1B8) = (n - 12) % 5;
                *(s16 *)(p + 0x1BA) = (n - 12) / 5;
            }
        }
    }
}
