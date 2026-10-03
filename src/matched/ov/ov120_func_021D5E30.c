/*
 * function: func_021D5E30
 * address: 0x021D5E30
 * packet: pkt_ov120_021D5E30
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D5E86.
 * symbols:
 *   func_0200F7F4 0x0200F7F4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_02028148 0x02028148 thumb
 *   func_02027858 0x02027858 thumb
 *   func_021D7898 0x021D7898 thumb ov120
 *   func_021D5FC4 0x021D5FC4 thumb ov120
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
extern void func_0200F7F4(void);
extern unsigned int func_020221A4(void);
extern int func_0203CD98(void);
extern void func_0203A5E4(unsigned int);
struct S020315D4;
struct TaskMenu;
extern void func_02028148(u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D7898(void *);
extern void func_021D5FC4(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(void *);
int func_021D5E30(void *p, int a, int b, u8 *q)
{
    func_0200F7F4();
    if (!func_020221A4()) return 0;
    if (func_0203CD98()) func_0203A5E4(0x2200);
    if (*(void **)(q + 0x34)) func_02028148(*(void **)(q + 0x34));
    if (*(void **)(q + 0x38)) func_02027858(*(void **)(q + 0x38));
    func_021D7898(*(void **)(q + 0x40));
    func_021D5FC4(*(void **)(q + 0x3c));
    func_020315D4(p);
    func_020306F0((void *)31);
    return 1;
}
