/*
 * function: func_021FC3BC
 * address: 0x021FC3BC
 * packet: pkt_ov186_021FC3BC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: the mode switch has no default arm: the original 021FC3E8 branches
 *       to 021FC3F0 with r6 (config) never set for modes other than 0/1,
 *       which is what a default-less switch over an unset local compiles to
 *       (docs/idioms/switch-arms-tail-merge.md). A `default: config = 0`
 *       arm adds a `movs r4, #0` and shifts every register.
 * volatile: hardware DISPCNT read-modify-write at 021FC3FC..021FC40A; BLDCNT stores at 021FC3F4/021FC3FA.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021FC4FC 0x021FC4FC thumb ov186
 *   func_021FC5A0 0x021FC5A0 thumb ov186
 *   func_021FC4E8 0x021FC4E8 thumb ov186
 *   func_020056A0 0x020056A0 thumb
 *   d_02200D4C 0x02200D4C data a1
 *   d_0220093C 0x0220093C data a4
 *   d_0220096C 0x0220096C data a4
 */
extern const char d_02200D4C[];
struct DispVram;
extern const struct DispVram d_0220093C,d_0220096C;
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void),BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void),func_0201DD60(void);
extern void func_021FC4FC(void *,unsigned);
extern void func_021FC5A0(int *,int,int);
extern void func_021FC4E8(int,char *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
void *func_021FC3BC(unsigned mode,int setting,unsigned heap)
{
    const struct DispVram *config;
    char *p;
    p=func_02030734(heap,16,0,d_02200D4C,0x1d5);
    func_02082BCC(p,0,16);
    switch(mode){case 0:config=&d_0220093C;break;case 1:config=&d_0220096C;break;}
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    *(volatile unsigned *)0x04001000&=~0xe000;
    BG_SYS_ClearGraphicsMemory(0);func_020433E0(config);func_0204363C(setting);
    func_0204361C();BG_SYS_ClearMainPlanes();BG_SYS_ClearSubPlanes();func_0201DD60();
    func_021FC4FC(p,heap);
    func_021FC5A0((int *)(p+4),(int)config,heap);
    *(void **)(p+12)=func_020056A0((unsigned)func_021FC4E8,(unsigned)p,0);
    return p;
}
