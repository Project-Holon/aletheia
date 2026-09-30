/*
 * function: func_021BD114
 * address: 0x021BD114
 * packet: pkt_ov110_021BD114
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021C38D9 0x021C38D9 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { void *root; u8 pad[0x8c]; void *items[2]; } Object;
extern const u8 d_021C38D9[];
extern void *func_021BAC78(void *,void *,int,int,int,int);
extern void func_0204B878(void *,u16);
extern void func_0204B3DC(void *,int);
void func_021BD114(Object *p) {
    u8 i;
    for(i=0;i<2;i++) {
        p->items[i]=func_021BAC78(p->root,(u8 *)p+0x10,d_021C38D9[3*i],d_021C38D9[3*i+1],0,1);
        func_0204B878(p->items[i],d_021C38D9[3*i+2]);
        func_0204B3DC(p->items[i],0);
    }
}
