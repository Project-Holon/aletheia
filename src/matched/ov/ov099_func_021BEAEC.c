/*
 * function: func_021BEAEC
 * address: 0x021BEAEC
 * packet: pkt_ov099_021BEAEC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 0x0203C600 and 0x0203CB00 have no outside code witness.
 * extent: 122 bytes code followed by two zero alignment bytes.
 * blocker: 0x0203C600 ARM verified EXACT, 40 bytes, leaf-c600-r1.log.
 *   extern char *d_021469DC;
 *   extern void func_0203C0F4(void);
 *   int func_0203C600(void) {
 *       return *(void **)(d_021469DC + 8) == (void *)func_0203C0F4;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203C0F4 0x0203C0F4 arm.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes, leaf-cb00-r1.log.
 *   extern char *d_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)func_0203CADC) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203CADC 0x0203CADC arm.
 *   Leaf's only unresolved site is ARM9 0x0203CADC.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_02156C84 0x02156C84 thumb ov009
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0203C600 0x0203C600 arm
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   func_0203CB00 0x0203CB00 arm
 *   func_0203C3EC 0x0203C3EC arm
 *   func_021BE900 0x021BE900 thumb ov099
 */
extern int func_021BA928(char *, int);
extern unsigned char func_02156C84(void);
extern void func_021BAAB8(char *, int, int);
extern int func_0203C600(void);
extern void func_021BE6F0(char *, int, int);
extern int func_021BE788(char *);
extern int func_021BE4F0(char *, int);
extern int func_0203CB00(void);
extern int func_0203C3EC(void);
extern void func_021BE900(char *);
int func_021BEAEC(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (func_02156C84()) {
        *(int *)(p + 0x1cc) = 0x3c;
        func_021BAAB8(p, 0x1e, 1);
    }
    if (func_0203C600()) {
        if (*(int *)(p + 0x1e8)) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else {
        if (func_0203CB00() || func_0203C3EC() == 3) func_021BE900(p);
    }
    return ret;
}
