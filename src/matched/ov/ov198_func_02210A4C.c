/*
 * function: func_02210A4C
 * address: 0x02210A4C
 * packet: pkt_ov198_02210A4C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02210B00 0x02210B00 thumb ov198
 *   func_02211970 0x02211970 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Sound;
extern int func_02025DE8(struct Sound *);
extern int func_02210B00(u8 *,u32);
extern void func_02211970(u8 **,u32);
int func_02210A4C(u8 *p)
{
    u32 sel=func_02025DE8(*(struct Sound **)(p+0x2184));
    switch(sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if(func_02210B00(p,sel)) {
            (*(u8 **)p)[32]=sel;
            return 1;
        }
        break;
    case 6:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-2:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 0;
}
