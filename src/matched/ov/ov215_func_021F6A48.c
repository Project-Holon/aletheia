/*
 * function: func_021F6A48
 * address: 0x021F6A48
 * packet: pkt_ov215_021F6A48
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 *   func_021F6CAC 0x021F6CAC thumb ov215
 *   func_021F6AEC 0x021F6AEC thumb ov215
 *   func_021F6CCC 0x021F6CCC thumb ov215
 */
typedef unsigned char u8;
struct McssFade;
extern void MCSS_SetVanishFlag(void *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void func_021F6CAC(char *);
extern void func_021F6AEC(char *);
extern void func_021F6CCC(char *,unsigned,int);
void func_021F6A48(char *p,int a)
{
    func_021F6CAC(p);
    *(int *)(p + 4) = a;
    func_021F6AEC(p);
    func_021F6CCC(p,0,0);
    MCSS_SetVanishFlag(*(void **)(p + 0x34));
    MCSS_SetPaletteFade(*(struct McssFade **)(p + 0x34),16,16,0,32767);
    *(int *)(p + 0xC) = 5;
}
