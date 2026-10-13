/*
 * function: C_GEAR_POWER_ONOFF_ExitWindows
 * address: 0x021F0218
 * packet: pkt_ov035_021F0218
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0201F614 THM_CALL at +0x36 has no outside witness.
 * interface: 0201F614 forwards r0 and splits packed r1 into two halfwords;
 *            02028604 uses only r0; legacy trailing inputs are unread.
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *
 * 2026-10-05 (D8 lane 15): 0201F614 now filed EXACT as src/matched/arm9/func_0201F614.c (u16 lo, u16 hi split of r1).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int APP_KEYCURSOR_Delete(int a0);
extern void TCBL_Destroy(struct S02031140 *p);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_0201F614(int, unsigned int);
void C_GEAR_POWER_ONOFF_ExitWindows(char *p)
{
    if (*(void **)(p + 0x24)) {
        PRINTSYS_PrintStreamDelete(*(void **)(p + 0x24));
        *(void **)(p + 0x24) = 0;
        STRBUF_Delete(*(void **)(p + 0x28));
        *(void **)(p + 0x28) = 0;
    }
    APP_KEYCURSOR_Delete((int)(*(void **)(p + 0x30)));
    TCBL_Destroy(*(void **)(p + 0x20));
    BMP_WIN_Delete(*(void **)(p + 0x1c));
    BMP_WIN_Delete(*(void **)(p + 0x18));
    func_0201F614(5, *(unsigned int *)(p + 0x14));
}
