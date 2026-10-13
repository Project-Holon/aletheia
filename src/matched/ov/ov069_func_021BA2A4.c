/*
 * function: BSUBWAY_RECORD_LIST_PollTouchAndCancel
 * address: 0x021BA2A4
 * packet: pkt_ov069_021BA2A4
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   BSUBWAY_RECORD_LIST_HandleAction 0x021BA2D8 thumb ov069
 *   sTouchRects 0x021BA5FC data a4
 */
extern int TOUCHPANEL_HitTrg(const void *key);
extern unsigned func_020362DC(void);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void BSUBWAY_RECORD_LIST_HandleAction(char *o, int k);
extern const char sTouchRects[];
int BSUBWAY_RECORD_LIST_PollTouchAndCancel(char *p)
{
    int k;
    k = TOUCHPANEL_HitTrg(sTouchRects);
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        k = 2;
    }
    BSUBWAY_RECORD_LIST_HandleAction(p, k);
    return k;
}
