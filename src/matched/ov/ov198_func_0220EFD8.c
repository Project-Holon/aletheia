/*
 * function: func_0220EFD8
 * address: 0x0220EFD8
 * packet: pkt_ov198_0220EFD8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the copied Pair is a field of a struct-typed table (twin 0220EC2C's
 * Table1 shape, extended to offset 0x1c), not an indexed Pair array; the
 * array form hoists the 0x1ed8 resource load above the second strh.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   func_0220E974 0x0220E974 thumb ov198
 *   func_0220E9A0 0x0220E9A0 thumb ov198
 *   func_0220EA30 0x0220EA30 thumb ov198
 *   func_0220F060 0x0220F060 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D4C 0x02211D4C data a2
 *   d_02211D80 0x02211D80 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
typedef struct {Pair first,second;short pad[4];Pair third;short pad2[4];Pair fourth;} Table1;
extern const Table1 d_02211D34;
extern const Pair d_02211D4C;
extern const Pair d_02211D80;
extern int func_022110D4(u8 *,int);
extern void func_0220E7CC(u8 *,u32);
extern void func_0220E974(int,u8 *,const Pair *);
extern void func_0220E9A0(char *,u8 *,Pair *);
extern void func_0220EA30(u32,u8 *,const Pair *);
extern void func_0220F060(u8 *);
void func_0220EFD8(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.fourth;
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),&d_02211D4C);
    func_0220E9A0((char *)p,rec,(Pair *)&d_02211D80);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),&pair);
    func_0220F060(p);
}
