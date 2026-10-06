/*
 * function: func_021B69AC
 * address: 0x021B69AC
 * packet: pkt_ov133_021B69AC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 data 020A1448 has no independent witness; keep the ROM-pool Config copy.
 * blocker: ARM9 unit_0204349C.c omits sub_020434CC from function:; unit_02043570.c omits func_02043588.
 * blocker: 020434CC verified MATCH 16 bytes (nested 020434B4 missing in the same unit):
 *   extern void sub_0204349C(void),sub_020434B4(void);
 *   void sub_020434CC(void) { sub_0204349C(); sub_020434B4(); }
 *   The unit's sub_020434B4 body is g_02146A48.unk_04 &= 0xf (second word).
 * blocker: 02043588 verified EXACT 16 bytes:
 *   extern void func_02043558(void),func_02043570(void);
 *   void func_02043588(void) { func_02043558(); func_02043570(); }
 * tu: MATCH 504 bytes; --suggest-split leaves the sole function OUT, no viable partition.
 * volatile: hardware display-register accesses at 021B69BE,021B69C8,021B69F8,021B6A64.
 * symbols:
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204044C 0x0204044C arm
 *   func_021B6E4C 0x021B6E4C thumb ov133
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_0204EBD4 0x0204EBD4 arm
 *   d_021BA518 0x021BA518 data a4
 *   d_021BA3F4 0x021BA3F4 data a4
 *   d_021BA40C 0x021BA40C data a4
 *   d_021BA400 0x021BA400 data a4
 *   d_021BA418 0x021BA418 data a4
 *   d_021BA428 0x021BA428 data a4
 *   d_021BA438 0x021BA438 data a4
 *   d_021BA458 0x021BA458 data a4
 *   d_021BA478 0x021BA478 data a4
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA498 0x021BA498 data a4
 *   d_021BA4B8 0x021BA4B8 data a4
 *   d_021BA4D8 0x021BA4D8 data a4
 *   d_020A1448 0x020A1448 data a4
 *   d_021BA5C4 0x021BA5C4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 x,y,z; } Vec;
typedef struct { u32 words[2]; u8 a,b,c,d; u32 field; u16 dims[6]; } Config;
extern u8 d_021BA518[],d_021BA418[],d_021BA428[],d_021BA438[],d_021BA458[],d_021BA478[],d_021BA4F8[],d_021BA498[],d_021BA4B8[],d_021BA4D8[];
extern Vec d_021BA3F4,d_021BA40C,d_021BA400;
extern Config d_020A1448,d_021BA5C4;
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32,u32);
extern u32 func_02022224(void *);
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
extern void func_020433E0(const struct DispVram *c);
extern void func_02046440(u32,u32,u32,u32,u16,u32,void (*)(void));
extern void func_02046BE0(u32,u32);
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,Vec *,Vec *,Vec *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(void *);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0204044C(u32);
extern void func_021B6E4C(const void *t, unsigned int id);
extern void func_02040588(u32,u32);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void *func_0204EBD4(u8 *,void *);
typedef enum { DISP_SUB_MAIN=0, DISP_MAIN_SUB=1 } DispSelect;
static inline void visible_main(int plane)
{
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0x1f00u) | (plane << 8));
}
static inline void visible_sub(int plane)
{
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0x1f00u) | (plane << 8));
}
static inline void select_display(DispSelect sel)
{
    *(volatile u16 *)0x04000304 = (u16)((*(volatile u16 *)0x04000304 & ~0x8000u) | (sel << 15));
}
void func_021B69AC(u8 *p)
{
    Config cfg, board;
    func_020434CC(); func_02043588();
    visible_main(0);
    visible_sub(0);
    func_0202223C(0,0); func_0202223C(1,0);
    func_02022224(0); func_02022224((void *)1);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    select_display(DISP_SUB_MAIN);
    func_020433E0((const struct DispVram *)d_021BA518);
    func_02046440(0,2,0,1,0,*(u16 *)p,0);
    func_02046BE0(0,1);
    *(u32 **)(p+0x1888) = func_02048A24(2,0xc000,0,0,0x10000,0x1000,0x3e8000,0,&d_021BA3F4,&d_021BA40C,&d_021BA400,*(u16 *)p);
    func_02048AD0(*(void **)(p+0x1888));
    func_0207DCF8(d_021BA418);
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    func_02046BE0(0,0);
    func_0203F8F4(*(u16 *)p); func_02045088(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021BA428); func_0204044C(1);
    func_021B6E4C(d_021BA438,1); func_021B6E4C(d_021BA458,2);
    func_021B6E4C(d_021BA478,3); func_021B6E4C(d_021BA4F8,7);
    func_021B6E4C(d_021BA498,4); func_021B6E4C(d_021BA4B8,5); func_021B6E4C(d_021BA4D8,6);
    func_02040588(0,1);
    func_0207D63C((void *)0x04001050,0,15,4,16);
    cfg = d_020A1448;
    cfg.a = 16; cfg.b = 112;
    func_0204A48C((const struct Cfg *)(&cfg),(u32)d_021BA518,*(u16 *)p);
    func_020434DC(16,1); func_02043598(16,1);
    *(void **)(p+0x1848) = func_0204B100(24,0,*(u16 *)p);
    func_0204B270(*(void **)(p+0x1848));
    board = d_021BA5C4;
    *(void **)(p+0x188c) = func_0204EBD4((u8 *)&board,(void *)*(u16 *)p);
}
