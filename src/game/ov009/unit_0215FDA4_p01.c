/*
 * file:     unit_0215FDA4_p01.c
 * unit:     yes
 * function: func_0215FFD0, func_0216003C, func_0216007C, func_0216008C
 * address:  0x0215FFD0
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
 *   func_02087988  0x02087988  arm
 *   func_020923F0  0x020923F0  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021AA664  0x021AA664  data
 *   func_02088864  0x02088864  arm
 *   func_0208890C  0x0208890C  arm
 *   func_02089004  0x02089004  arm
 *   pairlist                         0x021a1d40 data ov009
 *   d_021A1D40                   0x021A1D40  data
 */
#include "../../matched/include/G_CPSSslSession.h"

struct RTCDate;
struct RTCTime;
typedef struct CPSSslSession CPSSslSession;

typedef struct CPSSslConnection {
    unsigned char pad0[0x74];
    unsigned char session_id[0x20];     /* +0x74 */
} CPSSslConnection;

typedef unsigned char  u8;

typedef struct {
	int year;
	int month;
	int day;
	int week;
} RTCDate;

typedef struct {
	int hour;
	int minute;
	int second;
} RTCTime;

extern unsigned long func_02087988(void);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern unsigned long func_0208799C(unsigned long state);
extern int func_02088864(struct RTCDate *date);
extern int func_0208890C(struct RTCTime *time);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
unsigned long func_0216003C(void);
unsigned long CPS_GetSslHandshakePriority(void);
void CARDi_CommandBegin(int len);
extern struct CPSSslSession g_021AA664[4];
extern unsigned long pairlist[];
extern unsigned char d_021A1D40[];


/*
 * sdk:      purge_session (libssl.TWL.HYB.a(ssl.o))
 */
static void func_0215FFD0(CPSSslConnection *con)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = func_02087988();
    for (i = 0; i < 4; i++) {
        p = &g_021AA664[i];
        if (p->valid != 0) {
            if (func_020923F0((const u8 *)p, con->session_id, 0x20) == 0) {
                p->valid = 0;
                break;
            }
        }
    }
    func_0208799C(enabled);
}


/*
 * sdk:      date2sec (libssl.TWL.HYB.a(ssl.o))
 */
unsigned long func_0216003C(void)
{
	unsigned long sec;
	RTCDate date;
	RTCTime time;

	func_02088864((struct RTCDate *)(&date));
	func_0208890C((struct RTCTime *)(&time));
	sec = func_02089004((struct RTCDate *)(&date), (struct RTCTime *)(&time));
	return sec + 946684800;
}


unsigned long CPS_GetSslHandshakePriority(void)
{
	return pairlist[1];
}

void CARDi_CommandBegin(int len)
{
	*(int *)(d_021A1D40 + 4) = len;
}
