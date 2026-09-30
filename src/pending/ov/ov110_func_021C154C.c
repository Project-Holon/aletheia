/*
 * function: func_021C154C
 * address: 0x021C154C
 * packet: pkt_ov110_021C154C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * Blocked on ARM9 leaves 0x02024910 and 0x02024108, no outside witnesses.
 * blocker: 0x02024910 Thumb, EXACT (block24910.log)
 *   typedef unsigned char u8;
 *   void *func_02024910(u8 *p,int i) { return p+8+i*8; }
 * blocker: 0x02024108 Thumb, EXACT (block24108.log)
 *   typedef unsigned char u8; typedef unsigned short u16;
 *   void func_02024108(u8 *p,const u16 *s) {
 *     *(u16 *)(p+16)=s[0]; *(u16 *)(p+18)=s[1];
 *     *(u16 *)(p+20)=s[2]; *(u16 *)(p+22)=s[3];
 *   }
 * symbols:
 *   func_02024044 0x02024044 thumb
 *   func_02024910 0x02024910 thumb
 *   func_02024108 0x02024108 thumb
 *   func_02031348 0x02031348 arm
 *   d_021C39B8 0x021C39B8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02024044(unsigned, unsigned, void *, unsigned, void *, unsigned);
extern void *func_02024910(void *, u8);
extern void func_02024108(void *, const void *);
extern void func_02031348(void *, int, void *, void *);
extern const unsigned d_021C39B8[];
int func_021C154C(int *state, u8 *p) {
    void *q;
    switch (*state) {
    case 0: ++*state; break;
    case 1:
        q=func_02024044(2,0,0,1,*(void **)(p+0x1c),*(u16 *)(p+4));
        func_02024108(q,func_02024910(*(void **)(p+0x20),p[0x95]));
        func_02031348(*(void **)(p+0xac),-1,(void *)d_021C39B8,q);
        *(void **)(p+0x90)=q;
        return 1;
    }
    return 0;
}
