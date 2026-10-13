/*
 * function: P_STA_RIBBON_CollectOwned
 * address: 0x021D911C
 * packet: pkt_ov131_021D911C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Initialize the count after the clear loop so its zero shares the
 *   clear-store value without a redundant live zero register.
 * proof: Loop indices are initialized u8 values bounded by 80 or 10.
 *   P_STA_RIBBON_GetRibbonInfo field 5 reads byte +12 of immutable P_STA_RIBBON_InfoTable;
 *   all 80 original records have selector 0..4 (B8/table-proof.log).
 *   count begins with five ROM bytes 1,1,1,1,1 and never exceeds 81.
 *   All scaling and count increments fit int; stores preserve u8 narrowing.
 * interface: P_STA_RIBBON_GetRowOwnedIndex forwards live r1 to P_STA_RIBBON_GetOwnedIndex, whose
 *   own matched body consumes target; caller sets r1 despite stale one-arg
 *   declaration in P_STA_RIBBON_GetRowOwnedIndex's source.
 * symbols:
 *   P_STA_RIBBON_KindCountInit 0x021DC2B0 data a1
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STA_RIBBON_GetRibbonInfo 0x021DBF2C thumb ov131
 *   P_STA_RIBBON_GetRowOwnedIndex 0x021D9428 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Counts { u8 value[5]; };
extern const struct Counts P_STA_RIBBON_KindCountInit;
extern void *P_STATUS_GetPokePara(u8 *);
extern u32 P_STA_RIBBON_GetRibbonInfo(u32,u32);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 P_STA_RIBBON_GetRowOwnedIndex(u8 *,u32);
void P_STA_RIBBON_CollectOwned(u8 *a,u8 *p)
{
    struct Counts counts = P_STA_RIBBON_KindCountInit;
    void *object;
    u8 i, n, selector;
    object=P_STATUS_GetPokePara(a);
    for(i=0;i<80;i++) *(u32 *)(p+0x138+i*8)=0;
    n=0;
    for(i=0;i<80;i++) {
        if(func_02017E88(object,P_STA_RIBBON_GetRibbonInfo(i,0),0)==1) {
            selector=P_STA_RIBBON_GetRibbonInfo(i,5);
            *(u32 *)(p+0x138+n*8)=1;
            p[0x13c+n*8]=i;
            p[0x13d+n*8]=selector;
            p[0x13e + n*8]=counts.value[selector];
            counts.value[selector]++;
            n++;
        }
    }
    p[0x10]=n;
    for(i=0;i<10;i++) *(u16 *)(p+0x70+i*20)=P_STA_RIBBON_GetRowOwnedIndex(p,i);
}
