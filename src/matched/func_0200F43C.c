
/*
 * function: func_0200F43C
 * address:  0x0200F43C
 * packet:   pkt_0200F43C
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02009860           0x02009860  thumb
 *   sub_020099C8            0x020099C8  thumb
 *   func_02009A34           0x02009A34  thumb
 *   DWC_CheckFriendKey      0x02059354  arm
 *   DWC_CreateFriendKeyToken 0x02059980 arm
 *   DWC_GetGsProfileId      0x020598EC  arm
 *   DWC_IsValidFriendData   0x020596D8  arm
 *
 * The friend-list lookup: build a DWC friend-key token from the 64-bit
 * friend key, and compare its GS profile id against every entry of the
 * DWCFriendData (0xC-byte) array; report the matching slot through *out.
 * Returns 3 if the key is bad or the token has no profile id, 0 on a hit,
 * 2 if the list was walked without one; *out is left holding the first slot
 * whose record fails DWC_IsValidFriendData when there is no hit, -1 when
 * there is not even one of those.
 *
 * Closed in wave 12 by two declaration facts the earlier passes missed:
 *  - the key is ONE u64 (DWC_CheckFriendKey / DWC_CreateFriendKeyToken take
 *    a u64 friendKey), not two ints: that is why r1:r2 are homed together
 *    at sp+0/sp+4;
 *  - the array is typed as 12-byte records and indexed as arr[i], so the
 *    i*12 offset is computed once at the loop top into a callee-saved
 *    register ahead of both uses (a u8 pointer plus i * 0xC is recomputed
 *    and spilled per use, which is what pushed p into r7 and cost 2 bytes).
 * Both profile lookups stay inside the loop, as in the image.
 *
 * EXACT* only because the listing extent includes the two-byte
 * "movs r0, r0" alignment filler after the function.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct { u32 w[3]; } DWCFriendData;

extern void *func_02009860(void *obj);
extern DWCFriendData *sub_020099C8(void *obj, int i);
extern int   func_02009A34(void *obj);

extern int  DWC_CheckFriendKey(void *p, u64 key);
extern void DWC_CreateFriendKeyToken(DWCFriendData *tok, u64 key);
extern int  DWC_GetGsProfileId(void *p, const DWCFriendData *rec);
extern int  DWC_IsValidFriendData(const DWCFriendData *rec);

int func_0200F43C(void *obj, u64 key, int *out)
{
    void *p;
    DWCFriendData *arr;
    int n;
    int i;
    DWCFriendData tok;

    p = func_02009860(obj);
    i = 0;
    arr = sub_020099C8(obj, 0);
    n = func_02009A34(obj);

    if (DWC_CheckFriendKey(p, key) == 0)
        return 3;

    DWC_CreateFriendKeyToken(&tok, key);
    if (DWC_GetGsProfileId(p, &tok) <= 0)
        return 3;

    *out = i - 1;
    for (; i < n; i++) {
        if (DWC_GetGsProfileId(p, &tok) == DWC_GetGsProfileId(p, &arr[i])) {
            *out = i;
            return 0;
        }
        if (*out < 0 && DWC_IsValidFriendData(&arr[i]) == 0)
            *out = i;
    }
    return 2;
}
