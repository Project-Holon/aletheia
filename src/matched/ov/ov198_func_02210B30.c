/*
 * function: B_PLIST_MAIN_NextSelectable
 * address: 0x02210B30
 * packet: pkt_ov198_02210B30
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOwnerFlag18 0x02210EFC thumb ov198
 *   B_PLIST_MAIN_GetSlotState 0x02210B00 thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   d_02212130 0x02212130 data a1
 */
typedef unsigned char u8;
struct Order {u8 ids[6];};
struct Flags {u8 low:7,high:1;};
extern const struct Order d_02212130;
extern int B_PLIST_MAIN_GetOwnerFlag18(char **p);
extern int B_PLIST_MAIN_GetSlotState(u8 *p, int i);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
u8 B_PLIST_MAIN_NextSelectable(u8 *p,int i,int delta)
{
    int current=i;
    if(B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1) {
        struct Order order=d_02212130;
        u8 selected;
        for(i=0;i<6;i++) if(current==order.ids[i]) break;
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            selected=order.ids[i];
            if(current==selected) break;
            if(!B_PLIST_MAIN_GetSlotState(p,selected)) continue;
            if(((struct Flags *)(p+B_PLIST_MAIN_GetOrderIndex(p,selected)*0x4c+0x1b))->high) continue;
            return selected;
        }
    } else {
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            if(current==i) break;
            if(!B_PLIST_MAIN_GetSlotState(p,i)) continue;
            if(((struct Flags *)(p+B_PLIST_MAIN_GetOrderIndex(p,i)*0x4c+0x1b))->high) continue;
            return i;
        }
    }
    return 255;
}
