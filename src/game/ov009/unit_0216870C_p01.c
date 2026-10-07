/*
 * file:     unit_0216870C_p01.c
 * unit:     yes
 * function: func_02168848, func_02168864
 * address:  0x02168848
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
 *   func_02168724  0x02168724  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_02059CBC  0x02059CBC  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern unsigned char func_02168724(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusString);
extern int func_0209477C(const u8 *s);
extern int func_02059CBC(const char *src, u32 srclen, char *dst, u32 dstlen);
unsigned char func_02168848(void *p, int a, int b);
unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);


/*
 * Calls func_02168864 with two zeroed arguments between the tail arguments.
 */
unsigned char func_02168848(void *p, int a, int b)
{
    unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
    return func_02168864(p, 0, 0, (char *)a, (int *)b);
}

/*
 * sdk:      DWC_GetFriendStatusDataSC (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
unsigned char func_02168864(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size)
{
	char statusString[256];
	unsigned char ret;
	ret = func_02168724(friendData, maxEntry, numEntry, statusString);
	if (ret == 0) {
		*size = -1;
		return ret;
	}
	*size = func_02059CBC(statusString, func_0209477C((const u8 *)statusString), 0, 0);
	if (statusData == 0 || *size == -1)
		return ret;
	func_02059CBC(statusString, func_0209477C((const u8 *)statusString), statusData, *size);
	return ret;
}
