/*
 * function: DWCi_MOV_WH_StateOutEndChild
 * address:  0x0217850C
 * packet:   pkt_ov014_0217850C
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The trailing `*`: the inferred extent ran two bytes long onto the unlabelled
 * follower at 0x02178522; no byte differs.
 *
 * sdk:      DWCi_MOV_WH_StateOutEndChild (libdwcutil.TWL.HYB.thumb.a(dwc_mov_wh.o))
 *
 * symbols:
 *   DWCi_MOV_WH_SetError             0x0217814C  thumb
 *   DWCi_MOV_WH_ChangeSysState       0x02178138  thumb
 */

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_ChangeSysState(int state);

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
