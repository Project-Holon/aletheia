/*
 * function: BTL_MAIN_StartClientMainSteps
 * address: 0x021BA7F8
 * packet: pkt_ov093_021BA7F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_CLIENT_StartMainStep 0x021CD9B0 thumb ov093
 */

typedef unsigned char u8;
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern void BTL_CLIENT_StartMainStep(u8 *p);
void BTL_MAIN_StartClientMainSteps(char *p)
{
 unsigned int i;
 for (i = 0; i < 4; i++) {
  if (BTL_MAIN_IsClientUsed((unsigned char *)p, i)) BTL_CLIENT_StartMainStep(*(void **)(p + i * 4 + 0x10));
 }
}
