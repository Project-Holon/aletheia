/*
 * file:     eventdata_system_p05.c
 * unit:     yes
 * function: func_02163230, func_02163288, func_021632F0, func_02163340, func_021633A8
 * address:  0x02163230
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021640B0  0x021640B0  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_021631C0  0x021631C0  thumb  ov010
 *   func_021634D8  0x021634D8  thumb  ov010
 *   func_02163618  0x02163618  thumb  ov010
 *   func_021636F0  0x021636F0  thumb  ov010
 *   func_02163418  0x02163418  thumb  ov010
 *   func_021637E4  0x021637E4  thumb  ov010
 *   func_021634FC  0x021634FC  thumb  ov010
 *   func_02163580  0x02163580  thumb  ov010
 *   func_02163650  0x02163650  thumb  ov010
 *   func_0216377C  0x0216377C  thumb  ov010
 *   func_021638C8  0x021638C8  thumb  ov010
 *   func_0216369C  0x0216369C  thumb  ov010
 *   func_0216352C  0x0216352C  thumb  ov010
 *   func_021637B0  0x021637B0  thumb  ov010
 *   func_02163868  0x02163868  thumb  ov010
 *   func_0216372C  0x0216372C  thumb  ov010
 *   func_021638AC  0x021638AC  thumb  ov010
 *   func_0216355C  0x0216355C  thumb  ov010
 *   func_0216375C  0x0216375C  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021640B0(int a);
extern u32 func_0216D57C(void *p, u32 v);
extern int func_0216DB24(int a0);
extern int func_021631C0();
extern int func_021634D8();
extern int func_02163618(int a0, int a1);
extern int func_021636F0();
extern int func_02163418();
extern int func_021637E4();
extern int func_021634FC();
extern int func_02163580();
extern int func_02163650(int a0, int a1);
extern int func_0216377C();
extern int func_021638C8();
extern int func_0216369C();
extern int func_0216352C();
extern int func_021637B0();
extern int func_02163868();
extern int func_0216372C();
extern int func_021638AC(int a0, int a1);
extern int func_0216355C();
extern int func_0216375C();
void func_02163230(int a0);
void func_02163288(int a0);
void func_021632F0(int a0);
void func_02163340(int a0);
void func_021633A8(int a0);



void func_02163230(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0(a0);
loc_0216323A:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163244:
    if (a0 != 0) goto loc_02163284;
loc_02163248:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_0216324E:
    if (a0 != 1) goto loc_02163284;
loc_02163252:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_0216325C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021634D8(a0, a1);
loc_02163264:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163618(a0, a1);
loc_0216326C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021636F0(a0, a1);
loc_02163274:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163418(a0, a1);
loc_0216327C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637E4(a0, a1);
loc_02163284:
    return;
}



void func_02163288(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0(a0);
loc_02163292:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216329C:
    if (a0 != 0) goto loc_021632EC;
loc_021632A0:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_021632A6:
    if (a0 != 1) goto loc_021632EC;
loc_021632AA:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_021632B4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021634FC(a0, a1);
loc_021632BC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163580(a0, a1);
loc_021632C4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163650(a0, a1);
loc_021632CC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021636F0(a0, a1);
loc_021632D4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216377C(a0, a1);
loc_021632DC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637E4(a0, a1);
loc_021632E4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021638C8(a0, a1);
loc_021632EC:
    return;
}



void func_021632F0(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0(a0);
loc_021632FA:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163304:
    if (a0 != 0) goto loc_0216333C;
loc_02163308:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_0216330E:
    if (a0 != 1) goto loc_0216333C;
loc_02163312:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_0216331C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021636F0(a0, a1);
loc_02163324:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637E4(a0, a1);
loc_0216332C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216369C(a0, a1);
loc_02163334:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021638C8(a0, a1);
loc_0216333C:
    return;
}



void func_02163340(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0(a0);
loc_0216334A:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163354:
    if (a0 != 0) goto loc_021633A4;
loc_02163358:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_0216335E:
    if (a0 != 1) goto loc_021633A4;
loc_02163362:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_0216336C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163418(a0, a1);
loc_02163374:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216352C(a0, a1);
loc_0216337C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637B0(a0, a1);
loc_02163384:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163650(a0, a1);
loc_0216338C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163868(a0, a1);
loc_02163394:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216372C(a0, a1);
loc_0216339C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021638AC(a0, a1);
loc_021633A4:
    return;
}



void func_021633A8(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0(a0);
loc_021633B2:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_021633BC:
    if (a0 != 0) goto loc_02163414;
loc_021633C0:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_021633C6:
    if (a0 != 1) goto loc_02163414;
loc_021633CA:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_021633D4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163418(a0, a1);
loc_021633DC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637B0(a0, a1);
loc_021633E4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163650(a0, a1);
loc_021633EC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163868(a0, a1);
loc_021633F4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216372C(a0, a1);
loc_021633FC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216355C(a0, a1);
loc_02163404:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216375C(a0, a1);
loc_0216340C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021638AC(a0, a1);
loc_02163414:
    return;
}
