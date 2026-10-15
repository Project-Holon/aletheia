/*
 * function: PMS_INPUT_Destroy
 * address: 0x021BD764
 * packet: pkt_ov110_021BD764
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * blocker: 0x02024224, Thumb ARM9, integrator-owned unlabelled tail forwarder.
 * No witness outside this caller; tu --suggest-split leaves it out.
 * Scratch one verdict EXACT (12 bytes), fixed compiler/flags, no region:
 * Blocker relocation: func_020355D8 0x020355D8 arm (matched).
 * extern void func_020355D8(void *);
 * void PMSI_PARAM_SetUiInputMode(void *a,void *b) { func_020355D8(b); }
 * The caller visibly loads both r0 and r1, so its extern retains both arguments.
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   PMSI_PARAM_SetUiInputMode 0x02024224 thumb
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   PMS_INPUT_VIEW_Delete 0x021B9B20 thumb ov110
 *   TCB_Noop 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B95F4 0x021B95F4 thumb ov110
 *   PMSI_SEARCH_Delete 0x021BAF4C thumb ov110
 *   func_020315D4 0x020315D4 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PMSI_PARAM_SetUiInputMode(void *,void *);
extern void BUTTON_MAN_Delete(void *);
extern void PMS_INPUT_VIEW_Delete(u8 *);
extern void TCB_Noop(void *);
extern u32 func_020307B0(void *p);
extern void func_021B95F4(char *);
extern void PMSI_SEARCH_Delete(unsigned);
struct Proc;
extern void func_020315D4(struct Proc *p);
void PMS_INPUT_Destroy(u8 *p,void *a)
{
    PMSI_PARAM_SetUiInputMode(*(void **)p,*(void **)(p+0x70));
    BUTTON_MAN_Delete(*(void **)(p+0x44));
    PMS_INPUT_VIEW_Delete(*(u8 **)(p+0x14));
    TCB_Noop(*(void **)(p+0x7c));
    func_020307B0(*(void **)(p+0x78));
    func_021B95F4(*(char **)(p+0x18));
    PMSI_SEARCH_Delete(*(u32 *)(p+0x1c));
    func_020315D4(a);
}
