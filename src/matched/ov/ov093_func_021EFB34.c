/*
 * function: func_021EFB34
 * address: 0x021EFB34
 * packet: pkt_ov093_021EFB34
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned long outer index closes register rotation and missing base spill.
 * symbols:
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021EFC0C 0x021EFC0C thumb ov093
 *   BTL_FIELD_ResetSlot 0x021EF83C thumb ov093
 *   BTLV_CORE_GetSlotPosition 0x021E8A98 thumb ov093
 *   BTLV_CORE_SetSlotPosition 0x021E8AC8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v; } Slot;
typedef struct {
    u32 pad00[2];
    u32 t[8];
    Slot c[8];
    u32 z48[8];
    u32 w[8][6];
    u32 z128[8];
    u32 used[8];
} S;
extern void *func_021EFCE4(char *, int);
extern void func_021EFC0C(u32);
extern void BTL_FIELD_ResetSlot(char *, u32);
extern u32 BTLV_CORE_GetSlotPosition(Slot);
union Slot;
extern void BTLV_CORE_SetSlotPosition(union Slot *p, u8 v);
void func_021EFB34(S *a, u32 v)
{
    unsigned long i;
    u32 j;
    int found;
    for (i = 0; i < 8; i++) {
        if (func_021EFCE4((char *)a, i) && a->z128[i]) {
            found = 0;
            for (j = 0; j < a->z128[i]; j++) {
                if (v == a->w[i][j]) { found = 1; break; }
            }
            if (found) {
                for (; j < 5; j++) a->w[i][j] = a->w[i][j + 1];
                a->w[i][j] = 0x1f;
                a->z128[i] = a->z128[i] - 1;
                if (a->z128[i] == 0) {
                    if (a->t[i]) { func_021EFC0C(a->t[i]); a->t[i] = 0; }
                    BTL_FIELD_ResetSlot((char *)a, i);
                } else {
                    if (v == BTLV_CORE_GetSlotPosition(a->c[i])) BTLV_CORE_SetSlotPosition((union Slot *)(&a->c[i]), a->w[i][0]);
                }
            }
        }
    }
}
