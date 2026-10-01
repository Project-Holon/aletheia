/*
 * function: func_021C11A0
 * address: 0x021C11A0
 * packet: pkt_ov099_021C11A0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * extent: 021C1286..021C1288 is two zero alignment bytes.
 * blocker: 0x0203C5EC ARM verified EXACT 20 bytes in blocker-c5ec-one.log.
 *   extern char *d_021469DC;
 *   int func_0203C5EC(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   symbols: d_021469DC 0x021469DC data a4.
 * prototype: 399A8 leaves a live pointer consumed by 399B8, 39C68 and 3D1A4.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_0203C3EC 0x0203C3EC arm
 *   func_0203C5EC 0x0203C5EC arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_020399B8 0x020399B8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02039C68 0x02039C68 arm
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_020399EC 0x020399EC arm
 */
typedef unsigned short u16;
extern int func_021BA928(void *);
extern int func_0203C3EC(void);
extern int func_0203C5EC(void);
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
extern int func_021C1154(char *);
extern void *func_020399A8(void);
extern unsigned func_020399B8(void *);
extern void func_02082BCC(void *, int, int);
extern void func_02039C68(void *, unsigned, unsigned);
extern void func_021BC090(void *);
extern unsigned func_0203D1A4(void *);
extern int func_02039ACC(void);
extern int func_020399EC(void);
int func_021C11A0(char *p, int ret)
{
    func_021BA928(p);
    if (func_0203C3EC() >= 4 || func_0203C5EC() != 0) {
        if (*(u16 *)(p + 0x244) != 0) {
            func_021BAAB8(p, 0x44, 0);
        } else {
            func_021BA874(p, *(int *)(p + 0x1f0));
            func_021BAAB8(p, 15, 0);
        }
        *(u16 *)(p + 0x244) = 0;
        *(int *)(p + 0x1cc) = 19;
    } else if (func_021C1154(p) == 0) {
        if (*(int *)(p + 0x1e0) > 1) --*(int *)(p + 0x1e0);
        if (*(int *)(p + 0x1e0) == 0) {
            if (func_020399B8(func_020399A8()) != 0) {
                func_02082BCC(p + 0x1f4, 0, 0x40);
                func_02039C68(func_020399A8(), 14, 10);
                *(u16 *)(p + 0x244) = 0;
                func_021BAAB8(p, 0x45, 0);
                func_021BC090(p);
                *(int *)(p + 0x1cc) = 0x2a;
            }
        } else if (*(int *)(p + 0x1e0) == 1) {
            if (func_0203D1A4(func_020399A8()) != 0) {
                if (func_02039ACC() == 1) *(int *)(p + 0x1e0) = 0;
            } else if (func_020399EC() != 0 && func_02039ACC() == 1) {
                *(int *)(p + 0x1e0) = 0;
            }
        }
    }
    return ret;
}
