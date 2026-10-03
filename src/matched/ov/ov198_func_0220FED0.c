/*
 * function: func_0220FED0
 * address: 0x0220FED0
 * packet: pkt_ov198_0220FED0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original narrows state to u8 before 0220B760; extern preserves caller truncation despite owner u32 state.
 * symbols:
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02211970 0x02211970 thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int func_02025DE8(struct Sound *);
extern void func_02211970(u8 **,u32);
extern void func_0220B760(u8 *,u8);
extern int func_02210F1C(u8 *);
extern u32 func_02021ED8(const char *);
int func_0220FED0(u8 *p)
{
    u32 sel;
    u8 value;
    if(func_02021ED8(*(const char **)(p+0x1D8))!=0)return 25;
    sel=func_02025DE8(*(struct Sound **)(p+0x2184));
    switch(sel){
    case 0: case 1: case 2: case 3: case 4:
        value=sel;
        (*(u8 **)p)[0x4B]=value;
        p[0x2191]=value;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,sel+22);
        *(u32 *)(p+0x217C)=17;
        return 29;
    case 5:
        func_02211970((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        func_0220B760(p,6);
        return 31;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        func_0220B760(p,6);
        return 31;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 25;
}
