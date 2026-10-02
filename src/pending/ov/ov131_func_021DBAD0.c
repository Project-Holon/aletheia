/*
 * function: func_021DBAD0
 * address: 0x021DBAD0
 * packet: pkt_ov131_021DBAD0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note (2026-10-02): two scheduling residues remain, no content difference: (1) the original loads the 0204A6C8
 *   argument r3 (b[0x14]) right after the stack argument, before the constants (here it loads last); (2) the
 *   original orders adds r3,r5,r3 (a+mode*4) before ldr r2,[r4,#8] (b[8]); here ldr r2 comes first.
 *   Levers found: bm=*(void **)b as a local feeding the copy and the first size call (fixes the blk spill/reload),
 *   f8=b[8] as a local assigned just before d.kind. Inert: struct-typed a/b/blk, mp local for a+mode*4, f14 local.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021DBEA4 0x021DBEA4 thumb ov131
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021DC854 0x021DC854 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Desc {s16 x,y;u16 z;u8 kind,flag;};
extern void *func_02030734(u32,u32,u32,const char *,u32);
extern int func_020437DC(void *);
extern int func_020437E4(void *);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_021DBEA4(u8 *,int,void *);
extern void *func_0204A6C8(void *,u32,u32,u32,u16);
extern void *func_0204B294(u32,u32,u32,u32,void *,u32,u16);
extern void func_0204B6F4(void *,u8,u32);
extern void func_02049238(void *);
extern const char d_021DC854[];
u8 *func_021DBAD0(u8 *a,u8 *b)
{
    struct Desc d={0};
    u8 *blk;
    u8 cols,rows,i,j;
    void *heap;
    u8 *row;
    u8 *e;
    int mode;
    u32 f8;
    void *bm;
    blk=func_02030734(*(u16 *)(a+4),0x24,1,d_021DC854,0x8a);
    bm=*(void **)b;
    *(void **)blk=bm;
    cols=((u32)func_020437DC(bm)>>6)&0xff;
    rows=((u32)func_020437E4(*(void **)b)>>5)&0xff;
    if(func_020437DC(*(void **)b)%64!=0) cols=cols+1;
    if(func_020437E4(*(void **)b)%32!=0) rows=rows+1;
    blk[0x22]=cols;
    blk[0x23]=rows;
    *(u16 *)(blk+0x20)=*(u16 *)(b+0x12);
    *(u32 *)(blk+0x10)=*(u32 *)(b+0x14);
    heap=func_020490F4(0x4e,*(u16 *)(a+4));
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            row=blk+i*cols*4;
            mode=func_021DBEA4(a,*(u32 *)(b+0x14),heap);
            e=row+j*4;
            *(void **)(e+0x14)=func_0204A6C8(heap,7,0,*(u32 *)(b+0x14),*(u16 *)(a+4));
            d.x=*(s16 *)(b+4)+(j<<6);
            d.y=*(s16 *)(b+6)+(i<<5);
            f8=*(u32 *)(b+8);
            d.kind=b[0x10];
            d.flag=b[0x11];
            *(void **)(e+4)=func_0204B294(*(u32 *)a,*(u32 *)(e+0x14),f8,*(u32 *)(a+8+mode*4),&d,*(u16 *)(b+0x12),*(u16 *)(a+4));
            func_0204B6F4(*(void **)(blk+(u32)j*4+4),*(u32 *)(b+0xc),0);
        }
    }
    func_02049238(heap);
    return blk;
}
