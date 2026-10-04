/*
 * function: func_021F0284
 * address: 0x021F0284
 * packet: pkt_ov034_021F0284
 * region: ov034
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: inline print_record binds owner before the bitmap getter; named one
 * remains live across the repeated blocks and pins their distinct spill slots.
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012944 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_0201F158 0x0201F158 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200D0AC 0x0200D0AC thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_020071F0 0x020071F0 thumb
 *   func_020071EC 0x020071EC thumb
 *   func_02008748 0x02008748 thumb
 *   func_020086C8 0x020086C8 thumb
 *   func_020086D0 0x020086D0 thumb
 *   func_020086D8 0x020086D8 thumb
 *   func_020086E0 0x020086E0 thumb
 *   func_020086E8 0x020086E8 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02088864 0x02088864 arm
 *   func_0208890C 0x0208890C arm
 *   func_02045334 0x02045334 arm
 *   func_02045C04 0x02045C04 arm
 *   d_021F0A70 0x021F0A70 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201C440(void *p);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(void *,u8);
extern void *func_0201D7EC(int,int,int,int,u32);
extern void *func_02045B38(u32,u32,u32,u32);
extern void *func_0201EC64(u32);
extern void *func_020457B0(u32,u32);
extern void *func_020120F4(const void *);
extern void *func_02012EBC(void *);
extern void *func_02045EC0(void *,u32);
extern void *func_02012944(void *);
extern void func_0201F02C(void *,u32,void *);
extern void func_0201F250(void *,void *,void *);
extern void func_0201C724(u32,void *,u32,u32,void *,void *,u16);
extern void func_02045808(void *);
extern int func_02088864(void *);
extern int func_0208890C(void *);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void *func_020120F8(const void *);
extern u16 func_02012AC8(void *);
extern u32 func_02013E4C(u32);
extern void func_0201F158(void *,u32,u32);
extern void *func_02012F08(void *);
extern u32 func_0200C258(void *);
extern u32 func_0201296C(const void *);
extern u32 func_020142E8(void *,int);
extern void *func_0200CA1C(void *);
extern u16 func_0200D0AC(void *,u32);
extern u32 func_02012FCC(u32);
extern u16 func_0200864C(const void *);
extern u8 func_02008650(const void *);
extern int func_020071F0(void *);
struct Sub020071E4Ctrl;
extern u8 func_020071EC(const struct Sub020071E4Ctrl *);
extern void *func_02008748(void *);
extern u32 func_020086C8(const void *);
extern u32 func_020086D0(const void *);
extern u32 func_020086D8(const void *);
extern u32 func_020086E0(const void *);
extern u32 func_020086E8(const void *);
extern void func_02045334(struct Descriptor *d);
extern void func_0201ED04(void *);
extern void func_02045C04(void *);
extern const u8 d_021F0A70[];
static inline void print_record(u8 *p,u32 index,void *dst,void *s,u32 y,u16 color,u32 one)
{
    u32 owner=*(u32 *)(p+8);
    func_0201C724(owner,func_02045770((struct Descriptor *)*(u32 *)(p+12+index*8)),0,y,dst,*(void **)(p+0x4C),color);
    p[16+index*8]=one;
    func_02045808(s);
}
void func_021F0284(u8 *p)
{
    u32 i,one=1;
    void *bank,*ws,*dst,*ctx,*ctrl,*s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7,*time,*t;
    u32 date[4],clock[3];
    *(u32 *)(p+8)=func_0201C440((void *)(*(u16 *)(p+0x12C)));
    for(i=0;i<8;i++) {
        const u8 *r=d_021F0A70+i*6;
        u8 *entry=p+i*8;
        *(u32 *)(entry+12)=func_020450F0(r[0],r[1],r[2],r[3],r[4],r[5],one);
        func_02043B5C(func_02045770((struct Descriptor *)*(u32 *)(entry+12)),0);
    }
    *(void **)(p+0x4C)=func_0201D7EC(23,0,0,0,*(u16 *)(p+0x12C));
    bank=func_02045B38(0,2,168,*(u16 *)(p+0x12C));
    ws=func_0201EC64(*(u16 *)(p+0x12C));
    dst=func_020457B0(256,*(u16 *)(p+0x12C));
    ctx=func_020120F4(*(void **)p);
    ctrl=func_02012EBC(ctx);
    s0=func_02045EC0(bank,0);
    func_0201F02C(ws,0,func_02012944(ctx));
    func_0201F250(ws,dst,s0);
    print_record(p,0,dst,s0,4,0x3580,one);
    s1=func_02045EC0(bank,1);
    func_02088864(date);
    func_0201EFA4(ws,0,date[0],2,2,one);
    func_0201EFA4(ws,one,date[1],2,0,one);
    func_0201EFA4(ws,2,date[2],2,0,one);
    func_0201F250(ws,dst,s1);
    print_record(p,1,dst,s1,0,0x3DC0,one);
    s2=func_02045EC0(bank,2);
    func_0208890C(clock);
    func_0201EFA4(ws,0,clock[0],2,0,one);
    func_0201EFA4(ws,one,clock[1],2,2,one);
    func_0201F250(ws,dst,s2);
    print_record(p,2,dst,s2,0,0x3DC0,one);
    s3=func_02045EC0(bank,3);
    func_0201F158(ws,0,func_02013E4C(func_02012AC8(func_020120F8(*(void **)p))));
    func_0201F250(ws,dst,s3);
    print_record(p,3,dst,s3,0,0x3DC0,one);
    s4=func_02045EC0(bank,4);
    func_0201EFA4(ws,0,func_0200C258(func_02012F08(ctx)),2,0,1);
    func_0201F250(ws,dst,s4);
    print_record(p,4,dst,s4,0,0x3DC0,one);
    if(func_020142E8((void *)func_0201296C(func_020120F4(*(void **)p)),0x962)==1) {
        s5=func_02045EC0(bank,5);
        func_0201EFA4(ws,0,func_0200D0AC(func_0200CA1C(ctx),*(u16 *)(p+0x12C)),3,0,1);
        func_0201F250(ws,dst,s5);
        print_record(p,5,dst,s5,0,0x3DC0,one);
    }
    s6=func_02045EC0(bank,6);
    time=(void *)func_02012FCC((u32)ctx);
    func_0201EFA4(ws,0,func_0200864C(time),3,0,1);
    func_0201EFA4(ws,1,func_02008650(time),2,2,1);
    func_0201F250(ws,dst,s6);
    print_record(p,6,dst,s6,0,0x3DC0,one);
    if(func_020071F0(ctrl)==0 && func_020071EC(ctrl)==1) {
        t=func_02008748(ctrl);
        s7=func_02045EC0(bank,7);
        func_0201EFA4(ws,0,func_020086C8(t),2,2,1);
        func_0201EFA4(ws,1,func_020086D0(t),2,0,1);
        func_0201EFA4(ws,2,func_020086D8(t),2,0,1);
        func_0201EFA4(ws,3,func_020086E0(t),2,0,1);
        func_0201EFA4(ws,4,func_020086E8(t),2,2,1);
        func_0201F250(ws,dst,s7);
        print_record(p,7,dst,s7,4,0x3580,one);
    } else func_02045334((struct Descriptor *)*(u32 *)(p+68));
    func_02045808(dst);
    func_0201ED04(ws);
    func_02045C04(bank);
}
