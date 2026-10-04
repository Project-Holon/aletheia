/*
 * function: func_021C1154
 * address: 0x021C1154
 * packet: pkt_ov099_021C1154
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero alignment bytes at 0x021C119E.
 * blocker: ARM9 0x0203CB00 lacks an outside code witness.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes, blocker-1.log.
 *   extern char *d_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)func_0203CADC) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203CADC 0x0203CADC arm.
 *   Leaf's only unresolved site is ARM9 0x0203CADC; Ilias owns it.
 * symbols:
 *   func_0203C3EC 0x0203C3EC arm
 *   func_0203CB00 0x0203CB00 arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BE900 0x021BE900 thumb ov099
 */
extern int func_0203C3EC(void);
extern int func_0203CB00(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BE900(char *);
int func_021C1154(char *p)
{
    if (func_0203C3EC() >= 3) {
        func_021BA874(p, *(int *)(p + 0x1f0));
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else {
        if (func_0203CB00() != 0) func_021BE900(p);
        else return 0;
    }
    *(unsigned short *)(p + 0x244) = 0;
    return 1;
}
