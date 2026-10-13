/*
 * function: func_021F36EC
 * address: 0x021F36EC
 * packet: pkt_ov049_021F36EC
 * region: ov049
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   func_021F3868 0x021F3868 thumb ov049
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 */
extern int *FIELDMAP_GetCommonWork(char *p,int idx);
extern void func_021F3868(int *q,char *p);
extern void FIELDMAP_FreeCommonWork(unsigned char *p,int id);
void func_021F36EC(char *p) { func_021F3868(FIELDMAP_GetCommonWork(p,0),p); FIELDMAP_FreeCommonWork((unsigned char *)p,0); }
