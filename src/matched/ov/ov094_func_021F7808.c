/*
 * function: func_021F7808
 * address:  0x021F7808
 * packet:   pkt_ov094_021F7808
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   func_020066E8 0x020066E8 thumb
 *   func_021F8B6C 0x021F8B6C thumb ov094
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_021FEB78 0x021FEB78 thumb ov094
 *   func_021F6898 0x021F6898 thumb ov094
 *   func_021F6CF0 0x021F6CF0 thumb ov094
 *   func_021F6EC0 0x021F6EC0 thumb ov094
 *   func_02201AC4 0x02201AC4 thumb ov094
 *   func_02206E28 0x02206E28 thumb ov094
 *   func_022092E8 0x022092E8 thumb ov094
 *   func_0220977C 0x0220977C thumb ov094
 *   func_02050ED4 0x02050ED4 arm
 *   func_021F94D8 0x021F94D8 thumb ov094
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
extern char *d_0220AF20;
extern void func_020066E8(void *);
extern void func_021F8B6C(void);
extern void func_020215A0(void *, int);
extern void func_02021540(void *);
extern void func_021FEB78(void *);
extern void func_021F6898(void *);
extern void func_021F6CF0(void *);
extern void func_021F6EC0(void *);
extern void func_02201AC4(void *);
extern void func_02206E28(void *);
extern void func_022092E8(void *);
extern void func_0220977C(void *);
extern void func_02050ED4(void);
extern void func_021F94D8(void *);
extern void func_02030EAC(void *);
extern void func_02030DA4(void *);
extern void func_020307B0(void *);
#define FIELD(k) (*(void **)(d_0220AF20 + (k)))

void func_021F7808(void)
{
    if (d_0220AF20 != 0) {
        func_020066E8(d_0220AF20);
        func_021F8B6C();
        func_020215A0(FIELD(0x18c), 0);
        func_020215A0(FIELD(0x18c), 1);
        func_020215A0(FIELD(0x18c), 2);
        func_020215A0(FIELD(0x18c), 3);
        func_02021540(FIELD(0x18c));
        func_021FEB78(FIELD(0x190));
        func_021F6898(FIELD(0x194));
        func_021F6CF0(FIELD(0x198));
        func_021F6EC0(FIELD(0x19c));
        func_02201AC4(FIELD(0x1a0));
        func_02206E28(FIELD(0x1a4));
        func_022092E8(FIELD(0x1b0));
        func_0220977C(FIELD(0x1b4));
        func_02050ED4();
        func_021F94D8(FIELD(0x188));
        func_02030EAC(FIELD(0x1b8));
        func_02030DA4(FIELD(0));
        func_020307B0(FIELD(4));
        func_020307B0(d_0220AF20);
        d_0220AF20 = 0;
    }
}
