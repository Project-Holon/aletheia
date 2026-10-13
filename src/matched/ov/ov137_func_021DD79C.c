/*
 * function: func_021DD79C
 * address: 0x021DD79C
 * packet: pkt_ov137_021DD79C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_021DD93C 0x021DD93C thumb ov137
 */
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GFL_NET_SetAutoExit(unsigned char a0);
typedef unsigned char  u8;
extern void *func_021DCF50(u8 *p);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern void func_021DE4B4(char *, int, int);
extern void func_021DD93C(char *, int);
int func_021DD79C(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        if ((unsigned)UNION_APP_GetMemberCount(func_021DCF50((u8 *)p)) >= 2)
            func_021DE4B4(p, 2, zero);
    } else {
        GFL_NET_SetAutoExit(1);
        func_021DE4B4(p, 8, 0);
    }
    func_021DD93C(p, 3);
    return state;
}
