/*
 * function: func_021C4F64
 * address: 0x021C4F64
 * packet: pkt_ov093_021C4F64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 recoup: `ok = 0;` written after the call to func_021C5108 (it is
 * only read by the later compare), not before it; this puts the zero store in r2 as in the
 * original. EXACT in c99 and c. Callees: func_021D59B4 and func_021BA1A8 return int,
 * func_021B8DDC (unlabelled in ov093 matched set) returns u8, func_021C5108 and
 * func_021B92B0 are void with three arguments.
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C5078 0x021C5078 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C5108 0x021C5108 thumb ov093
 *   func_021D646C 0x021D646C thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C5098 0x021C5098 thumb ov093
 *   func_021B92B0 0x021B92B0 thumb ov093
 *   func_021C5088 0x021C5088 thumb ov093
 *   func_021B902C 0x021B902C thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *);
extern int func_021D5B68(void *);
extern void func_021C5078(u8 *, u8);
extern int func_021BA1A8(char **p, int m);
extern u8 func_021B8DDC(u32);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5108(u8 *, u8 *, int);
extern void func_021D646C(u8 *);
extern u8 func_021B8FF4(u8 *);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021C5098(u8 *);
extern void func_021B92B0(char *p, void *m, int k);
extern void func_021C5088(u8 *, u8);
extern int func_021B902C(int, int);
extern void func_021BA1B4(char **p, int i);
int func_021C4F64(u8 *p, u8 *a)
{
    u8 k = func_021D5440(a);
    u8 *flags = p + 0x7a9;
    int ok;
    int side;
    int health;
    if (!flags[k] && func_021D5B68(a)) {
    flags[k] = 1;
    func_021C5078(p + 0x3e0, k);
    if (!(func_021BA1A8(*(void **)(p + 4), 0x200) && func_021B8DDC(k) != 0) && p[0x789] != k)
        func_021CD64C(*(void **)(p + 12), 0x5b, 0, k, 0xffff0000);
    func_021CD4B0(*(void **)(p + 12), 0x39, k);
    func_021C5108(p, a, 0);
    ok = 0;
    func_021D646C(a);
    side = func_021B8DDC(k);
    if (side == func_021B8FF4(*(u8 **)(p + 4))) {
        health = func_021D59B4(a, 15);
        if (health + 30 <= (int)func_021C5098(p)) ok = 1;
        func_021B92B0((char *)(*(u8 **)(p + 4)), a, ok);
    }
    func_021C5088(p + 0x1ab8, k);
    side = func_021B8DDC(k);
    {
        int current = func_021B8FF4(*(u8 **)(p + 4));
        if (side == current) {
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x4c);
        } else if (!func_021B902C(side, current)) {
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x19);
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x52);
        }
    }
    return 1;
    }
    return 0;
}
