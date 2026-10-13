/*
 * function: func_021B8F38
 * address: 0x021B8F38
 * packet: pkt_ov093_021B8F38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 */
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern void *BTL_MAIN_GetCompetitor(void ***p);
int func_021B8F38(unsigned char *p) { unsigned int v; if(BTL_MAIN_IsMultiMode((unsigned char **)p)) { v=(unsigned int)BTL_MAIN_GetCompetitor((void ***)p); if(v!=1 && v!=0) return 1; } return 0; }
