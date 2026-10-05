/*
 * function: func_0220EECC
 * address: 0x0220EECC
 * packet: pkt_ov198_0220EECC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: each bit-test if/else writes its 0220E7CC call per arm (tail merge keeps 0x1ed8 live); rec byte read as (rec+n*8)[0x31]
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   func_0220E974 0x0220E974 thumb ov198
 *   func_0220E9A0 0x0220E9A0 thumb ov198
 *   func_0220EA30 0x0220EA30 thumb ov198
 *   func_0220E8B4 0x0220E8B4 thumb ov198
 *   func_0201BD28 0x0201BD28 thumb
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D3C 0x02211D3C data a2
 *   d_02211D40 0x02211D40 data a2
 *   d_02211D5C 0x02211D5C data a2
 *   d_02211D90 0x02211D90 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
typedef struct {u8 low:6;u8 a:1;u8 b:1;} Fl;
typedef struct {char pad[0x1F58];u8 *a;u8 *b;} Q;
typedef struct {Pair first,second;short pad[4];Pair third;short pad2[6];Pair fourth;} Table1;
extern const Table1 d_02211D34;
extern const Pair d_02211D3C;
extern const Pair d_02211D40;
extern const Pair d_02211D5C;
extern const Pair d_02211D90;
extern int func_022110D4(u8 *,int);
extern void func_0220E7CC(u8 *,u32);
extern void func_0220E974(int,u8 *,const Pair *);
extern void func_0220E9A0(char *,u8 *,Pair *);
extern void func_0220EA30(u32,u8 *,const Pair *);
extern void func_0220E8B4(char *,int,int,int);
extern int func_0201BD28(int,int);
void func_0220EECC(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    unsigned n;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.fourth;
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),&d_02211D3C);
    func_0220E9A0((char *)p,rec,(Pair *)&d_02211D90);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),&pair);
    if(((Fl *)(p+0x2175))->a==0) func_0220E7CC(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x22)*4+0x1ebc),(u32)&d_02211D40);
    else func_0220E7CC(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x1d)*4+0x1ebc),(u32)&d_02211D40);
    if(((Fl *)(p+0x2175))->b==0) func_0220E7CC(*(u8 **)(p+0x1F58),(u32)&d_02211D5C);
    else func_0220E7CC(*(u8 **)(p+0x1F5C),(u32)&d_02211D5C);
    n=(*(u8 **)p)[0x4b];
    if(n<4) func_0220E8B4((char *)p,0x27,0x16,(rec+n*8)[0x31]);
    else func_0220E8B4((char *)p,0x27,0x16,func_0201BD28(*(u16 *)(*(u8 **)p+0x26),2));
}
