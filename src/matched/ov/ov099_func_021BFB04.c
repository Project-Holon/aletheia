/*
 * function: func_021BFB04
 * address: 0x021BFB04
 * packet: pkt_ov099_021BFB04
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 has no outside witness.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEB68.c (leaf-cb00-r1.log).
 *   extern char *d_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)func_0203CADC) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203CADC 0x0203CADC arm.
 * symbols:
 *   func_0203CB00 0x0203CB00 arm
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BFB90 0x021BFB90 thumb ov099
 */
typedef unsigned char u8;
extern int func_0203CB00(void);
extern void func_021BE900(char *);
extern int func_02156A3C(void);
extern void func_021BAAB8(char *, int, int);
extern int func_021BA928(char *);
typedef unsigned int   u32;
extern u32 func_020362DC(void);
extern void func_021BA8EC(char *);
extern void func_021BAADC(char *, int, int);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021C24A4(char *, int);
extern int func_021BFB90(char *, int);
int func_021BFB04(char *p, int ret)
{
    if (func_0203CB00()) {
        func_021BE900(p);
        return ret;
    }
    if (func_02156A3C() < 0) {
        func_021BAAB8(p, 0x10, 0);
        *(int *)(p + 0x1cc) = 0x13;
        return ret;
    }
    if (func_021BA928(p)) {
        if (func_020362DC() & 3) {
            func_021BA8EC(p);
            func_021BAADC(p, 0x7b, 0);
            func_021C18C8(p, 4, 4);
            func_021C24A4(p, 0);
            *(u8 *)(p + 0x1355) = 0;
            *(int *)(p + 0x1cc) = 0x10;
        } else {
            func_021BFB90(p, ret);
        }
    }
    return ret;
}
