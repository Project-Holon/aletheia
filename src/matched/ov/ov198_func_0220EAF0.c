/*
 * function: func_0220EAF0
 * address: 0x0220EAF0
 * packet: pkt_ov198_0220EAF0
 * region: ov198
 * status: EXACT
 * lever: the final pointer-table subscript preserves the unscaled index
 * spill and its fresh shift. Byte-offset pointer arithmetic CSEs that shift.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   func_0220E974 0x0220E974 thumb ov198
 *   func_0220EA30 0x0220EA30 thumb ov198
 *   d_02211DB4 0x02211DB4 data a2
 *   d_02211DCC 0x02211DCC data a2
 *   d_02211DE4 0x02211DE4 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
typedef struct {u8 bytes[76];} Record;
extern const Pair d_02211DB4[],d_02211DCC[],d_02211DE4[];
extern int func_022110D4(u8 *,int);
extern void func_0220E7CC(u8 *,unsigned);
extern void func_0220E974(unsigned,u8 *,const Pair *);
extern void func_0220EA30(u16,u8 *,Pair *);
void func_0220EAF0(Record *records) {
    u8 *p=(u8 *)records;
    short i;
    int index,offset;
    Pair pair;
    for(i=0;i<6;i++) {
        index=func_022110D4(p,i);
        offset=index*76;
        if(*(u16 *)((char *)records+offset+8)!=0) {
            func_0220E7CC(*(u8 **)(p+index*4+0x1ed8),(unsigned)&d_02211DB4[i]);
            func_0220E974(((Bits *)(p+0x1b))[offset].kind,*(u8 **)(p+index*4+0x1ef0),&d_02211DCC[i]);
            if(((Bits *)(p+0x1b))[offset].high==0)
                func_0220E7CC(*(u8 **)(p+index*4+0x1f08),(unsigned)&d_02211DE4[i]);
            pair=d_02211DB4[i];
            pair.x+=8;
            pair.y+=8;
            func_0220EA30(*(u16 *)((char *)records+offset+0x1e),((u8 **)(p+0x1ebc))[index],&pair);
        }
    }
}
