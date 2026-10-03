/*
 * function: func_02210B30
 * address: 0x02210B30
 * packet: pkt_ov198_02210B30
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02210EFC 0x02210EFC thumb ov198
 *   func_02210B00 0x02210B00 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   d_02212130 0x02212130 data a1
 */
typedef unsigned char u8;
struct Order {u8 ids[6];};
struct Flags {u8 low:7,high:1;};
extern const struct Order d_02212130;
extern unsigned func_02210EFC(unsigned);
extern int func_02210B00(u8 *,unsigned);
extern int func_022110D4(u8 *,int);
u8 func_02210B30(u8 *p,int i,int delta)
{
    int current=i;
    if(func_02210EFC((unsigned)p)==1) {
        struct Order order=d_02212130;
        u8 selected;
        for(i=0;i<6;i++) if(current==order.ids[i]) break;
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            selected=order.ids[i];
            if(current==selected) break;
            if(!func_02210B00(p,selected)) continue;
            if(((struct Flags *)(p+func_022110D4(p,selected)*0x4c+0x1b))->high) continue;
            return selected;
        }
    } else {
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            if(current==i) break;
            if(!func_02210B00(p,i)) continue;
            if(((struct Flags *)(p+func_022110D4(p,i)*0x4c+0x1b))->high) continue;
            return i;
        }
    }
    return 255;
}
