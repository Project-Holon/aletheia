/*
 * function: func_021B8E50
 * address: 0x021B8E50
 * packet: pkt_ov106_021B8E50
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding after the return.
 * symbols:
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 */
typedef struct { int x,y; } Pair;
extern int TOUCHPANEL_GetCont(void);
int func_021B8E50(char *p, Pair *a, Pair *b, Pair *c) {
 if (TOUCHPANEL_GetCont()) {
 if(a) *a=*(Pair *)p;
 if(b) *b=*(Pair *)(p+8);
 if(c) *c=*(Pair *)(p+24);
 return 1;
 }
 return 0;
}
