/*
 * function: func_021DBCF4
 * address: 0x021DBCF4
 * packet: pkt_ov131_021DBCF4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note (2026-10-02): only residue is edge/seg stack slot swap (orig edge=[sp,#8], seg=[sp,#0xc]).
 *   Declaration-order permutations, seg block-local, if/else vs ternary, int/u32 types are all inert.
 * symbols:
 *   func_020437D4 0x020437D4 arm
 *   func_020437EC 0x020437EC arm
 *   func_020862F0 0x020862F0 arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_0204ABBC 0x0204ABBC arm
 *   func_0207E780 0x0207E780 arm
 *   func_0207E804 0x0207E804 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020437D4(void *);
extern int func_020437EC(void *);
extern void func_020862F0(void *,int);
extern int func_020437DC(void *);
extern int func_020437E4(void *);
extern u8 *func_0204ABBC(void *,u32);
extern void func_0207E780(void *,void *,u32);
extern void func_0207E804(void *,void *,u32);
void func_021DBCF4(u8 *p)
{
    u8 *dst0;
    int c,r;
    u32 off,edge,seg;
    int rem;
    u32 wt;
    u8 *src;
    u8 k;
    void (*fn)(void *,void *,u32);
    dst0=func_020437D4(*(void **)p);
    func_020862F0(dst0,func_020437EC(*(void **)p));
    if(*(u32 *)(p+0x10)==0) fn=func_0207E780; else fn=func_0207E804;
    wt=(u32)func_020437DC(*(void **)p)>>3;
    rem=(u32)func_020437E4(*(void **)p)>>3;
    rem=rem%4;
    edge=func_020437DC(*(void **)p)%64/8*32;
    if(edge==0) edge=256;
    off=0;
    for(r=0;r<p[0x23];r++) {
        for(c=0;c<p[0x22];c++) {
            seg=(c==p[0x22]-1)?edge:256;
            src=func_0204ABBC(*(void **)(p+0x14+(c+r*p[0x22])*4),*(u32 *)(p+0x10));
            for(k=0;k<4;k++) {
                if(r==p[0x23]-1 && rem!=0 && k>=rem) continue;
                fn(dst0+(off+k*(wt*32)),src,seg);
                src+=256;
            }
            off+=seg;
        }
        off+=wt*32;
    }
}
