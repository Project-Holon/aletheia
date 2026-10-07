/*
 * file:     wih_p07.c
 * unit:     yes
 * function: func_021784F0, func_0217850C
 * address:  0x021784F0
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WM_EndParent                 0x0208F654  arm
 *   func_0217814C                0x0217814C  thumb
 *   DWCi_MOV_WH_SetError             0x0217814C  thumb
 *   DWCi_MOV_WH_ChangeSysState       0x02178138  thumb
 */
typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern int WM_EndParent(void *);
extern void func_0217814C(void);
extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_ChangeSysState(int state);
int DWCi_MOV_WH_StateInEndParent(void);


int DWCi_MOV_WH_StateInEndParent(void)
{
	if (WM_EndParent((void *)0x0217850D) != 2)
	{
		func_0217814C();
		return 0;
	}
	return 1;
}


static void DWCi_MOV_WH_StateOutEndChild(void *arg)
{
	WMCallback *cb = (WMCallback *)arg;

	if (cb->errcode != 0)
	{
		DWCi_MOV_WH_SetError(cb->errcode);
		return;
	}
	DWCi_MOV_WH_ChangeSysState(1);
}
