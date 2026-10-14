/*
 * function: GDS_SOCKET_IsDottedQuad
 * address: 0x021D7D88
 * packet: pkt_ov125_021D7D88
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 */
int GDS_SOCKET_IsDottedQuad(const char *s) {
 int digits=0, dots=0;
 while (*s) {
  if (*s >= '0' && *s <= '9') {
   if (++digits >= 4) return 0;
  } else if (*s == '.') {
   if (digits == 0) return 0;
   ++dots;
   digits=0;
   if(dots >= 4) return 0;
  } else return 0;
  ++s;
 }
 if(dots==3 && digits!=0) return 1;
 return 0;
}
