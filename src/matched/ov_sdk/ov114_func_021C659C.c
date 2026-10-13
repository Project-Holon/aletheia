/*
 * function: DWCi_NdSetError
 * address:  0x021C659C
 * packet:   pkt_ov114_021C659C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdSetError (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 */

extern void func_02059F54(int error, int errorCode);

void DWCi_NdSetError(int err, int servererror)
{
	switch (err) {
	case 1:
		func_02059F54(9, -31001);
		break;
	case 3:
		func_02059F54(14, -31020);
		break;
	case 4:
		func_02059F54(13, -31040);
		break;
	case 7:
		func_02059F54(13, -31000 - servererror);
		break;
	case 5:
		func_02059F54(13, -31040);
		break;
	case 8:
		func_02059F54(9, -31009);
		break;
	case 2:
		func_02059F54(13, -31010);
		break;
	case 0:
	case 6:
		break;
	default:
		func_02059F54(9, -31009);
		break;
	}
}
