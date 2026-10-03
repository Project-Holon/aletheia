/*
 * function: func_021C0FAC
 * address:  0x021C0FAC
 * packet:   pkt_ov016_021C0FAC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MSGlRead (libdwcutil.TWL.HYB.a(message.o))
 *
 * symbols:
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_021D4B68  0x021D4B68  arm  ov016
 *   g_021DE58C  0x021DE58C  data
 */

typedef struct {
	int a;
	int b;
	int c;
} Info;

extern void *func_021D54C4(void *que);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern char *g_021DE58C;

void *func_021C0FAC(char *file)
{
	unsigned long size;
	Info *info;
	char *msg;
	int *hdr;

	info = (Info *)func_021D54C4(*(void **)(g_021DE58C + 0x60));
	msg = func_021D4B68(file, &size, 4);
	hdr = (int *)(msg + 0x20);
	info->c = (int)msg;
	info->a = (int)(hdr + 4);
	info->b = (int)hdr + hdr[1] + 8;
	return info;
}
