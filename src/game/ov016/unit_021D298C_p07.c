/*
 * file:     unit_021D298C_p07.c
 * unit:     yes
 * function: func_021D3200, func_021D3228, func_021D323C
 * address:  0x021D3200
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 */
typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void DWCi_MOV_WH_ChangeSysState(int state);
void func_021D3228(unsigned int v);
unsigned short func_021D323C(void);


static void DWCi_MOV_WH_StateOutEnd(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_ChangeSysState(10);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(0);
}

/*
 * Store a word at +0x08 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D3228.c \
 *       --func func_021D3228 --addr 0x021D3228 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021D3228(unsigned int v)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 4);
    q[1] = v;
}

/*
 * Halfword at +0x52 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D323C.c \
 *       --func func_021D323C --addr 0x021D323C --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned short func_021D323C(void)
{
    char **p = (char **)0x021DE660;
    unsigned short *q = (unsigned short *)(p[1] + 0x52);
    return *q;
}
