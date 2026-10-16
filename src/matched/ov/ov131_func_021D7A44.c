/*
 * function: P_STA_SUB_GetSpeciesAdjust
 * address: 0x021D7A44
 * packet: pkt_ov131_021D7A44
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */
typedef unsigned int   u32;
extern void *P_STATUS_GetPokePara(unsigned char *p);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
void P_STA_SUB_GetSpeciesAdjust(void *p,int unused,int *a,int *b) {
 int n=POKE_TOOL_GetBoxValue(P_STATUS_GetPokePara(p),5,0);
 if(n==5) {b[1]=0x299a;a[1]=0xf4cd;return;}
 if(n==37) {a[1]=0xfb33;return;}
 if(n==86) {a[0]=0x10666;a[1]=0x10666;return;}
 if(n==155) {a[0]=0xfe66;a[1]=0xfb33;return;}
 if(n==179) {a[0]=0x10333;a[1]=0x10333;return;}
 if(n==225) {a[0]=0xfccd;a[1]=0xfccd;return;}
 if(n==248) {a[0]=0xfccd;a[1]=0xfccd;return;}
 if(n==310) {a[0]=0xf800;a[1]=0xf800;return;}
 if(n==311) {a[0]=0xfb33;a[1]=0xfb33;return;}
 if(n==391) {a[0]=0xfb33;a[1]=0xf99a;}
}
