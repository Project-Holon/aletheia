/*
 * function: ZUKAN_DETAIL_FORM_HandleKeyEvent
 * address: 0x021C4298
 * packet: pkt_ov208_021C4298
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, wD9r lane66): closed from 1248 bytes. Fixes, all read from the listing: (1) every
 *   division is _u32_div_f, so both inner modulos take a u32 divisor (the draft had a signed one in
 *   case 0x1c); (2) the field is re-read after the H(k + 6) compare: H(k + 8)++ in case 0x1c and
 *   += in case 0x1d (a plain x = x + 1 reuses the compare load); with these, ev spills to its home
 *   slot and r7 holds k as in the image; (3) flag is int; (4) bufA/bufB and sA/sB declared in that
 *   order, and sys, flag, cur, id2 in that order, give the image frame; (5) case 0: break; (its
 *   jump table entry is the shared epilogue) and the last switch's case order follows the image
 *   block order.
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry 0x021BC3C0 thumb ov208
 *   ov208_func_021BC3CC 0x021BC3CC thumb ov208
 *   ov208_func_021BC40C 0x021BC40C thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb ov208
 *   ZUKAN_DETAIL_FORM_BuildFormEntries 0x021C53F4 thumb ov208
 *   ZUKAN_DETAIL_FORM_RebuildModels 0x021C580C thumb ov208
 *   ZUKAN_DETAIL_FORM_RebuildSideModels 0x021C5C64 thumb ov208
 *   ZUKAN_DETAIL_FORM_HandleStateEvent 0x021C5F34 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible 0x021BDBEC thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState 0x021BDBA0 thumb ov208
 *   ov208_func_021BDC2C 0x021BDC2C thumb ov208
 *   GAME_DATA_SetSaveFlag 0x02012BE0 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Sel {
    u16 next;
    u16 sel;
    u16 twos;
    u16 groups;
    u16 count;
};

extern void *ZUKAN_DETAIL_COMMON_GetWorkPtr(int key);
extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(int key);
extern void ov208_func_021BC3CC(int key);
extern void ov208_func_021BC40C(int key);
extern int ZUKAN_DETAIL_COMMON_GetSource(int key);
extern void ZUKAN_DETAIL_FORM_BuildFormEntries(u16 *heap, int key, u8 *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next);
extern void ZUKAN_DETAIL_FORM_RebuildModels(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_RebuildSideModels(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_HandleStateEvent(u16 *heap, u8 *p, int key, int mode);
extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(void *sys, int v);
extern void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(void *sys);
extern int ov208_func_021BDC2C(void *sys);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

void ZUKAN_DETAIL_FORM_HandleKeyEvent(void *proc, int *seq, u16 *heap, u8 *p, int key, int ev)
{
    u8 bufA[0x400];
    u8 bufB[0x400];
    struct Ov208Sel sA;
    struct Ov208Sel sB;
    u32 id;
    void *sys;
    int flag;
    u32 cur;
    u32 id2;
    u32 n;
    u32 k;
    if (p == 0)
        return;
    sys = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    flag = 0;
    W(0x698) = flag;
    W(0x6d4) = flag;
    switch (ev) {
    case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11:
    case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20:
        W(0x6b4) = flag;
        break;
    }
    switch (ev) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        flag = 1;
        W(0x6b4) = 1;
        break;
    }
    switch (ev) {
    case 0xc:
    case 0x1e:
        if (W(0x6b8) == 0) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ov208_func_021BC3CC(key);
            if (id != ZUKAN_DETAIL_COMMON_GetCurrentEntry(key))
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ov208_func_021BC3CC(key);
            cur = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            while (id != cur) {
                ZUKAN_DETAIL_FORM_BuildFormEntries(heap, key, bufA, &sA.count, &sA.groups, &sA.twos, &sA.sel, &sA.next);
                if (sA.count >= 2)
                    break;
                ov208_func_021BC3CC(key);
                cur = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            }
            if (id != cur) {
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
                if (sA.count >= 3)
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 1);
                else
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 0);
            }
        }
        break;
    case 0xd:
    case 0x1f:
        if (W(0x6b8) == 0) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ov208_func_021BC40C(key);
            if (id != ZUKAN_DETAIL_COMMON_GetCurrentEntry(key))
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ov208_func_021BC40C(key);
            id2 = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            while (id != id2) {
                ZUKAN_DETAIL_FORM_BuildFormEntries(heap, key, bufB, &sB.count, &sB.groups, &sB.twos, &sB.sel, &sB.next);
                if (sB.count >= 2)
                    break;
                ov208_func_021BC40C(key);
                id2 = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            }
            if (id != id2) {
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
                if (sB.count >= 3)
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 1);
                else
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 0);
            }
        }
        break;
    case 0x1c:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8)++;
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                H(k + 8)++;
                n = H(k);
                H(k + 8) = H(k + 8) % n;
            }
            ZUKAN_DETAIL_FORM_RebuildSideModels(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x1d:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8) += (u16)(n - 1);
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                H(k + 8) += (u16)(H(k) - 1);
                H(k + 8) = H(k + 8) % (u32)H(k);
            }
            ZUKAN_DETAIL_FORM_RebuildSideModels(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x20:
        if (H(0x548) >= 2) {
            ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 5);
            W(0x6d8) = 1;
            W(0x6dc) = 0;
            W(0x6e0) = 0;
        } else {
            W(0x6d8) = 1;
            W(0x6dc) = 1;
            W(0x6e0) = 0;
        }
        break;
    }
    switch (ev) {
    case 0:
        break;
    case 1:
    case 2:
        W(0x6b0) = 2;
        return;
    case 6:
    case 7:
    case 8:
        W(0x6b0) = 1;
        return;
    case 3:
    case 24:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 4:
    case 25:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 5:
        GAME_DATA_SetSaveFlag((void *)ZUKAN_DETAIL_COMMON_GetSource(key), 0x14, ov208_func_021BDC2C(sys));
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 22:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 23:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 21:
        if (W(0x6b8) == 4)
            ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 6);
        return;
    case 26:
        if (W(0x6d8) != 0) {
            W(0x6e0) = 1;
            if (W(0x6dc) != 0) {
                W(0x6d8) = 0;
                ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
                return;
            }
        }
        return;
    default:
        if (flag != 0)
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    }
}
