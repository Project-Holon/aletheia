/*
 * function: func_022100BC
 * address: 0x022100BC
 * packet: pkt_ov198_022100BC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bounded permuter expanded row use, cast the row/column sum to u32,
 *   and captured the byte selection in tmp before calling func_022110D4.
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02211970 0x02211970 thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 * Caller truncates the selection+18 argument to u8 before func_0220B760.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int func_02025DE8(struct Sound *);
extern int func_022110D4(u8 *,int);
extern void func_02211970(u8 **,u32);
extern void func_0220B760(u8 *,u8);
int func_022100BC(u8 *p)
{
    u32 selection=func_02025DE8(*(struct Sound **)(p+0x2184));
    u8 tmp;
    switch(selection) {
    case 0: case 1: case 2: case 3: {
        unsigned idx;
        u8 *row;
        tmp=(*(u8 **)p)[0x20];
        idx=func_022110D4(p,tmp);
        row=(u8 *)((u32)p+idx*0x4c);
        if(*(u16 *)((u32)((u32)((u8 *)((u32)p+idx*0x4c))+selection*8)+0x30)==0) break;
        (*(u8 **)p)[0x4b]=selection;
        (*(u8 **)p)[0x48]=idx;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,(u8)(selection+18));
        return 31;
    }
    case 4:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        *(int *)(p+0x217c)=11;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        *(int *)(p+0x217c)=11;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5:
    case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 28;
}
