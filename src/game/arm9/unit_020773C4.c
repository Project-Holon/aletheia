/*
 * file:     unit_020773C4.c
 * unit:     yes
 * function: CARD_WaitRomAsync, CARDi_GetRomCacheBuffer
 * address:  0x020773C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0215086C  0x0215086C  data
 */
extern void func_02076050(void);
void CARD_WaitRomAsync(void);
void *CARDi_GetRomCacheBuffer(void);
extern char g_0215086C[];

void CARD_WaitRomAsync(void){ func_02076050(); }


/*
 * Getter returning the address of a global (CARDi_GetOwnSignature).  Called
 * from the ov107 segment reader 0x021F2FA0.
 */
void *CARDi_GetRomCacheBuffer(void)
{
    return g_0215086C;
}
