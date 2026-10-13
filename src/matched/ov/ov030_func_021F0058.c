/*
 * function: NO_GEAR_Init
 * address: 0x021F0058
 * packet: pkt_ov030_021F0058
 * region: ov030
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: empty ov030 callback NO_GEAR_Step now matched in its own shard.
 * interface: caller sets r2=0x149 despite two-input thunk/leaf; retained
 * in the caller extern to reproduce original argument setup.
 * symbols:
 *   NO_GEAR_SetupBackgrounds 0x021EFF54 thumb ov030
 *   NO_GEAR_LoadGraphics 0x021EFECC thumb ov030
 *   NO_GEAR_SetStepFunc 0x021EFEC4 thumb ov030
 *   NO_GEAR_Step 0x021F00C4 thumb ov030
 */
extern void NO_GEAR_SetupBackgrounds(void);
extern void NO_GEAR_LoadGraphics(void *);
extern void NO_GEAR_SetStepFunc(void *, void (*)(void *), int);
extern void NO_GEAR_Step(void *);
void NO_GEAR_Init(void *p)
{
    NO_GEAR_SetupBackgrounds();
    NO_GEAR_LoadGraphics(p);
    NO_GEAR_SetStepFunc(p, NO_GEAR_Step, 0x149);
}
