/*
 * function: WF2DMAP_SCENE_HandleInput
 * address: 0x021D8FA0
 * packet: pkt_ov129_021D8FA0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave P2 lane Q4, pengy share, user-approved for this function only): first draft, no twin found.
 * Earlier (824 B): the flag at [sp+4] is a member of a local struct with the table (struct { int flag; Tbl t; } L);
 * rec[idx] reads go through a const Record pointer; up and left write the store in each arm.
 * 2026-10-05 (wave P2 lane Q4b, 25-compile cap): 836 bytes now, same size as the original, 21 bytes differ, all in
 * the head (first 0x34 bytes). Closed this lane: (b) the L-button block is EXACT: the store of idx - 1 is written in each
 * arm (if (idx == 0) { idx = n; p->188 = idx - 1; } else { p->188 = idx - 1; }); cross-jumping keeps the shared subs/str
 * and leaves the then-arm's b to the next instruction (docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md).
 * (c) the R-button block is EXACT: idx = p->188; if (idx == p->23C - 1) store 0 else store idx + 1, store in each arm.
 * Remaining residue (a): the original emits movs r0,#0; str r0,[sp,#4] right after the row ldrsh and movs r7,#0xbf late.
 * Here the flag store comes after the final ldr r4 (flag init after cur) or before ldr r6 / row ldrsh (row as a local, flag
 * init between row and col; a pointer to the row gives 18 bytes with the store after muls). scheduling off does not change
 * the head, so the order is IR order, not the scheduler. Pragmas tried this lane with no gain: opt_propagation,
 * opt_dead_assignments, peephole, scheduling (no change), opt_common_subs (836 B but 401 bytes differ),
 * opt_lifetimes (34 differ). Tried and rejected: empty else {}, a wrap helper with (n, cur) parameter order (no change).
 * d_021DA75C has no witness outside the function (the pool word is inside it): give it an overlay token
 * in the integrator step.
 *
 * 2026-10-05 (wave P2 lane Q4c): EXACT. The flag is a plain int local (spilled to [sp+4]), not a struct member:
 * row is read into a local, then flag = 0, then cur = T.v[row][col] (IR order puts the zero store right after the row load).
 * d_021DA75C resolves with the data hint without the ov129 token (data a4).
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021D9E98 0x021D9E98 thumb ov129
 *   func_021D93D4 0x021D93D4 thumb ov129
 *   func_021D9320 0x021D9320 thumb ov129
 *   func_021D9348 0x021D9348 thumb ov129
 *   WF2DMAP_SCENE_ResetState 0x021D8AF4 thumb ov129
 *   func_021D9E48 0x021D9E48 thumb ov129
 *   func_021D9EE8 0x021D9EE8 thumb ov129
 *   func_021DA158 0x021DA158 thumb ov129
 *   d_021DA75C 0x021DA75C data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
struct Obj;
typedef struct { int v[3][5]; } Tbl;
typedef struct { int state, value, flag; struct Obj *handle; char tail[12]; } Record;
extern const Tbl d_021DA75C;
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetRepeat(void);
typedef unsigned char  u8;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_021D9E98(char *p, int i);
extern void func_021D93D4(char *p);
extern int func_021D9320(u8 *p);
extern void func_021D9348(char *p);
extern void WF2DMAP_SCENE_ResetState(char *p, int v);
extern void func_021D9E48(char *p, int i, int a);
extern void func_021D9EE8(char *p, int i, int j);
extern int func_021DA158(int x, int flag);

void WF2DMAP_SCENE_HandleInput(char *p)
{
    Tbl T = d_021DA75C;
    int flag;
    int row;
    int cur;
    int idx, n, k;
    const Record *r = (const Record *)p;

    row = *(s16 *)(p + 0x1BA);
    flag = 0;
    cur = T.v[row][*(s16 *)(p + 0x1B8)];

    if (*(int *)(p + 0x2FC) == 1 && KEY_GetTrg() != 0) {
        *(int *)(p + 0x2FC) = flag;
        func_021D9E98(p, cur);
        if (cur == 10 || cur == 11) {
            if (*(int *)(p + 0x1A4) == 2) return;
            *(int *)(p + 0x1A4) = 2;
            return;
        }
        if (*(int *)(p + 0x1A4) == 1) return;
        *(int *)(p + 0x1A4) = 1;
        return;
    }
    if (KEY_GetRepeat() & 0x40) {
        int v = *(s16 *)(p + 0x1BA);
        if (v > 0) *(s16 *)(p + 0x1BA) = v - 1; else *(s16 *)(p + 0x1BA) = 2;
        flag = 1;
    } else if (KEY_GetRepeat() & 0x80) {
        *(s16 *)(p + 0x1BA) += 1;
        *(s16 *)(p + 0x1BA) %= 3;
        flag = 1;
    } else if (KEY_GetRepeat() & 0x10) {
        if (cur == 10) *(s16 *)(p + 0x1B8) = 3;
        else if (cur == 11) *(s16 *)(p + 0x1B8) = 0;
        else {
            *(s16 *)(p + 0x1B8) += 1;
            *(s16 *)(p + 0x1B8) %= 5;
        }
        flag = 1;
    } else if (KEY_GetRepeat() & 0x20) {
        if (cur == 10) *(s16 *)(p + 0x1B8) = 3;
        else if (cur == 11) *(s16 *)(p + 0x1B8) = 0;
        else {
            int v = *(s16 *)(p + 0x1B8);
            if (v > 0) *(s16 *)(p + 0x1B8) = v - 1; else *(s16 *)(p + 0x1B8) = 4;
        }
        flag = 1;
    } else if (KEY_GetTrg() & 1) {
        if (cur == 10) {
            func_021D93D4(p);
            GFL_USE_PlaySeDefaultVolume(1363);
        } else if (cur == 11) {
            if (func_021D9320((u8 *)p)) {
                func_021D9348(p);
                GFL_USE_PlaySeDefaultVolume(1357);
            } else {
                WF2DMAP_SCENE_ResetState(p, 4);
            }
        } else {
            if (*(int *)(p + 0x240) == 0) return;
            idx = *(int *)(p + 0x188);
            ((Record *)p)[idx].state = cur + 1;
            func_021D9E48(p, 1, 0);
            func_021D9E48(p, 2, 1);
            func_021D9EE8(p, cur, 2);
            CLACT_SetActorAnimSeq(r[idx].handle, func_021DA158(r[idx].state, r[idx].flag));
            CLACT_SetActorAnimSeq(*(struct Obj **)(p + 0x1CC), 3);
            n = r[idx].value;
            if (idx + 1 == *(int *)(p + 0x23C)) {
                *(int *)(p + 0x31C) = 1;
                *(int *)(p + 0x320) = 0;
                *(s16 *)(p + 0x1B8) = 3;
                *(s16 *)(p + 0x1BA) = 2;
                flag = 1;
            } else {
                k = r[idx + 1].value;
                if (n != k) {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = k;
                } else {
                    *(int *)(p + 0x31C) = 2;
                    *(int *)(p + 0x320) = idx + 1;
                }
                GFL_USE_PlaySeDefaultVolume(1356);
            }
        }
    } else if (KEY_GetTrg() & 2) {
        func_021D93D4(p);
        GFL_USE_PlaySeDefaultVolume(1363);
    } else if (KEY_GetRepeat() & 0x200) {
        idx = *(int *)(p + 0x188);
        if (idx == 0) {
            idx = *(int *)(p + 0x23C);
            *(int *)(p + 0x188) = idx - 1;
        } else {
            *(int *)(p + 0x188) = idx - 1;
        }
        idx = *(int *)(p + 0x188);
        if (r[idx].flag == 1) {
            *(int *)(p + 0x31C) = 2;
            *(int *)(p + 0x320) = idx;
        } else {
            *(int *)(p + 0x31C) = 1;
            *(int *)(p + 0x320) = r[idx].value;
            *(int *)(p + 0x324) = 1;
        }
        GFL_USE_PlaySeDefaultVolume(1352);
    } else if (KEY_GetRepeat() & 0x100) {
        idx = *(int *)(p + 0x188);
        if (idx == *(int *)(p + 0x23C) - 1) {
            *(int *)(p + 0x188) = 0;
        } else {
            *(int *)(p + 0x188) = idx + 1;
        }
        idx = *(int *)(p + 0x188);
        if (r[idx].flag == 1) {
            *(int *)(p + 0x31C) = 2;
            *(int *)(p + 0x320) = idx;
        } else {
            *(int *)(p + 0x31C) = 1;
            *(int *)(p + 0x320) = r[idx].value;
        }
        GFL_USE_PlaySeDefaultVolume(1352);
    }
    if (flag == 1) {
        GFL_USE_PlaySeDefaultVolume(1352);
        cur = T.v[*(s16 *)(p + 0x1BA)][*(s16 *)(p + 0x1B8)];
        func_021D9E98(p, cur);
        if (cur == 10 || cur == 11) {
            if (*(int *)(p + 0x1A4) == 2) return;
            *(int *)(p + 0x1A4) = 2;
            return;
        }
        if (*(int *)(p + 0x1A4) != 1) *(int *)(p + 0x1A4) = 1;
    }
}
