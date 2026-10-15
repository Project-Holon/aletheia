/*
 * unit:     yes
 * function: WIFILIST_GetGsProfileId
 * address:  0x02009CC0
 * packet:   pkt_02009CC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   DWC_GetGsProfileId    0x020598EC  arm
 *   WIFILIST_MakeExchangeToken  0x02009CB0  thumb
 *
 * Compared as a unit rather than as a single function because the packet's
 * range runs two bytes past the last instruction: `match.py one` sees the
 * original as 36 bytes against the compiler's 34 and reports EXACT*, while
 * `tu` lays the section out and reproduces the linker's two-byte filler.
 */

typedef unsigned char u8;

struct Sub020097BCObj;
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int WIFILIST_MakeExchangeToken(int a0, int a1);
struct DWCstAccUserData;
extern int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);

int WIFILIST_GetGsProfileId(void *a0)
{
    u8 buf[12];
    void *h = func_02009860(a0);

    WIFILIST_MakeExchangeToken((int)a0, (int)buf);
    return DWC_GetGsProfileId(h, buf);
}
