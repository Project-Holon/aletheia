/*
 * unit: yes
 * function: func_021BE148,func_021BE150,func_021BE158
 * address: 0x021BE148
 * packet: pkt_ov203_021BE148
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: solely blocks assigned 021BDF24; parent cleared ownership.
 * extent: three 8-byte wrappers; ends at peer-owned 021BE160, which is excluded.
 * symbols:
 *   func_02047970 0x02047970 arm
 *   func_0204EA64 0x0204EA64 arm
 *   func_02048AC4 0x02048AC4 arm
 */
extern void func_02047970(void);
extern void func_0204EA64(void);
typedef unsigned int   u32;
extern u32 func_02048AC4(void *ptr);
void func_021BE148(void *p){func_02047970();}
void func_021BE150(void){func_0204EA64();}
void func_021BE158(void *p){func_02048AC4(p);}
