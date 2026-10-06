/*
 * function: func_021BEC60
 * address: 0x021BEC60
 * packet: pkt_ov099_021BEC60
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0203CB00, 0203C628 and 0203C5EC lack code witnesses.
 * lever: duplicate state-update tail in each arm, goto shared return;
 *   writing one update after the outer branch cross-jumps the earlier call.
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
 * blocker: 0x0203C628 ARM verified EXACT, 52 bytes, blocker-c628-1.log.
 *   extern char *d_021469DC;
 *   extern void func_0203C0F4(void);
 *   extern void func_0203C464(void);
 *   int func_0203C628(void) {
 *       void *v = *(void **)(d_021469DC + 8);
 *       return v == (void *)func_0203C0F4 || v == (void *)func_0203C464;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203C0F4 0x0203C0F4 arm;
 *     func_0203C464 0x0203C464 arm.
 * blocker: 0x0203C5EC ARM verified EXACT, 20 bytes, blocker-c5ec-1.log.
 *   extern char *d_021469DC;
 *   int func_0203C5EC(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   symbols: d_021469DC 0x021469DC data.
 * symbols:
 *   func_0201A570 0x0201A570 thumb
 *   func_0203CB00 0x0203CB00 arm
 *   func_0203C3EC 0x0203C3EC arm
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_0203C628 0x0203C628 arm
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021BE26C 0x021BE26C thumb ov099
 *   func_0203C5EC 0x0203C5EC arm
 *   func_0203D1C0 0x0203D1C0 arm
 *   func_0203C554 0x0203C554 arm
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 */
extern void func_0201A570(void *);
extern int func_0203CB00(void);
extern int func_0203C3EC(void);
extern void func_021BE900(char *);
extern int func_0203C628(void);
extern int func_021B96CC(int *);
extern void func_021BE26C(char *);
extern int func_0203C5EC(void);
typedef unsigned int   u32;
extern u32 func_0203D1C0(u32 index);
extern void func_0203C554(u32 a);
extern int func_021BE4F0(char *, int);
int func_021BEC60(char *p, int ret)
{
    if (*(int *)(p + 0x1e0) > 0) {
        *(int *)(p + 0x1e0) -= 1;
        return ret;
    }
    if (*(void **)(p + 0x1344)) {
        func_0201A570(*(void **)(p + 0x1344));
        *(void **)(p + 0x1344) = 0;
    }
    if (func_0203CB00() || func_0203C3EC() == 3) {
        func_021BE900(p);
    } else {
        if (func_0203C628()) {
            if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
            goto done;
        } else {
            if (func_0203C3EC() < 4 && !func_0203C5EC() && func_0203D1C0(0xff)) goto done;
            func_0203C554(1);
            if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
        }
        *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
    }
done:
    return ret;
}
