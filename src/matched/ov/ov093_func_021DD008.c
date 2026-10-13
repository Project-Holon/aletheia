/*
 * function: HAND_ITEM_GetBoostRatio
 * address: 0x021DD008
 * packet: pkt_ov093_021DD008
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   HAND_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
extern int HAND_ITEM_GetParam(int,int);
int HAND_ITEM_GetBoostRatio(int a) { int n; float f; n=HAND_ITEM_GetParam(a,2)+100; if(n>0) f=0.5f+(float)(n<<12); else f=(float)(n<<12)-0.5f; return (int)f/100; }
