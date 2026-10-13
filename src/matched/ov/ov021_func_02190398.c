/*
 * function: FIELD_MSGBG_SetupBgSingle
 * address:  0x02190398
 * packet:   pkt_ov021_02190398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_Delete  0x02194798  thumb  ov021
 *   FIELD_MSGBG_InitBgOneLayer  0x02192E0C  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   FIELD_MSGBG_VblankTalkSysTask  0x02192EB8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;

extern void TALKMSGWIN_Delete(unsigned char *a);
extern void FIELD_MSGBG_InitBgOneLayer(u32 *p);
extern u32 func_020056A0(void *fn, void *arg, int z);
typedef unsigned char  u8;
extern void FIELD_MSGBG_VblankTalkSysTask(u32 a, u8 *b);

void FIELD_MSGBG_SetupBgSingle(u32 *p)
{
    if (p[0x57] != 0) {
        TALKMSGWIN_Delete((unsigned char *)p[0x57]);
    }
    FIELD_MSGBG_InitBgOneLayer(p);
    if (p[0x5b] == 0) {
        p[0x5b] = func_020056A0((void *)FIELD_MSGBG_VblankTalkSysTask, p, 0);
    }
}
