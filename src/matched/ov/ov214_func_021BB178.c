/*
 * function: func_021BB178
 * address: 0x021BB178
 * packet: pkt_ov214_021BB178
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * volatile: MMIO accesses 021BB19E..021BB1B2
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BB2C8 0x021BB2C8 thumb ov214
 *   func_021BB36C 0x021BB36C thumb ov214
 *   func_021BB3DC 0x021BB3DC thumb ov214
 *   func_021BB2B4 0x021BB2B4 thumb ov214
 *   func_020056A0 0x020056A0 thumb
 *   site 0x021BB668 data ov214
 *   config 0x021BB588 data ov214
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern const char site[];
extern const u32 config[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,u32,u32);
extern void func_0204335C(u32);
extern void func_020433E0(const void *);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BB2C8(void *,u32);
extern void func_021BB36C(unsigned char *,int,int);
extern void func_021BB3DC(u32 **,u32);
extern void func_021BB2B4(void *);
extern u32 func_020056A0(void (*)(void *),void *,u32);
char *func_021BB178(u32 a,u32 heap)
{
    char *p=func_02030734(heap,16,0,site,458);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0(config);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BB2C8(p,heap);
    func_021BB36C((unsigned char *)p+4,(int)config,heap);
    func_021BB3DC((u32 **)(p+8),heap);
    *(u32 *)(p+12)=func_020056A0(func_021BB2B4,p,0);
    return p;
}
