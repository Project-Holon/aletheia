/*
 * function: FIELD_GIMMICK_MODELS_B_Exit
 * address: 0x021F36EC
 * packet: pkt_ov050_021F36EC
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two-byte alignment padding at 0x021F3706 follows the return.
 * symbols:
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELD_GIMMICK_MODELS_B_ExitExtra 0x021F3894 thumb ov050
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 */

extern int *FIELDMAP_GetCommonWork(char *, int);
extern void FIELD_GIMMICK_MODELS_B_ExitExtra(int *, char *);
extern void FIELDMAP_FreeCommonWork(unsigned char *, int);
void FIELD_GIMMICK_MODELS_B_Exit(char *p) { FIELD_GIMMICK_MODELS_B_ExitExtra(FIELDMAP_GetCommonWork(p,1),p); FIELDMAP_FreeCommonWork((unsigned char *)p,1); }
