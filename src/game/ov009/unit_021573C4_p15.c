/*
 * file:     unit_021573C4_p15.c
 * unit:     yes
 * function: func_02159244, func_021592A8, func_0215938C
 * address:  0x02159244
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   check_socket                     0x02159190 arm
 *   OSi_ThreadInfo                   0x02150fec data
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 */
struct _OSThread;
struct _CPSSoc;
struct _CPSSoc {
	unsigned char pad0[0x33];
	unsigned char sack;
	unsigned char pad1[6];
	unsigned short mss;
};

extern unsigned long check_socket(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc);
extern int func_021578C8(void);
extern int func_02157D8C(void);
int func_0215938C(void);
extern int OSi_ThreadInfo;



static struct _CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct _CPSSoc *soc;
	struct _OSThread *t;

	t = *(struct _OSThread **)((char *)&OSi_ThreadInfo + 8);
	while (t != 0) {
		soc = *(struct _CPSSoc **)((char *)t + 0xa4);

		if (soc != 0 && *(struct _OSThread **)soc != 0) {
			if (check_socket(iphdr, tcphdr, soc) != 0)
				return soc;
		}
		t = *(struct _OSThread **)((char *)t + 0x68);
	}
	return 0;
}



void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc)
{
	long len;
	unsigned char *p;

	soc->mss = 536;
	len = ((tcphdr[0xc] & 0xf0) / 4) - 20;
	p = tcphdr + 0x14;
	while (len-- > 0) {
		switch (*p++) {
		case 0:
			return;
		case 1:
			break;
		case 2:
			if (len <= 2)
				return;
			if (p[0] != 4)
				return;
			soc->mss = (p[1] << 8) | p[2];
			p += 3;
			len -= 3;
			break;
		case 4:
			if (len <= 0)
				return;
			if (p[0] != 2)
				return;
			soc->sack = 1;
			p++;
			len--;
			break;
		default: {
			unsigned long l;

			if (len <= 0)
				return;
			l = p[0];
			if (l < 2)
				return;
			l--;
			len -= l;
			p += l;
		}
		}
	}
}


/*
 * One when the test fails, else the second call.
 */
int func_0215938C(void)
{
    if (func_021578C8() == 0) {
        return 1;
    }

    return func_02157D8C();
}
