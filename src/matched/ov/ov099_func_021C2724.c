/*
 * function: func_021C2724
 * address: 0x021C2724
 * packet: pkt_ov099_021C2724
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C2438 0x021C2438 thumb ov099
 *   func_020221A4 0x020221A4 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_021BA7F8 0x021BA7F8 thumb ov099
 *   func_0200AE08 0x0200AE08 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_021BDF7C 0x021BDF7C thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BCBB0 0x021BCBB0 thumb ov099
 *   func_021BB224 0x021BB224 thumb ov099
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C2438(char *);
extern int func_020221A4(void);
extern int func_0203CD98(void);
extern void func_021BA7F8(char *);
extern void func_0200AE08(void *, void *);
extern void func_020307B0(void *);
extern void func_021BC0C4(char *);
extern void func_021BDF7C(char *);
extern int func_02156A3C(void);
extern void func_021BCBB0(void *);
extern void func_021BB224(char *);
extern void func_020315D4(void *);
extern void func_020306F0(int);
int func_021C2724(void *task, int unused, char *output, char *p)
{
    if (!func_021C2438(p)) return 0;
    if (!func_020221A4()) return 0;
    if (func_0203CD98()) func_021BA7F8(p);
    *(u8 *)(output + 0x49) = *(int *)(p + 0x135c);
    if (*(void **)(p + 0x1348)) {
        func_0200AE08(*(void **)(p + 0x1348), *(void **)(output + 0x1c));
        func_020307B0(*(void **)(p + 0x1348));
        *(void **)(p + 0x1348) = 0;
    }
    func_021BC0C4(p);
    func_021BDF7C(p);
    *(u8 *)(output + 0x47) = *(u16 *)(p + 0x242);
    *(int *)(output + 0xc) = *(int *)(p + 0x1d0);
    if (func_0203CD98()) *(int *)(output + 0x10) = func_02156A3C();
    func_021BCBB0(*(void **)(p + 0xcc));
    func_021BB224(p);
    func_020315D4(task);
    func_020306F0(33);
    return 1;
}
