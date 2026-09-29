/*
 * function: func_021A13D0
 * address:  0x021A13D0
 * packet:   pkt_ov009_021A13D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessAdHocData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_021A0E30  0x021A0E30  arm  ov009
 *   func_021A12DC  0x021A12DC  arm  ov009
 *   func_0217EC90  0x0217EC90  arm  ov009
 *   func_021A1254  0x021A1254  arm  ov009
 *   func_021A10D4  0x021A10D4  arm  ov009
 *   func_021A0F0C  0x021A0F0C  arm  ov009
 *   memmove        0x02092364  arm
 *   func_0219FAAC  0x0219FAAC  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad0[0x7c];
    u8 *inbuffer;
    int inbufferlen;
    char pad84[0x630];
    int sock;
} SBServerList;

extern int func_021A0E30(SBServerList *slist, u8 *buf, int len);
extern int func_021A12DC(SBServerList *slist, u8 *buf, int len);
extern int func_0217EC90(int sock, u8 *buf, int len, int flags);
extern int func_021A1254(SBServerList *slist, u8 *buf, int len);
extern int func_021A10D4(SBServerList *slist, u8 *buf, int len);
extern int func_021A0F0C(SBServerList *slist, u8 *buf, int len);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern void func_0219FAAC(SBServerList *slist);

int func_021A13D0(SBServerList *slist)
{
    int ret = 0;
    int i;
    u16 msglen;

    while (slist->inbufferlen >= 3) {
        u8 *dst = (u8 *)&msglen;
        dst[0] = slist->inbuffer[0];
        dst[1] = slist->inbuffer[1];
        msglen = ((msglen >> 8) & 0xFF) | ((msglen << 8) & 0xFF00);
        if (msglen > 0x1000) {
            ret = 4;
            break;
        }
        if (slist->inbufferlen < msglen)
            return 0;
        switch ((char)slist->inbuffer[2]) {
        case 0:
            break;
        case 1:
            ret = func_021A0E30(slist, slist->inbuffer + 3, msglen - 3);
            break;
        case 2:
            ret = func_021A12DC(slist, slist->inbuffer + 3, msglen - 3);
            break;
        case 3:
            if (func_0217EC90(slist->sock, slist->inbuffer, msglen, 0) <= 0)
                return 3;
            break;
        case 4:
            ret = func_021A1254(slist, slist->inbuffer + 3, msglen - 3);
            break;
        case 5:
            ret = func_021A10D4(slist, slist->inbuffer + 3, msglen - 3);
            break;
        case 6:
            ret = func_021A0F0C(slist, slist->inbuffer + 3, msglen - 3);
            break;
        default:
            break;
        }
        slist->inbufferlen -= msglen;
        if (slist->inbufferlen != 0 && slist->inbuffer != 0)
            memmove(slist->inbuffer, slist->inbuffer + msglen, slist->inbufferlen);
        if (ret != 0)
            break;
    }
    if (ret != 0)
        func_0219FAAC(slist);
    return ret;
}
