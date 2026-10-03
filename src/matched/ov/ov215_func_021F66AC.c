/*
 * unit: yes
 * function: func_021F66AC,func_021F66C0
 * address: 0x021F66AC
 * packet: pkt_ov215_021F66AC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes cleared tiny follower func_021F66C0; no further code included.
 * symbols:
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 */
struct Light;
extern void func_02047964(void *);
extern void func_02048AD0(struct Light *);
extern void func_020479D8(void);
extern void func_02047970(void);
void func_021F66AC(void *p){func_02047964(p);func_02048AD0(*(struct Light **)p);func_020479D8();}
void func_021F66C0(void *p){func_02047970();}
