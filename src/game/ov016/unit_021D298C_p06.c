/*
 * file:     unit_021D298C_p06.c
 * unit:     yes
 * function: func_021D3068, func_021D308C, func_021D30D8
 * address:  0x021D3068
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
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   WM_EndMP                         0x0208FDEC  arm
 *   DWCi_MOV_WH_StateOutEndChildMP   0x021D3108  arm
 */
typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int func_02090BB8(int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);
extern int WM_EndMP(void (*callback)(void *));
extern void DWCi_MOV_WH_StateOutEndChildMP(void *arg);
int func_021D308C(void);


static void DWCi_MOV_WH_StateOutEndParent(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(1);
}


/*
 * Only in state 6, select port 3 and query the global tail for the ready answer.
 * Addresses are Black-image addresses.
 */
int func_021D308C(void)
{
    int *g = (int *)0x021DE660;

    if (*(int *)(g[1] + 0x40) != 6)
        return 0;
    func_021D29C8(3);
    if (func_02090BB8(g[1] + 0x1e00) == 2)
        return 1;
    func_021D2A44();
    return 0;
}


static int DWCi_MOV_WH_StateInEndChildMP(void)
{
    int result;

    DWCi_MOV_WH_ChangeSysState(3);
    result = WM_EndMP(DWCi_MOV_WH_StateOutEndChildMP);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}
