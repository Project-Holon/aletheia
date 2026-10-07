/*
 * file:     unit_0220BC70_p09.c
 * unit:     yes
 * function: func_0220EAF0, func_0220EBCC
 * address:  0x0220EAF0
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
 *   func_0220EA30 0x0220EA30 thumb ov198
 *   d_02211DB4 0x02211DB4 data a2
 *   d_02211DCC 0x02211DCC data a2
 *   d_02211DE4 0x02211DE4 data a2
 *   d_02211D34 0x02211D34 data a2
 */
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {short x,y;} Pair;

typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;

typedef struct {u8 bytes[76];} Record;

typedef unsigned int   u32;

extern int func_022110D4(u8 *,int);
extern void func_0220E7CC(u8 *,unsigned);
extern void func_0220E974(int mode, u8 *p, const struct Vec2 *q);
extern void func_0220EA30(u32 mode, u8 *p, const struct Vec2 *q);
void func_0220EAF0(Record *records);
void func_0220EBCC(Record *records);
extern const Pair d_02211DB4[],d_02211DCC[],d_02211DE4[];
extern const Pair d_02211D34;

/*
 * lever: the final pointer-table subscript preserves the unscaled index
 * spill and its fresh shift. Byte-offset pointer arithmetic CSEs that shift.
 */
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
            func_0220E974(((Bits *)(p+0x1b))[offset].kind,*(u8 **)(p+index*4+0x1ef0),(const struct Vec2 *)(&d_02211DCC[i]));
            if(((Bits *)(p+0x1b))[offset].high==0)
                func_0220E7CC(*(u8 **)(p+index*4+0x1f08),(unsigned)&d_02211DE4[i]);
            pair=d_02211DB4[i];
            pair.x+=8;
            pair.y+=8;
            func_0220EA30(*(u16 *)((char *)records+offset+0x1e),((u8 **)(p+0x1ebc))[index],(const struct Vec2 *)(&pair));
        }
    }
}

/*
 * lever: a char cast only on the later resource access prevents CSE of
 * the base-plus-index sum, preserving the byte-offset spill across E7CC.
 */
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
