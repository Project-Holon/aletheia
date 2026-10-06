/*
 * function: func_0216003C
 * address:  0x0216003C
 * packet:   pkt_ov009_0216003C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      date2sec (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02088864  0x02088864  arm
 *   func_0208890C  0x0208890C  arm
 *   func_02089004  0x02089004  arm
 */

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

struct RTCDate;
struct RTCTime;
extern int func_02088864(struct RTCDate *date);
extern int func_0208890C(struct RTCTime *time);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);

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
