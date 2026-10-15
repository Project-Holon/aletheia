/*
 * function: WIFILOGIN_DISP_CreateUnit
 * address: 0x021D57D0
 * packet: pkt_ov115_021D57D0
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 data 0x020A1448 has no outside witness; data a4 declared without overlay hint. Singleton tu --suggest-split confirms zero witnesses and no viable partition; concrete bytes exact.
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_020056A0 0x020056A0 thumb
 *   WIFILOGIN_DISP_VBlank 0x021D5900 thumb ov115
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021D65E4 0x021D65E4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 gClActorInitParam[];
extern const u8 d_021D65E4[];
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020056A0(void *,void *,u32);
extern void WIFILOGIN_DISP_VBlank(void *,u8 *);
void WIFILOGIN_DISP_CreateUnit(u8 *p) { CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)d_021D65E4,*(u16 *)(p+12)); *(void **)(p+0x980)=CLACT_CreateUnit(40,0,*(u16 *)(p+12)); *(void **)(p+0x984)=func_020056A0((void *)WIFILOGIN_DISP_VBlank,p,0); }
