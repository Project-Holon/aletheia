/*
 * function: func_021DDF84
 * address: 0x021DDF84
 * packet: pkt_ov137_021DDF84
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   func_021DD924 0x021DD924 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021DE4B4(char *, int, int);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void *func_021DCF50(u8 *);
extern int UNION_APP_GetMemberCount(u8 *);
extern void func_021DD924(char *);
int func_021DDF84(char *p, int state) {
    func_021DE4B4(p, 15, 1);
    *(int *)(p + 0x118) = 20;
    GFL_NET_SYSTEM_GetCurrentAid();
    *(int *)(p + 0x481C) = UNION_APP_GetMemberCount(func_021DCF50((u8 *)p));
    *(int *)(p + 0x4818) = 300;
    func_021DD924(p);
    return state;
}
