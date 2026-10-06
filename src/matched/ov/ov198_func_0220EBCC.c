/*
 * function: func_0220EBCC
 * address: 0x0220EBCC
 * packet: pkt_ov198_0220EBCC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a char cast only on the later resource access prevents CSE of
 * the base-plus-index sum, preserving the byte-offset spill across E7CC.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   func_0220EA30 0x0220EA30 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y;} Pair;
typedef struct {u8 bytes[76];} Record;
extern const Pair d_02211D34;
extern int func_022110D4(u8 *,int);
extern void func_0220E7CC(u8 *,unsigned);
typedef unsigned int   u32;
struct Vec2;
extern void func_0220EA30(u32 mode, u8 *p, const struct Vec2 *q);
void func_0220EBCC(Record *records)
{
    u8 *p=(u8 *)records;
    int i;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    pair=d_02211D34;
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(p+i*0x4c+0x1e),*(u8 **)((char *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
}
