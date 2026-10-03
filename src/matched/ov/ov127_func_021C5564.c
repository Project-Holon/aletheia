/*
 * function: func_021C5564
 * address: 0x021C5564
 * packet: pkt_ov127_021C5564
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y; } Pos;
extern Pos func_021C4AC4(void *);
void func_021C5564(u8 *out,void *p,int kind,int index,int value) { *(Pos *)out=func_021C4AC4(p); *(u16 *)(out+4)=kind; out[7]=index; out[6]=value; }
