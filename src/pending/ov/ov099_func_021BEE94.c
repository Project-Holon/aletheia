/*
 * function: func_021BEE94
 * address: 0x021BEE94
 * packet: pkt_ov099_021BEE94
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * extent: two zero alignment bytes after the 38-byte function.
 * blocker: ARM9 0203CB00 and 0203C628 lack outside code witnesses;
 *   tu --suggest-split leaves the singleton out.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEAEC.c, leaf-cb00-r1.log.
 *   extern char *d_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)func_0203CADC) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203CADC 0x0203CADC arm.
 *   Leaf's unresolved site is ARM9 0203CADC.
 * blocker: 0x0203C628 ARM verified EXACT, 52 bytes; copied from
 *   ov099_func_021BEC60.c, blocker-c628-1.log.
 *   extern char *d_021469DC;
 *   extern void func_0203C0F4(void);
 *   extern void func_0203C464(void);
 *   int func_0203C628(void) {
 *       void *v = *(void **)(d_021469DC + 8);
 *       return v == (void *)func_0203C0F4 || v == (void *)func_0203C464;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203C0F4 0x0203C0F4 arm;
 *     func_0203C464 0x0203C464 arm.
 * symbols:
 *   func_0203CB00 0x0203CB00 arm
 *   func_0203C628 0x0203C628 arm
 */
typedef unsigned int u32;
extern int func_0203CB00(void);
extern int func_0203C628(void);
int func_021BEE94(u32 p, int a) {
    if (!func_0203CB00() && !func_0203C628()) return a;
    *(u32 *)(p+460) = 10;
    return a;
}
