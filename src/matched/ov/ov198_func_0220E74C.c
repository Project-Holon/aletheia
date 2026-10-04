/*
 * function: func_0220E74C
 * address: 0x0220E74C
 * packet: pkt_ov198_0220E74C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0220AFC4 0x0220AFC4 thumb ov196
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
typedef unsigned char  u8;
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0220AFC4(u8 *p);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B1CC(struct Bank *bank);
void func_0220E74C(char *p)
{
    unsigned i;
    for(i=0;i<41;i++) func_0204B3B4(*(void **)(p+i*4+0x1ebc));
    func_0220AFC4(*(void **)(p+0x2188));
    for(i=0;i<26;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x24a4)));
    for(i=0;i<6;i++) func_0204ADA4((u32)(*(void **)(p+i*4+0x250c)));
    for(i=0;i<6;i++) func_0204AFD8((u32)(*(void **)(p+i*4+0x2524)));
    func_0204B1CC(*(void **)(p+0x1eb8));
}
