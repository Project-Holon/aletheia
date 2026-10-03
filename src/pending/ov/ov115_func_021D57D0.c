/*
 * function: func_021D57D0
 * address: 0x021D57D0
 * packet: pkt_ov115_021D57D0
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 data 0x020A1448 has no outside witness; data a4 declared without overlay hint. Singleton tu --suggest-split confirms zero witnesses and no viable partition; concrete bytes exact.
 * symbols:
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021D5900 0x021D5900 thumb ov115
 *   d_020A1448 0x020A1448 data a4
 *   d_021D65E4 0x021D65E4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 d_020A1448[];
extern const u8 d_021D65E4[];
extern void func_0204A48C(void *,const void *,u32);
extern void *func_0204B100(int,int,u32);
extern void *func_020056A0(void *,void *,u32);
extern void func_021D5900(void *,u8 *);
void func_021D57D0(u8 *p) { func_0204A48C(d_020A1448,d_021D65E4,*(u16 *)(p+12)); *(void **)(p+0x980)=func_0204B100(40,0,*(u16 *)(p+12)); *(void **)(p+0x984)=func_020056A0((void *)func_021D5900,p,0); }
