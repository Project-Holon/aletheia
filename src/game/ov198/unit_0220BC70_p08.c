/*
 * file:     unit_0220BC70_p08.c
 * unit:     yes
 * function: func_0220ED54, func_0220EE44
 * address:  0x0220ED54
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   func_0220E974 0x0220E974 thumb ov198
 *   func_0220E9A0 0x0220E9A0 thumb ov198
 *   func_0220EA30 0x0220EA30 thumb ov198
 *   func_0220E8B4 0x0220E8B4 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D60 0x02211D60 data a2
 *   d_02211D88 0x02211D88 data a2
 *   d_02211D58 0x02211D58 data a2
 *   d_02211D48 0x02211D48 data a2
 *   func_0220F060 0x0220F060 thumb ov198
 *   d_02211D4C 0x02211D4C data a2
 *   d_02211D80 0x02211D80 data a2
 */
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {short x,y;} Pair;

typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;

typedef struct {u8 low:6;u8 bit:1;u8 high:1;} Flag;

typedef struct {Pair first,second;short pad[4];Pair third;short pad2[4];Pair fourth;short pad3[8];Pair fifth;} Table1_0220ED54;

typedef struct {Pair first,second;short pad[4];Pair third;short pad2[4];Pair fourth;} Table1_0220EE44;

extern int func_022110D4(u8 *,int);
extern void func_0220E7CC(u8 *,u32);
extern void func_0220E974(int mode, u8 *p, const struct Vec2 *q);
extern void func_0220E9A0(char *,u8 *,const Pair *);
extern void func_0220EA30(u32 mode, u8 *p, const struct Vec2 *q);
extern void func_0220E8B4(char *,int,int,int);
extern void func_0220F060(u8 *);
void func_0220ED54(u8 *p);
void func_0220EE44(u8 *p);
extern const Table1_0220ED54 d_02211D34;
extern const Pair d_02211D60;
extern const Pair d_02211D88;
extern const Pair d_02211D58;
extern const Pair d_02211D48;
extern const Pair d_02211D4C;
extern const Pair d_02211D80;

/*
 * note 2026-10-05 (wD6 lane16): EXACT. The 0x1ebc call is written in each arm of the idx if/else (tail-merged), so the
 *   0x1ED8 pool word stays CSE-live into it; the 0x1F58/0x1F5C read is a ternary of two loads; rec + k*8 + 0x31 as pointer adds.
 */
void func_0220ED54(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    int idx;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.fifth;
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D60));
    func_0220E9A0((char *)p,rec,&d_02211D88);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    if (((Flag *)(p+0x2175))->bit==0) {
        idx=(*(u8 **)p)[0x4b]+0x22;
        func_0220E7CC(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D58);
    } else {
        idx=(*(u8 **)p)[0x4b]+0x1d;
        func_0220E7CC(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D58);
    }
    func_0220E7CC(((Flag *)(p+0x2175))->high==0?((u8 **)p)[0x7d6]:((u8 **)p)[0x7d7],(u32)&d_02211D48);
    func_0220E8B4((char *)p,0x27,0x16,*(rec+(*(u8 **)p)[0x4b]*8+0x31));
}

/*
 * lever: the copied Pair is a field of a struct-typed table (twin 0220EC2C's
 * Table1 shape, extended to offset 0x1c), not an indexed Pair array; the
 * array form hoists the 0x1ed8 resource load above the second strh.
 */
void func_0220EE44(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.fourth;
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D4C));
    func_0220E9A0((char *)p,rec,(Pair *)&d_02211D80);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    func_0220F060(p);
}
