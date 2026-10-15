/*
 * function: IRC_RHYTHM_StartRecord
 * address: 0x021B85E4
 * packet: pkt_ov104_021B85E4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OS_IsTickAvailable 0x02087058 arm
 *   OS_InitTick 0x02086FE8 arm
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int OS_IsTickAvailable(void);
extern void OS_InitTick(void);
extern unsigned long long func_020870D0(void);
void IRC_RHYTHM_StartRecord(u8 *p) { if(OS_IsTickAvailable()) OS_InitTick(); *(unsigned long long *)(p+0x7c)=(func_020870D0()<<6)/33514; }
