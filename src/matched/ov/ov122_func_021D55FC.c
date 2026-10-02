/*
 * function: func_021D55FC
 * address: 0x021D55FC
 * packet: pkt_ov122_021D55FC
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: intended code ends 021D5704; remaining handed extent is rodata.
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_02178118 0x02178118 thumb ov014
 *   func_021D4AD4 0x021D4AD4 thumb ov122
 *   func_02031140 0x02031140 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned int u32;
extern u32 func_020221A4(void);
extern int func_0203CD98(void);
extern void func_02178118(u32, u32);
extern void func_021D4AD4(char *);
extern void func_02031140(void *);
extern void func_020403F4(int);
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_0204B3B4(void *);
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_02030EAC(void *);
extern void func_0204B1CC(void *);
extern void func_0204A5AC(void);
extern void func_0201CE48(void *);
extern void func_0201ED04(void *);
extern void func_02027858(void *);
extern void func_020452E8(void *);
extern void func_02027FD8(void *);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(void *);
extern void func_020306F0(int);
int func_021D55FC(void *a, void *b, char *out, char *p)
{
    int i;
    if (!func_020221A4()) return 0;
    if (func_0203CD98()) func_02178118(0, 0);
    func_021D4AD4(p);
    *(int *)(out + 0x20) = *(int *)(p + 8);
    func_02031140(*(void **)(p + 0x31c));
    func_020403F4(5);
    func_0201C6EC(*(void **)(p + 0x320));
    func_0201C4C0(*(void **)(p + 0x320));
    for (i = 0; i < 3; i++) func_0204B3B4(*(void **)(p + i * 4 + 0x390));
    func_0204B3B4(*(void **)(p + 0x39c));
    func_0204B3B4(*(void **)(p + 0x3a0));
    func_0204B3B4(*(void **)(p + 0x3a4));
    func_0204ADA4(*(void **)(p + 0x378));
    func_0204A8D4(*(void **)(p + 0x37c));
    func_0204AFD8(*(void **)(p + 0x380));
    func_02030EAC(*(void **)(p + 0x310));
    func_0204B1CC(*(void **)(p + 0x30c));
    func_0204A5AC();
    if (*(void **)(p + 0x318)) func_0201CE48(*(void **)(p + 0x318));
    func_0201ED04(*(void **)(p + 0x48));
    if (*(void **)(p + 0x324)) {
        func_02027858(*(void **)(p + 0x324));
        *(void **)(p + 0x324) = 0;
    }
    if (*(void **)(p + 0x314)) func_020452E8(*(void **)(p + 0x314));
    func_02027FD8(*(void **)(p + 0x340));
    func_020450C8();
    func_0203F9B4();
    func_020315D4(a);
    func_020306F0(31);
    return 1;
}
