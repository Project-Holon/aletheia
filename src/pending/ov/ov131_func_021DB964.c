/*
 * function: func_021DB964
 * address: 0x021DB964
 * packet: pkt_ov131_021DB964
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: ARM9 func_020275EC lacks an outside witness; Ilias owns filing.
 *   Verified C copied from ov119_func_021E0DBC.c, blocker-r3.log EXACT:
 *   extern const unsigned char d_0209FCF8[];
 *   unsigned func_020275EC(unsigned a) { return d_0209FCF8[a]; }
 *   symbols: d_0209FCF8 0x0209FCF8 data a1
 * extent: two-byte zero alignment padding at 0x021DB9E6.
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0201C1C8 0x0201C1C8 thumb
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DBCF4 0x021DBCF4 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021D6064(u8 *);
extern unsigned func_02017E88(void *,unsigned,unsigned);
extern int func_0201C1C8(u16);
extern void func_0204AB84(void *,void *);
extern void func_0204B784(void *,void *);
extern int func_020275EC(int);
extern void func_0204B6F4(void *,int,int);
extern void func_0204B3DC(void *,int);
extern void func_021DBCF4(void *);
void func_021DB964(u8 *a,void *b,u8 *p) {
    unsigned v;
    int i;
    unsigned words[9];
    void *q;
    q=func_021D6064(a);
    if(p[0]<4) v=func_02017E88(q,p[0]+54,0);
    else v=*(u16 *)(*(u8 **)(a+8)+20);
    if(*(int *)(p+4)==1) {
        if(v!=0) {
            i=func_0201C1C8(v);
            func_0204AB84(*(void **)(a+304+i*4),words);
            func_0204B784(*(void **)(p+12),words);
            func_0204B6F4(*(void **)(p+12),func_020275EC(i),1);
            func_0204B3DC(*(void **)(p+12),1);
        } else func_0204B3DC(*(void **)(p+12),0);
        func_021DBCF4(*(void **)(p+20));
        func_0204B3DC(*(void **)(p+8),1);
        *(int *)(p+4)=0;
    }
}
