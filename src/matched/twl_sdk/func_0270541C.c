/*
 * function: DSPi_CommitWram
 * address:  0x0270541C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_GetWramBankMaster 0x02730388 arm twl
 */
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef struct Chan {
    u32 pad[10];
    u32 tabA[8];
    u32 tabB[8];
} Chan;
extern s32 MI_IsWramSlotUsed(s32 sel, u32 id);
extern s32 MI_GetWramBankMaster(s32 sel, u32 id);
extern s32 MI_FreeWramSlot(s32 sel, u32 id, s32 n, s32 v);
extern s32 MI_AllocWramSlot(s32 sel, u32 id, s32 n, s32 mode);
u32 DSPi_CommitWram(Chan *c, s32 sel, u32 idx, s32 mode)
{
    u32 ok;
    u32 id;
    u8 *p;
    if (sel == 1) {
        id = c->tabA[idx];
    } else {
        id = c->tabB[idx];
    }
    ok = 0;
    if (MI_IsWramSlotUsed(sel, id) == 0 || MI_FreeWramSlot(sel, id, 1, MI_GetWramBankMaster(sel, id)) > 0) {
        if (MI_AllocWramSlot(sel, id, 1, mode) != 0) {
            p = (u8 *)(sel == 1 ? 0x04004044 : 0x0400404C);
            if (mode == 0) {
                p[id] = (p[id] & ~0x1c) | (id << 2);
            } else if (mode == 2) {
                p[id] = (p[id] & ~0x1c) | (idx << 2);
            }
            ok = 1;
        }
    }
    return ok;
}
