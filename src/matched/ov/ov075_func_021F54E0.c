/*
 * function: ENCEFF_GetScreenTexParam
 * address: 0x021F54E0
 * packet: pkt_ov075_021F54E0
 * region: ov075
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: enum Bank preserves the cumulative OR tests; u32 folds the final test.
 * symbols:
 *   GX_GetBankForTex 0x02080C44 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef enum { BANK_NONE, BANK_A=1, BANK_B=2, BANK_C=4 } Bank;
extern u16 GX_GetBankForTex(void);
u32 ENCEFF_GetScreenTexParam(void) {
    Bank v;
    u32 n;
    v=GX_GetBankForTex(); n=0;
    v |= 4; if(v) n+=0x20000;
    v |= 2; if(v) n+=0x20000;
    v |= 1; if(v) n+=0x20000;
    return 0x20000000 | ((u16)(n>>3));
}
