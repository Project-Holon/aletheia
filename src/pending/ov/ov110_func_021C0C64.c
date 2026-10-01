/*
 * function: func_021C0C64
 * address: 0x021C0C64
 * packet: pkt_ov110_021C0C64
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 Thumb 0x02024910 lacks an outside witness. Full 8-byte
 *   primary body reads r0/r1, no memory; fixed-flag scratch EXACT8,
 *   blocker-24910-two.log terminal0, no ARM9 source/shard filed.
 *   void *func_02024910(char *p,unsigned i) { return p+8+i*8; }
 * Caller explicitly narrows the outgoing index to u8. Own ARM9 units and
 *   complete overlay callee bodies fix arity; observed caller truncations
 *   fix the u8 index externs. Both bounded row loops retain indices0..3.
 * A named u8 which before the comparison/call removes duplicate narrowing
 *   (DIFF84/212 -> MATCH208); no volatile or uninitialized local.
 * Caller-only tu --suggest-split: MATCH208, no viable partition.
 * symbols:
 *   func_0202DC98 0x0202DC98 thumb
 *   func_02041570 0x02041570 arm
 *   func_02024910 0x02024910 thumb
 *   func_0202452C 0x0202452C thumb
 *   func_021C09E8 0x021C09E8 thumb ov110
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   func_0202DC9C 0x0202DC9C thumb
 *   func_021C124C 0x021C124C thumb ov110
 *   func_021C11B8 0x021C11B8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0202DC98(void *);
extern void func_02041570(int,u16);
extern void *func_02024910(void *,u8);
extern u16 func_0202452C(const u16 *);
extern void func_021C09E8(u8 *,int);
extern u32 sub_0202DCC4(const void *,u8);
extern void func_0202DC9C(void *,u8,u32);
extern void func_021C124C(u8 *,u8,u8,int);
extern void func_021C11B8(u8 *,u8,int,int);
void func_021C0C64(u8 *p,int flag)
{
    int i;
    if(flag && !func_0202DC98(*(void **)(p+0x8c))) return;
    func_02041570(2,0);
    if(p[0x96]) {
        func_021C09E8(p+0x24,func_0202452C(func_02024910(*(void **)(p+0x20),p[0x96]-1)));
    }
    for(i=0;i<4;i++) {
        if(sub_0202DCC4(*(void **)(p+0x8c),i)) func_0202DC9C(*(void **)(p+0x8c),i,0);
    }
    for(i=0;p[0x96]+i<p[0x97] && i<4;i++) {
        u8 which;
        which=p[0x96]+i;
        func_021C124C(p,i,which,which==p[0x95]);
    }
    if(p[0x97]<20 && i<4) {
        u8 which;
        which=p[0x96]+i;
        func_021C11B8(p,i,0,which==p[0x95]);
    }
}
