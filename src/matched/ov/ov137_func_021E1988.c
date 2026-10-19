/*
 * function: GURU2_MAIN_PushAndPlayBgm
 * address: 0x021E1988
 * packet: pkt_ov137_021E1988
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Legacy 02005E64 source lists four inputs, but its complete
 * body saves no entry input and starts with 02005FBC(void); omitted them.
 * symbols:
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 */
extern void GFL_USE_SetBgmPaused(void *);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned int,unsigned short);
void GURU2_MAIN_PushAndPlayBgm(unsigned int n) { GFL_USE_SetBgmPaused((void *)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(n,65535); }
