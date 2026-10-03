/*
 * unit: yes
 * function: func_021DAFCC, func_021DB008
 * address: 0x021DAFCC
 * packet: pkt_ov121_021DAFCC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: unit includes tail-call follower func_021DB008 (function-start seed).
 * symbols:
 *   func_021DA2C8 0x021DA2C8 thumb ov121
 *   func_021D9B34 0x021D9B34 thumb ov121
 *   func_021DD9CC 0x021DD9CC thumb ov121
 *   func_021DA8AC 0x021DA8AC thumb ov121
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021DA2C8(u8 *p);
extern int func_021D9B34(u8 *p);
extern void func_021DD9CC(void *);
extern int func_021DA8AC(u32 *p);
static inline void update(void *p)
{
    if(p) func_021DD9CC(p);
}
void func_021DAFCC(char *p)
{
    int i;
    func_021DA2C8(*(void **)(p+0xab8));
    if(*(void **)(p+0xab4)) func_021D9B34(*(void **)(p+0xab4));
    for(i=0;i<12;i++) {
        void *q=*(void **)(p+i*4+0xa7c);
        if(q) update(q);
    }
}
int func_021DB008(char *p)
{
    return func_021DA8AC(*(void **)(p+0xac4));
}
