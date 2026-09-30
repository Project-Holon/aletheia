/*
 * function: func_021BF360
 * address: 0x021BF360
 * packet: pkt_ov110_021BF360
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BF39E.
 * symbols:
 *   func_021BEDD0 0x021BEDD0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BEDD0(void *);
int func_021BF360(u8 *p) {
    if (*(u16 *)p<*(u16 *)(p+2)) {
        if (*(u16 *)p+6<=*(u16 *)(p+2)) { *(u32 *)(p+8)=6; *(u16 *)p+=6; }
        else { *(u32 *)(p+8)=*(u16 *)(p+2)-*(u16 *)p; *(u16 *)p=*(u16 *)(p+2); }
        if(func_021BEDD0(p)<*(u16 *)(p+4)-2) return 2;
        p[6]=0; return 3;
    }
    return 4;
}
