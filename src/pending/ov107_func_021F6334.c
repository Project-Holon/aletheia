/*
 * function: MBi_CheckWmErrcode
 * address:  0x021F6334
 * packet:   pkt_ov107_021F6334
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).  decl_line 1711, local arg.
 *
 * symbols:
 *   d_021F6F90   0x021F6F90  data
 */
typedef unsigned short u16;

extern char d_021F6F90[];

void MBi_CheckWmErrcode(u16 apiid, int errcode)
{
    struct
    {
        u16 apiid;
        u16 errcode;
    } arg;
    void (*callback)(int, void *);

    if (errcode == 2 || errcode == 0)
        return;

    arg.apiid = apiid;
    arg.errcode = (u16)errcode;
    callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
    callback(0xFF, &arg);
}
