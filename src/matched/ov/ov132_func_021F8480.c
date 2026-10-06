/*
 * function: func_021F8480
 * address: 0x021F8480
 * packet: pkt_ov132_021F8480
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ABS32 callback func_021F8994 (ov132) at +0x1B8 has no code
 * witness. Original 0x021F8994..0x021F899C is 00 4B 18 47 48 A6 04 02:
 * Thumb ldr r3,[pc,#0]; bx r3; ARM target 0x0204A648. Its matched ARM9
 * source proves void(void); no ARM9 C was compiled or embedded here.
 * This stub is inside handed lead 0x021F879C's extent and must be filed
 * in that lead's unit, never as a duplicate standalone file. Root denied
 * a standalone extension. The lead was returned after fresh CFG review.
 * budget: two one runs, shrinking 8 concrete bytes to zero; no capped
 * iteration, mandatory DIFF checks, sweeps or permuter consumed.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F8994 0x021F8994 thumb ov132
 *   func_021FD8D4 0x021FD8D4 thumb ov132
 *   func_021F95F0 0x021F95F0 thumb ov132
 *   func_020490F4 0x020490F4 arm
 *   func_021F899C 0x021F899C thumb ov132
 *   func_021F8BD4 0x021F8BD4 thumb ov132
 *   func_021F92CC 0x021F92CC thumb ov132
 *   func_021F8DC4 0x021F8DC4 thumb ov132
 *   func_021F8E58 0x021F8E58 thumb ov132
 *   func_021F8E88 0x021F8E88 thumb ov132
 *   func_021F6BD8 0x021F6BD8 thumb ov112
 *   func_021F9FEC 0x021F9FEC thumb ov132
 *   func_021FA5B0 0x021FA5B0 thumb ov132
 *   func_021FAAF4 0x021FAAF4 thumb ov132
 *   func_021F9CF4 0x021F9CF4 thumb ov132
 *   func_0203D34C 0x0203D34C arm
 *   func_021F8D88 0x021F8D88 thumb ov132
 *   d_021FDCA0 0x021FDCA0 data a1
 *   g_02FFFC3C 0x02FFFC3C data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern const char d_021FDCA0[];
extern u32 g_02FFFC3C;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void (*)(void),void *,u32);
extern void func_021F8994(void);
extern u32 func_021FD8D4(char *p);
extern void func_021F95F0(u8 *);
extern void *func_020490F4(u32 id, u16 heap);
extern void func_021F899C(u8 *);
extern void func_021F8BD4(u8 *);
extern void func_021F92CC(u8 *);
extern void func_021F8DC4(u8 *);
extern void func_021F8E58(char *p);
extern void func_021F8E88(char *p);
extern void *func_021F6BD8(u16,void *);
extern char *func_021F9FEC(u32,void *,u32);
extern char *func_021FA5B0(u32,void *,char *);
extern void *func_021FAAF4(u32,void *);
extern void func_021F9CF4(char *);
extern void func_0203D34C(u32,u32);
extern void func_021F8D88(u8 *,u32);
u8 *func_021F8480(u8 *input, int heap)
{
    u8 *p;
    u8 i;
    p=func_02030734(heap,0x1f0,1,d_021FDCA0,0x11a);
    *(u16 *)p=heap;
    *(void **)(p+0x30)=input;
    i=0;
    *(u16 *)(p+2)=0;
    *(u16 *)(p+4)=127;
    *(u16 *)(p+6)=128;
    *(u16 *)(p+8)=0;
    *(u32 *)(p+0xb4)=0;
    *(u32 *)(p+0x1c)=0;
    *(u32 *)(p+0x164)=0;
    *(u32 *)(p+0xc)=1;
    *(u32 *)(p+0x14)=0;
    *(u32 *)(p+0x10)=0;
    *(u32 *)(p+0x24)=0;
    *(u32 *)(p+0x28)=0;
    *(u32 *)(p+0x2c)=0;
    *(void **)(p+0x20)=func_020056A0(func_021F8994,p,64);
    if(**(u32 **)(p+0x30)==0){
        for(;i<4;i++){
            if(**(u32 **)(*(u8 **)(p+0x30)+4+i*4)==0){p[0xa]=i;break;}
        }
        if(i==4)p[0xa]=1;
    }else p[0xa]=func_021FD8D4((void *)**(u32 **)(p+0x30));
    for(i=0;i<4;i++)p[0xf7+i]=0;
    func_021F95F0(p);
    *(u32 *)(p+0xec)=1;
    p[0xf0]=4;
    p[0xf1]=4;
    p[0xf2]=4;
    p[0x11c]=4;
    *(u16 *)(p+0x11e)=0;
    *(u32 *)(p+0x15c)=0;
    *(u16 *)(p+0x168)=0;
    for(i=0;i<4;i++){
        *(u32 *)(p+0xfc+i*4)=0;
        *(u16 *)(p+0x124+i*2)=0;
        *(u32 *)(p+0x13c+i*8)=0;
        *(u32 *)(p+0x140+i*8)=0;
    }
    *(void **)(p+0x18)=func_020490F4(47,*(u16 *)p);
    func_021F899C(p);
    func_021F8BD4(p);
    func_021F92CC(p);
    func_021F8DC4(p);
    func_021F8E58((char *)p);
    func_021F8E88((char *)p);
    *(void **)(p+0x90)=func_021F6BD8(*(u16 *)p,p);
    *(void **)(p+0xb8)=func_021F9FEC(*(u16 *)p,p,*(u32 *)(p+0x30));
    *(void **)(p+0xa4)=func_021FA5B0(*(u16 *)p,p,*(char **)(*(u8 **)(p+0x30)+p[0xa]*4+4));
    *(void **)(p+0xb0)=func_021FAAF4(*(u16 *)p,p);
    func_021F9CF4((char *)p);
    func_0203D34C(0,*(u16 *)p);
    func_021F8D88(p,0);
    *(u32 *)(p+0x1dc)=*(u32 *)((*(u8 ***)(p+0x30))[6]+0x14);
    *(u32 *)(p+0x1e0)=*(u32 *)((*(u8 ***)(p+0x30))[6]+0x18);
    *(u32 *)(p+0x1e4)=*(u32 *)((*(u8 ***)(p+0x30))[6]+0x1c);
    *(u32 *)(p+0x1ec)=g_02FFFC3C;
    return p;
}
