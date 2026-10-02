/*
 * function: func_021D6A38
 * address: 0x021D6A38
 * packet: pkt_ov131_021D6A38
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: block-local Vec zero initializers materialize addresses before
 *   stores; explicit visibility if/else calls retain original branch shape;
 *   mask update before i++ retains the original loop scheduling.
 * output: 49F34/49DB4 call 4A1BC, whose returned allocation is nonzero:
 *   30734 null failure calls 88234 -> 882C0 -> 882C8 halt loop (882CC
 *   branches back). Both 62A98 and 62A4C assign *out on every returning
 *   path, including absent block. No output default or success assumption.
 * interface: 785C receives the visibly loaded third mon word even though
 *   its own body ignores it. 4ADEC's fourth legacy parameter is overwritten
 *   before use, original sets only r0-r2; 276C4 reads only r0 and replaces
 *   r1-r3 before each call, so unused legacy trailing inputs are omitted.
 * arithmetic: local u8 i=0..5 and mask truncates modulo256; all vectors
 *   assigned from three-word ROM templates or all three explicit zeros.
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D785C 0x021D785C thumb ov131
 *   func_021D7A1C 0x021D7A1C thumb ov131
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049F34 0x02049F34 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_021DC204 0x021DC204 data a4
 *   d_021DC21C 0x021DC21C data a4
 *   d_021DC1B0 0x021DC1B0 data a4
 *   d_021DC1A4 0x021DC1A4 data a4
 *   d_021DC18C 0x021DC18C data a4
 *   d_021DC1BC 0x021DC1BC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec;
extern const Vec d_021DC204,d_021DC21C,d_021DC1B0,d_021DC1A4,d_021DC18C,d_021DC1BC;
extern void *func_021D6064(u8 *);
extern void *func_021D60A4(void *);
extern void func_021D785C(void *,void *,void *);
extern void func_021D7A1C(void *,void *,Vec *);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_02041B6C(u32);
extern u32 func_02017E88(void *,u32,u32);
extern u32 func_020275E4(void);
extern int func_02027720(int);
extern int func_0202772C(int);
extern void *func_02049F34(u32,u32,u32,u32);
extern void *func_02049DB4(u32,u32,u32,u32,u16);
extern void func_0204ADEC(u32,void *,u32);
extern void func_0204A9D0(int,void *);
extern void func_020307B0(void *);
extern void func_0204B3DC(void *,u32);
extern void func_0204B878(void *,u16);
extern u32 func_0201B28C(void *);
extern u32 func_02017EB4(void *);
extern u32 func_02017F90(void *);
extern int func_020276C4(void *);
extern u32 func_0201B268(void *);
extern void func_02015C78(void *,u32 *);
extern void func_02015D30(void *,u32 *);
extern void func_02048AFC(void *,const Vec *);
extern void func_02048AD0(void *);
void func_021D6A38(u8 *p,u8 *q)
{
    void *pal,*chr;
    void *mon,*other,*window,*loaded;
    u32 form,archive,status;
    u8 i,mask;
    mon=func_021D6064(p);
    other=func_021D60A4(p);
    func_021D785C(p,q,mon);
    window=*(void **)(q+0x18);
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    window=*(void **)(q+0x1c);
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    form=func_02017E88(mon,0x98,0);
    archive=func_020275E4();
    loaded=func_02049F34(archive,func_02027720(form),(u32)&pal,*(u16 *)p);
    func_0204ADEC(*(u32 *)(p+0x9c),pal,1);
    func_020307B0(loaded);
    archive=func_020275E4();
    loaded=func_02049DB4(archive,func_0202772C(form),0,(u32)&chr,*(u16 *)p);
    func_0204A9D0(*(int *)(p+0xd0),chr);
    func_020307B0(loaded);
    func_0204B3DC(*(void **)(q+0x20),1);
    status=func_02017E88(mon,11,0);
    for(i=0,mask=1;i<6;mask=(u8)(mask<<1),i++) {
        if(status & mask) func_0204B878(*(void **)(q+0x24+i*4),i*2+1);
        else func_0204B878(*(void **)(q+0x24+i*4),i*2);
    }
    if(func_0201B28C(mon)==1) func_0204B3DC(*(void **)(q+0x40),1);
    else func_0204B3DC(*(void **)(q+0x40),0);
    if(func_02017EB4(mon)==1 && *(u32 *)(p+0x38)==0)
        func_0204B3DC(*(void **)(q+0x3c),1);
    else func_0204B3DC(*(void **)(q+0x3c),0);
    if(*(u32 *)(q+0xc)==1) {
        Vec a=d_021DC204;
        Vec b=d_021DC21C;
        Vec c={0,0,0};
        Vec d=d_021DC1B0;
        func_02015C78(*(void **)q,&c.x);
        func_021D7A1C(p,q,&d);
        func_02015D30(*(void **)q,&b.x);
        func_02048AFC(*(void **)(p+0x70),&a);
        func_02048AD0(*(void **)(p+0x70));
        *(u32 *)(q+8)=0;
    } else {
        Vec e=d_021DC1A4;
        Vec f=d_021DC18C;
        Vec g={0,0,0};
        Vec h=d_021DC1BC;
        func_02015C78(*(void **)q,&g.x);
        func_021D7A1C(p,q,&h);
        func_02015D30(*(void **)(q+4),&f.x);
        func_02048AFC(*(void **)(p+0x70),&e);
        func_02048AD0(*(void **)(p+0x70));
        *(u32 *)(q+8)=2;
    }
    if((u8)func_02017F90(other)!=0) {
        func_0204B878(*(void **)(q+0x48),func_020276C4(other));
        func_0204B3DC(*(void **)(q+0x48),1);
        func_0204B3DC(*(void **)(q+0x44),0);
    } else {
        func_0204B3DC(*(void **)(q+0x48),0);
        if(func_0201B268(mon)==1) func_0204B3DC(*(void **)(q+0x44),1);
        else func_0204B3DC(*(void **)(q+0x44),0);
    }
    {
    Vec zero={0,0,0};
    func_02015C78(*(void **)q,&zero.x);
    func_02015C78(*(void **)(q+4),&zero.x);
    q[0x78]=0;q[0x79]=0;q[0x80]=0;q[0x81]=0;
    *(u32 *)(q+0x6c)=0;*(u32 *)(q+0x5c)=0;
    q[0x88]=0;q[0x89]=0;
    }
}
