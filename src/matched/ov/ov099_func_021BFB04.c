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
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 * symbols:
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   func_021BE900 0x021BE900 thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BFB90 0x021BFB90 thumb ov099
 */
typedef unsigned char u8;
extern int GFL_NET_STATE_IsFatalError(void);
extern void func_021BE900(char *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void func_021BAAB8(char *, int, int);
extern int func_021BA928(char *);
typedef unsigned int   u32;
extern u32 KEY_GetTrg(void);
extern void func_021BA8EC(char *);
extern void func_021BAADC(char *, int, int);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021C24A4(char *, int);
extern int func_021BFB90(char *, int);
int func_021BFB04(char *p, int ret)
{
    if (GFL_NET_STATE_IsFatalError()) {
        func_021BE900(p);
        return ret;
    }
    if (DWC_RAP_GetTargetFriendIndex() < 0) {
        func_021BAAB8(p, 0x10, 0);
        *(int *)(p + 0x1cc) = 0x13;
        return ret;
    }
    if (func_021BA928(p)) {
        if (KEY_GetTrg() & 3) {
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
