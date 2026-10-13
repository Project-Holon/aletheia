/*
 * function: func_0204A600
 * address:  0x0204A600
 * packet:   pkt_0204A600
 * isa:      arm
 * status:   EXACT
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * symbols:
 *   lbl_02146A74  0x02146A74 data
 *   CLACT_SetSystemActive 0x0204BAEC arm
 *   CLACT_ResetOamIfPending 0x0204BB54 arm
 *   CLACT_DrawAllUnits 0x0204BB8C arm
 *   func_02066998 0x02066998 arm
 */

typedef unsigned int u32;

struct Struct_0204A600 {
    char pad_00[0xEC];
    void *field_EC;
};

extern struct Struct_0204A600 *lbl_02146A74;

extern void CLACT_SetSystemActive(int a0);
extern void CLACT_ResetOamIfPending(void);
extern void CLACT_DrawAllUnits(void);
extern void func_02066998(void);

void func_0204A600(void)
{
    struct Struct_0204A600 *p = lbl_02146A74;

    if (p == 0) {
        return;
    }

    CLACT_SetSystemActive(0);
    CLACT_ResetOamIfPending();
    CLACT_DrawAllUnits();

    p = lbl_02146A74;
    if (p->field_EC != 0) {
        func_02066998();
    }

    CLACT_SetSystemActive(1);
}
