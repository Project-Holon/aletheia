/*
 * function: func_021D7450
 * address: 0x021D7450
 * packet: pkt_ov116_021D7450
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: incoming r1 is forwarded as fourth6E50 argument; 81EC reads
 * incoming r0 left intact by the switch. Both inputs are named.
 * symbols:
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D6EC4 0x021D6EC4 thumb ov116
 *   func_021D6E50 0x021D6E50 thumb ov116
 *   func_021D7060 0x021D7060 thumb ov116
 *   func_021D70B0 0x021D70B0 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 *   func_021D81D0 0x021D81D0 thumb ov116
 *   func_021D81EC 0x021D81EC thumb ov116
 *   func_021D81B4 0x021D81B4 thumb ov116
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D8010(void *,u32);
extern int func_021D6EC4(u8 *,u8 *,int);
extern void func_021D6E50(u8 *,u8 *,int,int);
extern void func_021D7060(u8 *,u8 *);
extern int func_021D70B0(u8 *,u8 *);
extern int func_021D80CC(void *);
extern void func_0200DBA0(void *,int,int);
extern void func_021D81D0(u8 *);
extern int func_021D81EC(u8 *);
extern void func_021D81B4(void *);
int func_021D7450(u8 *p,int b)
{
    int v;
    switch (*(u32 *)(p+0xb6c)) {
    case 0: func_021D8010(p+4,7); ++*(u32 *)(p+0xb6c); break;
    case 1: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++*(u32 *)(p+0xb6c); break;
    case 2:
        v=func_021D6EC4(p+0x1610,p+0x182c,0);
        if(v==1) *(u32 *)(p+0xb6c)=5;
        else if(v==2) *(u32 *)(p+0xb6c)=3;
        break;
    case 3: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++*(u32 *)(p+0xb6c); break;
    case 4:
        if(func_021D6EC4(p+0x1610,p+0x182c,1)==1) *(u32 *)(p+0xb6c)=5;
        break;
    case 5: func_021D7060(p+0x1610,p+0x182c); ++*(u32 *)(p+0xb6c); break;
    case 6:
        if(func_021D70B0(p+0x1610,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++*(u32 *)(p+0xb6c);
        break;
    case 7: func_0200DBA0(*(void **)(p+0x1858),1,2); func_021D81D0(p); ++*(u32 *)(p+0xb6c); break;
    case 8:
        if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,8); ++*(u32 *)(p+0xb6c); }
        break;
    case 9: if(func_021D80CC(p+4)!=0) ++*(u32 *)(p+0xb6c); break;
    case 10: return 1;
    }
    return 0;
}
