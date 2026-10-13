/*
 * function: MONOLITH_TOOL_FreeActors
 * address: 0x021B68B4
 * packet: pkt_ov071_021B68B4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 ACTOR_TOOL_Delete at +0x26 has no outside witness.
 * split: TU confirms one image-wide witness, inside this caller; no cuts.
 * ARM9 stub: 02025358 ldr r3,[pc,#0]; bx r3; pool 020307B0.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   ACTOR_TOOL_Delete 0x02025358 thumb
 */
typedef unsigned int u32;
struct Bank;
extern void func_020434DC(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void BMP_OAM_DeleteSys(void *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void ACTOR_TOOL_Delete(void *);
void MONOLITH_TOOL_FreeActors(void **p)
{
    func_020434DC(0x10, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
    BMP_OAM_DeleteSys(p[11]);
    CLACT_DeleteUnit(p[5]);
    CLACT_ExitSystem();
    ACTOR_TOOL_Delete(p[1]);
}
